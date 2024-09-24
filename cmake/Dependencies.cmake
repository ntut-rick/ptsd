cmake_minimum_required(VERSION 3.21)
project(MyProject)

find_package(OpenGL REQUIRED)

include(ExternalProject)
include(GNUInstallDirs)

# Define options for SDL2 libraries
set(BUILD_SHARED_LIBS FALSE)
set(SDL2IMAGE_INSTALL OFF)
set(SDL2IMAGE_VENDORED ON)
set(SDL2TTF_INSTALL OFF)
set(SDL2TTF_VENDORED ON)
set(SDL2MIXER_INSTALL OFF)
set(SDL2MIXER_VENDORED ON)
set(SDL2MIXER_FLAC OFF)
set(SDL2MIXER_MIDI OFF)
set(SDL2MIXER_MOD OFF)
set(SDL2MIXER_OPUS OFF)
set(SDL2MIXER_OGG OFF)
set(SDL2MIXER_VORBIS OFF)
set(SDL2MIXER_VOC OFF)

# Add submodules as CMake projects
add_subdirectory(lib/glew/build/cmake)
add_subdirectory(lib/sdl2)
add_subdirectory(lib/sdl2_image)
add_subdirectory(lib/sdl2_ttf)
add_subdirectory(lib/sdl2_mixer)
add_subdirectory(lib/spdlog)
add_subdirectory(lib/glm)
add_subdirectory(lib/googletest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_compile_definitions(GLEW_NO_GLU)

# Add ImGui as a library
set(IMGUI_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/backends/imgui_impl_sdl2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/backends/imgui_impl_opengl3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/imgui_widgets.cpp
)

set(IMGUI_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui/backends/
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/sdl2/include/
)

add_library(ImGui STATIC
    ${IMGUI_SOURCE}
)
target_include_directories(ImGui PUBLIC
    ${IMGUI_INCLUDE_DIR}
)

# Define dependency libraries
set(DEPENDENCY_LINK_LIBRARIES
    ${OPENGL_LIBRARY}
    glew_s
    SDL2::SDL2-static
    SDL2_image::SDL2_image-static
    SDL2_ttf::SDL2_ttf-static
    SDL2_mixer::SDL2_mixer-static
    spdlog::spdlog
    ImGui
)

set(DEPENDENCY_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/sdl2/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/spdlog/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/glm/
    ${IMGUI_INCLUDE_DIR}
)

