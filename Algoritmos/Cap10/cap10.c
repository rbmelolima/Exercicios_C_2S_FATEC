#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
  struct data dados;
  struct data* p;
  p = &dados;

  insertValues(p);
  printValues(p);
}
#endif

#ifdef ex2
void main() {
  int running = 1;

  while (running == 1) {

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex3
struct product {
  char id[9];
  char description[255];
  char quantity[3];
};

char filename[] = "produtos.txt";

void add(struct product* value) {
  FILE* pFile;
  pFile = fopen(filename, "a");

  if ((pFile = fopen(filename, "a")) == NULL) {
    printf("Erro na abertura do arquivo :( \n");
    exit(0);
  }

  printf("\nDigite o codigo do produto: ");
  gets(&value->id);

  printf("\nDigite a descricao do produto: ");
  gets(value->description);

  printf("\nDigite a quantidade do produto: ");
  gets(&value->quantity);

  fwrite(value, sizeof(struct product), 1, pFile);
  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void index(struct product* value) {
  FILE* pFile;
  pFile = fopen(filename, "r");

  if ((pFile = fopen(filename, "r")) == NULL) {
    printf("Erro na abertura do arquivo :( \n");
    exit(0);
  }

  fread(value, sizeof(struct product), 1, pFile);

  while (!feof(pFile)) {
    if (value->id != NULL && value->description[0] != '\0') {
      printf("\tID: %s   Desc: %s   Quantidade: %s\n", value->id, value->description, value->quantity);
    }

    fread(value, sizeof(struct product), 1, pFile);
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void update(struct product* value) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char searchID[9];

  printf("\n\nPesquisar pelo ID: ");
  gets(searchID);

  int finded = 0;
  int index = -1;

  fread(value, sizeof(struct product), 1, pFile);

  while (!feof(pFile)) {
    if (value->id != NULL) {
      index++;

      for (int j = 0; j < 21 && (searchID[j] != '\0' || value->id[j] != '\0'); j++) {
        if (searchID[j] == value->id[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\tID: %s   Desc: %s   Quantidade: %s\n", value->id, value->description, value->quantity);
        break;
      }
    }

    fread(value, sizeof(struct product), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  else {
    printf("\nDigite o codigo do produto: ");
    gets(&value->id);

    printf("\nDigite a descricao do produto: ");
    gets(value->description);

    printf("\nDigite a quantidade do produto: ");
    gets(&value->quantity);

    pFile = fopen(filename, "r+");

    fseek(pFile, sizeof(struct product) * index, 0);
    fwrite(value, sizeof(struct product), 1, pFile);
    fclose(pFile);
  }

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void updateQuantity(struct product* value) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char searchID[9];

  printf("\n\nPesquisar pelo ID: ");
  gets(searchID);

  int finded = 0;
  int index = -1;

  fread(value, sizeof(struct product), 1, pFile);

  while (!feof(pFile)) {
    if (value->id != NULL) {
      index++;

      for (int j = 0; j < 21 && (searchID[j] != '\0' || value->id[j] != '\0'); j++) {
        if (searchID[j] == value->id[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\tID: %s   Desc: %s   Quantidade: %s\n", value->id, value->description, value->quantity);
        break;
      }
    }

    fread(value, sizeof(struct product), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  else {
    printf("\nDigite a quantidade do produto: ");
    gets(&value->quantity);

    pFile = fopen(filename, "r+");

    fseek(pFile, sizeof(struct product) * index, 0);
    fwrite(value, sizeof(struct product), 1, pFile);
    fclose(pFile);
  }

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void cleanArrayChar(char* p, int size) {
  int i;
  for (i = 0; i < size; i++) {
    p[i] = '\0';
  }
}

void delete(struct product* value) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char searchID[9];

  printf("\n\nPesquisar pelo ID: ");
  gets(searchID);

  int finded = 0;
  int index = -1;

  fread(value, sizeof(struct product), 1, pFile);

  while (!feof(pFile)) {
    if (value->id != NULL) {
      index++;

      for (int j = 0; j < 21 && (searchID[j] != '\0' || value->id[j] != '\0'); j++) {
        if (searchID[j] == value->id[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\tID: %s   Desc: %s   Quantidade: %s\n", value->id, value->description, value->quantity);
        break;
      }
    }

    fread(value, sizeof(struct product), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  else {
    pFile = fopen(filename, "r+");

    cleanArrayChar(&value->id, 9);
    cleanArrayChar(&value->quantity, 3);
    cleanArrayChar(&value->description, 255);

    fseek(pFile, sizeof(struct product) * index, 0);
    fwrite(value, sizeof(struct product), 1, pFile);
    fclose(pFile);

    printf("\nRegistro deletado!");
    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getch();
  }

}

void searchProduct(struct product* value) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char description[255];

  printf("\n\nPesquisar pela descricao: ");
  gets(description);

  int finded = 0;
  int j = 0;
  int achados = 0;

  fread(value, sizeof(struct product), 1, pFile);

  while (!feof(pFile)) {
    if (value->id != NULL) {
      for (j = 0; j < 255 && (description[j] != '\0' || value->description[j] != '\0'); j++) {
        if (description[j] == value->description[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        achados++;
        printf("\tID: %s   Desc: %s   Quantidade: %s\n", value->id, value->description, value->quantity);
      }
    }

    fread(value, sizeof(struct product), 1, pFile);
  }

  if (achados == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void searchUnavailable(struct product* value) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  
  int finded = 0;
  int j = 0;
  int achados = 0;

  fread(value, sizeof(struct product), 1, pFile);

  while (!feof(pFile)) {
    if (value->id != NULL) {
      for (j = 0; j < 255 && (value->quantity[j] != '\0'); j++) {
        if (value->description[j] == '0' || value->description[j] == "0") {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        achados++;
        printf("\tID: %s   Desc: %s   Quantidade: %s\n", value->id, value->description, value->quantity);
      }
    }

    fread(value, sizeof(struct product), 1, pFile);
  }

  if (achados == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void main() {
  int option = 0;

  struct product products;
  struct product* p;
  p = &products;

  do {
    system("cls");
    printf("********************** \n");
    printf("**** Exercicio 3  **** \n");
    printf("********************** \n");

    printf("\n(01) Incluir produtos");
    printf("\n(02) Alterar produtos");
    printf("\n(03) Excluir produtos");
    printf("\n(04) Pesquisar uma mercadoria pela descricao");
    printf("\n(05) Listar todos os produtos");
    printf("\n(06) Listar os produtos nao disponiveis");
    printf("\n(07) Alterar a quantidade atual de um produto");
    printf("\n(08) Sair");
    printf("\n\n-> Digite sua acao: ");

    scanf("%i", &option);
    getchar();

    switch (option) {
      case 1:
        add(&p);
        break;
      case 2:
        update(&p);
        break;
      case 3:
        delete(&p);
        break;
      case 4:
        searchProduct(&p);
        break;
      case 5:
        index(&p);
        break;
      case 6:
        searchUnavailable(&p);
        break;
      case 7:
        updateQuantity(&p);
        break;
      case 8:
      default:
        exit(0);
        break;
  }

    option = 0;

} while (option == 0);
}
#endif

#ifdef ex4
void main() {
  int running = 1;

  while (running == 1) {

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif