#include <bimg/decode.h>
#include "render_utils.h"
#include "file_utils.h"

namespace bgfx
{
     int32_t read(bx::ReaderI* _reader, bgfx::VertexDecl& _decl, bx::Error* _err = NULL);
}   

namespace px
{
    namespace render
    {

        //Image
        static void ImageReleaseCb(void *ptr, void* user_data)
        {
            BX_UNUSED(ptr);
            bimg::ImageContainer* _image_container = (bimg::ImageContainer*)user_data;
            bimg::imageFree(_image_container);
        }



        //Mesh
        
        Group::Group()
        {
            Reset();
        }

        void Group::Reset()
        {
            m_vbh.idx = bgfx::kInvalidHandle;
            m_ibh.idx = bgfx::kInvalidHandle;
            m_prims.clear();
        }

        void Mesh::Load(bx::ReaderSeekerI* reader)
        {
#define     PX_CHUNK_MAGIC_VB  BX_MAKEFOURCC('V', 'B', ' ', 0x1)
#define     PX_CHUNK_MAGIC_IB  BX_MAKEFOURCC('I', 'B', ' ', 0x0)
#define     PX_CHUNK_MAGIC_IBC BX_MAKEFOURCC('I', 'B', 'C', 0x0)
#define     PX_CHUNK_MAGIC_PRI BX_MAKEFOURCC('P', 'R', 'I', 0x0)

            Group  group;
            bx::AllocatorI *allocator = GetDefaultAllocator();

            uint32_t  chunk;
            bx::Error err;
            while(4 == bx::read(reader, chunk, &err)
            &&  err.isOk())
            {
                switch (chunk)
                {
                    case PX_CHUNK_MAGIC_VB:
                    {
                        bx::read(reader, group.m_sphere);
                        bx::read(reader, group.m_aabb);
                        bx::read(reader, group.m_obb);

                        bgfx::read(reader, m_decl);

                        uint16_t stride = m_decl.getStride();

                        uint16_t num_vertices;
                        bx::read(reader, num_vertices);
                        const bgfx::Memory *mem = bgfx::alloc(num_vertices*stride);
                        bx::read(reader, mem->data, mem->size);

                        group.m_vbh = bgfx::createVertexBuffer(mem, m_decl);
                        DBG("Can Test Mesh Load VB---- stride(%d), num_vertices(%d))", stride, num_vertices);
                    }
                        break;
                    case PX_CHUNK_MAGIC_IB:
                    {
                        uint32_t  num_indices;
                        bx::read(reader, num_indices);
                        const bgfx::Memory* mem = bgfx::alloc(num_indices*2);
                        bx::read(reader, mem->data, mem->size);
                        group.m_ibh = bgfx::createIndexBuffer(mem);
                        DBG("Can Test Mesh Load IB----");
                    }
                        break;
                    case PX_CHUNK_MAGIC_IBC:
                    {
                        //DBG("Can Test Mesh Load IBC ----");
                    }
                        break;
                    case PX_CHUNK_MAGIC_PRI:
                    {
                        //DBG("Can Test Mesh Load PRI----");
                        uint16_t len;
                        bx::read(reader, len);

                        tinystl::string material;
                        material.resize(len);
                        bx::read(reader, const_cast<char*>(material.c_str()), len);
                        
                        uint16_t num;
                        bx::read(reader, num);
                        
                        for(uint32_t ii = 0; ii < num; ++ii)
                        {
                            bx::read(reader, len);

                            tinystl::string name;
                            name.resize(len);
                            bx::read(reader, const_cast<char*>(name.c_str()), len);

                            Primitive prim;
                            bx::read(reader, prim.m_start_index);
                            bx::read(reader, prim.m_num_indices);
                            bx::read(reader, prim.m_start_vertex);
                            bx::read(reader, prim.m_num_vertices);
                            bx::read(reader, prim.m_sphere);
                            bx::read(reader, prim.m_aabb);
                            bx::read(reader, prim.m_obb);

                            group.m_prims.push_back(prim);
                        }

                        m_groups.push_back(group);
                        group.Reset();

                    }
                        break;
                    default:
                    {
                        //DBG("%08x at %d", chunk, bx::skip(reader, 0) );
                    }
                        break;
                }
            }

        }

