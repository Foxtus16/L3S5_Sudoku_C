/******************************************************************************!
 * \file     resolution.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     15/10/16
 * \brief    Implémentation des fonctions résolutions d'une grille de sudoku
 * 
 * \details  
 * 
 * 
 ******************************************************************************/

#include "resolution.h"

int estDansLigne(int val, Grille *g, Position *p){
    int j;
    //g->c[ligne][colonne], l'on fait donc varier la colonne 
    for(j=0;i<TAILLE;j++){
        if(g->c[p->y][j].valeur == val)
            return TRUE;
    }
    return FALSE;
}

int estDansCol(int val, Grille *g, Position *p){
    int i;
    // on fait varier la ligne
    for(i=0;i<TAILLE;i++){
        if(g->c[i][p->x].valeur == val)
            return TRUE;
    }
    return FALSE;  
}

int estDansSsReg(int val, Grille *g, Position *p){
    // on récupère la ligne, colonne  on lui enleve son modulo par 3 pour 
    // avoir l'origine de la sous-région où l'on est
    Position o;
    o.y = p->y - (p->y%REG); //ligne
    o.x = p->x - (p->x%REG); //colonne
    
    int i,j;
    for(i=o.y; i<(o.y+3); i++){
        for(j=o.x; j<(o.y+3); j++){
            if(g->c[i][j]==val)
                return TRUE;
        }
    }
    return FALSE; 
}

int estPossible(int val, Grille *g, Position *p){
   // Vérifie que la position est correcte
    if(estValidePosition(p)){
         // Vérifie s'il ne s'agit pas d'une constante
        if(!g->c[p->y][p->x].constante){
            // on vérifie les 3 conditions 
            if(    !estDansLigne(val,g,p)
                && !estDansCol  (val,g,p)
                && !estDansSsReg(val,g,p) ){
                return TRUE;
            } 
        }
    }
    return FALSE;
}