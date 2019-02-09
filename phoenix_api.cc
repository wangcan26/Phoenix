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

    void PXShutdown(){
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

    render::Mesh *LoadMesh(const char* file_path)
    {
        using namespace render;
        bx::FileReaderI *reader = GetFileReader();
        if(bx::open(reader, file_path))
        {
            Mesh *mesh = render::LoadMesh(reader);
            bx::close(reader);
            return mesh;
        }

        return NULL;
    }

    bgfx::TextureHandle LoadTexture(const char* name, uint32_t flags, uint8_t skip, bgfx::TextureInfo* info, bimg::Orientation::Enum* orientation)
    {
        return render::LoadTexture(GetFileReader(), name, flags, skip, info, orientation);
    }

}