
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
//  *********************************************
//  Declarations des fonctions autres que le main
//  *********************************************

/**
 * @brief Excute la boucle principale du jeu
 * @name jeu_executer
 * @param terrain la terrain sur lequel le joueur evolue
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param joueur_carburant la quantite de carburant du joueur
 * @param destination_ligne la ligne de la case a atteindre
 * @param destination_colonne la colonne de la case a atteindre
 */
//  Ecrire le prototype de la fonction 'jeu_executer' ici

//  ******************************
//  Definition de la fonction main
//  ******************************
/*
int main(void) {
    srand((unsigned int) time(NULL));        // ligne qui sert à genéré le chiffre aléatoire
    rand();                                 // ligne qui sert à genéré le chiffre aléatoire


    //  Les donnees du jeu : terrain, joueur, case de sortie
    t_terrain terrain;
    int joueur_ligne, joueur_colonne, joueur_carburant; //  le joueur
    int destination_ligne, destination_colonne; //  la case de destination

    //  initialisation du jeu
    jeu_init(terrain, &joueur_ligne, &joueur_colonne, &joueur_carburant, &destination_ligne, &destination_colonne);

    //  Presentation du jeu
    interaction_presenter_jeu();

    //  Boucle principale du jeu
    //jeu_executer(terrain, joueur_ligne, joueur_colonne, joueur_carburant, destination_ligne, destination_colonne);

    return 0;
}

//  ********************************************
//  Definitions des fonctions autres que le main
//  ********************************************
// Definir la fonction 'jeu_executer' ici */