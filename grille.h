/******************************************************************************!
 * \file     grille.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     09/10/16
 * \brief    Déclaration des fonctions pour la grille de sudoku
 * 
 * \details  
 *
 * 
 ******************************************************************************/

#ifndef GRILLE_H
#define GRILLE_H

#include <stdio.h>
#include <stdlib.h>

/*! \struct  Case
 *  \brief   Type pour les case d'une grille de sudoku
 *  \details Cette structure nous sert à savoir si la valeur est constante, 
             ou si la valeur est bien la valeur solution de cette case*/
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


#endif /* GRILLE_H */

