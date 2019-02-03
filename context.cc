#include "context.h"
#include "log.h"

static void* GetNativewindowHandleFromGLFW(GLFWwindow *window)
{
#if 	BX_PLATFORM_LINUX || BX_PLATFORM_BSD
		return (void*)(uintptr_t)glfwGetX11Window(window);
#elif 	BX_PLATFORM_OSX
		return glfwGetCocoaWindow(window);
#elif   BX_PLATFORM_WINDOWS
		return glfwGetWin32Window(window);
#endif //BX_PLATFORM
}

static  void SetNativewindow(GLFWwindow *window)
{
		bgfx::PlatformData pd;
#if 	BX_PLATFORM_LINUX || BX_PLATFORM_BSD
		pd.ndt = glfwGetX11Display();
#elif	BX_PLATFORM_OSX
		pd.ndt = NULL;
#elif  	BX_PLATFORM_WINDOWS
		pd.ndt = NULL;
#endif
		pd.nwh 			= GetNativewindowHandleFromGLFW(window);
		pd.context 		= NULL;
		pd.backBuffer 	= NULL;
		pd.backBufferDS = NULL;
		bgfx::setPlatformData(pd);
}



namespace px
{
    WindowContext::WindowContext():
            m_msgs(GetDefaultAllocator())
    {

    }

    int32_t WindowContext::Init(int32_t width, int32_t height, FuncGLFWInitErrorCb error_cb)
    {
        glfwSetErrorCallback(error_cb);

        if(!glfwInit())
        {
            DBG("glfwInit failed!");
            return bx::kExitFailure;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        WindowHandle  handle = {m_window_alloc.alloc()};
	    //Create Window
	    m_windows[0] = glfwCreateWindow(width, height, "bgfx", NULL, NULL);

	    if(!m_windows[0])
	    {
		    DBG("glfwCreateWindow failed!");
		    glfwTerminate();
		    return bx::kExitFailure;
	    }

        //Set Window
	    SetNativewindow(m_windows[0]);

        return bx::kExitSuccess;
    }

    void WindowContext::Run()
    {
        while(NULL != m_windows[0] && !glfwWindowShouldClose(m_windows[0]))
        {
            glfwWaitEvents();

            while(Msg* msg = m_msgs.pop())
            {
                switch (msg->m_type)
                {
                    case GLFW_WINDOW_CREATE:
                        GLFWwindow *window = glfwCreateWindow(msg->m_width
                            ,msg->m_height
                            ,msg->m_title.c_str()
                            ,NULL
                            ,NULL
                        );
                        if(!window)
                        {
                            break;
                        }

                        glfwSetWindowPos(window, msg->m_x, msg->m_y);
                        if(msg->m_flags & WINDOW_FLAG_ASPECT_RATIO)
                        {
                            glfwSetWindowAspectRatio(window, msg->m_width, msg->m_height);
                        }

                        m_windows[msg->m_handle.idx] = window;
                        break;
                }

                delete msg;
            }
        } 
    }

    void WindowContext::DeInit()
    {
        glfwDestroyWindow(m_windows[0]);
        glfwTerminate();
    }

    void SetWindowTitle(WindowContext& win_ctx, WindowHandle handle, const char* title)
    {
        Msg *msg = new Msg(GLFW_WINDOW_SET_TITLE);
        msg->m_title = title;
        msg->m_handle = handle;
        win_ctx.m_msgs.push(msg);
        glfwPostEmptyEvent();
    }

    void DestroyMainWindow(WindowContext &context)
    {
        Msg* msg = new Msg(GLFW_WINDOW_DESTROY);
        msg->m_handle.idx = 0;

    }

}