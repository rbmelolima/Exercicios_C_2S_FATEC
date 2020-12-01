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

void insertValues(struct data* p) {
  printf("Digite um char: ");
  scanf("%c", &p->c);

  printf("Digite um int: ");
  scanf("%d", &p->i);

  printf("Digite um long int: ");
  scanf("%li", &p->l);

  printf("Digite um float: ");
  scanf("%f", &p->f);

  printf("Digite um double: ");
  scanf("%lf", &p->d);

  printf("Digite um unsigned char: ");
  scanf(" %c", &p->uc);

  printf("Digite um unsigned int: ");
  scanf("%u", &p->ui);

  printf("Digite um unsigned long int: ");
  scanf("%lu", &p->ul);
}

void printValues(struct data* p) {
  printf("        10        20        30        40        50        60        70\n");
  printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
  printf("    %-4c      %-6i    %-11li         %-6f            %-7lf\n", p->c, p->i, p->l, p->f, p->d);
  printf("         %-3c                 %-5u               %-10lu\n", p->uc, p->ui, p->ul);
}

void main() {
  int running = 1;

  while (running == 1) {
    struct data dados;
    struct data* p;
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
int returnOperation(int* number, char* operation) {
  printf("Operacoes (+, -, /, *, =): ");
  *operation = getchar();

  if (*operation == '=') {
    return 0;
  }

  getchar();

  printf("\nNumero: ");
  scanf("%d", number);

  return 1;
}

void calculate(int* valor, char* operation, int* result) {
  switch (*operation) {
    case '+':
      *result += *valor;
      break;
    case '-':
      *result -= *valor;
      break;
    case '/':
      *result /= *valor;
      break;
    case '*':
      *result *= *valor;
      break;
  }
  getchar();
}

void main() {
  int running = 1;

  while (running == 1) {
    int number = 0, result = 0, run;
    char operation;

    do {
      run = returnOperation(&number, &operation);
      calculate(&number, &operation, &result);
    } while (run == 1);

    printf("Resultado: %d \n", result);

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
int compare(char *p1, char *p2);

main()
{
    int running = 1;
    char string1[11];
    char string2[11];
    char *p1;
    char *p2;
	
    while (running == 1) {
	    printf("Digite a 1 string: ");
	    scanf("%s", string1);

	    printf("Digite a 2 string: ");
	    scanf("%s", string2);

	    p1 = string1;
	    p2 = string2;

	    switch(compare(p1, p2)){
		case 1:
		    printf("1. As strings sao iguais\n");
		break;
		case 2:
		    printf("2. A string 1 e maior que a string 2\n");
		break;
		case 3:
		    printf("3. A string 2 e maior que a string 1\n");
		break;
		case 4:
		    printf("4. As strings tem o mesmo tamanho, mas sao diferentes\n");
		break;
	    }

	    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
	    scanf("%d", &running);
	    system("cls");
    }
}

int compare(char *p1, char *p2){
    int i;
    int result = 1;
    int size = 0;

    for(i = 0; i < 10; i++){
        if(p1[i] != p2[i]){
            result = 0;
        };
        if(p1[i] == '\0' && p2[i] == '\0'){
    		size = 4;
    		break;
		}
		if(p1[i] == '\0' && p2[i] != '\0'){
    		size = 3;
    		break;
		}
		if(p1[i] != '\0' && p2[i] == '\0'){
    		size = 2;
    		break;
		}
    }
    if(result == 1){
        return 1;
    }
    else{
        return size;
    }
}
#endif

#ifdef ex5
void main() {
  int running = 1;

  while (running == 1) {

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex6
void main() {
  int running = 1;

  while (running == 1) {

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif
