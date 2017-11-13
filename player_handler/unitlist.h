/* Representasi unitlist_address dengan pointer */
/* unitlist_infotype adalah UNIT */

#ifndef unitlist_H
#define unitlist_H

#include "../unit.h"
#include "boolean.h"
#include <stdlib.h>

#define Nil NULL

typedef UNIT unitlist_infotype;
typedef struct tElmtlist *unitlist_address;
typedef struct tElmtlist { 
	unitlist_infotype info;
	unitlist_address next;
} ElmtList;
typedef struct {
	unitlist_address First;
} UnitList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan unitlist_address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika unitlist_addressnya Last, maka Next(Last)=Nil */
#define unitlist_elmt_Info(P) (P)->info
#define unitlist_elmt_Next(P) (P)->next
#define unitlist_First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean unitlist_IsEmpty (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void unitlist_CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
unitlist_address unitlist_Alokasi (unitlist_infotype X);
/* Mengirimkan unitlist_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka unitlist_address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void unitlist_Dealokasi (unitlist_address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian unitlist_address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
unitlist_address unitlist_Search (List L, unitlist_infotype X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan unitlist_address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
boolean unitlist_FSearch (List L, unitlist_address P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
unitlist_address unitlist_SearchPrec (List L, unitlist_infotype X);
/* Mengirimkan unitlist_address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan unitlist_address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void unitlist_InsVFirst (List *L, unitlist_infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void unitlist_InsVLast (List *L, unitlist_infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void unitlist_DelVFirst (List *L, unitlist_infotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void unitlist_DelVLast (List *L, unitlist_infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void unitlist_InsertFirst (List *L, unitlist_address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-unitlist_address P sebagai elemen pertama */
void unitlist_InsertAfter (List *L, unitlist_address P, unitlist_address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void unitlist_InsertLast (List *L, unitlist_address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void unitlist_DelFirst (List *L, unitlist_address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void unitlist_DelP (List *L, unitlist_infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berunitlist_address P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void unitlist_DelLast (List *L, unitlist_address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void unitlist_DelAfter (List *L, unitlist_address *Pdel, unitlist_address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void unitlist_PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int unitlist_NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
void unitlist_DelAll (List *L);
/* Delete semua elemen list dan alamat elemen di-dealokasi */

#endif