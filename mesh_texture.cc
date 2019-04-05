#include <bx/math.h>
#include <bgfx/defines.h>
#include "event_consumer.h"
#include "mesh_texture.h"
#include "phoenix_api.h"

namespace px
{

    #define VIEW_BACKGROUND_ID 0
    #define VIEW_SCENE_ID      1
    #define VIEW_FORGROUND_ID  2
    #define RENDERVIEW_IRRADIANCE_ID 3

    #define HDR_TEX_W    3200
    #define HDR_TEX_H    1600
    #define HDR_MIPS     8

    static bool  kIrradiance = false;
    static float kTexelHalf = 0.0f;
    struct PosTexCoord0Vertex
    {
        float m_x;
        float m_y;
        float m_z;
        float m_u;
        float m_v;

        static void Init()
        {
            kDecl
                .begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
                .end();
        }

        static bgfx::VertexDecl kDecl;
    };

    bgfx::VertexDecl PosTexCoord0Vertex::kDecl;

    // A Plane
    static float offset_x = 0.5f;
    static float offset_y = 0.75f;
    static float scale_x = 1.0f;
    static float scale_y = 0.5f;
    static PosTexCoord0Vertex kPlaneVertices[] = {
        {0.5f*scale_x+offset_x, 0.5f*scale_y+offset_y, 0.0f, 1.0f, 1.0f},  //top right  
        {0.5f*scale_x+offset_x, -0.5f*scale_y+offset_y, 0.0f, 1.0f, 0.0f}, // bottom right 
        {-0.5f*scale_x+offset_x, -0.5f*scale_y+offset_y, 0.0f, 0.0f, 0.0f}, //bottom left  
        {-0.5f*scale_x+offset_x, 0.5f*scale_y+offset_y, 0.0f, 0.0f, 1.0f}, //top left
    };


    static PosTexCoord0Vertex kRenderPlaneVertices[] = {
        {1.f, 1.f, 0.0f, 1.0f, 1.0f},  //top right  
        {1.f, -1.f, 0.0f, 1.0f, 0.0f}, // bottom right 
        {-1.f, -1.f, 0.0f, 0.0f, 0.0f}, //bottom left  
        {-1.f, 1.f, 0.0f, 0.0f, 1.0f}, //top left
    };

    static const uint16_t kPlaneTriList[] = {
        0, 1, 3, //first triangle
        1, 2, 3  //second triangle
    };

    //A Cube
    static PosTexCoord0Vertex kCubeVertices[] = {
        {-1.0f, 1.0f, 1.0f, 0.0f, 1.0f},   // top-left       0
        {1.0f, 1.0f, 1.0f,  1.0f, 1.0f},    // top-right      1
        {-1.0f, -1.0f, 1.0f, 0.0f, 0.0f},  // bottom-left    2   
        {1.0f, -1.0f, 1.0f, 1.0f, 0.0f},   // bottom-right   3
        {-1.0f, 1.0f, -1.0f, 0.0f, 1.0f},  //4
        {1.0f, 1.0f, -1.0f,  1.0f, 1.0f},   //5
        {-1.0f, -1.0f, -1.0f, 0.0f, 0.0f}, //6
        {1.0f, -1.0f, -1.0f,  1.0f, 0.0f},  //7
    };

    static const uint16_t kCubeTriList[] = {
        0, 1, 2,  // 0 front 
        1, 3, 2, 
        4, 6, 5,  // 2 back
        5, 6, 7, 
        0, 2, 4,  // 4  left
        4, 2, 6, 
        1, 5, 3,  // 6 right
        5, 7, 3, 
        0, 4, 1,  // 8  top
        4, 5, 1,
        2, 3, 6,  // 10 bottom 
        6, 3, 7,
    };

    static const char *kDTNames[]{
        "Triangle List", "Triangle Strip", "Lines", "Line Strip", "Points",
    };

    static const uint64_t kDTState[]{
        UINT16_C(0),          BGFX_STATE_PT_TRISTRIP,
        BGFX_STATE_PT_LINES,  BGFX_STATE_PT_LINESTRIP,
        BGFX_STATE_PT_POINTS,
    };

    BX_STATIC_ASSERT(BX_COUNTOF(kDTState) == BX_COUNTOF(kDTNames));

    
    MeshTexture::MeshTexture():
        m_width(800)
        ,m_height(600)
        ,m_back_sphere(NULL)
        ,m_orb(NULL)
        ,m_time(0.0)
    {

    }

