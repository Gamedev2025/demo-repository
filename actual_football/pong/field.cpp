#include "field.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"
#include "player1.hpp"
#include "player2.hpp"
#include "math.hpp"
#include <iostream>
extern TexturedRectangle football;
extern  TexturedRectangle argentina;
 extern TexturedRectangle brazil;
extern  TexturedRectangle belgium;
extern  TexturedRectangle england;
extern  TexturedRectangle france;
extern  TexturedRectangle germany;
extern  TexturedRectangle italy;
extern  TexturedRectangle ned;
extern  TexturedRectangle portugal;
extern  TexturedRectangle spain;
extern TexturedRectangle uruguya;
extern TexturedRectangle object1;
extern TexturedRectangle walking1;
extern TexturedRectangle walking2;
extern TexturedRectangle walking3;
extern TexturedRectangle walking4;
extern TexturedRectangle reflected1;
extern TexturedRectangle reflected2;
extern TexturedRectangle reflected3;
extern TexturedRectangle reflected4;
extern TexturedRectangle tennis;

SDL_Rect Player1rect;
SDL_Rect Player2rect;

extern Gamestate currState;
extern SDL_Renderer* renderer;

extern bool isGameRunning ;
extern int width ;
 extern int height;
 
  
  int positionx = 273;
  int positiony = 425;
  int positionx1 = 400;
  int positiony1 = 400;
  int frameNumber = 0;
  int frameNumber1 = 0;
  //ball position
  int SCREEN_WIDTH = 670;
  int SCREEN_HEIGHT = 560;
  int dx = 10;
  int dy = 10;
//DynamicText* object;
 field::~field()
    {
    
    }

   void field:: ball()
   {
        
   }

void field::handleEvent_field(SDL_Event e)
{
    int x , y;
    SDL_GetMouseState(&x , &y);
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    cout << x << " " << y << endl;
    //bool running = true;
    //SDL_Event e;
       
        
            if(e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
             {
                currState = main_menu;
                
             }
        //      switch (e.key.keysym.sym) {
        //             case SDLK_w:
        //                 positiony -= 6;
        //                 frameNumber++;
        //                 break;
        //             case SDLK_s:
        //                 positiony -= 6;
        //                 frameNumber++;
        //                 break;
        //             case SDLK_a:
        //                 positionx -= 6;
        //                 frameNumber++;
        //                 break;
        //             case SDLK_d:
        //                 positionx += 6;
        //                 frameNumber++;
        //                 break;
        //             case SDLK_UP:
        //                 positiony1 -= 6;
        //                 frameNumber1++;
        //                 break;
        //             case SDLK_DOWN:
        //                positiony1 += 6;
        //                 frameNumber1++;
        //                 break;
        //             case SDLK_LEFT:
        //                 positionx1 -= 6;
        //                 frameNumber1++;
        //                 break;
        //             case SDLK_RIGHT:
        //                positionx1 += 6;
        //                 frameNumber++;
        //                 break;
        //         }
        //         //break;
        // }
           // player 1
             if (e.key.keysym.sym == SDLK_w &&  positiony >= 340)
             {
                cout << "w" << endl;
                frameNumber++;
                
                positiony -= 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_s && positiony <= 580)
             {
                cout << "y" << endl;
                 frameNumber++;
                
                positiony += 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_a && positionx >= 138)
             {
                cout << "a" << endl;
                 frameNumber++;
                
                positionx -= 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_d && positionx <= 690)
             {
                cout << "d" << endl;
                 frameNumber++;
                
                positionx += 6;
                cout << frameNumber<< endl;

             }
            //player 2
             if (e.key.keysym.sym == SDLK_UP &&  positiony <= 540)
             {
                cout << "w" << endl;
                frameNumber1++;
                
                positiony1 -= 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_DOWN && positiony >= 340)
             {
                cout << "y" << endl;
                 frameNumber1++;
                
                positiony1 += 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_LEFT && positionx <= 690)
             {
                cout << "a" << endl;
                 frameNumber1++;
                
                positionx1 -= 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_RIGHT && positionx >= 138)
             {
                cout << "a" << endl;
                 frameNumber1++;
                
                positionx1 += 6;
                cout << frameNumber1 << endl;

             }
             

		// {
			
			
				
			
				
		// }
	 	// if (state[SDL_SCANCODE_RIGHT])
		// {
			
			
				
			
		// }
	 	// if (state[SDL_SCANCODE_UP]
		// ){
			
			
		// 		y -= 6;
			
		// }
	 	// if (state[SDL_SCANCODE_DOWN])
		// {
		
			
		// 		y += 6;
			
		// }

             
        
        
        
}
}     

        
    
    

    


