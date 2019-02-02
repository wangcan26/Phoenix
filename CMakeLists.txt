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

#set flags
set(CMAKE_C_FLAGS "-Wc++98-compat")

#  settings env config
use_cxx()

#set cmake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

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

#add external library to this project
add_subdirectory(external)

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

#link external libraries
#find_package(GLFW3 REQUIRED)
message("Find GLFW3 include path -> ${GLFW3_INCLUDE_DIR}: lib -> ${GLFW3_LIBRARY}")
include_directories(${GLFW3_INCLUDE_DIR})

target_link_libraries(phoenix_main ${GLFW3_LIBRARY})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR})