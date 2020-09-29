#define ex1
#include "stdio.h"

/******************************************************************************

			MATRIZES OU VETORES NUMERICOS

*******************************************************************************

1. Compreendendo o que sao matrizes ou vetores

Uma matriz ou vetor e� um conjunto de dados que pode armazenar multiplos valores
do mesmo tipo.

Por exemplo, pode-se criar uma vetor que contenha 100 valores do tipo "int"
e um segundo vetor com 25 valores do tipo "float". Observe que todos os valores
que sao atribuidos a um vetor sao do mesmo tipo.

Os valores de um vetor sao acessados atraves de um indice. Este indice e' que
caracteriza uma matriz ou vetor.

2.Definicao

Vetores sao variaveis compostas que agrupam dados do mesmo tipo e sao
referenciadas atraves de um indice.

Na linguaguem C, todos os vetores sao montados numa sequencia continua de
memoria ou seja,o endereco mais baixo corresponde ao primeiro elemento, e o
endereco mais alto ao ultimo elemento.

3.Declaracao de vetores

Para declarar um vetor, precisa-se especificar o tipo de dado desejado (tal
como int, float ou double), bem como o tamanho do vetor. Para especificar o
tamanho do vetor, utiliza-se o operador "[]". Dentro dos colchetes coloca-se o
numero de elementos que o vetor ira' armazenar.

O formato para declaracao de um vetor e':

	<tipo> <nome_variavel> [tamanho];
onde:
      tipo -> define o tipo de dado dos elementos do vetor.(int, float, long,
              etc..)

      nome_variavel -> e�o nome pelo qual o vetor vai ser referenciado

      tamanho -> e�o n�mero de elementos que o vetor vai conter

OBS.: O <nome_variavel> de um vetor deve expressar o seu significado, mas deve
      obedecer as mesmas 4 regras para atribuicao de nomes das variaveis
      simples.

Exemplo:
int notas [100];    declara um vetor de nome "notas" do tipo "int" que pode
                    armazenar "100" notas

float salarios [50];   declara um vetor de nome "salarios" do tipo "float" que
                       pode armazenar "50" sal�rios

Outro detalhe importante e�que na linguagem C nao ha' verificacao de limites nos
vetores. Isto significa que e�possivel ultrapassar o fim de um vetor e escrever
em outras variaveis, ou mesmo em trechos de codigo de programa. E�tarefa do
programador fazer com que os indices dos vetores estejam sempre dentro dos
limites estabelecidos pela declaracao do tamanho do vetor.

4. Refenciando um elemento do vetor

Cada um dos elementos de um vetor e�refenciado individualmente por meio de um
numero inteiro (indice) entre colchetes"[]" apos o nome do vetor. Este numero
tem 2 significados diferente a saber:
1. quando referencia um elemento do vetor e' o "indice do elemento".

2. na declaracao do vetor que indica o seu "tamanho".

Quando referenciamos um elemento do vetor atraves do seu indice, este numero
especifica a posicao do elemento no vetor

Exemplo:
notas [4];  referencia o 5. elemento do vetor "notas"

salarios [13];  referencia o 14. elemento do vetor "salarios"

Observando os exemplos acima podemos notar que o n. do elemento e�um a mais que
o numero entre colchetes. Isso acontece por que na linguaguem C as refenrencias
ou indices comecam em 0 e a referencia ou indice do ultimo elemento e�o tamanho
do vetor -1.

5.Inicializacao de vetores

Pode-se inicializar os elementos de um vetor junto com a declaracao da variavel.

Para inicializar os elementos um vetor temos 2 formas que sao os seguintes:

1 - declarando o n. de elementos do vetor explicitamente.

exemplo: int notas [4] = {1,2,3,4};

2 - sem declarar o tamanho do vetor. Neste caso, o tamanho sera� preenchido
pelo pre-compilador que contara o n. de elementos da inicializacao. Os
colchetes "[]" sao declarados vazios neste caso.

Exemplo: int notas [] = {1,2,3,4};

Observe nos exemplos acima que a inicializacao e�feita utilizando-se o abre
chave"{" e o fecha chave"}" colocados depois do operador atribuicao(=) e entre
as chaves "{}" utiliza-se a virgula"," para separar os elementos.

Um vetor so' pode ser inicializado se for declarado como uma variavel global
ou static local.

Um vetor declarado como variavel local pode ser inicializado se for elemento
por elemento.

Porem, se o vetor for declarado mas nao tem inicializacao, entao e' obrigatorio
declarar o numero de elementos(tamanho) deste vetor. Em outra palavras os
colchetes tem que ter o numero de elementos do vetor (tamanho).

Exemplos:*/

