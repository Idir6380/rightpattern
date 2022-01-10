#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "menu.h"
#include "game.h"
#include "cpu.h"
void partie(){
  switch (menu()){
  case 1 : game();
  break;
  case 2:cpu();
  break;
  }
}
int main(int argc, char *argv[]){

    partie();

return 0;
}
