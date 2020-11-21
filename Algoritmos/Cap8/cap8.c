#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ex1

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
struct data dados;

void main()
{
  int running = 1;
  
  while(running == 1){
    struct data *p;
    p = &dados;

    printf("Digite um int: ");
    scanf("%i",&p -> i);

    printf("Digite um long int: ");
    scanf("%li",&p -> l);

    printf("Digite um unsigned int: ");
    scanf("%u",&p -> ui);

    printf("Digite um float: ");
    scanf("%f",&p -> f);

    printf("Digite um double: ");
    scanf("%lf",&p -> d);

    printf("Digite um char: ");
    scanf(" %c",&p -> c);

    printf("Digite um unsigned long int: ");
    scanf("%lu",&p -> ul);

    printf("Digite um unsigned char: ");
    scanf(" %c",&p -> uc);

    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-6i              %-11li         %-5u\n", p -> i, p -> l, p -> ui);
    printf("              %-6f            %-7lf            %-4c\n", p -> f, p -> d, p -> c);
    printf("         %-10lu          %-3c\n", p -> ul, p -> uc);
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex2
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

#ifdef ex3
void main()
{
  int running = 1;

  while(running == 1){
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
  
  while(running == 1){
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

    for(i = 0; i < 9; i++){
        if((int)p1[i] == 0 && (int)p2[i] == 0){
    		break;
		}
        if(p1[i] != p2[i]){
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
  
  while(running == 1){
    printf("\n\nDeseja continuar? (1) Sim (0) Nao: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex6
void main()
{
  int running = 1;
  
  while(running == 1){
    printf("\n\nDeseja continuar? (1) Sim (0) Nao: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif
