/*
Use my makefile to compile; it will do something like :
gcc neillsdl.c rl.c -o rl `sdl-config --cflags` -O4 -Wall -pedantic -std=c99  `sdl-config --libs`
*/

#include "neillsdl.h"

int main()
{

    SDL_Surface *screen;
    SDL_bool done = SDL_FALSE;
    Uint32 springgreen;
    Uint32 salmon;
  
    Neill_SDL_Init(&screen);
    
    springgreen = SDL_MapRGB(screen->format, 0, 255, 127);
    salmon = SDL_MapRGB(screen->format, 250, 128, 114);
    while(!done) 
    {
         Neill_DrawLine(screen, rand()%WIDTH, rand()%HEIGHT, rand()%WIDTH, rand()%HEIGHT, springgreen);
         Neill_DrawArc(screen, rand()%WIDTH, rand()%HEIGHT, rand()%HEIGHT, -rand()%360, rand()%360, salmon);
         Neill_SDL_Events(&done);
    }

    SDL_Quit();
  
    return 0;
}


