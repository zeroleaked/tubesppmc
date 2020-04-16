#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pengacakan/pengacakan.h"
#include "lookup/lookup.h"
#include "konfigurasi/konfigurasi.h"
#include "input/input.h"
#include "flow/flow.h"

int main()
{
    //deklarasi variabel
    arrKata *dict, *inText, key, *value;
    char *outVal;
    int n, banyak_kata, printed = 0;
    time_t t;

    //set seed utk random
    srand((unsigned) time(&t));

    //insialisasi arrKata inText
    initializeArrKata(&inText);
    initializeArrKata(&value);

    //User input text, value of n, banyak kata yang ingin dicetak
    inputText(inText);
    inputN(&n);
    inputBanyakKata(&banyak_kata);
    
    //membuat dictionary
    createDictionary(n, *inText, &dict);
    printDictionary(*dict, n);

    //mengambil key pertama secara random
    key = getRandomKey(dict, n);

    //mencetk n kata pertama (key pertama)
    while (printed < n)
    {
        printf("%s ", key.array[printed]);
        printed += 1;
    }
    
    // pada tahap ini printed = n, printed adalah counter berapa banyak yg sudah dicetak

    //memperoleh value berdasarkan key (fungsi blm terdefinisi)
    lookupDictionary(dict, n, key, &value);
    // printf("lookup clear\n");

    //merandom value yang akan dicetak
    outVal = randomWord(value);

    //mencetak outVal (salah satu value dari key sebelumnya), increment counter
    printf("%s ", outVal);
    printed += 1;

    //append outVal ke dalam key
    pushArrKata(&key, outVal);
    //geser head key->array[0] = key->array[1]
    deleteHeadArrKata(&key);

    //looping hingga printed = banyak_kata
    Flow(key, dict, n, printed, banyak_kata);



    return 0;
}