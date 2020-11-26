#include "neillsdl.h"

/* Horrible assumptions here about 32 bit displays etc.*/
void Neill_DrawPixel(SDL_Surface *screen, Uint16 x, Uint16 y, Uint32 colour)
{
   Uint32 *bufp;
   bufp = (Uint32 *)screen->pixels + y*WIDTH + x;
   *bufp = colour;
}

/* Oooh, this is really nasty. Aliasing would be nice too.*/
void Neill_DrawArc(SDL_Surface *screen, Uint16 x, Uint16 y, Uint16 r, double a1, double a2, Uint32 colour)
{

   double xp, yp;
   double ang, angstep;
   
   if(SDL_MUSTLOCK(screen)){
        if(SDL_LockSurface(screen) < 0) return;
   }
   
   if(a1 > a2){ /* User got them the wrong way around ?*/
       xp = a1; a1=a2;a2=xp;
   }
   
   a1 = a1*M_PI/180.0; /* Convert degress to radians*/
   a2 = a2*M_PI/180.0;
   angstep = asin(0.5/(double)r); /* How far to move each plot*/
   
   for(ang=a1; ang<=a2; ang=ang+angstep){
      xp = (double)x + cos(ang)*(double)r;
      yp = (double)y - sin(ang)*(double)r;
      if(xp >= 0 && xp < WIDTH && yp >= 0 && yp < HEIGHT){
         Neill_DrawPixel(screen, xp, yp, colour);
      }
   }
   
   if(SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
   SDL_Flip(screen); 
      
}


/* Adapted from http://en.wikipedia.org/wiki/Bresenham's_line_algorithm*/
void Neill_DrawLine(SDL_Surface *screen, Uint16 x0, Uint16 y0, Uint16 x1, Uint16 y1, Uint32 colour)
{

   Sint16 dx, dy, err, e2, sx, sy;


   dx = abs(x1-x0);
   dy = abs(y1-y0); 

   if(x0 < x1) sx = 1;
   else sx = -1;
   if(y0 < y1) sy = 1;
   else sy = -1;

   err = dx-dy;
 
   while((x0 != x1) && (y0 != y1)){
     Neill_DrawPixel(screen, x0, y0, colour);
     e2 = 2*err;
     if(e2 > -dy){ 
       err = err - dy;
       x0 = x0 + sx;
     }
     if(e2 <  dx){ 
       err = err + dx;
       y0 = y0 + sy;
     }
   }

   if(SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
   SDL_Flip(screen); 

}

/* Probably more readable if this were to return a SDL_SURFACE * ? */
void Neill_SDL_Init(SDL_Surface **screen)
{

   if((SDL_Init(SDL_INIT_VIDEO) < 0 ) || (!(*screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_FULLSCREEN|SDL_HWSURFACE)))){
      fprintf(stderr, "SDL Initialisation Failed in %s\n", __FILE__);
      SDL_Quit();
      exit(1);
   }
  
}

/* Gobble all events & ignore most*/
void Neill_SDL_Events(SDL_bool *done)
{
      SDL_Event event;
      while(SDL_PollEvent(&event)) 
      {      
          switch (event.type){
             case SDL_QUIT:
             case SDL_MOUSEBUTTONDOWN:
	         case SDL_KEYDOWN:
	           *done = 1;
          }
       }
}
