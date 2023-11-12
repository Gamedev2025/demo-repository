#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

#include<bits/stdc++.h>
#include<SDL2/SDL.h>

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

    void Render()
    {
        if (m_sprite != nullptr)
        {
            m_sprite -> Render(m_renderer);
        }
    }

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