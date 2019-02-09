#pragma once
#include "common.h"
#include "event_consumer.h"

namespace px
{
    struct WindowContext;
    struct InputMouse
    {

        InputMouse();

        void Reset();

        void SetResolution(uint16_t width, uint16_t height);

        void SetPos(int32_t mx, int32_t my, int32_t mz);

        void SetButtonState(MouseButton::Enum button, uint8_t state);

        int32_t     m_absolute[3];
        float       m_norm[3];
        int32_t     m_wheel;
        uint8_t     m_buttons[MouseButton::Count];
        uint16_t    m_width;
        uint16_t    m_height;
        uint16_t    m_wheel_delta;
        bool        m_lock;
    };

    struct Input
    {
        Input();
        ~Input();

        void Reset();

        InputMouse m_mouse;
    };

    extern Input *input_ctx;
    extern bool   gExit;

    void InputInit();

    void InputShutdown();

    void InputSetMouseResolution(uint16_t width, uint16_t height);

    void InputSetMousePos(int32_t mx, int32_t my, int32_t mz);

    void InputSetMouseButtonState(MouseButton::Enum button, uint8_t state);

    void InputGetMouse(float mouse[3]);
    
    bool InputIsMouseLocked();

    void InputSetMouseLock(bool lock);

}