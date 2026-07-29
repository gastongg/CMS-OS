#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>


#include "core/config.h"
#include "core/app_state.h"


#include "graphics/renderer.h"
#include "graphics/font_manager.h"


#include "ui/boot_screen.h"
#include "ui/home_screen.h"
#include "ui/library_screen.h"
#include "ui/player_screen.h"
#include "ui/settings_screen.h"


#include "audio/music_manager.h"



int main(int argc, char* argv[])
{


    if(SDL_Init(
        SDL_INIT_VIDEO |
        SDL_INIT_AUDIO
    ) != 0)
    {

        std::cout
        << SDL_GetError()
        << std::endl;

        return 1;

    }



    if(TTF_Init() != 0)
    {

        std::cout
        << TTF_GetError()
        << std::endl;

        SDL_Quit();

        return 1;

    }





    SDL_Window* window =
    SDL_CreateWindow(
        "CHOCOMIX SYSTEM",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        CMS::SCREEN_WIDTH,
        CMS::SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );



    if(!window)
    {

        SDL_Quit();

        return 1;

    }




    Renderer renderer(window);



    FontManager font;



    font.load(
        "assets/fonts/DejaVuSans.ttf",
        24
    );





    BootScreen boot;

    HomeScreen home;


    MusicManager music;


    music.scanFolder(
        "assets/music"
    );


    LibraryScreen library(music);


    PlayerScreen player;

    SettingsScreen settings;





    CMS::AppState state =
    CMS::AppState::BOOT;



    bool running = true;



    while(running)
    {

        SDL_Event event;



        while(SDL_PollEvent(&event))
        {


            if(event.type == SDL_QUIT)
            {

                running = false;

            }



            switch(state)
            {

                case CMS::AppState::HOME:

                    home.handleEvent(event);

                    break;


                case CMS::AppState::LIBRARY:

                    library.handleEvent(event);

                    break;


                default:

                    break;

            }


        }






        switch(state)
        {


            case CMS::AppState::BOOT:

                boot.update();

                boot.render(
                    renderer.get()
                );


                if(boot.finished())
                {
                    state =
                    CMS::AppState::HOME;
                }

                break;




            case CMS::AppState::HOME:

                home.render(
                    renderer.get(),
                    font
                );


                if(home.isPressed())
                {

                    if(home.getSelected() == 1)
                    {
                        state =
                        CMS::AppState::LIBRARY;
                    }


                    if(home.getSelected() == 0)
                    {
                        state =
                        CMS::AppState::PLAYER;
                    }


                    if(home.getSelected() == 2)
                    {
                        state =
                        CMS::AppState::SETTINGS;
                    }

                }


                break;





            case CMS::AppState::LIBRARY:

                library.render(
                    renderer.get(),
                    font
                );


                if(library.backPressed())
                {
                    state =
                    CMS::AppState::HOME;
                }

                break;





            case CMS::AppState::PLAYER:

                player.render(
                    renderer.get(),
                    font
                );

                break;





            case CMS::AppState::SETTINGS:

                settings.render(
                    renderer.get(),
                    font
                );

                break;


        }




        renderer.present();


        SDL_Delay(16);

    }





    SDL_DestroyWindow(window);


    TTF_Quit();

    SDL_Quit();


    return 0;

}