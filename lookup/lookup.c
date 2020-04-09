#include "../konfigurasi/konfigurasi.h"

#include <stdio.h>

void createDictionary(int n, arrKata input_text, arrKata **dict) {
  initializeDictionary(dict);

  arrKata *current = *dict;
  for (int i = 0; i < input_text.length - n; i++) {
    arrKata key;
    initializeArrKata(&key);

    for (int j = 0; j < n; j++) {
      pushArrKata(&key, input_text.array[i+j]);
    }
    char *value = input_text.array[i+n];
    pushDictionary(dict, &key, value, n);
    freeArrKata(&key);
  }
}

void lookupDictionary (arrKata *dict, int n, arrKata key, arrKata *value) {
  printf("finding ");
  printArrKata(key);
  printf("\n");

  initializeArrKata(value);
  int dictionary_length = getDictionaryLength(dict);
  for (int i = 0; i < dictionary_length; i ++) {
    arrKata dictionary_entry = peekDictionary(dict, i);
    if (compareKey( key, dictionary_entry, n )) {
      for (int i = n; i < dictionary_entry.length; i ++) {
        pushArrKata(value, dictionary_entry.array[i]);
      }
      return;
    }
  }
  printf("not found\n");

}
