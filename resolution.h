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
        
/*! \struct  Checkpoint
 *  \brief   Type pour savoir le chemin optimal pour la résolution
 *  \details Cette structure permet d'avoir un chemin pour notre backtracking
 *           trié par ordre croissant de solutions par case via une liste */
typedef struct checkpoint{
    int nbSol_;
    Position *p_;
    struct checkpoint* next_;
}Checkpoint;

/*! \fn Checkpoint* initCheckpoint()
 *  \brief Init un checkpoint du chemin et ses champs
 *  \param nbSol: initialise le nb de solution du checkpoint
 *  \param p: initialise la position du checkpoint
 *  \return Un Checkpoint alloué dynamiquement à libérer via fonction */
Checkpoint* initCheckpoint(Position *p, int nbSol);

/*! \fn Checkpoint* insertCheckpointTrie(Checkpoint* chemin, Checkpoint* chk)
 *  \brief Insert un checkpoint de manière triée
 *  \param chemin: le début du chemin
 *  \param chk: le checkpoint à insérer
 *  \return Le début du nouveau chemin */
Checkpoint* insertCheckpointTrie(Checkpoint* chemin, Checkpoint* chk);

/*! \fn Checkpoint* cheminBacktracking(Grille* g) 
 *  \brief Crée le chemin a prendre pour le remplissage de la grille
 *  \param grille: grille où l'on travaille
 *  \return Le chemin obtenu */
Checkpoint* cheminBacktracking(Grille* g);

/*! \fn void afficherChemin(Checkpoint* chemin)
 *  \brief Affiche chaque checkpoint du chemin
 *  \param chemin: le début du chemin */
void afficherChemin(Checkpoint* chemin);

/*! \fn void freeChemin(Checkpoint* chemin)
 *  \brief Free les champs du checkpoint et ses attributs */
void freeChemin(Checkpoint* chemin);

/*! \struct  Arbre
 *  \brief   Structure d'un arbre à 9 branche tableau dont l'indice = chiffre
 *  \details L'on peut ainsi parcourir notre grille à l'aide du backtracking */
typedef struct arbre{
    struct arbre* c[9];
}Arbre;

/*! \fn Arbre* initArbre()
 *  \brief Initialise le tableau d'arbre à null
 *  \return l'arbre crée */
Arbre* initArbre();

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
 *       On vérifie que la case est vide
 *  \return Renvoit TRUE si possible sinon FALSE */
int estPossible(int val, Grille *g, Position *p);

/*! \fn int estResolue(Grille *g, Checkpoint* chemin)
 *  \brief Fonction récursive pour résoudre le sudoku
 *  \details Cette fonction va parcourir le chemin en testant chaque 
 *           possibilité d'un checkpoint et passe au suivant 
 *           s'il ne peut plus avancer alors il rebrousse chemin et
 *          teste une autre possibilité ainsi de suite jusqu'à l'arrivée 
 *  \param g: Grille de sudoku où l'on travaille
 *  \param Chemin: Chemin emprunté par notre backtracking
 *  \return Renvoit TRUE si l'on atteind la fin du chemin
 *          sinon renvoit FALSE */
int estResolue(Grille *g, Checkpoint* chemin);

/*! \fn int grilleResolue(Grille *g)
 *  \brief Indique si la grille a été résolue
 *  \param g:   Grille de sudoku où l'on travaille
 *  \pre On vérifie que toutes les cases soient remplies
 *       On vérifie que chaque valeur est possible
 *  \return Renvoit TRUE si résolue sinon FALSE */
int grilleResolue(Grille *g);

#endif /* RESOLUTION_H */

