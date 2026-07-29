#pragma once

#include <SDL2/SDL.h>

class Renderer
{

public:

    Renderer(SDL_Window* window);

    ~Renderer();


    SDL_Renderer* get();


    void present();


private:

    SDL_Renderer* renderer;

};