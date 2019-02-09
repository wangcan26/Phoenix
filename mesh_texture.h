#pragma once
#include "render_utils.h"
#include "camera.h"
namespace px
{
    class MouseState;
    class MeshTexture
    {
    public:
        MeshTexture();

        ~MeshTexture();

        void Init(uint32_t width, uint32_t height);

        bool Update(float delta_time, MouseState* mouse);

        void Shutdown();
    private:
        bgfx::UniformHandle m_back_texColor;
        bgfx::ProgramHandle m_back_program;
        bgfx::TextureHandle m_back_texture;

        bgfx::UniformHandle m_albedo_u;
        bgfx::ProgramHandle m_orb_program;
        bgfx::TextureHandle m_albedo_texture;

        Camera              m_back_camera;
        Camera              m_orb_camera;
        Mouse               m_mouse;

        uint32_t            m_width, m_height;
        render::Mesh        *m_background;
        render::Mesh        *m_orb;
        float               m_time;
    };
}