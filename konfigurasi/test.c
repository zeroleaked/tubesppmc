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
  int n = 2;

  arrKata key1;
  initializeArrKata(&key1);
  pushArrKata(&key1, "the");
  pushArrKata(&key1, "quick");

  arrKata val1;
  initializeArrKata(&val1);
  pushArrKata(&val1, "brown");
  pushArrKata(&val1, "fox");
  pushArrKata(&val1, "jumped");

  arrKata key2;
  initializeArrKata(&key2);
  pushArrKata(&key2, "over");
  pushArrKata(&key2, "the");

  arrKata val2;
  initializeArrKata(&val2);
  pushArrKata(&val2, "lazy");
  pushArrKata(&val2, "white");
  pushArrKata(&val2, "Calico");
  pushArrKata(&val2, "cat");

  // initialize
  arrKata* dict;
  dict = NULL;

  pushDictionary(&dict, &key1, &val1);
  pushDictionary(&dict, &key2, &val2);

  // printArrKata(*dict);

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

  while (fscanf(fptr, " %s", word) == 1 && arr_kata.length < 20) {
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
