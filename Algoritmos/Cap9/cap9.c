#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ex3

#ifdef ex1
struct data {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

void insertValues(struct data *p){
    printf("Digite um char: ");
    scanf("%c",&p -> c);

    printf("Digite um int: ");
    scanf("%d",&p -> i);

    printf("Digite um long int: ");
    scanf("%li",&p -> l);

    printf("Digite um float: ");
    scanf("%f",&p -> f);

    printf("Digite um double: ");
    scanf("%lf",&p -> d);

    printf("Digite um unsigned char: ");
    scanf(" %c",&p -> uc);

    printf("Digite um unsigned int: ");
    scanf("%u",&p -> ui);

    printf("Digite um unsigned long int: ");
    scanf("%lu",&p -> ul);
}

void printValues(struct data *p){
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-4c      %-6i    %-11li         %-6f            %-7lf\n", p -> c, p -> i, p -> l, p -> f, p -> d);
    printf("         %-3c                 %-5u               %-10lu\n", p -> uc, p -> ui, p -> ul);
}

void main()
{
  int running = 1;

  while (running == 1)
  {
    struct data dados;
    struct data *p;
    p = &dados;

    insertValues(p);
    printValues(p);

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex2

void soma(float *n, float *nA){
    *n = *n + *nA;
}

void subtracao(float *n, float *nA){
    *n = *n - *nA;
}

void multiplicacao(float *n, float *nA){
    *n = *n * *nA;
}

void divisao(float *n, float *nA){
    *n = *n / *nA;
}

void numeros(float *n, float *nA, char *o){
    if(*n != 0){
        if(*o == '+'){
            soma(n, nA);
        }
        else if(*o == '-'){
            subtracao(n, nA);
        }
        else if(*o == '*'){
            multiplicacao(n, nA);
        }
        else if(*o == '/'){
            divisao(n, nA);
        }
    }
    else{
        *n = *nA;
    }
}

void main()
{
  int running = 1, cont = 0;
  char operacao = "+";
  float numero = 0, numeroAtual;


  while (running == 1)
  {
    do{
      if(cont == 0 || cont == 2){
        printf("Digite um numero: ");
        scanf("%f", &numeroAtual);
        numeros(&numero, &numeroAtual, &operacao);
        cont = 1;
      }
      else{
        printf("Digite uma operacao (+, -, *, / ou =): ");
        getchar();
        operacao = getchar();
        cont = 2;
      }
    }while(operacao != '=');
    system("cls");
    printf("\nResultado final: %-2f", numero);
    
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex3
int find(char *listLetters, char* letter) {
	int i;
	for (i = 0; listLetters[i] != '\0' && i < 14; i++) {
		
		if (listLetters[i] == *letter) {
		  	return i;
		}
	}
	return -1;
}

void main() {
  int running = 1;

  char listLetters[] = {"bdfhjkmoqsuwv"};
  char letter;

  while (running == 1) {
    printf("Digite uma letra: ");
    
	letter = getchar();
	if(letter == '\n'){
		letter = getchar();
	}

	int posicao = find(&listLetters, &letter);
    if (posicao != -1) {
      printf("\nA letra foi encontrada na posicao %i!\n", posicao);
    }

    else {
      printf("\nA letra nao foi encontrada!\n");
    }

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex4
void main()
{
  int running = 1;

  while (running == 1)
  {
    
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex5
void main()
{
  int running = 1;

  while (running == 1)
  {
    
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex6
void main()
{
  int running = 1;

  while (running == 1)
  {
    
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif