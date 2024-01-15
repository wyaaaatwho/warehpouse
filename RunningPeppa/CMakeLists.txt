cmake_minimum_required(VERSION 3.27)
project(RunningPeppa C)

set(CMAKE_C_STANDARD 11)

include_directories("C:\\Users\\26711\\SDL2-2.28.5\\SDL2-2.28.5\\x86_64-w64-mingw32\\include")
include_directories("C:\\Users\\26711\\SDL2-2.28.5\\SDL2-2.28.5\\x86_64-w64-mingw32\\bin")


add_executable(
        RunningPeppa main.c
        header.h
        initiating.c
        initiating.h
        shutdown.c
        shutdown.h
        pages.c
        pages.h
        peppa.c
        peppa.h
        obstacle.c
        obstacle.h
        status.c
        status.h
        global.h
)

target_link_libraries(RunningPeppa PRIVATE mingw32 SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer )
