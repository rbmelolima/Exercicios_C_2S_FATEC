#define ex1
#include "stdio.h"

/******************************************************************************

	    MATRIZES OU VETORES COM SERIE DE CARACTERES OU STRING

*****************************************************************************
1. Vetor de serie de caracteres ou strings

Um vetor de string e' uma variavel do tipo "char" que armazena mais de um
caracter ou seja um serie de caracteres. Assim, um vetor de string e�uma serie
de caracteres, onde cada um deste caracteres ocupa um byte na memoria, um do
lado do outro em sequencia, e o ultimo byte e'sempre o finalizador "\0".

Um vetor de string pode ser acessado de 2 formas, caracter por caracter atraves
do "indice" de cada uma dos elemnetos do vetor (como nos vetores numerico), ou
como uma string acessando todos os caracteres ate' encontrar o finalizador"\0",

2. Inicializando um vetor ou matriz de strings ou serie de caracteres

Lembrando que, um vetor so�pode ser inicializado se for declarado como uma
variavel global ou static local. Para um vetor de string a regra continua
valendo.

Podemos inicializar um vetor de strings de 2 formas:

A - Inicializando letra por letra como nos vetores numerico. Neste caso, o
finalizador "\0" deve ser colocado explicitamente assim pode-se tratar os
elementos deste vetor como uma unica string. Nao colocando o finalizador
"\0" nao se pode acessar o conteudos como string apenas caracter por caracter
atraves do indice como nos vetores numericos.

Exemplo:
    char nome [] = {'F','A','T','E','C'}; sem finalizador

    char nome [] = {'F','A','T','E','C','\0'}; com finalizador

B - Inicializando como string. Neste caso o finalizador e�colocado
automaticamente. Lembrando ainda que o finalizador tambem e�um caracter,
portanto ocupa uma posicao no vetor.

Exemplo:
    char nome [] = {"FATEC"}; sem contar os caracteres da string, o pre'
                              compilador faz a contagem

    char nome [6] = {"FATEC"}; contando os caracteres da string (5 letras +
                               1 do finalizador

Antes de estudarmos alguns exemplos com vetores utilizando uma serie de
caracteres ou string, vamos voltar as funcoes de biblioteca printf e scanf e
verificar como elas funcionam usando uma string.

3 - printf() -> escreve caracteres formatados na saida padrao.(no caso video)

A forma geral da funcao printf() e�:
	printf("<serie de controle>", lista de argumentos);

O codigo de formatacao para uma serie de caracteres ou string e' "%s"

Lembrando que tambem para string pode-se indicar o "tamanho do campo",
"alinhando" ou "justificado" (a direita ou a esquerda) a informacao no campo
definido como vimos para os numeros. No caso de string nao temos o numero de
casas decimais (precisao) pois sao caracteres e nao numeros.

O formato geral e':
	% <alinhamento> <tamanho de campo> <codigo de formatacao>

Exemplo:
%10s    -> define o alinhamento a direita e o tamanho de campo com 10 posicoes
%-10s   -> define o alinhamento a esquerda e o tamanho de campo com 10 posicoes

Exemplo:
*/
#ifdef ex1
/* variavel global do tipo caracter, com inicializacao letra por letra.
   Aqui nao tem o finalizador\0 e nao se contou o n. de elementos do vetor */

char f[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

main()
{
    printf("As letras sao: \n");
    printf(" %c", f[0]);
    printf(" %c", f[1]);
    printf(" %c", f[2]);
    printf(" %c", f[3]);
    printf(" %c", f[4]);
    printf(" %c", f[5]);
    printf(" %c", f[6]);
    printf(" %c", f[7]);
    printf(" %c", f[8]);
    printf(" %c", f[9]);
}
#endif

#ifdef ex2
/* idem ao anterior. Contando o n. de elementos do vetor. */

char f[10] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q'};

main()
{
    printf("As letras sao: \n");
    printf(" %c %c %c %c %c %c %c %c %c %c",
           f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]);
}
#endif

#ifdef ex3
/* idem ao ex1. Conta o n. de elementos do vetore acrescenta explicitamente o
finalizador \0 */

char f[11] = {'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', '\0'};

main()
{
    printf("As letras sao: \n");
    printf(" %c %c %c %c %c %c %c %c %c %c \n",
           f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]);

    printf("Acessando o vetor como string -> %s", f);
}
#endif

