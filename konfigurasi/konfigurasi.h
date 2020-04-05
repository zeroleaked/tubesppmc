typedef struct{
    char **array;
    int length;
} arrKata;

typedef struct{
    arrKata *key, *value;
    int length;
} dictionary;

void initializeArrKata(arrKata *arr_kata);
void pushArrKata(arrKata *arr_kata, char *kata);
void printArrKata(arrKata arr_kata);
void freeArrKata(arrKata *arr_kata);
void deleteHeadArrKata (arrKata *arr_kata);
