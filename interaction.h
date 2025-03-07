//
// Created by stephane on 09/01/25.
//
#include <stdlib.h>
#include <stdio.h>
#ifndef CODE_INTERACTION_H
#define CODE_INTERACTION_H


typedef enum {
    ACTION_INVALIDE, ACTION_DEPLACER, ACTION_ACHETER_BONUS, ACTION_QUITTER
} t_action;

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

/**
 * @brief Affiche une petite presentation du jeu.
 * @name interaction_presenter_jeu
  */
//  Ecrire le prototype de la fonction 'interaction_presenter_jeu' ici

void interaction_presenter_jeu(){

    printf("Bienvenue dans le jeu\n");
    printf("Dans ce jeu vous serez dans un véhicule contenant 2 litres de carburant initialement\n ");
    printf("vous allez être projeté dans un labyrinth composé de cases et vous aurez pour but de trouver la sortie\n ");
    printf("Votre position sera affiché par un signe X\n");
    printf("Les règles du jeu sont les suivantes: \n ");
    printf("\n");
    printf("-vous avez quatre déplacement disponible ( haut, bas, droite, gauche\n");
    printf("-À chaque déplacement vous perdez un litre de carburant\n");
    printf("-À chaque déplacement vous avez la posibilité de gagner entre 0 à 9 litre de carburant dépendamment de la case que vous tombez\n");
    printf("-Après s'être déplacé d'une case celle-ci est réinitialiser à zéro\n");
    printf("-La partie se termine si une des conditions suivantes est respecté: \n");
    printf("1. Vous avez trouvez la sortie\n");
    printf("2. Vous avez brulé tout votre carburant avant d'atteindre la sortie\n");

}


/**
 * @brief Affiche les options du menu de jeu.
 * Une option non valide sera grisee.
 * @name interaction_afficher_options
 * @param carburant la quantite de carburant du joueur
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_options' ici

void interaction_afficher_option(int carburant){

    carburant = 2;

    printf("Voici vos options: \n");
    printf("1.Déplacer\n");
    printf("2.Acheter bonus\n");
    printf("3.Quitter\n");






}

/**
 * @brief Demande un choix a l'utilisateur sur une des options du menu
 * @name interaction_demander_action
 * @param carburant la quantite de carburant du joueur
 * @return ACTION_DEPLACER, ACTION_ACHETER_BONUS ou ACTION_QUITTER selon l'option choisie par le joueur
 */
//  Ecrire le prototype de la fonction 'interaction_demander_action' ici

int interaction_demander_action(int carburant){

    interaction_afficher_option(carburant);

}

/**
 * @brief Demande une direction de deplacement au joueur.
 * @name interaction_demander_direction_deplacement
 * @return DIRECTION_ERRONEE si la direction choisie est invalide.
 * DIRECTION_DROITE, DIRECTION_BAS, DIRECTION_HAUT ou DIRECTION_GAUCHE selon le choix du joueur, sinon
 */
//  Ecrire le prototype de la fonction 'interaction_demander_direction_deplacement' ici

/**
 * @brief Affiche un message d'echec de la mission.
 * @name interaction_afficher_echec
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_echec' ici

/**
 * @brief Affiche un message de victoire de la mission ainsi que la quantite de
 * carburant restant dans le reservoir du joueur.
 * @name interaction_afficher_victoire
 * @param carburant la quantite de carburant du joueur
 */
//  Ecrire le prototype de la fonction 'interaction_afficher_victoire' ici

/**
 * @brief Verifie que l'action choisie par le joueur est correcte.
 * @name interaction_verifier_choix_action
 * @param action l'action choisie par le joueur
 * @param carburant la quantite de carburant du joueur
 * @return action si elle est correcte, ACTION_INVALIDE sinon
 */
//  Ecrire le prototype de la fonction 'interaction_verifier_choix_action' ici

#endif //CODE_INTERACTION_H
