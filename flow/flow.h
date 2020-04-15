//Flow oleh Kendrik Emkel Ginting

#include <stdio.h>
#include "konfigurasi.h"
#include "lookup.h"
#include "pengacakan.h"

void Flow(arrKata *key, arrKata *lookup_table, int n, int printed, int banyak_kata)
{
    //deklarasi variabel
    arrKata *value;
    char *outVal;

    if (printed < banyak_kata)
    {
        //obtain values by key, output to *value. More than 1 values is possible
        lookupDictionary(lookup_table, n, *key, value);
        //get one value from the values obtained in prev step
        outVal = randomWord(value);
        //print the value obtained
        printf("%s ", outVal);
        //add counter
        printed += 1;
        pushArrKata(value, outVal);
        deleteHeadArrKata(value);
    }
    

}