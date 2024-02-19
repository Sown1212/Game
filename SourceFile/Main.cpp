//Makefile : make build
//Commandline : g++ Main.cpp -o Main.exe -IE:/Dev_Game/Game/HeaderFile -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <DataBase.hpp>
#include "Setup.cpp"
#include "BaseObject.cpp"

void Input(){
    while( SDL_PollEvent( &event ) != 0 ){
            if(event.type == SDL_QUIT)
                run = false;
            switch (event.key.keysym.sym){
                case SDLK_d:{
                    player.Move(0);
                    break;
                }
                case SDLK_a:{
                    player.Move(1);
                    break;
                }
                case SDLK_w:{
                    player.Move(2);
                    break;
                }
                case SDLK_s:{
                    player.Move(3);
                    break;
                }
            default:
                break;
            }
    }
}

int main(int argc, char *argv[]){
    Open();

    if(Create_Window() && Create_Renderer())
        std::cout << "Game ready" << std::endl;
    else 
        return -1;

    SDL_Rect rectb;
    rectb.h = g_Window_Height;
    rectb.w = g_Window_Width;
    rectb.x = 0;
    rectb.y = 0;

    backgroud.Set_Surface(IMG_Load("E:/Dev_Game/Game/Map/Map1/backgroud.jpg"));
    backgroud.Set_Rect(rectb);

    SDL_Rect rectp;
    rectp.h = g_Window_Height;
    rectp.w = g_Window_Width;
    rectp.x = 0;
    rectp.y = 0;
    
    player.Set_Surface(IMG_Load("E:/Dev_Game/Game/Player/Player.png"));
    player.Set_Rect(rectp);
    player.Set_Color_Key(g_ColorKeyR, g_ColorKeyG, g_ColorKeyB);

    while( run ){

        firt_time = SDL_GetTicks();
        
        backgroud.Load_Image(backgroud.Get_Rect());
        player.Load_Image(rectp);
        SDL_RenderPresent(g_prenderer);
        SDL_RenderClear(g_prenderer);

        Input();
        
        last_time = SDL_GetTicks();
        if((last_time - firt_time) < 1000/FPS)
            SDL_Delay((1000/FPS) - (last_time - firt_time));
        std::cout << "FPS = " << 1000/(SDL_GetTicks() - firt_time) << std::endl;

    }
    Close();
    return 0;
}