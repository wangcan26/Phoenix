#include <bgfx/bgfx.h>
#include <bgfx/defines.h>
#include <bx/pixelformat.h>
#include <bx/timer.h>
#include <bx/handlealloc.h>
#include <bx/spscqueue.h>
#include <bx/thread.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <iostream>

#include "context.h"
#include "phoenix_api.h"
#include "cube.h"

//macros

//enums


//RenderThread for run rendering api
struct RenderThread
{
	int m_argc;
	const char* const *m_argv;
	px::WindowContext *m_win_ctx;

	static int32_t ThreadFunc(bx::Thread* thread, void *user_data);
};


//Functions
static void ErrorCb(int error, const char *description)
{
	DBG("GLFW error %d: %s", error, description);
}

static int32_t MAIN(int argc, const char* const *argv, px::WindowContext *win_ctx)
{
	//Init Phoenix Api
	DBG("Executing MAIN ------");
	px::PXInit();

	px::WindowHandle default_window = {0};
	//Set Default title
	bx::FilePath fp(argv[0]);
	char title[bx::kMaxFilePath];
	bx::strCopy(title, BX_COUNTOF(title), fp.getBaseName());
	px::SetWindowTitle(*win_ctx, default_window, title);

	int32_t result = bx::kExitSuccess;



	return result;
}

int32_t RenderThread::ThreadFunc(bx::Thread* thread, void *user_data)
{
	BX_UNUSED(thread);
	RenderThread *self = (RenderThread*)(user_data);
	int32_t result = MAIN(self->m_argc, self->m_argv, self->m_win_ctx);

	px::DestroyMainWindow(*self->m_win_ctx);
}

int main(int argc, char **argv)
{
	std::cout << "test bgfx ..." << std::endl;
	//Init
	uint32_t m_width = 1280;
	uint32_t m_height = 720;

	int64_t  m_time_offset;
	bool     m_r = true;
	bool     m_g = true;
	bool     m_b = true;
	bool     m_a = true;


	//Init glfw for creating window
	px::WindowContext  window_ctx;
	window_ctx.Init(m_width, m_height, &ErrorCb);

	//Create Renderer thread
	RenderThread  m_render_self;
	m_render_self.m_argc = argc;
	m_render_self.m_argv = argv;
	m_render_self.m_win_ctx = &window_ctx;
	bx::Thread m_thread;
	m_thread.init(RenderThread::ThreadFunc, &m_render_self);

	//Something with the main thread
	window_ctx.Run();

	m_thread.shutdown();
	/*
	// Init bgfx
	bgfx::Init init;
	init.type = bgfx::RendererType::OpenGL;
	init.vendorId = 0;
	init.resolution.width = m_width;
	init.resolution.height = m_height;
	init.resolution.reset = BGFX_RESET_VSYNC;

	bgfx::init(init);

	// Set view 0 clear state.
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f,
					   0);

	std::cout << "test bgfx end..." << std::endl;

	//Init Scene
	// Create a Cube vertex stream declaration
	px::PosColorVertex::Init();

	// Create vertex buffer for the Cube
	bgfx::VertexBufferHandle m_vbh;
	m_vbh = bgfx::createVertexBuffer(
		bgfx::makeRef(px::kCubeVertices, sizeof(px::kCubeVertices)),
		px::PosColorVertex::kDecl);

	bgfx::IndexBufferHandle m_ibh[BX_COUNTOF(px::kDTState)];

	m_ibh[0] = bgfx::createIndexBuffer(
		bgfx::makeRef(px::kCubeTriList, sizeof(px::kCubeTriList)));

	// Create program from shaders
	bgfx::ProgramHandle m_program;
	m_program = px::LoadProgram("vs_cubes", "fs_cubes");
	DBG("Create ProgramHandle %d", m_program.idx);
	m_time_offset = bx::getHPCounter();
	bgfx::frame();

	//Update 
	while(1)
	{

		float time = (float)( (bx::getHPCounter() - m_time_offset)/double(bx::getHPFrequency()));

		//Set view and projection matrix for view 0
		const bx::Vec3 at = {0.0f, 0.0f, 0.0f};
		const bx::Vec3 eye = {0.0f, 0.0f, -35.0f};
		{
			float view[16];
			bx::mtxLookAt(view, eye, at);

			float proj[16];
			bx::mtxProj(proj, 60.0f, float(m_width)/float(m_height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
		}

		//This dummy draw call is here to make sure that view 0 is cleared
		//if no other draw calls are submitted to view 0.
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

		//Submit 11x11 cubes
		for(uint32_t yy = 0; yy < 11; ++yy)
		{
			for(uint32_t xx = 0; xx < 11; ++xx)
			{
				float mtx[16];
				bx::mtxRotateXY(mtx, time + xx*0.21f, time + yy*0.37f);
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

		bgfx::frame();
	}
	*/

	return 0;
}