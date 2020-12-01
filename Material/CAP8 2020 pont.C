#define ex4a
#include "stdio.h"

/******************************************************************************

			 PONTEIROS OU APONTADORES

*******************************************************************************

1. Como funciona os ponteiros?

Os ints guardam numeros inteiros. Os floats guardam numeros de ponto flutuante.
Os chars guardam caracteres. Ponteiros guardam enderecos de memoria.

Quando voce anota o endereco de um colega voce esta' criando um ponteiro. O
ponteiro e' este seu pedaco de papel. Ele tem anotado um endereço. Qual e' o
sentido disto? Simples. Quando voce anota o endereco de um colega, depois voce
vai usar este endereco para acha'-lo. Na linguaguem C funciona assim. Voce anota
o endereco de uma variavel num ponteiro para depois usa-la.

Um ponteiro tambem tem tipo. Veja: quando voce anota o endereco de um amigo voce
o trata diferente de quando voce anota o endereco de uma empresa. Apesar do
endereco dos dois locais ter o mesmo formato (rua, numero, bairro, cidade, etc.)
eles indicam locais cujos conteudos são diferentes. Entao os dois enderecos sao
ponteiros de tipos diferentes.
                            p                               f
                            -------------------------------->
                           |                                |
        -------------------------------------------------------------------
	....| xxx | xxx | 308 |    ......    | xxx | xxx | ´i´ | xxx | ....
        -------------------------------------------------------------------
             $100  $101  $102                 $306  $307  $308  $309

Na figura acima, "p" e' um ponteiro para a variavel "f'. Ou seja, "p" contem o
endereco de memoria onde esta' armazenada a variável "f".

2.  Definicao

Ponteiro e' uma variavel que, diferentemente das outras, nao contem o valor
de um dado, mas aponta para o endereco de outra variavel que o contem.

3. Ponteiros para variaveis simples

Na linguaguem C quando declaramos ponteiros nos informamos ao compilador para
que tipo de variável vamos aponta'-lo. Um ponteiro int aponta para uma variavel
do tipo inteira, isto é, guarda o endereço de um inteiro.

O formato geral para a declaracao de um ponteiro para variaveis simples e':

	tipo *nome_variavel;

onde "tipo" indica o tipo da variavel (int, char, estrutura, etc..)
e "nome_variavel" e' o nome da variavel ponteiro.

exemplos
	char *pc;        declara um ponteiro do tipo char de nome "pc"
	int *pi;         declara um ponteiro do tipo int de nome "pi"
	float *pf;      declara um ponteiro do tipo float de nome "pf"
	unsigned *pu;    declara um ponteiro do tipo unsigned de nome "pu"

Para atribuir-se diretamente o endereco da variavel apontada, deve-se utilizar
o operador de endereco "&" (E comercial) antes do nome da variavel a ser
apontada; isto indicara' que se quer acessar o endereco da mesma e nao seu
conteudo.

O formato geral e':
		ponteiro = &nome_variavel;

Olhando a figura inicial temos:
	p = &f;	   atribui ao ponteiro "p" o end. da variavel "f".
                   Em outras palavras atribui a "p" o endereco $308.

Exemplos:
declaracao de variaveis
	char a = 'p';
	int b = 700;
	float c = 9.777;
	unsigned d = 4000000007;

Atribuindo os enderecos aos ponteiros;
	pc = &a;    atribui ao ponteiro "pc" o end. da variavel "a".
	pi = &b;    atribui ao ponteiro "pi" o end. da variavel "b".
	pf = &c;    atribui ao ponteiro "pf" o end. da variavel "c".
	pu = &d;    atribui ao ponteiro "pu" o end. da variavel "d".

Para se obter o valor armazenado numa variavel atraves do seu ponteiro,
utiliza-se o operador de conteudo "*" (asterisco), obtendo como resultado o
conteudo da variavel apontada pelo ponteiro.

O formato geral e':
		variavel = *ponteiro;

Olhando a figura inicial temos:
	k = *p;	 atribui a "k" o conteudo da variavel apontada por "p"
                 Em outras palavras atribui a "k" o conteudo de "f"
                 que e' a letra "i".

Exemplos:

Buscando os conteudos das variaveis atraves dos seus ponteiros.
	w = *pc;   atribui a "w" o conteudo da variavel "a" que e'"p"
	x = *pi;   atribui a "x" o conteudo da variavel "b" que e'"700"
	y = *pf;   atribui a "y" o conteudo da variavel "c" que e'"9.777"
	z = *pu;   atribui a "z" o conteudo da variavel "d" que e'"4000000007"

Exemplo com variaveis simples:*/

