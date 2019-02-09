#include "file_utils.h"
#include "log.h"

namespace px
{
    namespace file
    {
        static String kCurrentDir;

        bool FileReader::open(const bx::FilePath &file_path, bx::Error *err)
        {
             String _file_path(kCurrentDir);
             _file_path.append(file_path.get());
             return super::open(_file_path.getPtr(), err);
        }

        bool FileWriter::open(const bx::FilePath& file_path, bool append, bx::Error* err)
        {
            String _file_path(kCurrentDir);
            _file_path.append(file_path.get());
            return super::open(_file_path.getPtr(), append, err);
        }

        const bgfx::Memory* LoadMem(bx::FileReaderI* reader, const char* file_path){
        
            if(bx::open(reader, file_path))
            {
                uint32_t _size = (uint32_t)bx::getSize(reader);
                const bgfx::Memory* _mem = bgfx::alloc(_size+1);
                bx::read(reader, _mem->data, _size);
                bx::close(reader);
                _mem->data[_mem->size-1] = '\0';
                return _mem;
            }

            DBG("Failed to load %s.", file_path);
            return NULL;
        }

        void* Load(bx::FileReaderI* reader, bx::AllocatorI* allocator, const char* file_path, uint32_t* size)
        {
            if(bx::open(reader, file_path))
            {
                 uint32_t _size = (uint32_t)bx::getSize(reader);
                 void* _data = BX_ALLOC(allocator, _size);
                 bx::read(reader, _data, _size);
                 bx::close(reader);
                 if(NULL != size)
                 {
                    *size = _size;
                 }
                 return _data;
             }else{
                 DBG("Failed to open: %s.", file_path);
             }

             if(NULL != size)
             {
                 *size = 0;
             }

             return NULL;
        }

        void UnLoad(void* ptr)
        {
            BX_FREE(GetDefaultAllocator(), ptr);
        }
    }
}