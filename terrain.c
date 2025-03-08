//
// Created by stephane on 08/01/25.
//



//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************
// Definir la fonction 'terrain_generer_position_sortie' ici

#include "terrain.h"


// Definir la fonction 'terrain_generer_position_depart' ici

// Definir la fonction 'terrain_contient' ici

// Definir la fonction 'terrain_get_carburant' ici

// Definir la fonction 'terrain_set_carburant' ici

// Definir la fonction 'terrain_init' ici

// Definir la fonction 'terrain_creer_stations_carburant' ici

// Definir la fonction 'terrain_afficher' ici

int main(){

    srand((unsigned int) time(NULL));        // ligne qui sert à genéré le chiffre aléatoire
    rand();


    int i = 0;
    int a =  nb_aleatoire(0,9);
    int b =  nb_aleatoire(0,9);
    int c =  nb_aleatoire(0,9);
    int d =  nb_aleatoire(0,9);

    while(a == c ){

         a =  nb_aleatoire(0,9);
         c =  nb_aleatoire(0,9);
    }

        // terrain_generer_position_sortie(a,b);
    terrain_generer_position_depart(a,b,c,d);

}

