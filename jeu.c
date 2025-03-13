//
// Created by stephane on 08/01/25.
//
#include <interaction.h>
#include <terrain.h>
#include <jeu.h>

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
    terrain_set_carburant(terrain, joueur_ligne, joueur_colonne, joueur_carburant);

    int i, j;
    while (joueur_ligne && joueur_colonne == terrain[i][j]) {

        joueur_carburant += 0;
    }


}
// Definir la fonction 'jeu_deplacer_joueur' ici

// Definir la fonction 'jeu_init' ici

void jeu_init(int terrain[NB_LIGNES][NB_COLONNES], int *joueur_ligne, int *joueur_colonne, int *joueur_carburant,
              int *destination_ligne, int *destination_colonne) {

    /* Initialiser les variables. */
    int sortie_ligne; // Ligne de destination de sortie.
    int sortie_colonne; // Colonne de desitination de sortie.
    int depart_ligne; // Ligne de départ du joueur.
    int depart_colonne; // Colonne de départ du joueur.

    /* Générer les stations de carburant sur le terrrain. */
    terrain_creer_stations_carburant(terrain, TOTAL_CARBURANT_NIVEAU_1);

    /* Boucle afin d'assurer que la sortie ne se retrouve pas sur une station de carburant. */
    do {
        terrain_generer_position_sortie(&sortie_ligne, &sortie_colonne); // Générer la position de sortie.
    } while (terrain[sortie_ligne][sortie_colonne] != 0);

    /* Boucle afin d'assurer que la position de départ ne se retrouve pas sur une station de carburant. */
    do {
        terrain_generer_position_depart(sortie_ligne, sortie_colonne, &depart_ligne,
                                        &depart_colonne); // Générer la position de départ.
    } while (terrain[depart_ligne][depart_colonne] != 0);

    /* Enregistrer les coordonnées de sortie et de départ dans les paramètres de la fonction. */
    *joueur_ligne = sortie_ligne;
    *joueur_colonne = sortie_colonne;
    *destination_ligne = depart_ligne;
    *destination_colonne = depart_colonne;

    /* Afficher le terrain à l'utilisateur. */
    terrain_afficher(terrain, joueur_ligne, joueur_ligne, *destination_ligne, *destination_colonne);

    /* Afficher les options et le carburant disponible à l'utilisateur. */
    interaction_afficher_option(*joueur_carburant);
}

// Definir la fonction 'jeu_afficher_direction' ici

// Definir la fonction 'jeu_verifier_choix_deplacement' ici

// Definir la fonction 'jeu_calculer_voisin' ici

// Definir la fonction 'jeu_verifier_fin' ici
