

/* Tugas ADT ALSTRUKDAT 03 */

/* 5 Sept 2017 */
/* Jessin Donnyson */
/* 13516112 */

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "array.h"
#include <stdio.h>

/*

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999

*/

/*
typedef int array_IdxType;
typedef int array_ElType;
typedef struct {
	array_ElType TI[IdxMax+1];
	int array_Neff;  >=0, banyaknya elemen efektif
} TabInt; */

/* Indeks yang digunakan [IdxMin..IdxMax] */

/* Definisi :
  Tabel kosong: T.array_Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.array_Neff */


/* ********** SELEKTOR ********** */

/*
#define array_Neff(T)   (T).array_Neff
#define array_TI(T)     (T).TI
#define array_Elmt(T,i) (T).TI[(i)]
*/


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void array_MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    array_Neff(*T) = 0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int array_NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return array_Neff(T);
}

int array_MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return IdxMax;
}

array_IdxType array_GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

array_IdxType array_GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return array_Neff(T);
}


/* ********** Test Indeks yang valid ********** */
boolean array_IsIdxValid (TabInt T, array_IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin)&&(i <= IdxMax));
}

boolean array_IsIdxEff (TabInt T, array_IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= array_GetFirstIdx(T))&&(i <= array_GetLastIdx(T)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean array_IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (array_Neff(T)==0);
}

/* *** Test tabel penuh *** */
boolean array_IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (array_Neff(T)==(IdxMax-IdxMin+1));
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void array_BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int N;
    int num;
    int i;

    do {
        scanf("%d",&N);
    }
    while (!((N>=0) && (N <= array_MaxNbEl(*T))));

    if (N ==0 ){
        array_MakeEmpty(&T);
    }

    array_Neff(*T) = N;
    for ( i = IdxMin;(i< N);i++){
        scanf("%d\n",&num);
        array_Elmt(*T,i) = num;
    }

    if (!IsEmpty(*T)){
    scanf("%d",&num);
    array_Elmt(*T,array_Neff(*T)) = num;}
}

void array_BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    int num;
    int i = IdxMin;

    while(1){


        if(i > IdxMax){
                /* Just in case filled up until 100 and not yet a single -9999 */
            break;
            }

        scanf("%d",&num);

        if (num == (-9999)){
            break;
        }

        else{
            array_Elmt(*T,i) = num;
            i += 1;
        }
    }
    array_Neff(*T) = i-1;

    if (array_IsEmpty(*T)){
        array_MakeEmpty(&T);
    }

}

void array_TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    int i;

    if (array_IsEmpty(T)){
        printf("Tabel kosong\n");
    }
    else {
        for ( i = IdxMin;(i <= array_Neff(T));i++){
            printf("[%d]%d\n",i,array_Elmt(T,i));
        }

    }
}

void array_TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    int i;

    if (array_IsEmpty(T)){
        printf("[]"); /* no 32 */
    }
    else{
        printf("[");
        for ( i = IdxMin;(i < array_Neff(T));i++){
            printf("%d,",array_Elmt(T,i));
        }
        printf("%d]",array_Elmt(T,array_Neff(T)));
    }
}



/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt array_PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    TabInt Tsum;
    int i;

    for ( i=IdxMin;(i<=array_Neff(T1));i++){
        array_Elmt(Tsum,i) = array_Elmt(T1,i) + array_Elmt(T2,i);
    }
    array_Neff(Tsum) = array_Neff(T1);

    return Tsum;
}

TabInt array_MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt Tdim;
    int i;

    for ( i=IdxMin;(i<=array_Neff(T1));i++){
        array_Elmt(Tdim,i) = array_Elmt(T1,i) - array_Elmt(T2,i);
    }
    array_Neff(Tdim) = array_Neff(T1);

    return Tdim;
}

TabInt array_KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    TabInt Ttim;
    int i;

    for ( i=IdxMin;(i<=array_Neff(T1));i++){
        array_Elmt(Ttim,i) = array_Elmt(T1,i) * array_Elmt(T2,i);
    }
    array_Neff(Ttim) = array_Neff(T1);

    return Ttim;
}
TabInt array_KaliKons (TabInt Tin, array_ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    TabInt Ttim;
    int i;

    for ( i=IdxMin;(i<=array_Neff(Tin));i++){
        array_Elmt(Ttim,i) = array_Elmt(Tin,i) * c;
    }
    array_Neff(Ttim) = array_Neff(Tin);

    return Ttim;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean array_IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    int i;

    if (array_Neff(T1) != array_Neff(T2)){
        return false;
    }
    else{
        for ( i = IdxMin;(i<= array_Neff(T1));i++){
            if (array_Elmt(T1,i) != array_Elmt(T2,i)) {
                return false;
            }
        }
    }

    /* if the array is exactly the same */
    return true;
}

