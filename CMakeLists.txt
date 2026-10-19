cmake_minimum_required(VERSION 3.24)

project(NebulaDevice LANGUAGES C CXX)

option(NEBULA_FETCH_DEPENDENCIES
       "Download NebulaDevice dependencies with FetchContent" ON)
option(NEBULA_BUILD_ENGINE
       "Build the native Linux NebulaDevice engine" OFF)
option(NEBULA_BUILD_MINGW64
       "Build the NebulaDevice Foundation layer for MinGW-w64" OFF)

if(NEBULA_FETCH_DEPENDENCIES AND NOT TARGET nebuladevice_dependencies)
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Dependencies.cmake")
endif()

if(NEBULA_BUILD_ENGINE)
    message(FATAL_ERROR
        "The NebulaDevice Linux backend is not implemented yet. "
        "Set NEBULA_BUILD_ENGINE=OFF until the platform layer is ported.")
endif()

if(NEBULA_BUILD_MINGW64)
    if(NOT WIN32 OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(FATAL_ERROR
            "NEBULA_BUILD_MINGW64 requires a MinGW-w64 CMake toolchain.")
    endif()

    file(GLOB_RECURSE nebula_foundation_sources CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/code/foundation/*.cc"
    )

    add_library(nebuladevice_foundation STATIC
        ${nebula_foundation_sources}
    )
    target_compile_definitions(nebuladevice_foundation PRIVATE
        __WIN32__
        WIN32
        _HAS_EXCEPTIONS=0
    )
    target_compile_options(nebuladevice_foundation PRIVATE
        -fno-exceptions
        -fno-rtti
    )
    target_include_directories(nebuladevice_foundation PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/code"
        "${CMAKE_CURRENT_SOURCE_DIR}/code/foundation"
        "${CMAKE_CURRENT_SOURCE_DIR}/code/extlibs"
    )
    target_link_libraries(nebuladevice_foundation PUBLIC
        nebuladevice_dependencies
        ws2_32
        user32
        dbghelp
        dxerr9
        winmm
    )
endif()

add_library(nebuladevice INTERFACE)

if(TARGET nebuladevice_foundation)
    target_link_libraries(nebuladevice INTERFACE
        nebuladevice_foundation
    )
elseif(TARGET nebuladevice_dependencies)
    target_link_libraries(nebuladevice INTERFACE
        nebuladevice_dependencies
    )
endif()

add_custom_target(nebuladevice_status
    COMMAND ${CMAKE_COMMAND} -E echo
        "NebulaDevice build is staged; select NEBULA_BUILD_MINGW64 for MinGW-w64."
    VERBATIM
)
