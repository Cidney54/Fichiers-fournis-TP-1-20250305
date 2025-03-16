
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

void jeu_exectuer(t_terrain terrain, int joueur_ligne, int joueur_colonne, int joueur_carburant, int destination_ligne,
    int destination_colonne) {

    t_jeu_etat jeu_etat = JEU_ETAT_EN_COURS;
    int voisin_ligne,
    voisin_colonne;

    while (jeu_etat == JEU_ETAT_EN_COURS) {

        t_action action = interaction_demander_action(joueur_carburant);
        action = interaction_verifier_choix_action(action, joueur_carburant);

        switch (action) {

            case ACTION_DEPLACER:
                t_direction direction = DIRECTION_ERRONEE;

                while (direction == DIRECTION_ERRONEE) {
                    direction = interaction_demander_direction_deplacement();
                    direction = jeu_verifier_choix_deplacement(direction);
                }

                jeu_calculer_voisin(joueur_ligne,joueur_colonne,direction,&voisin_ligne, &voisin_colonne);

                joueur_ligne = voisin_ligne;
                joueur_colonne = voisin_colonne;

                jeu_maj_carburant_joueur(joueur_ligne,joueur_colonne,&joueur_carburant,terrain);

                jeu_etat = jeu_verifier_fin(joueur_ligne,joueur_colonne,joueur_carburant,destination_ligne,
                    destination_colonne);

            case ACTION_ACHETER_BONUS:
                printf("ok");
            case ACTION_QUITTER:
                printf("ok");
            default:

        }
    }
}
