#include <stdio.h>

#define ex3

#ifdef ex1
main()
{
    int num1, num2, continuar;
    do
    {
        printf("Digite o primeiro numero inteiro: ");
        scanf("%i", &num1);

        printf("Digite o segundo numero inteiro: ");
        scanf("%i", &num2);

        printf("Soma: %i + %i = %i\n", num1, num2, num1 + num2);
        printf("Subtracao: %i - %i = %i\n", num1, num2, num1 - num2);
        printf("Multiplicacao: %i * %i = %i\n", num1, num2, num1 * num2);
        printf("Divisao: %i / %i = %.1f\n", num1, num2, (float)num1 / (float)num2);

        printf("Digite (1) para continuar ou (0) para sair: ");
        scanf("%i", &continuar);
    } while (continuar == 1);
}
#endif

#ifdef ex2
main()
{
    int soma, sub, mult, num1, num2, continuar;
    float div;
    do
    {
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
    } while (continuar == 1);
}
#endif

#ifdef ex3
main()
{
    int finish = 0;
    unsigned number1, number2;

    while (finish == 0)
    {
        printf("\n\nDigite um número inteiro: ");
        scanf("%d", &number1);

        printf("Digite outro número inteiro: ");
        scanf("%d", &number2);

        printf("%d | %d => %3d  0x%x\n", number1, number2, number1 | number2, number1 | number2);
        printf("%d & %d => %3d  0x%x\n", number1, number2, number1 & number2, number1 & number2);
        printf("%d ^ %d => %3d  0x%x\n", number1, number2, number1 ^ number2, number1 ^ number2);

        printf("\n\nDeseja continuar? (0) Sim (1) Não: ");
        scanf("%d", &finish);

        system("cls");
    }
}
#endif

#ifdef ex4
main()
{
    int num, div, mult, continuar;
    do
    {
        printf("Digite um numero inteiro: ");
        scanf("%i", &num);

        div = (num >> 3);
        mult = (num << 3);

        printf("\nO numero digitado foi %d, ele dividido por 8 e' %d e multiplicado por 8 e' %d", num, div, mult);

        printf("\nDigite (1) para continuar ou (0) para sair: ");
        scanf("%i", &continuar);
    } while (continuar == 1);
}
#endif

#ifdef ex5
main()
{
    char data_nasc[11];
    char data_agora[11];
    int dias_meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dia, mes, ano, continuar, mes_tira, ano_tira, dias_mes;

    do
    {
        printf("\nDigite a data de nascimento (dd/mm/yyyy): ");
        scanf("%s", &data_nasc);

        printf("\nDigite a data de calculo (dd/mm/yyyy): ");
        scanf("%s", &data_agora);

        ano = ((data_agora[6] * 1000) + (data_agora[7] * 100) + (data_agora[8] * 10) + data_agora[9]) - ((data_nasc[6] * 1000) + (data_nasc[7] * 100) + (data_nasc[8] * 10) + data_nasc[9]);

        ano_tira = (((data_agora[3] * 10) + data_agora[4]) < ((data_nasc[3] * 10) + data_nasc[4]));

        mes = (ano_tira == 1) ? (((data_agora[3] * 10) + data_agora[4] + 12) - ((data_nasc[3] * 10) + data_nasc[4])) : (((data_agora[3] * 10) + data_agora[4]) - ((data_nasc[3] * 10) + data_nasc[4]));

        mes_tira = (((data_agora[0] * 10) + data_agora[1]) < ((data_nasc[0] * 10) + data_nasc[1]));

        dia = (mes_tira == 1) ? (((data_agora[0] * 10) + data_agora[1] + 30) - ((data_nasc[0] * 10) + data_nasc[1])) : (((data_agora[0] * 10) + data_agora[1]) - ((data_nasc[0] * 10) + data_nasc[1]));

        mes = mes - mes_tira;

        ano = ano - ano_tira;

        printf("%d %d %d", dia, mes, ano);

        printf("\nDigite (1) para continuar ou (0) para sair: ");
        scanf("%i", &continuar);
    } while (continuar == 1);
}
#endif