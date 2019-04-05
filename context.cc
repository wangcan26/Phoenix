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

static px::MouseButton::Enum TranslateMouseButton(int button)
{
    using namespace px;
    if(button == GLFW_MOUSE_BUTTON_LEFT)
    {
        //DBG("Can Test Mouse Button Left Callback ----");
        return MouseButton::Left;
    }else if(button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        //DBG("Can Test Mouse Button Right Callback ----");
        return MouseButton::Right;
    }
    //DBG("Can Test Mouse Button Middle Callback ----");
    return MouseButton::Middle;
}

px::WindowContext  window_ctx;
px::RenderContext  render_ctx;

namespace px
{

    //Window Context
    //static methods
    /*void WindowContext::KeyCb(GLFWwindow* window, int32_t key, int32_t scan_code, int32_t action, int32_t mods)
    {
        BX_UNUSED(scan_code);
        if(key == GLFW_KEY_UNKNOWN)
        {
            return;
        }

        WindowHandle handle = window_ctx.FindHandle(window);
        int mods = 
    }*/

    void WindowContext::ScrollCb(GLFWwindow* window, double dx, double dy)
    {
        BX_UNUSED(dx);
        WindowHandle handle = window_ctx.FindHandle(window);
        double mx, my;
        glfwGetCursorPos(window, &mx, &my);
        window_ctx.m_scroll_pos += dy;
        window_ctx.m_event_queue.PostMouseEvent(handle
            , (int32_t)mx
            , (int32_t)my
            , (int32_t) window_ctx.m_scroll_pos
        );
        //DBG("Can Test Mouse Button Callback ----");
    }

    void WindowContext::CursorPosCb(GLFWwindow* window, double mx, double my)
    {
        WindowHandle handle = window_ctx.FindHandle(window);
        window_ctx.m_event_queue.PostMouseEvent(handle, (int32_t)mx, (int32_t)my,
        (int32_t)window_ctx.m_scroll_pos);
    }

    void WindowContext::MouseButtonCb(GLFWwindow* window, int32_t button, int32_t action, int32_t mods)
    {
        BX_UNUSED(mods);
        WindowHandle handle = window_ctx.FindHandle(window);
        bool down = action == GLFW_PRESS;
        double mx, my;
        glfwGetCursorPos(window, &mx, &my);
        window_ctx.m_event_queue.PostMouseEvent(handle
        ,(int32_t)mx
        , (int32_t)my
        , (int32_t)window_ctx.m_scroll_pos
        , TranslateMouseButton(button)
        , down);
    }

    void WindowContext::WindowSizeCb(GLFWwindow *window, int32_t width, int32_t height)
    {
        WindowHandle handle = window_ctx.FindHandle(window);
        window_ctx.m_event_queue.PostSizeEvent(handle, width, height);
    }

    WindowContext::WindowContext():
            m_msgs(GetDefaultAllocator())
            ,m_width(800)
            ,m_height(600)
            ,m_scroll_pos(0.0f)

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

        //Set glfw Callbacks
        glfwSetScrollCallback(m_windows[0], ScrollCb);
        glfwSetWindowSizeCallback(m_windows[0], WindowSizeCb);
        glfwSetCursorPosCallback(m_windows[0], CursorPosCb);
        glfwSetMouseButtonCallback(m_windows[0], MouseButtonCb);
        
        //Set Window
	    SetNativewindow(m_windows[0]);
        m_event_queue.PostSizeEvent(handle, width, height);

