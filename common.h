#pragma once


#include <bx/bx.h>
#include <bx/file.h>
#include <bx/string.h>
#include <bx/macros.h>
#include <bx/spscqueue.h>
#include <bgfx/bgfx.h>
#include <bimg/bimg.h>
struct TinyStlAllocator
{
    static void* static_allocate(size_t bytes);
    static void static_deallocate(void* ptr, size_t /*bytes*/);
};

#define  TINYSTL_ALLOCATOR TinyStlAllocator
#include <tinystl/string.h>
#include <tinystl/vector.h>
#include <tinystl/unordered_map.h>

#include "log.h"

namespace  px
{
    struct WindowHandle
    {
	    uint16_t idx;
    };

    inline bool isValid(WindowHandle handle)
	{
		return UINT16_MAX != handle.idx;
	}

    bx::AllocatorI *GetDefaultAllocator();

    extern bx::AllocatorI *gAllocator;

    typedef bx::StringT<&gAllocator> String;

} // namespace px
