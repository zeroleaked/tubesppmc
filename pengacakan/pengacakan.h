/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : C6
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : pengacakan.h
* Deskripsi : Program untuk mendapatkan key dan value secara acak
dari dictionary
*/

#include <stdlib.h>
#include "../konfigurasi/konfigurasi.h"

#ifndef PENGACAKAN
#define PENGACAKAN

arrKata getRandomKey(arrKata *dict, int n)
{
    arrKata temp, *toReturn;
    int index, dictLength, i;

    dictLength = getDictionaryLength(dict);
    index = rand()%dictLength;

    //menuju ke row yang diinginkan (hasil random)
    temp = peekDictionary(dict, index);

    //sudah di Row yang diinginkan, assign nilai-nilai untuk return
    initializeArrKata(&toReturn);
    for ( i = 0; i < n; i++)
    {
        pushArrKata(toReturn, temp.array[i]);
    }
    
    return (*toReturn);
}
char* randomWord(arrKata *value){
    int index;

    //Initialize random number generator (seed at time &t)
    index= rand()%(value->length);
    char *word;
    word = value->array[index];
    return (word);
}

#endif
