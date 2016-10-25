/******************************************************************************!
 * \file     main.c
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     09/10/16
 * \brief    Fichier main du sudoku
 * 
 * \details 
 *  
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bilan_memoire.h"
#include "macro.h"
#include "grille.h"
#include "resolution.h"
#include "graphique.h"
#include "test.h"


int main(int argc, char** argv) {
//    Grille *g =  testGrille();
//    testAffichageGrille(g);
//    testResolution(g);
//    freeGrille(g);
    
    // Notre sudoku en SDL
    Sudoku* sudoku = initSudoku();
    if(!initSDL(sudoku)){
        printf("Erreur lors de la creation fenetre SDL");
        return (EXIT_FAILURE);
    }
    if(!configureSudoku(sudoku)){
        printf("Erreur lors de la configuration du sudoku !\n");
        return (EXIT_FAILURE);
    }
    // Creation des menus de notre jeu 
    Menu *menuPrincipal=initMenu(), *menuDiff=initMenu();
    SDL_Color cTxt = {0,0,0}; //noir en rgb
    char *textMenuP[] = { "Jouer", "Quitter" };
    char *textMenuD[] = { "Facile","Moyen","Difficule","Quitter"};
    // Configuration des menus
    if(  !configMenu(menuPrincipal,2,textMenuP,cTxt,sudoku)
       ||!configMenu(menuDiff     ,4,textMenuD,cTxt,sudoku) ){
            printf("Erreur lors de la configuration des menu !\n");
            return FALSE;
    }
    // Gère les evenement en SDL
    SDL_Event e; 
    Position *p = initPosition(0,0);
    NavigationMenu nav = MENUPRINCIPAL;
    Difficulte diff = NEANT;
    // Boucle de jeu
    while(sudoku->enJeu){
        // Recupère les entres utilisateur
        sudoku->enJeu = recupEntree(&e,p);
        //Nettoye l'écran
        SDL_RenderClear(sudoku->rendu);
        // Navigation entre les écran 
        switch(nav){
            case MENUPRINCIPAL:
                // Applique le fond et titre
                SDL_RenderCopy(sudoku->rendu,sudoku->fdMenu,NULL,NULL);
                SDL_RenderCopy(sudoku->rendu,sudoku->fdTitre
                               ,NULL,&sudoku->rectTitre);
                dessinMenu(menuPrincipal,sudoku);
                // Gestion des clic
                if(estDansRect(&menuPrincipal->rect[0],p)){
                    nav = MENUDIFF;
                }
                else if(estDansRect(&menuPrincipal->rect[1],p)){
                    sudoku->enJeu = FALSE;
                }
                break;
            case MENUDIFF:
                // Applique le fond et titre
                SDL_RenderCopy(sudoku->rendu,sudoku->fdMenu,NULL,NULL);
                SDL_RenderCopy(sudoku->rendu,sudoku->fdTitre
                               ,NULL,&sudoku->rectTitre);
                dessinMenu(menuDiff,sudoku);
                // Gestion des clic
                if(estDansRect(&menuPrincipal->rect[0],p)){
                    diff = FACILE;
                    nav = ENJEU;
                }
                else if(estDansRect(&menuDiff->rect[1],p)){
                    diff = MOYEN;
                    nav = ENJEU;
                }
                else if(estDansRect(&menuDiff->rect[2],p)){
                    diff = DIFFICILE;
                    nav = ENJEU;
                }
                else if(estDansRect(&menuDiff->rect[3],p)){
                    sudoku->enJeu = FALSE;
                }
                break;
            case ENJEU:
                // Applique le fond et titre
                SDL_RenderCopy(sudoku->rendu,sudoku->fdJeu,NULL,NULL);
                SDL_RenderCopy(sudoku->rendu,sudoku->fdTitre
                               ,NULL,&sudoku->rectTitre);
                /*! \todo !!! */
                break;
            case ECRANFIN:
                /*! \todo !!! */
                break;
            default:
                break;
        }
        //Reset de la position du curseur apres clic
        *p = (Position){0,0};
        // Actualise le rendu à la fenetre
        SDL_RenderPresent(sudoku->rendu);

//        SDL_RenderCopy(sudoku->rendu,test,NULL,NULL);
        // Donne une couleur au rectangle
//        SDL_SetRenderDrawColor(sudoku->rendu, 0x00, 0x00, 0x00, 0x00);
        //Trace le rendu du rectangle
//        SDL_RenderDrawRect(sudoku->rendu,&sudoku->rectMenu);
        //Trace une ligne
//        SDL_RenderDrawLine(sudoku->rendu, 0, 0, ECRAN_LARGEUR, ECRAN_HAUTEUR);
        //Actualise l'écran
    }
    
    freeMenu(menuPrincipal);
    freeMenu(menuDiff);
    free(p);
    quitSDL(sudoku);
    bilan_memoire();
    return (EXIT_SUCCESS);
}

