#include <SDL.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define DEPTH 32

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

void Neill_DrawPixel(SDL_Surface *screen, Uint16 x, Uint16 y, Uint32 colour);
void Neill_DrawLine(SDL_Surface *screen, Uint16 x0, Uint16 y0, Uint16 x1, Uint16 y1, Uint32 colour);
void Neill_DrawArc(SDL_Surface *screen, Uint16 x, Uint16 y, Uint16 r, double a1, double a2, Uint32 colour);
void Neill_SDL_Init(SDL_Surface **screen);
void Neill_SDL_Events(SDL_bool *done);

