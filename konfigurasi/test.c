#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "konfigurasi.h"

#define MAX_WORD_LENGTH 255


// pilih satu test case
// #define TEST_CASE_1
// #define TEST_CASE_2
// #define TEST_CASE_3
#define TEST_CASE_4

int main(){

  #ifdef TEST_CASE_1
  arrKata arr_kata;
  initializeArrKata(&arr_kata);

  char a[MAX_WORD_LENGTH];
  printf("insert two words: ");
  scanf("%s", a);
  pushArrKata(&arr_kata, a);
  scanf("%s", a);
  pushArrKata(&arr_kata, a);

  printf("awal : ");
  printArrKata(arr_kata);
  deleteHeadArrKata(&arr_kata);
  printf("deleteHead : ");
  printArrKata(arr_kata);
  pushArrKata(&arr_kata, "suka gitu");
  printf("push : ");
  printArrKata(arr_kata);

  freeArrKata(&arr_kata);
  #endif

  #ifdef TEST_CASE_2
  arrKata arr_kata;
  initializeArrKata(&arr_kata);
  char *filename = "text1.txt";
  FILE *fptr = fopen(filename, "r");
  char word[MAX_WORD_LENGTH];
  while (fscanf(fptr, " %s", word) == 1) {
    pushArrKata(&arr_kata, word);
  }
  printArrKata(arr_kata);
  freeArrKata(&arr_kata);
  #endif

  #ifdef TEST_CASE_3
  // initialize
  arrKata* dict;
  dict = NULL;

  int n = 2;

  arrKata key;
  initializeArrKata(&key);
  pushArrKata(&key, "the");
  pushArrKata(&key, "quick");
  pushDictionary(&dict, &key, "brown", n);

  initializeArrKata(&key);
  pushArrKata(&key, "the");
  pushArrKata(&key, "quick");
  pushDictionary(&dict, &key, "fox", n);

  initializeArrKata(&key);
  pushArrKata(&key, "the");
  pushArrKata(&key, "quick");
  pushDictionary(&dict, &key, "jumped", n);

  initializeArrKata(&key);
  pushArrKata(&key, "over");
  pushArrKata(&key, "the");
  pushDictionary(&dict, &key, "lazy", n);

  initializeArrKata(&key);
  pushArrKata(&key, "over");
  pushArrKata(&key, "the");
  pushDictionary(&dict, &key, "cats", n);

  printDictionary(*dict, n);

  freeDictionary(dict);
  #endif


  #ifdef TEST_CASE_4
  int n = 2;

  arrKata arr_kata;
  initializeArrKata(&arr_kata);
  char *filename = "text2.txt";
  FILE *fptr = fopen(filename, "r");
  char word[MAX_WORD_LENGTH];

  while (fscanf(fptr, " %s", word) == 1) {
    pushArrKata(&arr_kata, word);
  }
  printArrKata(arr_kata);

  // buat dictionary
  arrKata *dict;
  dict = NULL;

  arrKata *current = dict;
  for (int i = 0; i < arr_kata.length - n; i++) {
    arrKata key;
    initializeArrKata(&key);

    for (int j = 0; j < n; j++) {
      pushArrKata(&key, arr_kata.array[i+j]);
    }
    char *value = arr_kata.array[i+n];
    pushDictionary(&dict, &key, value, n);
  }
  printDictionary(*dict, n);

  freeArrKata(&arr_kata);
  freeDictionary(dict);
  #endif


  return 0;
}
