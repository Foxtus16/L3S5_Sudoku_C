/******************************************************************************!
 * \file     grille.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     09/10/16
 * \brief    Déclaration des fonctions pour la grille de sudoku
 * 
 * \details  Contient des structures fonctions pour gérer la grille de sudoku
 *
 * 
 ******************************************************************************/

#ifndef GRILLE_H
#define GRILLE_H

#include <stdio.h>
#include <stdlib.h>
#include "bilan_memoire.h"
#include "macro.h"

/*! \struct  Position
 *  \brief   Type pour savoir la position dans la grille
 *  \details Cette structue sert pour déterminer où placer une valeur sur la 
 *           grille de sudoku dont l'origine est en haut à gauche */
typedef struct Position{
    int y; /*!< axe des ordonnées (ligne) */
    int x; /*!< axe des abscisses (colonne) */
}Position;

typedef enum Difficulte{
    NEANT = 0,
    FACILE = 1,
    MOYEN =2,
    DIFFICILE=3
}Difficulte;

/*! \struct  Case
 *  \brief   Type pour les case d'une grille de sudoku
 *  \details Cette structure nous sert à savoir si la valeur est constante, 
 *           ou si la valeur est bien la valeur solution de cette case*/
typedef struct Case{
    int valeur, constante, solution;
}Case;

/*! \struct  Grille
 *  \brief   Type pour la grille de sudoku
 *  \details Tableaux à 2 dimensions de Case */
typedef struct Grille{
    Case** c;
    int longueur, hauteur; /*!< Dimensions de la grille*/ 
}Grille;

/*! \fn Position* initPosition(int y, int x)
 *  \brief Init une Position 
 *  \param p: initialise les champs de position à 0 
 *  \return Un élément Position alloué dynamiquement à libérer*/
Position* initPosition(int y, int x);

/*! \fn int estValidePosition(Position *p)
 *  \brief Vérifie que la position ne sort pas de la grille
 *  \param p: Position que l'on vérifie 
 *  \return TRUE si ok sinon FALSE*/
int estValidePosition(Position *p);

/*! \fn void initCase(Case *c)
 *  \brief Init une Case 
 *  \param c: initialise les champs de Case à 0 */
void initCase(Case *c);

/*! \fn Grille* initGrille()
 *  \brief Init une grille de sudoku
 *  \return Renvoit une grille avec des cases initialisé à 0 */
Grille *initGrille();

/*! \fn Grille* void freeGrille(Grille *g)
 *  \brief Free les cases allouées dynamiquement */
void freeGrille(Grille *g);


/*! \fn void afficherGrille(Grille *g);
 *  \brief Affiche une grille de Sudoku  */
void afficherGrille(Grille *g);


/*! \fn void getCasesEnlever(Difficulte diff);
 *  \brief Récupère les cases à enlever en fonction de la diffculté choisie par l'utilisateur  */
int getCasesEnlever(Difficulte diff);


/*! \fn créerGrilleJouable(Grille *g, char difficulté);
 *  \brief Vide n cases en fonction de la difficulté choisie et définit les cases remplies comme constantes*/
void creeGrilleJouable(Grille *g, Difficulte diff);

#endif /* GRILLE_H */

