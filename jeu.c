//
// Created by stephane on 08/01/25.
//
#include <interaction.h>
#include <terrain.h>

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'jeu_maj_carburant_joueur' ici
/**
 * @brief Met a jour la quantite de carburant du joueur apres un deplacement. Annule la quantite de carburant sur la case du joueur.
 * @name jeu_maj_carburant_joueur
 * @param joueur_ligne la ligne ou se trouve maintenant le joueur
 * @param joueur_colonne la colonne ou se trouve maintenant le joueur
 * @param joueur_carburant l'adresse ou placer la nouvelle quantite de carburant du joueur apres deplacement
 * @param terrain le terrain sur lequel le joueur s'est deplace
 */
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int joueur_carburant,
                              int terrain[NB_LIGNES][NB_COLONNES]) {
    terrain_set_carburant(terrain,joueur_ligne,joueur_colonne,joueur_carburant);

    int i,j;
    while(joueur_ligne && joueur_colonne == terrain[i][j]){

        joueur_carburant +=
    }


}
// Definir la fonction 'jeu_deplacer_joueur' ici

// Definir la fonction 'jeu_init' ici

// Definir la fonction 'jeu_afficher_direction' ici

// Definir la fonction 'jeu_verifier_choix_deplacement' ici

// Definir la fonction 'jeu_calculer_voisin' ici

// Definir la fonction 'jeu_verifier_fin' ici
