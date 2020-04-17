#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pengacakan/pengacakan.h"
#include "lookup/lookup.h"
#include "konfigurasi/konfigurasi.h"
#include "input/input.h"
#include "flow/flow.h"


int main()
{
    //deklarasi variabel
    arrKata *dict, *inText, key, *value;
    char *outVal;
    int n, banyak_kata, printed = 0;
    time_t t;

    //set seed utk random
    srand((unsigned) time(&t));
    printf("                            Welcome to N-Gram Simulation\n");
    printf("                                Delivered by Group C6\n");
    printf("\n");
    printf("__________________________________________________________________________________________\n");
    printf("\n");
    printf("1.Kendrik Emkel Ginting 13218077\n");
    printf("2.Rizki Habibi Alamsyah 13218080\n");
    printf("3.Mohammad Salman Subki 13218078\n");
    printf("4.Anindhita Nayazirly   13218083\n");
    printf("5.Michael Kresna Putra  13218066\n");
    printf("\n");
    printf("Dalam dunia computational linguistics dan probabilitas dikenal istilah n-gram, yaitu rangkaian\nkata-kata, fonem, huruf, suku kata, atau yang lainnya dari sebuah teks atau kalimat. Model\nn-gram merupakan pendekatan bahasa menggunakan konsep probabilitas untuk memprediksi atau\nmenebak kata selanjutnya dari suatu rangkaian kata-kata.\n");
    printf("\n");
    int isEnd=0;

    while(isEnd==0){
        char End[5];
        //insialisasi arrKata inText
        initializeArrKata(&inText);
        initializeArrKata(&value);

        //User input text, value of n, banyak kata yang ingin dicetak
        inputText(inText);
        inputN(&n);
        inputBanyakKata(&banyak_kata);
        
        //membuat dictionary
        createDictionary(n, *inText, &dict);

        while(banyak_kata != 0){
            //mengambil key pertama secara random
            key = getRandomKey(dict, n);

            //mencetk n kata pertama (key pertama)
            printf("... ");
            while (printed < n)
            {
                printf("%s ", key.array[printed]);
                printed += 1;
            }
            
            // pada tahap ini printed = n, printed adalah counter berapa banyak yg sudah dicetak

            //memperoleh value berdasarkan key (fungsi blm terdefinisi)
            lookupDictionary(dict, n, key, &value);

            //merandom value yang akan dicetak
            outVal = randomWord(value);

            //mencetak outVal (salah satu value dari key sebelumnya), increment counter
            printf("%s ", outVal);
            printed += 1;

            //append outVal ke dalam key
            pushArrKata(&key, outVal);
            //geser head key->array[0] = key->array[1]
            deleteHeadArrKata(&key);

            //looping hingga printed = banyak_kata
            Flow(key, dict, n, printed, banyak_kata);
            printf("...\n\n");
            printf("Masukkan jumlah kata random yang ingin dicetak kembali dengan input yang sama. Jika tidak, masukkan 0.\n");
            inputBanyakKata(&banyak_kata);
        }
        
        printf("Apakah Anda Ingin Melakukan Pembacaan Lagi? (Yes/No)\n");
        scanf("%s", End);
        if (strcmp("Yes", End)){
            isEnd=1;
        }
    }
    return 0;
}