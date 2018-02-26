//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.
#include "Header.h"

int main(int argc, char const *argv[])
{
    FILE *file_in = NULL;
    if (argc > 1)
    {
        file_in = fopen(argv[1], "rb");
        printf("Votre fichier est : \n");
    }
    else
    {    
        int choix =0;
        printf("Quelle fichier :\n");
        printf("(1) En couleur\n");
        printf("(2) En noir et blanc\n");
        scanf("%d", &choix);
        if (choix == 1)
        {
        	file_in = fopen("lena_RGB.bmp","rb");
        }
        else if (choix == 2)
        {
        	file_in = fopen("lena_NB.bmp","rb");
        }
    }
    if (file_in)
    {
    	// ***********************************************
    	// ** CREATION ET LECTURE DE L'ENTETE DU BITMAP **
    	// ***********************************************

    	// INITIALISATION DES HEADERS
    	printf("LECTURE DES HEADERS\n");
    	info_header headerBMP;
    	file_header header;
        printf("\nDONE\n");

    	// LECTURE DE L'ENTETE DE FICHIER ET DE BITMAP
    	fread(&header, sizeof(header), 1, file_in);
    	fread(&headerBMP, sizeof(headerBMP), 1, file_in);

    	// LECTURE DE LA PALLETTE SI BESOIN
    	palette ** paletteIMG = NULL;
    	if (headerBMP.nbColor != 0)
    	{
    		paletteIMG = lire_palette (paletteIMG, file_in, headerBMP.nbColor);
    	}

        // AFFICHAGE DES INFORMATION RÉCUPÉRÉ PAR LA LECTURE
    	afficher_headers(headerBMP, header);


    	// ********************************************
    	// ** CREATION DE LA MATRICE DE MODIFICATION **
    	// ********************************************

    	//INTIALISATION DE LA MATRICE
    	colorRGB ** matrixIMG_RGB = NULL;
    	colorNB ** matrixIMG_NB = NULL;

    	if (headerBMP.depth == 24)
    	{
    		matrixIMG_RGB = intialisation_matrice_RGB(headerBMP);
    	}
    	else if (headerBMP.depth == 8)
    	{
    		matrixIMG_NB = intialisation_matrice_NB(headerBMP);
    	}

    	//LECTURE ET REMPLISSAGE DE LA MATRICE
        if (headerBMP.depth == 24)
        {
        	remplissage_matrice_RGB(matrixIMG_RGB, headerBMP, file_in);
        }
        else if (headerBMP.depth == 8)
    	{
    		remplissage_matrice_NB(matrixIMG_NB, headerBMP, file_in);
    	}

    	// *******************************************
        // ** PROCESSUS: MODIFICATION DE LA MATRICE **
        // *******************************************

        // CHOIX DE LA MODIFICATION
        char action[200];
        int NbrAction;
        printf("Dilatation ou Erosion ?\n");
        printf("-----------------------\n");
        printf("Veulliez rentrer une chaine de caratere pour avoir des dilatations ou des erosions dans l'ordre souhait""\x82""\n");
        printf("Ex: eeeddede\n");
        printf("Votre choix: ");
        scanf("%s",action);
        NbrAction = strlen(action);
        int repeat;
        printf("Combien de fois voulez-vous r""\x82""p""\x82""ter cette s""\x82""quence ?\n");
        printf("Votre choix: ");
        scanf("%d", &repeat);
        int choix1;
        int choix2;
        printf("\nQuel type de connexion ?\n(1)\tConnexion 4\n(2)\tConnexion 8\n");
        printf("Votre choix: ");
        scanf("%d",&choix2);
        printf("\n");

        infoNB ** etiquette_NB = NULL;
        infoRGB ** etiquette_RGB = NULL;
    	int i, j, k, l;

        if (headerBMP.depth == 24)
        {
            etiquette_RGB = calloc_matrice_info_RGB(etiquette_RGB, headerBMP.width, headerBMP.height);
        }
        else if (headerBMP.depth == 8)
        {
            etiquette_NB = calloc_matrice_info_NB(etiquette_NB, headerBMP.width, headerBMP.height);
        }
        
        for (k = 0; k < NbrAction + 1; k++)
        {
            if (action[k] == 'e')
            {
                choix1 = 1;
            }
            else if (action[k] == 'd')
            {
                choix1 = 2;
            }
            else
            {
                choix1 = 0;
            }
            // PARCOURS DE LA MATRICE ET REMPLISSAGE DU TABLEAU ETIQUETTE
            for (l = 0; l < repeat; l++)
            {
                for(j = 0; j < headerBMP.height; j++)
                {
                    for(i = 0; i < headerBMP.width; i++)
                    {
                        if (choix1 == 1)
                        {
                            if (choix2 == 1)
                            {
                            	if (headerBMP.depth == 24)
                                {
                            		coin_info_erosion_C4_RGB(matrixIMG_RGB, etiquette_RGB, i, j, headerBMP.width, headerBMP.height);  
                                }
                            	if (headerBMP.depth == 8)
                                {
                            		coin_info_erosion_C4_NB(matrixIMG_NB, etiquette_NB, i, j, headerBMP.width, headerBMP.height);
                                }   
                            }
                            if (choix2 == 2)
                            {
                            	if (headerBMP.depth == 24)
                                {
                            		coin_info_erosion_C8_RGB(matrixIMG_RGB, etiquette_RGB, i, j, headerBMP.width, headerBMP.height);
                                }
                            	if (headerBMP.depth == 8)
                                {
                                	coin_info_erosion_C8_NB(matrixIMG_NB, etiquette_NB, i, j, headerBMP.width, headerBMP.height);
                                }
                            }
                        }
                        if (choix1 == 2)
                        {
                            if (choix2 == 1)
                            {
                            	if (headerBMP.depth == 24)
                                {
                            		coin_info_dilatation_C4_RGB(matrixIMG_RGB, etiquette_RGB, i, j, headerBMP.width, headerBMP.height);
                                }
                            	if (headerBMP.depth == 8)
                                {
                                	coin_info_dilatation_C4_NB(matrixIMG_NB, etiquette_NB, i, j, headerBMP.width, headerBMP.height);
                                }
                            }
                            if (choix2 == 2)
                            {
                            	if (headerBMP.depth == 24)
                                {
                            		coin_info_dilatation_C8_RGB(matrixIMG_RGB, etiquette_RGB, i, j, headerBMP.width, headerBMP.height);
                                }
                            	if (headerBMP.depth == 8)
                                {
                                	coin_info_dilatation_C8_NB(matrixIMG_NB, etiquette_NB, i, j, headerBMP.width, headerBMP.height);
                                }
                            }
                        }
                    }
                }
            }

            // PARCOURS DE LA MATRICE ET EXETUTION DES MODIFICATIONS
        	if (headerBMP.depth == 24)
            {         
                if (choix1 == 1)
                {
                    erosion_RGB(matrixIMG_RGB, etiquette_RGB, headerBMP.width, headerBMP.height);
                }
                if (choix1 == 2)
                {
                    dilatation_RGB(matrixIMG_RGB, etiquette_RGB, headerBMP.width, headerBMP.height);
                }
            }     
            else if (headerBMP.depth == 8)
            {
                if (choix1 == 1)
                {
                    erosion_NB(matrixIMG_NB, etiquette_NB, headerBMP.width, headerBMP.height);
                }
                else if (choix1 == 2)
                {
                    dilatation_NB(matrixIMG_NB, etiquette_NB, headerBMP.width, headerBMP.height);
                }
            }
        }



    	// ******************************************************
    	// ** SAUVEGARDE DE LA MATRICE DANS UNE NOUVELLE IMAGE **
    	// ******************************************************

        FILE *file_out = NULL;
        file_out = fopen ("image_modified.bmp","wb");
        if (file_out)
        {
    	    //SAUVEGARDE DES HEADERS DANS L'IMAGE DE SORTIE
    		printf("Sauvegarde des headers\n");
    		fwrite(&header, sizeof(header), 1, file_out);

    		fwrite(&headerBMP, sizeof(headerBMP), 1, file_out);
    		printf("DONE\n");

    		// SAUVEGARDE DE LA PALLETTE SI BESOIN
    		if (headerBMP.nbColor != 0)
    		{
    			ecrire_palette (paletteIMG, file_out, headerBMP.nbColor);
    		}

    		// SAUVEGARDE DE LA MATRICE DANS L'IMAGE DE SORITE
    		if (headerBMP.depth == 24)
    	    {
    	    	sauvegarde_matrice_RGB(matrixIMG_RGB, headerBMP, file_out);
    	    }
    	    else if (headerBMP.depth == 8)
    		{
    			sauvegarde_matrice_NB(matrixIMG_NB, headerBMP, file_out);
    		}
            
            // LIBERATION DE LA MATRICE
            free(matrixIMG_RGB);
            free(matrixIMG_NB);
        }
        else
            printf("PROBLEME : file_out ne s'est pas accroché au fichier de sortie\n");
        fclose(file_out);
    }
    else
        printf("PROBLEME : file_in ne s'est pas accroché au fichier d'entree\n");
    fclose(file_in);
    return 0;
}
