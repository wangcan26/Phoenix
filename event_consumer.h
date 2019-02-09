#pragma once
#include "common.h"

#define PX_IMPLEMENT_EVENT(_class, _type) \
    _class(px::WindowHandle _handle): px::Event(_type, _handle){}

namespace px
{

    struct MouseButton
    {
        enum Enum
        {
            None,
            Left,
            Middle,
            Right,

            Count
        };
    };

    struct Event
    {
        enum Enum
        {
            Exit,
            Mouse,
            Size,
            Window,
        };

        Event(Enum type);

        Event(Enum type, WindowHandle handle);

        Event::Enum     m_type;
        WindowHandle    m_handle;
    };

    struct MouseEvent : public Event
    {
        PX_IMPLEMENT_EVENT(MouseEvent, Event::Mouse);

        int32_t  m_mx;
        int32_t  m_my;
        int32_t  m_mz;
        MouseButton::Enum m_button;
        bool     m_down;
        bool     m_move;
    };

    struct SizeEvent : public Event
    {
        PX_IMPLEMENT_EVENT(SizeEvent, Event::Size);

        uint32_t  m_width;
        uint32_t  m_height;
    };

    struct WindowEvent : public Event
    {
        PX_IMPLEMENT_EVENT(WindowEvent, Event::Window);

        void *m_nwh;
    };

    struct MouseState
    {
        MouseState()
            : m_mx(0)
            , m_my(0)
            , m_mz(0)
        {
            for(uint32_t ii = 0; ii < MouseButton::Count; ++ii)
            {
                m_buttons[ii] = MouseButton::None;
            }
        }

        int32_t m_mx;
        int32_t m_my;
        int32_t m_mz;
        uint8_t m_buttons[MouseButton::Count];
    };

    class EventQueue
    {
    public:
        EventQueue();

        ~EventQueue();

        void PostExitEvent();

        void PostMouseEvent(WindowHandle handle, int32_t mx, int32_t my, int32_t mz);

        void PostMouseEvent(WindowHandle handle, int32_t mx, int32_t my, int32_t mz, 
        MouseButton::Enum button, bool down);

        void PostSizeEvent(WindowHandle handle, uint32_t width, uint32_t height);

        void PostWindowEvent(WindowHandle handle, void *nwh = NULL);

        const Event* Poll();

        const Event* Poll(WindowHandle handle);

        void Release(const Event *event) const;

    private:
        bx::SpScUnboundedQueueT<Event> m_queue;
    };


}