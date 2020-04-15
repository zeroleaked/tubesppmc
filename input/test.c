#include <stdio.h>
#include "input.h"

int main()
{
    arrKata inText;
    int N, banyak_kata;

    initializeArrKata(&inText);
    inputText(&inText);
    inputN(&N);
    inputBanyakKata(&banyak_kata);

    printf("\nNilai N: %d\n", N);
    printf("Banyak kata yang akan dicetak: %d\n", banyak_kata);
    printArrKata(inText);

    return 0;
}