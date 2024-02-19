#include<BaseObject.hpp>

Base_Object::Base_Object(){
    p_base_surface = NULL;
    base_rect.h = 0;
    base_rect.w = 0;
    base_rect.x = 0;
    base_rect.y = 0;
}

void Base_Object::Set_Surface(SDL_Surface *p_surface){
    this->p_base_surface = p_surface;
}

void Base_Object::Set_Rect(SDL_Rect rect){
    this->base_rect = rect;
}

SDL_Surface *Base_Object::Get_Surface(){
    return p_base_surface;
}

SDL_Rect Base_Object::Get_Rect(){
    return base_rect;
}

void Base_Object::Move(int i){
    if(i == 0)
        base_rect.x -= 7;
    if(i == 1)
        base_rect.x += 7;
    if(i == 2)
        base_rect.y += 7;
    if(i == 3)
        base_rect.y -= 7;
}

void Base_Object::Set_Color_Key(int ColorKeyR, int ColorKeyG, int ColorKeyB){
    SDL_SetColorKey(p_base_surface, SDL_TRUE, SDL_MapRGB(p_base_surface->format, ColorKeyR, ColorKeyG, ColorKeyB));
}

bool Base_Object::Load_Image(SDL_Rect dst_rect){
    SDL_Texture *texture = SDL_CreateTextureFromSurface(g_prenderer, p_base_surface);
    if(texture == nullptr)
        return false;
    SDL_RenderCopy(g_prenderer, texture, &base_rect, &dst_rect);
    if(g_prenderer == nullptr)
        return false;

    SDL_DestroyTexture(texture);
    return true;
}

Base_Object::~Base_Object(){
    SDL_FreeSurface(p_base_surface);
    p_base_surface = NULL;
    base_rect.w = 0;
    base_rect.h = 0;
    base_rect.x = 0;
    base_rect.y = 0;
}