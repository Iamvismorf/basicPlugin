# project(Hyproverview)
# cmake_minimum_required(VERSION 3.19)
#
# set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_EXPORT_COMPILE_COMMANDS on)
# find_package(PkgConfig REQUIRED)
# pkg_check_modules(deps REQUIRED IMPORTED_TARGET
#     hyprland
#     libdrm
#     libinput
#     libudev
#     pangocairo
#     pixman-1
#     wayland-server
#     xkbcommon
# )
#
# add_library(hyproverview SHARED main.cpp)

cmake_minimum_required(VERSION 3.27)

project(hyproverview
    DESCRIPTION "hyprwinwrap plugin for Hyprland"
    VERSION 0.1
)

set(CMAKE_CXX_STANDARD 23)

# file(GLOB_RECURSE SRC "*.cpp")

add_library(hyproverview SHARED main.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(deps REQUIRED IMPORTED_TARGET
    hyprland
    libdrm
    libinput
    libudev
    pangocairo
    pixman-1
    wayland-server
    xkbcommon
)
target_link_libraries(hyproverview PRIVATE rt PkgConfig::deps)

install(TARGETS hyproverview)

