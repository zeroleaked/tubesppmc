#include <stdlib.h>
#include <time.h>
#include "konfigurasi.h"

arrKata getRandomKey(arrKata *dict, int n)
{
    arrKata temp, toReturn;
    int index, dictLength, currRow = 0, i;

    srand(time(0));

    dictLength = getDictionaryLength(dict);
    index = rand()%dictLength;

    //menuju ke row yang diinginkan (hasil random)
    temp = peekDictionary(dict, index);

    //sudah di Row yang diinginkan, assign nilai-nilai untuk return
    toReturn.next = NULL;
    toReturn.length = n;
    for ( i = 0; i < n; i++)
    {
        pushArrKata(&toReturn, temp.array[i]);
    }
    
    return toReturn;
}

char* randomWord(arrKata *value, int n){
    int indeks;
    indeks= rand()%((value->length)-n)-1;
    char *word=value->array[indeks+n];
    return (*word);
}