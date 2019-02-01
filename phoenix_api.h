#pragma once
#include "common.h"

namespace px
{

    void PXInit();
    void PXDeInit();

    bx::FileReaderI *GetFileReader();
    bx::FileWriterI *GetFileWriter();

    void* Load(const char* file_path, uint32_t* size);

    bgfx::ProgramHandle LoadProgram(const char *vs_name, const char* fs_name);
    
    bgfx::TextureHandle LoadTexture(const char* name, uint32_t flags = BGFX_SAMPLER_NONE, uint8_t skip = 0,
    bgfx::TextureInfo* info = NULL, bimg::Orientation::Enum* orientation = NULL);

    
}