#ifdef ex4
/* variavel global do tipo caracter. Inicializacao como string (finalizador e'
colocado automaticamente). Contou - se o n. de elementos do vetor */

char f[11] = "zyxwvutsrq"; /* 10 letras + 1 finalizador */

main()
{
    printf(" As letras sao: \n");
    printf(" %c", f[0]);
    printf(" %c", f[1]);
    printf(" %c", f[2]);
    printf(" %c", f[3]);
    printf(" %c", f[4]);
    printf(" %c", f[5]);
    printf(" %c", f[6]);
    printf(" %c", f[7]);
    printf(" %c", f[8]);
    printf(" %c\n\n", f[9]);

    printf("Acessando o vetor como string -> %s\n", f);
}

#endif

#ifdef ex5
main()
{
    /*variavel static local do tipo caracter.Sem contar o n. de elementos do vetor*/

    static char f[] = "abcdefghij"; /* 10 letras + 1 finalizador */

    printf(" As letras sao: \n");
    printf(" %c", f[0]);
    printf(" %c", f[1]);
    printf(" %c", f[2]);
    printf(" %c", f[3]);
    printf(" %c", f[4]);
    printf(" %c", f[5]);
    printf(" %c", f[6]);
    printf(" %c", f[7]);
    printf(" %c", f[8]);
    printf(" %c\n\n", f[9]);

    printf("Acessando o vetor como string -> %s\n", f);
}

#endif

#ifdef ex6
/* variavel global do tipo caracter. Inicializacao com uma string (finalizador
colocado automaticamente). Nao se contou o n. de elementos do vetor */

char str[] = "FATEC BS - CURSO ADS 2.SEMESTRE";

main()
{
    printf("        10        20\n");
    printf("12345678901234567890  \n");
    printf("%s\n", "FATEC");    /* sem alinhamento e tamanho de campo*/
    printf("%10s\n", "FATEC");  /* alinhado pela direita c/ tam = 10 */
    printf("%-10s\n", "FATEC"); /* alinhado pela esquerda c/ tam = 10 */
    printf("%-20s\n", str);     /* alinhado pela esquerda c/ tam = 20 */
    printf("%20s\n\n", str);    /* alinhado pela direita c/ tam = 20 */

    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890 \n");
    printf("%-50s\n", str); /* alinhado pela esquerda c/ tam = 50 */
    printf("%50s\n", str);  /* alinhado pela direita c/ tam = 50 */
}
#endif

/*
4 - scanf() -> le caracteres formatados da entrada padrao. (no caso teclado)

A forma geral da funcao scanf() e�:
	scanf("<serie de controle>", lista de argumentos);

O codigo de formatacao para uma serie de caracteres ou string e' "%s".

Lembrando que no scanf a serie de controle nao pode conter nenhuma string ou
caracter especial somente o codigo de formatacao.

Exemplo:
*/
#ifdef ex7
main()
{
    char a[30]; /*variavel local. Como nao tem inicializacao e' obrigatorio
               declarar o numero de elementos (tamanho) do vetor */
    printf("digite uma string: \n");

    scanf("%s", &a[0]);

    printf("a string digitada e': %s", a);
}

#endif

/*
Temos outras 2 funcoes de biblioteca que funcionando somente com uma serie de
caracteres ou string, sao elas:

5 - gets () -> le uma serie de caracteres da entrada padrao (no caso teclado) +
a tecla ENTER.

A forma geral da funcao gets() e': gets(variavel);

Exemplo:*/
#ifdef ex8
main()
{
    char c[40]; /*variavel local. Como nao tem inicializacao e' obrigatorio
                declarar o numero de elementos (tamanho) do vetor */
    printf("digita um string via teclado : ");
    gets(c);
    printf("a string digitada e': %s", c);
}
#endif

/*
6 - puts() -> escreve uma serie de caracteres na saida padrao.(no caso video)

A forma geral da funcao puts() e�: puts(variavel);

Exemplo:*/
#ifdef ex9
main()
{
    char c[50]; /*variavel local. Como nao tem inicializacao e' obrigatorio
                 declarar o numero de elementos (tamanho) do vetor */

    puts("digita um string via teclado : ");
    gets(c);
    printf("a string digitada e': ");
    puts(c);
}
#endif

