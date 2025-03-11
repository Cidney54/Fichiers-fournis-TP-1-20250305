//
// Created by stephane on 09/01/25.
//

#include <stdlib.h>
#include <stdio.h>
#include <couleur.h>

#define NB_LIGNES 10
#define NB_COLONNES 10
//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'interaction_presenter_jeu' ici

void interaction_presenter_jeu() {

    printf("Bienvenue dans le jeu\n");
    printf("Dans ce jeu vous serez dans un véhicule contenant 2 litres de carburant initialement\n ");
    printf("vous allez être projeté dans un labyrinth composé de cases et vous aurez pour but de trouver la sortie\n ");
    printf("Votre position sera affiché par un signe X\n");
    printf("Les règles du jeu sont les suivantes: \n ");
    printf("\n");
    printf("-vous avez quatre déplacement disponible ( haut, bas, droite, gauche\n");
    printf("-À chaque déplacement vous perdez un litre de carburant\n");
    printf("-À chaque déplacement vous avez la posibilité de gagner entre 0 à 9 litre de carburant\n");
    printf("-Après s'être déplacé d'une case celle-ci est réinitialiser à zéro\n");
    printf("-La partie se termine si une des conditions suivantes est respecté: \n");
    printf("1. Vous avez trouvez la sortie\n");
    printf("2. Vous avez brulé tout votre carburant avant d'atteindre la sortie\n");


}

// Definir la fonction 'interaction_afficher_options' ici

/**
 * @brief Affiche les options du menu de jeu.
 * Une option non valide sera grisee.
 * @name interaction_afficher_options
 * @param carburant la quantite de carburant du joueur
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_options' ici

void interaction_afficher_option(int carburant) {

    printf("Voici vos options: \n");
    printf("1.Déplacer\n");
    if (carburant < 10) {
        couleur_set(0, 90, 40);
        printf("2.Acheter bonus\n");
    }
    if (carburant >= 10) {
        printf("2.Acheter bonus\n");
    }
    couleur_reset();
    printf("3.Quitter\n");


}


// Definir la fonction 'interaction_demander_action' ici

/**
 * @brief Demande un choix a l'utilisateur sur une des options du menu
 * @name interaction_demander_action
 * @param carburant la quantite de carburant du joueur
 * @return ACTION_DEPLACER, ACTION_ACHETER_BONUS ou ACTION_QUITTER selon l'option choisie par le joueur
 */

int interacion_demander_action(int carburant) {

    int action_deplacer = 1;
    int action_acheter_bonus = 2;
    int action_quitter = 3;
    int i;


    do {
        interaction_afficher_option(carburant);
        printf("Veuillez choisir une option: \n");
        scanf("%d", &i);

        if (i == 1) {
            printf("déplacement\n");
            return action_deplacer;
        }
        if (i == 2) {
            printf("achat bonus\n");
            return action_acheter_bonus;
        }
        if (i == 3) {
            printf("quitter\n");
            return action_quitter;
        }

    } while (i > 3 || i < 0);

}





// Definir la fonction 'interaction_demander_direction_deplacement' ici

/**
 * @brief Demande une direction de deplacement au joueur.
 * @name interaction_demander_direction_deplacement
 * @return DIRECTION_ERRONEE si la direction choisie est invalide.
 * DIRECTION_DROITE, DIRECTION_BAS, DIRECTION_HAUT ou DIRECTION_GAUCHE selon le choix du joueur, sinon
 */
//  Ecrire le prototype de la fonction 'interaction_demander_direction_deplacement' ici
int interaction_demander_direction_deplacement() {

    int DIRECTION_ERRONEE = -1;
    int DIRECTION_DROITE = 1;
    int DIRECTION_GAUCHE = 2;
    int DIRECTION_HAUT = 3;
    int DIRECTION_BAS = 4;
    int i = 0;


    while (i <= 0 || i > 4) {


        printf("veuillez choisir une direct: \n");
        printf("1. droite\n");
        printf("2. gauche\n");
        printf("3. haut\n");
        printf("4. bas\n");
        scanf("%i", &i);

        if (i == 1) {
            printf("droite\n");
            return DIRECTION_DROITE;
        }
        if (i == 2) {
            printf("gauche\n");
            return DIRECTION_GAUCHE;
        }
        if (i == 3) {
            printf("haut\n");
            return DIRECTION_HAUT;
        }
        if (i == 4) {
            printf("bas\n");
            return DIRECTION_BAS;
        }
    }


}

// Definir la fonction 'interaction_afficher_echec' ici

/**
 * @brief Affiche un message d'echec de la mission.
 * @name interaction_afficher_echec
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_echec' ici
void interaction_affiche_echec() {
    printf("Vous avez perdu\n");
}

// Definir la fonction 'interaction_afficher_victoire' ici

/**
 * @brief Affiche un message de victoire de la mission ainsi que la quantite de
 * carburant restant dans le reservoir du joueur.
 * @name interaction_afficher_victoire
 * @param carburant la quantite de carburant du joueur
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_victoire' ici
void interaction_afficher_victoire(int carburant) {
    printf("vous avez gagné\n");
    printf("il vous reste %i litre de carburant\n", carburant);
}


// Definir la fonction 'interaction_verifier_choix_action' ici


int main() {

    interaction_demander_direction_deplacement();

}