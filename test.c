/******************************************************************************!
 * \file     test.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     16/10/16
 * \brief    Implémentation des fonctions test pour nos fonctions
 * 
 * \details  En construction ! 
 * \todo     Créer des fonctions test pour chaque fonctionnalité importante
 * 
 ******************************************************************************/
        
#include "test.h"
        
void testGrille(){
    Grille *g = initGrille();
    int i,j,k;
    // Grille de test
    int grille[9][9] = {
        {9, 0, 0, 1, 0, 0, 0, 0, 5},
        {0, 0, 5, 0, 9, 0, 2, 0, 1},
        {8, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 6, 0, 0, 9},
        {2, 0, 0, 3, 0, 0, 0, 0, 6},
        {0, 0, 0, 2, 0, 0, 9, 0, 0},
        {0, 0, 1, 9, 0, 4, 5, 7, 0}
    };

    // Affiche les coordonnée de chaque case
    for(i=0;i<(g->longueur);i++){
        if(i%3==0){
            for(k=0;k<(g->longueur*3)+4;k++){
                printf("-");
            }
            printf("\n");
        }
        for(j=0;j<(g->hauteur);j++){
            if(j%3==0) 
                printf("|");
            printf("(%d,%d)",i,j);
        }
        printf("|\n");
    }
    for(k=0;k<(g->longueur)*3+4;k++){
        printf("-");
    }
    printf("\n");
    
    // Remplit notre grille avec la grille test, et met constante à TRUE
    for (i = 0; i < g->longueur; i++) {
        for (j = 0; j < g->hauteur; j++) {
            if (grille[i][j]){
                g->c[i][j].valeur = grille[i][j];
                g->c[i][j].constante = TRUE;
            }
        }
    }

    afficherGrille(g);

    freeGrille(g);
}