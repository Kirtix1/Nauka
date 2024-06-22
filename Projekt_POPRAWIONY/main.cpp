#include <stdio.h>
#include <string.h>

int unit; // zmienna przechowujaca wybrana jednostke miary
double a; // zmienna przechowujaca wartosc do przeliczenia
int docelowa; // zmienna przechowujaca wybrana jednostke docelowa
int choice; // zmienna przechowujaca wybor kategorii konwersji
int kontynuacja; // zmienna przechowujaca decyzje o kontynuowaniu programu

void przelicznik(double liczba) {
    char ciagznakow[50];
    sprintf(ciagznakow, "%.10f", liczba); // Konwertuje liczbe na string

    // Usun nadmiarowe zera z konca
    int wynik = strlen(ciagznakow);
    while (wynik > 1 && ciagznakow[wynik - 1] == '0') {
        wynik--;
    }
    if (ciagznakow[wynik - 1] == '.') {
        wynik--; // Usun kropke, jesli jest na koncu
    }
    ciagznakow[wynik] = '\0';

    printf("%s", ciagznakow);
}

int main() {
    printf("Konwerter jednostek miary\n");
    printf("Nacisnij dowolny przycisk, aby kontynuowac...\n");

    getchar();

    do {
        do {
            printf("Wybierz co chcesz przeliczyc?\n");
            printf("1. Dlugosc\n");
            printf("2. Waga\n");
            printf("3. Objetosc\n");
            printf("Wybierz numer jednostki (1-3): ");
            scanf("%d", &choice);

            if (choice < 1 || choice > 3) {
                printf("Nieprawidlowy wybor.\n Wybierz numer od 1 do 3.\n");
            } else {
                switch(choice) {
                    case 1: {
                        printf("Wybrales dlugosc.\n");
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
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);

                                switch(docelowa) {
                                    case 1: //konwersja dla milimetrow
                                        printf("%lf milimetrow to ", a);
                                        przelicznik(a / 10.0); // konwersja z milimetrow na centymetry
                                        printf(" centymetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf milimetrow to ", a);
                                        przelicznik(a / 1000.0); // konwersja z milimetrow na metry
                                        printf(" metrow\n");
                                        break;
                                    case 3:
                                        printf("%lf milimetrow to ", a);
                                        przelicznik(a / 1000000.0); // konwersja z milimetrow na kilometry
                                        printf(" kilometrow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            }
                            case 2: // konwersje dla centymetrow
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
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n");
                                    }
                                }while (docelowa < 1 || docelowa > 3 );
                                switch(docelowa) {
                                    case 1:
                                        printf("%lf centymetrow to ", a);
                                        przelicznik(a * 10.0); // konwersja z centymetrow na milimetry
                                        printf(" milimetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf centymetrow to ", a);
                                        przelicznik(a / 100.0); // konwersja z centymetrow na metry
                                        printf(" metrow\n");
                                        break;
                                    case 3:
                                        printf("%lf centymetrow to ", a);
                                        przelicznik(a / 100000.0); // konwersja z centymetrow na kilometry
                                        printf(" kilometrow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 3: // konwersje dla metrow
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
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%lf metrow to ", a);
                                        przelicznik(a * 1000.0); // konwersja z metrow na milimetry
                                        printf(" milimetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf metrow to ", a);
                                        przelicznik(a * 100.0); // konwersja z metrow na centymetry
                                        printf(" centymetrow\n");
                                        break;
                                    case 3:
                                        printf("%lf metrow to ", a);
                                        przelicznik(a / 1000.0); // konwersja z metrow na kilometry
                                        printf(" kilometrow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 4: // konwersje dla kilometrow
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
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%lf kilometrow to ", a);
                                        przelicznik(a * 1000000.0); // konwersja z kilometrow na milimetry
                                        printf(" milimetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf kilometrow to ", a);
                                        przelicznik(a * 100000.0); // konwersja z kilometrow na centymetry
                                        printf(" centymetrow\n");
                                        break;
                                    case 3:
                                        printf("%lf kilometrow to ", a);
                                        przelicznik(a * 1000.0); // konwersja z kilometrow na metry
                                        printf(" metrow\n");
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
                    case 2: { // konwersje dla wagi
                        printf("Wybrales wage.\n");
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
                                        printf("%lf gramow to ", a);
                                        przelicznik(a / 10.0); //konwersja z gramow na dekagramy
                                        printf(" dekagramow\n");
                                        break;
                                    case 2:
                                        printf("%lf gramow to ", a);
                                        przelicznik(a / 1000.0); // konwersja z gramow na kilogramy
                                        printf(" kilogramow\n");
                                        break;
                                    case 3:
                                        printf("%lf gramow to ", a);
                                        przelicznik(a / 1000000.0); // konwersja z gramow na tony
                                        printf(" ton\n");
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
                                        printf("%lf dekagramow to ", a);
                                        przelicznik(a * 10.0); // konwersja z dekagramow na gramy
                                        printf(" gramow\n");
                                        break;
                                    case 2:
                                        printf("%lf dekagramow to ", a);
                                        przelicznik(a / 100.0); // konwersja z dekagramow na kilogramy
                                        printf(" kilogramow\n");
                                        break;
                                    case 3:
                                        printf("%lf dekagramow to ", a);
                                        przelicznik(a / 100000.0); // konwersja z dekagramow na tony
                                        printf(" ton\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 3: // konwersje dla kilogramow
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
                                        printf("%lf kilogramow to ", a);
                                        przelicznik(a * 1000.0); // konwersja z kilogramow na gramy
                                        printf(" gramow\n");
                                        break;
                                    case 2:
                                        printf("%lf kilogramow to ", a);
                                        przelicznik(a * 100.0); // konwersja z kilogramow na dekagramy
                                        printf(" dekagramow\n");
                                        break;
                                    case 3:
                                        printf("%lf kilogramow to ", a);
                                        przelicznik(a / 1000.0); // konwersja z kilogramow na tony
                                        printf(" ton\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 4: // konwersje dla ton
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
                                        printf("%lf ton to ", a);
                                        przelicznik(a * 1000000.0); // konwersja z ton na gramy
                                        printf(" gramow\n");
                                        break;
                                    case 2:
                                        printf("%lf ton to ", a);
                                        przelicznik(a * 100000.0); // konwersja z ton na dekagramy
                                        printf(" dekagramow\n");
                                        break;
                                    case 3:
                                        printf("%lf ton to ", a);
                                        przelicznik(a * 1000.0); // konwersja z ton na kilogramy
                                        printf(" kilogramow\n");
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
                    case 3: { // konwersje dla objetosci
                        printf("Wybrales objetosc.\n");
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
                                        printf("%lf milimetrow szesciennych to ", a);
                                        przelicznik(a / 1000.0); // konwersja z milimetrow szesciennych na centymetry szescienne
                                        printf(" centymetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf milimetrow szesciennych to ", a);
                                        przelicznik(a / 1000000.0); // konwersja z milimetrow szesciennych na decymetry szescienne
                                        printf(" decymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf milimetrow szesciennych to ", a);
                                        przelicznik(a / 1000000000.0); // konwersja z milimetrow szesciennych na metry szescienne
                                        printf(" metrow szesciennych\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 2: // konwersje dla centymetrow szesciennych
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
                                        printf("%lf centymetrow szesciennych to ", a);
                                        przelicznik(a * 1000.0); // konwersja z centymetrow szesciennych na milimetry szescienne
                                        printf(" milimetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf centymetrow szesciennych to ", a);
                                        przelicznik(a / 1000.0); // konwersja z centymetrow szesciennych na decymetry szescienne
                                        printf(" decymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf centymetrow szesciennych to ", a);
                                        przelicznik(a / 1000000.0); // konwersja z centymetrow szesciennych na metry szescienne
                                        printf(" metrow szesciennych\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 3: // konwersje dla decymetrow szesciennych
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
                                        printf("%lf decymetrow szesciennych to ", a);
                                        przelicznik(a * 1000000.0); // konwersja z decymetrow szesciennych na milimetry szescienne
                                        printf(" milimetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf decymetrow szesciennych to ", a);
                                        przelicznik(a * 1000.0); // konwersja z decymetrow szesciennych na centymetry szescienne
                                        printf(" centymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf decymetrow szesciennych to ", a);
                                        przelicznik(a / 1000.0); // konwersja z decymetrow szesciennych na metry szescienne
                                        printf(" metrow szesciennych\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n");
                                        break;
                                }
                                break;
                            case 4: // konwersje dla metrow szesciennych
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
                                    if (docelowa < 1 || docelowa > 3){
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n");
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) {
                                    case 1:
                                        printf("%lf metrow szesciennych to ", a);
                                        przelicznik(a * 1000000000.0); // konwersja z metrow szesciennych na milimetry szescienne
                                        printf(" milimetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf metrow szesciennych to ", a);
                                        przelicznik(a * 1000000.0); // konwersja z metrow szesciennych na centymetry szescienne
                                        printf(" centymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf metrow szesciennych to ", a);
                                        przelicznik(a * 1000.0); // konwersja z metrow szesciennych na decymetry szescienne
                                        printf(" decymetrow szesciennych\n");
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


        printf("Czy chcesz przeliczyc kolejne jednostki? (1 - Tak, 2 - Nie): ");
        scanf("%d", &kontynuacja);

    } while(kontynuacja == 1);

    return 0;
}
