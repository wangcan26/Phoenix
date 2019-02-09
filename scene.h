#pragma once
#include "common.h"
#include "event_consumer.h"



namespace px
{
    class Cube;
    class MeshTexture;
    class Scene
    {
    public:
        Scene();

        ~Scene();

        void Init(uint32_t width, uint32_t height); 
        
        bool Update();

        bool ProcessEvents(uint32_t& width, uint32_t& height, uint32_t& reset, MouseState* mouse);

        void Shutdown();
    private:
        
        int64_t                  m_time_offset;

        uint32_t                 m_width, m_height;

        //Cube                     *m_cube;
        MeshTexture                *m_obj;

        MouseState                 m_mouse_state;
    };
}