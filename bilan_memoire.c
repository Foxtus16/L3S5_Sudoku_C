/******************************************************************************!
 * \file     bilan_memoire.h
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     15/10/16
 * \brief    Implémentation des fonctions interfaces d'allo dyn et fichiers
 * 
 * \details  Ces fonctions lancent les fonctions usuelles d'allocation 
 *           dynamiques et d'ouverture de fichiers mais incrémentent une var
 *           globales pour faire les comptes et éviter les fuites
 * 
 * 
 ******************************************************************************/

#include "bilan_memoire.h"

/*! Variables global pour le compteur mémoire */
int NB_MALLOC=0;
int NB_FREE=0;
int NB_FOPEN=0;
int NB_FCLOSE=0;

void *mon_malloc (size_t size){  
    NB_MALLOC++;
    return malloc(size); 
}

void mon_free (void *ptr){ 
    NB_FREE++;
    free(ptr);
}

void *mon_calloc(size_t taille,size_t size){
    NB_MALLOC++;
    return calloc(taille,size);
}

void *mon_fopen(const char* chemin_fichier, const char* type_operation){
    NB_FOPEN++;
    return fopen(chemin_fichier,type_operation);
}

void mon_fclose(FILE* fichier_ouvert){
    NB_FCLOSE++;
    fclose(fichier_ouvert);
}

void bilan_memoire(void){
    FILE* fichier_memoire = NULL;
    NB_FOPEN++;
    fichier_memoire = fopen ("bilan_memoire.txt","w");

    if( NB_MALLOC!=NB_FREE )
        fprintf(fichier_memoire,"Erreur memoire: %d allocations et %d liberation\n",NB_MALLOC,NB_FREE);
    else
        fprintf(fichier_memoire,"Pas d'erreur memoire : %d allocations  et %d liberation !\n",NB_MALLOC,NB_FREE);
    if (NB_FOPEN!=NB_FCLOSE)
        fprintf(fichier_memoire,"Erreur memoire: %d fichiers ouverts et %d fichiers fermes\n",NB_FOPEN,NB_FCLOSE);
    else
        fprintf(fichier_memoire,"Pas d'erreur memoire : %d fichiers ouverts et %d fichiers fermes !\n",NB_FOPEN,NB_FCLOSE);

    NB_FCLOSE++;
    fclose(fichier_memoire);
}
