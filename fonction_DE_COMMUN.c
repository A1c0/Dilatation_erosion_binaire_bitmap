//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.

#include "fonction_DE_COMMUN.h"

// FONTION EN COMMUN
void correction_position_max_min (int x, int y , int longueurMatrice, int hauteurMatrice, int* xMin, int* xMax, int* yMin, int* yMax)
{
    if (y == 0)
        *yMin = y;
    else
        *yMin = y - 1;
    if (y == hauteurMatrice - 1)
        *yMax = y;
    else
        *yMax = y + 1;

    if (x == 0)
        *xMin = x;
    else
        *xMin = x - 1;
    if (x == longueurMatrice - 1)
        *xMax = x;
    else
        *xMax = x + 1;
}