#ifdef ex1
/* inicializacao como variavel global com o tamanho do vetor declarado
explicitamente */

int f[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

main()
{
    printf("Os numeros sao: ");
    printf(" %d", f[0]);
    printf(" %d", f[1]);
    printf(" %d", f[2]);
    printf(" %d", f[3]);
    printf(" %d", f[4]);
    printf(" %d", f[5]);
    printf(" %d", f[6]);
    printf(" %d", f[7]);
    printf(" %d", f[8]);
    printf(" %d", f[9]);
}
#endif

#ifdef ex2
main()
{
    /* inicializacao como variavel local static sem declarado de tamanho */

    static int f[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    printf("Os numeros sao: ");
    printf(" %d %d %d %d %d %d %d %d %d %d",
           f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]);
}
#endif

#ifdef ex3
main()
{
    /* vetor como variavel local, sem inicializacao.
Aqui como nao tem inicializacao e obrigatorio preencher os colchetes "[]" com
o numero de elementos do vetor (tamanho) */

    float f[10];

    f[0] = 11.1; /* inicializacao elemento por elemento*/
    f[1] = 12.2;
    f[2] = 13.3;
    f[3] = 14.4;
    f[4] = 15.5;
    f[5] = 16.6;
    f[6] = 17.7;
    f[7] = 18.8;
    f[8] = 19.9;
    f[9] = 20.29;

    printf("Os numeros sao: \n");
    printf(" %f\n", f[0]);
    printf(" %f\n", f[1]);
    printf(" %f\n", f[2]);
    printf(" %f\n", f[3]);
    printf(" %f\n", f[4]);
    printf(" %f\n", f[5]);
    printf(" %f\n", f[6]);
    printf(" %f\n", f[7]);
    printf(" %f\n", f[8]);
    printf(" %f\n", f[9]);
}
#endif

/*
6. Vetores com mais de uma dimensao

Como foi visto, um vetor e� uma variavel que pode armazenar multiplos valores
do mesmo tipo. Nos exemplos apresentados, os vetores consistiram de uma fileira
de dados ou seja um vetor unidimensional. No entanto, a Linguagem C permite
vetores bi, tri e multidimensionais.

O melhor modo de visualizar uma vetor bidimensional  e�como uma tabela com
linhas e colunas.

Por exemplo, ao declarar-se um vetor bidimensional, o primeiro valor que for
especificado informara o numero de linhas, e o segundo valor, o numero de
colunas:

Exemplo:
int tabela [2] [3]; vetor bidimensional (linha 2 coluna 3)

Se um vetor contem tres dimensoes, visualize-se como varias p�ginas, cada uma
das quais contendo uma tabela bidimensional.

Por exemplo, ao declarar-se um vetor tridimensional, o primeiro valor declarado
informara' a pagina, o segundo valor declarado informara' o numero de linhas, e
o terceiro valor, o numero de colunas:

Exemplo:
int tabela [2] [3] [4]; vetor tridimensional (pagina 2 linha 3 coluna 4)

OBS IMPORTANTE: Apesar da linguagem C utilizar o conceito de "vetor multi-
dimensional" os elementos destes vetores sao armazenados na memoria de forma
linear ou continua ou seja todos os elementos do vetor estao um do lado do
outro na memoria do computador. Isso possibilita acessar os elementos do vetor
multidimensionais como se fossem vetores unidimensionais.

7. Inicializacao de vetores com mais de uma dimensao

Os vetores de mais de uma dimensao sao inicializados da mesma forma que os
vetores de uma unica dimensao, isto e�, os elementos sao colocados entre o abre
chave"{" e o fecha chave"}" depois do operador atribuicao "=" e seus elementos
separados por virgulas entre as chaves "{}". Pode-se inicializar um vetor multi-
dimensional usando as chaves "{}" e a separacao dos elementos por v�rgulas","
internamente para melhor visualizar as suas linhas e colunas. Esta notacao e'
utilizada para apenas para facilitar a visualizacao.

Exemplo:
          linhas colunas
int tabela [2]    [3]   = {{1,2,3}, {4,5,6}};
                           linha 1   linha 2

Esta mesma inicializacao poderia ser apenas com um abre chave "{" e um fecha
chave "}" simplesmente.

Exemplo:
int tabela [2] [3] = {1,2,3,4,5,6};

Exemplo:
*/
#ifdef ex4
/* declara um vetor bidimensional como variavel global */

int tabela[2][3] = {{10, 20, 30}, {40, 50, 60}};

main()
{

    printf(" valor da linha 1 coluna 1-> %d\n", tabela[0][0]);
    printf(" valor da linha 1 coluna 2-> %d\n", tabela[0][1]);
    printf(" valor da linha 1 coluna 3-> %d\n", tabela[0][2]);

    printf(" valor da linha 2 coluna 1-> %d\n", tabela[1][0]);
    printf(" valor da linha 2 coluna 2-> %d\n", tabela[1][1]);
    printf(" valor da linha 2 coluna 3-> %d\n", tabela[1][2]);
}
#endif

#ifdef ex5
/* declara um vetor tridimensional como variavel global */

float valores[2][3][5] = {
    {{1.0, 2.0, 3.0, 4.0, 5.0},
     {6.0, 7.0, 8.0, 9.0, 10.0},
     {11.0, 12.0, 13.0, 14.0, 15.0}},

    {{16.0, 17.0, 18.0, 19.0, 20.0},
     {21.0, 22.0, 23.0, 24.0, 25.0},
     {26.0, 27.0, 28.0, 29.0, 30.0}}};
main()
{

    printf("Valores da pagina 1\n");

    printf(" linha 1 coluna 1-> %f\n", valores[0][0][0]);
    printf(" linha 1 coluna 2-> %f\n", valores[0][0][1]);
    printf(" linha 1 coluna 3-> %f\n", valores[0][0][2]);
    printf(" linha 1 coluna 4-> %f\n", valores[0][0][3]);
    printf(" linha 1 coluna 5-> %f\n", valores[0][0][4]);

    printf(" linha 2 coluna 1-> %f\n", valores[0][1][0]);
    printf(" linha 2 coluna 2-> %f\n", valores[0][1][1]);
    printf(" linha 2 coluna 3-> %f\n", valores[0][1][2]);
    printf(" linha 2 coluna 4-> %f\n", valores[0][1][3]);
    printf(" linha 2 coluna 5-> %f\n", valores[0][1][4]);

    printf(" linha 3 coluna 1-> %f\n", valores[0][2][0]);
    printf(" linha 3 coluna 2-> %f\n", valores[0][2][1]);
    printf(" linha 3 coluna 3-> %f\n", valores[0][2][2]);
    printf(" linha 3 coluna 4-> %f\n", valores[0][2][3]);
    printf(" linha 3 coluna 5-> %f\n\n", valores[0][2][4]);

    printf("aperte a tecla enter para continuar");
    getchar();

    printf("Valores da pagina 2\n");

    printf(" linha 1 coluna 1-> %f\n", valores[1][0][0]);
    printf(" linha 1 coluna 2-> %f\n", valores[1][0][1]);
    printf(" linha 1 coluna 3-> %f\n", valores[1][0][2]);
    printf(" linha 1 coluna 4-> %f\n", valores[1][0][3]);
    printf(" linha 1 coluna 5-> %f\n", valores[1][0][4]);

    printf(" linha 2 coluna 1-> %f\n", valores[1][1][0]);
    printf(" linha 2 coluna 2-> %f\n", valores[1][1][1]);
    printf(" linha 2 coluna 3-> %f\n", valores[1][1][2]);
    printf(" linha 2 coluna 4-> %f\n", valores[1][1][3]);
    printf(" linha 2 coluna 5-> %f\n", valores[1][1][4]);

    printf(" linha 3 coluna 1-> %f\n", valores[1][2][0]);
    printf(" linha 3 coluna 2-> %f\n", valores[1][2][1]);
    printf(" linha 3 coluna 3-> %f\n", valores[1][2][2]);
    printf(" linha 3 coluna 4-> %f\n", valores[1][2][3]);
    printf(" linha 3 coluna 5-> %f\n\n", valores[1][2][4]);
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890 
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double

2 - Receba via teclado dez valores inteiros e ordene por ordem crescente assim 
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores em ordem.

3 - Um vetor � pal�ndromo se ele n�o se altera quando as posi��es dos componentes
    s�o invertidos. Por exemplo, o vetor v = {1, 3, 5, 2, 2, 5, 3, 1} � pal�ndromo.
    Escreva um programa que verifique se um vetor � pal�ndromo. Receba o vetor 
    via teclado (tamanho 10)

4 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    subtracao "-", subtraia os elementos de mesmo indice dos 2 vetores
    e guarde o resultado num 3. vetor. Imprima na tela o indice, os valores e
    o resultado dos 6 elementos dos vetores.

5 - Receba via teclado valores para uma matriz 5 x 5. Receba via teclado um valor X. 
    O programa dever fazer a busca desse valor x na matriz e, ao final escrever a
    localizacao (linha e coluna) ou uma mensagem de �nao encontrado�.



*/
