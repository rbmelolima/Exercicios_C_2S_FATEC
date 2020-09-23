#include <stdio.h>
#define ex1

#ifdef ex1
main()
{
    int num1, num2, continuar;
    do{
        printf("Digite o primeiro numero inteiro: ");
        scanf("%i", &num1);
        printf("Digite o segundo numero inteiro: ");
        scanf("%i", &num2);

        printf("Soma: %i + %i = %i\n", num1, num2, num1 + num2);
        printf("Subtracao: %i - %i = %i\n", num1, num2, num1 - num2);
        printf("Multiplicacao: %i * %i = %i\n", num1, num2, num1 * num2);
        printf("Divisao: %i / %i = %.1f\n", num1, num2, (float)num1/(float)num2);
        printf("Digite (1) para continuar ou (0) para sair: ");
        scanf("%i", &continuar);
    }while(continuar == 1);

}
#endif

#ifdef ex2
main()
{
    int soma, sub, mult, num1, num2, continuar; float div;
    do{
        printf("Digite o primeiro numero inteiro: ");
        scanf("%i", &num1);
        soma = sub = mult = div = num1;
        printf("Digite o segundo numero inteiro: ");
        scanf("%i", &num2);

        printf("Soma: %i + %i = %i\n", num1, num2, soma += num2);
        printf("Subtracao: %i - %i = %i\n", num1, num2, sub -= num2);
        printf("Multiplicacao: %i * %i = %i\n", num1, num2, mult *= num2);
        printf("Divisao: %i / %i = %.1f\n", num1, num2, div /= (float)num2);
        printf("Digite (1) para continuar ou (0) para sair: ");
        scanf("%i", &continuar);
    }while(continuar == 1);

}
#endif