/******************************************************************************!
 * \file     resolution.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     15/10/16
 * \brief    Déclaration des fonctions résolutions d'une grille de sudoku
 * 
 * \details   
 * 
 * 
 ******************************************************************************/


#ifndef RESOLUTION_H
#define RESOLUTION_H

#include <stdio.h>
#include <stdlib.h>
#include "bilan_memoire.h"
#include "macro.h"
#include "grille.h"
        
/*! \fn int int estDansLigne(int val, Grille *g, Position *p)
 *  \brief Vérifie si le chiffre est déjà présent dans la ligne 
 *  \param val: Valeur que l'on veut insérer
 *  \param g:   Grille où l'on veut insérer l'élément
 *  \param pos: Position sur la grille où l'on veut insérer le chiffre
 *  \return Renvoit TRUE si valeur déjà présente dans la ligne sinon FALSE */
int estDansLigne(int val, Grille *g, Position *p);

/*! \fn int estDansCol(int val, Grille *g, Position *p)
 *  \brief Vérifie si le chiffre est déjà présent dans la colonne 
 *  \param val: Valeur que l'on veut insérer
 *  \param g:   Grille où l'on veut insérer l'élément
 *  \param pos: Position sur la grille où l'on veut insérer le chiffre
 *  \return Renvoit TRUE si valeur déjà présente dans la col sinon FALSE */
int estDansCol(int val, Grille *g, Position *p);

/*! \fn int estDansSsReg(int val, Grille *g, Position *p)
 *  \brief Vérifie si le chiffre est déjà présent dans la ss-region 
 *  \param val: Valeur que l'on veut insérer
 *  \param g:   Grille où l'on veut insérer l'élément
 *  \param pos: Position sur la grille où l'on veut insérer le chiffre
 *  \return Renvoit TRUE si valeur déjà présente ds la ss reg sinon FALSE */
int estDansSsReg(int val, Grille *g, Position *p);

/*! \fn int estPossible(Grille *g, Position *p)
 *  \brief Regroupe les 3 conditions 'ligne, col, ssreg' 
 *  \param val: Valeur que l'on veut ajouter  
 *  \param g:   Grille de sudoku où l'on travaille
 *  \param pos: Position sur la grille où l'on veut travailler
 *  \pre On vérifie que position appartient à la grille
 *       On vérifie que la case n'est pas constante
 *  \return Renvoit TRUE si possible sinon FALSE */
int estPossible(int val, Grille *g, Position *p);


#endif /* RESOLUTION_H */

