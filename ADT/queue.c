
/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 06   */
/*   29 Sept 2017   */
/*------------------*/

/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */
/* Versi I : tabel dinamik, queue_Head dan queue_Tail eksplisit, ukuran disimpan */
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define queue_Head(Q) (Q).HEAD
#define queue_Tail(Q) (Q).TAIL
#define queue_InfoHead(Q) (Q).T[(Q).HEAD]
#define queue_InfoTail(Q) (Q).T[(Q).TAIL]
#define queue_MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean queue_IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((queue_Head(Q) == Nil) && (queue_Tail(Q) == Nil));
}

boolean queue_IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak queue_MaxEl */
{
    int CountEl = (((queue_Tail(Q)-queue_Head(Q) + queue_MaxEl(Q)) %queue_MaxEl(Q))+ 1 );

    return (CountEl == queue_MaxEl(Q));
}

int queue_NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{

    if (queue_IsEmpty(Q)){
        return 0;
    }

    int CountEl = (((queue_Tail(Q)-queue_Head(Q) + queue_MaxEl(Q)) %queue_MaxEl(Q)) + 1 );     //  REMEMBER TO MOD FIRST THEN INCREMENT
    return (CountEl);
}

/* *** Kreator *** */
void queue_CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg queue_MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (queue_infotype *) malloc ((Max+1) * sizeof(queue_infotype));

    if ((*Q).T != NULL) {
        queue_MaxEl(*Q) = Max;
        queue_Head(*Q) = Nil;
        queue_Tail(*Q) = Nil;

    } else /* alokasi gagal */ {
        queue_MaxEl(*Q) = 0;

    }

}

/* *** Destruktor *** */
void queue_Dealokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, queue_MaxEl(Q) diset 0 */
{
    queue_MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void queue_Add (Queue * Q, queue_infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh                  >>>>>   HAVE TO MAKE SURE IT'S NOT FULL !!  */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{

    if (queue_IsEmpty(*Q)){
        queue_Head(*Q) = 1;
        queue_Tail(*Q) = 1;
        queue_InfoTail(*Q) = X;
    }

    /* If not empty */
    else {
        queue_Tail(*Q) = (queue_Tail(*Q) % queue_MaxEl(*Q)) + 1;
        queue_InfoTail(*Q) = X;
    }


}


void queue_Del (Queue * Q, queue_infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (queue_NBElmt(*Q) == 1){

        *X = queue_InfoHead(*Q);
        queue_Head(*Q) = 0;
        queue_Tail(*Q) = 0;

    }
    /* If contains more than one element */
    else{
        *X = queue_InfoHead(*Q);
        queue_Head(*Q) = (queue_Head(*Q) % queue_MaxEl(*Q)) + 1;
    }
}

void queue_PrintQ (Queue Q){



    if (queue_IsEmpty(Q)){
        printf("Empty queue");
    }
    else{

        int i = queue_Head(Q);

        printf("queue_Head : %d\n",queue_Head(Q));
        printf("queue_Tail : %d\n",queue_Tail(Q));
        printf("Jumlah el : %d\n",queue_NBElmt(Q));
        printf("element : ");

        while(i != (queue_Tail(Q) + 1 ))
        {
            printf("[%d] > %d ",i,Q.T[i]);
            i = (i % queue_MaxEl(Q)) + 1;
        }
    }
}
