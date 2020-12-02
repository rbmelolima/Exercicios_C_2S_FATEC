#include <stdio.h>
#include <stdbool.h>

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
    struct data dados;
    struct data *p;
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

void insert(struct dados *p);
void list(struct dados *p);
void searchName(struct dados *p);
void searchLetter(struct dados *p);
int toInt(char a[]);
void searchBirthday(struct dados *p);
void updateRegister(struct dados *p);
void del(struct dados *p);
void cleanArrayChar(char *p, int size);

main()
{
    int menu = 0;

    struct dados usuario;
    struct dados *p;
    p = &usuario;

    do
    {
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

        switch (menu)
        {
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

void insert(struct dados *p)
{
    FILE *pFile;
    pFile = fopen(filename, "a");

    printf("\n\nDigite o nome: ");
    gets(&p -> nome[0]);

    printf("Digite o telefone: ");
    gets(&p -> telefone[0]);

    printf("Digite o dia do nascimento: ");
    gets(&p -> dia[0]);

    printf("Digite o mes do nascimento: ");
    gets(&p -> mes[0]);

	fwrite(p, sizeof(struct dados), 1, pFile);
    fclose(pFile);
}

void list(struct dados *p)
{
    FILE *pFile;
    pFile = fopen(filename, "r");

    printf("\n\tDados atuais:\n");

    while (fread(p, sizeof(struct dados), 1, pFile))
    {
        if(p->nome != NULL && p->nome[0] != '\0'){
        	printf("\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
		}
    }

    fclose(pFile);

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getchar();
}

void searchName(struct dados *p) {

    FILE *pFile;
    pFile = fopen(filename, "r");
    char nameText[21];

    printf("\n\nPesquisar nome: ");
    gets(nameText);

    int finded = 0;
    int j = 0;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
        	for(j = 0; j < 21 && (nameText[j] != '\0' || p->nome[j] != '\0'); j++) {
                if (nameText[j] == p->nome[j]){
                    finded++;
                }
                else{
                    finded = 0;
                    break;
                }
            }
            if(finded != 0){
                printf("\n\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
            }
		}
        fread(p, sizeof(struct dados), 1, pFile);
    }

    if(finded == 0) {
        printf("\n\tNenhum registro foi encontrado.");
    }

	fclose(pFile);

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getchar();
}

void searchLetter(struct dados *p) {

    FILE *pFile;
    pFile = fopen(filename, "r");
    char letter;

    printf("\n\nPesquisar letra: ");
    scanf(" %c", &letter);

    int all = 0;
    int countNotFound = 0;
    int j = 0;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
            all++;
            if(p->nome[0] == letter){
                printf("\n\t%s - %s - %s/%s", p->nome, p->telefone, p->dia, p->mes);
            }
            else {
                countNotFound++;
            }
		}
        fread(p, sizeof(struct dados), 1, pFile);
    }

    if(all == countNotFound) {
        printf("\n\tNenhum registro foi encontrado.");
    }

	fclose(pFile);

    printf("\n\nPressione qualquer coisa para voltar ao menu... ");
    getchar();
    getchar();
}

void searchBirthday(struct dados *p) {

    FILE *pFile;
    pFile = fopen(filename, "r");
    int mesPesquisa;

    printf("\n\nPesquisar por mes de aniversario: ");
    scanf("%d", &mesPesquisa);

    int finded = 0;

    fread(p, sizeof(struct dados), 1, pFile);
    while (!feof(pFile))
    {
        if(p->nome != NULL){
            if(mesPesquisa == toInt(p->mes)){ //utilizando função de conversão para comparar com int
                finded++;
                printf("\n\t%s - %s - %s/%s\n", p->nome, p->telefone, p->dia, p->mes);
            }
		}
        fread(p, sizeof(struct dados), 1, pFile);
    }

    if(finded == 0) {
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
    gets(&p -> nome[0]);

    printf("Digite o novo telefone: ");
    gets(&p -> telefone[0]);

    printf("Digite o novo dia do nascimento: ");
    gets(&p -> dia[0]);

    printf("Digite o novo mes do nascimento: ");
    gets(&p -> mes[0]);

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
void main()
{
  int running = 1;
  
  while(running == 1){
    
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
  
  while(running == 1){
    
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif
