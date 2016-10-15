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
    int grille[9][9] =

    {

        {9,0,0,1,0,0,0,0,5},

        {0,0,5,0,9,0,2,0,1},

        {8,0,0,0,4,0,0,0,0},

        {0,0,0,0,8,0,0,0,0},

        {0,0,0,7,0,0,0,0,0},

        {0,0,0,0,2,6,0,0,9},

        {2,0,0,3,0,0,0,0,6},

        {0,0,0,2,0,0,9,0,0},

        {0,0,1,9,0,4,5,7,0}

    };
    
    int i,j;
    
    for(i=0;i<g->longueur;i++){
        for(j=0;j<g->hauteur;j++){
            if(grille[i][j])
                g->c[i][j].valeur = grille[i][j], g->c[i][j].constante = 1;
        }
    }
    
    afficherGrille(g);
    
    freeGrille(g);
    return (EXIT_SUCCESS);
}

