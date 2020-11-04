#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ex3

#ifdef ex1
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
