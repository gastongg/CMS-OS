#pragma once

#include <SDL2/SDL.h>

#include "../graphics/font_manager.h"


class HomeScreen
{

public:

    HomeScreen();


    void render(
        SDL_Renderer* renderer,
        FontManager& font
    );


    void handleEvent(
        SDL_Event& event
    );


    bool isPressed();


    int getSelected();



private:

    int selected;

    bool pressed;

};