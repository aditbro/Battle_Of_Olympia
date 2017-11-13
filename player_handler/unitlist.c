#include "unitlist.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean unitlist_IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return unitlist_First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void unitlist_CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    unitlist_First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
unitlist_address unitlist_Alokasi (unitlist_infotype X)
/* Mengirimkan unitlist_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka unitlist_address tidak nil, dan misalnya */
/* menghasilkan P, maka unitlist_elmt_Info(P)=X, unitlist_elmt_Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));             // TAKE NOTES !!!

    if (P != Nil){
        unitlist_elmt_Info(P) = X;
        unitlist_elmt_Next(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void unitlist_Dealokasi (unitlist_address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian unitlist_address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
unitlist_address unitlist_Search (List L, unitlist_infotype X)
/* Mencari apakah ada elemen list dengan unitlist_elmt_Info(P)= X */
/* Jika ada, mengirimkan unitlist_address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean found = false;
    unitlist_address found_add = Nil;
    unitlist_address CP = unitlist_First(L);

    if (!unitlist_IsEmpty(L)){

        do{
            if (unitlist_elmt_Info(CP) == X){
                found_add = CP;
                found = true;
            }
            else{
                CP = unitlist_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

boolean unitlist_FSearch (List L, unitlist_address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	boolean found = false;
	unitlist_address CP = unitlist_First(L);

	if (!unitlist_IsEmpty(L)){

        do{
            if (CP == P){
                found = true;
            }
            else{
                CP = unitlist_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found;

}

unitlist_address unitlist_SearchPrec (List L, unitlist_infotype X)
/* Mengirimkan unitlist_address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan unitlist_elmt_Info(P)=X */
/* Jika ada, mengirimkan unitlist_address Prec, dengan unitlist_elmt_Next(Prec)=P dan unitlist_elmt_Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    boolean found = false;
    unitlist_address prec = Nil;
    unitlist_address found_add = Nil;
    unitlist_address CP = unitlist_First(L);

    if (!unitlist_IsEmpty(L)){

        do{
            if (unitlist_elmt_Info(CP) == X){
                found_add = prec;
                found = true;
            }
            else{
				prec = CP;
                CP = unitlist_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void unitlist_InsVFirst (List *L, unitlist_infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    unitlist_address P = unitlist_Alokasi(X);
    if (P != Nil){
        unitlist_InsertFirst(L, P);
    }
}

void unitlist_InsVLast (List *L, unitlist_infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    unitlist_address P = unitlist_Alokasi (X);
    if (P != Nil){
        unitlist_InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void unitlist_DelVFirst (List *L, unitlist_infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    unitlist_address P;
    unitlist_DelFirst(L, &P);
    *X = unitlist_elmt_Info(P);
    unitlist_Dealokasi(&P);
}
void unitlist_DelVLast (List *L, unitlist_infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    unitlist_address P;
    unitlist_DelLast(L, &P);
    *X = unitlist_elmt_Info(P);
    unitlist_Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void unitlist_InsertFirst (List *L, unitlist_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-unitlist_address P sebagai elemen pertama */
{
    unitlist_elmt_Next(P) = unitlist_First(*L);
    unitlist_First(*L) = P;
}

void unitlist_InsertAfter (List *L, unitlist_address P, unitlist_address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    unitlist_elmt_Next(P) = unitlist_elmt_Next(Prec);
    unitlist_elmt_Next(Prec) = P;
}

