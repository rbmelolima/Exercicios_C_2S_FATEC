#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ex3

#ifdef ex1
void main()
{
  int running = 1;
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
  
  while(running == 1){
    printf("Digite um char: ");
    scanf("%c",&dados.c);

    printf("Digite um int: ");
    scanf("%i",&dados.i);

    printf("Digite um long int: ");
    scanf("%li",&dados.l);

    printf("Digite um float: ");
    scanf("%f",&dados.f);

    printf("Digite um double: ");
    scanf("%lf",&dados.d);

    printf("Digite um unsigned char: ");
    scanf(" %c",&dados.uc);

    printf("Digite um unsigned int: ");
    scanf("%u",&dados.ui);

    printf("Digite um unsigned long int: ");
    scanf("%lu",&dados.ul);

    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-4c      %-6i    %-11li         %-6f            %-7lf\n", dados.c, dados.i, dados.l, dados.f, dados.d);
    printf("          %-3c                 %-5u               %-10lu", dados.uc, dados.ui, dados.ul);
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
    struct ponto{
        float X;
        float Y;
    };

    float calculaDistancia(struct ponto p){
        float d;
        d = sqrt( pow(p.X, 2) + pow(p.Y, 2) );
        return(d);
    }

    void main()
    {
        int running = 1;
        double distancia;
        struct ponto pont;
        while(running == 1){
            printf("Digite a coordenada X do ponto: \n");
            scanf("%f",&pont.X);
            system("cls");
            printf("Digite a coordenada Y do ponto: \n");
            scanf("%f",&pont.Y);
            system("cls");
            distancia = calculaDistancia(pont);
            printf("\nA distancia do ponto (%f, %f) ate a origem e %f \n", pont.X, pont.Y, distancia );
            printf("\n\nDeseja continuar? (1) Sim (0) Nao: ");
            scanf("%d", &running);
            system("cls");
        }
    }
#endif
