/******************************************************************************!
 * \file     bilan_memoire.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     15/10/16
 * \brief    Déclaration des fonctions interfaces d'allo dynamique et fichiers
 * 
 * \details  Ces fonctions lancent les fonctions usuelles d'allocation 
 *           dynamiques et d'ouverture de fichiers mais incrémentent une var
 *           globales pour faire les comptes dans un fichier 
 *           Il faut inclure ce fichier à chaque fois pour chaque module.
 * 
 * 
 ******************************************************************************/

#ifndef BILAN_MEMOIRE_H
#define BILAN_MEMOIRE_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

/*! \fn void *mon_malloc (size_t size)
 *  \brief Fonction appelant malloc et incrémente NB_MALLOC (global).
 *  \param size: Taille à allouer (type size_t standard) 
 *  \return Renvoit un pointeur vers l'espace mémoire crée */
void *mon_malloc (size_t size);

/*! \fn void mon_free (void *ptr)
 *  \brief Libère l'espace mémoire alloué et incrémente NB_FREE
 *  \param ptr: Pointeur vers l'espace mémoire alloué dynamiquement */
void mon_free (void *ptr);

/*! \fn void *mon_calloc(size_t taille, size_t size)
 *  \brief Lance calloc et incrémente NB_MALLOC
 *  \param taille: nb d'espace mémoire à allouer
 *  \param size:   espace mémoire à allouer  
 *  \return Renvoit un pointeur vers l'espace mémoire crée */
void *mon_calloc(size_t taille, size_t size);

/*! \fn void *mon_fopen(const char* chemin_fichier,const char* type_operation)
 *  \brief Lance la fonction fopen et incrémente NB_OPEN
 *  \param chemin_fichier: Chemin du fichier
 *  \param yype_operation: Paramètre de la fonction fopen ("w","r",..) 
 *  \return Renvoit le pointeur du fichier crée */
void *mon_fopen(const char* chemin_fichier,const char* type_operation);

/*! \fn void mon_fclose(FILE* fichier_ouvert)
 *  \brief Lance fclose et incrémente NB_CLOSE
 *  \param fichier_ouvert: Ferme le fichier associé à ce pointeur */
void mon_fclose(FILE* fichier_ouvert);

/*! \fn void mon_fclose(FILE* fichier_ouvert)
 *  \brief Lance IMG_Load et incrémente NB_SURFACEALLOUE
 *  \param file: chemin de l'image chargé */
SDL_Surface* mon_IMG_Load(const char* file);

/*! \fn void mon_SDL_free(SDL_Surface*surface)
 *  \brief Lance SDL_FreeSurface et incrémente NB_FREESURFACE
 *  \param surface: Surface libérée */
void mon_SDL_free(SDL_Surface* surface);

/*! \fn void bilan_memoire(void)
 *  \brief Ecrit le bilan mémoire dans un fichier placé à la racine du projet */
void bilan_memoire(void);

#endif // BILAN_MEMOIRE_H