    MeshTexture::~MeshTexture()
    {

    }

    void MeshTexture::Init(uint32_t width, uint32_t height)
    {
        //Init background
        //Sphere background
        m_back_texColor = bgfx::createUniform("s_sphereMap", bgfx::UniformType::Int1);
        m_back_program = LoadProgram("vs_sphere_texture", "fs_sphere_texture");
        m_back_texture = LoadTexture("textures/CaveRoom.hdr");
        m_back_sphere = LoadMesh("meshes/sphere1.bin");

        PosTexCoord0Vertex::Init();
        //Plane background
        m_back_plane.m_vbh = bgfx::createVertexBuffer(
            //Static data can be passed with bgfx::makeRef
            bgfx::makeRef(kPlaneVertices, sizeof(kPlaneVertices))
            ,PosTexCoord0Vertex::kDecl
        );
        m_back_plane.m_ibh = bgfx::createIndexBuffer(
            //Static data can be passed with bgfx::makeRef
            bgfx::makeRef(kPlaneTriList, sizeof(kPlaneTriList))
        );
        m_back_plane.m_programh = LoadProgram("vs_plane", "fs_orb");
        m_back_plane.m_texu = bgfx::createUniform("s_albedo", bgfx::UniformType::Int1);
        m_back_plane.m_texh = LoadTexture("textures/CaveRoom.hdr");

        //Cube background
        m_back_cube.m_vbh = bgfx::createVertexBuffer(
            bgfx::makeRef(kCubeVertices, sizeof(kCubeVertices))
            ,PosTexCoord0Vertex::kDecl
        );
        m_back_cube.m_ibh = bgfx::createIndexBuffer(
            bgfx::makeRef(kCubeTriList, sizeof(kCubeTriList))
        );
        m_back_cube.m_programh = LoadProgram("vs_cubes", "fs_cubes");
        m_back_cube.m_texu = bgfx::createUniform("s_cubeMap", bgfx::UniformType::Int1);
        m_back_cube.m_texh = LoadTexture("textures/uffizi.ktx");


        //Create a orb 
        m_albedo_u = bgfx::createUniform("s_albedo", bgfx::UniformType::Int1);
        m_orb_program = LoadProgram("vs_orb", "fs_orb");
        m_albedo_texture = LoadTexture("textures/CaveRoom.hdr");
        m_orb = LoadMesh("meshes/orb.bin");

        //Create a irradiance render plane
        m_irradiance_plane.m_vbh = bgfx::createVertexBuffer(
            //Static data can be passed with bgfx::makeRef
            bgfx::makeRef(kRenderPlaneVertices, sizeof(kPlaneVertices))
            ,PosTexCoord0Vertex::kDecl
        );
        m_irradiance_plane.m_ibh = bgfx::createIndexBuffer(
            //Static data can be passed with bgfx::makeRef
            bgfx::makeRef(kPlaneTriList, sizeof(kPlaneTriList))
        );
        m_irradiance_plane.m_fbo = bgfx::createFrameBuffer(256, 128, bgfx::TextureFormat::RGBA8);
        m_irradiance_plane.m_programh = LoadProgram("vs_irradiance_convolution", "fs_irradiance_convolution");
        m_irradiance_plane.m_texu = bgfx::createUniform("s_hdrMap", bgfx::UniformType::Int1);
        m_irradiance_plane.m_texh = LoadTexture("textures/output.hdr");

        //Create a radiance render plane
        m_radiance_plane.m_vbh = bgfx::createVertexBuffer(
            bgfx::makeRef(kRenderPlaneVertices, sizeof(kPlaneVertices))
            ,PosTexCoord0Vertex::kDecl
        );
        m_radiance_plane.m_ibh = bgfx::createIndexBuffer(
            //Static data can be passed with bgfx::makeRef
            bgfx::makeRef(kPlaneTriList, sizeof(kPlaneTriList))
        );
        m_radiance_plane.m_fbo = bgfx::createFrameBuffer(HDR_TEX_W/HDR_MIPS, HDR_TEX_H/HDR_MIPS, bgfx::TextureFormat::RGBA16F);
        m_radiance_plane.m_programh = LoadProgram("vs_radiance_prefilter", "fs_radiance_prefilter");
        m_radiance_plane.m_texu = bgfx::createUniform("s_hdrMap", bgfx::UniformType::Int1);
        m_radiance_plane.m_texh = LoadTexture("textures/CaveRoom.ktx");

        //Create a brdf render plane
        m_brdf_plane.m_vbh = bgfx::createVertexBuffer(
            bgfx::makeRef(kRenderPlaneVertices, sizeof(kPlaneVertices))
            ,PosTexCoord0Vertex::kDecl
        );
        m_brdf_plane.m_ibh = bgfx::createIndexBuffer(
            bgfx::makeRef(kPlaneTriList, sizeof(kPlaneTriList))
        );
        
        
        m_width = width;
        m_height = height;
    }

