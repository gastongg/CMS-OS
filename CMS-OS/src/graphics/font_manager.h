#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>


class FontManager
{

public:

    FontManager();

    ~FontManager();


    bool load(
        const std::string& path,
        int size
    );


    void draw(
        SDL_Renderer* renderer,
        const std::string& text,
        int x,
        int y
    );


private:

    TTF_Font* font = nullptr;

};