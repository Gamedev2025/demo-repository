#include "GameEntity.hpp"
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
using namespace std;


  GameEntity::GameEntity(SDL_Renderer* renderer ,  string sprite)
    {
        m_renderer = renderer;
        m_sprite = new TexturedRectangle(m_renderer , sprite);
    }

   

     void GameEntity:: draw(int x , int y , int w , int h)
        {
        dest.x = x;
        dest.y = y;
        dest.w = w;
        dest.h = h;

        }

       void GameEntity:: playFrame(int x , int y , int w , int h , int frameNumer)
        {
    
        src.x = x+w*frameNumer;
        src.y= y;
        src.w = w;
        src.h = h;
        }

    void GameEntity:: Render()
    {
        if (m_sprite != nullptr)
        {
            m_sprite -> Render(m_renderer);
        }
    }