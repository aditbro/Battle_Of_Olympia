
/* NOTES */

/* Stack disusun dengan tabel */
/* TOP adalah INDEKS elemen TERAKHIR */

/* Nil = 0 ,, MaxEl = 10 */
/* Definisi stack S kosong : S.TOP = Nil */
/* stack_Top(S) untuk akses INDEKS top , stack_InfoTop(S) untuk akses value top */



#include "stackt.h"
#include <stdio.h>

#define Nil 0
#define MaxEl 100
#define stack_Top(S) (S).TOP
#define stack_InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void stack_CreateEmpty (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    stack_Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean stack_IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return stack_Top(S) == Nil;
}

boolean stack_IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return stack_Top(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void stack_Push (Stack * S, stack_infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (stack_IsEmpty(*S)){
        stack_Top(*S) = 1;
    }

    else {
        stack_Top(*S) += 1;
    }

    stack_InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void stack_Pop (Stack * S, stack_infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = stack_InfoTop(*S);

    if (stack_Top(*S) == 1){
        stack_CreateEmpty(S);
    }

    else{
        stack_Top(*S) -= 1;
    }
}

// void PrintStack(Stack S);
void stack_PrintStack(Stack S)
{
    int i;

    for (i = stack_Top(S); i > 0; i--){
        printf("%d -> %d ",i, S.T[i]);

        if (i == stack_Top(S)){
            printf("<top>");
        }

        printf("\n");
    }
}
