#define ex1
#include "stdio.h"
#include "stdlib.h"
/******************************************************************************

			MANIPULACAO DE ARQUIVOS

*******************************************************************************

1 - Introducao

Na Linguagem C, um arquivo e' um conceito logico onde todas as entradas ou
saidas da maquina sao associadas a um arquivo. Assim um arquivos em disco
tambem pode usar este conceito logico pois e' uma entrada e saida da maquina.
Para trocar dados com um arquivo especifico realiza-se uma operacao de
abertura do arquivo. Uma vez que o arquivo esteja aberto, informacoes podem ser
intercambiadas entre o arquivo e o seu programa.

Nem todos os arquivos tem as mesmas capacidades. Por exemplo, um  arquivo em
disco pode-se ler e escrever dados enquanto a entrada de dados pelo teclado so'
pode ler dados.Isso ilustra um ponto importante sobre o sistema de entrada/saida
(E/S) de dados da linguagem C: todos os dados sao os mesmos, mas nem todos os
arquivos os sao.

A abertura de um arquivo inicializa um ponteiro de arquivo apontando para o
comeco dele. A medida que cada caracter e' lido ou escrito no arquivo, o
ponteiro de arquivo e' incrementado, assegurando assim a progressao deste
atraves do arquivo.

O acesso a um arquivo e' interrompido por meio de uma operação de fechamento.
Nos arquivos abertos como saida, o fechamento faz com que o conteudo, se houver,
na memoria intermediaria(buffer) seja descarregado para o dispositivo externo.
Esse processo e' geralmente referenciado como uma limpeza/descarga de dados
e garante que nenhuma informacao sera' acidentalmente esquecida na area
intermediaria(buffer) do disco. Todos os arquivos sao fechados automaticamente
quando o programa termina normalmente.

Resumindo, os procedimentos para se acessar um arquivo sao:
- abertura do arquivo
- leitura ou escrita de dados
- fechamento do arquivo

2 - Ponteiro de arquivo

A linha comum que une o sistema de E/S de disco aos programas escritos em C e' o
ponteiro de arquivo. Este é um ponteiro para uma area na memoria(buffer) onde
estao contidos varios dados sobre o arquivo, tais como o nome do arquivo, estado
e posicao corrente, etc. A memoria(buffer) apontado pelo ponteiro de arquivo e'
a area intermediaria entre o arquivo no disco e o programa.

Um ponteiro de arquivo e' uma variavel ponteiro do tipo "FILE" que esta definida
no arquivo de cabecalho(header) "stdio.h". Para ler ou escrever dados em um
arquivo de disco, o programa deve declarar uma (ou mais de uma se formos
trabalhar com mais de um arquivo simultaneamente) variavel ponteiro de arquivo.

Para declarar uma variavel ponteiro de arquivo, usa-se o seguinte formato:

    FILE *p1;  -> "p1" é uma variavel ponteiro de arquivo do tipo "FILE"

3 - fopen()

A funcao fopen() abre um arquivo associando-o a uma estrutura do tipo "FILE" que
e' atualizada com as informacoes necessarias e retorna um ponteiro  de arquivo
ou simplesmente ponteiro para a localizacao desta estrutura. Deve-se entao fazer
a atribuicao deste valor retornado a um ponteiro previamente declarado pois
este sera' usado em substituicao ao nome do arquivo.

O formato geral e':
	fopen(nome_arquivo,modo);

  - nome_arq --> e' uma serie de caracteres contendo o nome externo do arquivo
  - modo ------> informa o tipo de uso que tera' o arquivo, podendo ser :

"r" --> Abre o arquivo apenas para leitura. Se ele ja' estava aberto, entao
o ponteiro e' posicionado no primeiro caracter do arquivo. Caso o arquivo nao
exista entao e' retornado uma condicao de erro representada pela constante
"NULL". A constante "NULL" e' definido no arquivo "stdio.h" e tem o valor -1.

"w" --> Abre o arquivo apenas para escrita. Se o arquivo ja' existia no disco,
entao todos os dados serao perdidos e se nao existia entao sera' criado.

"a" --> Abre o arquivo para acrescentar dados. Caso o arquivo nao exista sera'
criado.

"x" --> Abre o arquivo para escrita. O arquivo nao pode existir previamente.

4 - getc() e putc()

Estas funcoes de leitura e escrita para apenas um caracter por vez no arquivo.
Sao similares as funcoes getchar() e putchar().

O formato geral e':
	getc(ponteiro);
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo

O formato geral e':
	putc(caracter,ponteiro);
   - caracter --> caracter a ser escrito no arquivo
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo

5 - fclose()

Esta funcao fecha o arquivo aberto com a funcao fopen() liberando as areas de
memoria e blocos de controle criados para gerenciamento deste arquivo.

O formato geral e':
	fclose(ponteiro);
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.

6 - exit()

Esta funcao fecha todos arquivos que estejam abertos, encerra  a execucao do
programa e retorna ao sistema operacional.

O formato geral e':
	exit(0);

Exemplo:*/

