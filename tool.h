//  Copyright © 2016 Alexandre CONTASSOT, Anne-Sophie LABANSAT. All rights reserved.

#ifndef tool_h
#define tool_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 1
#define DONE(num) printf("\n*****DONE*****"); printf("\n******%d*******\n", num);

#pragma pack(1)

typedef struct
{
	char signature[2];
	int size;
	int reserved;
	int offset;

}file_header;

typedef struct
{
	int entete_size;
	int width;
	int height;
	short plans;
	short depth;
	int compr;
	int sizeTotal;
	int hRes;
	int vRes;
	int nbColor;
	int nbColorImp;

}info_header;

typedef struct
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;

}colorRGB;

typedef unsigned char colorNB;

typedef enum{modifie, pastoucher}modif;

typedef struct
{
    modif infoCase;
    colorRGB valeurMax;
    colorRGB valeurMin;

}infoRGB;

typedef struct
{
    modif infoCase;
    colorNB valeurMax;
    colorNB valeurMin;
    
}infoNB;

typedef struct
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
	unsigned char reserved;

} palette;

#endif