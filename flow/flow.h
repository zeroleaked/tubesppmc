/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : C6
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : flow.h
* Deskripsi : Program untuk mengatur 'aliran' (flow)
keberjalanan program utama memanfaatkan fungsi-fungsi yang telah dibuat
pada bagian sebelumnya untuk memecahkan masalah dan mengeluarkan output.
*/

//Flow oleh Kendrik Emkel Ginting

#include <stdio.h>
#include "../lookup/lookup.h"
#include "../pengacakan/pengacakan.h"

#ifndef FLOW
#define FLOW

void Flow(arrKata key, arrKata *lookup_table, int n, int printed, int banyak_kata)
{
    //deklarasi variabel
    arrKata *value;
    char *outVal;
    
    while (printed < banyak_kata)
    {
        //obtain values by key, output to *value. More than 1 values is possible
        initializeArrKata(&value);
        lookupDictionary(lookup_table, n, key, &value);
        //printArrKata(value);
        
        //get one value from the values obtained in prev step
        outVal = randomWord(value);

        //print the value obtained, increment counter
        printf("%s ", outVal);
        printed += 1;

        //push value ke key, lalu geser head dari key
        pushArrKata(&key, outVal);
        deleteHeadArrKata(&key);
    }
    return;
}

#endif
