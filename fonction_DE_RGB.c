//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.

#include "fonction_DE_RGB.h"

// **********
// PROTOTYPE*
// **********

colorRGB ** calloc_matrice_RGB (colorRGB **tab, int x, int y)
{
    int i;
    tab = (colorRGB**) calloc((size_t) y, sizeof(colorRGB*));
    for(i = 0; i < y; i++)
    {
        tab[i] = (colorRGB*) calloc((size_t) x, sizeof(colorRGB));
    }
    return tab;
}

infoRGB ** calloc_matrice_info_RGB (infoRGB** tab, int x, int y)
{
    int i;
    tab = (infoRGB**) calloc((size_t) y, sizeof(infoRGB*));
    for(i=0;i<y;i++)
    {
        tab[i] = (infoRGB*) calloc((size_t) x, sizeof(infoRGB));
    }
    return tab;
}

void get_val_min_max_RGB (colorRGB ** tab, infoRGB** etiquette, int x, int y, int xMin, int xMax, int yMin, int yMax)
{
    etiquette[y][x].valeurMax = tab[y][x];
    etiquette[y][x].valeurMin = tab[y][x];
    int i,j;
    for (j = yMin; j <= yMax; j++)
    {
        for (i = xMin; i <= xMax; i++)
        {
            if ( tab[j][i].blue < etiquette[y][x].valeurMin.blue)
            {
                etiquette[y][x].valeurMin.blue = tab[j][i].blue;
            }
            if ( tab[j][i].green < etiquette[y][x].valeurMin.green)
            {
                etiquette[y][x].valeurMin.green = tab[j][i].green;
            }
            if ( tab[j][i].red < etiquette[y][x].valeurMin.red)
            {
                etiquette[y][x].valeurMin.red = tab[j][i].red;
            }
            if ( tab[j][i].blue > etiquette[y][x].valeurMax.blue)
            {
                etiquette[y][x].valeurMax.blue = tab[j][i].blue;
            }
            if ( tab[j][i].green > etiquette[y][x].valeurMax.green)
            {
                etiquette[y][x].valeurMax.green = tab[j][i].green;
            }
            if ( tab[j][i].red > etiquette[y][x].valeurMax.red)
            {
                etiquette[y][x].valeurMax.red = tab[j][i].red;
            }
        }
    }
}

