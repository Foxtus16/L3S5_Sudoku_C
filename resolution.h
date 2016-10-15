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


#ifndef RESO_H
#define RESO_H

#include <stdio.h>
#include <stdlib.h>
#include "bilan_memoire.h"
#include "macro.h"
        
/*! \fn int estSurLigne()
 *  \brief Init une grille de sudoku
 *  \param val:
 *  \return Renvoit TRUE si valeur déjà présente sur la ligne sinon FALSE */
int estSurLigne();


#endif /* RESO_H */

