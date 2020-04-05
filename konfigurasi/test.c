#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "konfigurasi.h"

#define MAX_WORD_LENGTH 255

// #define TEST_CASE_1
#define TEST_CASE_2

int main(){

  arrKata arr_kata;
  initializeArrKata(&arr_kata);


  #ifdef TEST_CASE_1
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
  #endif

  #ifdef TEST_CASE_2
  char *filename = "text1.txt";
  FILE *fptr = fopen(filename, "r");
  char word[MAX_WORD_LENGTH];
  while (fscanf(fptr, " %s", word) == 1) {
    pushArrKata(&arr_kata, word);
  }
  printArrKata(arr_kata);
  #endif

  freeArrKata(&arr_kata);

  return 0;
}
