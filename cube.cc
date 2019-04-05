#include <bx/math.h>
#include "event_consumer.h"
#include "cube.h"
#include "phoenix_api.h"

namespace px
{

bgfx::VertexDecl PosColorVertex::kDecl;

    // A Cube
static PosColorVertex kCubeVertices[] = {
    {-1.0f, 1.0f, 1.0f, 0xff000000},   {1.0f, 1.0f, 1.0f, 0xff0000ff},
    {-1.0f, -1.0f, 1.0f, 0xff00ff00},  {1.0f, -1.0f, 1.0f, 0xff00ffff},
    {-1.0f, 1.0f, -1.0f, 0xffff0000},  {1.0f, 1.0f, -1.0f, 0xffff00ff},
    {-1.0f, -1.0f, -1.0f, 0xffffff00}, {1.0f, -1.0f, -1.0f, 0xffffffff},
};

static const uint16_t kCubeTriList[] = {
    0, 1,
    2,  // 0
    1, 3, 2, 4, 6,
    5,  // 2
    5, 6, 7, 0, 2,
    4,  // 4
    4, 2, 6, 1, 5,
    3,  // 6
    5, 7, 3, 0, 4,
    1,  // 8
    4, 5, 1, 2, 3,
    6,  // 10
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


    Cube::Cube():
         m_width(800)
        ,m_height(600)
        ,m_elapsed_time(0.0f)
        ,m_r(true)
        ,m_g(true)
        ,m_b(true)
        ,m_a(true)
    {

    }

    Cube::~Cube()
    {

    }

    void Cube::Init(uint32_t width, uint32_t height)
    {
        PosColorVertex::Init();

        //Create static vertex buffer
        m_vbh = bgfx::createVertexBuffer(
            //Static data can be passed with bgfx::makeRef
            bgfx::makeRef(kCubeVertices, sizeof(kCubeVertices))
            ,PosColorVertex::kDecl
        );

        //Create static index buffer for tiangle list rendering
        m_ibh[0] = bgfx::createIndexBuffer(
            //Static data can be passed with bgfx::makeRef
            bgfx::makeRef(kCubeTriList, sizeof(kCubeTriList))
        );

        m_program = px::LoadProgram("vs_cubes", "fs_cubes");

        m_width = width;
        m_height = height;
    }

    bool Cube::Update(float delta_time, MouseState* mouse)
    {

        const bx::Vec3 at = {0.0f, 0.0f, 0.0f};
        const bx::Vec3 eye = {0.0f, 0.0f, -35.0f};

        //Set view and projection matrix for view 0
        {
            float view[16];
            bx::mtxLookAt(view, eye, at);

            float proj[16];
            bx::mtxProj(proj, 60.0f, float(m_width)/(float)(m_height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);

            bgfx::setViewTransform(0, view, proj);

            //Set view 0 default viewport
            bgfx::setViewRect(0, 0, 0, uint16_t(m_width), uint16_t(m_height));
        }

        bgfx::touch(0);

        bgfx::IndexBufferHandle ibh = m_ibh[0];
		uint64_t state = 0 
			| (m_r ? BGFX_STATE_WRITE_R : 0)
			| (m_g ? BGFX_STATE_WRITE_G : 0)
			| (m_b ? BGFX_STATE_WRITE_B : 0)
			| (m_a ? BGFX_STATE_WRITE_A : 0)
			| BGFX_STATE_WRITE_Z
			| BGFX_STATE_DEPTH_TEST_LESS
			| BGFX_STATE_CULL_CW
			| BGFX_STATE_MSAA
			| px::kDTState[0]
			;

        m_elapsed_time += delta_time;
		//Submit 11x11 cubes
		for(uint32_t yy = 0; yy < 11; ++yy)
		{
			for(uint32_t xx = 0; xx < 11; ++xx)
			{
				float mtx[16];
				bx::mtxRotateXY(mtx, m_elapsed_time + xx*0.21f, m_elapsed_time + yy*0.37f);
				mtx[12] = -15.0f + float(xx)*3.0f;
				mtx[13] = -15.0f + float(yy)*3.0f;
				mtx[14] = 0.0f;

				//Set model matrix for rendering
				bgfx::setTransform(mtx);
				//Set vertex and index buffer.
				bgfx::setVertexBuffer(0, m_vbh);
				bgfx::setIndexBuffer(ibh);

				//Set render states
				bgfx::setState(state);

				//Submit primitive for rendering to view 0.
				bgfx::submit(0, m_program);
			}
		}

        return true;
    }

    void Cube::Shutdown()
    {
        // Cleanup.
		for (uint32_t ii = 0; ii < BX_COUNTOF(m_ibh); ++ii)
		{
			bgfx::destroy(m_ibh[ii]);
		}

		bgfx::destroy(m_vbh);
		bgfx::destroy(m_program);
    }

    
}