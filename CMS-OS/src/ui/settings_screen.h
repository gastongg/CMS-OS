#pragma once

#include <SDL2/SDL.h>

#include "../graphics/font_manager.h"


class SettingsScreen
{

public:

    SettingsScreen();


    void render(
        SDL_Renderer* renderer,
        FontManager& font
    );


    void handleEvent(
        SDL_Event& event
    );


};