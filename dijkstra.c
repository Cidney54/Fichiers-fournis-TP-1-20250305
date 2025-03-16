//
// Created by stephane on 08/01/25.
//
#include "dijkstra.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include "terrain.h"
#include "jeu.h"

//  ****************************
//  Definitions des types prives
//  ****************************
//  Type pour le tableau des couts qui donne le cout en carburant du plus court chemin du depart a l'une des cases du terrain
typedef int t_couts[NB_LIGNES][NB_COLONNES];

// Type pour le tableau 2D permettant de savoir si une case a deja ete visitee lors de l'algorithme de Dijkstra
typedef bool t_visites[NB_LIGNES][NB_COLONNES];

// Type pour coder la direction d'ou on vient pour atteindre l'une des cases du terrain en suivant le plus court chemin
typedef t_direction t_precedents[NB_LIGNES][NB_COLONNES];

//  **********************************
//  Declarations des fonctions privees
//  **********************************

/**
 * @brief Initialise tous les couts avec le plus grand entier du type int.
 * Initialise egalement le cout de la case du joueur a 0.
 * @name initialiser_couts
 * @param couts le tableau bi-dimensionnel des couts a initialiser
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
*/

//  Ecrire le prototype de la fonction 'initialiser_couts' ici

void initialiser_couts(t_couts couts,int joueur_ligne, int joueur_colonne);
/**
 * @brief Initialise toutes les cases a non visitee.
 * @name initialiser_visitees
 * @param visitees le tableau bi-dimensionnel qui indique, pour chaque case, si elle a deja ete visitee ou non.
 */
//  Ecrire le prototype de la fonction 'initialiser_visitees' ici
//void initialiser_visitees(visitees, case_ligne, case_colonne);
void initialiser_visitees(t_visites visitees,int case_ligne,int case_colonne);
/**
 * @brief Indique si une case donnee a deja ete visitee au cours de l'algorithme.
 * @name est_case_visitee
 * @param visitees le tableau a 2 dimensions qui indique, pour chaque case, si elle a deja ete visitee durant l'algorithme
 * @param case_ligne la ligne de la case a tester
 * @param case_colonne la colonne de la case a tester
 * @return true si la case a deja ete visitee, false sinon
 */
//  Ecrire le prototype de la fonction 'est_case_visitee' ici
void est_case_visitee(t_visites visitees,int case_ligne,int case_colonne);

/**
 * @brief Recherche la case non visitee qui possede le plus petit cout.
 * @name choisir_min_dist_non_visitee
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique si une case a deja ete visitee ou pas
 * @param case_choisie_ligne l'adresse ou deposer la ligne de la case choisie
 * @param case_choisie_colonne l'adresse ou deposer la colonne de la case choisie
 */
//  Ecrire le prototype de la fonction 'choisir_min_dist_non_visitee' ici
void choisir_min_dist_non_visitee(t_couts couts, t_visites visitees,int *case_choisie_ligne,int *case_choisie_colonne);
/**
 * @brief Retourne le cout de deplacement pour aller d'une case a une case voisine.
 * @name cout_deplacement
 * @param couts le tableau a 2 dimensions des couts
 * @param voisin_ligne la ligne de la case voisine vers laquelle on veut aller
 * @param voisin_colonne la colonne de la case voisine vers laquelle on veut aller
 * @return le cout du chemin pour se rendre a la case voisine specifiee en parametre
 * @note le cout pour aller d'une case a l'une de ses voisines est 1 + (9 - carburant dans la case voisine)
 */
//  Ecrire le prototype de la fonction 'cout_deplacement' ici

void cout_deplacement(t_couts couts, int voisin_ligne, int voisin_colonne);
/**
 * @brief Parcourt les voisins d'une case donnee et met a jour leur cout dans le tableau des couts.
 * @name maj_voisins
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique, pour toute case, si elle a deja ete visitee
 * @param terrain le terrain qui contient les stations de carburant
 * @param precedents le tableau des precedents qui est mis a jour si l'un des chemins ameliore un chemin deja trouve auparavant
 * @param courante_ligne la ligne de la position courante a partir de laquelle on regarde les voisins
 * @param courante_colonne la colonne de la position courante a partir de laquelle on regarde les voisins
 */
//  Ecrire le prototype de la fonction 'maj_voisins' ici
void maj_voisins(t_couts couts,t_visites visitees,int terrain[NB_LIGNES][NB_COLONNES],t_precedents precedents,int courante_ligne,int courante_colonne); // jsp terrain terrain.c ou pas et tableau precedents????
/**
 * @brief Affiche le tableau des couts
 * @name afficher_couts
 * @param couts le tableau des couts
 * @param visitees le tableau qui indique si une case a deja ete visitee ou pas durant l'algorithme
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param destination_ligne la ligne de la position a atteindre
 * @param destination_colonne la colonne de la position a atteindre
 */
