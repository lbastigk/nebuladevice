cmake_minimum_required(VERSION 3.24)

project(Nebuladevice LANGUAGES C CXX)

option(NEBULA_FETCH_DEPENDENCIES
       "Download Nebuladevice dependencies with FetchContent" ON)
option(NEBULA_BUILD_ENGINE
       "Build the native Linux Nebuladevice engine" OFF)
option(NEBULA_BUILD_MINGW64
       "Build the Nebuladevice Foundation layer for MinGW-w64" OFF)
option(NEBULA_BUILD_TESTS
       "Build Nebuladevice GoogleTest tests" ON)
option(NEBULA_BUILD_LEGACY_TESTS
       "Build the legacy NebuladeviceTests programs" OFF)

if(NEBULA_FETCH_DEPENDENCIES AND NOT TARGET nebuladevice_dependencies)
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Dependencies.cmake")
endif()

if(NEBULA_BUILD_ENGINE)
    message(FATAL_ERROR
        "The Nebuladevice Linux backend is not implemented yet. "
        "Set NEBULA_BUILD_ENGINE=OFF until the platform layer is ported.")
endif()

if(NEBULA_BUILD_MINGW64)
    if(NOT WIN32 OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(FATAL_ERROR
            "NEBULA_BUILD_MINGW64 requires a MinGW-w64 CMake toolchain.")
    endif()

    file(GLOB_RECURSE nebula_foundation_sources CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Nebuladevice/foundation/*.cc"
    )
    list(FILTER nebula_foundation_sources EXCLUDE REGEX
        "/jobs/serial/")

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
        -fpermissive
    )
    target_include_directories(nebuladevice_foundation PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/external"
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

if(NEBULA_BUILD_LEGACY_TESTS)
    if(NOT TARGET nebuladevice_foundation)
        message(FATAL_ERROR
            "NEBULA_BUILD_LEGACY_TESTS requires NEBULA_BUILD_MINGW64=ON.")
    endif()

    file(GLOB legacy_test_directories LIST_DIRECTORIES true
        "${CMAKE_CURRENT_SOURCE_DIR}/src/NebulaDeviceTests/*"
    )
    foreach(legacy_test_directory IN LISTS legacy_test_directories)
        if(NOT IS_DIRECTORY "${legacy_test_directory}")
            continue()
        endif()

        get_filename_component(legacy_test_name
            "${legacy_test_directory}" NAME)
        file(GLOB_RECURSE legacy_test_sources CONFIGURE_DEPENDS
            "${legacy_test_directory}/*.cc"
            "${legacy_test_directory}/*.cpp"
            "${legacy_test_directory}/*.c"
        )
        if(NOT legacy_test_sources)
            continue()
        endif()

        set(legacy_target "legacy_${legacy_test_name}")
        add_executable("${legacy_target}" ${legacy_test_sources})
        target_compile_definitions("${legacy_target}" PRIVATE
            __WIN32__
            WIN32
            _HAS_EXCEPTIONS=0
        )
        target_compile_options("${legacy_target}" PRIVATE
            -fno-exceptions
            -fno-rtti
            -fpermissive
        )
        target_include_directories("${legacy_target}" PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/include"
            "${CMAKE_CURRENT_SOURCE_DIR}/external"
        )
        target_link_libraries("${legacy_target}" PRIVATE
            nebuladevice_foundation
        )
    endforeach()
endif()

if(NEBULA_BUILD_TESTS)
    enable_testing()
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
        URL_HASH SHA256=7b42b4d6ed48810c5362c265a17faebe90dc2373c885e5216439d37927f02926
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    add_subdirectory(Tests)
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
        "Nebuladevice build is staged; select NEBULA_BUILD_MINGW64 for MinGW-w64."
    VERBATIM
)