    bool MeshTexture::Update(float delta_time, MouseState* mouse)
    {
        //DBG("Can Test Mesh Texture Update begin---");
        bool res = true;
        m_time += delta_time*0.37f;

        //Camera
        m_mouse.Update(float(mouse->m_mx), float(mouse->m_my), mouse->m_mz, m_width,
        m_height);

        if(mouse->m_buttons[MouseButton::Left])
        {
            m_back_camera.Orbit(m_mouse.m_dx, m_mouse.m_dy);
            m_orb_camera.Orbit(m_mouse.m_dx, m_mouse.m_dy);
        }
        else if(mouse->m_buttons[MouseButton::Right])
        {
            m_orb_camera.Dolly(m_mouse.m_dx + m_mouse.m_dy);
        }else if(mouse->m_buttons[MouseButton::Middle])
        {

        }else if(0 != m_mouse.m_scroll)
        {
            m_orb_camera.Dolly(float(m_mouse.m_scroll)*0.05f);
        }
        m_orb_camera.Update(delta_time);
        m_back_camera.Update(delta_time);

        float proj[16];
            bx::mtxProj(proj, 90.0f, float(m_width)/float(m_height), 0.1f, 100.f, bgfx::getCaps()
            ->homogeneousDepth);
        
        //Reset render targets
        const bgfx::FrameBufferHandle invalid_rt = BGFX_INVALID_HANDLE;
        for(uint8_t ii = 0; ii < RENDERVIEW_IRRADIANCE_ID+1; ++ii)
        {
            bgfx::setViewFrameBuffer(ii, invalid_rt);
        }

        //Set view and projection matrix for view VIEW_BACKGROUND_ID
        {
            float view[16];
            m_back_camera.MtxLookAt(view);
            bgfx::setViewTransform(VIEW_BACKGROUND_ID, view, proj);
            //Set view 0 default viewport.
            bgfx::setViewRect(VIEW_BACKGROUND_ID, 0, 0, uint16_t(m_width), uint16_t(m_height));
        }

        //Set view and projection matrix for view VIEW_SCENE_ID
        {
            float view[16];
            m_orb_camera.MtxLookAt(view);
            bgfx::setViewTransform(VIEW_SCENE_ID, view, proj);
            bgfx::setViewRect(VIEW_SCENE_ID, 0, 0, uint16_t(m_width), uint16_t(m_height));
        }

        //Set view and ortho matrix for view VIEW_FORGROUND_ID
        {
            const bx::Vec3 at  = { 0.0f, 0.0f,  0.0f };
			const bx::Vec3 eye = { 0.0f, 0.0f, -1.0f };

			float view[16];
			//bx::mtxLookAt(view, eye, at);
            bx::mtxIdentity(view);
            float ortho[16];
            bx::mtxOrtho(ortho, 1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 100.0f, 0.0, bgfx::getCaps()->homogeneousDepth);
            bgfx::setViewTransform(VIEW_FORGROUND_ID, view, ortho);
            bgfx::setViewRect(VIEW_FORGROUND_ID, 0, 0, uint16_t(m_width), uint16_t(m_height));
        }

        //Set view and ortho matrix for view RENDERVIEW_IRRADIANCE_ID
        {
            float view[16];
			//bx::mtxLookAt(view, eye, at);
            bx::mtxIdentity(view);
            float ortho[16];
            bx::mtxOrtho(ortho, 1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 100.0f, 0.0, bgfx::getCaps()->homogeneousDepth);
            bgfx::setViewTransform(RENDERVIEW_IRRADIANCE_ID, view, ortho);
            bgfx::setViewRect(RENDERVIEW_IRRADIANCE_ID, 0, 0, uint16_t(HDR_TEX_W/HDR_MIPS), uint16_t(HDR_TEX_H/HDR_MIPS));
            bgfx::setViewFrameBuffer(RENDERVIEW_IRRADIANCE_ID, m_radiance_plane.m_fbo);
        }


        //Clear RenderTargets at begining
        if(!kIrradiance)
        {
            bgfx::setViewClear(RENDERVIEW_IRRADIANCE_ID
                ,BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH
                ,0xffffffff
                ,1.0f
                ,0
            );
            bgfx::touch(RENDERVIEW_IRRADIANCE_ID);
        }
        
        //Submit view VIEW_BACKGROUND_ID
        {
            float mtx[16];
            bx::mtxScale(mtx, 1.f, 1.f, 1.f);  
            const uint64_t state_double_sided = 0    \
						| BGFX_STATE_WRITE_RGB       \
						| BGFX_STATE_WRITE_A         \
						| BGFX_STATE_WRITE_Z         \
						| BGFX_STATE_DEPTH_TEST_LESS \
						| BGFX_STATE_MSAA  
                        ;          
            const uint64_t state_back_side = 0    \
						| BGFX_STATE_WRITE_RGB       \
						| BGFX_STATE_WRITE_A         \
						| BGFX_STATE_WRITE_Z         \
						| BGFX_STATE_DEPTH_TEST_LESS \
                        | BGFX_STATE_CULL_CCW         \
						| BGFX_STATE_MSAA            
						;
			//Sphere background	
            /*bgfx::setTexture(0, m_back_texColor, m_back_texture);
            if(m_back_sphere != NULL)
            {
                m_back_sphere->Submit(VIEW_BACKGROUND_ID, m_back_program, mtx, state_double_sided);
            }*/

            //Cube background
            bgfx::setTexture(0, m_back_cube.m_texu, m_back_cube.m_texh);
            bgfx::setState(state_back_side);
            bgfx::setVertexBuffer(0, m_back_cube.m_vbh);
            bgfx::setIndexBuffer(m_back_cube.m_ibh);
            bgfx::submit(VIEW_BACKGROUND_ID, m_back_cube.m_programh);

        }
        //Submit view VIEW_SCENE_ID
        {
            float mtx[16];
            //bx::mtxScale(mtx, 1.f, 1.f, 1.f); 
            bx::mtxSRT(mtx, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -0.80f, 0.0f);
            bgfx::setTexture(0, m_albedo_u, m_albedo_texture);
            const uint64_t state = 0    \
						| BGFX_STATE_WRITE_RGB       \
						| BGFX_STATE_WRITE_A         \
						| BGFX_STATE_WRITE_Z         \
						| BGFX_STATE_DEPTH_TEST_LESS \
                        | BGFX_STATE_CULL_CCW         \
						| BGFX_STATE_MSAA            
						;
            if(m_orb != NULL)
            {
                m_orb->Submit(VIEW_SCENE_ID, m_orb_program, mtx, state);
            }
        }

        //Submit rendeview RENDERVIEW_IRRADIANCE_ID
        {
            if(!kIrradiance)
            {
                bgfx::setTexture(0, m_radiance_plane.m_texu, m_radiance_plane.m_texh);
                bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
                bgfx::setVertexBuffer(0, m_radiance_plane.m_vbh);
                bgfx::setIndexBuffer(m_radiance_plane.m_ibh);
                bgfx::submit(RENDERVIEW_IRRADIANCE_ID, m_radiance_plane.m_programh);
                kIrradiance = true;
            }
        }

        //Submit view VIEW_FORGROUND_ID
        {
            bgfx::setTexture(0, m_back_plane.m_texu, bgfx::getTexture(m_radiance_plane.m_fbo));
            bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
            bgfx::setVertexBuffer(0, m_back_plane.m_vbh);
            bgfx::setIndexBuffer(m_back_plane.m_ibh);
            bgfx::submit(VIEW_FORGROUND_ID, m_back_plane.m_programh);
        }

        //DBG("Can Test Mesh Texture Update end---");
        return true;

    }

    void MeshTexture::Shutdown()
    {
        bgfx::destroy(m_back_program);
        bgfx::destroy(m_back_texColor);
        bgfx::destroy(m_back_texture);
    }
}