        m_width = width;
        m_height = height;

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
                    {
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

                        //glfw callbacks
                        glfwSetScrollCallback(window, ScrollCb);
                        glfwSetWindowSizeCallback(window, WindowSizeCb);
                        glfwSetCursorPosCallback(window, CursorPosCb);
                        glfwSetMouseButtonCallback(window, MouseButtonCb);

                        m_windows[msg->m_handle.idx] = window;
                        m_event_queue.PostSizeEvent(msg->m_handle, msg->m_width, 
                            msg->m_height);
                        m_event_queue.PostWindowEvent(msg->m_handle, GetNativewindowHandleFromGLFW(window));
                    }
                        break;
                    case GLFW_WINDOW_SET_TITLE:
                    {
                        GLFWwindow *window = m_windows[msg->m_handle.idx];
                         glfwSetWindowTitle(window, msg->m_title.c_str());
                    }
                        break;
                    case GLFW_WINDOW_DESTROY:
                    {
                        if(isValid(msg->m_handle))
                        {
                            GLFWwindow *window = m_windows[msg->m_handle.idx];
                            m_event_queue.PostWindowEvent(msg->m_handle);
                            glfwDestroyWindow(window);
                            m_windows[msg->m_handle.idx] = NULL;
                        }
                        
                    }
                        break;
                    case GLFW_WINDOW_MOUSE_LOCK:
                    {
                        GLFWwindow *window = m_windows[msg->m_handle.idx];
                        if(msg->m_value)
                        {
                            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                        }else{
                            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                        }
                    }
                        break;
                }

                delete msg;
            }
        } 
    }

    void WindowContext::Shutdown()
    {
        glfwDestroyWindow(m_windows[0]);
        glfwTerminate();
    }

    WindowHandle WindowContext::FindHandle(GLFWwindow* window)
    {
        bx::MutexScope scope(m_lock);
        for(uint32_t ii = 0, num = m_window_alloc.getNumHandles(); ii < num; ++ii)
        {
            uint16_t idx = m_window_alloc.getHandleAt(ii);
            if(window == m_windows[idx])
            {
                WindowHandle handle = {idx};
                return handle;
            }
        }

        WindowHandle invalid = {UINT16_MAX};
        return invalid;
    }

    void SetWindowTitle(WindowHandle handle, const char* title)
    {
        Msg *msg = new Msg(GLFW_WINDOW_SET_TITLE);
        msg->m_title = title;
        msg->m_handle = handle;
        window_ctx.m_msgs.push(msg);
        glfwPostEmptyEvent();
    }

    void SetWindowSize(WindowHandle handle, uint32_t width, uint32_t height)
    {
        Msg *msg = new Msg(GLFW_WINDOW_SET_SIZE);
        msg->m_width = width;
        msg->m_height = height;
        msg->m_handle = handle;
        window_ctx.m_msgs.push(msg);
        glfwPostEmptyEvent();
    }

    void SetMouseLock(WindowHandle handle, bool lock)
    {
        Msg *msg = new Msg(GLFW_WINDOW_MOUSE_LOCK);
        msg->m_value = lock;
        msg->m_handle = handle;
        window_ctx.m_msgs.push(msg);
        glfwPostEmptyEvent();
    }

    void DestroyMainWindow()
    {
        Msg* msg = new Msg(GLFW_WINDOW_DESTROY);
        msg->m_handle.idx = 0;
        window_ctx.m_msgs.push(msg);
        glfwPostEmptyEvent();
    }

    const Event* Poll()
    {
        glfwPostEmptyEvent();
        return window_ctx.m_event_queue.Poll();
    }

    const Event* Poll(WindowHandle handle)
    {
        glfwPostEmptyEvent();
        return window_ctx.m_event_queue.Poll(handle);
    }

    void Release(const Event* event)
    {
        window_ctx.m_event_queue.Release(event);
    }

    RenderContext::RenderContext()
        :m_width(800)
        ,m_height(600)
    {
        m_scene = new Scene();
        
    }


    void RenderContext::Init(uint32_t width, uint32_t height, uint32_t reset /*BGFX_RESET_VSYNC*/,
			bgfx::RendererType::Enum type /*= bgfx::RendererType::OpenGL*/, 
			uint16_t vender_id /*= 0*/)
    {
        m_width = width;
        m_height = height;
        
        bgfx::Init init;
        init.type = type;
        init.vendorId = vender_id;
        init.resolution.width = m_width;
        init.resolution.height = m_height;
        init.resolution.reset = reset;
        bgfx::init(init);

        //Set view 0 clear state
        bgfx::setViewClear(0
            ,BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH
            ,0xff3030ff
            ,1.0f
            ,0
        );

        //Create Scene
        m_scene->Init(m_width, m_height);

        bgfx::frame();
    }

    bool RenderContext::Update()
    {
        bool res = true;
        if(m_scene != NULL)
        {
            res = m_scene->Update();
        }
        return res; 
    }

    void RenderContext::Shutdown()
    {
        if(m_scene != NULL)
        {
            delete m_scene;
            m_scene = NULL;
        }
    }

}