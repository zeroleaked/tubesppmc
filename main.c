#include <stdio.h>
#include "pengacakan.h"
#include "lookup.h"
#include "konfigurasi.h"
#include "input.h"
#include "flow.h"

int main()
{
    //deklarasi variabel
    arrKata *dict, *inText, *Key, *value;
    char *outVal;
    int n, banyak_kata, printed;

    //User input text, value of n, banyak kata yang ingin dicetak
    inputText(inText);
    inputN(n);
    inputBanyakKata(banyak_kata);

    //membuat dictionary
    createDictionary(n, inputText, dict);

    //mengambil key pertama secara random
    *outKey = getRandomKey(dict);
    //mencetk n kata pertama (key pertama)
    printArrKata(*outKey);
    // set counter untuk menghitung jumlah kata yang sudah dicetak
    printed = n;

    //memperoleh value berdasarkan key (fungsi blm terdefinisi)
    *value = lookupDictionary(dict, n, Key);
    //merandom value yang akan dicetak
    *outVal = randomWord(value);
    //mencetak outVal (salah satu value dari key sebelumnya), increment counter
    printf("%s", *outVal);
    printed += 1;

    //append outVal ke dalam key
    pushArrKata(Key, outVal);
    //geser head key->array[0] = key->array[1]
    deleteHeadArrKata(Key);

    //looping hingga printed = banyak_kata
    Flow(Key, dict, n, printed, banyak_kata);



    return 0;
}