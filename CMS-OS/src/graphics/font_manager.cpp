#include "font_manager.h"

#include <iostream>



FontManager::FontManager()
{
    font = nullptr;
}




FontManager::~FontManager()
{
    if(font)
    {
        TTF_CloseFont(font);
    }
}





bool FontManager::load(
    const std::string& path,
    int size
)
{

    font = TTF_OpenFont(
        path.c_str(),
        size
    );


    if(!font)
    {

        std::cout
        << "Error cargando fuente: "
        << TTF_GetError()
        << std::endl;


        return false;
    }


    return true;

}





void FontManager::draw(
    SDL_Renderer* renderer,
    const std::string& text,
    int x,
    int y
)
{

    if(!font)
        return;



    SDL_Color color;

    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;



    SDL_Surface* surface =
    TTF_RenderText_Solid(
        font,
        text.c_str(),
        color
    );


    if(!surface)
        return;



    SDL_Texture* texture =
    SDL_CreateTextureFromSurface(
        renderer,
        surface
    );



    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;



    SDL_FreeSurface(surface);



    SDL_RenderCopy(
        renderer,
        texture,
        nullptr,
        &rect
    );


    SDL_DestroyTexture(texture);

}