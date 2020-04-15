//Flow oleh Kendrik Emkel Ginting

#include <stdio.h>
#include "../lookup/lookup.h"
#include "../pengacakan/pengacakan.h"

#ifndef FLOW
#define FLOW

void Flow(arrKata key, arrKata *lookup_table, int n, int printed, int banyak_kata)
{
    //deklarasi variabel
    arrKata value;
    char *outVal;
    
    while (printed < banyak_kata)
    {
        //obtain values by key, output to *value. More than 1 values is possible
        lookupDictionary(lookup_table, n, key, &value);
        //printArrKata(value);
        
        //get one value from the values obtained in prev step
        outVal = randomWord(&value);

        //print the value obtained, increment counter
        printf("%s ", outVal);
        printed += 1;

        //push value ke key, lalu geser head dari key
        pushArrKata(&key, outVal);
        deleteHeadArrKata(&key);
    }
    printf("\n");
    return;
}

#endif