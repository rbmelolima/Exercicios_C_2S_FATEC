#define ex1
#include "stdio.h"
/******************************************************************************

				FUNCOES

*******************************************************************************

1 - Conceito de funcao

Funcoes dividem grandes tarefas de computacao em tarefas menores, e permitem as
pessoas trabalhar sobre o que outras ja' fizeram, em vez de partir do inicio
novamente. Funcoes bem definidas podem frequentemente esconder detalhes de
operacao de partes de um programa. Nos ja' usamos a funcao printf() sem conhecer
os detalhes de sua programacao.

2 - Definicao

Funcao e' um conjunto de instrucoes e/ou declaracoes desenhadas para cumprir uma
determinada tarefa e referencia-la por um nome.

A principal razao para usar funcoes e' dividir uma tarefa em outras pequenas
tarefas que simplificam e organizam o programa como um todo.

Outra razao para escrever funcoes e' a de reduzir o tamanho do programa.
Qualquer sequencia de instrucoes ou declaracoes que apareca no programa mais de
uma vez e' candidata a se transformar em uma funcao.

Uma funcao e' escrita no programa uma unica vez mas pode ser executado muitas
vezes durante a execucao do programa.

A funcao, uma vez desenvolvida e testada, passa a ser completamente transparente
ao usuario, que necessita saber sua utilidade, as informacoes de entradas e
infomacoes de saida, podendo abster-se de todos os detalhes de sua
implementacao. Exemplos disso sao as funcoes printf, scanf, gets, puts que
temos utilizado sem saber como foram construidas.

3 - Formato de uma funcao em C

A estrutura de uma funcao na linguaguem C e' semelhante a estrutura da funcao
main(). A unica diferenca e' que a funcao main() tem um nome especial.

O formato de uma funcao em C e':

<tipo_de_retorno> <nome_da_funcao> (<parametros ou informacoes>)
tipos dos parametros ou informacoes;

{
	declaracao de variaveis;
	comandos;
	funcoes;
        retorno da funcao;
}

tipo_de_retorno -----------> E' o tipo do dado que a funcao retornara'.

nome_da_funcao ------------> E' o nome pelo qual a funcao sera' chamada.

parametros ou informacoes ou
lista de argumentos -------> Sao as informacoes que a funcao recebe para
                             executar a tarefa definida.

tipos dos parametros  ou
informacoes ---------------> Se houve informacoes entao o tipo destes deve ser
                             declarado.

declaracao de variaveis----> Declaracao dos tipos das variaveis locais`a funcao
                             e que sao utilizados apenas dentro nesta.

comandos ------------------> Sao os comandos da linguaguem C que executam as
                             tarefas definidas para a funcao.

funcoes -------------------> Sao chamadas para funcoes de biblioteca e/ou outras
                             funcoes desenvolvidas pelo programador.

retorno da funcao ---------> Retorna uma informacao para a funcao que chamou.

4 - Chamando uma funcao

Chamar uma funcao e' desviar o fluxo do programa para que uma tarefa seja
executada. Terminada esta tarefa chamada, o fluxo do programa retorna para a
declaracao seguinte a da chamada da funcao.

Varias funcoes, como o printf(), sao desenvolvidas pelo fabricante do compilador
e juntadas ao programa pelo linkeditor. Sao as chamadas funcoes de biblioteca.

Podemos tambem escrever nossas proprias funcoes no programa e chama-las como
fazemos com as funcoes de biblioteca.

A sintaxe para chamar uma funcao e'

	<nome_da_funcao>(<parametros ou informacoes>);

Exemplo:
	printf("teste");  chama a funcao de bilioteca "printf" e passa a
                          informacao "teste".

	soma(a,b);   chama a funcao "soma" e passa as informacoes "a" e "b".

Exemplo:*/

#ifdef ex1
/*  a funcao imprimir mensagens na tela */

