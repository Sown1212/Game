#include<DataBase.hpp>

void Open(){
    SDL_Init((SDL_INIT_EVERYTHING));
    
}

bool Create_Window(){
    g_pwindow = SDL_CreateWindow("Game",
                                g_Window_PositionX,
                                g_Window_PositionY,
                                g_Window_Width,
                                g_Window_Height,
                                SDL_WINDOW_SHOWN);
    if(g_pwindow == nullptr)
        return false;
    return true;
}

bool Create_Renderer(){
    g_prenderer = SDL_CreateRenderer(g_pwindow,
                                    -1,
                                    SDL_RENDERER_ACCELERATED);
    if(g_prenderer == nullptr)
        return false;
    return true;
}

void Close(){
    if(g_prenderer == nullptr)
        SDL_DestroyRenderer(g_prenderer);
    if (g_pwindow == nullptr)
        SDL_DestroyWindow(g_pwindow);
    SDL_Quit();
}
