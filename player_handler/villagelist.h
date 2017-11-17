// /* Representasi villagelist_address dengan pointer */
// /* villagelist_infotype adalah Building */

// #ifndef villagelist_H
// #define villagelist_H

// #include "../unit.h"
// #include "../ADT/boolean.h"
// #include <stdlib.h>

// #define Nil NULL

// typedef Build villagelist_infotype;
// typedef struct tElmtlist *villagelist_address;
// typedef struct tElmtlist { 
// 	villagelist_infotype info;
// 	villagelist_address next;
// } ElmtList;
// typedef struct {
// 	villagelist_address First;
// } VillageList;

// /* Definisi list : */
// /* List kosong : First(L) = Nil */
// /* Setiap elemen dengan villagelist_address P dapat diacu Info(P), Next(P) */
// /* Elemen terakhir list : jika villagelist_addressnya Last, maka Next(Last)=Nil */
// #define villagelist_elmt_Info(P) (P)->info
// #define villagelist_elmt_Next(P) (P)->next
// #define villagelist_First(L) ((L).First)

// /* PROTOTYPE */
// /****************** TEST LIST KOSONG ******************/
// boolean villagelist_IsEmpty (VillageList L);
// /* Mengirim true jika list kosong */

// /****************** PEMBUATAN LIST KOSONG ******************/
// void villagelist_CreateEmpty (VillageList *L);
// /* I.S. sembarang             */
// /* F.S. Terbentuk list kosong */

// /****************** Manajemen Memori ******************/
// villagelist_address villagelist_Alokasi (villagelist_infotype X);
// /* Mengirimkan villagelist_address hasil alokasi sebuah elemen */
// /* Jika alokasi berhasil, maka villagelist_address tidak nil, dan misalnya */
// /* menghasilkan P, maka info(P)=X, Next(P)=Nil */
// /* Jika alokasi gagal, mengirimkan Nil */
// void villagelist_Dealokasi (villagelist_address *P);
// /* I.S. P terdefinisi */
// /* F.S. P dikembalikan ke sistem */
// /* Melakukan dealokasi/pengembalian villagelist_address P */

// /****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
// villagelist_address villagelist_Search (VillageList L, villagelist_infotype X);
// /* Mencari apakah ada elemen list dengan info(P)= X */
// /* Jika ada, mengirimkan villagelist_address elemen tersebut. */
// /* Jika tidak ada, mengirimkan Nil */
// boolean villagelist_FSearch (VillageList L, villagelist_address P);
// /* Mencari apakah ada elemen list yang beralamat P */
// /* Mengirimkan true jika ada, false jika tidak ada */
// villagelist_address villagelist_SearchPrec (VillageList L, villagelist_infotype X);
// /* Mengirimkan villagelist_address elemen sebelum elemen yang nilainya=X */
// /* Mencari apakah ada elemen list dengan Info(P)=X */
// /* Jika ada, mengirimkan villagelist_address Prec, dengan Next(Prec)=P dan Info(P)=X. */
// /* Jika tidak ada, mengirimkan Nil */
// /* Jika P adalah elemen pertama, maka Prec=Nil */
// /* Search dengan spesifikasi seperti ini menghindari */
// /* traversal ulang jika setelah Search akan dilakukan operasi lain */

// /****************** PRIMITIF BERDASARKAN NILAI ******************/
// /*** PENAMBAHAN ELEMEN ***/
// void villagelist_InsVFirst (VillageList *L, villagelist_infotype X);
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
// void villagelist_InsVLast (VillageList *L, villagelist_infotype X);
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen list di akhir: elemen terakhir yang baru */
//  bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. 

// /*** PENGHAPUSAN ELEMEN ***/
// void villagelist_DelVFirst (VillageList *L, villagelist_infotype *X);
// /* I.S. VillageList L tidak kosong  */
// /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen pertama di-dealokasi */
// void villagelist_DelVLast (VillageList *L, villagelist_infotype *X);
// /* I.S. list tidak kosong */
// /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen terakhir di-dealokasi */

// /****************** PRIMITIF BERDASARKAN ALAMAT ******************/
// /*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void villagelist_InsertFirst (VillageList *L, villagelist_address P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-villagelist_address P sebagai elemen pertama */
// void villagelist_InsertAfter (VillageList *L, villagelist_address P, villagelist_address Prec);
// /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// void villagelist_InsertLast (VillageList *L, villagelist_address P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void villagelist_DelFirst (VillageList *L, villagelist_address *P);
// /* I.S. VillageList tidak kosong */
// /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
// void villagelist_DelP (VillageList *L, villagelist_infotype X);
// /* I.S. Sembarang */
// /* F.S. Jika ada elemen list bervillagelist_address P, dengan info(P)=X  */
// /* Maka P dihapus dari list dan di-dealokasi */
// /* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
// /* VillageList mungkin menjadi kosong karena penghapusan */
// void villagelist_DelLast (VillageList *L, villagelist_address *P);
// /* I.S. VillageList tidak kosong */
// /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen terakhir yg lama, */
// /* jika ada */
// void villagelist_DelAfter (VillageList *L, villagelist_address *Pdel, villagelist_address Prec);
// /* I.S. VillageList tidak kosong. Prec adalah anggota list  */
// /* F.S. Menghapus Next(Prec): */
// /*      Pdel adalah alamat elemen list yang dihapus  */

// /****************** PROSES SEMUA ELEMEN LIST ******************/
// void villagelist_PrintInfo (VillageList L);
// /* I.S. VillageList mungkin kosong */
// /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
// int villagelist_NbElmt (VillageList L);
// /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

// /****************** PROSES TERHADAP LIST ******************/
// void villagelist_DelAll (VillageList *L);
// /* Delete semua elemen list dan alamat elemen di-dealokasi */

// #endif