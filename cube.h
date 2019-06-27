#pragma once

#include "render_filter.h"

namespace px {
//专门用来渲染颜色顶点信息
struct PosColorVertex {
  float m_x;
  float m_y;
  float m_z;
  uint32_t m_abgr;

  static void Init() {
    kDecl.begin()
        .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
        .end();
  };
  static bgfx::VertexDecl kDecl;
};


/**
 * @brief Cube 虽然是用来渲染立方体的， 但是它是用来证明Position-Color VertexDecl和渲染一个简单的prebuilt demo的
 * 最好例子
 * 
 */
class Cube : public IRenderFilter
{
public:
    Cube();

    ~Cube();

    void Init(uint32_t width, uint32_t height) override;

    bool Update(float delta_time, MouseState* mouse) override;

    void Shutdown() override;

private:
    bgfx::VertexBufferHandle m_vbh;
    bgfx::IndexBufferHandle  m_ibh[5];
    bgfx::ProgramHandle      m_program;

    uint32_t                 m_width, m_height;
    float                    m_elapsed_time;
    bool                     m_a;
    bool                     m_r;
    bool                     m_g;
    bool                     m_b;
};

}  // namespace px
