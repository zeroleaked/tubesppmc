typedef struct arrKata{
    int length;
    struct arrKata *next;
    char **array;
} arrKata;

void initializeArrKata(arrKata *arr_kata);
void pushArrKata(arrKata *arr_kata, char *kata);
void printArrKata(arrKata arr_kata);
void freeArrKata(arrKata *arr_kata);
void deleteHeadArrKata (arrKata *arr_kata);

//initialize dictionary Lihat TEST_CASE_3
void pushDictionary(arrKata **dict, arrKata *key, char *value, int n);
void printDictionary(arrKata dict, int n);
void freeDictionary(arrKata *dict);
int compareKey(arrKata dict1, arrKata dict2, int n);