//  Ecrire le prototype de la fonction 'afficher_couts' ici
void afficher_couts(t_couts couts,t_visites visitees, int joueur_ligne, int joeur_colonne, int destination_ligne, int destination_colonne);
/**
 * @brief Calcule les 4 premieres cases du plus court chemin en terme de carburant
 * @name calculer_chemin_bonus
 * @param precedents tableau de directions qui indique de quelle direction on vient pour atteindre une case du terrain en suivant le plus court chemin
 * @param depart_ligne la ligne de la case de depart
 * @param depart_colonne la colonne de la case de depart
 * @param destination_ligne la ligne de la case a atteindre
 * @param destination_colonne la colonne de la case a atteindre
 * @param directions les 4 premieres directions (au plus) a suivre sur le plus court chemin du depart a l'arrivee
 * @return le nombre de directions proposees par l'algorithme (normalement 4, mais peut etre plus petit)
 */
//  Ecrire le prototype de la fonction 'calculer_chemin_bonus' ici
void calculer_chemin_bonus(t_precedents precedents,int depart_ligne, int depart_colonne, int destination_ligne, int destination_colonne, int directions[]);
/**
 * @brief Algorithme de Dijkstra pour calculer le plus court chemin en partent de la position du joueur pour atteindre
 * la position de destination.
 * @name dijkstra
 * @param terrain la terrain sur lequel le joueur evolue
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param destination_ligne la ligne de la case a atteindre
 * @param destination_colonne la colonne de la case a atteindre
 * @param directions les 4 premieres directions a suivre sur le plus court chemin
 * @return
 */
//  Ecrire le prototype de la fonction 'dijkstra' ici
void dijkstra(int terrain [NB_LIGNES][NB_COLONNES] , int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne, int directions[]);
/**
 * @brief Affiche les 4 premieres directions a suivre sur le plus court chemin pour joindre la destination a partir de la position du joueur
 * @name afficher_direction_suggeree
 * @param dircetions les premieres directions a suivre sur le plus court chemin
 * @param nb le nombre de directions a suivre
 */
//  Ecrire le prototype de la fonction 'afficher_direction_suggeree' ici



void afficher_direction_suggeree(directions[], int nb);
//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************
// Definir la fonction 'dijkstra_acheter_bonus' ici
void dijkstra_acheter_bonus(int carburant) {        //carb #include jeu.h? carb->tot joueur ????
    if (carburant >= 10) {
        carburant = carburant - 10;                            //carburant erreur??
        printf("%d", afficher_direction_suggeree(directions[], nb));    //%?? // parametre??
        //carb-10
        //printf fct afficher d sugg 
    }
    else {
        printf("Vous n'avez pas assez de carburant pour acheter un bonus...");
    }

  }

//  *********************************
//  Definitions des fonctions privees
//  *********************************
// Definir la fonction 'initialiser_couts' ici
void initialiser_couts(t_couts couts,int joueur_ligne, int joueur_colonne) {

    /* Boucle pour arcourir les lignes du tableau « couts ». */
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (i == joueur_ligne && j == joueur_colonne) {

                couts[i][j] = 0;
            }
            else {
                couts[i][j] = INT_MAX; // Pour representer le cout infini.
            }
        }
    }
}

// Definir la fonction 'initialiser_visitees' ici
void initialiser_visitees (t_visites visitees, int case_ligne, int case_colonne){
  //Initialise toutes les cases comme non visitees
  for (int i=0; i< NB_LIGNES; i++) {
      for (int j= 0; j < NB_COLONNES; j++) {
          visitees[i][j]=false;
    }
  }
}
//parametres case ligne colonne???***************

// Definir la fonction 'est_case_visitee' ici
void est_case_visitee(t_visites visitees,int case_ligne,int case_colonne){
    visitees[case_ligne][case_colonne] = 1; // Marque la case comme visite
}


// Definir la fonction 'choisir_min_dist_non_visitee' ici
void choisir_min_dist_non_visitee(t_couts couts,t_visites visitees, int *case_choisie_ligne, int*case_choisie_colonne){
    int min_cout = INT_MAX;
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (!visitees[i][j] && couts[i][j] < min_cout) {
                min_cout = couts[i][j]; // On met a jour le min_cout si on trouve un cout plus bas
                *case_choisie_ligne = i;
                *case_choisie_colonne = j;
            }
        }
    }
}

