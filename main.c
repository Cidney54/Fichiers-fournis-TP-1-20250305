
#include "dijkstra.h"
#include "interaction.h"
#include "jeu.h"
#include "stdio.h"
#include "stdlib.h"
#include "terrain.h"
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
void jeu_executer(t_terrain terrain, int joueur_ligne, int joueur_colonne, int joueur_carburant, int destination_ligne,
    int destination_colonne);

//  ******************************
//  Definition de la fonction main
//  ******************************

int main(void) {

    /* Réinitialiser le générateur de nombre aléatoire. */
    srand((unsigned int) time(NULL));
    rand();

    /* Initialiser les variables. */
    t_terrain terrain = {}; // Terrain de jeu.
    terrain_init(terrain); // Initialiser toutes les cases du terrain à « 0 ».
    int sortie_ligne = 0; // Ligne de position de sortie.
    int sortie_colonne = 0; // Colonne de position de sortie.
    int depart_ligne = 0; // Ligne de position de départ.
    int depart_colonne = 0; // Colonne de position de départ.
    int joueur_carburant = JOUEUR_CARBURANT_INITIAL; // Quantité de carburant du joueur.

    /* Présenter du jeu. */
    interaction_presenter_jeu();

    /* Initialiser l'interface du jeu (positions de sortie et de départ, le tableau et le menu d'option). */
    jeu_init(terrain, &depart_ligne, &depart_colonne, &joueur_carburant, &sortie_colonne, &sortie_ligne);

    /* Démarrer le jeu pour l'utilisateur. */
    jeu_executer(terrain,depart_ligne,depart_colonne,joueur_carburant,sortie_ligne,sortie_colonne);

    return 0;

}

//  ********************************************
//  Definitions des fonctions autres que le main
//  ********************************************
// Definir la fonction 'jeu_executer' ici */

void jeu_executer(t_terrain terrain, int joueur_ligne, int joueur_colonne, int joueur_carburant,
    const int destination_ligne, const int destination_colonne) {

    /* Initialiser les variables d'éxécution de jeu. */
    t_jeu_etat jeu_etat = JEU_ETAT_EN_COURS; // L'état du jeu.
    int voisin_ligne, // La ligne de la case voisine.
    voisin_colonne; // La colonne de la case voisine.

    /* Initialiser et vérifier l'action demandée au joueur. */
    t_action action = interaction_demander_action(joueur_carburant);
    action = interaction_verifier_choix_action(action, joueur_carburant);

    /* Boucle pour exécuter les parties du jeu jusqu'à sa fin. */
    while (jeu_etat == JEU_ETAT_EN_COURS) {

        /* Traiter les actions demandées par le joueur. */
        switch (action) {

            /* Traiter l'action de déplacement. */
            case ACTION_DEPLACER:

                /* Initialiser la validation de la direction saisit par le joueur. */
                t_direction direction = DIRECTION_ERRONEE;

                /* Boucle pour saisir la direction tant qu'elle est erronée. */
                while (direction == DIRECTION_ERRONEE) {

                    /* Saisir et valider la direction de déplacement du joueur. */
                    direction = interaction_demander_direction_deplacement();
                    direction = jeu_verifier_choix_deplacement(direction);
                }

                /* Déterminer la case dans la direction de déplacement */
                jeu_calculer_voisin(joueur_ligne,joueur_colonne,direction,&voisin_ligne,&voisin_colonne);

                /* Vérifier si la case est contenu dans le terrain. */
                if (terrain_contient(voisin_ligne,voisin_colonne)) {

                    /* Mettre à jour le positionnement du joueur. */
                    jeu_deplacer_joueur(&joueur_ligne,&joueur_colonne,direction);

                    /* Mettre à joueur le carburant du joueur et la quantité dans la case du tableau. */
                    jeu_maj_carburant_joueur(joueur_ligne,joueur_colonne,&joueur_carburant,terrain);

                    /* Vérifier si le joueur est rendu à la destination de fin du jeu. */
                    jeu_etat = jeu_verifier_fin(joueur_ligne,joueur_colonne,joueur_carburant,destination_ligne,
                        destination_colonne);

                }

                break;

            /* Traîter l'action d'achat de bonus. */
            case ACTION_ACHETER_BONUS:

                dijkstra_acheter_bonus(terrain,joueur_ligne,joueur_colonne,&joueur_carburant,destination_ligne,
                    destination_colonne);
                break;

            /* Traiter l'action de quitter le jeu. */
            case ACTION_QUITTER:

                /* Définir le jeu comme échoué afin de sortir du boucle principal. */
                jeu_etat = JEU_ETAT_ECHEC;

                break;

            /* Traiter l'option d'un choix d'action invalide. */
            default:
                break;
        }

        /* Vérifier si le jeu est toujours en cours que l'action choisie a été traitée et était valide. */
        if (jeu_etat == JEU_ETAT_EN_COURS && action != ACTION_INVALIDE) {

            /* Afficher le terrain modifié. */
            terrain_afficher(terrain,&joueur_ligne,&joueur_colonne,destination_ligne,destination_colonne);

            /* Afficher le les options à nouveau à l'utilisateur. */
            interaction_afficher_option(joueur_carburant);
        }
    }
}
