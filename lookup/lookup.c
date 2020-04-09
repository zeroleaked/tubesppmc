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
