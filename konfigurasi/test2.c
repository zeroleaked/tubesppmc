#include <stdio.h>
#include "konfigurasi.h"

int main()
{
    arrKata *kata1, *kata2;
    int result;
    initializeArrKata(kata1);
    initializeArrKata(kata2);
    pushArrKata(kata1, "Saya");
    pushArrKata(kata1, "suka");
    pushArrKata(kata1, "makan");
    pushArrKata(kata1, "ayam.");

    pushArrKata(kata2, "Saya");
    pushArrKata(kata2, "suka");
    pushArrKata(kata2, "makan");

    printArrKata(*kata1);
    printArrKata(*kata2);

    //result = compareKey(*kata1, *kata2, 3);

    printf("%d\n", result);

    return 0;
}