#pragma once
#include "common.h"

namespace px
{
    namespace render
    {
        class Mesh;
    }

    void PXInit();
    void PXShutdown();

    bx::FileReaderI *GetFileReader();
    bx::FileWriterI *GetFileWriter();

    void* Load(const char* file_path, uint32_t* size);

    render::Mesh *LoadMesh(const char* file_path);

    bgfx::ProgramHandle LoadProgram(const char *vs_name, const char* fs_name);
    
    bgfx::TextureHandle LoadTexture(const char* name, uint32_t flags = BGFX_SAMPLER_NONE, uint8_t skip = 0,
    bgfx::TextureInfo* info = NULL, bimg::Orientation::Enum* orientation = NULL);

    
}