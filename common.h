#pragma once


#include <bx/bx.h>
#include <bx/file.h>
#include <bx/string.h>
#include <bgfx/bgfx.h>
#include <bimg/bimg.h>

#include "log.h"

namespace  px
{
    bx::AllocatorI *GetDefaultAllocator();

    extern bx::AllocatorI *gAllocator;

    typedef bx::StringT<&gAllocator> String;

} // namespace px
