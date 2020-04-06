// dict adalah pointer ke arrKata. 

typedef struct arrKata{
    int length;
    struct arrKata *next; // untuk dict
    char **array;
} arrKata;

// harus dipanggil setelah deklarasi arr_kata, sebelum prosedur arrKata lainnya
void initializeArrKata(arrKata *arr_kata);

// menambahkan kata ke akhir arr_kata dan menambahkan length
void pushArrKata(arrKata *arr_kata, char *kata);

// mencetak arr_kata ke console
void printArrKata(arrKata arr_kata);

// harus dipanggil ketika arr_kata telah selesai dipakai
void freeArrKata(arrKata *arr_kata);



//initialize dictionary lihat TEST_CASE_3

// jika key tidak ada di dict, menambahkan key baru
void pushDictionary(arrKata **dict, arrKata *key, char *value, int n);

// print setiap pasangan key-value yang ada di dict, n adalah banyak kata pada key
void printDictionary(arrKata dict, int n);

// harus dipanggis ketika dict selesai dipakai
void freeDictionary(arrKata *dict);

// membandingkan dua key, apabila sama maka True, apabila beda maka false, n adalah banyak kata pada key
int compareKey(arrKata dict1, arrKata dict2, int n);

// Kalau butuh fungsi lain, ngobrol ya
