#pragma once

#include <bgfx/bgfx.h>
#include <bimg/bimg.h>
#include <bx/bx.h>

namespace px
{
    class MouseState;
    class IRenderFilter
    {
    public:
        virtual void Init(uint32_t width, uint32_t height) = 0;
        virtual bool Update(float delta_time, MouseState* mouse) = 0;
        virtual void Shutdown() = 0;
    };
}