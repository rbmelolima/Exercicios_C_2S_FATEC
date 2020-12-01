#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ex6

#ifdef ex1
struct Date
{
  char c;
  int i;
  long l;
  float f;
  double d;
  unsigned char uc;
  unsigned int ui;
  unsigned long ul;
};
struct data dados;

void main()
{
  int running = 1;

  while (running == 1)
  {
    struct data *p;
    p = &dados;

    printf("Digite um int: ");
    scanf("%i", &p->i);

    printf("Digite um long int: ");
    scanf("%li", &p->l);

    printf("Digite um unsigned int: ");
    scanf("%u", &p->ui);

    printf("Digite um float: ");
    scanf("%f", &p->f);

    printf("Digite um double: ");
    scanf("%lf", &p->d);

    printf("Digite um char: ");
    scanf(" %c", &p->c);

    printf("Digite um unsigned long int: ");
    scanf("%lu", &p->ul);

    printf("Digite um unsigned char: ");
    scanf(" %c", &p->uc);

    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-6i              %-11li         %-5u\n", p->i, p->l, p->ui);
    printf("              %-6f            %-7lf            %-4c\n", p->f, p->d, p->c);
    printf("         %-10lu          %-3c\n", p->ul, p->uc);
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex2
struct adressUser
{
  char name[60];
  char adress[60];
  char city[60];
  char state[60];
  char cep[8];
};

void main()
{
  int running = 1;

  struct adressUser users[4];
  struct adressUser *p_users = &users;

  while (running == 1)
  {

    for (int i = 0; i < 4; i++)
    {
      printf("\n\nNome (%d): ", i + 1);
      scanf("%s", p_users[i].name);

      printf("CEP (%d): ", i + 1);
      scanf("%s", p_users[i].cep);

      printf("Estado (%d): ", i + 1);
      scanf("%s", p_users[i].state);

      printf("Cidade (%d): ", i + 1);
      scanf("%s", p_users[i].city);

      printf("Endereco (%d): ", i + 1);
      scanf("%s", p_users[i].adress);
    }

    system("cls");

    for (int i = 0; i < 4; i++)
    {
      printf("\n\nUsuario %d\n", i + 1);
      printf("\nNome (%d): %s", i + 1, p_users[i].name);
      printf("\nCEP (%d): %s", i + 1, p_users[i].cep);
      printf("\nEstado (%d): %s", i + 1, p_users[i].state);
      printf("\nCidade (%d): %s", i + 1, p_users[i].city);
      printf("\nEndereco (%d): %s", i + 1, p_users[i].adress);
    }

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex3
void main()
{
  int running = 1;
  char alphabet[13] = {'b', 'd', 'f', 'h', 'j', 'l', 'm', 'o', 'q', 's', 'u', 'w', 'y'};

  char letter;
  char *p_letter = &letter;

  while (running == 1)
  {
    int isEqual = 0;

    printf("\n\nDigite uma letra: ");
    scanf("%s", p_letter);

    for (int i = 0; i < 13; i++)
    {
      if (*p_letter == alphabet[i])
      {
        printf("IGUALDADE");
        isEqual = 1;
        break;
      }
    }

    if (isEqual == 0)
    {
      printf("DESIGUALDADE");
    }

    printf("\n\nDeseja continuar? (1) Sim (0) Nao: ");
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
    char string1[10];
    char string2[10];
    char *p1;
    char *p2;
    int i;

    printf("Digite a 1 string: ");
    scanf("%s", string1);

    printf("Digite a 2 string: ");
    scanf("%s", string2);

    p1 = string1;
    p2 = string2;

    for (i = 0; i < 9; i++)
    {
      if ((int)p1[i] == 0 && (int)p2[i] == 0)
      {
        break;
      }
      if (p1[i] != p2[i])
      {
        printf("As strings sao diferentes!");
        return 0;
      }
    };
    printf("As strings sao iguais!");
    printf("\n\nDeseja continuar? (1) Sim (0) Nao: ");
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
    int sum = 0, count = 0, number = 0;
    int *p_number = &number;
    float media = 0;

    while (p_number >= 0)
    {
      printf("Digite um numero positivo: ");
      scanf("%d", p_number);

      sum += *p_number;
      count++;
    }

    media = sum / count;

    printf("Media: %.2f", media);

    printf("\n\nDeseja continuar? (1) Sim (0) Nao: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex6

struct Date
{
  int day;
  int month;
  int year;
} ;

int bissexto(int ano);
unsigned long difference(struct Date *inicio, struct Date *fim);

int daysInMonth[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

void main()
{
  int running = 1;

  while (running == 1)
  {
    struct Date date1, date2;

    printf("Data inicial (dd/mm/aa): ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);

    printf("Data final (dd/mm/aa): ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    printf("\nDiferença de dias: %lu\n", difference(&date1, &date2));

    printf("\n\nDeseja continuar? (1) Sim (0) Nao: ");
    scanf("%d", &running);
    system("cls");
  }
}

int leapYear(int year)
{
  //Retorna 1 caso 'ano' seja bissexto, senão, 0
  return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

unsigned long difference(struct Date *start, struct Date *end)
{
  unsigned long IDays, FDays;
  unsigned long diff = 0;

  register int i;
  int dayLeap;

  IDays = start->day;
  dayLeap = leapYear(start->year);

  for (i = start->month - 1; i > 0; --i)
  {
    IDays += daysInMonth[dayLeap][i];
  }

  FDays = end->day;
  dayLeap = leapYear(end->year);

  for (i = end->month - 1; i > 0; --i)
  {
    FDays += daysInMonth[dayLeap][i];
  }

  while (start->year < end->year)
  {
    diff += 365 + leapYear(start->year++);
  }

  return diff - IDays + FDays;
}
#endif
