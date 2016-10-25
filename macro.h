/******************************************************************************!
 * \file     macro.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     15/10/16
 * \brief    Contient les defines et macro du programme 
 * 
 * \details  Regroupe les define utilisé dans le programme en plus des macros 
 *           car l'on ne sait jamais dans quel ordre le compilateur va opérer
 *           donc au moins l'on incluera cette bibliothèque après redéfinition 
 *           des fonctions pour éviter la récursivité infinie
 * 
 * 
 ******************************************************************************/

#ifndef MACRO_H
#define MACRO_H

    /*! Maccro de bilan_memoire */
    #define malloc(X) mon_malloc(X) 
    #define free(X) mon_free(X)
    #define calloc(Y,X) mon_calloc(Y,X)
    #define fopen(X,Y) mon_fopen(X,Y)
    #define fclose(X) mon_fclose(X)
    #define IMG_Load(X) mon_IMG_Load(X)
    #define SDL_FreeSurface(X) mon_SDL_free(X)
    #define TTF_RenderText_Solid(X,Y,Z) monRenderTextSolid(X,Y,Z) 
    #define SDL_CreateTextureFromSurface(X,Y) monCreatTexture(X,Y)
    #define SDL_DestroyTexture(X) monDestroyTexture(X)

    /*! Constantes de sudoku */
    #define REG    3
    #define TAILLE 9
    #define ECRAN_LARGEUR  880
    #define ECRAN_HAUTEUR  620
    #define HAUTEUR_TITRE  50
    #define NB_BOUTON_MAX  4
    #define BOUTON_LARGEUR 200
    #define BOUTON_HAUTEUR 50

    /*  \enum Boolean
        \brief Enumération pour gerer les booleans plus intuitivement */
    typedef enum boolean{
        TRUE  = 1, 
        FALSE = 0
    }Boolean;
    
    /*  \enum Difficulte
        \brief Enumération pour gerer la diffulte choisie par l'utilisateur */
    typedef enum difficulte{
        NEANT     = 0,
        FACILE    = 1, 
        MOYEN     = 2,
        DIFFICILE = 3
    }Difficulte;

#endif /* MACRO_H */

