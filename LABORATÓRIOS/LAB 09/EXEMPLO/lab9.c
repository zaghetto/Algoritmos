
struct dados
{
	char identifier[2];
	unsigned long int file_size;
	unsigned long int reserved;
	unsigned long int data_offset;
	unsigned long int header_size;
	unsigned long int width;
	unsigned long int height;

	// ...demais variáveis do cabeçalho.

} imagem;

// Vetor de dados
unsigned char *dados;
    
// Abertura do arquivo
FILE *arq;	
arq = fopen(argv[1], "rb"));

// Leitura dos dados
fread(&imagem.identifier[0],sizeof(char),1,arq);
fread(&imagem.identifier[1],sizeof(char),1,arq);
fread(&imagem.file_size,  sizeof(long int),1,arq);
fread(&imagem.reserved,   sizeof(long int),1,arq);
fread(&imagem.data_offset,sizeof(long int),1,arq);
fread(&imagem.header_size,sizeof(long int),1,arq);
fread(&imagem.width,      sizeof(long int),1,arq);
fread(&imagem.height,     sizeof(long int),1,arq);
	
// ...ler demais informações do cabeçalho

	
// Alocar vetor para armazenar os dados
dados = (unsigned char*)malloc((imagem.data_size)*sizeof(char));
	

// Ler dados de
for(i=0;i<imagem.data_size;i++)	{

		fread(&dados[i],  sizeof(char),1,arq);		
}	

// Mostrar informações do cabeçalho
puts("   Header ");		
printf("\nMagic Number1 = %c ",imagem.identifier[0]);
printf("\nMagic Number2 = %c ",imagem.identifier[1]);
printf("\nfile size :   %d bytes",imagem.file_size);
printf("\nThe offset where the bitmap data (pixels) can be found: %d ",imagem.data_offset);
printf("\nThe number of bytes in the header = %d",imagem.header_size);
printf("\nThe width of the bitmap in pixels = %d",imagem.width);
printf("\nThe height of the bitmap in pixels = %d",imagem.height);

// ...mostrar demais informações do cabeçalho
		
// Mostrar dados da imagem		
for(i=0;i<imagem.data_size;i++) {

        printf("%d ",imagem.dados[i]);   
}
     	