#ifdef ex1
/*o programa cria e escreve caracteres no arquivo "teste1"*/
main()
{
//FILE *fopen(); /*a funcao fopen() retorna um ponteiro do tipo "FILE". Por isso,
//                 tem que fazer esta declaracao */
FILE *p;   /*declara o ponteiro "p" do tipo "FILE"*/
char ch;
char i;

printf("exemplo1 \n\n");
printf("abre o arquivo no modo escrita w \n");
if((p = fopen("teste1","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);  /*encerra o programa e volta ao sistema operacional*/
	}

printf("escreve 4 caracteres no arquivo teste1\n");
putc('a',p);
putc(66,p);

ch = 'e';
putc(ch,p);

i=70;
putc(i,p);

fclose(p);
}
#endif

#ifdef ex2
/* o programa le os caracteres escritos no arquivo "teste1" pelo exemplo 1*/
main()
{
//FILE *fopen();
FILE *p;
char ch;

printf("exemplo2 \n\n\n");
printf("abre o arquivo no modo leitura r \n");
if((p = fopen("teste1","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le os char escrito no arquivo pelo exemplo 1 e imprime na tela\n\n");
ch = getc(p);
putchar(ch);
putchar(getc(p));
putchar(getc(p));
putchar(getc(p));

fclose(p);
}
#endif

/*

7 - fscanf() e fprintf()

As funcoes fprintf() e fscanf() sao a leitura e a escrita formatada de dados
em arquivos, que seguem exatamente as mesmas caracteristicas das similares
printf() e scanf() acrescentando o ponteiro do arquivo.

O formato geral e':
	fprintf(ponteiro,serie_de_controle,argumentos);
	fscanf(ponteiro,serie_de_controle,argumentos);
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.
   - serie de controle --> usa-se os mesmos codigos de formatacao do printf().
   - argumentos --> como no printf() coloca-se as variaveis para os codigos de
  		    formatacao.
Exemplo:*/

#ifdef ex3
/*o programa cria e escreve dados formatados no arquivo teste2*/
main()
{
//FILE *fopen();
FILE *p;
int i = 100;
float f = 20.34;
unsigned u = 65000;
long l = 2000000000;
char c = 'x';
static char s[] = "dadosformatados";

if((p = fopen("teste2","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve dados formatados no arquivo teste2\n");
fprintf(p,"%d ",i);
fprintf(p,"%f ",f);
fprintf(p,"%u ",u);
fprintf(p,"%ld ",l);
fprintf(p,"%c ",c);
fprintf(p,"%s ",s);

fclose(p);
}
#endif

#ifdef ex4
/* programa que le dados formatados do arquivo teste2 e imprime na tela*/
main()
{
//FILE *fopen();
FILE *p;
int i;
float f;
unsigned u;
long l;
char c;
static char s[20];

if((p = fopen("teste2","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le os dados escritos pelo exemplo anterior\n");
fscanf(p,"%d ",&i);
fscanf(p,"%f ",&f);
fscanf(p,"%u ",&u);
fscanf(p,"%ld ",&l);
fscanf(p,"%c ",&c);
fscanf(p,"%s ",s);

printf("imprime na tela os dados formatados lidos do arquivo teste2\n\n");
printf("inteiro : %d\n",i);
printf("float   : %f\n",f);
printf("unsigned: %u\n",u);
printf("long    : %ld\n",l);
printf("char    : %c\n",c);
printf("string  : %s\n",s);

fclose(p);
}
#endif

/*

8 - fgets() e fputs()

As funcoes fgets() e fputs() le e escreve uma serie de caracteres no arquivo .
Elas sao similares as funcoes gets() e puts().

O formato geral e':
	fgets(string,tamanho,ponteiro);
   - string ----> e' um ponteiro para variavel que recebera'os caracteres lidos.
   - tamanho ---> e' o numero de caracteres a serem lidos
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.

O formato geral e':
	fputs(string,ponteiro);
   - string ----> e' um ponteiro para variavel a ser escrita no arquivo.
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.

Exemplos:*/

#ifdef ex5
main()
{
//FILE *fopen();
FILE *p;
static char s[] = "teste com variavel";
char a[40];
char b[100];

if((p = fopen("teste3","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve as strings no arquivo teste3\n");
fputs("isto e' um pequeno teste com uma string",p);
fputs(s,p);

fclose(p);
getchar();

if((p = fopen("teste3","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le as strings do arquivo teste3\n\n");
fgets(a,40,p);
fgets(b,100,p);

printf("escreve as strings lidas na tela\n\n");
puts(a);
puts(b);

fclose(p);
}
#endif

/*
9 - fread() e fwrite()

As funcoes fread() e fwrite() sao utilizadas para ler e escrever dados compostos
no arquivo.

O formato geral e':
	fread(b,c,n,p);
	fwrite(b,c,n,p);
   b -> e' o ponteiro para a variavel que recebera ou contem os dados.
   c -> e' o n. de bytes que serao lidos ou escritos.
   n -> e' o n. de itens que serao lidos ou escritos.
   p -> e' o ponteiro para a posicao corrente do arquivo.

Exemplo:*/

#ifdef ex6
char ch[5] = {'a','b','c','d','\0'};
typedef struct dados
	{
	int i;
	float f;
	double d;
	}dados;
dados numeros = {1000,5000,10000};

main()
{
char st[5];
dados num;

//FILE *fopen();
FILE *p;

if((p = fopen("teste4","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve as variaveis no arquivo teste4\n");
fwrite(ch,5,1,p);
fwrite(&numeros,sizeof(numeros),1,p);

fclose(p);
getchar();

if((p = fopen("teste4","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le as variaveis do arquivo teste4\n\n");
fread(st,5,1,p);
fread(&num,sizeof(num),1,p);

printf("escreve as variaveis lidas na tela\n\n");
printf("vetor: %s\n\n",st);
printf("estrutura: %d\n",num.i);
printf("estrutura: %f\n",num.f);
printf("estrutura: %g\n",num.d);

fclose(p);
}
#endif

/*
10 - fseek()

A funcao fseek() e' utilizada para posicionar o ponteiro do arquivo em
qualquer ponto para executar as operacoes de leitura ou escrita.

O formato e':
	fseek(p,d,o);
   p -> e' o ponteiro para a posicao corrente do arquivo.
   d -> e' o numero de bytes que serao deslocados que pode ser positivo ou
	negativo.
   o -> e' a origem para o deslocamento que sera' somado ou subtraido
        e pode assumir 3 valores que sao:
   	   0 -> comeco do arquivo.
	   1 -> posicao atual do arquivo.
	   2 -> fim do arquivo.
Exemplo: */
#ifdef ex7
struct dados
	{
	int i;
	float f;
	double d;

	char a;
	char b;
	char c;
	};
struct dados varios = {1000,20000,300000,'a','i','r'};

main()
{
//FILE *fopen();
FILE *p;
long y;		/* deslocamento */
long k = 0;	/* n. do registro */
int x;

if((p = fopen("teste5","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve 5 registros no arquivo teste5\n");
getchar();
for(x=0;x < 5;x++)
	{
	printf("escreve o registro %d: \n",x+1);
	printf("int    i: %d\n",varios.i);
	printf("float  f: %f\n",varios.f);
	printf("double d: %g\n",varios.d);
	printf("char a: %c\n",varios.a);
	printf("char b: %c\n",varios.b);
	printf("char c: %c\n",varios.c);
	getchar();

	fwrite(&varios,sizeof(varios),1,p);
	varios.i = varios.i + 10;
	varios.f = varios.f + 100;
	varios.d = varios.d + 1000;
	varios.a = varios.a + 1;
	varios.b = varios.b + 1;
	varios.c = varios.c + 1;
	}
fclose(p);

if((p = fopen("teste5","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}

printf("calcula o n. de bytes a partir do inicio do arquivo ate' o inicio\n");
printf(" do 3. registro. o 3. registro tem indice 2\n\n");
k = 2;
y = k * sizeof(varios);

printf("posiciona o ponteiro p no inicio 3. registro do arquivo teste5\n\n");
fseek(p,y,0);

printf("le o 3. registro do arquivo teste5\n\n");
fread(&varios,sizeof(varios),1,p);

printf("escreve o 3. registro na tela\n\n");
printf("int    i: %d\n",varios.i);
printf("float  f: %f\n",varios.f);
printf("double d: %g\n",varios.d);
printf("char a: %c\n",varios.a);
printf("char b: %c\n",varios.b);
printf("char c: %c\n",varios.c);

fclose(p);
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Faça um programa para:
    1 - criar/abrir um arquivo texto de nome ”arq.txt”,
    2 - receba via teclado diversos caracteres (um por vezes)e armazene-os
        nesse arquivo. O caracter '0' finaliza a entrada de dados.
    3 - abra o arquivo. Leia e imprima na tela todos os caracteres armazenados.

2 - Faça um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversário (dia e mês) em uma estrutura de 
    dados. 
    O programa deve ter as opções:
    1 - inserir contato
    2 - altera contato
    3 - exclui contato
    4 - pesquisar um contato pelo nome
    5 - listar todos os contatos
    6 - listar os contatos cujo nome inicia com uma letra digitada
    7 - imprimir os aniversariantes do mês.
    Sempre que o programa for encerrado, os contatos devem ser escritos no arquivo.
    Quando o programa iniciar os contatos devem ser lidos do arquivo.
    O vetor de estrutura será de 4 elementos como variavel local na funcao main().
    Utilize ponteiros

3 - Faça um programa para o controle de mercadorias em uma despensa doméstica.
    Cada produto será armazenado um código numérico, descrição e quantidade atual 
    numa estrutura de dados. Utilize ponteiros. A estrutura deve ser declarada como
    variavel local na funcao main().
    O programa deve ter as opções:
    1 - inclui produtos
    2 - altera produtos
    3 - exclui produtos
    4 - pesquisar uma mercadoria pela descrição
    5 - listar todos os produtos
    6 - listar os produtos não disponíveis.
    7 - alterar a quantidade atual
    Escreva os itens das mercadorias direto no arquivo. (utilize a funcao fseek).

4 - A partir do exercico 6 do capitulo de funcoes, retire o vetor de estrutura e
    escreva e leia os registros direto no arquivo. (utilize a funcao fseek).
*/

