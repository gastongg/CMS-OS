#include "home_screen.h"


HomeScreen::HomeScreen()
{

    selected = 0;

    pressed = false;

}





void HomeScreen::handleEvent(
    SDL_Event& event
)
{

    pressed = false;


    if(event.type == SDL_KEYDOWN)
    {

        switch(event.key.keysym.sym)
        {

            case SDLK_DOWN:

                if(selected < 2)
                    selected++;

                break;



            case SDLK_UP:

                if(selected > 0)
                    selected--;

                break;



            case SDLK_RETURN:

                pressed = true;

                break;

        }

    }

}





void HomeScreen::render(
    SDL_Renderer* renderer,
    FontManager& font
)
{

    SDL_SetRenderDrawColor(
        renderer,
        20,
        20,
        20,
        255
    );


    SDL_RenderClear(renderer);



    font.draw(
        renderer,
        "CHOCOMIX SYSTEM",
        120,
        40
    );



    font.draw(
        renderer,
        selected == 0 ? "> PLAYER" : "  PLAYER",
        160,
        120
    );


    font.draw(
        renderer,
        selected == 1 ? "> LIBRARY" : "  LIBRARY",
        160,
        160
    );


    font.draw(
        renderer,
        selected == 2 ? "> SETTINGS" : "  SETTINGS",
        160,
        200
    );

}





bool HomeScreen::isPressed()
{

    return pressed;

}





int HomeScreen::getSelected()
{

    return selected;

}