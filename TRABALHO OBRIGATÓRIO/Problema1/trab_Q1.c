#include<stdio.h>
#include<stdlib.h>

typedef struct bmpImage
{
	// 2 x 1 Byte
	char identifier[2];
	// 4 Bytes
	unsigned long  int file_size;
    unsigned long  int reserved;
	unsigned long  int data_offset;
	unsigned long  int header_size;
	unsigned long  int width;
	unsigned long  int height;
	// 2 Bytes
	unsigned short int planes;
	unsigned short int bpp;
	// 4 Bytes
	unsigned long  int compression;
	unsigned long  int data_size;
	unsigned long  int HRes;
	unsigned long  int VRes;
	unsigned long  int colors;
	unsigned long  int important_colors;
	unsigned long  int pallete;
	unsigned char *dados;
} TBMPimage;

int readImage(TBMPimage *, FILE *);
int showData(TBMPimage *);


// Chamar com trab2Q2.exe RGB2x2.bmp
int main (int argc, char *argv[])
{
	// Ponteiro para Struct
	TBMPimage ImageOriginal;

 	// Abre o  arquivo
	FILE *fp;
	fp=fopen(argv[1],"rb");

	if(fp==NULL){
        printf("Erro!");
        system("PAUSE");
	}

	// Lê os dados
    readImage(&ImageOriginal, fp);

    // Mostra os dados
    showData(&ImageOriginal);

    // Feacha o arquivo
    fclose(fp);


    return 0;

}

int readImage(TBMPimage *img, FILE *fp)
{
	int i;

   	fread(&img->identifier[0],    sizeof(char     ),1,fp);
	fread(&img->identifier[1],    sizeof(char     ),1,fp);
	fread(&img->file_size,        sizeof(long  int),1,fp);
	fread(&img->reserved,         sizeof(long  int),1,fp);
	fread(&img->data_offset,      sizeof(long  int),1,fp);
	fread(&img->header_size,      sizeof(long  int),1,fp);
	fread(&img->width,            sizeof(long  int),1,fp);
	fread(&img->height,           sizeof(long  int),1,fp);
	fread(&img->planes,           sizeof(short int),1,fp);
	fread(&img->bpp,              sizeof(short int),1,fp);
	fread(&img->compression,      sizeof(long  int),1,fp);
	fread(&img->data_size,        sizeof(long  int),1,fp);
	fread(&img->HRes,             sizeof(long  int),1,fp);
	fread(&img->VRes,             sizeof(long  int),1,fp);
	fread(&img->colors,           sizeof(long  int),1,fp);
	fread(&img->important_colors, sizeof(long  int),1,fp);

	img->dados=(unsigned char*)malloc((img->data_size)*sizeof(char));

    for(i=0;i<img->data_size;i++)
    {
		fread(&img->dados[i],  sizeof(char), 1, fp);
	}

	return 0;
}

int showData(TBMPimage *img){

    int i;

	puts("   Header ");

    printf("\nMagic Number1 = %c ",img->identifier[0]);
	printf("\nMagic Number2 = %c ",img->identifier[1]);
    printf("\nfile size :   %d bytes",img->file_size);
	printf("\nThe offset where the bitmap data (pixels) can be found: %d ",img->data_offset);
	printf("\nThe number of bytes in the header = %d",img->header_size);
	printf("\nThe width of the bitmap in pixels = %d",img->width);
	printf("\nThe height of the bitmap in pixels = %d",img->height);
	printf("\nNumber of color planes being used= %d",img->planes);
	printf("\nThe number of bits/pixel = %d",img->bpp);
	printf("\ncompression = %d",img->compression);
	printf("\nData Size : %d",img->data_size);
	printf("\nThe horizontal resolution of the image = %d",img->HRes);
	printf("\nThe vertical resolution of the image = %d",img->VRes);
	printf("\nNumber of colors in the palette = %d",img->colors);
	printf("\nImportant_colors = %d",img->important_colors);
	printf("\n\n\n");

	puts("   Start of Bitmap Data \n");

    for(i=0;i<img->data_size;i++)
  	{
        printf("%d ",img->dados[i]);
    }

    free(img->dados);

    return 0;
}