#ifdef ex1
main()
{
char *pc,a,w;
int *pi,b,x;
float *pf,c,y;
unsigned long *pu,d,z;

a = 'p';
b = 700;
c = 9.777;
d = 4000000007;

pc = &a;    /*atribui ao ponteiro "pc" o end. da variavel "a".*/
pi = &b;    /*atribui ao ponteiro "pi" o end. da variavel "b".*/
pf = &c;    /*atribui ao ponteiro "fl" o end. da variavel "c".*/
pu = &d;    /*atribui ao ponteiro "pd" o end. da variavel "d".*/

w = *pc;   /*atribui a "w" o conteudo da variavel "a" que e'"p"*/
x = *pi;   /*atribui a "x" o conteudo da variavel "b" que e'"700"*/
y = *pf;   /*atribui a "y" o conteudo da variavel "c" que e'"9.777"*/
z = *pu;   /*atribui a "z" o conteudo da variavel "d" que e'"4000000007"*/

printf("exibe o conteudo da variavel a '%c' \n",a);
printf("exibe o conteudo da variavel b '%d' \n",b);
printf("exibe o conteudo da variavel c '%f' \n",c);
printf("exibe o conteudo da variavel d '%lu' \n\n",d);

printf("exibe o conteudo da variavel direto atraves do ponteiro '%c'\n",*pc);
printf("exibe o conteudo da variavel direto atraves do ponteiro '%d'\n",*pi);
printf("exibe o conteudo da variavel direto atraves do ponteiro '%f'\n",*pf);
printf("exibe o conteudo da variavel direto atraves do ponteiro '%lu'\n\n",*pu);

printf("exibe o conteudo da var. w que recebeu o dado via ponteiro '%c'\n",w);
printf("exibe o conteudo da var. x que recebeu o dado via ponteiro '%d'\n",x);
printf("exibe o conteudo da var. y que recebeu o dado via ponteiro '%f'\n",y);
printf("exibe o conteudo da var. z que recebeu o dado via ponteiro '%lu'\n",z);

}
#endif

#ifdef ex2
main ()
{
int num;
int *p;

num = 55;
p = &num;          /* atribui o endereco da variavel "num" ao ponteiro "p"*/

printf ("\nValor inicial: %d\n",num);
*p = 100;     /* atribui o valor 100 a variavel "num" atraves do ponteiro "p"*/
printf ("\nValor final: %d\n",num);

}
#endif

#ifdef ex3
main()
{
int rx;
int *p;

rx = 200;
p = &rx;          /* atribui o endereco da variavel "rx" ao ponteiro "p"*/


printf ("\nValor inicial: %d\n",rx);
printf("digite um valor inteiro: ");
scanf("%d",p);   /*recebe via teclado um numero inteiro usando o ponteiro "p"*/
getchar();
printf ("\nO valor recebido via teclado e': %d ou %d\n",*p,rx);

}
#endif

