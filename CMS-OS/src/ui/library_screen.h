#pragma once

#include <SDL2/SDL.h>

#include "../graphics/font_manager.h"
#include "../audio/music_manager.h"

#include <vector>
#include <string>


class LibraryScreen
{

public:

    LibraryScreen(
        MusicManager& music
    );


    void render(
        SDL_Renderer* renderer,
        FontManager& font
    );


    void handleEvent(
        SDL_Event& event
    );


    bool backPressed();



private:

    MusicManager& music;

    int selected;

    bool back;

};