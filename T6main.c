#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "T6define.h"
#include "T6proto.h"
#include "T6screen.h"
#include "T6game.h"
#include "menu.h"
#include "menu_config.h"

// clear && gcc main.c `sdl-config --cflags --libs` -lSDL_image  && ./a.out

void main(){

SDL_Surface *screen = NULL;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

SDL_Flip(screen);

menu_main(screen);

SDL_Quit();
exit(0);
}
