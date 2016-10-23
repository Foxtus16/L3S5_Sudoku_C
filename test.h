/******************************************************************************!
 * \file     test.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     16/10/16
 * \brief    Declaration des fonctions test pour nos fonctions
 * 
 * \details  En construction ! 
 * \todo     Créer des fonctions test pour chaque fonctionnalité importante
 * 
 ******************************************************************************/

#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include "bilan_memoire.h"
#include "macro.h"
#include <time.h>
        
/*! \todo Rajouter batterie de test pour grille.h */
#include "grille.h"
/*! \todo Rajouter batterie de test pour resolution.h*/
#include "resolution.h"
/*! \todo Rajouter batterie de test pour graphique.h*/
#include "graphique.h"

/*! */
Grille* testGrille();

void testAffichageGrille(Grille *g);

void testResolution(Grille *g);

void testResolutionGrilleVide(void);
        
void testSDL(void);
        

#endif /* TEST_H */