// Definir la fonction 'cout_deplacement' ici
void cout_deplacement(int terrain[NB_LIGNES][NB_COLONNES], t_couts couts, int voisin_ligne, int voisin_colonne) {
    int carburant = terrain_get_carburant(terrain, voisin_ligne, voisin_colonne);
    int cout_voisin = 1 + (9 - carburant);
}
// Definir la fonction 'maj_voisins' ici
void maj_voisins(t_couts couts,t_visites visitees,int terrain[NB_LIGNES][NB_COLONNES],t_precedents precedents,int courante_ligne,int courante_colonne) {
    // Iteration des voisins possibles(HAUT, BAS, GAUCHE, DROITE)
    //int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // (directions_lignes, directions_colonnes) voisins
    //Parcours les 4 directions possibles
    //for (int i = 0; i < 4; i++) {
    //int voisin_ligne = courante_ligne + directions[i][0];
    //int voisin_colonne = courante_colonne + directions[i][1];

    int voisin_ligne;
    int voisin_colonne;

    for (int i = 0; i < 4;i++) {

        if (i == 0) {

            voisin_ligne = courante_ligne - 1;
            voisin_colonne = courante_colonne;
        }
        else if (i == 1) {

            voisin_ligne = courante_ligne + 1;
            voisin_colonne = courante_colonne;
        }
        else if (i == 2) {
            
            voisin_ligne = courante_ligne;
            voisin_colonne = courante_colonne - 1;
        }
        else if (i == 3) {

            voisin_ligne = courante_ligne;
            voisin_colonne = courante_colonne + 1;
        }
        // Verifie que les voisins sont dans dans la zone permise
        if (voisin_ligne >= 0 && voisin_ligne < NB_LIGNES && voisin_colonne >= 0 && voisin_colonne < NB_COLONNES) {
            // Verifie que les voisins n'ont pas ete visites
            if (visitees[voisin_ligne][voisin_colonne] == 0) {
                // calcule le cout pour aller au voisin (depend du terrain)
                int nouveau_cout = couts[courante_ligne][courante_colonne] + terrain[voisin_ligne][voisin_colonne];

                // mis a jour du nouveau prix
                if (nouveau_cout < couts[voisin_ligne][voisin_colonne]) {
                    couts[voisin_ligne][voisin_colonne] = nouveau_cout; // mise a jour du prix
                 
                }
            }
        }
    }
}
// Definir la fonction 'afficher_couts' ici

void afficher_couts(t_couts couts,t_visites visitees, int joueur_ligne, int joueur_colonne, int destination_ligne, int destination_colonne) {
  for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
          if (i == joueur_ligne && j == joueur_colonne) {
            printf("j");
          }
          else if (i == destination_ligne && j == destination_colonne) {
            printf("d");
          }
          else if (visitees[i][j]) {        //si la case est visitee, afficher le cout
            printf("%d", couts[i][j]);       //pointeur??
          }
          // else {
          //   printf("%d", couts[i][j]);
          // }

          printf("\n");
}


// Definir la fonction 'calculer_chemin_bonus' ici
      void calculer_chemin_bonus(t_precedents precedents,int depart_ligne, int depart_colonne, int destination_ligne, int destination_colonne, int directions[]) {
          

// Definir la fonction 'dijkstra' ici

// Definir la fonction 'afficher_direction_suggeree' ici // Boucle qui parcourt le tableau directions [], qui contient (HAUT,BAS,GAUCHE,DROITE)
void afficher_direction_suggeree(directions[], int nb) {
            printf("Directions suggérées: ");
            for (int i = 0; i < nb; i++) {
                if (directions[i] == HAUT) {
                    printf("Haut ");
                } else if (directions[i] == BAS) {
                    printf("Bas ");
                } else if (directions[i] == GAUCHE) {
                    printf("Gauche ");
                } else if (directions[i] == DROITE) {
                    printf("Droite ");
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}
void afficher_direction_suggeree(t_direction directions, int nb) {
      //loop de 4?
      //fct cout deplacement?
    //fct jeu.h??
            printf("Directions suggérées: ");
      for (int i = 0; i < NB_LIGNES; i++) {
          for (int j = 0; j < NB_COLONNES; j++)
            // for (int i = 0; i < 4; i++) {
                if (t_direction[i] == 2) {                //t_direction???
                    printf("Haut ");
                } else if (t_direction == 1) {
                    printf("Bas ");
                } else if (t_direction[i] == 3) {
                    printf("Gauche ");
                } else if (t_direction[i] == 0) {
                    printf("Droite ");
                }
            }

            else {
                printf("direction erronée"); //??
            }
            printf("\n");
        }

