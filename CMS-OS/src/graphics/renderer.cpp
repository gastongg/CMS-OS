#include "renderer.h"

#include <iostream>



Renderer::Renderer(
    SDL_Window* window
)
{

    renderer =
    SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC
    );


    if(!renderer)
    {
        std::cout
        << "Error renderer: "
        << SDL_GetError()
        << std::endl;
    }

}





Renderer::~Renderer()
{

    if(renderer)
    {
        SDL_DestroyRenderer(renderer);
    }

}





SDL_Renderer* Renderer::get()
{

    return renderer;

}





void Renderer::present()
{

    SDL_RenderPresent(renderer);

}