void unitlist_InsertLast (List *L, unitlist_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{

    if (unitlist_IsEmpty(*L)){ // empty list
        unitlist_elmt_Next(P) = Nil;
        unitlist_First(*L) = P;
    }
    else{
        unitlist_address last = unitlist_First(*L);

        while(unitlist_elmt_Next(last) != Nil) {
            last = unitlist_elmt_Next(last);
        }

        unitlist_InsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void unitlist_DelFirst (List *L, unitlist_address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = unitlist_First(*L);
    if (unitlist_elmt_Next(unitlist_First(*L)) == Nil)    // 1 element only
        unitlist_CreateEmpty(L);
    else
        unitlist_First(*L) = unitlist_elmt_Next(unitlist_First(*L));

}
void unitlist_DelP (List *L, unitlist_infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berunitlist_address P, dengan unitlist_elmt_Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan unitlist_elmt_Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    unitlist_address P = unitlist_Search(*L, X);

    if (P != Nil){   // Found
        unitlist_address prec = unitlist_First(*L);

        if (prec == P){ // If its on first element
            unitlist_DelFirst(L, &P);
        }
        else {

            while(unitlist_elmt_Next(prec) != P) { // search for the predecesor
                prec = unitlist_elmt_Next(prec);
            }

            unitlist_DelAfter(L, &P, prec);
        }
    }
    unitlist_Dealokasi(&P);
}
void unitlist_DelLast (List *L, unitlist_address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (unitlist_elmt_Next(unitlist_First(*L)) == Nil){    // 1 element only

        *P = unitlist_First(*L);
        unitlist_CreateEmpty(L);

    }
    else {
        unitlist_address prec = unitlist_First(*L);

        while(unitlist_elmt_Next(unitlist_elmt_Next(prec)) != Nil) {
            prec = unitlist_elmt_Next(prec);
        }

        // Next Next (prec ) == nil , got the prec of last element

        unitlist_DelAfter(L, P, prec);

    }
}

void unitlist_DelAfter (List *L, unitlist_address *Pdel, unitlist_address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus unitlist_elmt_Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = unitlist_elmt_Next(Prec);
    if (*Pdel != Nil)
        unitlist_elmt_Next(Prec) = unitlist_elmt_Next(unitlist_elmt_Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void unitlist_PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!unitlist_IsEmpty(L)){

        unitlist_address CP = unitlist_First(L);

        do{

            printf("%d",unitlist_elmt_Info(CP));
            CP = unitlist_elmt_Next(CP);

            if (CP != Nil){ // last element no ','
                printf(",");
            }

        } while (CP != Nil);

    }

    printf("]");
}

int unitlist_NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int Count = 0;
    unitlist_address CP = unitlist_First(L);

    while(CP != Nil){
        CP = unitlist_elmt_Next(CP);
        Count++;
    }

    return Count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/\

unitlist_address unitlist_AdrMax (List L){

	unitlist_address Max = unitlist_First(L);
    unitlist_address CP = unitlist_First(L);

    while(CP != Nil){

        if (unitlist_elmt_Info(CP) > unitlist_elmt_Info(Max)){
            Max = CP;
        }

        CP = unitlist_elmt_Next(CP);
    }

    return Max;
}

unitlist_address unitlist_AdrMin (List L){

	unitlist_address Min = unitlist_First(L);
    unitlist_address CP = unitlist_First(L);

    while(CP != Nil){

        if (unitlist_elmt_Info(CP) < unitlist_elmt_Info(Min)){
            Min = CP;
        }

        CP = unitlist_elmt_Next(CP);
    }

    return Min;
}

unitlist_infotype unitlist_Max (List L)
/* Mengirimkan nilai unitlist_elmt_Info(P) yang maksimum */
{
	return unitlist_elmt_Info(unitlist_AdrMax(L));
}

unitlist_infotype unitlist_Min (List L)
/* Mengirimkan nilai unitlist_elmt_Info(P) yang maksimum */
{
	return unitlist_elmt_Info(unitlist_AdrMin(L));
}

float unitlist_Average (List L)
/* Mengirimkan nilai rata rata unitlist_elmt_Info(P) */
{
    int Count = 0;
    float Sum = 0;
    unitlist_address CP = unitlist_First(L);

    while(CP != Nil){

        Sum += unitlist_elmt_Info(CP);
        Count++;
        CP = unitlist_elmt_Next(CP);
    }

    return (Sum/Count);
}

/****************** PROSES TERHADAP LIST ******************/
void unitlist_Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    unitlist_CreateEmpty(L3);

    if (!(unitlist_IsEmpty(*L1))){
        unitlist_First(*L3) = unitlist_First(*L1);

        unitlist_address last1 = unitlist_First(*L1);

        while(unitlist_elmt_Next(last1) != Nil) {
            last1 = unitlist_elmt_Next(last1);
        }

        unitlist_elmt_Next(last1) = unitlist_First(*L2);
    }
    else{
        unitlist_First(*L3) = unitlist_First(*L2);
    }


    unitlist_CreateEmpty(L1);
    unitlist_CreateEmpty(L2);

}

/****************** PROSES TERHADAP LIST ******************/
void unitlist_DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	unitlist_infotype temp;

	while(!unitlist_IsEmpty (*L)){
		unitlist_DelVFirst(L, &temp);
	}

	unitlist_CreateEmpty(L);
}/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean unitlist_IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return unitlist_First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void unitlist_CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    unitlist_First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
unitlist_address unitlist_Alokasi (unitlist_infotype X)
/* Mengirimkan unitlist_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka unitlist_address tidak nil, dan misalnya */
/* menghasilkan P, maka unitlist_elmt_Info(P)=X, unitlist_elmt_Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));             // TAKE NOTES !!!

    if (P != Nil){
        unitlist_elmt_Info(P) = X;
        unitlist_elmt_Next(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void unitlist_Dealokasi (unitlist_address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian unitlist_address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
unitlist_address unitlist_Search (List L, unitlist_infotype X)
/* Mencari apakah ada elemen list dengan unitlist_elmt_Info(P)= X */
/* Jika ada, mengirimkan unitlist_address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean found = false;
    unitlist_address found_add = Nil;
    unitlist_address CP = unitlist_First(L);

    if (!unitlist_IsEmpty(L)){

        do{
            if (unitlist_elmt_Info(CP) == X){
                found_add = CP;
                found = true;
            }
            else{
                CP = unitlist_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

boolean unitlist_FSearch (List L, unitlist_address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    boolean found = false;
    unitlist_address CP = unitlist_First(L);

    if (!unitlist_IsEmpty(L)){

        do{
            if (CP == P){
                found = true;
            }
            else{
                CP = unitlist_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found;

}

unitlist_address unitlist_SearchPrec (List L, unitlist_infotype X)
/* Mengirimkan unitlist_address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan unitlist_elmt_Info(P)=X */
/* Jika ada, mengirimkan unitlist_address Prec, dengan unitlist_elmt_Next(Prec)=P dan unitlist_elmt_Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    boolean found = false;
    unitlist_address prec = Nil;
    unitlist_address found_add = Nil;
    unitlist_address CP = unitlist_First(L);

    if (!unitlist_IsEmpty(L)){

        do{
            if (unitlist_elmt_Info(CP) == X){
                found_add = prec;
                found = true;
            }
            else{
                prec = CP;
                CP = unitlist_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void unitlist_InsVFirst (List *L, unitlist_infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    unitlist_address P = unitlist_Alokasi(X);
    if (P != Nil){
        unitlist_InsertFirst(L, P);
    }
}

void unitlist_InsVLast (List *L, unitlist_infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    unitlist_address P = unitlist_Alokasi (X);
    if (P != Nil){
        unitlist_InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void unitlist_DelVFirst (List *L, unitlist_infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    unitlist_address P;
    unitlist_DelFirst(L, &P);
    *X = unitlist_elmt_Info(P);
    unitlist_Dealokasi(&P);
}
void unitlist_DelVLast (List *L, unitlist_infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    unitlist_address P;
    unitlist_DelLast(L, &P);
    *X = unitlist_elmt_Info(P);
    unitlist_Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void unitlist_InsertFirst (List *L, unitlist_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-unitlist_address P sebagai elemen pertama */
{
    unitlist_elmt_Next(P) = unitlist_First(*L);
    unitlist_First(*L) = P;
}

void unitlist_InsertAfter (List *L, unitlist_address P, unitlist_address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    unitlist_elmt_Next(P) = unitlist_elmt_Next(Prec);
    unitlist_elmt_Next(Prec) = P;
}

void unitlist_InsertLast (List *L, unitlist_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{

    if (unitlist_IsEmpty(*L)){ // empty list
        unitlist_elmt_Next(P) = Nil;
        unitlist_First(*L) = P;
    }
    else{
        unitlist_address last = unitlist_First(*L);

        while(unitlist_elmt_Next(last) != Nil) {
            last = unitlist_elmt_Next(last);
        }

        unitlist_InsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void unitlist_DelFirst (List *L, unitlist_address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = unitlist_First(*L);
    if (unitlist_elmt_Next(unitlist_First(*L)) == Nil)    // 1 element only
        unitlist_CreateEmpty(L);
    else
        unitlist_First(*L) = unitlist_elmt_Next(unitlist_First(*L));

}
void unitlist_DelP (List *L, unitlist_infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berunitlist_address P, dengan unitlist_elmt_Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan unitlist_elmt_Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    unitlist_address P = unitlist_Search(*L, X);

    if (P != Nil){   // Found
        unitlist_address prec = unitlist_First(*L);

        if (prec == P){ // If its on first element
            unitlist_DelFirst(L, &P);
        }
        else {

            while(unitlist_elmt_Next(prec) != P) { // search for the predecesor
                prec = unitlist_elmt_Next(prec);
            }

            unitlist_DelAfter(L, &P, prec);
        }
    }
    unitlist_Dealokasi(&P);
}
void unitlist_DelLast (List *L, unitlist_address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (unitlist_elmt_Next(unitlist_First(*L)) == Nil){    // 1 element only

        *P = unitlist_First(*L);
        unitlist_CreateEmpty(L);

    }
    else {
        unitlist_address prec = unitlist_First(*L);

        while(unitlist_elmt_Next(unitlist_elmt_Next(prec)) != Nil) {
            prec = unitlist_elmt_Next(prec);
        }

        // Next Next (prec ) == nil , got the prec of last element

        unitlist_DelAfter(L, P, prec);

    }
}

void unitlist_DelAfter (List *L, unitlist_address *Pdel, unitlist_address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus unitlist_elmt_Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = unitlist_elmt_Next(Prec);
    if (*Pdel != Nil)
        unitlist_elmt_Next(Prec) = unitlist_elmt_Next(unitlist_elmt_Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void unitlist_PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!unitlist_IsEmpty(L)){

        unitlist_address CP = unitlist_First(L);

        do{

            printf("%d",unitlist_elmt_Info(CP));
            CP = unitlist_elmt_Next(CP);

            if (CP != Nil){ // last element no ','
                printf(",");
            }

        } while (CP != Nil);

    }

    printf("]");
}

int unitlist_NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int Count = 0;
    unitlist_address CP = unitlist_First(L);

    while(CP != Nil){
        CP = unitlist_elmt_Next(CP);
        Count++;
    }

    return Count;
}

/****************** PROSES TERHADAP LIST ******************/
void unitlist_DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    unitlist_infotype temp;

    while(!unitlist_IsEmpty (*L)){
        unitlist_DelVFirst(L, &temp);
    }

    unitlist_CreateEmpty(L);
}