#pragma once
#include <bgfx/platform.h>
#include <bx/platform.h>
#include <bx/handlealloc.h>
#include <bx/spscqueue.h>


//Config
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#	define GLFW_EXPOSE_NATIVE_X11
#	define GLFW_EXPOSE_NATIVE_GLX
#elif BX_PLATFORM_OSX
#	define GLFW_EXPOSE_NATIVE_COCOA
#	define GLFW_EXPOSE_NATIVE_NSGL
#elif BX_PLATFORM_WINDOWS
#	define GLFW_EXPOSE_NATIVE_WIN32
#	define GLFW_EXPOSE_NATIVE_WGL
#endif //

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "common.h"

//macros
#define CONFIG_MAX_WINDOWS          8
#define WINDOW_FLAG_NONE            UINT32_C(0x00000000)
#define WINDOW_FLAG_ASPECT_RATIO    UINT32_C(0x00000001)
#define WINDOW_FLAG_FRAME           UINT32_C(0x00000002)

//typedefs
typedef void (*FuncGLFWInitErrorCb)(int error, const char* description);


namespace px
{

    //enums
    enum MsgType
    {
	    GLFW_WINDOW_CREATE,
	    GLFW_WINDOW_DESTROY,
	    GLFW_WINDOW_SET_TITLE,
	    GLFW_WINDOW_SET_POS,
	    GLFW_WINDOW_SET_SIZE,
	    GLFW_WINDOW_TOGGLE_FRAME,
	    GLFW_WINDOW_TOGGLE_FULL_SCREEN,
    };

    //structs
    struct WindowHandle
    {
	    uint16_t idx;
    };

    struct Msg
    {
	    Msg(MsgType type)
		    :m_type(type)
		    ,m_x(0)
		    ,m_y(0)
		    ,m_width(0)
		    ,m_height(0)
		    ,m_value(false)
	    {

	    }

	    MsgType 			m_type;
	    int32_t 			m_x;
	    int32_t 			m_y;
	    uint32_t 			m_width;
	    uint32_t    		m_height;
	    uint32_t    		m_flags;
	    bool        		m_value;
	    tinystl::string  	m_title;
	    WindowHandle        m_handle;
    };


    struct WindowContext
    {
        WindowContext();

        int32_t Init(int32_t width, int32_t height, FuncGLFWInitErrorCb error_cb);

        void    Run();

		void    DeInit();

        bx::HandleAllocT<CONFIG_MAX_WINDOWS> m_window_alloc;
	    bx::SpScUnboundedQueueT<Msg>  m_msgs;
	    GLFWwindow *m_windows[CONFIG_MAX_WINDOWS];
    };


    //functions 
    extern void SetWindowTitle(WindowContext &context, WindowHandle handle, const char* title);
    extern void DestroyMainWindow(WindowContext &context);
}