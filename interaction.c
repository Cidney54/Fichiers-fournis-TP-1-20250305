//
// Created by stephane on 09/01/25.
//

#include <stdlib.h>
#include <stdio.h>
#include <couleur.h>
#include <jeu.h>
#include "interaction.h"


#define NB_LIGNES 10
#define NB_COLONNES 10
//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'interaction_presenter_jeu' ici

void interaction_presenter_jeu() {

    printf("Bienvenue dans le jeu\n");
    printf("Dans ce jeu vous serez dans un vehicule contenant 2 litres de carburant initialement\n ");
    printf("vous allez etre projete dans un labyrinth compose de cases et vous aurez pour but de trouver la sortie\n ");
    printf("Votre position sera affiche par un signe X\n");
    printf("Les regles du jeu sont les suivantes: \n ");
    printf("\n");
    printf("-vous avez quatre deplacement disponible ( haut, bas, droite, gauche\n");
    printf("-À chaque deplacement vous perdez un litre de carburant\n");
    printf("-À chaque deplacement vous avez la posibilite de gagner entre 0 à 9 litre de carburant\n");
    printf("-Après s'etre deplace d'une case celle-ci est reinitialiser à zero\n");
    printf("-La partie se termine si une des conditions suivantes est respecte: \n");
    printf("1. Vous avez trouvez la sortie\n");
    printf("2. Vous avez brule tout votre carburant avant d'atteindre la sortie\n");


}

// Definir la fonction 'interaction_afficher_options' ici

void interaction_afficher_option(int carburant) {

    /* affichage des options  */
    printf("Voici vos options: \n");
    printf("1.Deplacer\n");
    /* affiche l'option acheter bonus en gris si le carburant est inférieur à 10 */
    if (carburant < 10) {
        couleur_set(0, 90, 40);
        printf("2.Acheter bonus\n");
    }
    /* affiche l'option acheter bonus normalement si le carburant est supérieur  ou égal à 10 */
    if (carburant >= 10) {
        printf("2.Acheter bonus\n");
    }
    couleur_reset();
    printf("3.Quitter\n");


}


// Definir la fonction 'interaction_demander_action' ici
int interaction_demander_action(int carburant) {
    int i;
    int action = 0;

    do {
        // demande à l'utilisateur l'option qu'il choisit
        interaction_afficher_option(carburant);
        printf("Veuillez choisir une option: \n");
        scanf("%d", &i);

        // s'il choisit 1, cela affiche déplacement
        if (i == 1) {
            action = ACTION_DEPLACER;
            printf("deplacement\n");

        }
            // s'il choisit 2, cela affiche achat bonus
        else if (i == 2) {
            action = ACTION_ACHETER_BONUS;
            printf("achat bonus\n");

        }
            // s'il choisit 3, cela affiche quitter
        else if (i == 3) {
            action = ACTION_QUITTER;
            printf("quitter\n");

        }
            // s'il choisit tout autre valeur, cela affiche invalide
        else {
            action = ACTION_INVALIDE;
            printf("Invalide");
        }

    } while (i > 3 || i < 0);

    return action;

}

// Definir la fonction 'interaction_demander_direction_deplacement' ici
int interaction_demander_direction_deplacement() {
    // sert d'outil de comparaison
    int i;
    // initialisation de la valeur retourné
    int direction = 5;

    //affiche les options de déplacement
    printf("veuillez choisir une direct: \n");
    printf("1. droite\n");
    printf("2. gauche\n");
    printf("3. haut\n");
    printf("4. bas\n");
    scanf("%i", &i);

    //retourne droite si l'utilisateur choisi 1
    if (i == 1) {

        direction = DIRECTION_DROITE;
    }
        //retourne gauche si l'utilisateur choisi 2
    else if (i == 2) {

        direction = DIRECTION_GAUCHE;
    }
        //retourne haut si l'utilisateur choisi 3
    else if (i == 3) {

        direction = DIRECTION_HAUT;
    }
        //retourne bbas si l'utilisateur choisi 4
    else if (i == 4) {

        direction = DIRECTION_BAS;
    }
        //retourne errone si l'utilisateur choisi une valeur autre que 1 à 4
    else {

        direction = DIRECTION_ERRONEE;
    }

    return direction;
}


// Definir la fonction 'interaction_afficher_echec' ici
void interaction_affiche_echec() {
    //affiche que le joueur a perdu
    printf("Vous avez perdu\n");
}

// Definir la fonction 'interaction_afficher_victoire' ici

void interaction_afficher_victoire(int carburant) {
    //affiche que le joueur a gagné suivi de son niveau de carburant
    printf("vous avez gagne\n");
    printf("il vous reste %i litre de carburant\n", carburant);
}


// Definir la fonction 'interaction_verifier_choix_action' ici

/**
 * @brief Verifie que l'action choisie par le joueur est correcte.
i * @name interaction_verifier_choix_actionnt main() {
 * @param action l'action choisie par le joueur
 * @param carburant la quantite de carburant du joueur
 * @return action si elle est correcte, ACTION_INVALIDE sinon
} */

int interaction_verifier_choix_action(int action, int carburant) {
    //initialise le choix d'action
    int choix_action = 0;
    //demande à l'utilisateur son choix
    scanf("%i", &action);


    if (action == ACTION_DEPLACER) {
        printf("deplacement\n");
        choix_action = ACTION_DEPLACER;
    } else if (action == ACTION_ACHETER_BONUS) {
        printf("achat bonus\n");
        choix_action = ACTION_ACHETER_BONUS;
    } else if (action == ACTION_QUITTER) {
        printf("quitte\n");
        choix_action = ACTION_QUITTER;
    } else {
        printf("errone\n");
        choix_action = ACTION_INVALIDE;
    }

    return choix_action;
}



