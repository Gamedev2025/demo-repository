#ifndef TEXTUREDRECTANGLE_HPP
#define TEXTUREDRECTANGLE_HPP

#include <string>
// Third Party
#include <SDL2/SDL.h> // For Mac, use <SDL.h>
#include <bits/stdc++.h>
using namespace std;
class TexturedRectangle{
    public:
        // Constructor
        TexturedRectangle();

        //TexturedRectangle(SDL_Renderer*& renderer, string filepath);

        
        // Destructor
        ~TexturedRectangle();
        // 

        bool textureMedia(SDL_Renderer*& renderer, string filepath);
        void SetPosition(int x, int y, int w, int h);
        // Copy Constructor..
        // Copy assignment operator
        //Detect collison
       // SDL_bool IsColliding(TexturedRectangle& obj);

        //for animating
        void draw(int x , int y , int w , int h)
        {
        m_rectangle.x = x;
        m_rectangle.y = y;
        m_rectangle.w = w;
        m_rectangle.h = h;

        }

       void playFrame(int x , int y , int w , int h , int frameNumer)
        {
    
        m_rectangle.x = x+w*frameNumer;
        m_rectangle.y= y;
        m_rectangle.w = w;
        m_rectangle.h = h;
        }
    SDL_Rect& GetSDLRect();
        

        // Update every frame
        void Update();

        //determining collision
        SDL_bool IsColliding(TexturedRectangle& obj);
        //updating animation
       void updateAnimation(SDL_Renderer* renderer)

{
    SDL_RenderCopy(renderer , m_texture , &src , &dest);

}
        // Render
        void Render(SDL_Renderer*& renderer);

    private:
        SDL_Renderer* renderer;
        inline SDL_Rect GetRectangle() const {return m_rectangle;}
        SDL_Rect m_rectangle;
        SDL_Texture* m_texture;
        SDL_Rect src;
        SDL_Rect dest;
};

#endif