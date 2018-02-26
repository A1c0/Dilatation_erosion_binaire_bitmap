//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.

#ifndef fonction_DE_RGB_h
#define fonction_DE_RGB_h

#include "tool.h"
#include "fonction_DE_COMMUN.h"

// FONCTION RGB
colorRGB ** calloc_matrice_RGB (colorRGB **tab, int x, int y);

infoRGB ** calloc_matrice_info_RGB (infoRGB** tab, int x, int y);

void get_val_min_max_RGB (colorRGB ** tab, infoRGB** etiquette, int x, int y, int xMin, int xMax, int yMin, int yMax);

void coin_info_dilatation_C4_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void coin_info_dilatation_C8_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void coin_info_erosion_C4_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void coin_info_erosion_C8_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice);

void dilatation_RGB (colorRGB ** tab, infoRGB** etiquette, int longueurMatrice, int hauteurMatrice);

void erosion_RGB (colorRGB ** tab, infoRGB** etiquette, int longueurMatrice, int hauteurMatrice);

#endif