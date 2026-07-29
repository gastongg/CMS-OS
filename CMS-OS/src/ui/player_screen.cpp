#include "player_screen.h"


PlayerScreen::PlayerScreen()
{

}


void PlayerScreen::render(
    SDL_Renderer* renderer,
    FontManager& font
)
{

    font.draw(
        renderer,
        "PLAYER",
        50,
        50
    );

}