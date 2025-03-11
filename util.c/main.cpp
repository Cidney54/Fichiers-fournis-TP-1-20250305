#include <iostream>
#include <stdio.h>

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************


int min(int entier1, int entier2) {
    if (entier1 < entier2) {
        //si le premier entier est plus petit, on retourne le premier
        return entier1;
    } else {
        //sinon, on retourne le deuxieme
        return entier2;
    }
}


int abs(int entier) {
    if (entier < 0) {
        //si l'entier est plus petit que 0,
        entier = entier * (-1); //l'entier est multiplié par -1.

        return entier;
    } else {
        return entier;
    }
}


int nb_aleatoire(int min, int max) {
    //fonction qui prend un chiffre aleatoire dans une intervalle
    return min + rand() % (max - min + 1);
}


int util_symetrique(int min, int max, int n) {
    //fonction qui calcule le symetrique d'un entier dans une intervalle
    int symetrique = max + min - n;

    return symetrique;
}