void imprimir_mensagem()
{
printf("\t\t Voce esta' na funcao imprimir_mensagem\n");
printf("\t\t esta funcao foi chamada pela funcao main()\n");
printf("\t\t fim da funcao imprimir_mensagem\n\n");
}

main()
{


printf("\nVoce esta' na funcao main()\n");
printf("Este exemplo mostra a chamada de uma funcao.\n\n");

imprimir_mensagem(); /*chama a funcao"imprimir_mensagem" desenvolvida pelo
                       programador e sem a passagem de informacoes para a funcao
                       chamada */

printf("Voce esta' de volta a funcao main()\n");
printf("Fim do programa\n");
}

#endif

/*

5 - Passagem de parametros ou informacoes

O que sao parametros ou informacoes ou argumentos de uma funcao?
Sao as informacoes que a funcao recebe para executar a tarefa para a qual foi
desenvolvida.

Existem dois metodos de passagem de parametros ou informacoes para uma funcao.

- O 1. metodo e' a passagem de parametros ou informacoes por "valor" ou "copia".

Neste metodo, na função que chamou faz-se uma copia dos valores a serem
enviados para a funcao chamada. Dessa forma os valores originais nao podem ser
alterados, pois a funcao chamada manipula apenas as copias dos mesmos. Na funcao
chamada sao criadas variaveis do mesmo tipo da funcao que chamou que receberao
as copias destes valores.

Lembrando que as variaveis que recebem os parametros ou informcoes da funcao que
chamou e as que estao dentro da funcao chamada, sao variaveis locais. Portanto,
quando a execucao da funcao se encerrar as variaveis sao destruidas ou seja, o
seu conteudo e' perdido.

Exemplo:*/

#ifdef ex2
void soma(int i,int j);
void troca(int x,int y);

main()		/* passagem de parametros por "valor" ou "copia" */
{
int a,b;
a = 10;
b = 20;


printf("main() -> antes da troca ---> a = %d  b = %d \n\n",a,b);

troca(a,b); /* chama a funcao "troca" passando como informacao a copia dos
               valores das variaveis "a" e "b" */

printf("main() -> depois da troca --> a = %d  b = %d \n\n",a,b);

soma(a,b);  /* chama a funcao "soma" passando como informacao a copia dos
               valores das variaveis "a" e "b" */

printf("Voce esta' de volta a funcao main()\n");
printf("Fim do programa\n");
}

/* funcao troca dois valores */

void troca(int x,int y)    /* recebe a copias dos valores das variaveis "a" e "b" 
                           da funcao main */
{
int c;

printf("\tfuncao troca()\n");
printf("\ttroca os valores da variaveis x e y que sao\n");
printf("\tcopias das variaveis a e b da funcao main().\n\n");

printf("\to valor de x e' %d, o de y e' %d\n",x,y);

c = x;
x = y;
y = c;

printf("\to valor de x e' %d, o de y e' %d\n",x,y);
printf("\tfim da funcao troca\n\n");
}

/* funcao soma dois valores */

void soma(int i,int j)
{
int k;

k = i + j;

printf("\tfuncao soma()\n");

printf("\to valor de i e' %d, o de j e' %d e a soma de i + j e'%d\n",i,j,k);
printf("\tfim da funcao soma\n\n");
}
#endif

/*

- O 2. metodo sera' estudado oportunamente.


6 - Retorno de informacao de uma funcao

Uma funcao chamada pode retornar um ou nenhum valor a funcao que a chamou.
Para retornar uma valor a funcao que chamou utiliza-se o comando "return".

O formato geral e':

	return(informacao);	retorna o valor
	return();		nao retorna valor
	return;			nao retorna valor

A utilizacao do comando "return" e' opcional quando nao ha' retorno de valor.

IMPORTANTE: O comando "return" retorna uma unica informacao.

Exemplo: */

#ifdef ex6
int soma(int x,int y);

main()
{
int a,b,c;
a = 100;
b = 200;


printf("chama a funcao soma(). \n");
printf("A funcao soma() retorna o resultado que e' atribuido a variavel c\n\n");

c = soma(a,b); /* chama a funcao "soma" e passa como informacao uma copia dos
                  valores de "a" e "b" */

printf("soma de a + b e': %d + %d = %d \n",a,b,c);
}