        void Mesh::UnLoad()
        {
            for(GroupArray::const_iterator it = m_groups.begin(), it_end = m_groups.end(); it != it_end; ++it)
            {
                const Group& group = *it;
                bgfx::destroy(group.m_vbh);

                if(bgfx::isValid(group.m_ibh))
                {
                    bgfx::destroy(group.m_ibh);
                }
            }
            m_groups.clear();
        }

        void Mesh::Submit(bgfx::ViewId id, bgfx::ProgramHandle program, const float* mtx, uint64_t state)
        const 
        {
            if(BGFX_STATE_MASK == state)
            {
                state = 0
                    | BGFX_STATE_WRITE_RGB
                    | BGFX_STATE_WRITE_A
                    | BGFX_STATE_WRITE_Z
                    | BGFX_STATE_DEPTH_TEST_LESS
                    | BGFX_STATE_CULL_CCW
                    | BGFX_STATE_MSAA
                    ;
            }

            bgfx::setTransform(mtx);
            bgfx::setState(state);

            for(GroupArray::const_iterator it = m_groups.begin(), it_end = m_groups.end(); it != it_end;
            ++it)
            {
                const Group& group = *it;

                bgfx::setIndexBuffer(group.m_ibh);
                bgfx::setVertexBuffer(0, group.m_vbh);
                bgfx::submit(id, program, 0, it != it_end-1);
            }
        }

        //-------------------- functions -------------------------------------//

        Mesh *LoadMesh(bx::ReaderSeekerI* reader)
        {
            Mesh *mesh = new Mesh;
            mesh->Load(reader);
            return mesh;
        }

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
                    if(NULL != orientation)
                    {
                        *orientation = _image_container->m_orientation;
                    }

                    const bgfx::Memory* mem = bgfx::makeRef(
                        _image_container->m_data
                        ,_image_container->m_size
                        ,ImageReleaseCb
                        ,_image_container
                    );

                    file::UnLoad(_data);

                    if(_image_container->m_cubeMap)
                    {
                        handle = bgfx::createTextureCube(
                            uint16_t(_image_container->m_width)
                            , 1 < _image_container->m_numMips
                            , _image_container->m_numLayers
                            , bgfx::TextureFormat::Enum(_image_container->m_format)
                            , flags
                            , mem
                        );
                    }else if( 1 < _image_container->m_depth)
                    {
                        handle = bgfx::createTexture3D(
                            uint16_t(_image_container->m_width)
                            ,uint16_t(_image_container->m_height)
                            ,uint16_t(_image_container->m_depth)
                            ,1 < _image_container->m_numMips
                            ,bgfx::TextureFormat::Enum(_image_container->m_format)
                            ,flags
                            ,mem 
                        );
                    }
                    else if(bgfx::isTextureValid(0, false, _image_container->m_numLayers,
                    bgfx::TextureFormat::Enum(_image_container->m_format), flags))
                    {
                        DBG("bgfx_utils image info w-h(%d, %d), nummips(%d), format(%d)", _image_container->m_width,
					    _image_container->m_height, _image_container->m_numMips, _image_container->m_format);
                        handle = bgfx::createTexture2D(
                            uint16_t(_image_container->m_width)
                            ,uint16_t(_image_container->m_height)
                            ,1 < _image_container->m_numMips
                            ,_image_container->m_numLayers
                            ,bgfx::TextureFormat::Enum(_image_container->m_format)
                            ,flags
                            ,mem
                        );
                    }

                    if(bgfx::isValid(handle))
                    {
                        bgfx::setName(handle, file_path);
                    }
                    
                    if(NULL != info)
                    {
                        bgfx::calcTextureSize(
                            *info
                            ,uint16_t(_image_container->m_width)
                            ,uint16_t(_image_container->m_height)
                            ,uint16_t(_image_container->m_depth)
                            ,_image_container->m_cubeMap
                            ,1 < _image_container->m_numMips
                            ,_image_container->m_numLayers
                            ,bgfx::TextureFormat::Enum(_image_container->m_format)
                        );
                    }
                }
            }
            
            return handle;
        }
    } // render
    
}