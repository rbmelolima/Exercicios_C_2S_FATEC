#include <stdio.h>
#include <stdlib.h>

#define ex5

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
		for(i = 0; i < 10; i++){
			if((int)caracteres[i] >= 97 && (int)caracteres[i] <= 122){
				caracteres[i] = ((int)caracteres[i])-32;
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
		for(i = 0; i < 10; i++){
			if((int)caracteres[i] >= 65 && (int)caracteres[i] <= 90){
				caracteres[i] = ((int)caracteres[i])-32;
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

int main(){
    char word1[10];
    char word2[10];

    int isDifferent = 0;
    int loop = 1;

    while(loop == 1){
        printf("Digite uma palavra via teclado (10 caracteres): ");
        gets(word1);

        printf("\nDigite uma palavra via teclado (10 caracteres): ");
        gets(word2);

        for(int i = 0; i < 10; i++){
            printf("%c", word1[i]);
        }

        printf("\n\n");

        for(int i = 0; i < 10; i++){
            printf("%c", word2[i]);
        }

        printf("\nDeseja continuar? \n(1) Positivo \n(0) Negativo\n:");
        scanf("%d", &loop);

        system("cls");
    }

}

#endif // ex4
