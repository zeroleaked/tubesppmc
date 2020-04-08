#include<stdio.h>
#include"konfigurasi.h"

void inputN (int *n)
{
    printf("Masukkan n : ");
    scanf("%d",n);
}

void inputBanyakKata (int *banyak_kata)
{
    printf("Masukkan jumlah kata yang akan dicetak : ");
    scanf("%d",banyak_kata);
}

void inputText (arrKata *input_text)
{
    char nfile[20],temp[20];
    FILE*text;

    printf("Masukkan nama file : ");
    scanf("%s",&nfile);

    text=fopen(("%s",nfile),"r+");

    while(fscanf(text,"%s",&temp)!=EOF)
    {
        pushArrKata(input_text, temp);
    }
}
