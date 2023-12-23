


#include "game.hpp"


#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "TexturedRectangle.hpp"
#include "splashSCreen.hpp"
#include "menu.hpp"
#include "player1.hpp"
#include "player2.hpp"
#include "field.hpp"
#include "pausemenu.hpp"
#include "starting.hpp"
#include "goal1.hpp"
#include "goal2.hpp"
#include "player1wins.hpp"
#include "player2wins.hpp"

 TexturedRectangle menu_BackGround;
 TexturedRectangle after_menu;
 TexturedRectangle football;
 TexturedRectangle player1;
 TexturedRectangle player2;
 TexturedRectangle argentina;
 TexturedRectangle brazil;
 TexturedRectangle belgium;
 TexturedRectangle england;
 TexturedRectangle france;
 TexturedRectangle germany;
 TexturedRectangle italy;
 TexturedRectangle ned;
 TexturedRectangle portugal;
 TexturedRectangle spain;
 TexturedRectangle uruguya;
 TexturedRectangle object1;
 TexturedRectangle walking1;
 TexturedRectangle walking2;
 TexturedRectangle walking3;
 TexturedRectangle walking4;
 TexturedRectangle reflected1;
 TexturedRectangle reflected2;
 TexturedRectangle reflected3;
 TexturedRectangle reflected4;
 TexturedRectangle tennis;
 TexturedRectangle resume;
 TexturedRectangle gamescreen;
 TexturedRectangle point1;
 TexturedRectangle point2;
 TexturedRectangle wins1;
 TexturedRectangle wins2;
 
 SDL_Renderer* renderer;
 int count = 0;
 int count1 = 0;
TTF_Font* font = TTF_OpenFont("./font/liberation.ttf" , 24);

int width = 1380;
 int height = 720;
 Gamestate currState = splashscreen;
 string filename;
//currState = splashscreen;
    // SDL_Surface* tile = IMG_Load("image/football-3.png") ;
    // SDL_Texture* texture ;
Game::Game()
{
    //This where we initialize everything
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO | TTF_Init()| IMG_INIT_PNG)==-1)) { 
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
   
     SDL_CreateWindowAndRenderer( width , height , 0 , &window , &renderer);
     SDL_SetWindowTitle(window , "First game!!");
     isGameRunning = true;
     font ;
    


    

     loadMedia();
     loop();
}

Game::~Game()
{
    //Freeing all the allocated part
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    menu_BackGround.~TexturedRectangle();
   TTF_CloseFont(font);

    //SDL_DestroyTexture(texture);
    SDL_Quit();
}

