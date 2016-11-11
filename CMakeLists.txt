cmake_minimum_required(VERSION 3.0)

project(Shooter)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE ENGINESRCS "./Engine/Cpp/*.cpp")
file(GLOB_RECURSE GAMESRCS "./Game/Cpp/*.cpp")

include_directories("./Engine/Headers/")
include_directories("./Engine/Headers/Systems")
include_directories("./Game/Headers/")
include_directories("./Game/Headers/Systems")

include_directories(/usr/include/SDL2)

add_executable(Shooter ${ENGINESRCS} ${GAMESRCS})

target_link_libraries(Shooter /usr/lib/x86_64-linux-gnu/libSDL2-2.0.so)
