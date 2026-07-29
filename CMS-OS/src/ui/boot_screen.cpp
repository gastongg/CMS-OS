#include "boot_screen.h"


BootScreen::BootScreen()
{

    done = false;

}





void BootScreen::update()
{

    done = true;

}





void BootScreen::render(
    SDL_Renderer* renderer
)
{

    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        255
    );


    SDL_RenderClear(renderer);

}





bool BootScreen::finished()
{

    return done;

}