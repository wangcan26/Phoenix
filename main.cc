#include <bgfx/bgfx.h>
#include <bx/pixelformat.h>
#include <bx/handlealloc.h>
#include <bx/spscqueue.h>
#include <bx/thread.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <iostream>

#include "context.h"

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
	//px::RenderContext render_ctx;

	px::WindowHandle default_window = {0};
	//Set Default title
	bx::FilePath fp(argv[0]);
	char title[bx::kMaxFilePath];
	bx::strCopy(title, BX_COUNTOF(title), fp.getBaseName());
	px::SetWindowTitle(default_window, title);
	px::SetWindowSize(default_window, win_ctx->m_width, win_ctx->m_height);

	int32_t result = bx::kExitSuccess;
	//Render Context 
	render_ctx.Init(win_ctx->m_width, win_ctx->m_width);
	px::SetWindowSize(default_window, win_ctx->m_width, win_ctx->m_height);
	
	while(render_ctx.Update())
	{

	}

	window_ctx.m_event_queue.PostExitEvent();
	render_ctx.Shutdown();
	return result;
}

int32_t RenderThread::ThreadFunc(bx::Thread* thread, void *user_data)
{
	BX_UNUSED(thread);
	RenderThread *self = (RenderThread*)(user_data);
	int32_t result = MAIN(self->m_argc, self->m_argv, self->m_win_ctx);

	px::DestroyMainWindow();

	return result;
}

int main(int argc, char **argv)
{
	std::cout << "test bgfx ..." << std::endl;
	//Init
	uint32_t m_width = 960;
	uint32_t m_height = 720;

	//Init glfw for creating window
	//px::WindowContext  window_ctx;
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

	return 0;
}