/*
7. Um vetor de strings

Anteriormente nos estudamos vetores numericos com mais de uma dimensao. Uma
string e�um vetor unidimensional. Portanto, se juntarmos varios vetores de
strings teremos um vetor bidimensional.

A forma geral de uma vetor de strings e�:
          char <nome_da_vari�vel> [num_de_strings][compr_das_strings];

Exemplo:
char semana [7] [14];  vetor bidimensional do tipo "char" de nome "semana" com
                       7 linha(string) e 14 colunas(as strings com no maximo
                       14 caracteres)

Fazendo uma comparacao com a declaracao de um vetor numerico que ja visto
anteriormente temos:

int tabela [2] [3]; vetor bidimensional do tipo "int" de nome "tabela" com
                    2 linha e 3 coluna

IMPORTANTE:
Observe os exemplos acima. Nos 2 casos as declaracoes sao exatamente iguais. A
diferenca esta' na forma de interpreta'-las. O 1. exemplo usa caracteres e o
2. exemplo usa numeros.

8 - Acessando uma string ou linha no vetor de strings

Para acessar uma string ou linha no vetor de strings usa-se apenas o primeiro
�ndice do vetor que indica o "numero da string" ou "linha".

A forma geral para acessar uma string no vetor de strings e�:
             <nome_da_vari�vel> [num_da_strings ou linha];

Exemplo:
semana [2]; acessa a 3. linha (string) do vetor "semana"

Porque utiliza-se apenas o indice de "linha" ou "numero da string" para acessar
uma string num vetor bidimensional?
Porque as funcoes de bibliotecas printf (usando o codigo de formatacao "%s") e
puts colocam na tela todos os elementos de um vetor de caracteres ou string ate'
encontrar o finalizador "\0". Isto possibilita utilizar apenas um indice o
"num_da_string" ou "linha" para acessar todo o conteudo desta linha do vetor de
caracteres.

Assim como nos vetores numerico tambem pode-se acessar qualquer caracter de um
vetor de string utilizando-se os dois indices. Um vetor de string nao e'
diferente de um vetor numerico.

Exemplo:

vetor de string
semana [0] [2]; acessa a 1. linha (string) e a 3. coluna (caracter)

vetor numerico
tabela [0] [2]; acessa a 1. linha e a 3. coluna

9. Inicializacao de um vetor de strings

Um vetor de strings e�um vetor bidimensional. Assim, para inicializa-lo
coloca-se o operador atribuicao "=", o abre chave ({), as strings entre aspas
("),  separadas por virgula "," e o fecha chave (}).

Exemplos:
*/

#ifdef ex10
/* vetor bidimensional com 7 strings ou linhas e 14 caracteres ou colunas */

char semana[7][14] = {
    "Domingo",
    "Segunda-feira",
    "Terca-feira",
    "Quarta-feira",
    "Quinta-feira",
    "Sexta-feira",
    "Sabado",
};
main()
{

    printf(" Dias da semana \n\n");
    printf(" %s\n", semana[0]);
    printf(" %s\n", semana[1]);
    printf(" %s\n", semana[2]);
    printf(" %s\n", semana[3]);
    printf(" %s\n", semana[4]);
    printf(" %s\n", semana[5]);
    printf(" %s\n", semana[6]);
}
#endif

#ifdef ex11
/* vetor bidimensional com 7 strings ou linhas e 14 caracteres ou colunas */

char semana[7][14] = {
    "Domingo",
    "Segunda-feira",
    "Terca-feira",
    "Quarta-feira",
    "Quinta-feira",
    "Sexta-feira",
    "Sabado",
};
main()
{

    printf(" Acessando cada letra da string sabado \n\n");
    printf("%c", semana[6][0]);
    printf("%c", semana[6][1]);
    printf("%c", semana[6][2]);
    printf("%c", semana[6][3]);
    printf("%c", semana[6][4]);
    printf("%c", semana[6][5]);
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa para receber 5 nomes, com at� 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3

2 - Escreva um programa para receber 3 strings de ate 10 caracteres cada via
    teclado e imprima-as no video no seguinte formato:
    (utilize vetores multidimensionais)

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        string1             string2             string3

3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres 
    para letras maiusculas. 

4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres 
    para letras minusculas.

3 - Receba 2 string de ate 10 caracteres via teclado, compare-as mostrando como
    resultado se s�o IGUAIS ou DIFERENTES.
*/
