#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ex4

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

int find(char* listLetters, char* letter) {
  for (int i = 0; listLetters[i] != '\0' && i < 14; i++) {
    if (listLetters[i] == *letter) {
      return 1;
    }
  }
  return 0;
}

void main() {
  int running = 1;

  char listLetters[] = "bdfhjkmoqsuwv";
  char letter;

  while (running == 1) {
    printf("Digite uma letra: ");
    letter = getchar();

    if (find(&listLetters[0], &letter)) {
      printf("\nA letra foi encontrada!\n");
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
int analysis(char* string1, char* string2) {
  int status = 0;

  for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++) {
    if (string1[i] != string2[i]) {
      status = 4;

      if (string1[i] == '\0' && string2 != '\0') {
        status = 3;
        break;
      }

      else if (string1[i] != '\0' && string2 == '\0') {
        status = 2;
        break;
      }
    }

    else {
      status = 1;
    }
  }

  return status;
}

void displayMessage(int status) {
  switch (status) {
    case 1:
      printf("** As strings sao iguais\n");
      break;
    case 2:
      printf("** A primeira string e maior que a segunda\n");
      break;
    case 3:
      printf("** A segunda string e maior que a primeira\n");
      break;
    case 4:
      printf("** As strings sao diferentes, porem tem o mesmo tamanho\n");
      break;
  }
}

void clean(char *pointer, int length) {
  for(int i = 0; i < length; i++) {
    pointer[i] = "";
  }
}

void main() {
  int running = 1;

  while (running == 1) {

    char string1[20];
    char string2[20];

    clean(string1, 20);
    clean(string2, 20);

    printf("Primeira string: ");
    scanf("%s", &string1);

    printf("Segunda string: ");
    scanf("%s", &string2);

    int status = analysis(&string1[0], &string2[0]);
    displayMessage(status);

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
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