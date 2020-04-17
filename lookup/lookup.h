/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : C6
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Sarah Az Zahra (13216099)
* Nama File : lookup.h
* Deskripsi : Program untuk membuat dictionary (lookup tabel)
dan menggunakan dictionary tersebut(menggunakan nilai key)
*/

#include "../konfigurasi/konfigurasi.h"

#ifndef LOOKUP_H
#define LOOKUP_H

void createDictionary(int n, arrKata input_text, arrKata **dict);

void lookupDictionary (arrKata *dict, int n, arrKata key, arrKata **value);

void createDictionary(int n, arrKata input_text, arrKata **dict) {
  initializeDictionary(dict);
  arrKata *current = *dict;
   for (int i = 0; i < input_text.length; i++) {
     arrKata *key;
     initializeArrKata(&key);
    
     for (int j = 0; j < n; j++) {
       pushArrKata(key, input_text.array[(i+j)%input_text.length]);
     }
     char *value;
     value = input_text.array[(i+n)%input_text.length];
     pushDictionary(dict, key, value, n);
     freeArrKata(key);
    }
}

void lookupDictionary (arrKata *dict, int n, arrKata key, arrKata **value) {
  //printf("finding ");
  //printArrKata(key);
  //printf("\n");
  
  initializeArrKata(value);
  int dictionary_length = getDictionaryLength(dict);
  for (int i = 0; i < dictionary_length; i ++) {
    arrKata dictionary_entry = peekDictionary(dict, i);
    if (compareKey( key, dictionary_entry, n )) {
      for (int i = n; i < dictionary_entry.length; i ++) {
        pushArrKata(*value, dictionary_entry.array[i]);
      }
      return;
    }
  }
  printf("not found\n");
}

#endif