bool Game::loadMedia()
{
    
    if (!menu_BackGround.textureMedia(renderer , "./image/main_menu.png"))
    {
        cout << "none png" <<endl;
        success = false;
        
    }

    if(!after_menu.textureMedia(renderer , "./image/main.png"))
    {
        cout << "main not found" << endl;
    }

    if(!football.textureMedia(renderer , "./image/football_field_final.png"))
    {
        cout<< "footbatll field is not loaded" << endl;
        success = false;
    }

    if(!player1.textureMedia(renderer , "./image/player1-01.png"))
    {
        cout << "Player 1 is not loaded!" << endl;
        success = false;
    }

    if (!player2.textureMedia(renderer , "./image/player2-01.png"))
    {
        cout << "Player 2 is not loaded!" << endl;
        success = false;
    }

    if(!argentina.textureMedia(renderer, "./image/arg.png"))
    {
        cout << "Argentina Flag has not been loaded!" << endl;
        success = false;
    }
    if(!brazil.textureMedia(renderer, "./image/bra.png"))
    {
        cout << "Brazil Flag has not been loaded!" << endl;
        success = false;
    }
    if(!belgium.textureMedia(renderer, "./image/bel.png"))
    {
        cout << "Belgium Flag has not been loaded!" << endl;
        success = false;
    }
    if(!england.textureMedia(renderer, "./image/England.png"))
    {
        cout << "England Flag has not been loaded!" << endl;
        success = false;
    }
    if(!germany.textureMedia(renderer, "./image/ger.png"))
    {
        cout << "Germany Flag has not been loaded!" << endl;
        success = false;
    }
    if(!italy.textureMedia(renderer, "./image/italy.png"))
    {
        cout << "Italy Flag has not been loaded!" << endl;
        success = false;
    }
    if(!ned.textureMedia(renderer, "./image/Ned.png"))
    {
        cout << "Netherland Flag has not been loaded!" << endl;
        success = false;
    }
     if(!portugal.textureMedia(renderer, "./image/port.png"))
    {
        cout << "Portugal Flag has not been loaded!" << endl;
        success = false;
    }
    if(!spain.textureMedia(renderer, "./image/spa.png"))
    {
        cout << "Spain Flag has not been loaded!" << endl;
        success = false;
    }
    if(!uruguya.textureMedia(renderer, "./image/Uru.png"))
    {
        cout << "Uruguya Flag has not been loaded!" << endl;
        success = false;
    }
    if(!france.textureMedia(renderer, "./image/france.png"))
    {
        cout << "France Flag has not been loaded!" << endl;
        success = false;
    }
    if(!object1.textureMedia(renderer , "./image/football.png"))
    {
        cout << "tennis ball is not loaded!" << endl;
    }
    if(!walking1.textureMedia(renderer , "./image/walking1-01.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!walking2.textureMedia(renderer , "./image/walking2.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!walking3.textureMedia(renderer , "./image/walking3.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!walking4.textureMedia(renderer , "./image/walking4.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!reflected1.textureMedia(renderer , "./image/reflected1-01.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!reflected2.textureMedia(renderer , "./image/reflected2.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!reflected3.textureMedia(renderer , "./image/reflected3.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!reflected4.textureMedia(renderer , "./image/reflected4.png"))
    {
        cout<< "Walking 1 is not loaded!" << endl;
        success = false;
    }
    if(!tennis.textureMedia(renderer , "./image/walking1-01.png"))
    {
        success = false;
    }
    if(!resume.textureMedia(renderer, "./image/pausemenu.png"))
    {
        success = false;
    }
    if(!gamescreen.textureMedia(renderer, "./image/starting.png"))
    {
        success = false;
    }
    if(!point1.textureMedia(renderer , "./image/player1scores.png"))
    {
        success = false;
    }
    if(!point2.textureMedia(renderer , "./image/player2scores.png"))
    {
        success = false;
    }
    if(!wins1.textureMedia(renderer , "./image/Player1wins.png"))
    {
        success = false;
    }
    if(!wins2.textureMedia(renderer , "./image/Player2wins.png"))
    {
        success = false;
    }
    return success;
}


void Game::loop()
{
    while(isGameRunning)
    {
        
        Uint32 button;
        button = SDL_GetMouseState(&m_mouseX,&m_mouseY);
             input();
               update();
            render();
           
          

        
    }
}

void Game::render()
{
    

    SDL_SetRenderDrawColor(renderer , 103, 117, 105, 0.66);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0; 
    rect.w = width;
    rect.h = height;

    
    SDL_RenderFillRect(renderer, &rect);

   




    
    
    //SDL_RenderPresent(renderer);

    SDL_Delay(100);
}



void Game::input()
{
    SDL_Event event;
   
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isGameRunning = false;
        }

        // if (event.type == SDL_KEYDOWN)
        // {
        //     if (event.key.keysym.sym == SDLK_ESCAPE)
        //     {
        //         isGameRunning = false;
        //     }

        //     //frameNumber = 0;

            
        // }
         
        switch (currState)
        {
        case main_menu : menu::handleEvent_menu(event); break;
        case splashscreen: Splash::handleEvent_splashScreen(event); break;
        case Football_Field: field::handleEvent_field(event); break;
        case Player1 : count =  play1::handleEvent_menu(event);break;
       case Player2 : count1 = shift :: handleEvent_menu(event);break;
       case Pausemenu : pausemenu::handleEvent_menu(event); break;
       case GameScreen : starting::handleEvent_gameScreen(event); break;
       case Goal1: goal1::handleEvent_goal1Screen(event);break;
        case Goal2: goal2::handleEvent_goal2Screen(event);break;
        case Player1Wins: player1wins::handleEvent_menu(event);break;
        case Player2Wins: player2wins::handleEvent_menu(event);break;
        }
        
        //Splash::handle_splashScreen();
        

        

    }
    

    switch (currState)
        {
        case main_menu : menu::handle_menu(); break;
        case splashscreen: Splash::handle_splashScreen(); break;
        case Football_Field: field::handle_field(count , count1 , event);break;
        case Player1 : play1::handle_menu();break;
        case Player2 : shift:: handle_menu();break;
        case Pausemenu : pausemenu::handle_menu();break;
        case GameScreen : starting::handle_gameScreen();break;
        case Goal1 : goal1::handle_goal1Screen();break;
        case Goal2: goal2::handle_goal2Screen();break;
        case Player1Wins: player1wins::handle_menu();break;
        case Player2Wins: player2wins::handle_menu();break;
        case Exit: isGameRunning = false;
            
        
        }
        


}


int Game::GetMouseX()
{
    return m_mouseX;
}

int Game::GetMouseY()
{
    return m_mouseY;
}


void Game::StopAppLoop()
{
   isGameRunning = false; 
};

