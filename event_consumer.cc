#include "event_consumer.h"

namespace px
{
    Event::Event(Enum type): m_type(type)
    {
         m_handle.idx = UINT16_MAX;
    }

    Event::Event(Enum type, WindowHandle handle)
            :m_type(type)
            ,m_handle(handle)
    {

    }

    EventQueue::EventQueue()
        :m_queue(GetDefaultAllocator())
    {

    }

    EventQueue::~EventQueue()
    {
        for(const Event* ev = Poll(); NULL != ev; ev = Poll())
        {
            Release(ev);
        }
    }

    void EventQueue::PostExitEvent()
    {
        Event *ev = BX_NEW(GetDefaultAllocator(), Event)(Event::Exit);
        m_queue.push(ev);
    }

    void EventQueue::PostSizeEvent(WindowHandle handle, uint32_t width, uint32_t height)
    {
        SizeEvent *ev = BX_NEW(GetDefaultAllocator(), SizeEvent)(handle);
        ev->m_width = width;
        ev->m_height = height;
        m_queue.push(ev);
    }

    void EventQueue::PostMouseEvent(WindowHandle handle, int32_t mx, int32_t my, int32_t mz)
    {
        MouseEvent *ev = BX_NEW(GetDefaultAllocator(), MouseEvent)(handle);
        ev->m_mx = mx;
        ev->m_my = my;
        ev->m_mz = mz;
        ev->m_button = MouseButton::None;
        ev->m_down = false;
        ev->m_move = true;
        m_queue.push(ev);
    }

    void EventQueue::PostMouseEvent(WindowHandle handle, int32_t mx, int32_t my, int32_t mz, MouseButton::Enum button, bool down)
    {
        MouseEvent *ev = BX_NEW(GetDefaultAllocator(), MouseEvent)(handle);
        ev->m_mx = mx;
        ev->m_my = my;
        ev->m_mz = mz;
        ev->m_button = button;
        ev->m_down = down;
        ev->m_move = false;
        m_queue.push(ev);
    }

    void EventQueue::PostWindowEvent(WindowHandle handle, void *nwh /*= NULL*/)
    {
        WindowEvent *ev = BX_NEW(GetDefaultAllocator(), WindowEvent)(handle);
        ev->m_nwh = nwh;
        m_queue.push(ev);
    }

    const Event* EventQueue::Poll()
    {
        return m_queue.pop();
    }

    const Event* EventQueue::Poll(WindowHandle handle)
    {
        if(isValid(handle))
        {
            Event *ev = m_queue.peek();
            if(NULL == ev 
            || ev->m_handle.idx != handle.idx)
            {
                return NULL;
            }
        }

        return Poll();
    }

    void EventQueue::Release(const Event* event) const
    {
        BX_DELETE(GetDefaultAllocator(), const_cast<Event*>(event));
    }
    
}