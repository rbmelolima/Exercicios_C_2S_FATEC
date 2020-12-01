#define ex1
#include "stdio.h"

/*****************************************************************************

			ESTRUTURA DE DADOS

******************************************************************************

1. Definicao

Estrutura e' uma variavel composta, formada por uma ou mais variaveis,
possilvelmente de tipos diferentes, colocadas juntas sob um unico nome.

Quando se declara uma estrutura de dados criamos um tipo de variavel composta
onde os membros sao definidos pelo usuario. Assim, podemos dizer que estamos
criando um "novo tipo de variavel".Isso porque o usuario tem total flexibilidade
para declarar qualquer tipo de variavel como "membro" da estrutura juntando-o
para uma finalidade especifica.

2. Declaracao de estruturas

O formato geral para a declaracao de um estrutura e':

struct <nome_estrutura>
	{	-> chave de abertura da estrutura

	membros;

	};	-> chave de fechamento da estrutura

Na declaracao da estrutura de dados temos a palavra reservada "struct" mais o
"nome da estrutura" que define o "novo tipo da variavel" criada pelo usuario. Na
declaracao dos "membros" da estrutura define-se as variaveis, que podem ser do
tipo char, int , float, long, vetor, estrutura, etc.., que irao compor este
"novo tipo de variavel".

Quando a estrutura de dados e' declarada, ainda nao foi criada a variavel
propriamente dita (reservado espaco em memoria). Para entender isso vamos fazer
uma analogia com a declaracao das variaveis simples que conhecemos.

Declarando uma variavel simples:
          <tipo> <nome_variavel>;

Declarando uma variavel composta do tipo estrutura de dados:
          struct <nome da estrutura> <nome da variavel>;
                  (tipo)

Exemplo usando a analogia:

- variavel simples
	   int notas;  -> variavel do tipo "int" de nome "notas"
          (tipo)

- variavel do tipo estrutura de dados

struct tipos      -> "novo tipo de variavel" definida pelo usuario
	{
	int a;
	float b;
	long c;
	};

     struct tipos numeros; -> variavel do tipo "struct tipos" de nome "numeros"
        (tipo)

3. Referencia aos membros de uma estrutura

Para referenciar um "membro" da estrutura de dados usamos o operador ponto(.)
no seguinte formato:
	<nome_variavel>.<membro>;

Exemplo:
	numeros.a
	numeros.b
	numeros.c

4. Inicializacao de estruturas de dados

Assim como nos vetores, uma estrutura de dados so' pode ser inicializada se
declarada como uma variavel global ou static local.

Porem se a inicializacao for elemento por elemento, a declaracao da variavel
pode ser local.

Exemplos:*/

#ifdef ex1
/* declaracao do tipo de variavel */
struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
	};

/* declaracao da variavel como global. Por isso pode ser inicializada */
struct data calendario = {7,9,1822,250};

main()
{
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

#ifdef ex2
/* declaracao do tipo de variavel */
struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
	};
