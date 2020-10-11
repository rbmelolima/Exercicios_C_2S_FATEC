#include <stdio.h>
#include <stdbool.h>

#define ex4

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
int sum(int n1, int n2){
  return n1 + n2;
}

int subtract(int n1, int n2){
  return n1 - n2;
}

int multiplication(int n1, int n2){
  return n1 * n2;
}

float division(int n1, int n2){
  if(n2 > 0){
    return (float)n1 / (float)n2;
  }

  else {
    return -99999;
  }
}

void main()
{
  int running = 1;
  int number1 = 0, number2 = 0;

  while(running == 1) {

    printf("\nDigite o número 1: ");
    scanf("%d", &number1);

    printf("Digite o número 2: ");
    scanf("%d", &number2);

    printf("\nSoma: %d",          sum(number1, number2));
    printf("\nSubtração: %d",     subtract(number1, number2));
    printf("\nDivisão: %2.2f",     division(number1, number2));
    printf("\nMultiplicação: %d", multiplication(number1, number2));

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}

#endif

#ifdef ex3
int sum(int n1, int n2){
  return n1 + n2;
}

int subtract(int n1, int n2){
  return n1 - n2;
}

int multiplication(int n1, int n2){
  return n1 * n2;
}

float division(float n1, float n2){
  return n1 / n2;
}

void main()
{
  int running = 1;

  while(running == 1){
    int number = 0, stepper = 0;

    int collectorSum = 0;
    int collectorMultiplication = 0;
    int collectorSubtract = 0;
    float collectorDivision = 0;

    printf("** DIGITE 0 PARA SAIR DA ROTINA **\n\n\n");

    do{
      printf("-> Digite um número: ");
      scanf("%d", &number);

      stepper++;

      if(stepper == 1){
        collectorSum = number;
        collectorMultiplication = number;
        collectorSubtract = number;
        collectorDivision = (float)number;
      }

      else if(stepper > 1 && number > 0){
        collectorSum = sum(collectorSum, number);
        collectorMultiplication = multiplication(collectorMultiplication, number);
        collectorSubtract = subtract(collectorSubtract, number);
        collectorDivision = division(collectorDivision, number);
      }
    } while (number > 0);

    printf("\nSoma: %d", collectorSum);
    printf("\nSubtração: %d", collectorSubtract);
    printf("\nDivisão: %2.2f", collectorDivision);
    printf("\nMultiplicação: %d", collectorMultiplication);

    printf("\n\nDeseja continuar? (1) Sim (0) Não: ");
    scanf("%d", &running);
    system("cls");
  }
}
#endif

#ifdef ex4
float calculator(int operation, float n1, float n2){
  switch (operation) {
    case 1:
      return n1 + n2;
    break;

    case 2:
      return n1 - n2;
    break;

    case 3:
      return n1 * n2;
    break;

    case 4:
      return (float)n1 / (float)n2;
    break;

    default:
    break;
  }
}

void main()
{
  int running = 1;

  while(running == 1){
    int number = 0, stepper = 0, operatorCalc;

    float collector = 0;

    printf("** DIGITE 0 PARA SAIR DA ROTINA **\n\n\n");

    printf(" --> Operações aritméticas <-- \n\n(1) Soma\n(2) Subtração\n(3) Multiplicação\n(4) Divisão\n::: ");
    scanf("%d", &operatorCalc);

    do{
      printf("\nDigite um número ::: ");
      scanf("%d", &number);

      stepper++;

      if(stepper == 1){
        collector = (float)number;
      }

      else if(stepper > 1 && number > 0){
        collector = calculator(operatorCalc, collector, number);
      }
    } while (number > 0);

    printf("\nResultado da operação: %2.2f", collector);

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
