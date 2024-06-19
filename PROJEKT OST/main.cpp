#include <stdio.h>
#include <string.h>

int unit; // zmienna przechowujaca wybrana jednostke miary
double a; // zmienna przechowujaca wartosc do przeliczenia
int docelowa; // zmienna przechowujaca wybrana jednostke docelowa
int choice; // zmienna przechowujaca wybor kategorii konwersji
int continue_choice; // zmienna przechowujaca decyzje o kontynuowaniu programu

void print_trimmed_double(double number) {
    char buffer[50];
    sprintf(buffer, "%.10f", number); // Konwertuje liczbe na string z duza dokladnoscia

    // Usun nadmiarowe zera z konca
    int len = strlen(buffer);
    while (len > 1 && buffer[len - 1] == '0') {
        len--;
    }
    if (buffer[len - 1] == '.') {
        len--; // Usun kropke, jesli jest na koncu
    }
    buffer[len] = '\0';

    printf("%s", buffer);
}

int main() {
    printf("Konwerter jednostek miary\n"); // wyswietla tytul programu
    printf("Nacisnij dowolny przycisk, aby kontynuowac...\n"); // wyswietla komunikat o kontynuacji programu

    // Czeka na nacisniecie dowolnego przycisku
    getchar();

    do {
        do {
            printf("Wybierz co chcesz przeliczyc?\n"); // pyta uzytkownika, co chce przeliczyc
            printf("1. Length (dlugosc)\n"); // opcja dla dlugosci
            printf("2. Weight (waga)\n"); // opcja dla wagi
            printf("3. Volume (objetosc)\n"); // opcja dla objetosci
            printf("Wybierz numer jednostki (1-3): "); // prosi o wybor kategorii
            scanf("%d", &choice);

            if (choice < 1 || choice > 3) { // sprawdza, czy wybor jest poprawny
                printf("Nieprawidlowy wybor.\n Wybierz numer od 1 do 3.\n"); // komunikat o blednym wyborze
            } else {
                switch(choice) { // sprawdza wybrana kategorie
                    case 1: {
                        printf("Wybrales dlugosc (length).\n"); // informuje o wyborze dlugosci
                        do {
                            printf("Wybierz jednostke w jakiej podasz miare (1-4):\n"); // pyta o jednostke wejsciowa dla dlugosci
                            printf("1. Milimetry\n"); // opcja dla milimetrow
                            printf("2. Centymetry\n"); // opcja dla centymetrow
                            printf("3. Metry\n"); // opcja dla metrow
                            printf("4. Kilometry\n"); // opcja dla kilometrow
                            scanf("%d", &unit);
                            if (unit < 1 || unit > 4) { // sprawdza, czy wybor jednostki jest poprawny
                                printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki
                            }
                        } while (unit < 1 || unit > 4);

                        switch(unit) { // sprawdza wybrana jednostke wejsciowa
                            case 1: {
                                printf("Wybrales milimetry.\n"); // informuje o wyborze milimetrow
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0.\n Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Centymetry\n"); // opcja dla centymetrow
                                    printf("2. Metry\n"); // opcja dla metrow
                                    printf("3. Kilometry\n"); // opcja dla kilometrow
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);

                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf milimetrow to ", a);
                                        print_trimmed_double(a / 10.0); // konwersja z milimetrow na centymetry
                                        printf(" centymetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf milimetrow to ", a);
                                        print_trimmed_double(a / 1000.0); // konwersja z milimetrow na metry
                                        printf(" metrow\n");
                                        break;
                                    case 3:
                                        printf("%lf milimetrow to ", a);
                                        print_trimmed_double(a / 1000000.0); // konwersja z milimetrow na kilometry
                                        printf(" kilometrow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            }
                            case 2: // konwersje dla centymetrow
                                printf("Wybrales centymetry.\n"); // informuje o wyborze centymetrow
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0.\n Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Milimetry\n"); // opcja dla milimetrow
                                    printf("2. Metry\n"); // opcja dla metrow
                                    printf("3. Kilometry\n"); // opcja dla kilometrow
                                    scanf("%d", &docelowa);
                                    if (docelowa < 1 || docelowa > 3 ){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                }while (docelowa < 1 || docelowa > 3 );
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf centymetrow to ", a);
                                        print_trimmed_double(a * 10.0); // konwersja z centymetrow na milimetry
                                        printf(" milimetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf centymetrow to ", a);
                                        print_trimmed_double(a / 100.0); // konwersja z centymetrow na metry
                                        printf(" metrow\n");
                                        break;
                                    case 3:
                                        printf("%lf centymetrow to ", a);
                                        print_trimmed_double(a / 100000.0); // konwersja z centymetrow na kilometry
                                        printf(" kilometrow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 3: // konwersje dla metrow
                                printf("Wybrales metry.\n"); // informuje o wyborze metrow
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Milimetry\n"); // opcja dla milimetrow
                                    printf("2. Centymetry\n"); // opcja dla centymetrow
                                    printf("3. Kilometry\n"); // opcja dla kilometrow
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf metrow to ", a);
                                        print_trimmed_double(a * 1000.0); // konwersja z metrow na milimetry
                                        printf(" milimetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf metrow to ", a);
                                        print_trimmed_double(a * 100.0); // konwersja z metrow na centymetry
                                        printf(" centymetrow\n");
                                        break;
                                    case 3:
                                        printf("%lf metrow to ", a);
                                        print_trimmed_double(a / 1000.0); // konwersja z metrow na kilometry
                                        printf(" kilometrow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 4: // konwersje dla kilometrow
                                printf("Wybrales kilometry.\n"); // informuje o wyborze kilometrow
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Milimetry\n"); // opcja dla milimetrow
                                    printf("2. Centymetry\n"); // opcja dla centymetrow
                                    printf("3. Metry\n"); // opcja dla metrow
                                    scanf("%d", &docelowa);
                                    if (docelowa < 1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybor jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf kilometrow to ", a);
                                        print_trimmed_double(a * 1000000.0); // konwersja z kilometrow na milimetry
                                        printf(" milimetrow\n");
                                        break;
                                    case 2:
                                        printf("%lf kilometrow to ", a);
                                        print_trimmed_double(a * 100000.0); // konwersja z kilometrow na centymetry
                                        printf(" centymetrow\n");
                                        break;
                                    case 3:
                                        printf("%lf kilometrow to ", a);
                                        print_trimmed_double(a * 1000.0); // konwersja z kilometrow na metry
                                        printf(" metrow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            default:
                                printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                break;
                        }
                        break;
                    }
                    case 2: { // konwersje dla wagi
                        printf("Wybrales wage (weight).\n"); // informuje o wyborze wagi
                        do {
                            printf("Wybierz jednostke w jakiej podasz wage (1-4):\n"); // pyta o jednostke wejsciowa dla wagi
                            printf("1. Gramy\n"); // opcja dla gramow
                            printf("2. Dekagramy\n"); // opcja dla dekagramow
                            printf("3. Kilogramy\n"); // opcja dla kilogramow
                            printf("4. Tony\n"); // opcja dla ton
                            scanf("%d", &unit);
                            if (unit < 1 || unit > 4) { // sprawdza, czy wybor jednostki jest poprawny
                                printf("Nieprawidlowy wybor jednostki. Proboj dalej\n"); // komunikat o blednym wyborze jednostki
                            }
                        } while (unit < 1 || unit > 4);

                        switch(unit) { // sprawdza wybrana jednostke wejsciowa
                            case 1:
                                printf("Wybrales gramy.\n"); // informuje o wyborze gramow
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Dekagramy\n"); // opcja dla dekagramow
                                    printf("2. Kilogramy\n"); // opcja dla kilogramow
                                    printf("3. Tony\n"); // opcja dla ton
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf gramow to ", a);
                                        print_trimmed_double(a / 10.0); // konwersja z gramow na dekagramy
                                        printf(" dekagramow\n");
                                        break;
                                    case 2:
                                        printf("%lf gramow to ", a);
                                        print_trimmed_double(a / 1000.0); // konwersja z gramow na kilogramy
                                        printf(" kilogramow\n");
                                        break;
                                    case 3:
                                        printf("%lf gramow to ", a);
                                        print_trimmed_double(a / 1000000.0); // konwersja z gramow na tony
                                        printf(" ton\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 2: // konwersje dla dekagramow
                                printf("Wybrales dekagramy.\n"); // informuje o wyborze dekagramow
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Gramy\n"); // opcja dla gramow
                                    printf("2. Kilogramy\n"); // opcja dla kilogramow
                                    printf("3. Tony\n"); // opcja dla ton
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf dekagramow to ", a);
                                        print_trimmed_double(a * 10.0); // konwersja z dekagramow na gramy
                                        printf(" gramow\n");
                                        break;
                                    case 2:
                                        printf("%lf dekagramow to ", a);
                                        print_trimmed_double(a / 100.0); // konwersja z dekagramow na kilogramy
                                        printf(" kilogramow\n");
                                        break;
                                    case 3:
                                        printf("%lf dekagramow to ", a);
                                        print_trimmed_double(a / 100000.0); // konwersja z dekagramow na tony
                                        printf(" ton\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 3: // konwersje dla kilogramow
                                printf("Wybrales kilogramy.\n"); // informuje o wyborze kilogramow
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Gramy\n"); // opcja dla gramow
                                    printf("2. Dekagramy\n"); // opcja dla dekagramow
                                    printf("3. Tony\n"); // opcja dla ton
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf kilogramow to ", a);
                                        print_trimmed_double(a * 1000.0); // konwersja z kilogramow na gramy
                                        printf(" gramow\n");
                                        break;
                                    case 2:
                                        printf("%lf kilogramow to ", a);
                                        print_trimmed_double(a * 100.0); // konwersja z kilogramow na dekagramy
                                        printf(" dekagramow\n");
                                        break;
                                    case 3:
                                        printf("%lf kilogramow to ", a);
                                        print_trimmed_double(a / 1000.0); // konwersja z kilogramow na tony
                                        printf(" ton\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 4: // konwersje dla ton
                                printf("Wybrales tony.\n"); // informuje o wyborze ton
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Gramy\n"); // opcja dla gramow
                                    printf("2. Dekagramy\n"); // opcja dla dekagramow
                                    printf("3. Kilogramy\n"); // opcja dla kilogramow
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf ton to ", a);
                                        print_trimmed_double(a * 1000000.0); // konwersja z ton na gramy
                                        printf(" gramow\n");
                                        break;
                                    case 2:
                                        printf("%lf ton to ", a);
                                        print_trimmed_double(a * 100000.0); // konwersja z ton na dekagramy
                                        printf(" dekagramow\n");
                                        break;
                                    case 3:
                                        printf("%lf ton to ", a);
                                        print_trimmed_double(a * 1000.0); // konwersja z ton na kilogramy
                                        printf(" kilogramow\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            default:
                                printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                break;
                        }
                        break;
                    }
                    case 3: { // konwersje dla objetosci
                        printf("Wybrales objetosc (volume).\n"); // informuje o wyborze objetosci
                        do {
                            printf("Wybierz jednostke w jakiej podasz objetosc (1-4):\n"); // pyta o jednostke wejsciowa dla objetosci
                            printf("1. Milimetry szescienne\n"); // opcja dla milimetrow szesciennych
                            printf("2. Centymetry szescienne\n"); // opcja dla centymetrow szesciennych
                            printf("3. Decymetry szescienne\n"); // opcja dla decymetrow szesciennych
                            printf("4. Metry szescienne\n"); // opcja dla metrow szesciennych
                            scanf("%d", &unit);
                            if (unit < 1 || unit > 4) { // sprawdza, czy wybor jednostki jest poprawny
                                printf("Nieprawidlowy wybor jednostki. Proboj dalej\n"); // komunikat o blednym wyborze jednostki
                            }
                        } while (unit < 1 || unit > 4);

                        switch(unit) { // sprawdza wybrana jednostke wejsciowa
                            case 1:
                                printf("Wybrales milimetry szescienne.\n"); // informuje o wyborze milimetrow szesciennych
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Centymetry szescienne\n"); // opcja dla centymetrow szesciennych
                                    printf("2. Decymetry szescienne\n"); // opcja dla decymetrow szesciennych
                                    printf("3. Metry szescienne\n"); // opcja dla metrow szesciennych
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf milimetrow szesciennych to ", a);
                                        print_trimmed_double(a / 1000.0); // konwersja z milimetrow szesciennych na centymetry szescienne
                                        printf(" centymetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf milimetrow szesciennych to ", a);
                                        print_trimmed_double(a / 1000000.0); // konwersja z milimetrow szesciennych na decymetry szescienne
                                        printf(" decymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf milimetrow szesciennych to ", a);
                                        print_trimmed_double(a / 1000000000.0); // konwersja z milimetrow szesciennych na metry szescienne
                                        printf(" metrow szesciennych\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 2: // konwersje dla centymetrow szesciennych
                                printf("Wybrales centymetry szescienne.\n"); // informuje o wyborze centymetrow szesciennych
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Milimetry szescienne\n"); // opcja dla milimetrow szesciennych
                                    printf("2. Decymetry szescienne\n"); // opcja dla decymetrow szesciennych
                                    printf("3. Metry szescienne\n"); // opcja dla metrow szesciennych
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf centymetrow szesciennych to ", a);
                                        print_trimmed_double(a * 1000.0); // konwersja z centymetrow szesciennych na milimetry szescienne
                                        printf(" milimetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf centymetrow szesciennych to ", a);
                                        print_trimmed_double(a / 1000.0); // konwersja z centymetrow szesciennych na decymetry szescienne
                                        printf(" decymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf centymetrow szesciennych to ", a);
                                        print_trimmed_double(a / 1000000.0); // konwersja z centymetrow szesciennych na metry szescienne
                                        printf(" metrow szesciennych\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 3: // konwersje dla decymetrow szesciennych
                                printf("Wybrales decymetry szescienne.\n"); // informuje o wyborze decymetrow szesciennych
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Milimetry szescienne\n"); // opcja dla milimetrow szesciennych
                                    printf("2. Centymetry szescienne\n"); // opcja dla centymetrow szesciennych
                                    printf("3. Metry szescienne\n"); // opcja dla metrow szesciennych
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf decymetrow szesciennych to ", a);
                                        print_trimmed_double(a * 1000000.0); // konwersja z decymetrow szesciennych na milimetry szescienne
                                        printf(" milimetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf decymetrow szesciennych to ", a);
                                        print_trimmed_double(a * 1000.0); // konwersja z decymetrow szesciennych na centymetry szescienne
                                        printf(" centymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf decymetrow szesciennych to ", a);
                                        print_trimmed_double(a / 1000.0); // konwersja z decymetrow szesciennych na metry szescienne
                                        printf(" metrow szesciennych\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            case 4: // konwersje dla metrow szesciennych
                                printf("Wybrales metry szescienne.\n"); // informuje o wyborze metrow szesciennych
                                do {
                                    printf("Podaj wartosc: "); // pyta o wartosc do przeliczenia
                                    scanf("%lf", &a);
                                    if (a <= 0) { // sprawdza, czy wartosc jest poprawna
                                        printf("Wartosc nie moze byc ujemna lub rowna 0. Sprobuj ponownie.\n"); // komunikat o blednej wartosci
                                    }
                                } while (a <= 0);
                                do{
                                    printf("Na jaka jednostke chcesz przeliczyc?\n"); // pyta o jednostke docelowa
                                    printf("1. Milimetry szescienne\n"); // opcja dla milimetrow szesciennych
                                    printf("2. Centymetry szescienne\n"); // opcja dla centymetrow szesciennych
                                    printf("3. Decymetry szescienne\n"); // opcja dla decymetrow szesciennych
                                    scanf("%d", &docelowa);
                                    if (docelowa <1 || docelowa > 3){ // sprawdza, czy wybor jednostki docelowej jest poprawny
                                        printf("Nieprawidlowy wybur jednostki.\n Proboj dalej\n"); // komunikat o blednym wyborze jednostki docelowej
                                    }
                                } while (docelowa < 1 || docelowa > 3);
                                switch(docelowa) { // sprawdza wybrana jednostke docelowa
                                    case 1:
                                        printf("%lf metrow szesciennych to ", a);
                                        print_trimmed_double(a * 1000000000.0); // konwersja z metrow szesciennych na milimetry szescienne
                                        printf(" milimetrow szesciennych\n");
                                        break;
                                    case 2:
                                        printf("%lf metrow szesciennych to ", a);
                                        print_trimmed_double(a * 1000000.0); // konwersja z metrow szesciennych na centymetry szescienne
                                        printf(" centymetrow szesciennych\n");
                                        break;
                                    case 3:
                                        printf("%lf metrow szesciennych to ", a);
                                        print_trimmed_double(a * 1000.0); // konwersja z metrow szesciennych na decymetry szescienne
                                        printf(" decymetrow szesciennych\n");
                                        break;
                                    default:
                                        printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                        break;
                                }
                                break;
                            default:
                                printf("Nieprawidlowy wybor jednostki.\n"); // komunikat o blednym wyborze jednostki
                                break;
                        }
                        break;
                    }
                }
            }
        } while(choice < 1 || choice > 3);

        // Zapytaj uzytkownika, czy chce wrocic do poczatku lub wyjsc
        printf("Czy chcesz przeliczyc kolejne jednostki? (1 - Tak, 2 - Nie): ");
        scanf("%d", &continue_choice); // zapytanie o kontynuacje programu

    } while(continue_choice == 1); // kontynuuje, jesli uzytkownik wybral "Tak"

    return 0; // zakonczenie programu
}
