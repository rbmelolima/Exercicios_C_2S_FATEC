#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define ex5

#ifdef ex1
main()
{
    char nome1[8];
    char nome2[8];
    char nome3[8];
    char nome4[8];
    char nome5[8];
    int cont;
    do
    {
        printf("Digite o primeiro nome: ");
        scanf("%s", &nome1);
        printf("Digite o segundo nome: ");
        scanf("%s", &nome2);
        printf("Digite o terceiro nome: ");
        scanf("%s", &nome3);
        printf("Digite o quarto nome: ");
        scanf("%s", &nome4);
        printf("Digite o quinto nome: ");
        scanf("%s", &nome5);

        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890\n");
        printf("  %-7s                                 %-7s\n", nome1, nome5);
        printf("            %-7s             %-7s\n", nome2, nome4);
        printf("                      %-7s\n", nome3);
        printf("Digite (1) para continuar ou (0) para sair: ");
        scanf("%i", &cont);
    } while (cont == 1);
}
#endif

#ifdef ex2
main()
{
    char str[3][11];
    int cont;
    do
    {
        printf("Digite a primeira string: ");
        scanf("%s", &str[0]);
        printf("Digite a segunda string: ");
        scanf("%s", &str[1]);
        printf("Digite a terceira string: ");
        scanf("%s", &str[2]);

        printf("        10        20        30        40        50        60\n");
        printf("123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %-10s          %-10s          %-10s\n", str[0], str[1], str[2]);
        printf("Digite (1) para continuar ou (0) para sair: ");
        scanf("%i", &cont);
    } while (cont == 1);
}
#endif

#ifdef ex3
main()
{
    char caracteres[10];
    char tecla;
    int i;
    do
    {
        printf("Digite uma string via teclado : ");
        gets(caracteres);
        for (i = 0; i < 10; i++)
        {
            if ((int)caracteres[i] >= 97 && (int)caracteres[i] <= 122)
            {
                caracteres[i] = ((int)caracteres[i]) - 32;
            }
        }
        printf("A string digitada com seus caracteres maiusculus e \"%s\"", caracteres);
        printf("\nDeseja continuar?(s/n) ");
        tecla = getchar();
        getchar();
    } while ((tecla != 'n') && (tecla != 'N'));
}
#endif

#ifdef ex4
main()
{
    char caracteres[10];
    char tecla;
    int i;

    do
    {
        printf("Digite uma string via teclado : ");
        gets(caracteres);
        for (i = 0; i < 10; i++)
        {
            if ((int)caracteres[i] >= 65 && (int)caracteres[i] <= 90)
            {
                caracteres[i] = ((int)caracteres[i]) - 32;
            }
        }
        printf("A string digitada com seus caracteres minusculos e \"%s\"", caracteres);
        printf("\nDeseja continuar?(s/n) ");
        tecla = getchar();
        getchar();
    } while ((tecla != 'n') && (tecla != 'N'));
}
#endif

#ifdef ex5
int main()
{
    char word1[10];
    char word2[10];

    int isDifferent = false;
    int loop = 1;

    while (loop == 1)
    {
        printf("Digite uma palavra via teclado (10 caracteres): ");
        scanf("%s", &word1);

        printf("Digite uma palavra via teclado (10 caracteres): ");
        scanf("%s", &word2);

        for (int i = 0; i < 9; i++)
        {
            if(word1[i] != word2[i]){
                isDifferent = true;
                break;
            }

            isDifferent = false;
        }

        if(isDifferent){
            printf("\n\n ** Palavras diferentes **");
        }

        else {
            printf("\n\n ** Palavras iguais **");
        }


        printf("\n\n\nDeseja continuar? \n(1) Positivo \n(0) Negativo\n:");
        scanf("%d", &loop);

        system("cls");
    }
}

#endif
