/******************************************************************************!
 * \file     main.c
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     09/10/16
 * \brief    Fichier main du sudoku
 * 
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Grille *g = initGrille();
    
    afficherGrille(g);
    
    freeGrille(g);
    return (EXIT_SUCCESS);
}

