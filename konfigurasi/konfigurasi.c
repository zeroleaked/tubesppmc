#include "konfigurasi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initializeArrKata(arrKata *ptr) {
  ptr->array = NULL;
  ptr->length = 0;
}

void printArrKata(arrKata arr_kata) {
  printf("[");
  for (int i = 0; i < arr_kata.length; i++) {
    if (i) printf(", ");
    printf("\"%s\"", arr_kata.array[i]);
  }
  printf("]\n");
}

// menghapus dan
void pushArrKata(arrKata *arr_kata, char *kata){
  arr_kata->length ++;
  arr_kata->array = realloc(arr_kata->array, arr_kata->length * sizeof(char*));
  arr_kata->array[arr_kata->length-1] = strdup(kata);
}

void deleteHeadArrKata (arrKata *arr_kata) {
  arr_kata->length--;
  char *temp = arr_kata->array[0];
  memmove(arr_kata->array, arr_kata->array+1, arr_kata->length*sizeof(char*));
}

void freeArrKata(arrKata *arr_kata) {
  free(arr_kata->array);
}
