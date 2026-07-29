#pragma once

#include <SDL2/SDL.h>


class BootScreen
{

public:

    BootScreen();


    void update();


    void render(
        SDL_Renderer* renderer
    );


    bool finished();


private:

    bool done;

};