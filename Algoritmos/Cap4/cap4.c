#include <stdio.h>

#define ex3

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