boolean array_IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < 'Badu'; maka [0, 1] < [2, 3] */
{
    int i;


    if (array_IsEQ(T1, T2)){ // check equal ?
        return false;
    }

    else{
        for ( i = IdxMin;(i <= array_Neff(T1));i++){
            if (array_Elmt(T1,i) > array_Elmt(T2,i)) {
                return false;
            }
            else if (array_Elmt(T1,i) < array_Elmt(T2,i)) {
                    return true;
            }
        }
    }
    if (array_Neff(T1) > array_Neff(T2)){
        return false;
    }

    /* if the T1 is less than T2 */
    return true;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
array_IdxType array_Search1 (TabInt T, array_ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    /* no 53 - 59 */

    int i;
    for ( i = IdxMin;(i<= array_Neff(T));i++){
            if (array_Elmt(T,i) == X){
                /* if X is found */
                return i;
            }
        }

    /* only execute if X is not found */
    return IdxUndef;
}

array_IdxType array_Search2 (TabInt T, array_ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    boolean Found = false;
    int i;

    for ( i = IdxMin;(i<= array_Neff(T));i++){
            if (array_Elmt(T,i) == X){
                Found = true;
                break;
            }
        }

    if (Found){
        return i;
    }
    else{
        return IdxUndef;
    }

}

boolean array_SearchB (TabInt T, array_ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    boolean Found = false;
    int i;

    for ( i = IdxMin;(i<= array_Neff(T));i++){
            if (array_Elmt(T,i) == X){
                Found = true;
                break;
            }
        }

    return Found;
}

boolean array_SearchSentinel (TabInt T, array_ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
    array_Elmt(T,0) = X;
    int i;

    for ( i = array_Neff(T);(i>=0);i--){
            if (array_Elmt(T,i) == X){
                if (i != 0){
                    return true;
                }
            }
        }

    return false;
}


/* ********** NILAI EKSTREM ********** */
array_ElType array_ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    int max = -32600;
    int i;

    for ( i = IdxMin; (i <= array_Neff(T)); i++){
        if (array_Elmt(T,i) > max) {
            max = array_Elmt(T,i);
        }
    }

    return max;
}
array_ElType array_ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    int min = 32600;
    int i;

    for ( i = IdxMin; (i <= array_Neff(T)); i++){
        if (array_Elmt(T,i) < min) {
            min = array_Elmt(T,i);
        }
    }

    return min;
}


/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
array_IdxType array_IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    int idx_max = IdxMin;
    int i;

    for ( i = IdxMin; (i <= array_Neff(T)); i++){
        if (array_Elmt(T,i) > array_Elmt(T,idx_max)) {
            idx_max = i;
        }
    }

    return idx_max;
}
array_IdxType array_IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{

    int idx_min = IdxMin;
    int i;
    for ( i = IdxMin; (i <= array_Neff(T)); i++){
        if (array_Elmt(T,i) < array_Elmt(T,idx_min)) {
            idx_min = i;
        }
    }

    return idx_min;
}


/* ********** OPERASI LAIN ********** */
void array_CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */

/* QUESTION : WHAT IF TOUT ALREADY HAVE MORE ARRAY ELEMENTS THAN TIN ?? */

{
    int i;
    array_Neff(*Tout) = array_Neff(Tin);
    for ( i = IdxMin; (i <= array_Neff(Tin)); i++){
        array_Elmt(*Tout,i) = array_Elmt(Tin,i);
    }
}

TabInt array_InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    TabInt InvT;
    int i;

    if (array_IsEmpty(T)){
        return T;
    }

    array_Neff(InvT) = array_Neff(T);

    for ( i = IdxMin; (i <= array_Neff(T)); i++){
        array_Elmt(InvT, (array_Neff(InvT)+1-i) ) = array_Elmt(T,i);
    }

    return InvT;
}

boolean array_IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    int i;

    for (i = IdxMin; (i <= array_Neff(T)); i++){
        if ((array_Elmt(T,i)) != (array_Elmt(T,array_Neff(T)+1-i))){
            return false;
        }
    }

    return true;
}


