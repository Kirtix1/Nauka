#include <stdio.h>

int main(void)               /*prosty program*/
{
    int num;                 /*definujemy zmienną o nazwie num*/
    num = 1;                 /*przypisujemy jej wartość*/

    printf("Jestem prostym "); /*korzystamy z funkcji printf()*/
    printf("komputerem.\n");
    printf("Moja ulubion liczba jest %d, bo jest pierwsza.\n", num);

    return 0;
}
