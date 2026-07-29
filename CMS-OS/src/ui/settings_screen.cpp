#include "settings_screen.h"



SettingsScreen::SettingsScreen()
{

}





void SettingsScreen::render(
    SDL_Renderer* renderer,
    FontManager& font
)
{

    SDL_SetRenderDrawColor(
        renderer,
        25,
        25,
        25,
        255
    );


    SDL_RenderClear(renderer);



    font.draw(
        renderer,
        "SETTINGS",
        180,
        30
    );


    font.draw(
        renderer,
        "SYSTEM SETTINGS",
        120,
        150
    );

}





void SettingsScreen::handleEvent(
    SDL_Event& event
)
{

}