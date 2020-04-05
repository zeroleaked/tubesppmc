#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "konfigurasi.h"

#define MAX_WORD_LENGTH 255

int main(){
  char *filename = "text1.txt";
  FILE *fptr = fopen(filename, "r");


  arrKata arr_kata;
  initializeArrKata(&arr_kata);

  char a[MAX_WORD_LENGTH];
  printf("insert two words: ");
  scanf("%s", a);
  pushArrKata(&arr_kata, a);
  scanf("%s", a);
  pushArrKata(&arr_kata, a);

  printArrKata(arr_kata);
  deleteHeadArrKata(&arr_kata);
  printArrKata(arr_kata);
  pushArrKata(&arr_kata, "suka gitu");
  printArrKata(arr_kata);

  // arr_kata.array = realloc(arr_kata.array, )

  // char word[MAX_WORD_LENGTH];
  // while (fscanf(fptr, " %s", word) == 1) {
  //   pushArrKata(&arr_kata, word);
  // }
  // printf("before pop : ");
  // printArrKata(arr_kata);

  //
  // printf("after pop : ");
  // printArrKata(arr_kata);

  freeArrKata(&arr_kata);

  return 0;
}
