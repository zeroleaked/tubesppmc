// CARA RUN
// >> gcc test.c lookup.c ../konfigurasi/konfigurasi.c -o a
// >> ./a

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../konfigurasi/konfigurasi.h"
#include "lookup.h"

#define MAX_WORD_LENGTH 255

// pilih satu test case
#define TEST_CASE_1
// #define TEST_CASE_2
// #define TEST_CASE_3
// #define TEST_CASE_4
// #define TEST_CASE_5

int main(){

  #ifdef TEST_CASE_1
  int n = 2;

  arrKata arr_kata;
  initializeArrKata(&arr_kata);
  char *filename = "../konfigurasi/text2.txt";
  FILE *fptr = fopen(filename, "r");
  char word[MAX_WORD_LENGTH];

  while (fscanf(fptr, " %s", word) == 1) {
    pushArrKata(&arr_kata, word);
  }
  printArrKata(arr_kata);
  printf("\n");

  // buat dictionary
  arrKata *dict;

  createDictionary(n, arr_kata, &dict);

  freeArrKata(&arr_kata);
  printDictionary(*dict, n);
  printf("length = %d\n", getDictionaryLength(dict));

  printf("dict[1] = ");
  arrKata query = peekDictionary(dict, 1);
  printArrKata(query);
  printf("\n");

  freeDictionary(&dict);
  #endif

  return 0;
}
