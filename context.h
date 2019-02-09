#pragma once
#include <bgfx/platform.h>
#include <bgfx/bgfx.h>
#include <bx/platform.h>
#include <bx/handlealloc.h>
#include <bx/spscqueue.h>
#include <bx/mutex.h>
#include <stdint.h>
#include "event_consumer.h"
#include "scene.h"


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
		GLFW_WINDOW_MOUSE_LOCK,
    };

    //structs

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

		void    Shutdown();

		//Static methods
		//static void KeyCb(GLFWwindow* window, int32_t key, int32_t scan_code, 
		//	int32_t action, int32_t mods);
		//static void CharCb(GLFWwindow* window, uint32_t scan_code);
		static void ScrollCb(GLFWwindow* window, double dx, double dy);
		static void CursorPosCb(GLFWwindow* window, double mx, double my);
		static void MouseButtonCb(GLFWwindow* window, int32_t button, int32_t action,
			int32_t mods);
		static void WindowSizeCb(GLFWwindow* window, int32_t width, int32_t height);
		//static void DropFileCb(GLFWwindow* window, int32_t count, const char* file_paths);

		//methods
		WindowHandle FindHandle(GLFWwindow * window);

        bx::HandleAllocT<CONFIG_MAX_WINDOWS> m_window_alloc;
	    bx::SpScUnboundedQueueT<Msg>  m_msgs;
		bx::Mutex                     m_lock;

		EventQueue                    m_event_queue;

	    GLFWwindow *m_windows[CONFIG_MAX_WINDOWS];

		uint32_t   m_width, m_height;

		double     m_scroll_pos;
    };


    //functions 
    extern void SetWindowTitle(WindowHandle handle, const char* title);
	extern void SetWindowSize( WindowHandle handle, uint32_t width, uint32_t height);
	extern void SetMouseLock(WindowHandle handle, bool lock);
    extern void DestroyMainWindow();

	extern const Event*  Poll();
	extern const Event*  Poll(WindowHandle handle);
	extern void  Release(const Event* event);


	//Render Context
	struct RenderContext
	{
		RenderContext();

		void Init(uint32_t width, uint32_t height, uint32_t reset = BGFX_RESET_VSYNC,
			bgfx::RendererType::Enum type = bgfx::RendererType::OpenGL, 
			uint16_t vender_id = 0);

		bool Update();

		void Shutdown();

		uint32_t   m_width, m_height;

		Scene      *m_scene;

	};
}

extern px::WindowContext  window_ctx;
extern px::RenderContext  render_ctx;

