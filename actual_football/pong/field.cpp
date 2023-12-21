#include "field.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"
#include "player1.hpp"
#include "player2.hpp"
#include "math.hpp"

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


extern Gamestate currState;
extern SDL_Renderer* renderer;

extern bool isGameRunning ;
extern int width ;
 extern int height;
 
  
  int positionx = 502;
  int positiony = 217;
//DynamicText* object;
 field::~field()
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

             if (e.key.keysym.sym == SDLK_w)
             {
                cout << "w" << endl;
                positiony -= 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_s)
             {
                cout << "y" << endl;
                positiony += 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_a)
             {
                cout << "a" << endl;
                positionx -= 6;
                cout << x << endl;

             }
             if (e.key.keysym.sym == SDLK_d)
             {
                cout << "d" << endl;
                positionx += 6;
                cout << x << endl;

             }

		{
			
			
				
			
				
		}
	 	if (state[SDL_SCANCODE_RIGHT])
		{
			
			
				
			
		}
	 	if (state[SDL_SCANCODE_UP]
		){
			
			
				y -= 6;
			
		}
	 	if (state[SDL_SCANCODE_DOWN])
		{
		
			
				y += 6;
			
		}

             
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
             object1.SetPosition(positionx , positiony , 30 , 30);
             //object1.draw(x , y , 200 ,200);
   // object1.playFrame(x , y, 200 , 200 , 0);
    //object1.Render(renderer);
    //object1->GetTexturedRectangle().draw()
    object1.Render(renderer);
    
    //object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}