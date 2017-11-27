//Nama / NIM		: Dionesius Agung Andika P / 13516043
//Tanggal			: 27 September 2017
//Topik praktikum	: Mesin kata

#include "mesinkata.h"
#include "mesinkar.h"
#include <stdio.h>
#include <math.h>
#include "boolean.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while(CC==BLANK && CC!=MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(){
    START();
    IgnoreBlank();
    if(CC==MARK){
        EndKata = true;
    }
    else{
        EndKata = false;
        SalinKata();
    }

}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */



void ADVKATA(){
    IgnoreBlank();
    if(CC==MARK){
        EndKata = true;
    }
    else{
        SalinKata();
    }

}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */


void SalinKata(){
    int i = 1;
    while((CC!=MARK && CC!=BLANK) && i<=NMax) {
        CKata.TabKata[i] = CC;
        i++;
        ADV();
    }
    if (i>=NMax){
        EndKata = true;
    }
    CKata.Length = i-1;
    IgnoreBlank();
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int KataToInt (Kata K){
    int i, power, result;

    result = 0;
    for (i=1;i<=K.Length;i++) {
        power = K.Length-i;
        result = result + (((int) (pow(10,power))) * (K.TabKata[i]-'0'));
    }

    return result;
}
/* Mengubah tipe data dari Kata menjadi integer
   Hanya berlaku untuk kata numerik
   Contoh: Kata 100 menjadi int 100 */

boolean IsKataSama (Kata K1,Kata K2){
    int i = 1;
    boolean iSama = true;
    if (K1.Length != K2.Length){
        iSama = false;
    }
    else {
        while ((i<=K1.Length) && (iSama)) {
            if (K1.TabKata[i] != K2.TabKata[i]) {
                iSama = false;
            }
            else {
                i++;
            }
        }
    }
    return iSama;
}
/* Mereturn true jika Kata K1 dan K2 sama, false jika beda */