/*
4. Ponteiros para estruturas

Podemos utilizar ponteiros para estruturas assim como usamos para variaveis
simples(int,char,...). Uma estrutura e' um tipo de dado como os outros, por isso
tambem podemos utilizar ponteiros para elas.

Para declarar um ponteiro para uma estrutura usa-se o seguinte formato:
	struct nome da estrutura *nome da variavel;

Exemplo:
    struct data *pc;  declara um ponteiro "pc" para a estrutura de nome "data"

Para atribuir-se o endereco de uma estrutura de dados a um ponteiro utiliza-se
tambem o operador de endereco "&" (E comercial) no seguinte formato:
	ponteiro = &nome_variavel;

Exemplo:
	pc = &calendario;

Fazendo uma analogia com a atribuicao do endereco das variaveis simples com
a mesma declaracao para estruturas, observa-se que sao iguais. Vamos a um
exemplo que mostra isso.

variaveis simples
   int *pa, x;     declara um ponteiro "pa" e uma variavel "x" do tipo "int"
   pa = &x;        atribui o endereco da variavel "x" ao ponteiro "pa"

estruturas
struct data *pc, calendario;     declara um ponteiro "pc" e uma variavel
                                 "calendario" do tipo "struct data"
pc = &calendario;  atribui o endereco da variavel "calendario" ao ponteiro "pc"

A diferenca aparece na busca dos dados na variavel. No caso das variaveis
simples buscamos assim:
	y = *pa;    atribui o conteudo apontado por "pa" a variavel "y"

Para as estruturas alem do ponteiro temos que acessar o membro da estrutura.
Para isso utiliza-se o mesmo operador ponto(.) usado para acessar os membros de
uma estrutura.

O formato geral e':
	(*ponteiro).membro;

Exemplo:
        y = (*pc).dia;   atribui o conteudo apontado por "pc" do membro "dia" a
                         variavel "Y"

Nesta declaracao e' necessario utilizar o operador parenteses "()" pois o
operador ponto "." tem maior prioridade que o operador de conteudo "*".

Exemplo:*/

#ifdef ex4
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9];
	};

struct data calendario = {7,9,1822,250,"setembro"};

main()
{
struct data *pc;


pc = &calendario;/*atribui o endereco da variavel"calendario"ao ponteiro "pc"*/

printf("\nProclamacao da Independencia: ");
printf("%d/",(*pc).dia);
printf("%d/",(*pc).mes);
printf("%d - ",(*pc).ano);
printf("%d - ",(*pc).dia_ano);
printf("%s\n",(*pc).nome_mes);

}
#endif
#ifdef ex4a
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9];
	};

struct data calendario;

main()
{
struct data *pc;

pc = &calendario;/*atribui o endereco da variavel"calendario"ao ponteiro "pc"*/

printf("\nDigite a data da Proclamacao da Independencia: \n");
scanf("%d",&(*pc).dia);
scanf("%d",&(*pc).mes);
scanf("%d",&(*pc).ano);
scanf("%d",&(*pc).dia_ano);
scanf("%s",&(*pc).nome_mes[0]);

printf("\nProclamacao da Independencia: ");
printf("%d/",(*pc).dia);
printf("%d/",(*pc).mes);
printf("%d - ",(*pc).ano);
printf("%d - ",(*pc).dia_ano);
printf("%s\n",(*pc).nome_mes);

}
#endif
/*
Mas raramente encontramos referencias feitas a um membro de uma estrutura com o
uso explicito do operador de conteudo "*". O acesso a um membro de uma estrutura
por meio de um ponteiro e' tão comum, que um operador especial foi definido pela
linguagem C para realiza esta tarefa. Ele é o operador seta "->". Este operador
e' formado utilizando-se o sinal de menos(-) seguido do sinal de maior que(>).
O operador seta "->" e' usada no lugar do operador ponto "." para se acessar
um membro da estrutura utilizando ponteiro.

O formato geral e':
	ponteiro -> membro;

Exemplo:*/

#ifdef ex5
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9];
	};

main()
{
struct data *pc;

static struct data calendario = {15,11,1889,319,"novembro"};

pc = &calendario;

printf("\nProclamacao da republica: ");
printf("%d/",pc->dia);
printf("%d/",pc->mes);
printf("%d - ",pc->ano);
printf("%d - ",pc->dia_ano);
printf("%s\n",pc->nome_mes);

}
#endif
#ifdef ex5a
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9];
	};

