#include <stdlib.h>
#include <time.h>
#include "../konfigurasi/konfigurasi.h"

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
    initializeArrKata(&toReturn);
    for ( i = 0; i < n; i++)
    {
        pushArrKata(&toReturn, temp.array[i]);
    }
    
    return toReturn;
}
char* randomWord(arrKata *value){
    int index;
    srand(time(0));
    index= rand()%(value->length);
    char *word;
    word = value->array[index];
    return (word);
}
