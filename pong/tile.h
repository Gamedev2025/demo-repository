#ifndef TILE_H
#define TILE_H

#include<bits/stdc++.h>
using namespace std;
#include "GameEntity.h"
#include "TexturedRectangle.h"

class tile 
{
    public:
    //Initializes position and type
        tile(string filename)
        {
            m_sprite = new TexturedRectangle(m_renderer , filename.c_str());
        };

        ~tile()
        {
            m_sprite->~TexturedRectangle();
        }

        //Shows the tile
        void render( )
        {
            m_sprite -> Render(m_renderer);
        };

        //Get the tile type
        int getType();

        //Get the collision box
        SDL_Rect getBox();

    private:
    SDL_Rect m_box;
    TexturedRectangle* m_sprite;
    SDL_Renderer* m_renderer;
}

;






#endif