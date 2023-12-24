#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char* argv[]){

    // Create the window
    SDL_Window* window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN);
    if ( window == nullptr )
        std::cout << "Error Creating Window: " << SDL_GetError() << std::endl;

    // Create the renderer onto the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if ( renderer == nullptr )
        std::cout << "Error Creating Renderer: " << SDL_GetError() << std::endl; 

    // Basic gameloop
    while ( true ){
        SDL_Event event;
        SDL_PollEvent(&event);
        if ( event.type == SDL_QUIT )
            break;
        
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_Delay(5);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}