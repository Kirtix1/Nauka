#include <stdio.h>
void lokaj(void);                                                               /*Prototyp funkcji wg ANSI/ISO C*/
                                                                                /*w K&R C byłoby to: void lokaj(); */

int main()
{
    printf("Wywołam funkcję lokaja.\n");
    lokaj();
    printf("Tak. Przynieś mi herbate i zapisywalne DVD.\n");
    return 0;
}
    void lokaj(void)                                                            /*początek definicji funkcji*/
    {
        printf("Pan wzywał?\n");
    }

