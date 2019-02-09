#include <bx/math.h>
#include <bgfx/defines.h>
#include "event_consumer.h"
#include "mesh_texture.h"
#include "phoenix_api.h"

namespace px
{
    MeshTexture::MeshTexture():
        m_width(800)
        ,m_height(600)
        ,m_background(NULL)
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
        m_back_texColor = bgfx::createUniform("s_sphereMap", bgfx::UniformType::Int1);
        m_back_program = LoadProgram("vs_sphere_texture", "fs_sphere_texture");
        m_back_texture = LoadTexture("textures/CaveRoom.hdr");
        m_background = LoadMesh("meshes/sphere1.bin");

        //Create a orb 
        m_albedo_u = bgfx::createUniform("s_albedo", bgfx::UniformType::Int1);
        m_orb_program = LoadProgram("vs_orb", "fs_orb");
        m_albedo_texture = LoadTexture("textures/CaveRoom.hdr");
        m_orb = LoadMesh("meshes/orb.bin");

        
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
            bx::mtxProj(proj, 60.0f, float(m_width)/float(m_height), 0.1f, 100.f, bgfx::getCaps()
            ->homogeneousDepth);

        //Set view and projection matrix for view 0
        {
            float view[16];
            m_back_camera.MtxLookAt(view);
            bgfx::setViewTransform(0, view, proj);
            //Set view 0 default viewport.
            bgfx::setViewRect(0, 0, 0, uint16_t(m_width), uint16_t(m_height));
        }

        //Set view and projection matrix for view 1
        {
            float view[16];
            m_orb_camera.MtxLookAt(view);
            bgfx::setViewTransform(1, view, proj);
            bgfx::setViewRect(1, 0, 0, uint16_t(m_width), uint16_t(m_height));
        }

        //Submit view 0
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
            bgfx::setTexture(0, m_back_texColor, m_back_texture);
            if(m_background != NULL)
            {
                m_background->Submit(0, m_back_program, mtx, state_double_sided);
            }
        }
        //Submit view 1
        {
            float mtx[16];
            //bx::mtxScale(mtx, 1.f, 1.f, 1.f); 
             bx::mtxSRT(mtx, 1.0f, 1.0f, 1.0f, 0.0f, bx::kPi, 0.0f, 0.0f, -0.80f, 0.0f);
            bgfx::setTexture(1, m_albedo_u, m_albedo_texture);
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
                m_orb->Submit(1, m_orb_program, mtx, state);
            }
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