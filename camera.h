#pragma once
#include <bx/math.h>

namespace px
{

    struct Mouse
    {
        Mouse();

        void Update(float mx, float my, int32_t mz, uint32_t width, uint32_t height);

        float m_dx;//Screen space
        float m_dy;
        float m_prev_mx;
        float m_prev_my;
        int32_t m_scroll;
        int32_t m_scroll_prev;
    };

    struct Camera
    {
        Camera();

        void Reset();

        void MtxLookAt(float *out_view_matrix);

        void Orbit(float dx, float dy);

        void Dolly(float dz);

        void ConsumeOrbit(float amount);

        void Update(float dt);

        void EnvViewMtx(float *mtx);

        struct Interp3f
        {
            bx::Vec3 curr;
            bx::Vec3 dest;
        };

        Interp3f  m_target;
        Interp3f  m_pos;
        float     m_orbit[2];
    };


}