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
        
Grille* testGrille(){
    Grille *g = initGrille();
    int i,j;
// Grille de test
//        {9, 0, 0, 1, 0, 0, 0, 0, 5},
//        {0, 0, 5, 0, 9, 0, 2, 0, 1},
//        {8, 0, 0, 0, 4, 0, 0, 0, 0},
//        {0, 0, 0, 0, 8, 0, 0, 0, 0},
//        {0, 0, 0, 7, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 2, 6, 0, 0, 9},
//        {2, 0, 0, 3, 0, 0, 0, 0, 6},
//        {0, 0, 0, 2, 0, 0, 9, 0, 0},
//        {0, 0, 1, 9, 0, 4, 5, 7, 0}
    
//                {0,0,0, 4,0,0, 8,7,0}, 
//                {0,4,7, 0,9,2, 0,5,0},
//                {2,0,0, 6,0,0, 0,3,0},
//                {9,7,0, 5,0,0, 2,0,3},
//                {5,0,8, 0,2,4, 7,0,6},
//                {6,0,4, 0,0,7, 0,8,5},
//                {0,9,0, 3,0,8, 0,0,7},
//                {0,0,3, 2,4,0, 1,6,0},
//                {0,1,2, 0,0,0, 0,9,0}  
//
//             {  {2,0,7, 0,0,9, 0,0,0}, 
//                {0,0,0, 3,0,4, 0,5,0},
//                {1,0,0, 0,0,5, 6,0,8},
//                {8,0,0, 4,0,3, 0,6,0},
//                {3,1,0, 2,0,8, 0,7,4},
//                {0,9,0, 1,0,7, 0,0,3},
//                {7,0,4, 5,0,0, 0,0,2},
//                {0,2,0, 8,0,6, 0,0,0},
//                {0,0,0, 9,0,0, 4,0,6}  };
    
//           = {  {0,0,9, 0,3,0, 0,8,0}, 
//                {0,0,2, 8,0,0, 0,0,0},
//                {8,5,0, 0,0,6, 7,2,0},
//                {0,2,0, 0,0,0, 1,7,5},
//                {5,0,0, 0,0,0, 0,0,4},
//                {7,4,6, 0,0,0, 0,9,0},
//                {0,8,5, 6,0,0, 0,4,7},
//                {0,0,0, 0,0,3, 9,0,0},
    int grille[9][9] = {
        {1,0,0,0,0,7,0,9,0},
        {0,3,0,0,2,0,0,0,8},
        {0,0,9,6,0,0,5,0,0},
        {0,0,5,3,0,0,9,0,0},
        {0,1,0,0,8,0,0,0,2},
        {6,0,0,0,0,4,0,0,0},
        {3,0,0,0,0,0,0,1,0},
        {0,4,0,0,0,0,0,0,7},
        {0,0,7,0,0,0,3,0,0},
    };
    // Remplit notre grille avec la grille test, et met constante à TRUE
    for (i = 0; i < g->longueur; i++) {
        for (j = 0; j < g->hauteur; j++) {
            if (grille[i][j]){
                g->c[i][j].valeur = grille[i][j];
                g->c[i][j].constante = TRUE;
                g->c[i][j].solution = grille[i][j];
            }
        }
    }
    return g;
}

void testAffichageGrille(Grille *g){
    int i,j,k;
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
    
    afficherGrille(g);
}

void testResolution(Grille *g){
    Position *p = initPosition(0,0);
    int k=-1;
    clock_t start, end;
    double temps=0;

    if(grilleResolue(g)) printf("\n Grille resolue ! \n");
    else  printf("\n Grille pas resolue ! \n");
    
//     ici l'on a toutes les possibilitées par cases
//     on va essayer des réduires avec une fonction supplémentaire
    for(p->y=0;p->y<(g->longueur);p->y++){
            for(p->x=0;p->x<(g->hauteur);p->x++){
            printf("[%d][%d]",p->y,p->x);
            for(k=1;k<=TAILLE;k++){
                if(estPossible(k,g,p))
                     printf("%2d ",k);
            }
            printf("\n");
        }
    }
    
    printf("\n");
    Checkpoint *chemin = NULL;
    //On va commencer a créer notre chemin
    chemin=cheminBacktracking(g);

    printf("\n\n");
    afficherChemin(chemin);
    
    // Chronometre le temps de résolution 
    start=clock();
    estResolue(g,chemin);
    end=clock();
    temps+=((double)end-start)/CLOCKS_PER_SEC;
   
    printf("\ntemps pour résoudre: %lf \n",temps);
    
    if(grilleResolue(g)) printf("\n Grille resolue ! \n");
    else  printf("\n Grille pas resolue ! \n");
    afficherGrille(g);
    
    
    free(p);
    freeChemin(chemin);
    printf("\n");
   
}

void testResolutionGrilleVide(void){
    Grille*ga = initGrille();
    Checkpoint* chemin = cheminBacktracking(ga);


    afficherGrille(ga);
    estResolue(ga,chemin);
    afficherGrille(ga);

    freeChemin(chemin);
    freeGrille(ga);
}

void testSDL(void){
    // Fenetre ou tout va s'afficher
    SDL_Window* fenetre = NULL;
    // Surface contenu dans la fenetre
    SDL_Surface* ecran = NULL;
    if(!initSDL(fenetre,ecran)){
        printf("Erreur lors de la création fenêtre SDL");
        exit(404);
    }
    // Pour savoir lorsque l'on quitte le programme
    int quitter = FALSE;
    // Gère les evenement en SDL
    SDL_Event e;
    // Boucle de jeu
    while(!quitter){
        // FILE des événements (interaction clavier/souris, joystick, etc..)
        // Boucle d'événement jusqu'à ce que la FILE soit vide
        while(!SDL_PollEvent(&e)){
            //Si on ferme la fenêtre SDL
            switch(e.type){
                case SDL_QUIT:
                    quitter = TRUE;
                    break;
                default:
                    break;
            }
        }
    }
    
    quitSDL(fenetre,ecran);
}