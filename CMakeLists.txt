cmake_minimum_required(VERSION 3.30)
project(Fichiers_fournis_TP_1_20250305 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Fichiers_fournis_TP_1_20250305
        couleur.c
        couleur.h
        dijkstra.c
        dijkstra.h
        interaction.c
        interaction.h
        jeu.c
        jeu.h
        main.c
        terrain.c
        terrain.h)
