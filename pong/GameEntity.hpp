#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include "math.hpp"
#include "TexturedRectangle.hpp"

class GameEntity{

    public:
    GameEntity()
    {
        m_sprite = nullptr;
    }
    GameEntity(SDL_Renderer* renderer , std:: string sprite);

    ~GameEntity()
    {

    }

    void Update()
    {

    }

    void draw(int x , int y , int w , int h);
        
    void setPosition(int x , int y);
    void playFrame(int x , int y , int w , int h , int frameNumer);
        

    void Render();
    

    TexturedRectangle& GetTexturedRectangle()
    {
        return *m_sprite;
    }
    private:
    TexturedRectangle* m_sprite;
    SDL_Renderer* m_renderer;
    SDL_Rect src;
    SDL_Rect dest;
}
;






#endif