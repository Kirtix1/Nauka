#include <stdio.h>

int unit;
double a;
int docelowa;
int choice;
int continue_choice;

int main() {
    printf("Konwerter jednostek miary\n");
    printf("Nacisnij dowolny przycisk, aby kontynuowac...\n");

    // Czeka na nacisniecie dowolnego przycisku
    getchar();

    do {
        do {
            printf("Wybierz co chcesz przeliczyc?\n");
            printf("1. Length (dlugosc)\n");
            printf("2. Weight (waga)\n");
            printf("3. Volume (objetosc)\n");
            printf("Wybierz numer jednostki (1-3): ");
            scanf("%d", &choice);

            if (choice < 1 || choice > 3) {
                printf("Nieprawidlowy wybor.\n Wybierz numer od 1 do 3.\n");
            } else {
                switch(choice) {
                    case 1: {
                        printf("Wybrales dlugosc (length).\n");
                        do {
                            printf("Wybierz jednostke w jakiej podasz miare (1-4):\n");
                            printf("1. Milimetry\n");
                            printf("2. Centymetry\n");
                            printf("3. Metry\n");
                            printf("4. Kilometry\n");
                            scanf("%d", &unit);
                            if (unit < 1 || unit > 4) {
                                printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n");
                            }
                        } while (unit < 1 || unit > 4);

                        switch(unit) {
                            case 1: {
                                printf("Wybrales milimetry.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0.\n Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Centymetry\n");
                                    printf("2. Metry\n");
                                    printf("3. Kilometry\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);

                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf milimetry to %.6lf centymetrow.\n", a, a / 10.0);
                                        break;
                                    case 2:
                                        printf("%.6lf milimetry to %.6lf metrow.\n", a, a / 1000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf milimetry to %.6lf kilometrow.\n", a, a / 1000000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            }
                            case 2:
                                printf("Wybrales centymetry.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0.\n Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Milimetry\n");
                                    printf("2. Metry\n");
                                    printf("3. Kilometry\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa < 1 || docelowa > 3 ){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                }while (docelowa < 1 || docelowa > 3 );
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf centymetry to %.6lf milimetrow.\n", a, a * 10.0);
                                        break;
                                    case 2:
                                        printf("%.6lf centymetry to %.6lf metrow.\n", a, a / 100.0);
                                        break;
                                    case 3:
                                        printf("%.6lf centymetry to %.6lf kilometrow.\n", a, a / 100000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 3:
                                printf("Wybrales metry.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Milimetry\n");
                                    printf("2. Centymetry\n");
                                    printf("3. Kilometry\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf metry to %.6lf milimetrow.\n", a, a * 1000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf metry to %.6lf centymetrow.\n", a, a * 100.0);
                                        break;
                                    case 3:
                                        printf("%.6lf metry to %.6lf kilometrow.\n", a, a / 1000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 4:
                                printf("Wybrales kilometry.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Milimetry\n");
                                    printf("2. Centymetry\n");
                                    printf("3. Metry\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa < 1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf kilometry to %.6lf milimetrow.\n", a, a * 1000000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf kilometry to %.6lf centymetrow.\n", a, a * 100000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf kilometry to %.6lf metrow.\n", a, a * 1000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            default:
                                printf("Nieprawidlowy wybor jednostki.\n");
                                break;
                        }
                        break;
                    }
                    case 2: {
                        printf("Wybrales wage (weight).\n");
                        do {
                            printf("Wybierz jednostke w jakiej podasz wage (1-4):\n");
                            printf("1. Gramy\n");
                            printf("2. Dekagramy\n");
                            printf("3. Kilogramy\n");
                            printf("4. Tony\n");
                            scanf("%d", &unit);
                            if (unit < 1 || unit > 4) {
                                printf("Nieprawidlowy wybor jednostki. Proboj dalej\n");
                            }
                        } while (unit < 1 || unit > 4);

                        switch(unit) {
                            case 1:
                                printf("Wybrales gramy.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Dekagramy\n");
                                    printf("2. Kilogramy\n");
                                    printf("3. Tony\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf gramy to %.6lf dekagramow.\n", a, a / 10.0);
                                        break;
                                    case 2:
                                        printf("%.6lf gramy to %.6lf kilogramow.\n", a, a / 1000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf gramy to %.6lf ton.\n", a, a / 1000000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 2:
                                printf("Wybrales dekagramy.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Gramy\n");
                                    printf("2. Kilogramy\n");
                                    printf("3. Tony\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf dekagramy to %.6lf gramow.\n", a, a * 10.0);
                                        break;
                                    case 2:
                                        printf("%.6lf dekagramy to %.6lf kilogramow.\n", a, a / 100.0);
                                        break;
                                    case 3:
                                        printf("%.6lf dekagramy to %.6lf ton.\n", a, a / 100000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 3:
                                printf("Wybrales kilogramy.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Gramy\n");
                                    printf("2. Dekagramy\n");
                                    printf("3. Tony\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf kilogramy to %.6lf gramow.\n", a, a * 1000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf kilogramy to %.6lf dekagramow.\n", a, a * 100.0);
                                        break;
                                    case 3:
                                        printf("%.6lf kilogramy to %.6lf ton.\n", a, a / 1000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 4:
                                printf("Wybrales tony.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Gramy\n");
                                    printf("2. Dekagramy\n");
                                    printf("3. Kilogramy\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf tony to %.6lf gramow.\n", a, a * 1000000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf tony to %.6lf dekagramow.\n", a, a * 100000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf tony to %.6lf kilogramow.\n", a, a * 1000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            default:
                                printf("Nieprawidlowy wybor jednostki.\n");
                                break;
                        }
                        break;
                    }
                    case 3: {
                        printf("Wybrales objetosc (volume).\n");
                        do {
                            printf("Wybierz jednostke w jakiej podasz objetosc (1-4):\n");
                            printf("1. Milimetry szescienne\n");
                            printf("2. Centymetry szescienne\n");
                            printf("3. Decymetry szescienne\n");
                            printf("4. Metry szescienne\n");
                            scanf("%d", &unit);
                            if (unit < 1 || unit > 4) {
                                printf("Nieprawidlowy wybor jednostki. Proboj dalej\n");
                            }
                        } while (unit < 1 || unit > 4);

                        switch(unit) {
                            case 1:
                                printf("Wybrales milimetry szescienne.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Centymetry szescienne\n");
                                    printf("2. Decymetry szescienne\n");
                                    printf("3. Metry szescienne\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf milimetry szescienne to %.6lf centymetrow szesciennych.\n", a, a / 1000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf milimetry szescienne to %.6lf decymetrow szesciennych.\n", a, a / 1000000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf milimetry szescienne to %.6lf metrow szesciennych.\n", a, a / 1000000000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 2:
                                printf("Wybrales centymetry szescienne.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Milimetry szescienne\n");
                                    printf("2. Decymetry szescienne\n");
                                    printf("3. Metry szescienne\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf centymetry szescienne to %.6lf milimetrow szesciennych.\n", a, a * 1000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf centymetry szescienne to %.6lf decymetrow szesciennych.\n", a, a / 1000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf centymetry szescienne to %.6lf metrow szesciennych.\n", a, a / 1000000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 3:
                                printf("Wybrales decymetry szescienne.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Milimetry szescienne\n");
                                    printf("2. Centymetry szescienne\n");
                                    printf("3. Metry szescienne\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf decymetry szescienne to %.6lf milimetrow szesciennych.\n", a, a * 1000000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf decymetry szescienne to %.6lf centymetrow szesciennych.\n", a, a * 1000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf decymetry szescienne to %.6lf metrow szesciennych.\n", a, a / 1000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 4:
                                printf("Wybrales metry szescienne.\n");
                                do {
                                    printf("Podaj wartosc: ");
                                    scanf("%lf", &a);
                                    if (a <= 0) {
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n");
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n");
                                    printf("1. Milimetry szescienne\n");
                                    printf("2. Centymetry szescienne\n");
                                    printf("3. Decymetry szescienne\n");
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%.6lf metry szescienne to %.6lf milimetrow szesciennych.\n", a, a * 1000000000.0);
                                        break;
                                    case 2:
                                        printf("%.6lf metry szescienne to %.6lf centymetrow szesciennych.\n", a, a * 1000000.0);
                                        break;
                                    case 3:
                                        printf("%.6lf metry szescienne to %.6lf decymetrow szesciennych.\n", a, a * 1000.0);
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            default:
                                printf("Nieprawidlowy wybor jednostki.\n");
                                break;
                        }
                        break;
                    }
                }
            }
        } while(choice < 1 || choice > 3);

        // Zapytaj użytkownika, czy chce wrócić do początku lub wyjść
        printf("Czy chcesz przeliczyc kolejne jednostki? (1 - Tak, 2 - Nie): ");
        scanf("%d", &continue_choice);

    } while(continue_choice == 1);

    return 0;
}
