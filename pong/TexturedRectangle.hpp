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
        TexturedRectangle(SDL_Renderer*& renderer, string filepath);

        
        // Destructor
        ~TexturedRectangle();
        // 
        void SetPosition(int x, int y, int w, int h);
        // Copy Constructor..
        // Copy assignment operator
        //Detect collison
       // SDL_bool IsColliding(TexturedRectangle& obj);

        //for animating
        void draw(int x , int y , int w , int h)
        {
        dest.x = x;
        dest.y = y;
        dest.w = w;
        dest.h = h;

        }

       void playFrame(int x , int y , int w , int h , int frameNumer)
        {
    
        src.x = x+w*frameNumer;
        src.y= y;
        src.w = w;
        src.h = h;
        }

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