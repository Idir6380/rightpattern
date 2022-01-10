#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include "ttffonc.h"
#include "verifie.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include "ttffonc.h"
#include "verifie.h"
#include "affichage.h"
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
void SDL_ExitWithError(const char *message);
int cpu(int argc, char *argv[])
{
    int p=0;
    size_t x1,y1;
    int score=1000;
    int k[36]; //tableau de compteur
    srand(time(NULL));
    int num[7][7];
    //
    //boutton
 int km[36];
 //les numeros
 int v[49];
for (int i=0; i<49; i++){
       v[i]=0;
    }
 int c;
 for (int i=0;i<36;i++){
    km[i]=(rand()%2)+1;
    int j=i/6;
    if (km[i]==1){
       //represente les lignes
       c=j+i;
       v[c]++;
       c=i+j+8;
       v[c]++;
    }
    if(km[i]==2){
       //represente les lignes
       c=j+i+1;
       v[c]++;
       c=i+j+7;
       v[c]++;
    }
 }

int i=0;
    for (int m=0; m<7; m++){
        for(int l=0; l<7; l++){
            num[m][l]=v[i];
            i++;
        }
    }
affichmat(num);
    //
   unsigned int lastTime = 0, currentTime;
   SDL_Rect rectangle2[6][6];
   SDL_Texture* wintxt=NULL;
   SDL_Rect winrect={580,580,500,500};
    TTF_Init();
    //creer un rectangle pour GO
    SDL_Rect gorect={580,0,100,100};
    //rectangle pour le timer
    SDL_Rect timerrect={450,0,300,120};
    //
    SDL_Window *window = NULL;
    SDL_Renderer *pRenderer = NULL;
    SDL_Texture* txt = NULL;//texture
    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
printf("\n");
    affichevecteur(k);
    affichmat(num);
    //Création fenêtre
    window = SDL_CreateWindow("Première fenêtre SDL 2",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1000, 0 );
    if(window == NULL)
        SDL_ExitWithError("Creation fenetre echouee");
    /*------------------------------------------------------------*/
   pRenderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
    if(pRenderer==NULL)
    {
        SDL_ExitWithError("creation echouee");
    }
    //afficher rendu----------------------------------------------
    SDL_SetRenderDrawColor(pRenderer, 40, 100, 204, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
    //init sdl_ttf
    if(TTF_Init()==-1)
{
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
}
     txt=loadttf("GO!!",pRenderer,40,251, 255, 226);
      SDL_RenderCopy(pRenderer,txt,NULL,&gorect);
      SDL_RenderPresent(pRenderer);
    //dessinner la matrice pleine
    for(int x=0;x<6;x++){
        for(int y=0;y<6;y++){
                for(int i=290;i<891;i=i+103){
                    for(int j=250;j<851;j=j+103){
    //coordonees
    rectangle2[x][y].x = i;
    rectangle2[x][y].y = j;
    //largeur
    rectangle2[x][y].w=100;
    //hauteur
    rectangle2[x][y].h=100;

    if(SDL_SetRenderDrawColor(pRenderer,251, 255, 226,SDL_ALPHA_OPAQUE)!=0){
         SDL_ExitWithError("impossible de de changer la couleur du rendu");
    }
    if(SDL_RenderFillRect(pRenderer,&rectangle2)!=0){
        SDL_ExitWithError("impossible de dessiner un rectangle");
    }
    SDL_RenderPresent(pRenderer);
    }
    }
    }
    }
    /*------------------------------------------------------------*/
    int j=0;
      for (int n=240;n<941;n=n+103)
        {
         int i=0;
        for (int c=200;c<901;c=c+103)
        {
         int cx=n+37;
         int cy=c+37;
          SDL_SetRenderDrawColor(pRenderer,0,0,0,99);
          nbr(pRenderer,cx,cy,num[i][j]);
         i++;
        }
         j++;
        }
        //---------afficher les ligne
    //
    SDL_Event event;
    bool quit = false;
    char result[50];
    SDL_Texture *tme;
    int q=0,s;
    int tab[36];
    int count=0;
    for(int j=0;j<36;j++){
        tab[j]=1;
    }
     while(quit==false &&p  == 0 ){

           currentTime = SDL_GetTicks();
      if ((currentTime > lastTime + 1000 && 120-(currentTime/1000)>0) && count!=36 ) {
         sprintf(result,"score:%d♠time:%03d",score,120-(currentTime/1000));
         SDL_SetRenderDrawColor(pRenderer,40, 100, 204, 255);
         SDL_RenderFillRect(pRenderer,&timerrect);
         tme=loadttf(result,pRenderer,40,251, 255, 226);
         SDL_RenderCopy(pRenderer,tme,NULL,&timerrect);
         SDL_RenderPresent(pRenderer);
         tme=NULL;
         score=score-3;
         lastTime = currentTime;


                    if((currentTime/1000)%1==0){
                         q=(rand()%36);
                         s=q/6;

                if (km[q] == 1 && tab[q] == 1){
                    tab[q]--;
                    count++;
                    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
                    SDL_RenderDrawLine(pRenderer,((q%6)*103)+290,(s*103)+250,((q%6)*103)+393,(s*103)+353);

                }
                if (km[q]==2 && tab[q]==1){
                    tab[q]--;
                    count++;
                    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
                    SDL_RenderDrawLine(pRenderer,((q%6)*103)+290,(s*103)+353,((q%6)*103)+393,(s*103)+250);
                }

         }

      }

             while(SDL_PollEvent(&event))
        {

            switch(event.type){
              case SDL_QUIT:
                  SDL_DestroyWindow(window);
                  partie();
                quit = true;
                break;

            }
        }
        if(count>=36){
          wintxt=loadttf("GG!",pRenderer,200,0,0,0);
          SDL_RenderCopy(pRenderer,wintxt,NULL,&winrect);
          SDL_RenderPresent(pRenderer);
       }
       if(120-(currentTime/1000) == 0 && count!=36){
          wintxt=loadttf("U lose :'(",pRenderer,200,0,0,0);
          SDL_RenderCopy(pRenderer,wintxt,NULL,&winrect);
          SDL_RenderPresent(pRenderer);
          p=1;
       }
    }
     //-----------
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return p;
}



