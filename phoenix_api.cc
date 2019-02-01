#include "file_utils.h"
#include "render_utils.h"
#include "phoenix_api.h"

namespace px
{

    static bx::FileReaderI *kFileReader = NULL;
    static bx::FileWriterI *kFileWriter = NULL;

    void PXInit(){
        kFileReader = BX_NEW(GetDefaultAllocator(), file::FileReader);
        kFileWriter = BX_NEW(GetDefaultAllocator(), file::FileWriter);
    }

    void PXDeInit(){
        BX_DELETE(GetDefaultAllocator(), kFileReader);
        kFileReader = NULL;

        BX_DELETE(GetDefaultAllocator(), kFileWriter);
        kFileWriter = NULL;
    }

    bx::FileWriterI* GetFileWriter()
    {
        return kFileWriter;
    }

    bx::FileReaderI* GetFileReader()
    {
        return kFileReader;
    }

    bgfx::ProgramHandle LoadProgram(const char* vs_name, const char* fs_name)
    {
        return render::LoadProgram(GetFileReader(), vs_name, fs_name);
    }

    void* Load(const char* file_path, uint32_t* size)
    {
        return file::Load(GetFileReader(), GetDefaultAllocator(), file_path, size);
    }

    bgfx::TextureHandle LoadTexture(const char* name, uint32_t flags, uint8_t skip, bgfx::TextureInfo* info, bimg::Orientation::Enum* orientation)
    {
        return render::LoadTexture(GetFileReader(), name, flags, skip, info, orientation);
    }

}