cmake_minimum_required(VERSION 3.20)
project(Sims2PC VERSION 1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform detection
if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|x86|i[3-6]86")
    set(SIMS2_PLATFORM "PC")
    add_compile_definitions(SIMS2_PLATFORM_PC=1)
    message(STATUS "Building for PC (x86/x64)")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "powerpc|ppc")
    set(SIMS2_PLATFORM "GC")
    add_compile_definitions(SIMS2_PLATFORM_GC=1)
    message(STATUS "Building for GameCube (PPC)")
else()
    set(SIMS2_PLATFORM "PC")
    add_compile_definitions(SIMS2_PLATFORM_PC=1)
    message(STATUS "Building for PC (unknown arch: ${CMAKE_SYSTEM_PROCESSOR})")
endif()

# Find SDL2 for PC builds
if(SIMS2_PLATFORM STREQUAL "PC")
    # Try system SDL2 first, then fall back to local copy
    set(SDL2_DIR "/f/coding/Decompiles/Tools/SDL2-2.30.11/x86_64-w64-mingw32")
    if(EXISTS "${SDL2_DIR}/include/SDL2/SDL.h")
        set(SDL2_FOUND TRUE)
        set(SDL2_INCLUDE_DIRS "${SDL2_DIR}/include")
        set(SDL2_LIBRARIES "${SDL2_DIR}/lib/libSDL2.dll.a" "${SDL2_DIR}/lib/libSDL2main.a")
        message(STATUS "Found SDL2 (local): ${SDL2_DIR}")
    else()
        find_package(SDL2 QUIET)
        if(SDL2_FOUND)
            message(STATUS "Found SDL2 (system): ${SDL2_INCLUDE_DIRS}")
        else()
            message(STATUS "SDL2 not found — will use stubs")
        endif()
    endif()

    find_package(OpenGL QUIET)
    if(OpenGL_FOUND)
        message(STATUS "Found OpenGL: ${OPENGL_LIBRARIES}")
    else()
        message(STATUS "OpenGL not found — will use stubs")
    endif()
endif()

# Include paths
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/classes
    ${CMAKE_SOURCE_DIR}/include/core
    ${CMAKE_SOURCE_DIR}/include/templates
    ${CMAKE_SOURCE_DIR}/include/platform
)

# Collect all portable C++ source files
file(GLOB DECOMP_SOURCES
    src/decomp_cpp/*.cpp
)

# Collect system-specific source files
file(GLOB CORE_SOURCES
    src/core/*.cpp
    src/sim/*.cpp
    src/objects/*.cpp
    src/render/*.cpp
    src/ui/*.cpp
    src/audio/*.cpp
    src/effects/*.cpp
    src/camera/*.cpp
    src/animation/*.cpp
    src/build_mode/*.cpp
    src/goals/*.cpp
    src/inventory/*.cpp
    src/save/*.cpp
    src/skin/*.cpp
    src/templates/*.cpp
)

# Platform-specific sources
if(SIMS2_PLATFORM STREQUAL "PC")
    file(GLOB PLATFORM_SOURCES src/platform/pc/*.cpp src/platform/pc/*.c)
else()
    file(GLOB PLATFORM_SOURCES src/platform/gc/*.cpp)
endif()

# Main executable
add_executable(sims2pc
    src/platform/pc/main_pc.cpp
    ${DECOMP_SOURCES}
    ${PLATFORM_SOURCES}
)

# Per-file compile options
set_source_files_properties(src/platform/pc/missing_stubs.cpp PROPERTIES COMPILE_FLAGS "-fpermissive")
set_source_files_properties(src/platform/pc/clib_wrappers.cpp PROPERTIES COMPILE_FLAGS "-fpermissive -Wno-builtin-declaration-mismatch")

# Compiler warnings
target_compile_options(sims2pc PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W3 /wd4244 /wd4267 /wd4305 /wd4996>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wno-unused-variable -Wno-unused-function -Wno-sign-compare -Wno-narrowing -fpermissive -Wno-builtin-declaration-mismatch>
)

# Linker flags — allow duplicate symbols (decomp files have overlapping definitions)
target_link_options(sims2pc PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wl,--allow-multiple-definition>
)

# Link libraries
if(SDL2_FOUND)
    target_include_directories(sims2pc PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(sims2pc PRIVATE ${SDL2_LIBRARIES})
    target_compile_definitions(sims2pc PRIVATE SIMS2_HAS_SDL2=1)
endif()

if(OpenGL_FOUND)
    target_link_libraries(sims2pc PRIVATE OpenGL::GL)
    target_compile_definitions(sims2pc PRIVATE SIMS2_HAS_OPENGL=1)
endif()

# Status
message(STATUS "")
message(STATUS "=== Sims 2 PC Port Build ===")
message(STATUS "  Platform: ${SIMS2_PLATFORM}")
message(STATUS "  decomp_cpp sources: ${DECOMP_SOURCES}")
message(STATUS "  SDL2: ${SDL2_FOUND}")
message(STATUS "  OpenGL: ${OpenGL_FOUND}")
message(STATUS "============================")
