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
struct dados {
  char nome[21];
  char telefone[12];
  char dia[3];
  char mes[3];
};

char filename[] = "lista.txt";

void insert(struct dados* p);
void list(struct dados* p);
void searchName(struct dados* p);
void searchLetter(struct dados* p);
int toInt(char a[]);
void searchBirthday(struct dados* p);
void updateRegister(struct dados* p);
void del(struct dados* p);
void cleanArrayChar(char* p, int size);

main() {
  int menu = 0;

  struct dados usuario;
  struct dados* p;
  p = &usuario;

  do {
    system("cls");
    printf("******************** \n");
    printf("**** EMAIL LIST **** \n");
    printf("******************** \n");
    printf("\n(1) Inserir dados");
    printf("\n(2) Altera contato");
    printf("\n(3) Exclui contato");
    printf("\n(4) Pesquisar um contato pelo nome");
    printf("\n(5) Listar todos os contatos");
    printf("\n(6) Listar os contatos cujo nome inicia com uma letra digitada");
    printf("\n(7) Imprimir os aniversariantes do mes");
    printf("\n(8) Sair");
    printf("\n\n-> Digite sua acao: ");

    scanf("%i", &menu);
    getchar();

    switch (menu) {
      case 1:
        menu = 0;
        insert(p);
        break;
      case 2:
        menu = 0;
        updateRegister(p);
        break;
      case 3:
        menu = 0;
        del(p);
        break;
      case 4:
        menu = 0;
        searchName(p);
        break;
      case 5:
        menu = 0;
        list(p);
        break;
      case 6:
        menu = 0;
        searchLetter(p);
        break;
      case 7:
        menu = 0;
        searchBirthday(p);
        break;
      case 8:
      default:
        exit(0);
        break;
    }

  } while (menu == 0);
}

int toInt(char a[]) {
  int c, sinal, posicao, n;

  if (a[0] == '-') {
    sinal = -1;
  }

  if (sinal == -1) {
    posicao = 1;
  }
  else {
    posicao = 0;
  }

  n = 0;

  for (c = posicao; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sinal == -1) {
    n = -n;
  }

  return n;
}

void insert(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "a");

  printf("\n\nDigite o nome: ");
  gets(&p->nome[0]);

  printf("Digite o telefone: ");
  gets(&p->telefone[0]);

  printf("Digite o dia do nascimento: ");
  gets(&p->dia[0]);

  printf("Digite o mes do nascimento: ");
  gets(&p->mes[0]);

  fwrite(p, sizeof(struct dados), 1, pFile);
  fclose(pFile);
}

void list(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");

  printf("\n\tDados atuais:\n");

  while (fread(p, sizeof(struct dados), 1, pFile)) {
    if (p->nome != NULL && p->nome[0] != '\0') {
      printf("\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
    }
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getchar();
}

void searchName(struct dados* p) {

  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j = 0;

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }
        else {
          finded = 0;
          break;
        }
      }
      if (finded != 0) {
        printf("\n\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
      }
    }
    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getchar();
}

void searchLetter(struct dados* p) {

  FILE* pFile;
  pFile = fopen(filename, "r");
  char letter;

  printf("\n\nPesquisar letra: ");
  scanf(" %c", &letter);

  int all = 0;
  int countNotFound = 0;
  int j = 0;

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      all++;
      if (p->nome[0] == letter) {
        printf("\n\t%s - %s - %s/%s", p->nome, p->telefone, p->dia, p->mes);
      }
      else {
        countNotFound++;
      }
    }
    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (all == countNotFound) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getchar();
  getchar();
}

void searchBirthday(struct dados* p) {

  FILE* pFile;
  pFile = fopen(filename, "r");
  int mesPesquisa;

  printf("\n\nPesquisar por mes de aniversario: ");
  scanf("%d", &mesPesquisa);

  int finded = 0;

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      if (mesPesquisa == toInt(p->mes)) { //utilizando função de conversão para comparar com int
        finded++;
        printf("\n\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
      }
    }
    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getchar();
  getchar();
}

