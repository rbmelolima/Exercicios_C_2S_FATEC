#include <stdio.h>
#include <math.h>

#define ex3

int main() {
    int finish = 0;

    int hour1, minutes1, seconds1;
    int hour2, minutes2, seconds2;

    while (finish == 0) {
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

void convertSecondsInHours(int seconds) {
    int secondsInMinute = 60;
    int secondsInHour = 3600; //60 * 60

    int hour = seconds / secondsInHour;
    int minutes = ((seconds / secondsInMinute) - (hour * secondsInMinute));
    int rest_seconds = seconds - (hour * secondsInHour) - (minutes * secondsInMinute);

    printf("%dh %dmin %ds", hour, minutes, rest_seconds);
}

int convertHoursInSeconds(int hour, int minute, int second) {
    int seconds = (hour * 60 * 60) + (minute * 60) + second;
    return seconds;
}
