//
// Created by stephane on 08/01/25.
//

#include <jeu.h>

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'jeu_maj_carburant_joueur' ici

// Definir la fonction 'jeu_deplacer_joueur' ici

// Definir la fonction 'jeu_init' ici

void jeu_init(int terrain[NB_LIGNES][NB_COLONNES], int *joueur_ligne, int *joueur_colonne, int *joueur_carburant,
    int *destination_ligne, int *destination_colonne) {

    terrain_creer_stations_carburant(terrain,TOTAL_CARBURANT_NIVEAU_1);
    do {
        terrain_generer_position_sortie(*destination_ligne,*destination_colonne);
    } while (terrain[*destination_ligne][*destination_colonne] == 0);

    do {
        terrain_generer_position_depart(*destination_ligne,*destination_colonne,*joueur_ligne,*joueur_colonne);
    } while (terrain[*joueur_ligne][*joueur_colonne]);

    terrain_afficher(terrain,*joueur_ligne,*joueur_ligne,*destination_ligne,*destination_colonne);
}

// Definir la fonction 'jeu_afficher_direction' ici

// Definir la fonction 'jeu_verifier_choix_deplacement' ici

// Definir la fonction 'jeu_calculer_voisin' ici

// Definir la fonction 'jeu_verifier_fin' ici