void field::handle_field(int value , int value1 , SDL_Event e)
{
    //object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
     football.SetPosition(0 ,0 , width , height);
     //brazil.SetPosition(515 , 235 , 140 , 40);

     football.playFrame(0 ,0 , width , height , 0);
     
      football.Render(renderer);
    // For player1
    switch (value)
    {
    case 1:
        brazil.SetPosition(515 , 235 , 140 , 40);
       
        brazil.Render(renderer);
        break;
    case 2:
        argentina.SetPosition(515 , 235 , 140 , 40);
        
        argentina.Render(renderer);
        break;
    case 3:
        spain.SetPosition(515 , 235 , 140 , 40);
       
        spain.Render(renderer);
        break;
    case 4:
        germany.SetPosition(515 , 235 , 140 , 40);
       
        germany.Render(renderer);
        break;
    case 5:
        portugal.SetPosition(515 , 235 , 140 , 40);
       
        portugal.Render(renderer);
        break;
    case 6:
        uruguya.SetPosition(515 , 235 , 140 , 40);
       
        uruguya.Render(renderer);
        break;
     case 7:
        france.SetPosition(515 , 235 , 140 , 40);
       
        france.Render(renderer);
        break;
    case 8:
        italy.SetPosition(515 , 235 , 140 , 40);
        
        italy.Render(renderer);
        break;
    case 9:
        ned.SetPosition(515 , 235 , 140 , 40);
        
        ned.Render(renderer);
        break;
    case 10:
        england.SetPosition(515 , 235 , 140 , 40);
        
        england.Render(renderer);
        break;
    case 11:
        belgium.SetPosition(515 , 235 , 140 , 40);
        
        belgium.Render(renderer);
        break;                           
  
    }

     // For player2
    switch (value1)
    {
    case 1:
        brazil.SetPosition(792 , 235 , 140 , 40);
        
        brazil.Render(renderer);
        break;
    case 2:
        argentina.SetPosition(792 , 235 , 140 , 40);
        
        argentina.Render(renderer);
        break;
    case 3:
        spain.SetPosition(792 , 235 , 140 , 40);
        
        spain.Render(renderer);
        break;
    case 4:
        germany.SetPosition(792 , 235 , 140 , 40);
       
        germany.Render(renderer);
        break;
    case 5:
        portugal.SetPosition(792 , 235 , 140 , 40);
      
        portugal.Render(renderer);
        break;
    case 6:
        uruguya.SetPosition(792 , 235 , 140 , 40);
        
        uruguya.Render(renderer);
        break;
     case 7:
        france.SetPosition(792 , 235 , 140 , 40);
      
        france.Render(renderer);
        break;
    case 8:
        italy.SetPosition(792 , 235 , 140 , 40);
        
        italy.Render(renderer);
        break;
    case 9:
        ned.SetPosition(792 , 235 , 140 , 40);
       
        ned.Render(renderer);
        break;
    case 10:
        england.SetPosition(792 , 235 , 140 , 40);
       
        england.Render(renderer);
        break;
    case 11:
        belgium.SetPosition(792 , 235 , 140 , 40);
       
        belgium.Render(renderer);
        break;                           
  
    }
     
    //SDL_Event event;
    
    
    // if(e.key.keysym.sym == SDLK_w)
    //          {
    //             cout << "w" << endl;
    //             x += 6;
    //             cout << x << endl;
    //          }
             
            // if(frameNumber == 0)
            // {
            //     walking1.SetPosition(positionx , positiony , 100 , 150);
            // walking1.Render(renderer);
            // }
            // if(frameNumber == 1)
            // {
            //      walking2.SetPosition(positionx , positiony , 100 , 150);
            // walking2.Render(renderer);

            // }
            // if(frameNumber == 2)
            // {
            //      walking3.SetPosition(positionx , positiony , 100 , 150);
            // walking3.Render(renderer);
            // }

            // if(frameNumber == 3)
            // {
            //      walking4.SetPosition(positionx , positiony , 100 , 150);
            // walking4.Render(renderer);
            // }
             
            object1.SetPosition(SCREEN_WIDTH , SCREEN_HEIGHT , 25 , 25);

            
            object1.Render(renderer);
                walking1.SetPosition(positionx , positiony , 100 , 105);
            walking1.Render(renderer);
                
            

            // if(frameNumber1 == 0)
            // {
            //     reflected1.SetPosition(positionx1 , positiony1 , 50 , 55);
            // reflected1.Render(renderer);
            // }
            // if(frameNumber == 1)
            // {
            //      reflected2.SetPosition(positionx1 , positiony1 , 100 , 150);
            // reflected2.Render(renderer);

            // }
            // if(frameNumber1 == 2)
            // {
            //      reflected3.SetPosition(positionx1 , positiony1 , 100 , 150);
            // reflected3.Render(renderer);
            // }

            // if(frameNumber1 == 3)
            // {
            //      reflected4.SetPosition(positionx1 , positiony1 , 100 , 150);
            // reflected4.Render(renderer);
            // }
            

            
            
                reflected1.SetPosition(positionx1 , positiony1 , 100 , 105);
            reflected1.Render(renderer);
                
            
             if(frameNumber > 3) frameNumber = 0;
            if(frameNumber1 > 3) frameNumber1 = 0;
            
        SCREEN_WIDTH += dx;
        SCREEN_HEIGHT += dy;

        if (SCREEN_WIDTH <=138  || SCREEN_WIDTH >= 1250)
		{
			dx = dx * -1;
			// touchNum += 1;
			//Mix_PlayChannel(-1, bouncing, 0);
		}
        if (SCREEN_HEIGHT <=435  || SCREEN_HEIGHT >= 700)
		{
			dy = dy * -1;
			// touchNum += 1;
			//Mix_PlayChannel(-1, bouncing, 0);
		}

        if (object1.IsColliding(walking1) || object1.IsColliding(walking2) ||object1.IsColliding(walking2) || object1.IsColliding(walking2) )
		{
			dx = (dx*-1) ;
            //SCREEN_WIDTH = SCREEN_WIDTH*-1;
            cout << SCREEN_WIDTH << endl;
            //dy = (dy* -1);
			// dx = dx + acceeX;
			//touchNum += 1;
			//Mix_PlayChannel(-1, sound, 0);

		}

        if (object1.IsColliding(reflected1) || object1.IsColliding(reflected2) ||object1.IsColliding(reflected3) || object1.IsColliding(reflected4) )
		{
			dx = (dx*-1) ;
              //dy = (dy* -1);
			// dx = dx + acceeX;
			//touchNum += 1;
			//Mix_PlayChannel(-1, sound, 0);

		}
            
           
    
    //object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}