/* funcao "soma" que recebe 2 valores por passagem de informacoes por "valor"
ou "copia", soma estes valores e retorna o resultado */

int soma(int x,int y)
{
int z;

printf("\tfuncao soma() \n");
printf("\ta funcao soma os valores x e y \n");
printf("\tretorna o resultado com o comando return\n\n");

z = x + y;

return(z); /* retorna o resultado da soma dos valores recebidos */
}
#endif

/*
7 - Definindo o tipo do valor de retorno

Os valores devolvidos pelo comando "return" sao inteiros por default como no
exemplo anterior. Quando nao existe valor devolvido, se a funcao que chamou
estiver esperando algum valor, recebera lixo e ocorrera um erro de logica nao
detectavel pelo compilador.

As funcoes podem devolver valores nao inteiros. Para isto devemos especificar
claramente o "tipo_de_retorno" na funcao chamada e declarar tambem este mesmo
tipo na funcao de chamada.

O formato geral para chamar uma funcao que retorna uma valor diferente de
inteiro e':

	<nome_da_função> (parametros ou informacoes);

Deve-se tambem declarar o tipo da informacao retornada na funcao que chamou
junto com as variaveis locais desta.

O formato geral é:
	<tipo> <nome_da_funcao>();

Exemplo:
	float soma();

Lembrando que o formato para se declarar uma variavel simples e':
	<tipo> <nome_da_variavel>;

Exemplo:
	float numero;

Note que a declaracao do tipo de "retorno da funcao" e' semelhante a declaracao
de uma variavel simples.

O formato geral para declarar uma funcao que retorna uma valor diferente de
inteiro e':
	<tipo_de_retorno> <nome_da_funcao>(parametros ou informacoes);

Exemplo:
      float soma(a,b) Atencao: aqui nao tem ";" pois e' a declaracao da funcao
      float a,b;
      {
      }

Exemplo:*/

#ifdef ex7
float soma(float x,float y);

main()
{
float a,b,c;
//float soma(); /* declara que a funcao "soma" retornara' um valor do tipo float*/

a = 3957.779;
b = 43558.357;


printf("chama a funcao soma(). \n");
printf("A funcao soma() retorna o resultado que e' atribuido a variavel c\n\n");

c = soma(a,b);   /* chama a funcao "soma" e passa como informacao uma copia dos
                    valores de "a" e "b" e espera o retorno de um valor do
                    tipo "float" */

printf("soma de a + b e': %.3f + %.3f = %.3f \n",a,b,c);
}

/* funcao "soma" que recebe 2 valores por passagem de informacoes por "valor",
soma estes valores e retorna o resultado como "float" pois o "tipo_de_retorno"
desta funcao esta declarado como "float" */

float soma(float x,float y) /* na frente do <nome_da_funcao> esta' declarado o
                   <tipo_de_retorno> ou o tipo de valor que o comando "return"
                   vai retornar */
{
float z;

printf("\tfuncao soma() \n");
printf("\ta funcao soma os valores x e y \n");
printf("\tretorna o resultado com o comando return\n\n");

z = x + y;

return(z); /* retorna o resultado da soma dos valores de guardados em "z" neste
              caso "float" */
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
    no video na funcao main(). Passe como informacao para a funcao a letra 
    digitada.(utilize o comando return). O vetor deve ser uma variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

2 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima-os no video na funcao main().

3 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.

4 - Aproveitando o programa anterior inclua a selecao das operacoes aritmeticas
    para transforma-lo em uma calculadora. (utilize o comando switch).

5 - Escreva um programa que receba na funcao main() 2 strings de ate' 10 caracteres.
    Escreva as funcoes que compare estas 2 strings e retorne se sao IGUAIS 1 e 
    se DIFERENTES 0. Declare as strings como variavel global.     
*/
