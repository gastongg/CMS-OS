#include "library_screen.h"

#include <iostream>



LibraryScreen::LibraryScreen(
    MusicManager& musicManager
)
:
music(musicManager)
{

    selected = 0;

    back = false;

}





void LibraryScreen::handleEvent(
    SDL_Event& event
)
{

    back = false;


    if(event.type == SDL_KEYDOWN)
    {

        switch(event.key.keysym.sym)
        {

            case SDLK_ESCAPE:

                back = true;

                break;



            case SDLK_DOWN:

                if(selected < music.getTrackCount() - 1)
                {
                    selected++;
                }

                break;



            case SDLK_UP:

                if(selected > 0)
                {
                    selected--;
                }

                break;



            case SDLK_RETURN:

                if(music.getTrackCount() > 0)
                {

                    std::cout
                    << "CARGAR TRACK: "
                    << music.getTrack(selected).title
                    << std::endl;

                }

                break;

        }

    }

}





void LibraryScreen::render(
    SDL_Renderer* renderer,
    FontManager& font
)
{

    SDL_SetRenderDrawColor(
        renderer,
        15,
        15,
        15,
        255
    );


    SDL_RenderClear(renderer);



    font.draw(
        renderer,
        "LIBRARY",
        170,
        30
    );



    int y = 80;



    for(
        int i = 0;
        i < music.getTrackCount();
        i++
    )
    {


        std::string text;


        if(i == selected)
        {
            text = "> ";
        }
        else
        {
            text = "  ";
        }



        text += music.getTrack(i).title;



        font.draw(
            renderer,
            text,
            80,
            y
        );



        y += 35;

    }

}





bool LibraryScreen::backPressed()
{

    return back;

}