#pragma once

#include <SDL2/SDL.h>
#include "../graphics/font_manager.h"


class PlayerScreen
{

public:

    PlayerScreen();


    void render(
        SDL_Renderer* renderer,
        FontManager& font
    );

};