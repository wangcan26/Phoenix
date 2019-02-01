#include <bimg/decode.h>
#include "render_utils.h"
#include "file_utils.h"

namespace px
{
    namespace render
    {

        bgfx::ShaderHandle LoadShader(bx::FileReaderI* reader, const char* name)
        {
            char _file_path[512];
            const char* _shader_path = "???";

            switch (bgfx::getRendererType())
            {
                case bgfx::RendererType::OpenGL: 
                    _shader_path = "shaders/glsl/"; 
                    break;
                case bgfx::RendererType::OpenGLES:
                    _shader_path = "shaders/essl/";
                    break;
                case bgfx::RendererType::Count:
                    BX_CHECK(false, "You should not be here!");
                    break;
                default:
                    break;
            }

            bx::strCopy(_file_path, BX_COUNTOF(_file_path), _shader_path);
            bx::strCat(_file_path, BX_COUNTOF(_file_path), name);
            bx::strCat(_file_path, BX_COUNTOF(_file_path), ".bin");

            bgfx::ShaderHandle _handle = bgfx::createShader(file::LoadMem(reader, _file_path));
            bgfx::setName(_handle, _file_path);
        
            return _handle;
        }

        bgfx::ProgramHandle LoadProgram(bx::FileReaderI* reader, const char* vs_name, const char* fs_name){
            bgfx::ShaderHandle vsh = LoadShader(reader, vs_name);
            bgfx::ShaderHandle fsh = BGFX_INVALID_HANDLE;

            if(NULL != fs_name)
            {
                fsh = LoadShader(reader, fs_name);
            }

            return bgfx::createProgram(vsh, fsh, true);
        }

        bgfx::TextureHandle LoadTexture(bx::FileReaderI* reader, const char* file_path, uint32_t flags, uint8_t skip, bgfx::TextureInfo* info, bimg::Orientation::Enum* orientation)
        {
            BX_UNUSED(skip);
            bgfx::TextureHandle handle = BGFX_INVALID_HANDLE;

            uint32_t _size;
            void* _data = file::Load(reader, GetDefaultAllocator(), file_path, &_size);

            if(NULL != _data)
            {
                bimg::ImageContainer *_image_container = bimg::imageParse(GetDefaultAllocator(), _data, _size);

                if(NULL != _image_container)
                {
                    DBG("The Image %s 's size is %d, %d", file_path, _image_container->m_width, _image_container->m_height);
                }
            }
            
            return handle;
        }
    } // render
    
}