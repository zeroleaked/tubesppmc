#include <stdio.h>
#include "pengacakan.h"

#define tc1
//#define tc2

int main()
{
    #ifdef tc1
    arrKata *dict, a, b, c, key;
    int n = 2;
    
    initializeArrKata(&a);
    initializeArrKata(&b);
    initializeArrKata(&c);
    pushArrKata(&a, "Saya");
    pushArrKata(&a, "mahasiswa");
    pushArrKata(&a, "ITB");
    pushArrKata(&b, "mahasiswa");
    pushArrKata(&b, "ITB");
    pushArrKata(&b, "yang");
    pushArrKata(&c, "ITB");
    pushArrKata(&c, "yang");
    pushArrKata(&c, "rajin.");
    pushArrKata(&c, "malas.");

    b.next = &c;
    a.next = &b;
    dict = &a;

    key = getRandomKey(dict, n);
    printArrKata(key);
    return 0;
    #endif

    #ifdef tc2
    arrKata a;
    char *output;
    int n = 2;
    initializeArrKata(&a);
    pushArrKata(&a, "ITB");
    pushArrKata(&a, "Unisba");
    pushArrKata(&a, "UI");
    pushArrKata(&a, "Unpad");
    printArrKata(a);
    output = randomWord(&a);
    printf("%s\n", output); 
    #endif


}

