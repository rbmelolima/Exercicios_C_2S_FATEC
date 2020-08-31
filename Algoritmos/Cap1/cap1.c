#include <stdio.h>
#define ex1

#ifdef ex1
main()
{
    short int s; long int l; int i; float f; double d; char ch;
    printf("Digite um numero int short: ");
    scanf("%hi",&s);
    printf("Digite um numero int long: ");
    scanf("%li",&l);
    printf("Digite um numero int: ");
    scanf("%i",&i);
    printf("Digite um numero float: ");
    scanf("%f",&f);
    printf("Digite um numero double: ");
    scanf("%lf",&d);
    printf("Digite um char: ");
    scanf(" %c", &ch);

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("    %-6hi              %-6li              %-6i\n",s,l,i);
    printf("              %-6.1f              %-6.1lf              %-1c",f,d,ch);
}
#endif

#ifdef ex2
int main() {
    int seconds = 0;

    while(seconds <= 0){
        printf("Digite o tempo em segundos: ");
        scanf("%d", &seconds);
    }

    convertSecondsInTime(seconds);

    return 0;
}

void convertSecondsInTime(int seconds) {
    int secondsInMinute = 60;
    int secondsInHour = 3600; //60 * 60

    int hour = seconds / secondsInHour;
    int minutes = ((seconds / secondsInMinute) - (hour * secondsInMinute));
    int rest_seconds = seconds - (hour * secondsInHour) - (minutes * secondsInMinute);

    printf("%dh %dmin %ds", hour, minutes, rest_seconds);
}

#endif ex2

#ifdef ex3
main()
{
	int n;
	int centena;
	int dezena;
	do{
		printf("Digite um numero positivo de tres digitos : ");
		scanf("%d",&n);
		if(n < 100 || n > 999){
			printf("\nO numero deve ser positivo e deve ter tres digitos\n");
		}
	}while(n < 100 || n > 999);
	centena = n/100;
	dezena = n/10 - ( (n/100) * 10 );
	printf("\nNumero Gerado %d%d%d", ( n - centena*100 - dezena*10 ), dezena, centena);
}
#endif ex3

#ifdef ex4
int main() {
    int a = 0, b = 0;

    printf("Digite A e B: ");
    scanf("%d %d", &a, &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("A: %d\n", a);
    printf("B: %d\n", b);

    return 0;
}
#endif ex4


#ifdef ex5
int main() {
    int money = 0;

    while(money <= 0){
        printf("Digite o valor do dinheiro: ");
        scanf("%d", &money);
    }

    splitMoney(money);

    return 0;
}

int bigDivisor(int money) {
    if (money >= 100) return 100;
    else if (money < 100 && money >= 50) return 50;
    else if (money < 50 && money >= 20) return 20;
    else if (money < 20 && money >= 10) return 10;
    else if (money < 10 && money >= 5) return 5;
    else if (money < 5 && money >= 2) return 2;
    else return 1;
}

void splitMoney(int money) {
    if (money == 0) return;

    int divisor = bigDivisor(money);
    int coin = 0, rest = 0;

    coin = money / divisor;
    rest = money % divisor;

    printf("\nQuantidade de notas de %d: %d\n", divisor, coin);
    splitMoney(rest);
}
#endif ex5