main()
{
/* declaracao da variavel como estatica local. Por isso pode ser inicializada */
static struct data calendario = {15,11,1889,319};

printf("\nProclamacao da republica: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

#ifdef ex3
/* declaracao do tipo de variavel */
struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
	};
main()
{
/* declaracao da variavel como local porem sem inicializacao */
struct data calendario;

calendario.dia=26;       /*inicializacao elemento por elemento */
calendario.mes=1;
calendario.ano=1839;
calendario.dia_ano=26;

printf("\nFundacao de Santos: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

/*
5. Estruturas dentro de estruturas

Uma estrutura dentro de outra estrutura nada mais e' que uma variavel composta
dentro de outra variavel composta. Lembrando que os "membros" de uma estrutura
de dados pode ser de qualquer tipo, entao pode-se declarar como "membro" de uma
estrutura de dados outra estrutura de dados.

Para acessar os "membros" de uma estrutura de dados dentro de outra estrutura
de dados usa-se o operador ponto(.) partindo-se da variavel mais externa para
a variavel mais interna no seguinte formato:

	<nome_variavel>.<nome_variavel>.<membro>;
     estrutura externa   estrutura interna

Para se inicializar uma estrutura de dados dentro de outra estrutura de dados
tambem valem os conceitos vistos anteriormente.

Exemplo:*/

#ifdef ex4
/* declaracao do tipo de variavel */
struct relogio{
	int hora;    /* membros */
	int minutos;
	int segundo;
	};

struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
struct relogio tempo;	/* declara uma variavel do tipo estrutura de nome
			   "tempo" dentro de outra variavel tipo estrutura */
	};
/* declaracao da variavel como global. Portanto pode ser inicializada */
struct data calendario = {7,9,1822,250,
	/* inicializando a variavel "tempo" dentro da variavel "calendario" */
                                       {20,50,10}};

/*outra forma de inicializar a variavel "tempo" dentro da variavel "calendario"
     struct data calendario = {7,9,1822,250,20,50,10};
*/

main()
{
printf("\nA data e': ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d ",calendario.dia_ano);

printf("e a hora e': ");
printf("%d:%d:%d",calendario.tempo.hora,calendario.tempo.minutos,
                  calendario.tempo.segundo);
}
#endif

#ifdef ex5
/* declaracao do tipo de variavel */
struct relogio{
	int hora;    /* membros */
	int minutos;
	int segundo;
	};

struct data {
	int dia;    /* membros */
	int mes;
	int ano;
struct relogio tempo;	/* declara uma variavel do tipo estrutura de nome
			   "tempo" dentro de outra variavel tipo estrutura */
	};

struct data calendario;

main()
{
/* entrada de dados */

printf("entre com data e hora do seu aniversario\n");
scanf("%d",&calendario.dia);
scanf("%d",&calendario.mes);
scanf("%d",&calendario.ano);

scanf("%d",&calendario.tempo.hora);
scanf("%d",&calendario.tempo.minutos);
scanf("%d",&calendario.tempo.segundo);

printf("\nA data e': ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);

printf("e a hora e': ");
printf("%d:%d:%d",calendario.tempo.hora,calendario.tempo.minutos,
                  calendario.tempo.segundo);
}
#endif

/*
6. Vetores como variavel dentro de uma estruturas de dados

Uma estrutura pode ser composta por variaveis simples(int, float, long, ...) e
variaveis compostas(vetores, estruturas). Neste caso, pode-se declarar um vetor
como "membro" de uma estrutura. O formato para declarar um vetor como "membro"
de uma estrutura e' o mesmo visto anteriormente.

Exemplo:*/
#ifdef ex6

struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9]; /* declara um vetor do tipo "char" de nome "nome_mes"
			    com 9 elementos dentro de uma estrutura. */
	};

struct data calendario = {15,11,1889,319,"novembro"}; /* variavel global */

main()
{
printf("\nProclamacao da republica: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d - ",calendario.dia_ano);
printf("%s\n",calendario.nome_mes);/*imprime o "membro" "nome_mes" como string*/

printf("\nimprimindo o nome do mes letra a letra: %c%c%c%c%c%c%c%c",
calendario.nome_mes[0],
calendario.nome_mes[1],
calendario.nome_mes[2],
calendario.nome_mes[3],
calendario.nome_mes[4],
calendario.nome_mes[5],
calendario.nome_mes[6],
calendario.nome_mes[7]);
}
#endif

/*
7. Vetor de estruturas de dados

Como ja' estudamos, um vetor se caracteriza por ter todos os seus elementos do
mesmo tipo e acessar estes elementos por um indice. Com estrutura de dados nao
e' diferente.

Fazendo analogia com um vetor como ja' conhecemos ele e' composto por variaveis
simples do tipo int, float long,... Na declaracao de um vetor onde cada elemento
e' uma estrutura de dados nada muda, pois todos os elementos continuam sendo do
mesmo tipo. O detalhe esta' no tipo da variavel que neste caso e' definida pelo
usuario atraves da declaracao de uma estrutura de dados.

Para declarar um vetor de estruturas de dados, deve-se primeiro definir a
estrutura com seus "membros", "novo tipo de variavel", e depois declarar um
vetor deste tipo.

Aqui tambem para referenciar "membros" em um vetor de estrutura usa-se o "nome
da variavel" mais o "indice" do elemento do vetor e o operador ponto(.) para
acessar o "membro" da estrutura de dados no seguinte formato:

	<nome_variavel> [<n. do elemento>].<membro>;

Para se inicializar um vetor de estruturas tambem valem os conceitos de vistos
anteriormente.

Exemplo: */

#ifdef ex7
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[10];
	};

/* declara um vetor de estrutura do tipo "struct data" de nome "calendario" com
3 elementos sendo cada um uma estrutura*/

struct data calendario[3] = {7,9,1822,250,"setembro",
                                      15,11,1889,319,"novembro",
                                                 26,1,1839,26,"janeiro"};
