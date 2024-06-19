#include <stdio.h>

int main() {
    float num1, num2, result;
    char operato;

    // Pobranie pierwszej liczby od użytkownika
    printf("Podaj pierwsza liczbe: ");
    scanf("%f", &num1);

    // Pobranie operatora od użytkownika
    printf("Podaj operator: ");
    scanf(" %c", &operato);

    // Pobranie drugiej liczby od użytkownika
    printf("Podaj druga liczbe: ");
    scanf("%f", &num2);

    // Wykonanie operacji na podstawie podanego operatora
    if (operato == '+') {
        result = num1 + num2;
    } else if (operato == '-') {
        result = num1 - num2;
    } else {
        printf("Nieprawidlowy operator\n");
        return 1;
    }

    // Wyświetlenie wyniku
    printf("Wynik: %.2f\n", result);

    return 0;
}