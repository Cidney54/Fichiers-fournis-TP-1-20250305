//
// Created by stephane on 08/01/25.
//

#ifndef CODE_DIJKSTRA_H
#define CODE_DIJKSTRA_H

#define NB_CASES_BONUS 4

//  ************************************
//  Declarations des fonctions publiques
//  ************************************
/**
 * @brief Achete un bonus au prix de 10L de carburant et affiche les 4 premieres
 * directions du chemin qui utilise le moins de carburant.
 * @name dijkstra_acheter_bonus
 * @param terrain le terrain sur lequel proposer un debut de chemin optimal
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param joueur_carburant l'adresse de la quantite de carburant du joueur
 * @param destination_ligne la ligne de la destination a atteindre
 * @param destination_colonne la colonne de la destination a atteindre
 * @note Le debut de chemin propose ne garantit pas que le joueur pourra l'emprunter.
 * Cela depend de la quantite de carburant qu'il lui reste.
 */
//  Ecrire le prototype de la fonction 'dijkstra_acheter_bonus' ici
void dijkstra_acheter_bonus(const int terrain[NB_LIGNES][NB_COLONNES], int joueur_ligne, int joueur_colonne, int *joueur_carburant, int destination_ligne, int destination_colonne); // (*joeur_carburant peut etre modifier)
#endif //CODE_DIJKSTRA_H
