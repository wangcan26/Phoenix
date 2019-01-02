#include <iostream>
#include <bgfx/bgfx.h>
#include <bgfx/defines.h>
#include <bx/pixelformat.h>

int main(int argc, char**argv)
{
	std::cout << "test bgfx ..." << std::endl;
	
	//Init bgfx
	bgfx::Init init;
	init.type = bgfx::RendererType::OpenGLES;
	init.vendorId = BGFX_PCI_ID_INTEL;
	init.resolution.width = 800;
	init.resolution.height = 600;
	init.resolution.reset = BGFX_RESET_VSYNC;
	
	bgfx::init(init);
	
	// Set view 0 clear state.
	bgfx::setViewClear(0
		, BGFX_CLEAR_COLOR|BGFX_CLEAR_DEPTH
		, 0x303030ff
		, 1.0f
		, 0
		);
		
		
	std::cout << "test bgfx end..." << std::endl;
	
	return 0;
} 