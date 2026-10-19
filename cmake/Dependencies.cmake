include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    zlib
    GIT_REPOSITORY https://github.com/madler/zlib.git
    GIT_TAG v1.3.1
    GIT_SHALLOW TRUE
)

FetchContent_Declare(
    sqlite3
    URL https://www.sqlite.org/2024/sqlite-amalgamation-3460100.zip
)

FetchContent_Declare(
    tinyxml
    URL https://downloads.sourceforge.net/project/tinyxml/tinyxml/2.6.2/tinyxml_2_6_2.tar.gz
    URL_HASH SHA256=15bdfdcec58a7da30adc87ac2b078e4417dbe5392f3afb719f9ba6d062645593
)

FetchContent_Declare(
    lua
    URL https://www.lua.org/ftp/lua-5.1.5.tar.gz
)

FetchContent_Declare(
    directxmath
    GIT_REPOSITORY https://github.com/microsoft/DirectXMath.git
    GIT_TAG jun2026
    GIT_SHALLOW TRUE
)

FetchContent_Declare(
    wine_headers
    URL https://codeload.github.com/wine-mirror/wine/tar.gz/16b3e9b0536b2bf92c79249114087757aae9dd80
    URL_HASH SHA256=68807bb9de2056438d6edd28d224d9216a17c3d1e5035ddaa808f122879e925f
    SOURCE_SUBDIR cmake/not-a-project
)

FetchContent_MakeAvailable(zlib sqlite3 tinyxml lua directxmath wine_headers)

set(wine_compat_include_dir
    "${CMAKE_CURRENT_BINARY_DIR}/generated/wine-headers"
)
file(MAKE_DIRECTORY "${wine_compat_include_dir}")
configure_file(
    "${wine_headers_SOURCE_DIR}/include/xact3.h"
    "${wine_compat_include_dir}/xact3.h"
    COPYONLY
)
configure_file(
    "${wine_headers_SOURCE_DIR}/include/xact3wb.h"
    "${wine_compat_include_dir}/xact3wb.h"
    COPYONLY
)

if(NOT TARGET nebula_zlib)
    add_library(nebula_zlib ALIAS zlibstatic)
endif()

if(NOT TARGET nebula_sqlite3)
    add_library(nebula_sqlite3 STATIC
        "${sqlite3_SOURCE_DIR}/sqlite3.c"
    )
    target_include_directories(nebula_sqlite3
        PUBLIC "${sqlite3_SOURCE_DIR}"
    )
    set_target_properties(nebula_sqlite3 PROPERTIES
        POSITION_INDEPENDENT_CODE ON
    )
endif()

if(NOT TARGET nebula_tinyxml)
    add_library(nebula_tinyxml STATIC
        "${tinyxml_SOURCE_DIR}/tinyxml.cpp"
        "${tinyxml_SOURCE_DIR}/tinyxmlerror.cpp"
        "${tinyxml_SOURCE_DIR}/tinyxmlparser.cpp"
    )
    target_include_directories(nebula_tinyxml
        PUBLIC "${tinyxml_SOURCE_DIR}"
    )
endif()

if(NOT TARGET nebula_lua)
    file(GLOB lua_sources CONFIGURE_DEPENDS
        "${lua_SOURCE_DIR}/src/*.c"
    )
    list(FILTER lua_sources EXCLUDE REGEX "/lua\\.c$")
    list(FILTER lua_sources EXCLUDE REGEX "/luac\\.c$")

    add_library(nebula_lua STATIC ${lua_sources})
    target_include_directories(nebula_lua
        PUBLIC "${lua_SOURCE_DIR}/src"
    )
endif()

add_library(nebuladevice_dependencies INTERFACE)
target_link_libraries(nebuladevice_dependencies INTERFACE
    nebula_zlib
    nebula_sqlite3
    nebula_tinyxml
    nebula_lua
)

target_include_directories(nebuladevice_dependencies INTERFACE
    "${directxmath_SOURCE_DIR}/Inc"
    "${wine_compat_include_dir}"
)
