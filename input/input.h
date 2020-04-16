#include "../konfigurasi/konfigurasi.h"
#include<stdio.h>

void inputN (int *n)
{
    printf("Masukkan N : ");
    scanf("%d", n);
}

void inputBanyakKata (int *banyak_kata)
{
    printf("Masukkan Jumlah Kata Yang Akan Dicetak : ");
    scanf("%d", banyak_kata);
}

void inputText (arrKata *input_text)
{
    char nfile[255],temp[255];
    FILE*text;

    printf("Sok Mangga Dipilih Textnya:\n");
    printf("APoemFromAFriend.txt\ncisneros.txt\nhamlet.txt\nhurston.txt\nisiguro.txt\nladygaga.txt\nmobydick.txt\nmorrison.txt\nshort.txt\ntiny.txt\ntomsawyer.txt\nTextReference_13218066.txt\nTextReference_13218077.txt\n");
    printf("Atau Masukkan Pilihan Teksmu.");
    printf("\n");
    printf("Format Nama File --> input/[Text yang dipilih]\n");
    printf("\n");
    printf("Masukkan Nama file : ");
    scanf("%s", nfile);

    text=fopen(nfile,"r");

    while(fscanf(text,"%s", temp)!=EOF)
    {
        pushArrKata(input_text, temp);
    }
}
