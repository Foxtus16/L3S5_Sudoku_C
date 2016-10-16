/******************************************************************************!
 * \file     main.c
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     09/10/16
 * \brief    Fichier main du sudoku
 * 
 * \details 
 *  
 * 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bilan_memoire.h"
#include "macro.h"
#include "grille.h"
#include "test.h"


int main(int argc, char** argv) {
    testGrille();
    
    bilan_memoire();
    return (EXIT_SUCCESS);
}

