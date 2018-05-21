#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <sys/timeb.h>
#include <unistd.h>


struct dados
{
	char identifier[2];
	unsigned long int file_size;
    unsigned long int reserved;
	unsigned long int data_offset;
	unsigned long int header_size;
	unsigned long int width;
	unsigned long int height;
	unsigned short planes;
	unsigned short bpp;
	unsigned long int compression;
	unsigned long int data_size;
	unsigned long int HRes;
	unsigned long int VRes;
	unsigned long int colors;
	unsigned long int important_colors;
	unsigned long int pallete;
	unsigned char *dados;
} imagem;



int LeituraImagem(void);
void SalvarImagem(void);


int main (void)
{
    int f;
    f=LeituraImagem();
//    if (f==1)
//	{SalvarImagem();}
    printf("\n");
    system ("PAUSE");
}
    
    
    
int LeituraImagem(void)
{
	FILE *arq;
	unsigned int g=1,i;
	char nomearq[128];

	printf("\n Entre com o nome do arquivo a ser lido : ");
	scanf("%s",nomearq);
	

	if((arq=fopen(nomearq,"rb"))==NULL)
	{
		g=0;
		printf("\n O arquivo nao pode ser aberto");
		printf("\n\nPressione qq tecla para continuar...");
		getchar();
		return(g);
	}

   
   	fread(&imagem.identifier[0],sizeof(char),1,arq);
	fread(&imagem.identifier[1],sizeof(char),1,arq);
	fread(&imagem.file_size,  sizeof(long int),1,arq);
	fread(&imagem.reserved,   sizeof(long int),1,arq);
	fread(&imagem.data_offset,sizeof(long int),1,arq);
	fread(&imagem.header_size,sizeof(long int),1,arq);
	fread(&imagem.width,      sizeof(long int),1,arq);
	fread(&imagem.height,     sizeof(long int),1,arq);
	fread(&imagem.planes,     sizeof(short),1,arq);
	fread(&imagem.bpp,        sizeof(short),1,arq);
	fread(&imagem.compression,     sizeof(long int),1,arq);
	fread(&imagem.data_size,       sizeof(long int),1,arq);
	fread(&imagem.HRes,            sizeof(long int),1,arq);
	fread(&imagem.VRes,            sizeof(long int),1,arq);
	fread(&imagem.colors,          sizeof(long int),1,arq);
	fread(&imagem.important_colors,sizeof(long int),1,arq);
	

	imagem.dados=(unsigned char*)malloc((imagem.data_size)*sizeof(char));
	


    for(i=0;i<imagem.data_size;i++)	
    {
		fread(&imagem.dados[i],  sizeof(char),1,arq);		
	}	
	puts("   Header ");		
    printf("\nMagic Number1 = %c ",imagem.identifier[0]);
	printf("\nMagic Number2 = %c ",imagem.identifier[1]);
    printf("\nfile size :   %d bytes",imagem.file_size);
	printf("\nThe offset where the bitmap data (pixels) can be found: %d ",imagem.data_offset);
	printf("\nThe number of bytes in the header = %d",imagem.header_size);
	printf("\nThe width of the bitmap in pixels = %d",imagem.width);
	printf("\nThe height of the bitmap in pixels = %d",imagem.height);
	printf("\nNumber of color planes being used= %d",imagem.planes);
	printf("\nThe number of bits/pixel = %d",imagem.bpp);
	printf("\ncompression = %d",imagem.compression);
	printf("\nData Size : %d",imagem.data_size);
	printf("\nThe horizontal resolution of the image = %d",imagem.HRes);
	printf("\nThe vertical resolution of the image = %d",imagem.VRes);
	printf("\nNumber of colors in the palette = %d",imagem.colors);
	printf("\nImportant_colors = %d",imagem.important_colors);
	printf("\n\n\n");
	puts("   Start of Bitmap Data \n");
		
    for(i=0;i<imagem.data_size;i++)
  	{
        printf("%d ",imagem.dados[i]);        
    }
     	
	
	fclose(arq);
	return(g);
}

void SalvarImagem(void)
{
	FILE *arq1;
	unsigned int g;
	char nomearq1[64];
    unsigned char valor;
    int cont=0,v[3];
    unsigned long int i,k;


   v[0]=v[1]=0;  v[2]=v[3]=1;

	do
	{
		printf("\n Entre com o nome do arquivo a ser salvo : ");
		scanf("%s",nomearq1);
      if((arq1=fopen(nomearq1,"wb"))==NULL)
		{
         g=0;
      	printf("\n O arquivo nao pode ser aberto.");
			printf("\n\nPressione qq tecla para continuar...");
			getchar();
			exit(0);
		}
		else
		{
			g=1;
		}

	}while(g==0);

    imagem.colors = 0;
    
	fwrite(&imagem.identifier[0],   sizeof(char),1,arq1);
	fwrite(&imagem.identifier[1],   sizeof(char),1,arq1);
    fwrite(&imagem.file_size,       sizeof(long int),1,arq1);
	fwrite(&imagem.reserved,        sizeof(long int),1,arq1);
	fwrite(&imagem.data_offset,     sizeof(long int),1,arq1);
	fwrite(&imagem.header_size,     sizeof(long int),1,arq1);
	fwrite(&imagem.width,           sizeof(long int),1,arq1);
	fwrite(&imagem.height,          sizeof(long int),1,arq1);
	fwrite(&imagem.planes,          sizeof(short),1,arq1);
	fwrite(&imagem.bpp,             sizeof(short),1,arq1);
	fwrite(&imagem.compression,     sizeof(long int),1,arq1);
	fwrite(&imagem.data_size,       sizeof(long int),1,arq1);
	fwrite(&imagem.HRes,            sizeof(long int),1,arq1);
	fwrite(&imagem.VRes,            sizeof(long int),1,arq1);
	fwrite(&imagem.colors,          sizeof(long int),1,arq1);
	fwrite(&imagem.important_colors,sizeof(long int),1,arq1);
	


   /*Área de Impressão da Figura*/
   for(i=1024;i<1024+(imagem.data_size)+2;i++)
		{
         printf("%d, ",imagem.dados[i]);
      	 fwrite(&imagem.dados[i],  sizeof(char),1,arq1);
      	 system("PAUSE");
   //      fwrite(&imagem.green[i],sizeof(char),1,arq1);
     //    fwrite(&imagem.blue[i], sizeof(char),1,arq1);
        }

 

	fclose(arq1);
}
