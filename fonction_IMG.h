//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.

#ifndef fonction_IMG_h
#define fonction_IMG_h

#include "tool.h"

// FONCTION DE BASE POUR L'IMAGE
void afficher_headers(info_header headerBMP, file_header header);

colorRGB ** intialisation_matrice_RGB(info_header headerBMP);

void remplissage_matrice_RGB(colorRGB **matrice, info_header headerBMP, FILE* file_in);

void sauvegarde_matrice_RGB(colorRGB **matrice, info_header headerBMP, FILE* file_out);

colorNB ** intialisation_matrice_NB(info_header headerBMP);

void remplissage_matrice_NB(colorNB **matrice, info_header headerBMP, FILE* file_in);

void sauvegarde_matrice_NB(colorNB **matrice, info_header headerBMP, FILE* file_out);

palette ** lire_palette (palette **tab, FILE *file_in, int nbColor);

void ecrire_palette (palette **tab, FILE *file_out,int  nbColor);

#endif