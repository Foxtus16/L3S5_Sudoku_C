/******************************************************************************!
 * \file     graphique.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     23/10/16
 * \brief    Declaration des fonctions pour les rendus graphiques
 * 
 * \details  Utilisation de la bibliothèque SDL pour gérer la partie graphique
 *           du projet et surement les événements utilisateurs
 * 
 ******************************************************************************/

#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <stdio.h>
#include <stdlib.h>
#include "bilan_memoire.h"
#include "macro.h"
#include "grille.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/*! \struct Sudoku
 *  \brief Structure pour gérer l'affichage graphique du sudoku */
typedef struct sudoku {
    Boolean       enJeu; /*!< Boolean pour boucle principale du jeu*/
    SDL_Window*   fenetre; /*!< Fenetre SDL du jeu*/
    TTF_Font*     font; /*!< Police utilisé */
    SDL_Renderer* rendu; /*!< Cadre de rendu pour afficher texture*/
    
    SDL_Texture *fdMenu, *fdJeu; /*!< Texture de background */
    SDL_Texture *fdTitre; /*! Texture pour le titre */
    SDL_Rect rectGrille; /*! Rectangle déliminantant la taille */
    SDL_Rect rectTitre;
}Sudoku;

/*! \struct Menu
 *  \brief Structure contenant les textures pour les boutons d'un menu */
typedef struct menu{
    SDL_Texture *fdBouton[NB_BOUTON_MAX]; /*!< Tableau de texture bouton*/
    SDL_Texture *fdTextBouton[NB_BOUTON_MAX]; /*!< Texte sur le bouton */
    SDL_Rect rect[NB_BOUTON_MAX]; /*< Tableau de rectangle pour les placer */
    SDL_Rect rectTxt[NB_BOUTON_MAX]; /*< Taille du texte */
    int nb; /*!< nombre de bouton dans le menu */
}Menu;

/*! \enum NavigationMenu 
 *  \brief une petite enumération pour gerer la navigation entre les menus*/
typedef enum navigationMenu{
    MENUPRINCIPAL= 0, MENUDIFF=1, ENJEU=2, ECRANFIN=3
}NavigationMenu;

/*! \fn Sudoku* initSudoku()
 *  \brief Initialise un Sudoku à 0 
 *  \return Retourne un sudoku vide */
Sudoku* initSudoku();

/*! \fn Menu* initMenu()
 *  \brief Initialise un menu
 *  \return Retourne un menu vide */
Menu* initMenu();

/*! \fn int initSDL(Sudoku* sudoku)
 *  \brief Initialise les sous-programme de SDL et SDL
 *  \param sudoku: structure pour notre affichage sdl du sudoku
 *  \return Renvoit TRUE si aucun soucis sinon FALSE */
Boolean initSDL(Sudoku* sudoku);

/*! \fn SDL_Texture* chargeTexture(char* chemin, SDL_Renderer* rendu)
 *  \brief Charge une image en texture sdl
 *  \param chemin: chemin vers l'image a charger
 *  \param rendu; rendu ou l'on affiche les texture decu
 *  \return Retourne la texture chargée*/
SDL_Texture* chargeTexture(char* chemin, SDL_Renderer* rendu);

/*! \fn SDL_Texture* chargeTexte(char* texte, SDL_Color cTxt, Sudoku* sudoku,
                          SDL_Rect* rText)
 *  \brief Cree une texture d'apres la surface ou l'on a apposer le texte
 *  \param texte: texte que l'on veut afficher
 *  \param cTxt: couleur du texte qu el'on veut afficher
 *  \param sudoku: l'on va récupérer la police, rendu utilisé
 *  \param rText: récupère les dimensions du texte apposé sur la surface tmp
 *  \return Retourne la texture chargée */
SDL_Texture* chargeTexte(char* texte, SDL_Color cTxt, Sudoku* sudoku,
                          SDL_Rect* rText);

/*! \fn Boolean configureSudoku(Sudoku* sudoku)
 *  \brief Charge les parametre SDL du sudoku
 *  \details Charge surtout les images et les textes a afficher
 *  \param s: Notre Sudoku en SDL
 *  \return Retourne TRUE si tout c'est bien déroulé*/
Boolean configureSudoku(Sudoku* sudoku);

/*! \fn Boolean configMenu(Menu* menu, int nb, char** textBouton, SDL_Color cTxt,
                   Sudoku* sudoku)
 *  \brief initialise les champs de notre menu 
 *  \details pour simplifier, les boutons seront alignés au centre de la 
 *           fenetre et auront tous la meme texture a part le texte qui change
 *  \param m: menu a configurer
 *  \param nb: nombre de bouton que l'on veut
 *  \param textBouton: tableau de chaine de caractere pour les boutons
 *  \param sudoku: pour récupérer la police et le rendu
 *  \param cTxt: couleur du texte
 *  \pre nb <= NB_BOUTON_MAX 
 *  \return retourne un menu pret*/
Boolean configMenu(Menu* menu, int nb, char** textBouton, SDL_Color cTxt,
                   Sudoku* sudoku);

/*! \fn void dessinMenu(Menu* m, Sudoku* sudoku)
 *  \brief Dessine le cadre du menu et les boutons (renderCopy)
 *  \param m: textures du menu a afficher 
 *  \param sudoku: recupération du rendu ou afficher */
void dessinMenu(Menu* m, Sudoku* sudoku);

/*! \fn void dessinCadreGrille(Sudoku* sudoku)
 *  \brief Dessine le cadre de la grille de sudoku 
 *  \param sudoku: recupération du rendu ou afficher */
void dessinCadreGrille(Sudoku* sudoku);

/*! \fn void dessinGrille(Sudoku* sudoku, Grille* g)
 *  \brief Dessine la grille en cours
 *  \param sudoku: recupération du rendu ou afficher 
 *  \param g: Grille sur laquelle on joue */
void dessinGrille(Sudoku* sudoku, Grille* g);

/*! \fn Boolean recupEntree(SDL_Event *e, Position *p)
 *  \brief Recupere les entree utilisateur au clavier et souris
 *  \param e: texte que l'on veut afficher
 *  \param p: Recupere les coordonnees de la souris
 *  \return Retourne FALSE si l'on quit la fenetre SDL */
Boolean recupEntree(SDL_Event *e, Position *p);

/*! \fn Boolean estDansRect(SDL_Rect* rect, Position* p)
 *  \brief Indique si les coordonnee sont bien dans le rectangle
 *  \param rect: rectangle du test
 *  \param p: la position consideree
 *  \return si position dans le rectangle alors renvoit TRUE */
Boolean estDansRect(SDL_Rect* rect, Position* p);

/*! \fn freeMenu()
 *  \brief free toutes les texture du menu
 *  \param m: menu a free */
void freeMenu(Menu* m);

/*! \fn void quitSDL(Sudoku* sudoku)
 *  \brief Quitte la sdl et détruit la fenetre de travail
 *  \param sudoku: structure pour notre affichage sdl du sudoku */
void quitSDL(Sudoku* sudoku);

#endif /* GRAPHIQUE_H */

