#pragma once

#ifndef BASE_OBJECT_HPP_
#define BASE_OBJECT_HPP_

#include<DataBase.hpp>

class Base_Object{
    protected:
        SDL_Surface *p_base_surface;
        SDL_Rect base_rect;
    public:
        Base_Object();
        void Set_Surface(SDL_Surface *p_surface);
        void Set_Rect(SDL_Rect rect);
        void Move(int i);
        SDL_Surface *Get_Surface();
        SDL_Rect Get_Rect();
        void Set_Color_Key(int ColorKeyR, int ColorKeyG, int ColorKeyB);
        bool Load_Image(SDL_Rect dst_rect);
        ~Base_Object();
};


#endif // BASE_OBJECT_HPP_
