#include <stdio.h>
#include <stdbool.h>

#define ex4

#ifdef ex2
main()
{
    int valores[10], aux, i, j, k;
    char tecla;
    do
    {
        for(i = 0; i < 10; i++){
            printf("\nDigite o %d inteiro: ", i+1);
            scanf("%d",&valores[i]);
            if(i != 0){
	            k = i;
	            for(j = i-1; j >= 0; j--){
	                if(valores[j] > valores[k]){
	                    aux = valores[j];
	                    valores[j] = valores[k];
	                    valores[k] = aux;
	                }
	                k = j;
	            }
			}
        }
        for(i = 0; i < 10; i++){
            printf("\no %d inteiro do vetor e %d ", i+1, valores[i]);
        }
        printf("\nDeseja continuar?(s/n) ");
        getchar();
        tecla = getchar();
    } while ((tecla != 'n') && (tecla != 'N'));
}
#endif // ex2

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

#ifdef ex5
main()
{
    float matriz[2][2], x;
    int i, j;
    char tecla;
    int encontrado = 0;
    do
    {
    	encontrado = 0;
        for(i = 0; i < 2; i++){
            for(j = 0; j < 2; j++){
                printf("\nDigite o valor da posicao [%d][%d] da matriz: ", i, j);
                scanf("%f", &matriz[i][j]);
            }
        }
        printf("\nDigite o valor que deseja buscar na matriz: ");
        scanf("%f", &x);
        i = 0;
        j = 0;
        for(i = 0; i < 2; i++){
            for(j = 0; j < 2; j++){
                if(x == matriz[i][j]){
                    encontrado = 1;
                    printf("\nO valor %f esta presente na posicao [%d][%d] ", x, i, j);
                }
            }
        }
        if(encontrado == 0){
            printf("\nO valor %f nao foi encontrado na matriz!", x);
        }
        printf("\n\nDeseja continuar?(s/n) ");
        getchar();
        tecla = getchar();
    } while ((tecla != 'n') && (tecla != 'N'));
}
#endif // ex5
