#include <bx/readerwriter.h>
#include <bx/allocator.h> 
#include "common.h"

void* TinyStlAllocator::static_allocate(size_t bytes)
{
    using namespace bx;
    return BX_ALLOC(px::GetDefaultAllocator(), bytes);
}

void TinyStlAllocator::static_deallocate(void* ptr, size_t/*bytes*/)
{
    if(NULL != ptr)
    {
        using namespace bx;
        BX_FREE(px::GetDefaultAllocator(), ptr);
    }
}

namespace px
{

    bx::AllocatorI* gAllocator = GetDefaultAllocator();

    bx::AllocatorI* GetDefaultAllocator()
    {
        BX_PRAGMA_DIAGNOSTIC_PUSH();
        BX_PRAGMA_DIAGNOSTIC_IGNORED_MSVC(4459);
        static bx::DefaultAllocator kAllocator;
        return &kAllocator;
    }

}