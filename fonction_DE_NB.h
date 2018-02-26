//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.

#ifndef fonction_DE_NB_h
#define fonction_DE_NB_h

#include "tool.h"
#include "fonction_DE_COMMUN.h"


// FONCTION NB
colorNB ** calloc_matrice_NB (colorNB **tab, int x, int y);

infoNB ** calloc_matrice_info_NB (infoNB** tab, int x, int y);

void get_val_min_max_NB (colorNB** tab, infoNB** etiquette, int x, int y, int xMin, int xMax, int yMin, int yMax);

void coin_info_dilatation_C4_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void coin_info_dilatation_C8_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void coin_info_erosion_C4_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void coin_info_erosion_C8_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void dilatation_NB (colorNB ** tab, infoNB** etiquette, int longueurMatrice, int hauteurMatrice);

void erosion_NB (colorNB ** tab, infoNB** etiquette, int longueurMatrice, int hauteurMatrice);

#endif