void coin_info_dilatation_C4_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
{
    int yMax,yMin,xMax,xMin;
    correction_position_max_min(x, y, longueurMatrice, hauteurMatrice, &xMin, &xMax, &yMin, &yMax);


    if (tab[yMax][x].blue == tab[y][x].blue && tab[yMin][x].blue == tab[y][x].blue && tab[y][xMax].blue == tab[y][x].blue && tab[y][xMin].blue == tab[y][x].blue && tab[yMax][x].green == tab[y][x].green && tab[yMin][x].green == tab[y][x].green && tab[y][xMax].green == tab[y][x].green && tab[y][xMin].green == tab[y][x].green &&tab[yMax][x].red == tab[y][x].red && tab[yMin][x].red == tab[y][x].red && tab[y][xMax].red == tab[y][x].red && tab[y][xMin].red == tab[y][x].red)
    {
        etiquette[y][x].infoCase = pastoucher;
    }
    
    {
        if (tab[yMax][x].blue > tab[y][x].blue || tab[yMin][x].blue > tab[y][x].blue || tab[y][xMax].blue > tab[y][x].blue || tab[y][xMin].blue > tab[y][x].blue || tab[yMax][x].green > tab[y][x].green || tab[yMin][x].green > tab[y][x].green || tab[y][xMax].green > tab[y][x].green || tab[y][xMin].green > tab[y][x].green || tab[yMax][x].red > tab[y][x].red || tab[yMin][x].red > tab[y][x].red || tab[y][xMax].red > tab[y][x].red || tab[y][xMin].red > tab[y][x].red)
        {
            etiquette[y][x].infoCase = modifie;
        }
        else
        {
            etiquette[y][x].infoCase = pastoucher;
        }
    }

    get_val_min_max_RGB(tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void coin_info_dilatation_C8_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
{
    int yMax,yMin,xMax,xMin;
    correction_position_max_min(x, y, longueurMatrice, hauteurMatrice, &xMin, &xMax, &yMin, &yMax);

    int milieu = 0;
    int cote = 0;
    int i,j;
    for (j = yMin; j <= yMax; j++)
    {
        for (i = xMin; i <= xMax; i++)
        {
            if (tab[j][i].blue == tab[y][x].blue && tab[j][i].green == tab[y][x].green && tab[j][i].red == tab[y][x].red)
            {
                milieu++;
            }
            else
            {
                if (tab[j][i].blue > tab[y][x].blue || tab[j][i].green > tab[y][x].green || tab[j][i].red > tab[y][x].red)
                {
                    cote = 1;
                }
            }
        }
    }
    if (milieu == 9)
    {
        etiquette[y][x].infoCase = pastoucher;
    }
    else
    {
        if (cote)
        {
            etiquette[y][x].infoCase = modifie;
        }
        else
        {
            etiquette[y][x].infoCase = pastoucher;
        }
    }

    get_val_min_max_RGB(tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void coin_info_erosion_C4_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
{
    int yMax,yMin,xMax,xMin;
    correction_position_max_min(x, y, longueurMatrice, hauteurMatrice, &xMin, &xMax, &yMin, &yMax);


    if (tab[yMax][x].blue == tab[y][x].blue && tab[yMin][x].blue == tab[y][x].blue && tab[y][xMax].blue == tab[y][x].blue && tab[y][xMin].blue == tab[y][x].blue && tab[yMax][x].green == tab[y][x].green && tab[yMin][x].green == tab[y][x].green && tab[y][xMax].green == tab[y][x].green && tab[y][xMin].green == tab[y][x].green &&tab[yMax][x].red == tab[y][x].red && tab[yMin][x].red == tab[y][x].red && tab[y][xMax].red == tab[y][x].red && tab[y][xMin].red == tab[y][x].red)
    {
        etiquette[y][x].infoCase = pastoucher;
    }
    else
    {
        if (tab[yMax][x].blue < tab[y][x].blue || tab[yMin][x].blue < tab[y][x].blue || tab[y][xMax].blue < tab[y][x].blue || tab[y][xMin].blue < tab[y][x].blue || tab[yMax][x].green < tab[y][x].green || tab[yMin][x].green < tab[y][x].green || tab[y][xMax].green < tab[y][x].green || tab[y][xMin].green < tab[y][x].green || tab[yMax][x].red < tab[y][x].red || tab[yMin][x].red < tab[y][x].red || tab[y][xMax].red < tab[y][x].red || tab[y][xMin].red < tab[y][x].red)
                etiquette[y][x].infoCase = modifie;
        else
            etiquette[y][x].infoCase = pastoucher;
    }

    get_val_min_max_RGB(tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void coin_info_erosion_C8_RGB (colorRGB ** tab,  infoRGB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
{
    int yMax,yMin,xMax,xMin;
    correction_position_max_min(x, y, longueurMatrice, hauteurMatrice, &xMin, &xMax, &yMin, &yMax);

    int milieu = 0;
    int cote = 0;
    int i,j;
    for (j = yMin; j <= yMax; j++)
    {
        for (i = xMin; i <= xMax; i++)
        {
            if (tab[j][i].blue == tab[y][x].blue && tab[j][i].green == tab[y][x].green && tab[j][i].red == tab[y][x].red)
            {
                milieu++;
            }
            else
            {
                if (tab[j][i].blue < tab[y][x].blue || tab[j][i].green < tab[y][x].green || tab[j][i].red < tab[y][x].red)
                {
                    cote = 1;
                }
            }
        }
    }
    int compteur = 0;
    if (milieu == 9)
    {
        etiquette[y][x].infoCase = pastoucher;
    }
    else
    {
        if (cote)
        {
            etiquette[y][x].infoCase = modifie;
        }
        else
        {
            etiquette[y][x].infoCase = pastoucher;
        }
    }
;

    get_val_min_max_RGB(tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void dilatation_RGB (colorRGB ** tab, infoRGB** etiquette, int longueurMatrice, int hauteurMatrice)
{
    int i, j;
    for(j = 0; j < hauteurMatrice; j++)
    {
        for(i = 0; i < longueurMatrice; i++)
        {
            if (etiquette[j][i].infoCase == modifie)
            {
                tab[j][i].blue = etiquette[j][i].valeurMax.blue;
                tab[j][i].green = etiquette[j][i].valeurMax.green;
                tab[j][i].red = etiquette[j][i].valeurMax.red;
            }
        }
    }
}

void erosion_RGB (colorRGB ** tab, infoRGB** etiquette, int longueurMatrice, int hauteurMatrice)
{
    int i, j;
    for(j = 0; j < hauteurMatrice; j++)
    {
        for(i = 0; i < longueurMatrice; i++)
        {
            if (etiquette[j][i].infoCase == modifie)
            {
                tab[j][i].blue = etiquette[j][i].valeurMin.blue;
                tab[j][i].green = etiquette[j][i].valeurMin.green;
                tab[j][i].red = etiquette[j][i].valeurMin.red;
            }
        }
    }
}