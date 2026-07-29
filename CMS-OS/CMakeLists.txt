cmake_minimum_required(VERSION 3.16)

project(CHOCOMIX_SYSTEM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)


add_executable(chocomix

    src/main.cpp

    src/graphics/renderer.cpp
    src/graphics/font_manager.cpp

    src/library/track.cpp

    src/audio/music_manager.cpp

    src/ui/boot_screen.cpp
    src/ui/home_screen.cpp
    src/ui/library_screen.cpp
    src/ui/player_screen.cpp
    src/ui/settings_screen.cpp
    src/ui/player_screen.cpp

)


target_compile_definitions(
    chocomix
    PRIVATE
    SDL_MAIN_HANDLED
)


target_link_libraries(
    chocomix

    SDL2::SDL2
    SDL2_ttf::SDL2_ttf

)