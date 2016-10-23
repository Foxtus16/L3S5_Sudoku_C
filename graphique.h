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
#include <SDL2/SDL.h>

/*! \fn void initSDL(SDL_Window* w, SDL_Surface* sreen)
 *  \brief Initialise les fenêtres SDL
 *  \param w: La fenêtre sdl où l'on travail
 *  \param sreen:   L'écran où l'on 'dessine' notre rendu
 *  \return Renvoit TRUE si aucun soucis sinon FALSE */
int initSDL(SDL_Window* w, SDL_Surface* screen);



/*! \fn void quitSDL(SDL_Window* w, SDL_Surface* screen)
 *  \brief Quitte la sdl et détruit la fenetre de travail
 *  \param w: La fenêtre sdl à détruire
 *  \param sreen:   L'écran où l'on 'dessine' notre rendu */
void quitSDL(SDL_Window* w, SDL_Surface* screen);

#endif /* GRAPHIQUE_H */

