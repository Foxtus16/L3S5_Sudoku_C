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

Checkpoint* initCheckpoint(Position *p, int nbSol){
    Checkpoint *chk = (Checkpoint*)malloc(sizeof(Checkpoint));
    
    chk->nbSol_ = nbSol;
    chk->p_ = p;
    chk->next_ = NULL;
    return chk;
}

Checkpoint* insertCheckpointTrie(Checkpoint* chemin, Checkpoint* chk){
    // Ajouter en tête si chemin vide ou checkpoint a moins de solution que tête
    if (!chemin || chemin->nbSol_ >= chk->nbSol_){ 
        chk->next_ = chemin;
        return chk;
    }
    
    Checkpoint *tmp = chemin;
    // Tant que le prochain element non null 
    // et que sa valeur est inferieure a celle du maillon
    while(chemin->next_ && chemin->next_->nbSol_ < chk->nbSol_)
        chemin=chemin->next_; // on passe au suivant meme test

    // On court-circuite en donnant au suivant de notre checkpoint 
    // le checkpoint suivant ou l'on s'est arrêté, celui si devenant
    // notre checkpoint donc la liste se continue sans encombre
    chk->next_ = chemin->next_;
    chemin->next_ = chk; // et le suivant de la liste on le met a maillon

    return tmp;
}

Checkpoint* cheminBacktracking(Grille* g){
    Checkpoint *chemin = NULL;
    Position *p = initPosition(0,0);
    int cpt,k;
    //On va commencer a créer notre chemin
    for(p->y=0 ;p->y<(g->longueur); p->y++){
        for(p->x=0; p->x<(g->hauteur); p->x++){
            for(k=1,cpt=0; k<=TAILLE; k++){
                if(estPossible(k,g,p)){
                    cpt++;
                }
            }
            if(cpt!=0){
                chemin = insertCheckpointTrie(chemin,
                                 initCheckpoint(initPosition(p->y,p->x),cpt) );
            }
        }
    }
    free(p);
    return chemin;
}

void afficherChemin(Checkpoint* chemin){
    if(!chemin) return;
    while(chemin){
        printf("[%d][%d]=",chemin->p_->y,chemin->p_->x);
        printf("%d->",chemin->nbSol_);
        chemin = chemin->next_;
    }
    printf("NULL\n");
}

void freeChemin(Checkpoint* chemin){
    Checkpoint *tmp;
    // Récupère la tête dans un tmp, avance dans la liste 
    // libere la tête et sa position
    while(chemin){
        tmp = chemin;
        free(tmp->p_);
        free(tmp);
        chemin = chemin->next_;
    }
}

Arbre* initArbre(Grille *g){
    Arbre *arb = (Arbre*)malloc(sizeof(Arbre));
    int i;
    for(i=0;i<TAILLE;i++){
        arb->c[i] = NULL;
    }
    arb->g = g;
    return arb;
}

int estDansLigne(int val, Grille *g, Position *p){
    int j;
    //g->c[ligne][colonne], l'on fait donc varier la colonne 
    for(j=0;j<TAILLE;j++){
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
        for(j=o.x; j<(o.x+3); j++){
            if(g->c[i][j].valeur==val)
                return TRUE;
        }
    }
    return FALSE; 
}

int estPossible(int val, Grille *g, Position *p){
   // Vérifie que la position est correcte
    if(estValidePosition(p)){
         // Vérifie que la case est vide et non constante
        if(g->c[p->y][p->x].valeur==0 && g->c[p->y][p->x].constante==FALSE){
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

int grilleComplete(Grille *g){
    Position *p = initPosition(0,0);
    for(p->y=0;p->y<(g->longueur);p->y++){
        for(p->x=0;p->x<(g->hauteur);p->x++){
            if(g->c[p->y][p->x].valeur == 0){
                free(p);
                return FALSE;
            }
        }
    }
    free(p);
    return TRUE;
}

int estResolue(Grille *g, Checkpoint* chemin){
    // Des qu'on arrive à la fin du chemin
    if(!chemin){
        // Si la grille a été complété alors on a finit de resoudre
        if(grilleComplete(g))return  TRUE;
        else                 return  FALSE;
    }
    Checkpoint* raccourci = NULL;
    int k;
    // Chaque grille de sudoku a obligatoirement une solution 
    for(k=1;k<=TAILLE;k++){
        //On vérifie déjà si la valeur est placable sinon on passe à la suivant
        if(estPossible(k,g,chemin->p_)){
            //On place la valeur dans la case et l'on teste la case suivante
            g->c[chemin->p_->y][chemin->p_->x].valeur = k;
            //On recrée un nouveau chemin avec ce choix
            raccourci= cheminBacktracking(g);
            // si l'on atteind la fin alors on place les solutions et fin
            if(estResolue(g,raccourci)){
                g->c[chemin->p_->y][chemin->p_->x].valeur   = k;
                g->c[chemin->p_->y][chemin->p_->x].solution = k;
                freeChemin(raccourci);
                return TRUE;
            }
            // sinon on remet cette case à 0
            g->c[chemin->p_->y][chemin->p_->x].valeur   = 0;
            // et on libere ce chemin 
            freeChemin(raccourci);
        }
    }
    //Lorsque que l'on a exploré toute les possibilités de placement
    // l'on va reprendre dans le for du noeud précédent 
    return FALSE;
}

int grilleResolue(Grille *g){
    Position *p = initPosition(0,0);
    int val=0,sol=0;
    for(p->y=0;p->y<(g->longueur);p->y++){
        for(p->x=0;p->x<(g->hauteur);p->x++){
            val=g->c[p->y][p->x].valeur;
            sol=g->c[p->y][p->x].solution;
            // Si une case vide || deja dans ligne/col/ssReg 
            if( val!= sol || val==0){
                free(p);
                return FALSE;
            }
        }
    }
    free(p);
    return TRUE;
}