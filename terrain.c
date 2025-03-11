//
// Created by stephane on 08/01/25.
//

#include <stdio.h>
#include <stdlib.h>
// #include <couleur.h>
#include "terrain.h"
#include <stdbool.h>


//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'terrain_generer_position_sortie' ici

void terrain_generer_position_sortie(int *sortie_ligne, int *sortie_colonne) {

    /* Générer et enregistrer les coordonnées de sortie aléatoire. */
    *sortie_ligne = nb_aleatoire(0, NB_LIGNES - 1);
    *sortie_colonne = nb_aleatoire(0, NB_COLONNES - 1);
}

// Definir la fonction 'terrain_generer_position_depart' ici

void terrain_generer_position_depart(int destination_ligne, int destination_colonne, int *depart_ligne,
                                     int *depart_colonne) {

    /* Boucle de génération de coordonnées aléatoires tant que la distance « Manhattan » entre les coordonnées de
     * départ et de sortie n'est pas plus grande que dix. */
    do {

        /* Générer et enregistrer les coordonnées de sortie aléatoire. */
        *depart_ligne = nb_aleatoire(0, NB_LIGNES - 1);
        *depart_colonne = nb_aleatoire(0, NB_COLONNES - 1);

    } while (abs(destination_ligne - *depart_ligne) + abs(destination_colonne - *depart_colonne) <= 10);
}


// Definir la fonction 'terrain_contient' ici

int terrain_contient(int position_ligne, int position_colonne) {

    /* Vérifier si les coordonnées sont à l'extérieur de l'intervalle x[0,9] et y[0,9]. */
    if (position_ligne < 0 || position_colonne < 0 || position_ligne >= NB_LIGNES || position_colonne >= NB_COLONNES) {

        return false;
    } else {
        return true;
    }
}

// Definir la fonction 'terrain_get_carburant' ici

int terrain_get_carburant(int terrain[NB_LIGNES][NB_COLONNES], int position_ligne, int position_colonne) {

    /* Retourner la valeur dans la case spécifiée. */
    return terrain[position_ligne][position_colonne];

}

// Definir la fonction 'terrain_set_carburant' ici

void terrain_set_carburant(int terrain[NB_LIGNES][NB_COLONNES], int position_ligne, int position_colonne,
                           int carburant) {

    /* Enregistrer la quantité de carburant dans la case en paramètre. */
    terrain[position_ligne][position_colonne] = carburant;
}

// Definir la fonction 'terrain_init' ici

void terrain_init(int terrain[NB_LIGNES][NB_COLONNES]) {

    /* Parcourir les lignes du tableau. */
    for (int i = 0; i < NB_LIGNES; i++) {

        /* Parcourir les colonnes du tableau. */
        for (int j = 0; j < NB_COLONNES; j++) {

            terrain[i][j] = 0; // Initialiser la case à « 0 ».
        }
    }
}

// Definir la fonction 'terrain_creer_stations_carburant' ici

void terrain_creer_stations_carburant(int terrain[NB_LIGNES][NB_COLONNES], int quantite_globale) {

    /* Initialiser les variables. */
    int carburant = 0; // La quantité de carburant à stocker dans une case.

    /* Boucle pour remplir des cases tant que la quantité de carburant total n'est pas rendue nulle. */
    do {

        /* Boucle pour parcourir les lignes du tableau. */
        for (int i = 0; i < NB_LIGNES; i++) {

            /* Boucle pour parcourir les colonnes du tableau. */
            for (int j = 0; j < NB_COLONNES; j++) {

                /* Vérifier que la case n'est pas déjà rempli. */
                if (terrain[i][j] == 0) {

                    /* Créer un nombre aléatoire dans l'intervalle [1,100]. */
                    int ratio_zero = nb_aleatoire(1, 100);

                    /* Remplir le tableau du carburant en limitant les cases potentielles jusqu'à que la quantité
                     * globale de carburant disponible est moins que le maximum qui peut être déposé dans une case. */
                    if (ratio_zero > 99 && quantite_globale > STATION_MAX_CARBURANT) {

                        carburant = nb_aleatoire(0,
                                                 STATION_MAX_CARBURANT); // Générer une quantité aléatoire de carburant.
                        terrain_set_carburant(terrain, i, j, carburant); // Enregistrer le carburant dans la case.
                        quantite_globale -= carburant; // Soustraire le carburant de la quantité totale.

                    }
                        /* Remplir le tableau avec le carburant restant jusqu'à la quantité est nulle. */
                    else if (ratio_zero > 99 && quantite_globale <= STATION_MAX_CARBURANT) {

                        /* Générer une quantité de carburant tant qu'elle ne dépasse pas la quantité disponible. */
                        do {

                            carburant = nb_aleatoire(0,
                                                     STATION_MAX_CARBURANT); // Générer une quantité aléatoire de carburant.

                        } while (quantite_globale - carburant < 0);

                        terrain_set_carburant(terrain, i, j, carburant); // Enregistrer le carburant dans la case.
                        quantite_globale -= carburant; // Soustraire le carburant déposé de la quantité total.
                    }
                }
            }
        }
    } while (quantite_globale > 0);
}

// Definir la fonction 'terrain_afficher' ici

void terrain_afficher(int terrain[NB_LIGNES][NB_COLONNES], int *courante_ligne, int *courante_colonne,
                      int destination_ligne, int destination_colonne) {

    /* Afficher le tableau. */
    /* Parcourir chaque ligne du tableau en incluant les lignes de séparation. */
    for (int i = -1; i < NB_LIGNES * 2; i++) {

        /* Parcourir chaque colonne du tableau. */
        for (int j = 0; j < NB_COLONNES; j++) {

            /* Vérifier si la ligne agit d'une ligne de séparation ou de valeurs du tableau. */
            if (i % 2 != 0) {

                printf("+---"); // Afficher les caractères pour la ligne de sépraration.
            } else {

                if (i / 2 == *courante_ligne && j == *courante_colonne) {

                    printf("|");

                    // couleur_set(STYLE_BOLD,FG_RED,BG_BLACK); // Changer la couleur de la case de position actuel du joueur.
                    printf(" X ");
                } else if (i / 2 == destination_ligne && j == destination_colonne) {


                    printf("|");

                    // couleur_set(STYLE_BOLD,FG_BLUE,BG_BLACK); // Changer la couleur de la case destination du joeur.

                    printf(" Y ");
                } else {

                    printf("| %d ", terrain[i / 2][j]); // Afficher la valeur correspondante du tableau.
                }
            }
        }

        // couleur_reset; // Réinitialiser les couleurs de l'affichage.

        /* Vérifier si la ligne agit d'une ligne de séparation ou de valeurs du tableau. */
        if (i % 2 != 0) {

            printf("+\n"); // Effectuer un retour à la prochaine ligne de valeurs du tableau.
        } else {

            printf("|\n"); // Effectuer un retour à la prochaine ligne de séparation.
        }
    }
}