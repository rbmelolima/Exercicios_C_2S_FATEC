#include <stdio.h>
#include <stdbool.h>

#define ex5

#ifdef ex1
char letras[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
int pesquisa(char letra);

void main()
{
  int running = 1;
  int retorno;
  char l;
  while(running == 1){
    printf("Digite uma letra para pesquisa-la no vetor: ");
    scanf(" %c", &l);
    retorno = pesquisa(l);
    if(retorno == -1){
      printf("\nEsta letra nao existe no vetor!");
    }
    else{
      printf("\nEsta letra esta na posicao %d do vetor!", retorno);
    }
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}

int pesquisa(char letra){
  int i;
  int retorno = -1;
  if ((int)letra >= 65 && (int)letra <= 90)
  {
      letra = ((int)letra) - 32;
  }
  
  for(i = 0; i < 13; i++){
    if(letras[i] == letra){
      retorno = i;
      break;
    }
  }
  return(retorno);
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

#ifdef ex5
char string1[11];
char string2[11];

int comparar(char *var1, char *var2);

void main()
{
  int running = 1;

  while(running == 1){
    printf("Digite uma string via teclado de ate 10 caracteres: ");
    gets(string1);
    printf("\nDigite uma outra string via teclado de ate 10 caracteres: ");
    gets(string2);
    printf("\nResposta: %d", comparar(string1, string2));
    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
    getchar();
  }
}
int comparar(char *var1, char *var2){
  int iguais = 1;
  int i;
  for (i = 0; i < 11; i++)
  {
    if(var1[i] != var2[i]){
      iguais = 0;
      break;
    }
  }
  return(iguais);
}
#endif