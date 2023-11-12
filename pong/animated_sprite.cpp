#include "animated_sprite.h"

void animatedSprite::animated(SDL_Renderer* renderer , string filename)
{
    SDL_Surface* image = IMG_Load(filename.c_str());
    texture = SDL_CreateTextureFromSurface(renderer , image);
}

animatedSprite::~animatedSprite()
{
    
    SDL_DestroyTexture(texture);
}

void animatedSprite::draw(int x , int y , int w , int h)
{
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;

}

void animatedSprite::playFrame(int x , int y , int w , int h , int frameNumer)
{
    
    src.x = x+w*frameNumer;
    src.y= y;
    src.w = w;
    src.h = h;
}

void animatedSprite::updateAnimation(SDL_Renderer* renderer)

{
    SDL_RenderCopy(renderer , texture , &src , &dest);

}