#include "camera.h"
#include "log.h"

namespace px
{

    Mouse::Mouse()
        : m_dx(0.0f)
        , m_dy(0.0f)
        , m_prev_mx(0.0f)
        , m_prev_my(0.0f)
        , m_scroll(0)
        , m_scroll_prev(0)
    {

    }

    void Mouse::Update(float mx, float my, int32_t mz, uint32_t width, uint32_t height)
    {
        const float widthf = float(int32_t(width));
        const float heightf= float(int32_t(height));

        //delta movemoent
        m_dx = float(mx - m_prev_mx)/widthf;
        m_dy = float(my - m_prev_my)/heightf;

        m_prev_mx = mx;
        m_prev_my = my;

        //Scroll
        m_scroll = mz - m_scroll_prev;
        m_scroll_prev = mz;
    }

    Camera::Camera()
    {
        Reset();
    }

    void Camera::Reset()
    {
        m_target.curr = {0.0f, 0.0f, 0.0f};
        m_target.dest = {0.0f, 0.0f, 0.0f};

        m_pos.curr = {0.0f, 0.0f, -3.0f};
        m_pos.dest = {0.0f, 0.0f, -3.0f};

        m_orbit[0] = 0.0f;
        m_orbit[1] = 0.0f;
    }

    void Camera::MtxLookAt(float *out_view_mtx)
    {
        /*DBG("Can Test Camera MtxLookAt %f, %f, %f; %f, %f, %f", 
            m_pos.curr.x, m_pos.curr.y, m_pos.curr.z, 
            m_target.curr.x, m_target.curr.y, m_target.curr.z);*/
        bx::mtxLookAt(out_view_mtx, m_pos.curr, m_target.curr);
    }

    void Camera::Orbit(float dx, float dy)
    {
        m_orbit[0] += dx;
        m_orbit[1] += dy;
    }

    void Camera::Dolly(float dz)
    {
        const float cnear = 1.0f;
        const float cfar = 100.0f;

        const bx::Vec3 to_target = bx::sub(m_target.dest, m_pos.dest);
        const float to_target_len = bx::length(to_target);
        const float inv_to_target_len = 1.0f / (to_target_len + bx::kFloatMin);
        const bx::Vec3 to_target_norm = bx::mul(to_target, inv_to_target_len);

        float delta = to_target_len * dz;
        float new_len = to_target_len + delta;
        if((cnear < new_len || dz < 0.0f) && (new_len < cfar || dz > 0.0f))
        {
            m_pos.dest = bx::mad(to_target_norm, delta, m_pos.dest);
        }
    }

    void Camera::ConsumeOrbit(float amount)
    {
        float consume[2];
        consume[0] = m_orbit[0] * amount;
        consume[1] = m_orbit[1] * amount;
        m_orbit[0] -= consume[0];
        m_orbit[1] -= consume[1];

        const bx::Vec3 to_pos = bx::sub(m_pos.curr, m_target.curr);
        const float to_pos_len = bx::length(to_pos);
        const float inv_to_pos_len = 1.0f/(to_pos_len +  bx::kFloatMin);
        const bx::Vec3 to_pos_norm = bx::mul(to_pos, inv_to_pos_len);

        float ll[2];
        bx::toLatLong(&ll[0], &ll[1], to_pos_norm);
        ll[0] += consume[0];
        ll[1] += consume[1];
        ll[1] = bx::clamp(ll[1], 0.02f, 0.98f);

        const bx::Vec3 tmp = bx::fromLatLong(ll[0], ll[1]);
        const bx::Vec3 diff = bx::mul(bx::sub(tmp, to_pos_norm), to_pos_len);

        m_pos.curr = bx::add(m_pos.curr, diff);
        m_pos.dest = bx::add(m_pos.dest, diff);
    }

    void Camera::Update(float dt)
    {
        const float amount = bx::min(dt/0.12f, 1.0f);
        ConsumeOrbit(amount);

        m_target.curr = bx::lerp(m_target.curr, m_target.dest, amount);
        m_pos.curr = bx::lerp(m_pos.curr, m_pos.dest, amount);
    }

    void Camera::EnvViewMtx(float *mtx)
    {
        const bx::Vec3 to_target = bx::sub(m_target.curr, m_pos.curr);
        const float to_target_len = bx::length(to_target);
        const float inv_to_target_len = 1.0f/(to_target_len + bx::kFloatMin);
        const bx::Vec3 to_target_norm = bx::mul(to_target, inv_to_target_len);

        const bx::Vec3 right = bx::normalize(bx::cross({0.0f, 1.0f, 0.0f}, to_target_norm));
        const bx::Vec3 up = bx::normalize(bx::cross(to_target_norm, right));

        mtx[0] = right.x;
        mtx[1] = right.y;
        mtx[2] = right.z;
        mtx[3] = 0.0f;
        mtx[4] = up.x;
        mtx[5] = up.y;
        mtx[6] = up.z;
        mtx[7] = 0.0f;
        mtx[8] = to_target_norm.x;
        mtx[9] = to_target_norm.y;
        mtx[10] = to_target_norm.z;
        mtx[11] = 0.0f;
        mtx[12] = 0.0f;
        mtx[13] = 0.0f;
        mtx[14] = 0.0f;
        mtx[15] = 1.0f;
    }
}