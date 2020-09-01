#include <stdio.h>
#include <math.h>

#define ex3

#ifdef ex1
main()
{
    int min, max;
    char simbolo;
    char tecla;
    do
    {
        min = 0;
        max = 100;
        printf("\nPense em um numero entre 1 e 99");

        do
        {
            printf("\nO numero que voce pensou e %d? (responda com =, > ou <)  ", ((max - min) / 2) + min);

            do
            {
                simbolo = getchar();
                getchar();
                if (simbolo != '=' && simbolo != '<' && simbolo != '>')
                {
                    printf("\nResponda com = caso seja igual a seu numero, com < caso seja menor que seu numero e com > caso seja maior que seu numero!\n");
                }
            } while (simbolo != '=' && simbolo != '<' && simbolo != '>');

            if (simbolo == '<')
            {
                min = (((max - min) / 2) + min);
            }

            else if (simbolo == '>')
            {
                max = (((max - min) / 2) + min);
            }

        } while (simbolo != '=');

        printf("\nDeseja continuar?(s/n) ");
        tecla = getchar();

        getchar();
    } while ((tecla != 'n') && (tecla != 'N'));
}
#endif

#ifdef ex2
main()
{
    int min, max;
    char simbolo;
    char tecla;
    do
    {
        min = 0;
        max = 100;
        printf("\nPense em um numero entre 1 e 99");
        do
        {
            printf("\nO numero que voce pensou e %d? (responda com =, > ou <)  ", ((max - min) / 2) + min);

            do
            {
                simbolo = getchar();
                getchar();
                if (simbolo != '=' && simbolo != '<' && simbolo != '>')
                {
                    printf("\nResponda com = caso seja igual a seu numero, com < caso seja menor que seu numero e com > caso seja maior que seu numero!\n");
                }
            } while (simbolo != '=' && simbolo != '<' && simbolo != '>');

            switch (simbolo)
            {
            case '<':
            {
                min = (((max - min) / 2) + min);
                break;
            }
            case '>':
            {
                max = (((max - min) / 2) + min);
                break;
            }
            }
        } while (simbolo != '=');

        printf("\nDeseja continuar?(s/n) ");
        tecla = getchar();

        getchar();
    } while ((tecla != 'n') && (tecla != 'N'));
}
#endif

#ifdef ex3
int main()
{
    int finish = 0;

    int hour1, minutes1, seconds1;
    int hour2, minutes2, seconds2;

    while (finish == 0)
    {
        printf("\nDigite o horario do instante 1 (hh mm ss):");
        scanf("%d %d %d", &hour1, &minutes1, &seconds1);

        printf("\nDigite o horario do instante 2 (hh mm ss):");
        scanf("%d %d %d", &hour2, &minutes2, &seconds2);

        int seconds = convertHoursInSeconds(hour2, minutes2, seconds2) - convertHoursInSeconds(hour1, minutes1, seconds1);
        convertSecondsInHours(seconds);

        printf("\n\n\nDeseja finalizar o programa? (0) Nao (1) Sim: ");
        scanf("%d", &finish);
    }
}

void convertSecondsInHours(int seconds)
{
    int secondsInMinute = 60;
    int secondsInHour = 3600; //60 * 60

    int hour = seconds / secondsInHour;
    int minutes = ((seconds / secondsInMinute) - (hour * secondsInMinute));
    int rest_seconds = seconds - (hour * secondsInHour) - (minutes * secondsInMinute);

    printf("%dh %dmin %ds", hour, minutes, rest_seconds);
}

int convertHoursInSeconds(int hour, int minute, int second)
{
    int seconds = (hour * 60 * 60) + (minute * 60) + second;
    return seconds;
}
#endif