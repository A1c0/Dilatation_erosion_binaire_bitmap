//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.

#include "fonction_DE_NB.h"

// **********
// PROTOTYPE*
// **********

colorNB ** calloc_matrice_NB (colorNB **tab, int x, int y)
{
    int i;
    tab = (colorNB**) calloc((size_t) y, sizeof(colorNB*));
    for(i = 0; i < y; i++)
    {
        tab[i] = (colorNB*) calloc((size_t) x, sizeof(colorNB));
    }
    return tab;
}

infoNB ** calloc_matrice_info_NB (infoNB** tab, int x, int y)
{
    int i;
    tab = (infoNB**) calloc((size_t) y, sizeof(infoNB*));
    for(i = 0; i < y; i++)
    {
        tab[i] = (infoNB*) calloc((size_t) x, sizeof(infoNB));
    }
    return tab;
}

void get_val_min_max_NB (colorNB** tab, infoNB** etiquette, int x, int y, int xMin, int xMax, int yMin, int yMax)
{
    etiquette[y][x].valeurMax = tab[y][x];
    etiquette[y][x].valeurMin = tab[y][x];
    int i,j;
    for (j = yMin; j <= yMax; j++)
    {
        for (i = xMin; i <= xMax; i++)
        {
            if ( tab[j][i] < etiquette[y][x].valeurMin)
            {
                etiquette[y][x].valeurMin = tab[j][i];
            }
            if ( tab[j][i] > etiquette[y][x].valeurMax)
            {
                etiquette[y][x].valeurMax = tab[j][i];
            }
        }
    }
}

void coin_info_dilatation_C4_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
{
    int yMax,yMin,xMax,xMin;
    correction_position_max_min(x, y, longueurMatrice, hauteurMatrice, &xMin, &xMax, &yMin, &yMax);


    if (tab[yMax][x] == tab[y][x] && tab[yMin][x] == tab[y][x] && tab[y][xMax] == tab[y][x] && tab[y][xMin] == tab[y][x])
    {
        etiquette[y][x].infoCase = pastoucher;
    }
    
    {
        if (tab[yMax][x] > tab[y][x] || tab[yMin][x] > tab[y][x] || tab[y][xMax] > tab[y][x] || tab[y][xMin] > tab[y][x])
        {
            etiquette[y][x].infoCase = modifie;
        }
        else
        {
            etiquette[y][x].infoCase = pastoucher;
        }
    }
    get_val_min_max_NB (tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void coin_info_dilatation_C8_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
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
            if (tab[j][i] == tab[y][x])
            {
                milieu++;
            }
            else
            {
                if (tab[j][i] > tab[y][x])
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

    get_val_min_max_NB (tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void coin_info_erosion_C4_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
{
    int yMax,yMin,xMax,xMin;
    correction_position_max_min(x, y, longueurMatrice, hauteurMatrice, &xMin, &xMax, &yMin, &yMax);


    if (tab[yMax][x] == tab[y][x] && tab[yMin][x] == tab[y][x] && tab[y][xMax] == tab[y][x] && tab[y][xMin] == tab[y][x])
    {
        etiquette[y][x].infoCase = pastoucher;
    }
    else
    {
        if (tab[yMax][x] < tab[y][x] || tab[yMin][x] < tab[y][x] || tab[y][xMax] < tab[y][x] || tab[y][xMin] < tab[y][x])
        {
            etiquette[y][x].infoCase = modifie;
        }
        else
        {
            etiquette[y][x].infoCase = pastoucher;
        }
    }

    get_val_min_max_NB (tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void coin_info_erosion_C8_NB (colorNB ** tab,  infoNB** etiquette, int x, int y, int longueurMatrice, int hauteurMatrice)
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
            if (tab[j][i] == tab[y][x])
            {
                milieu++;
            }
            else
            {
                if (tab[j][i] < tab[y][x])
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

    get_val_min_max_NB (tab, etiquette, x, y, xMin, xMax, yMin, yMax);
}

void dilatation_NB (colorNB ** tab, infoNB** etiquette, int longueurMatrice, int hauteurMatrice)
{
    int i, j;
    for(j = 0; j < hauteurMatrice; j++)
    {
        for(i = 0; i < longueurMatrice; i++)
        {
            tab[j][i] = etiquette[j][i].valeurMax;
        }
    }
}

void erosion_NB (colorNB ** tab, infoNB** etiquette, int longueurMatrice, int hauteurMatrice)
{
    int i, j;
    for(j = 0; j < hauteurMatrice; j++)
    {
        for(i = 0; i < longueurMatrice; i++)
        {
            tab[j][i] = etiquette[j][i].valeurMin;
        }
    }
}


