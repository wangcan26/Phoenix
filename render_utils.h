#pragma once
#include "common.h"

namespace px
{

    namespace render
    {

        bgfx::ShaderHandle LoadShader(bx::FileReaderI* reader, const char* name);
        
        bgfx::ProgramHandle LoadProgram(bx::FileReaderI* reader, const char *vs_name, const char *fs_name);

        bgfx::TextureHandle LoadTexture(bx::FileReaderI* reader, const char* file_path, uint32_t flags, uint8_t skp, bgfx::TextureInfo* info, bimg::Orientation::Enum* orientation);
    }

} // namespace px
