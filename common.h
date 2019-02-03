#pragma once


#include <bx/bx.h>
#include <bx/file.h>
#include <bx/string.h>
#include <bgfx/bgfx.h>
#include <bimg/bimg.h>
struct TinyStlAllocator
{
    static void* static_allocate(size_t bytes);
    static void static_deallocate(void* ptr, size_t /*bytes*/);
};

#define  TINYSTL_ALLOCATOR TinyStlAllocator
#include <tinystl/string.h>

#include "log.h"

namespace  px
{
    bx::AllocatorI *GetDefaultAllocator();

    extern bx::AllocatorI *gAllocator;

    typedef bx::StringT<&gAllocator> String;

} // namespace px
