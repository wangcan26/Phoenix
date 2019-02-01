#include <bgfx/bgfx.h>
#include <bgfx/defines.h>
#include <bx/pixelformat.h>
#include <iostream>

#include "phoenix_api.h"
#include "cube.h"

int main(int argc, char **argv)
{
	std::cout << "test bgfx ..." << std::endl;

	//Init Phoenix Api
	px::PXInit();

	// Init bgfx
	bgfx::Init init;
	init.type = bgfx::RendererType::OpenGLES;
	init.vendorId = BGFX_PCI_ID_INTEL;
	init.resolution.width = 800;
	init.resolution.height = 600;
	init.resolution.reset = BGFX_RESET_VSYNC;

	bgfx::init(init);

	// Set view 0 clear state.
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f,
					   0);

	std::cout << "test bgfx end..." << std::endl;

	//Init Scene
	// Create a Cube vertex stream declaration
	px::PosColorVertex::Init();

	// Create vertex buffer for the Cube
	bgfx::VertexBufferHandle m_vbh;
	m_vbh = bgfx::createVertexBuffer(
		bgfx::makeRef(px::kCubeVertices, sizeof(px::kCubeVertices)),
		px::PosColorVertex::kDecl);

	bgfx::IndexBufferHandle m_ibh[BX_COUNTOF(px::kDTState)];

	m_ibh[0] = bgfx::createIndexBuffer(
		bgfx::makeRef(px::kCubeTriList, sizeof(px::kCubeTriList)));

	uint32_t m_size;
	px::LoadTexture("textures/rgb.hdr", 0 | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_W_CLAMP);
	std::cout << "test bgfx load texture size: " << m_size << std::endl;

	// Create program from shaders
	bgfx::ProgramHandle m_program;
	//m_program = px::LoadProgram("vs_cubes", "fs_cubes");
	

	return 0;
}