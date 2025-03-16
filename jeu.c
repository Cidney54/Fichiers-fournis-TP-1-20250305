//
// Created by stephane on 08/01/25.
//
#include <interaction.h>
#include <terrain.h>
#include <jeu.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
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
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int *joueur_carburant,
                              t_terrain terrain) {

    *joueur_carburant += terrain_get_carburant(terrain, joueur_ligne, joueur_colonne);
    *joueur_carburant -= COUT_DEPLACEMENT_VOISIN;
    terrain_set_carburant(terrain, joueur_ligne, joueur_colonne, 0);

}
// Definir la fonction 'jeu_deplacer_joueur' ici
/**
 * @brief Deplace le joueur dans une dircetion donnee.
 * @name jeu_deplacer_joueur
 * @param joueur_ligne l'adresse de la ligne ou se trouve le joueur avant le deplacement et qui sera mise a jour
 * @param joueur_colonne l'adresse de la colonne ou se trouve le joueur avant le deplacement et qui sera mise a jour
 * @param direction la direction dans laquelle on veut deplacer le joueur
 * @return true si le deplacement a pu se faire dans les lilmites du terrain, false sinon
 */

int jeu_deplacer_joueur(int *joueur_ligne, int *joueur_colonne, int direction) {
    direction = interaction_demander_direction_deplacement();

    int condition = 1;
    if (direction == DIRECTION_DROITE) {
        *joueur_colonne += 1;

    } else if (direction == DIRECTION_BAS) {
        *joueur_ligne -= 1;
    } else if (direction == DIRECTION_HAUT) {
        *joueur_ligne += 1;
    } else if (direction == DIRECTION_GAUCHE) {
        *joueur_colonne -= 1;
    }

    if (*joueur_ligne > NB_LIGNES || *joueur_ligne < 0) {
        condition = false;
    } else if (*joueur_colonne > NB_COLONNES || *joueur_colonne < 0) {
        condition = false;
    }
    return condition;
}

void tester_jeu_deplacer_joueur() {


    int joueur_ligne = 0;
    int joueur_colonne = 0;
    int t_terrain[joueur_ligne][joueur_colonne];
    int direction;


    assert(jeu_deplacer_joueur(&joueur_ligne, &joueur_colonne, direction) !=
           joueur_colonne + 1);
    printf("%i", joueur_colonne);

}
// Definir la fonction 'jeu_init' ici

void jeu_init(t_terrain terrain, int *joueur_ligne, int *joueur_colonne, int *joueur_carburant, int *destination_ligne,
              int *destination_colonne) {

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

/**
 * @brief Affiche une direction en toutes lettres
 * @name jeu_afficher_direction
 * @param direction la direction a afficher
 */
void jeu_afficher_direction(int direction) {
    direction = interaction_demander_direction_deplacement();

    if (direction == DIRECTION_DROITE) {
        printf("Droite\n");
    }
    if (direction == DIRECTION_GAUCHE) {
        printf("Gauche\n");
    }
    if (direction == DIRECTION_HAUT) {
        printf("Haut\n");
    }
    if (direction == DIRECTION_BAS) {
        printf("Bas\n");
    }
    if (direction > 3 || direction < 0) {
        printf("erroné");
    }


}


// Definir la fonction 'jeu_verifier_choix_deplacement' ici
/**
 * @brief Recupere une direction saisie sous la forme d'une chaine de caracteres,
 * s'assure qu'elle est valide et retourne la constante correspondante.
 * @ame jeu_verifier_choix_deplacement
 * @param choix une chaine de caractere constituant un choix de direction du joueur
 * @return DIRECTION_ERRONEE si la chaine ne correspond pas a l'une des 4 directions.
 * Sinon, retourne DIRECTION_HAUT ou DIRECTION_BAS ou DIRECTION_DROITE ou DIRECTION_GAUCHE selon la direction choisie
 */
int jeu_verifier_choix_deplacement(int choix) {


}
// Definir la fonction 'jeu_calculer_voisin' ici
/**
 * @brief Calcule la position d'un voisin dans une direction donnee.
 * @name jeu_calculer_voisin
 * @param case_ligne la ligne de la case de depart
 * @param case_colonne la colonne de la case de depart
 * @param direction la direction dans laquelle se trouve le voisin
 * @param voisin_ligne l'adresse ou placer la ligne du voisin selon la direction
 * @param voisin_colonne l'adresse ou placer la colonne du voisin selon la direction
 */
void jeu_calculer_voisin(int case_ligne, int case_colonne, int direction, int *voisin_ligne, int *voisin_colonne) {


}


// Definir la fonction 'jeu_verifier_fin' ici
/**
 * @brief Verifie si le jeu est termine ou non.
 * @name jeu_verifier_fin
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param joueur_carburant la quantite de carburant actuel du joueur
 * @param destination_ligne la ligne de la destination
 * @param destination_colonne la colonne de la destination
 * @return JEU_ETAT_VICTOIRE si le joueur a atteint la case d'arrivee.
 * JEU_ETAT_ECHEC si le joueur n'a plus de carburant.
 * JEU_ETAT_EN_COURS si la partie est en cours.
 */
int jeu_verifier_fin(int joueur_ligne, int joueur_colonne, int joueur_carburant, int destination_ligne,
                     int destination_colonne) {


    //terrain_generer_position_depart(joueur_ligne, joueur_colonne, &destination_ligne, &destination_colonne);
    int etat_jeu = 0;

    if (joueur_ligne == destination_ligne && joueur_colonne == destination_colonne && joueur_carburant >= 0) {

        etat_jeu = JEU_ETAT_VICTOIRE;

    } else if (joueur_ligne != destination_ligne && joueur_colonne != destination_colonne && joueur_carburant > 0) {
        etat_jeu = JEU_ETAT_EN_COURS;
    } else if (joueur_ligne != destination_ligne && joueur_colonne != destination_colonne && joueur_carburant == 0) {
        etat_jeu = JEU_ETAT_ECHEC;
    }

    return etat_jeu;
}


int main() {


}