cmake_minimum_required(VERSION 3.0.2)

project(Phoenix)

#functions 
macro(use_cxx)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  else ()
    set (CMAKE_CXX_STANDARD 14)
  endif ()
endmacro(use_cxx)

if(APPLE)
macro(ADD_FRAMEWORK fwname appname)
    find_library(FRAMEWORK_${fwname}
    NAMES ${fwname}
    PATHS ${CMAKE_OSX_SYSROOT}/System/Library
    PATH_SUFFIXES Frameworks
    NO_DEFAULT_PATH)
    if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
        MESSAGE(ERROR ": Framework ${fwname} not found")
    else()
        TARGET_LINK_LIBRARIES(${appname} "${FRAMEWORK_${fwname}}/${fwname}")
        MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
    endif()
endmacro(ADD_FRAMEWORK)
endif(APPLE)

#  settings env config
use_cxx()

#  settings thirdparty config
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install)

# the main part
set(sources_main main.cc 
    render_utils.cc
    file_utils.cc
    common.cc
    phoenix_api.cc
  )
add_executable(phoenix_main ${sources_main})

add_subdirectory(bgfxLib)

#link xcode system libraries
if(APPLE)
	ADD_FRAMEWORK(Foundation phoenix_main)
	ADD_FRAMEWORK(Cocoa phoenix_main)
	ADD_FRAMEWORK(Metal phoenix_main)
	ADD_FRAMEWORK(QuartzCore phoenix_main)
endif(APPLE)

#link bgfx
include_directories(${THIRD_PARTY_DIR}/include)

target_link_libraries(phoenix_main ${THIRD_PARTY_DIR}/lib/libbgfx.a)
target_link_libraries(phoenix_main ${THIRD_PARTY_DIR}/lib/libbimg.a)
target_link_libraries(phoenix_main ${THIRD_PARTY_DIR}/lib/libbx.a)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR})