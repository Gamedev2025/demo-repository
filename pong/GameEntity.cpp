#include "GameEntity.hpp"
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
using namespace std;


GameEntity::GameEntity()
    {
        m_sprite = nullptr;
    }
    GameEntity(SDL_Renderer* renderer ,  string sprite)
    {
        m_renderer = renderer;
        m_sprite = new TexturedRectangle(m_renderer , sprite);
    }

    GameEntity::~GameEntity()
    {

    }

     GameEntity::void Update()
    {

    }

     GameEntity::void draw(int x , int y , int w , int h)
        {
        dest.x = x;
        dest.y = y;
        dest.w = w;
        dest.h = h;

        }

        GameEntity::void playFrame(int x , int y , int w , int h , int frameNumer)
        {
    
        src.x = x+w*frameNumer;
        src.y= y;
        src.w = w;
        src.h = h;
        }

     GameEntity::void Render()
    {
        if (m_sprite != nullptr)
        {
            m_sprite -> Render(m_renderer);
        }
    }