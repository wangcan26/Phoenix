#include "input.h"
#include "context.h"

namespace px
{
    InputMouse::InputMouse()
        : m_width(800)
        , m_height(600)
        , m_wheel_delta(120)
        , m_lock(false)
    {

    }

    void InputMouse::Reset()
    {
        if(m_lock)
        {
            m_norm[0] = 0.0f;
            m_norm[1] = 0.0f;
            m_norm[2] = 0.0f;
        }

        bx::memSet(m_buttons, 0, sizeof(m_buttons));
    }

    void InputMouse::SetResolution(uint16_t width, uint16_t height)
    {
        m_width = width;
        m_height = height;
    }

    void InputMouse::SetPos(int32_t mx, int32_t my, int32_t mz)
    {
        m_absolute[0] = mx;
        m_absolute[1] = my;
        m_absolute[2] = mz;
        m_norm[0] = float(mx)/float(m_width);
        m_norm[1] = float(my)/float(m_height);
        m_norm[2] = float(mz)/float(m_wheel_delta);
    }

    void InputMouse::SetButtonState(MouseButton::Enum button, uint8_t state)
    {
        m_buttons[button] = state;
    }

    Input::Input()
    {
        Reset();
    }

    Input::~Input()
    {

    }

    void Input::Reset()
    {
        m_mouse.Reset();
    }

    Input *input_ctx = NULL;
    bool   gExit = false;

    void InputInit()
    {
        input_ctx = BX_NEW(GetDefaultAllocator(), Input);
    }

    void InputShutdown()
    {
        BX_DELETE(GetDefaultAllocator(), input_ctx);
    }

    void InputSetMouseResolution(uint16_t width, uint16_t height)
    {
        input_ctx->m_mouse.SetResolution(width, height);
    }

    void InputSetMousePos(int32_t mx, int32_t my, int32_t mz)
    {
        input_ctx->m_mouse.SetPos(mx, my, mz);
    }

    void InputSetMouseButtonState(MouseButton::Enum button, uint8_t state)
    {
        input_ctx->m_mouse.SetButtonState(button, state);
    }

    void InputGetMouse(float mouse[3])
    {
        mouse[0] = input_ctx->m_mouse.m_norm[0];
        mouse[1] = input_ctx->m_mouse.m_norm[1];
        mouse[2] = input_ctx->m_mouse.m_norm[2];
        input_ctx->m_mouse.m_norm[0] = 0.0f;
        input_ctx->m_mouse.m_norm[1] = 0.0f;
        input_ctx->m_mouse.m_norm[2] = 0.0f;
    }

    bool InputIsMouseLocked()
    {
        return input_ctx->m_mouse.m_lock;
    }

    void InputSetMouseLock(bool lock)
    {
        if(input_ctx->m_mouse.m_lock != lock)
        {
            input_ctx->m_mouse.m_lock = lock;
            WindowHandle default_window = {0};
            SetMouseLock(default_window, lock);
            if(lock)
            {
                input_ctx->m_mouse.m_norm[0] = 0.0f;
                input_ctx->m_mouse.m_norm[1] = 0.0f;
                input_ctx->m_mouse.m_norm[2] = 0.0f;
            }
        }
    }
}