#include <bx/timer.h>
#include <bgfx/defines.h>
#include "context.h"
#include "input.h"
#include "scene.h"
#include "phoenix_api.h"
#include "render_utils.h"
#include "cube.h"
#include "mesh_texture.h"

static uint32_t kReset = BGFX_RESET_NONE;

namespace px
{
    Scene::Scene():
        m_width(800)
        ,m_height(600)
        ,m_obj(NULL) 
    {
        PXInit();
    }

    Scene::~Scene()
    {
        PXShutdown();
    }

    void Scene::Init(uint32_t width, uint32_t height)
    {
        m_time_offset = bx::getHPCounter();

        m_width = width;
        m_height = height;

        InputInit();

        m_obj = new MeshTexture();
        m_obj->Init(width, height);
        

    }

    bool Scene::Update()
    {
        //DBG("Can Test Scene Update begin----");
        if(!ProcessEvents(m_width, m_height, kReset, &m_mouse_state))
        {
            //DBG("Can Test Scene after ProcessEvents begin----");
            float delta_time = (float) ( (bx::getHPCounter() - m_time_offset)/double(bx::getHPFrequency()));
            bool res = false;
            if(m_obj != NULL)
            {
                res =  m_obj->Update(delta_time, &m_mouse_state);
            }
            m_time_offset = bx::getHPCounter();
            //DBG("Can Test Scene Update begin--");
		    bgfx::frame();
            //DBG("Can Test Scene after ProcessEvents end----");
            return res;
        }
        //DBG("Can Test Scene Update end----");
        //DBG("Can Test Scene Update end--");
        return false;
    }

    bool Scene::ProcessEvents(uint32_t& width, uint32_t& height, uint32_t& reset, MouseState* mouse)
    {
        kReset = reset;

        WindowHandle handle = {UINT16_MAX};

        bool mouse_lock = InputIsMouseLocked();

        const Event *ev;
        do
        {
            struct SE{
                const Event* m_ev; 
                SE():m_ev(Poll()){} 
                ~SE(){
                    if(NULL != m_ev)
                    {
                        Release(m_ev);
                    }
                }
            } scope_event;

            ev = scope_event.m_ev;

            if(NULL != ev)
            {
                switch(ev->m_type)
                {
                    case Event::Exit:
                        return true;
                    case Event::Mouse:
                        {
                            const MouseEvent* _mouse = static_cast<const MouseEvent*>(ev);
                            handle = _mouse->m_handle;
                            InputSetMousePos(_mouse->m_mx, _mouse->m_my, _mouse->m_mz);
                            if(!_mouse->m_move)
                            {
                                InputSetMouseButtonState(_mouse->m_button, _mouse->m_down);
                            }

                            if(NULL != _mouse
                            && !mouse_lock)
                            {
                                mouse->m_mx = _mouse->m_mx;
                                mouse->m_my = _mouse->m_my;
                                mouse->m_mz = _mouse->m_mz;

                                DBG("Can Test Process Mouse Event %d, %d", mouse->m_mx, mouse->m_my);
                                if(!_mouse->m_move)
                                {
                                    mouse->m_buttons[_mouse->m_button] = _mouse->m_down;
                                }
                            }
                        }
                    break;
                    case Event::Size:
                    break;
                    case Event::Window:
                    break;
                    default:
                    break;
                }
            }

        } while (NULL != ev);
        
        if(handle.idx == 0
        && reset != kReset)
        {
            reset = kReset;
            bgfx::reset(width, height, reset);
            InputSetMouseResolution(uint16_t(width), uint16_t(height));
        }

        window_ctx.m_width = width;
        window_ctx.m_height = height;

        return gExit;

    }

    void Scene::Shutdown()
    {
        if(m_obj != NULL)
        {
            m_obj->Shutdown();
            delete m_obj;
            m_obj = NULL;
        }

        InputShutdown();

        // Shutdown bgfx.
		bgfx::shutdown();
    }
}