main()
{
struct data *pc;

static struct data calendario;

pc = &calendario;

printf("\nDigite a data da Proclamacao da republica: \n");
scanf("%d",&pc -> dia);
scanf("%d",&pc -> mes);
scanf("%d",&pc -> ano);
scanf("%d",&pc -> dia_ano);
scanf("%s",&pc -> nome_mes[0]);

printf("\nProclamacao da republica: ");
printf("%d/",pc->dia);
printf("%d/",pc->mes);
printf("%d - ",pc->ano);
printf("%d - ",pc->dia_ano);
printf("%s\n",pc->nome_mes);

}
#endif

/*
5. Ponteiros para vetores

E'importante lembra que um vetor e' um conjunto de posicoes contiguas de
memoria ao passo que um ponteiro e' constituido normalmente por 2 ou 4 bytes
que armazena o endereco da variavel apontada.

Para declarar um ponteiro para um vetor usa-se o seguinte formato:

	tipo *nome_variavel;

Exemplo:
	char *pc;	 declara um ponteiro do tipo char de nome "pc"
	int *pi;	 declara um ponteiro do tipo int de nome "pi"
	float *pf;	 declara um ponteiro do tipo float de nome "pf"
	double *pd;	 declara um ponteiro do tipo double de nome "pd"
	struct data *ps; declara um ponteiro do tipo struct data de nome "ps"

Para atribuir-se o endereco a um ponteiro no caso de vetores, utilizamos o
seguinte formato:
		ponteiro = &nome_variavel [n._elemento];

Se compararmos as declaracoes de atribuicao do endereco para os vetores com a
de variaveis simples, observamos que para os vetores acrescenta-se o indice do
elemento do vetor (caracteristica dos vetores).

Exemplo:

variaveis simples
   pc = &a;    atribui ao ponteiro "pc" o end. da variavel "a".

vetores
   pb = &z[0];  atribui o endereco do 1. elemento do vetor "z" ao ponteiro "pb"

A declaracao pb = &z[0] aponta para o elemento de indice[0] do vetor "z". Ora
o elemento de indice[0] do vetor tem o mesmo endereco do vetor "z", que por
sua vez tambem e' um endereco. Portanto, pode-se dizer que pb = z. Esta
declaracao so' e' valida para o elemento de indice "0" do vetor. Pode-se dizer
que esta declaracao e' uma simplificacao de notacao e que sao declaracoes
equivalentes.

Exemplo:
   pb = &z[0];   podemos dizer que esta e' a notacao "por extenso"
   pb = z;       podemos dizer que esta e' a notacao "simplificada"

Para se obter o conteudo de um dos elementos do vetor atraves de seu ponteiro
utiliza-se o mesmo operador de conteudo "*"(asterisco).

O formaro geral e':
	variavel = *ponteiro;

Exemplo:
     y = *pb;   atribui o conteudo apontado por "pb" a variavel "y" ou seja
                o conteudo do 1. elemento do vetor "z", o elemento de indice[0]

Observe que a declaracao para buscar o conteudo de um elemento do vetor atraves
do ponteiro e' igual a declaracao para buscar o conteudo de uma variavel
simples.

Exemplo
*/
#ifdef ex6
main()
{
static int z[5]={1,2,3,4,5}; 	 /* declara um vetor de 5 elementos*/
int *pb;			 /* declara um ponteiro int */
int b;

pb = &z[0];	/* "pb" aponta para o elemento de indice[0] do vetor "z" ou
		   "pb" contem o endereco de z[0] */

b = *pb;	/* o conteudo apontado por "pb" e' atribuido a variavel "b" */
printf("imprime o conteudo de b = %d\n",b);
}
#endif