/* ********** SORTING ********** */
void array_MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    int i, j, max_idx;

    if (!(array_IsEmpty(*T))){
        for (i = IdxMin; (i <= (array_Neff(*T)-1)); i++)
        {
            max_idx = i;
            for (j = i+1; j <= array_Neff(*T); j++){
              if ((array_Elmt(*T,j)) > (array_Elmt(*T,max_idx))){
                   max_idx = j;
                   }
            }


            int Temp = array_Elmt(*T,max_idx);
            array_Elmt(*T,max_idx) = array_Elmt(*T, i);
            array_Elmt(*T, i) = Temp;

        }
    }

    /*array_ElType temp;
    array_IdxType i, iMax, step;
    iMax = GetFirstIdx(*T);
    if (array_Neff(*T) > 1){
        for (step = 1; step <= GetLastIdx(*T)-1; step++){
            iMax = step;
            for (i = step+1 ; i <= GetLastIdx(*T); i++){
                if (array_Elmt(*T,i) > Elmt (*T,iMax)){
                    iMax = i;
                }
            }

            temp = array_Elmt(*T,iMax);
            array_Elmt(*T, iMax) = array_Elmt(*T, step);
            array_Elmt(*T,step) = temp;
        }
    }
    */

}

void array_InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */

/*          tanpa menggunakan tabel kerja */
{

    int i, key, j;
    if (array_Neff(*T) > 1){
        for (i = IdxMin+1; (i <= array_Neff(*T)); i++){
           key = array_Elmt(*T,i);
           j = i-1;

           while ((j >= IdxMin) && (array_Elmt(*T,j) > key))
           {
               array_Elmt(*T,j+1) = array_Elmt(*T,j);
               j = j-1;
           }
           array_Elmt(*T,j+1) = key;
       }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void array_AddAsLastEl (TabInt * T, array_ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    array_Neff(*T) += 1;
    array_Elmt(*T,array_Neff(*T)) = X;
}

void array_AddEli (TabInt * T, array_ElType X, array_IdxType i)   // or maybe this one ?
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{

    int j;

    array_Neff(*T) += 1;
    for ( j = array_Neff(*T) ; (j > i); j--){
        array_Elmt(*T, j) = array_Elmt(*T, j-1);
        }
    array_Elmt(*T, i) = X;
}


/* ********** MENGHAPUS ELEMEN ********** */
void array_DelLastEl (TabInt * T, array_ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = array_Elmt(*T, GetLastIdx(*T));
    array_Neff(*T) -= 1;

    // is this X causing 104 - 107 ?? //
}

void array_DelEli (TabInt * T, array_IdxType i, array_ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    int j;

    array_Neff(*T) -= 1;
    for ( j = i; (j <= array_Neff(*T)); j++){
        array_Elmt(*T, j) = array_Elmt(*T, j+1);
        }
}


/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void array_AddElUnik (TabInt * T, array_ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    boolean found = false;
    int i;

    /* set sentinel, I suppose */
    array_Elmt(*T, 0) = X;

    if (IsEmpty(*T)){
        array_Elmt(*T, IdxMin) = X;
        array_Neff(*T) = 1;
    }
    else{
        for (i = IdxMin;(i<= array_Neff(*T));i++){
            if (array_Elmt(*T, i) == array_Elmt(*T,0)){
                found = true;
                printf("nilai sudah ada\n");
                break;
            }
        }

        if (!(found)){
            array_Elmt(*T,array_Neff(*T)+1) = array_Elmt(*T,0);
            array_Neff(*T) += 1;
        }
    }
}


/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
array_IdxType array_SearchUrut (TabInt T, array_ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    int i;

    for (i = IdxMin; ( (i<= array_Neff(T)) && (array_Elmt(T,i)<= X) ); i++){
            if (array_Elmt(T, i) == X){
                return i;
            }
        }

    return IdxUndef;
}

array_ElType array_MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return array_Elmt(T, array_Neff(T));
}

array_ElType array_MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return array_Elmt(T, IdxMin);
}

void array_MaxMinUrut (TabInt T, array_ElType * Max, array_ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Max = array_MaxUrut(T);
    *Min = array_MinUrut(T);
}

void array_Add1Urut (TabInt * T, array_ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    if (array_Neff(*T) < IdxMax){
        array_Elmt(*T, array_Neff(*T)+1) = X;
        array_Neff(*T) += 1;
        array_InsSortAsc(T);
    }
}

void array_Del1Urut (TabInt * T, array_ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
        int found_index = array_Search1(*T, X);

        if (found_index != IdxUndef){
            array_DelEli(T, found_index, &X);
        }
}


/* END OF CODE */
