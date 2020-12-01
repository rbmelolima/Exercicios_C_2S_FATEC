#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ex6

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

  char listLetters[] = { "bdfhjkmoqsuwv" };
  char letter;

  while (running == 1) {
    printf("Digite uma letra: ");

    letter = getchar();
    if (letter == '\n') {
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

void clean(char* pointer, int length) {
  for (int i = 0; i < length; i++) {
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
struct pessoa {
  char nome[21];
  char end[51];
  char cidade[51];
  char estado[51];
  char cep[10];
};

void insert(struct pessoa *p){
  int i;
  for (i = 0; i < 4; i++)
  {
    system("cls");
    
    printf("\nDigite o nome da %i pessoa: ", (i+1));
    scanf("%s", &p[i].nome);

    printf("\nDigite o endereco da %i pessoa: ", (i+1));
    scanf("%s", &p[i].end);

    printf("\nDigite a cidade da %i pessoa: ", (i+1));
    scanf("%s", &p[i].cidade);

    printf("\nDigite o estado da %i pessoa: ", (i+1));
    scanf("%s", &p[i].estado);

    printf("\nDigite o cep da %i pessoa: ", (i+1));
    scanf("%s", &p[i].cep);
  }
}

void list(struct pessoa *p){
	
    int i;
  	for (i = 0; i < 4; i++)
  	{
		if(p->nome[i] != NULL){
	    printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p[i].nome, p[i].end, p[i].cidade, p[i].estado, p[i].cep);
		}
	}
	printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
}

void main() {
  int menu;
  struct pessoa pessoas [4];

  while(1){
    system("cls");

    printf("\n(1) Inserir dados");
    printf("\n(2) Listar dados");
    printf("\n(3) Sair");
    printf("\n\n-> Digite sua acao: ");

    scanf("%i", &menu);
    getchar();

    switch (menu)
    {
      case 1:
        insert(pessoas);
      break;
      case 2:
        list(pessoas);
      break;
      default:
        exit(0);
      break;
    }
  }
}
#endif

#ifdef ex6
struct pessoa {
  char nome[21];
  char end[51];
  char cidade[51];
  char estado[51];
  char cep[10];
};

void insert(struct pessoa *p){
  int i;
  for (i = 0; i < 4; i++)
  {
    system("cls");
    
    printf("\nDigite o nome da %i pessoa: ", (i+1));
    scanf("%s", &p[i].nome);

    printf("\nDigite o endereco da %i pessoa: ", (i+1));
    scanf("%s", &p[i].end);

    printf("\nDigite a cidade da %i pessoa: ", (i+1));
    scanf("%s", &p[i].cidade);

    printf("\nDigite o estado da %i pessoa: ", (i+1));
    scanf("%s", &p[i].estado);

    printf("\nDigite o cep da %i pessoa: ", (i+1));
    scanf("%s", &p[i].cep);
  }
}

void list(struct pessoa *p){
	
  int i;
  for (i = 0; i < 4; i++)
  {
		if(p->nome[i] != NULL){
      printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p[i].nome, p[i].end, p[i].cidade, p[i].estado, p[i].cep);
		}
	}
	printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void search(struct pessoa *p){

  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j;
  int i;
  int achados = 0;
  for (i = 0; i < 4; i++)
  {
    if(p->nome != NULL){
      for(j = 0; j < 21 && (nameText[j] != '\0' || p[i].nome[j] != '\0'); j++) {
        if (nameText[j] == p[i].nome[j]){
          finded++;
        }
        else{
          finded = 0;
          break;
        }
      }
      if(finded != 0){
        achados++;
        printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p[i].nome, p[i].end, p[i].cidade, p[i].estado, p[i].cep);
      }
		}
  }
  if (achados == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }
	printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void update(struct pessoa *p){

  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j;
  int i;
  int achados = 0;
  for (i = 0; i < 4; i++)
  {
    if(p->nome != NULL){
      for(j = 0; j < 21 && (nameText[j] != '\0' || p[i].nome[j] != '\0'); j++) {
        if (nameText[j] == p[i].nome[j]){
          finded++;
        }
        else{
          finded = 0;
          break;
        }
      }
      if(finded != 0){
        achados++;
        printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p[i].nome, p[i].end, p[i].cidade, p[i].estado, p[i].cep);

        printf("\nDigite o novo nome: ");
        scanf("%s", &p[i].nome);

        printf("\nDigite o novo endereco: ");
        scanf("%s", &p[i].end);

        printf("\nDigite a nova cidade: ");
        scanf("%s", &p[i].cidade);

        printf("\nDigite o novo estado: ");
        scanf("%s", &p[i].estado);

        printf("\nDigite o novo cep: ");
        scanf("%s", &p[i].cep);
        break;
      }
		}
  }
  if (achados == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }
	printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void delete(struct pessoa *p){

  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j;
  int i;
  int achados = 0;
  for (i = 0; i < 4; i++)
  {
    if(p->nome != NULL){
      for(j = 0; j < 21 && (nameText[j] != '\0' || p[i].nome[j] != '\0'); j++) {
        if (nameText[j] == p[i].nome[j]){
          finded++;
        }
        else{
          finded = 0;
          break;
        }
      }
      if(finded != 0){
        achados++;
        printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p[i].nome, p[i].end, p[i].cidade, p[i].estado, p[i].cep);
        printf("Registro deletado!");
        p[i].nome[0] = '\0';
        p[i].end[0] = '\0';
        p[i].cidade[0] = '\0';
        p[i].estado[0] = '\0';
        p[i].cep[0] = '\0';
        break;
      }
		}
  }
  if (achados == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }
	printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void main() {
  int menu;
  struct pessoa pessoas [4];

  while(1){
    system("cls");

    printf("\n(1) Inserir dados");
    printf("\n(2) Listar dados");
    printf("\n(3) Procurar dados pelo nome");
    printf("\n(4) Atualizar dados pelo nome");
    printf("\n(5) Excluir dados pelo nome");
    printf("\n(6) Sair");
    printf("\n\n-> Digite sua acao: ");

    scanf("%i", &menu);
    getchar();

    switch (menu)
    {
      case 1:
        insert(pessoas);
      break;
      case 2:
        list(pessoas);
      break;
      case 3:
        search(pessoas);
      break;
      case 4:
        update(pessoas);
      break;
      case 5:
        delete(pessoas);
      break;
      default:
        exit(0);
      break;
    }
  }
}
#endif
