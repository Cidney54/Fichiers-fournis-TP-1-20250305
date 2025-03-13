
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
void jeu_executer(int terrain[NB_LIGNES][NB_COLONNES], int joueur_ligne, int joueur_colonne, int joueur_carburant,
                  int destination_ligne, int destination_colonne);

//  ******************************
//  Definition de la fonction main
//  ******************************

/*int main(void) {

    interaction_presenter_jeu();

    int t_terrain[NB_LIGNES][NB_COLONNES] = {};
    int sortie_ligne = 0;
    int sortie_colonne = 0;
    int depart_ligne = 0;
    int depart_colonne = 0;
    int joueur_carburant = JOUEUR_CARBURANT_INITIAL;

    terrain_creer_stations_carburant(t_terrain,TOTAL_CARBURANT_NIVEAU_1);
    do {
        terrain_generer_position_sortie(&sortie_ligne,&sortie_colonne);
    } while (t_terrain[sortie_ligne][sortie_colonne] == 0);

    do {
        terrain_generer_position_depart(sortie_ligne,sortie_colonne,&depart_ligne,&depart_colonne);
    } while (t_terrain[depart_ligne][depart_colonne]);

    terrain_afficher(t_terrain,&depart_ligne,&depart_colonne,sortie_ligne,sortie_colonne);

    interaction_afficher_option(joueur_carburant);
    jeu_executer(t_terrain,depart_ligne,depart_colonne,joueur_carburant,sortie_ligne,sortie_colonne);
}

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
} */

//  ********************************************
//  Definitions des fonctions autres que le main
//  ********************************************
// Definir la fonction 'jeu_executer' ici */