main()
{
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario[0].dia);
printf("%d/",calendario[0].mes);
printf("%d, ",calendario[0].ano);
printf("%d - ",calendario[0].dia_ano);
printf("%s\n",calendario[0].nome_mes);

printf("\nProclamacao da republica: ");
printf("%d/",calendario[1].dia);
printf("%d/",calendario[1].mes);
printf("%d, ",calendario[1].ano);
printf("%d - ",calendario[1].dia_ano);
printf("%s\n",calendario[1].nome_mes);

printf("\nFundacao de Santos: ");
printf("%d/",calendario[2].dia);
printf("%d/",calendario[2].mes);
printf("%d, ",calendario[2].ano);
printf("%d - ",calendario[2].dia_ano);
printf("%s\n",calendario[2].nome_mes);
}
#endif

#ifdef ex8
struct data {
	int dia;
	int mes;
	int ano;
	char nome_mes[10];
	};
main()
{
/* declara um vetor de estrutura do tipo "struct data" de nome "calendario" com
3 elementos sendo cada um uma estrutura*/
struct data calendario[3];


printf("\nEntre com a data da Proclamacao da Independencia: \n");
scanf("%d",&calendario[0].dia);
scanf("%d",&calendario[0].mes);
scanf("%d",&calendario[0].ano);
printf("digite o mes por extenso: ");
scanf("%s",&calendario[0].nome_mes[0]);
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario[0].dia);
printf("%d/",calendario[0].mes);
printf("%d, ",calendario[0].ano);
printf("%s\n",calendario[0].nome_mes);

printf("\nEntre com a data da Proclamacao da Republica: \n");
scanf("%d",&calendario[1].dia);
scanf("%d",&calendario[1].mes);
scanf("%d",&calendario[1].ano);
printf("digite o mes por extenso: ");
scanf("%s",&calendario[1].nome_mes[0]);
printf("\nProclamacao da republica: ");
printf("%d/",calendario[1].dia);
printf("%d/",calendario[1].mes);
printf("%d, ",calendario[1].ano);
printf("%s\n",calendario[1].nome_mes);

printf("\nEntre com a data da Fundacao de Santos: \n");
scanf("%d",&calendario[2].dia);
scanf("%d",&calendario[2].mes);
scanf("%d",&calendario[2].ano);
printf("digite o mes por extenso: ");
scanf("%s",&calendario[2].nome_mes[0]);
printf("\nFundacao de Santos: ");
printf("%d/",calendario[2].dia);
printf("%d/",calendario[2].mes);
printf("%d, ",calendario[2].ano);
printf("%s\n",calendario[2].nome_mes);
}
#endif

/*
8. Typedef
A Linguagem C permite definir explicitamente "novos nomes" para os tipos de
dados existentes usando-se a palavra reservada "typedef". Nao se cria um novo
tipo de variavel mas, ao contrario, define-se um "novo nome" para um tipo que
existem. O "typedef" tambem auxilia na documentacao do programa permitindo
definir nomes que descrevam melhor os tipos de dados padroes ou definidos pelo
usuario (estruturas).

O formato geral e':
   typedef <tipo da variavel> <novo nome do tipo da variavel>;

Exemplo:
   typedef int inteiro;
   typedef float flutuante;

Exemplo:  */

#ifdef ex9
struct data{
	int dia;
	int mes;
	int ano;
	int dia_ano;
	};

typedef struct data data;    /* a estrutura dados de nome "struct data" passa a
       		                ser chamada por um "novo nome que e' "data".*/

data calendario = {7,9,1822,250};

main()
{
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado e imprima estes conteudos no video no seguinte
    formato.
             char, int, long, float, double
             unsigned char, unsigned int, unsigned long,

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long

2 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos. Receba os dados pelo teclado e imprima-os no video. Faça um
    menu. (vetor de estruturas)
		nome, end, cidade, estado, cep

3 - Crie uma estrutura para representar as coordenadas de um ponto no plano
    (posicoes X e Y). Em seguida, declare e leia do teclado um ponto e exiba a
    distancia dele ate' a origem das coordenadas, isto é, posição (0, 0). Para
    realizar o cálculo, utilize a fórmula a seguir:
           d = raiz quadrada de  (XB - XA)ao 2 +(YB -YA)ao 2
    Em que:
    d = distância entre os pontos A e B
    X = coordenada X em um ponto
    Y = coordenada Y em um ponto
*/

