#pragma once

#include <bgfx/bgfx.h>
#include <bimg/bimg.h>

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

bgfx::VertexDecl PosColorVertex::kDecl;

// A Cube
static PosColorVertex kCubeVertices[] = {
    {-1.0f, 1.0f, 1.0f, 0xff000000},   {1.0f, 1.0f, 1.0f, 0xff0000ff},
    {-1.0f, -1.0f, 1.0f, 0xff00ff00},  {1.0f, -1.0f, 1.0f, 0xff00ffff},
    {-1.0f, 1.0f, -1.0f, 0xffff0000},  {1.0f, 1.0f, -1.0f, 0xffff00ff},
    {-1.0f, -1.0f, -1.0f, 0xffffff00}, {1.0f, -1.0f, -1.0f, 0xffffffff},
};

static const uint16_t kCubeTriList[] = {
    0, 1,
    2,  // 0
    1, 3, 2, 4, 6,
    5,  // 2
    5, 6, 7, 0, 2,
    4,  // 4
    4, 2, 6, 1, 5,
    3,  // 6
    5, 7, 3, 0, 4,
    1,  // 8
    4, 5, 1, 2, 3,
    6,  // 10
    6, 3, 7,
};

static const char *kDTNames[]{
    "Triangle List", "Triangle Strip", "Lines", "Line Strip", "Points",
};

static const uint64_t kDTState[]{
    UINT16_C(0),          BGFX_STATE_PT_TRISTRIP,
    BGFX_STATE_PT_LINES,  BGFX_STATE_PT_LINESTRIP,
    BGFX_STATE_PT_POINTS,
};

BX_STATIC_ASSERT(BX_COUNTOF(kDTState) == BX_COUNTOF(kDTNames));

}  // namespace px
