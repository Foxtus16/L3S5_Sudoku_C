/******************************************************************************!
 * \file     graphique.c
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     23/10/16
 * \brief    Implémentation des fonctions pour les rendus graphiques
 * 
 * \details  Utilisation de la bibliothèque SDL pour gérer la partie graphique
 *           du projet et surement les événements utilisateurs
 * 
 ******************************************************************************/

#include "graphique.h"

int initSDL(SDL_Window* w, SDL_Surface* screen){
    //Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("Pb d'initialisaiton! SDL_Error: %s\n", SDL_GetError());
        return FALSE;
    }
    //Création de la fenetre
    w = SDL_CreateWindow("L3S5 Sudoku C", SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if(!w){
        printf("Pb de création de fenêtre! SDL_Error: %s\n", SDL_GetError());
        return FALSE;
    }
    //Création de la surface écran
    screen = SDL_GetWindowSurface(w);

    return TRUE;
}




void quitSDL(SDL_Window* w, SDL_Surface* screen){
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(w);
    SDL_Quit();
}