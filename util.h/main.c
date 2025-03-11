//#include <stdio.h>

#ifndef CODE_UTILITAIRE_H
#define CODE_UTILITAIRE_H


//  *********************************
//  Definitions des fonctions publics
//  *********************************


/**
 * @brief Retourne le plus petit entier entre 2 entiers.
 * @name min
 * @param entier1 le premier entier
 * @param entier2 le deuxieme entier
 * @return le plus petit entier
 */
int min(int entier1, int entier2);


/**
 * @brief Retourne la valeur absolue d'un entier
 * @name abs
 * @param entier
 * @return valeur absolue de l'entier
 */
int abs(int entier);

//int aleatoire(int min, int max);


/**
 * @brief Retourne un entier aleatoire se trouvant dans une intervalle
 * @name nb_aleatoire
 * @param min la valeur minimale de l'intervalle
 * @param max la valeur maximale de l'intervalle
 * @return un entier aleatoire
 */
int nb_aleatoire(int min, int max);


/**
 * @brief Retourne le symetrique d'un entier compris dans un intervalle
 * @name util_symetrique
 * @param min la valeur minimale de l'intervalle
 * @param max la valeur maximale de l'intervalle
 * @param n la valeur se trouvant dans l'intervalle, auquel on veut calculer son symetrique
 * @return le symetrique de l'entier n
 */
int util_symetrique(int min, int max, int n);


#endif
