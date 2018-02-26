//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.
#include "fonction_IMG.h"

void afficher_headers(info_header headerBMP, file_header header)
{
    printf("\n=========================================");
    printf("\n|         AFFICHAGE DES ENTETES         |");
    printf("\n=========================================\n\n");
    printf("\t - ENTETE DU FICHIER - \n");
    printf("Signature du fichier : %c%c\n", header.signature[0], header.signature[1]);
    printf("Taille du fichier : %d\n", header.size);
    printf("Champ reserve : %d\n", header.reserved);
    printf("Offset de l'image: %d\n\n", header.offset);

    printf("\n\t - ENTETE DU BITMAP - \n");
    printf("Taille de l'entete de l'image : %d\n",  headerBMP.entete_size);
    printf("Largeur de l'image : %d\n",  headerBMP.width);
    printf("Hauteur de l'image : %d\n",  headerBMP.height);
    printf("Nombre de plans : %hu\n",  headerBMP.plans);
    printf("Profondeur de codage : %hu\n",  headerBMP.depth);
    printf("Methode de compression : %d\n",  headerBMP.compr);
    printf("Taille de l'image : %d\n",  headerBMP.sizeTotal);
    printf("Resolution horizontale : %d\n",  headerBMP.hRes);
    printf("Resolution verticale : %d\n",  headerBMP.vRes);
    printf("Nombre de couleur : %d\n",  headerBMP.nbColor);
    printf("Nombre de couleur importante : %d\n\n",  headerBMP.nbColorImp);

    printf("Size of header: %d\n", sizeof(header));
    printf("Size of HI: %d\n", sizeof(headerBMP));
    printf("Size of RGB: %d\n\n\n", sizeof(colorRGB));
    system("pause");
}


colorRGB ** intialisation_matrice_RGB(info_header headerBMP)
{
	int i;
    colorRGB ** matrice = NULL;
	int matrixWidth = headerBMP.width;
	int matrixHeight = headerBMP.height;
	matrice = (colorRGB**) malloc(matrixWidth* sizeof(colorRGB*));
	for(i=0; i<matrixHeight; i++)
	{
	    matrice[i] = (colorRGB*) malloc(matrixHeight* sizeof(colorRGB));
	}
    return matrice;
}

void remplissage_matrice_RGB(colorRGB **matrice, info_header headerBMP, FILE* file_in)
{
    int i;
    int j;
	int matrixWidth = headerBMP.width;
	int matrixHeight = headerBMP.height;
	char pourcentageCaractere ='%';
    int pourcentageAvancement = 100;

    printf("Remplissage de la matrice initiale:\n");
    for (j = matrixHeight - 1; j >= 0; j--)
    {
    	for (i = 0; i < matrixWidth; i++)
    	{
            fread(&matrice[j][i], sizeof(matrice[j][i]), DIM, file_in);
    	}
    	if (j*100/(matrixHeight - 1) < pourcentageAvancement)
    	{
    		pourcentageAvancement--;
    		printf("\r%d %c", 100 - pourcentageAvancement, pourcentageCaractere);
    	}
    }
    printf("\nDONE\n");
}


void sauvegarde_matrice_RGB(colorRGB **matrice, info_header headerBMP, FILE* file_out)
{
	int i;
    int j;
	int matrixWidth = headerBMP.width;
	int matrixHeight = headerBMP.height;
	char pourcentageCaractere ='%';
    int pourcentageAvancement = 100;

	printf("Sauvegarde de la matrice\n");
	for (j = matrixHeight - 1; j >= 0; j--)
    {
    	for (i = 0; i < matrixWidth ; i++)
    	{
    		fwrite(&matrice[j][i], sizeof(matrice[j][i]), 1, file_out);
    	}
    	if (j*100/(matrixHeight - 1) < pourcentageAvancement)
    	{
    		pourcentageAvancement--;
    		printf("\r%d %c", 100 - pourcentageAvancement, pourcentageCaractere);
    	}
    }
	printf("\nDONE\n");
}	

colorNB ** intialisation_matrice_NB(info_header headerBMP)
{
    int i;
    colorNB ** matrice = NULL;
    int matrixWidth = headerBMP.width;
    int matrixHeight = headerBMP.height;
    matrice = (colorNB**) calloc(matrixWidth, sizeof(colorNB*));
    for(i=0; i<matrixHeight; i++)
    {
        matrice[i] = (colorNB*) calloc(matrixHeight, sizeof(colorNB));
    }
    return matrice;
}

void remplissage_matrice_NB(colorNB **matrice, info_header headerBMP, FILE* file_in)
{
    int i;
    int j;
    int matrixWidth = headerBMP.width;
    int matrixHeight = headerBMP.height;
    char pourcentageCaractere ='%';
    int pourcentageAvancement = 100;

    printf("Remplissage de la matrice initiale:\n");
    for (j = matrixHeight - 1; j >= 0; j--)
    {
        for (i = 0; i < matrixWidth; i++)
        {
            fread(&matrice[j][i], sizeof(matrice[j][i]), DIM, file_in);
        }
        if (j*100/(matrixHeight - 1) < pourcentageAvancement)
        {
            pourcentageAvancement--;
            printf("\r%d %c", 100 - pourcentageAvancement, pourcentageCaractere);
        }
    }
    printf("\nDONE\n");
}


void sauvegarde_matrice_NB(colorNB **matrice, info_header headerBMP, FILE* file_out)
{
    int i;
    int j;
    int matrixWidth = headerBMP.width;
    int matrixHeight = headerBMP.height;
    char pourcentageCaractere ='%';
    int pourcentageAvancement = 100;

    printf("Sauvegarde de la matrice:\n");
    for (j = matrixHeight - 1; j >= 0; j--)
    {
        for (i = 0; i < matrixWidth ; i++)
        {
            fwrite(&matrice[j][i], sizeof(matrice[j][i]), 1, file_out);
        }
        if (j*100/(matrixHeight - 1) < pourcentageAvancement)
        {
            pourcentageAvancement--;
            printf("\r%d %c", 100 - pourcentageAvancement, pourcentageCaractere);
        }
    }
    printf("\nDONE\n");
}

palette ** lire_palette (palette **tab, FILE *file_in, int nbColor)
{
    tab = ( palette ** ) malloc( nbColor * (sizeof( palette * )));
    fread(tab, sizeof(palette), nbColor, file_in);

    return tab;
}

void ecrire_palette (palette **tab, FILE *file_out,int  nbColor)
{
    fwrite(tab, sizeof(palette), 256, file_out);
}