/******************************************************************************!
 * \file     grille.c
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     09/10/16
 * \brief    Implémentation des fonctions pour la grille de sudoku
 * 
 * \details  
 *
 * 
 ******************************************************************************/

#include "grille.h"

Position* initPosition(int y, int x){
    Position *p = (Position*)malloc(sizeof(Position));
    *p = (Position){y,x};
    return p;
}

int estValidePosition(Position *p){
    if(  (p->x)>=0 && (p->x)<TAILLE 
       &&(p->y)>=0 && (p->y)<TAILLE )
        return TRUE;
    return FALSE;
}

void initCase(Case *c){
    c->valeur = c->constante = c->solution = 0;
}

Grille *initGrille(){
    Grille* g = (Grille*)malloc(sizeof(Grille));
    g->longueur = g->hauteur = TAILLE;
    g->c = (Case**)malloc(sizeof(Case*)*g->longueur);
    
    int i,j;
    for(i=0;i<(g->longueur);i++){
        g->c[i] = (Case*)malloc(sizeof(Case)*g->hauteur);
        for(j=0;j<(g->hauteur);j++){
            initCase(&g->c[i][j]);
        }
    }
    
    return g;
}

void freeGrille(Grille *g){
    int i;
    for(i=0;i<(g->longueur);i++){
        free(&g->c[i]);
    }
    free(&g->c);
    free(g);
}

void afficherGrille(Grille *g){
    int i,j,k;
    
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
            printf("%2d ",g->c[i][j].valeur);
        }
        printf("|\n");
    }
    for(k=0;k<(g->longueur)*3+4;k++){
                printf("-");
            }
            printf("\n");
}

int getCasesEnlever(Difficulte diff){
    int casesEnlever = 0;
        switch (diff){
            case FACILE:
                casesEnlever = 50;
                return casesEnlever;
            break;
            
            case MOYEN:
                casesEnlever = 40;
                return casesEnlever;
            break;
            
        case DIFFICILE:
                casesEnlever = 30;
                return casesEnlever;
            break;
    }
}

void creeGrilleJouable(Grille *g, Difficulte diff) {
    estResolue(g);
    int i,x,y;
    for (i = 0; i < (TAILLE*TAILLE)-getCasesEnlever(diff); i++) {
        do {
            x = rand()%TAILLE;
            y = rand()%TAILLE;
        } while(!g->c[x][y].valeur);
        
        g->c[x][y].valeur = 0;
    }
    for (x = 0; x < TAILLE; x++) {
        for (y = 0; y < TAILLE; y++) {
            if (g->c[x][y].valeur){
                g->c[x][y].constante = TRUE;
            }
        }
    }
}
