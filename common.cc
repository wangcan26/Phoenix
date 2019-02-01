#include <bx/readerwriter.h>
#include "common.h"

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