#ifdef ex7
main()
{
static int z[5]={10,20,30,40,50};  	/* declara um vetor de 5 elementos*/
int *pb;				/* declara um ponteiro int */
int b;

pb = z;	    /* usando o conceito da igualdade de end. -> z[0] equivale a "z"*/

b = *pb;    /* se o conceito da igualdade de end. for verdade,entao o valor
	       atribuido sera' o mesmo do exemplo anterior*/

printf("imprime o conteudo de b = %d\n",b);
}
#endif

#ifdef ex8
int z[5]={100,200,300,400,500};  /* declara um vetor de 5 elementos*/
main()
{
int *pb;	/* declara um ponteiro int */
int b;

for(b=0;b <5 ;b++)
	{
	pb = &z[b];	/* atribui ao ponteiro "pb" o end. de cada
			   um dos elementos do vetor "z" */
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,*pb);
	}
}
#endif

#ifdef ex9
main()
{
static char z[16]="teste de string";
char *px;
int b;

for(b=0;b <15 ;b++)
	{
	px = &z[b];	/* atribui ao ponteiro "px" o end. de cada
			   um dos elementos do vetor "z" */

	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*px);
	}

px = &z[0];	/* atribui ao ponteiro "px" o end. do 1. elemento do vetor "z"*/

printf("\nOutra forma de exibir a string: %s \n",px);
}
#endif

#ifdef ex10
main()
{
int z[5];   		/* declara um vetor de 5 elementos*/
int *pk;		/* declara um ponteiro int */
int b;


for(b=0;b <5 ;b++)
	{
	pk = &z[b];	/* atribui ao ponteiro "pk" o end. de cada
			   um dos elementos do vetor "z" */
	printf("\nDigite o %d elemento do vetor z. Um numero: ",b+1);
	scanf("%d",pk);
	getchar();
	}
for(b=0;b <5 ;b++)
	{
	pk = &z[b];	/* atribui ao ponteiro "pk" o end. de cada
			   um dos elementos do vetor "z" */
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,*pk);
	}
}
#endif

#ifdef ex11
main()
{
char z[5];   		/* declara um vetor de 5 elementos*/
char *p;		/* declara um ponteiro int */
int b;

for(b=0;b <5 ;b++)
	{
	p=&z[b];	/* atribui ao ponteiro "p" o end. de cada
			   um dos elementos do vetor "z" */
	printf("\nDigite o %d elemento do vetor z. Uma letra: ",b+1);
	scanf("%c",p);
	getchar();
	}
for(b=0;b <5 ;b++)
	{
	p=&z[b];	/* atribui ao ponteiro "p" o end. de cada
			   um dos elementos do vetor "z" */
	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*p);
	}
p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/

printf("\noutra forma de exibir a string: %s \n",p); /*atencao na impressao*/
}
#endif

/*
6. Vetor de ponteiros

Como os ponteiros sao variaveis como as outras pode-se tambem montar vetor de
ponteiros. Este tipo de construcao normalmente e' usada para enderecar string.
O ponteiro aponta para o end. o 1. elemento da string(elemento de indice 0).

O vetor de ponteiros e' util quando se trabalha com informacoes de tamanho
diferente.

O formato para declaracao de um vetor de ponteiros e':
	tipo *nome_variavel[n._elementos];

onde "tipo" indica o tipo da variavel (int, char, estrutura, etc..)
e "nome_variavel" contem os ponteiros (enderecos) do vetor apontado, com o
tamanho definido por "n._elementos".

exemplos:
	char *pc[5];		vetor de ponteiros para caracter
	int *pont[10];		vetor de ponteiros para inteiro
	float *fl[20];		vetor de ponteiros para pto. flut.
	struct data *prt[30];	vetor de ponteiros para estruturas

Para atribuir o endereco de uma variavel a um elemento de um vetor de ponteiros
utiliza-se o seguinte formato:
		ponteiro [n._elemento] = &nome_variavel;

exemplo:
	p[2]=&x;	atribui ao 3. elementos do vetor de ponteiros
			"p" o end. da variavel "x"

Para se obter o conteudo apontado por um dos elementos do vetor de ponteiros
utiliza-se o seguinte forma:
		*ponteiro[indice]; para variavel simples
e
		ponteiro[indice];  para serie de caracteres(string)

Lembrando que os elementos de um vetor de ponteiros somente pode conter
endereco de variaveis.

Exemplo com vetor de ponteiros:
*/
#ifdef ex12
	char a = 'Z';
	char b = 'Y';
	char c = 'X';
	char d = 'W';
	char e = 'V';
