#include <stdio.h>
#include <stdbool.h>

#define ex4

#ifdef ex1
main()
{
    int numint[3]; long int numlong[3]; unsigned char charuns[3]; float numfloat[3]; double numdouble[3];
    printf("Digite o primeiro numero int: ");
    scanf("%i",&numint[0]);
    printf("Digite o segundo numero int: ");
    scanf("%i",&numint[1]);
    printf("Digite o terceiro numero int: ");
    scanf("%i",&numint[2]);

    printf("Digite o primeiro numero long int: ");
    scanf("%li",&numlong[0]);
    printf("Digite o segundo numero long int: ");
    scanf("%li",&numlong[1]);
    printf("Digite o terceiro numero long int: ");
    scanf("%li",&numlong[2]);

    printf("Digite o primeiro char: ");
    scanf(" %c",&charuns[0]);
    printf("Digite o segundo char: ");
    scanf(" %c",&charuns[1]);
    printf("Digite o terceiro char: ");
    scanf(" %c",&charuns[2]);

    printf("Digite o primeiro numero float: ");
    scanf(" %f",&numfloat[0]);
    printf("Digite o segundo numero float: ");
    scanf(" %f",&numfloat[1]);
    printf("Digite o terceiro numero float: ");
    scanf(" %f",&numfloat[2]);

    printf("Digite o primeiro numero double: ");
    scanf(" %lf",&numdouble[0]);
    printf("Digite o primeiro numero double: ");
    scanf(" %lf",&numdouble[1]);
    printf("Digite o primeiro numero double: ");
    scanf(" %lf",&numdouble[2]);

    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-6i              %-6li              %-1c\n",numint[0],numlong[0],charuns[0]);
    printf("            %-8.1f            %-8.1lf\n",numfloat[0],numdouble[0]);
    printf("  %-6i              %-6li              %-1c\n",numint[1],numlong[1],charuns[1]);
    printf("            %-8.1f            %-8.1lf\n",numfloat[1],numdouble[1]);
    printf("  %-6i              %-6li              %-1c\n",numint[2],numlong[2],charuns[2]);
    printf("            %-8.1f            %-8.1lf\n",numfloat[2],numdouble[2]);
}
#endif

#ifdef ex3
int main() {
    int lengthComponents = 10;
    int components[lengthComponents];
    bool isPalindrome = false;

    for (int i = 0; i < lengthComponents; i++){
        printf("\nInsira o valor %d: ", i + 1);
        scanf("%d", &components[i]);
    }

    for (int i = 0; i < lengthComponents; i++){
        if (components[i] == components[lengthComponents - i - 1]){
            isPalindrome = true;
        }
        else {
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome){
        printf("\n\n ** isPalindrome: True **\n\n");
    }

    else {
        printf("\n\n ** isPalindrome: False ** \n\n");
    }
}
#endif //ex3

#ifdef ex4
int main() {
    int rows = 2;
    int cols = 3;

    int table1 [rows][cols];
    int table2 [rows][cols];
    int table3 [rows][cols];

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("\n (Tabela 1) Posicao %d %d: ", i + 1, j + 1);
            scanf("%d", &table1[i][j]);

            printf("\n (Tabela 2) Posicao %d %d: ", i + 1, j + 1);
            scanf("%d", &table2[i][j]);
        }
    }


    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            table3[i][j] = table1[i][j] - table2[i][j];
            printf("\n (Tabela 3) Posicao %d %d: %d", i + 1, j + 1, table3[i][j]);
        }
    }

}
#endif // ex4
