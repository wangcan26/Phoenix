#pragma once

#include "common.h"

namespace px
{
    namespace file
    {
        class FileReader : public bx::FileReader
        {
            typedef bx::FileReader super;

        public:
            virtual bool open(const bx::FilePath &file_path, bx::Error *err) override;
        };

        class FileWriter : public bx::FileWriter
        {
            typedef bx::FileWriter super;
        public:
            virtual bool open(const bx::FilePath &file_path, bool append, bx::Error *err) override;
        };

        const bgfx::Memory* LoadMem(bx::FileReaderI* reader, const char* file_path);

        void* Load(bx::FileReaderI* reader, bx::AllocatorI* allocator, const char* file_path, uint32_t* size);

        void UnLoad(void *ptr);
        
    } // namespace file

} // namespace px