main()
{
int x;
char *pz[5];	/* declara um vetor de ponteiros */

	pz[0] = &a;  /*atribui o endereco da variavel simples*/
	pz[1] = &b;
	pz[2] = &c;
	pz[3] = &d;
	pz[4] = &e;

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. Elemento do vetor z = %c\n",x,*pz[x]);
	}
}
#endif
#ifdef ex12a
main()
{
int *pz[4];	/* declara um vetor de ponteiros */
int z[4] = {10, 20, 30, 40};

        pz[0] = &z[0];  /*atribui o endereco da variavel simples*/
	pz[1] = &z[1];
	pz[2] = &z[2];
	pz[3] = &z[3];


//Escreve na tela
printf("%d\n", *pz[0]);
printf("%d\n", *pz[1]);
printf("%d\n", *pz[2]);
printf("%d\n", *pz[3]);

//Recebe via teclado
scanf("%d",pz[0]);       //100 enter
scanf("%d",pz[1]);       //200 enter
scanf("%d",pz[2]);       //300 enter
scanf("%d",pz[3]);       //400 enter

//Escreve na tela
printf("%d\n", *pz[0]);
printf("%d\n", *pz[1]);
printf("%d\n", *pz[2]);
printf("%d\n", *pz[3]);

}
#endif
#ifdef ex13
	char a[] = "erro de digitacao";
	char b[] = "erro de conversao";
	char c[] = "erro de sintaxe";
	char d[] = "erro de declaracao";
	char e[] = "erro de parenteses";
main()
{
int x;
char *pz[5];	/* declara um vetor de ponteiros */

	/*atribui o endereco do vetor de caracteres ao ponteiro*/
	pz[0] = &a[0];	/*"notacao por extenso"*/
	pz[1] = &b[0];
	pz[2] = c;	/*"notacao simplificada"*/
	pz[3] = d;
	pz[4] = e;

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. Elemento do vetor z = %s\n",x,pz[x]);
	}
}
#endif

#ifdef ex14
main()
{
int x;
char *pz[5];
		/* inicializa o vetor de ponteiros */
	pz[0] = "erro de digitacao";
	pz[1] = "erro de conversao";
	pz[2] = "erro de sintaxe";
	pz[3] = "erro de declaracao";
	pz[4] = "erro de parenteses";

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. elemento do vetor z = %s\n",x,pz[x]);
	}
}
#endif

#ifdef ex15
main()
{
int x;
char *pz[5][20];

for(x=0;x <5 ;x++)
	{
	printf("digite a string de indice %d: ",x);
	scanf("%s",pz[x]);
	}

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. elemento do vetor z = %s\n",x,pz[x]);
	}
}
#endif

/*Incializa o vetor de ponteiro atribuindo a serie de caracteres diretamente*/

#ifdef ex16
main()
{
static char *psemana [7] = {  "Domingo" ,
       		              "Segunda-feira",
	                      "Terca-feira",
        	              "Quarta-feira",
                	      "Quinta-feira",
	                      "Sexta-feira",
        	              "Sabado",
                	    };

printf(" Dias da semana \n\n");
printf(" %s\n",psemana [0]);
printf(" %s\n",psemana [1]);
printf(" %s\n",psemana [2]);
printf(" %s\n",psemana [3]);
printf(" %s\n",psemana [4]);
printf(" %s\n",psemana [5]);
printf(" %s\n",psemana [6]);
}
#endif

