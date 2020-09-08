#include <stdio.h>
#include <stdbool.h>

#define ex4

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
