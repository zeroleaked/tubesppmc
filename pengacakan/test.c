#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "pengacakan.h"
#include "../konfigurasi/konfigurasi.h"

int main(){
    int n = 2;

  arrKata arr_kata;
  initializeArrKata(&arr_kata);
  char *filename = "test aja.txt";
  FILE *fptr = fopen(filename, "r");
  char word[MAX_WORD_LENGTH];

  while (fscanf(fptr, " %s", word) == 1) {
    pushArrKata(&arr_kata, word);
  }
  printArrKata(arr_kata);

  // buat dictionary
  arrKata *dict;
  initializeDictionary(&dict);

  arrKata *current = dict;
  for (int i = 0; i < arr_kata.length - n; i++) {
    arrKata key;
    initializeArrKata(&key);

    for (int j = 0; j < n; j++) {
      pushArrKata(&key, arr_kata.array[i+j]);
    }
    char *value = arr_kata.array[i+n];
    pushDictionary(&dict, &key, value, n);
    freeArrKata(&key);
  }
  freeArrKata(&arr_kata);
  printDictionary(*dict, n);
  printf("length = %d\n", getDictionaryLength(dict));
  arrKata query = peekDictionary(dict, 1);
  printArrKata(query);

  freeDictionary(&dict);


}