/*
7. Aritmetica de ponteiros

Com ponteiros pode-se executar um n. limitado de operacao sao elas:

-Atribuir um end. de memoria determinado direto a um ponteiro.

Isto porem e' perigoso quando nao se conhece o hardware e firmware da maquina
que se esta utilizando.

exemplo:
	px=0xf853;     o ponteiro "px" aponta para o end. f853(hexa) da memoria

- Somar e subtrar valores inteiros dos ponteiros

A soma e subtracao so' e' usada para vetores.

Quando se soma um numero inteiro a um ponteiro, equivale a enderecar posicoes
contiguas de memoria  ou seja, fazer a multiplicacao do numero inteiro pelo
numero de bytes do tipo do ponteiro e somar ao endereco guardado no ponteiro.
Esta e' a razao porque o tipo do ponteiro tem que ser igual ao tipo da variavel
que ele aponta.

Usando este conceito e' usual se atribuir o endereco do 1. elemento do vetor ou
elemento de indice "0" ao ponteiro que sera' utilizado como referencia para
acessar aos demais elementos.

Relembrando: O formato para acessar o conteudo dos elementos de um vetor como
vimos no capitulo de vetores e':
	nome da variavel[indice];

O formato para acessar este mesmo conteudo utilizando o ponteiro e aritmetica
de ponteiros e':
	*(ponteiro + indice);

E temos mais uma forma para acessar o conteudo deste mesmo elemento usando
ponteiros que e':
	ponteiro[indice];

Esta forma e' possivel por que se o ponteiro aponta para um elemento no vetor
e o indice soma o numero de elementos para o qual se quer aponta, lembrando
que o ponteiro leva em conta o tipo de variavel apontada, entao esta expressão
e' equivale a expressao da aritmetica de ponteiro.

Exemplos:
*/
#ifdef ex17
main()
{
static int z[5]={1000,2000,3000,4000,5000};/* declara um vetor de 5 elementos*/
int *p;		/* declara um ponteiro int */
int b;

p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/

for(b=0;b <5 ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,*(p+b));
	}
}
#endif

#ifdef ex18
main()
{
static int z[5]={6000,7000,8000,9000,10000};
int *p;
int b;

p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/
for(b=0;b <5 ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,p[b]);
	}
}
#endif

#ifdef ex19
main()
{
static char z[16]="teste de string";
char *p;
int b;

p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/

for(b=0;b <15 ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*(p+b));
	}
printf("\noutra forma de exibir a string: %s \n",p);
}
#endif

#ifdef ex20
main()
{
static char *p ="string com ponteiro";
int b;

for(b=0; p[b] != '\0' ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*(p+b));
	}
printf("\noutra forma de exibir a string: %s \n",p);
}
#endif

/****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa que receba via teclado usando ponteiros um char, 
    int, long, unsigned,float, double, unsigned long e unsigned char, 
    e imprima-os no video utilizando ponteiros e o operador de conteudo * 
    no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char

2 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados pelo teclado usando ponteiros e imprima-os no video
    também usando ponteiros. Utilize um comando de loop. (vetor de estruturas)
              nome, end, cidade, estado, cep

3 - Receba um caracter via teclado usando ponteiros e compara com o vetor abaixo
    usando ponteiros. Mostre como resultado se são EXISTE ou NAO EXISTE.
    vetor -> b,d,f,h,j,l,m,o,q,s,u,w,y

4 - Receba 2 string de ate 10 caracteres via teclado, compare-as usando ponteiros
    e mostre como resultado se são IGUAIS ou DIFERENTES.

5 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser 
    feitos usando ponteiro.

6 - Escreva um programa que contenha uma estrutura representando uma data
    valida. Essa estrutura deve conter os campos dia, mes e ano. Em seguida,
    leia duas datas e armazene nessa estrutura usando ponteiros. Calcule e exiba o
    numero de dias que decorreram entre as duas datas usando ponteiros.
*/