void updateRegister(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j = 0;
  int indice = -1;

  fread(p, sizeof(struct dados), 1, pFile);

  while (!feof(pFile)) {
    if (p->nome != NULL) {
      indice++;
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\n\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
        break;
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }

  else {
    printf("\n\nDigite o novo nome: ");
    gets(&p->nome[0]);

    printf("Digite o novo telefone: ");
    gets(&p->telefone[0]);

    printf("Digite o novo dia do nascimento: ");
    gets(&p->dia[0]);

    printf("Digite o novo mes do nascimento: ");
    gets(&p->mes[0]);

    pFile = fopen(filename, "r+");
    fseek(pFile, sizeof(struct dados) * indice, 0);
    fwrite(p, sizeof(struct dados), 1, pFile);
    fclose(pFile);
  }

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getchar();
}

void cleanArrayChar(char* p, int size) {
  int i;
  for (i = 0; i < size; i++) {
    p[i] = '\0';
  }
}

void del(struct dados* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j = 0;
  int indice = -1;

  fread(p, sizeof(struct dados), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      indice++;
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }

        else {
          finded = 0;
          break;
        }
      }

      if (finded != 0) {
        printf("\n\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
        break;
      }
    }

    fread(p, sizeof(struct dados), 1, pFile);
  }

  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
    getchar();
  }

  else {
    pFile = fopen(filename, "r+");

    cleanArrayChar(p->nome, 21);
    cleanArrayChar(p->telefone, 12);
    cleanArrayChar(p->dia, 3);
    cleanArrayChar(p->mes, 3);

    fseek(pFile, sizeof(struct dados) * indice, 0);
    fwrite(p, sizeof(struct dados), 1, pFile);
    fclose(pFile);

    printf("\nRegistro deletado!");
    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getchar();
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
struct pessoa {
  char nome[21];
  char end[51];
  char cidade[51];
  char estado[51];
  char cep[10];
};

char filename[] = "pessoas.txt";

void insert(struct pessoa* p) {
  FILE* pFile;
  pFile = fopen(filename, "a");
  printf("\nDigite o nome da pessoa: ");
  scanf("%s", &p->nome);

  printf("\nDigite o endereco da pessoa: ");
  scanf("%s", &p->end);

  printf("\nDigite a cidade da pessoa: ");
  scanf("%s", &p->cidade);

  printf("\nDigite o estado da pessoa: ");
  scanf("%s", &p->estado);

  printf("\nDigite o cep da pessoa: ");
  scanf("%s", &p->cep);

  fwrite(p, sizeof(struct pessoa), 1, pFile);
  fclose(pFile);
}

void list(struct pessoa* p) {

  FILE* pFile;
  pFile = fopen(filename, "r");

  printf("\n\tDados atuais:\n\n");

  fread(p, sizeof(struct pessoa), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL && p->nome[0] != '\0') {
      printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p->nome, p->end, p->cidade, p->estado, p->cep);
    }
    fread(p, sizeof(struct pessoa), 1, pFile);
  }

  fclose(pFile);

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void search(struct pessoa* p) {
  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j;
  int achados = 0;
  fread(p, sizeof(struct pessoa), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }
        else {
          finded = 0;
          break;
        }
      }
      if (finded != 0) {
        achados++;
        printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p->nome, p->end, p->cidade, p->estado, p->cep);
      }
    }
    fread(p, sizeof(struct pessoa), 1, pFile);
  }
  if (achados == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }
  fclose(pFile);
  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void update(struct pessoa* p) {

  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j;
  int indice = -1;

  fread(p, sizeof(struct pessoa), 1, pFile);

  while (!feof(pFile)) {
    if (p->nome != NULL) {
      indice++;
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }
        else {
          finded = 0;
          break;
        }
      }
      if (finded != 0) {
        printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p->nome, p->end, p->cidade, p->estado, p->cep);
        break;
      }
    }
    fread(p, sizeof(struct pessoa), 1, pFile);
  }
  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }
  else {
    printf("\nDigite o novo nome: ");
    scanf("%s", &p->nome);

    printf("\nDigite o novo endereco: ");
    scanf("%s", &p->end);

    printf("\nDigite a nova cidade: ");
    scanf("%s", &p->cidade);

    printf("\nDigite o novo estado: ");
    scanf("%s", &p->estado);

    printf("\nDigite o novo cep: ");
    scanf("%s", &p->cep);

    pFile = fopen(filename, "r+");
    fseek(pFile, sizeof(struct pessoa) * indice, 0);
    fwrite(p, sizeof(struct pessoa), 1, pFile);
    fclose(pFile);
  }

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void cleanArrayChar(char* p) {
  p[0] = '\0';
}

void delete(struct pessoa* p) {

  FILE* pFile;
  pFile = fopen(filename, "r");
  char nameText[21];

  printf("\n\nPesquisar nome: ");
  gets(nameText);

  int finded = 0;
  int j;
  int indice = -1;

  fread(p, sizeof(struct pessoa), 1, pFile);
  while (!feof(pFile)) {
    if (p->nome != NULL) {
      for (j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
        if (nameText[j] == p->nome[j]) {
          finded++;
        }
        else {
          finded = 0;
          break;
        }
      }
      if (finded != 0) {
        printf("\tNome: %s - Endereco: %s - Cidade: %s - Estado: %s - CEP: %s\n\n", p->nome, p->end, p->cidade, p->estado, p->cep);
        break;
      }
    }

    fread(p, sizeof(struct pessoa), 1, pFile);
  }
  if (finded == 0) {
    printf("\n\tNenhum registro foi encontrado.");
  }
  else {
    pFile = fopen(filename, "r+");

    cleanArrayChar(&p->nome);
    cleanArrayChar(&p->end);
    cleanArrayChar(&p->cidade);
    cleanArrayChar(&p->estado);
    cleanArrayChar(&p->cep);

    fseek(pFile, sizeof(struct pessoa) * indice, 0);
    fwrite(p, sizeof(struct pessoa), 1, pFile);
    fclose(pFile);

    printf("\nRegistro deletado!");
  }

  printf("\n\nPressione qualquer coisa para voltar ao menu... ");
  getch();
}

void main() {
  int menu;
  struct pessoa pessoas[4];

  while (1) {
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

    switch (menu) {
      case 1:
        insert(&pessoas);
        break;
      case 2:
        list(&pessoas);
        break;
      case 3:
        search(&pessoas);
        break;
      case 4:
        update(&pessoas);
        break;
      case 5:
        delete(&pessoas);
        break;
      default:
        exit(0);
        break;
    }
  }
}
#endif
