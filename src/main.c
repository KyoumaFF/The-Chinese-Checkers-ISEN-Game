#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "define.h"
#include "proto.h"
#include "screen.h"
#include "game.h"
#include "menu.h"
#include "menu_config.h"

// clear && gcc main.c `sdl-config --cflags --libs` -lSDL_image  && ./a.out

void main(){

SDL_Surface *screen = NULL;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

SDL_Flip(screen);
<<<<<<< HEAD
=======
char framechar="../img/Frame_6.png";
int part[6]={9,9,2,9,9,1};
int nbplayers=2;

>>>>>>> 5824458b9b172a0179c35c82fb52f7be71b5d03f
menu_main(screen);

SDL_Quit();
exit(0);
}
