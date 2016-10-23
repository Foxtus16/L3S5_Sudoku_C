/******************************************************************************!
 * \file     macro.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     15/10/16
 * \brief    Contient les defines et macro du programme 
 * 
 * \details  Regroupe les define utilisé dans le programme en plus des macros 
 *           car l'on ne sait jamais dans quel ordre le compilateur va opérer
 *           donc au moins l'on incluera cette bibliothèque après redéfinition 
 *           des fonctions pour éviter la récursivité infinie
 * 
 * 
 ******************************************************************************/

#ifndef MACRO_H
#define MACRO_H

    /*! Maccro de bilan_memoire */
    #define malloc(X) mon_malloc(X) 
    #define free(X) mon_free(X)
    #define calloc(Y,X) mon_calloc(Y,X)
    #define fopen(X,Y) mon_fopen(X,Y)
    #define fclose(X) mon_fclose(X)

    /*! Constantes de sudoku */
    #define REG    3
    #define TAILLE 9
    #define TRUE   1
    #define FALSE  0

#endif /* MACRO_H */

