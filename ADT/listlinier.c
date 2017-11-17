/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 08   */
/*   20 OCT 2017    */
/*------------------*/

/* NOTES

CONSTANT        : Nil = NULL
STRUCT TYPE     : ElmtList, List
Selector        : list_elmt_Info(P), list_elmt_Next(P), list_First(L)

Method list:

boolean IsEmpty (List L);
void list_CreateEmpty (List *L);

list_address Alokasi (list_infotype X);
void list_Dealokasi (list_address *P);

list_address Search (List L, list_infotype X);
boolean FSearch (List L, list_address P);
list_address SearchPrec (List L, list_infotype X);

void list_InsVFirst (List *L, list_infotype X);
void list_InsVLast (List *L, list_infotype X);
void list_InsertFirst (List *L, list_address P);
void list_InsertAfter (List *L, list_address P, list_address Prec);
void list_InsertLast (List *L, list_address P);

void list_DelVFirst (List *L, list_infotype *X);
void list_DelVLast (List *L, list_infotype *X);
void list_DelFirst (List *L, list_address *P);
void list_DelP (List *L, list_infotype X);
void list_DelLast (List *L, list_address *P);
void list_DelAfter (List *L, list_address *Pdel, list_address Prec);

void list_PrintInfo (List L);
int NbElmt (List L);
list_infotype Max (List L);
list_address AdrMax (List L);
list_infotype Min (List L);
list_address AdrMin (List L);
float Average (List L);

void list_DelAll (List *L);
void list_InversList (List *L);
List FInversList (List L);
void list_CopyList (List *L1, List *L2);
List FCopyList (List L);
void list_CpAlokList (List Lin, List *Lout);

void list_Konkat (List L1, List L2, List * L3);
void list_Konkat1 (List *L1, List *L2, List *L3);
void list_PecahList (List *L1, List *L2, List L);
*/

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean list_IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return list_First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void list_CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    list_First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
list_address list_Alokasi (list_infotype X)
/* Mengirimkan list_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka list_address tidak nil, dan misalnya */
/* menghasilkan P, maka list_elmt_Info(P)=X, list_elmt_Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));             // TAKE NOTES !!!

    if (P != Nil){
        list_elmt_Info(P) = X;
        list_elmt_Next(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void list_Dealokasi (list_address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian list_address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
list_address list_Search (List L, list_infotype X)
/* Mencari apakah ada elemen list dengan list_elmt_Info(P)= X */
/* Jika ada, mengirimkan list_address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    boolean found = false;
    list_address found_add = Nil;
    list_address CP = list_First(L);

    if (!list_IsEmpty(L)){

        do{
            if (list_elmt_Info(CP) == X){
                found_add = CP;
                found = true;
            }
            else{
                CP = list_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

boolean list_FSearch (List L, list_address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	boolean found = false;
	list_address CP = list_First(L);

	if (!list_IsEmpty(L)){

        do{
            if (CP == P){
                found = true;
            }
            else{
                CP = list_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found;

}

list_address list_SearchPrec (List L, list_infotype X)
/* Mengirimkan list_address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan list_elmt_Info(P)=X */
/* Jika ada, mengirimkan list_address Prec, dengan list_elmt_Next(Prec)=P dan list_elmt_Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    boolean found = false;
    list_address prec = Nil;
    list_address found_add = Nil;
    list_address CP = list_First(L);

    if (!list_IsEmpty(L)){

        do{
            if (list_elmt_Info(CP) == X){
                found_add = prec;
                found = true;
            }
            else{
				prec = CP;
                CP = list_elmt_Next(CP);
            }

        }while ((CP != Nil) && !found);
    }

    return found_add;

}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void list_InsVFirst (List *L, list_infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    list_address P = list_Alokasi(X);
    if (P != Nil){
        list_InsertFirst(L, P);
    }
}

void list_InsVLast (List *L, list_infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    list_address P = list_Alokasi (X);
    if (P != Nil){
        list_InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void list_DelVFirst (List *L, list_infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    list_address P;
    list_DelFirst(L, &P);
    *X = list_elmt_Info(P);
    list_Dealokasi(&P);
}
void list_DelVLast (List *L, list_infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    list_address P;
    list_DelLast(L, &P);
    *X = list_elmt_Info(P);
    list_Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void list_InsertFirst (List *L, list_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-list_address P sebagai elemen pertama */
{
    list_elmt_Next(P) = list_First(*L);
    list_First(*L) = P;
}

void list_InsertAfter (List *L, list_address P, list_address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    list_elmt_Next(P) = list_elmt_Next(Prec);
    list_elmt_Next(Prec) = P;
}

void list_InsertLast (List *L, list_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{

    if (list_IsEmpty(*L)){ // empty list
        list_elmt_Next(P) = Nil;
        list_First(*L) = P;
    }
    else{
        list_address last = list_First(*L);

        while(list_elmt_Next(last) != Nil) {
            last = list_elmt_Next(last);
        }

        list_InsertAfter(L, P, last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void list_DelFirst (List *L, list_address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = list_First(*L);
    if (list_elmt_Next(list_First(*L)) == Nil)    // 1 element only
        list_CreateEmpty(L);
    else
        list_First(*L) = list_elmt_Next(list_First(*L));

}
void list_DelP (List *L, list_infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berlist_address P, dengan list_elmt_Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan list_elmt_Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    list_address P = list_Search(*L, X);

    if (P != Nil){   // Found
        list_address prec = list_First(*L);

        if (prec == P){ // If its on first element
            list_DelFirst(L, &P);
        }
        else {

            while(list_elmt_Next(prec) != P) { // search for the predecesor
                prec = list_elmt_Next(prec);
            }

            list_DelAfter(L, &P, prec);
        }
    }
    list_Dealokasi(&P);
}
void list_DelLast (List *L, list_address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (list_elmt_Next(list_First(*L)) == Nil){    // 1 element only

        *P = list_First(*L);
        list_CreateEmpty(L);

    }
    else {
        list_address prec = list_First(*L);

        while(list_elmt_Next(list_elmt_Next(prec)) != Nil) {
            prec = list_elmt_Next(prec);
        }

        // Next Next (prec ) == nil , got the prec of last element

        list_DelAfter(L, P, prec);

    }
}

void list_DelAfter (List *L, list_address *Pdel, list_address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus list_elmt_Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = list_elmt_Next(Prec);
    if (*Pdel != Nil)
        list_elmt_Next(Prec) = list_elmt_Next(list_elmt_Next(Prec));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void list_PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!list_IsEmpty(L)){

        list_address CP = list_First(L);

        do{

            printf("%d",list_elmt_Info(CP));
            CP = list_elmt_Next(CP);

            if (CP != Nil){ // last element no ','
                printf(",");
            }

        } while (CP != Nil);

    }

    printf("]");
}

int list_NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int Count = 0;
    list_address CP = list_First(L);

    while(CP != Nil){
        CP = list_elmt_Next(CP);
        Count++;
    }

    return Count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/\

list_address list_AdrMax (List L){

	list_address Max = list_First(L);
    list_address CP = list_First(L);

    while(CP != Nil){

        if (list_elmt_Info(CP) > list_elmt_Info(Max)){
            Max = CP;
        }

        CP = list_elmt_Next(CP);
    }

    return Max;
}

list_address list_AdrMin (List L){

	list_address Min = list_First(L);
    list_address CP = list_First(L);

    while(CP != Nil){

        if (list_elmt_Info(CP) < list_elmt_Info(Min)){
            Min = CP;
        }

        CP = list_elmt_Next(CP);
    }

    return Min;
}

list_infotype list_Max (List L)
/* Mengirimkan nilai list_elmt_Info(P) yang maksimum */
{
	return list_elmt_Info(list_AdrMax(L));
}

list_infotype list_Min (List L)
/* Mengirimkan nilai list_elmt_Info(P) yang maksimum */
{
	return list_elmt_Info(list_AdrMin(L));
}

float list_Average (List L)
/* Mengirimkan nilai rata rata list_elmt_Info(P) */
{
    int Count = 0;
    float Sum = 0;
    list_address CP = list_First(L);

    while(CP != Nil){

        Sum += list_elmt_Info(CP);
        Count++;
        CP = list_elmt_Next(CP);
    }

    return (Sum/Count);
}

/****************** PROSES TERHADAP LIST ******************/
void list_Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    list_CreateEmpty(L3);

    if (!(list_IsEmpty(*L1))){
        list_First(*L3) = list_First(*L1);

        list_address last1 = list_First(*L1);

        while(list_elmt_Next(last1) != Nil) {
            last1 = list_elmt_Next(last1);
        }

        list_elmt_Next(last1) = list_First(*L2);
    }
    else{
        list_First(*L3) = list_First(*L2);
    }


    list_CreateEmpty(L1);
    list_CreateEmpty(L2);

}

/****************** PROSES TERHADAP LIST ******************/
void list_DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	list_infotype temp;

	while(!list_IsEmpty (*L)){
		list_DelVFirst(L, &temp);
	}

	list_CreateEmpty(L);
}

void list_InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{

	list_address P,Q;
	list_address First = list_First(*L);

	P = list_First(*L);
	Q = list_elmt_Next(P);

	while(Q != Nil){

		P = Q;
		Q = list_elmt_Next(Q);
		list_InsertFirst(L, P);
		list_elmt_Next(First) = Q;
	}
}

List list_FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	// Create temporary list
	List TempL;
	list_CreateEmpty(&TempL);

	// Create duplicate of original list
	List TempOrg;
	list_CreateEmpty(&TempOrg);
	TempOrg = list_FCopyList(L);

	list_infotype temp;
	list_address tempAdr;
	while(!list_IsEmpty(TempOrg)){

		list_DelVFirst(&TempOrg, &temp);
		tempAdr = list_Alokasi(temp);
		if (tempAdr != Nil) {
			list_InsertFirst(&TempL, tempAdr);
		}
		else{
			list_DelAll(&TempL);
			return TempL;
		}
	}

	return TempL;
}

void list_CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
	list_First(*L2) = list_First(*L1);
}


List list_FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	// Create temporary list
	List TempL;
	list_CreateEmpty(&TempL);

	list_address CP = list_First(L);
	list_address tempAdr;

	while(CP != Nil){

		tempAdr = list_Alokasi(list_elmt_Info(CP));
		if (tempAdr != Nil){
			list_InsertLast(&TempL, tempAdr);
			CP = list_elmt_Next(CP);
		}
		else{
			list_DelAll(&TempL);
			return TempL;
		}
	}

	return TempL;
}

void list_CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	list_CreateEmpty(Lout);
	*Lout = list_FCopyList(Lin);
}

void list_Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    list_CreateEmpty(L3);

	list_address tempAdr;
	list_infotype temp;
	list_address CP;
	boolean stop = false;

    if (!(list_IsEmpty(L1))){

        CP = list_First(L1);

        while ((CP != Nil) && (!stop)){

			temp = list_elmt_Info(CP);
			tempAdr = list_Alokasi(temp);
			if (tempAdr != Nil){
				list_InsertLast(L3, tempAdr);
				CP = list_elmt_Next(CP);
			}
			else {

				list_DelAll(L3);
				stop = true;
			}
		}

		CP = list_First(L2);

        while ((CP != Nil) && (!stop)){

			temp = list_elmt_Info(CP);
			tempAdr = list_Alokasi(temp);
			if (tempAdr != Nil){
				list_InsertLast(L3, tempAdr);
				CP = list_elmt_Next(CP);
			}
			else {

				list_DelAll(L3);
				stop = true;
			}
		}

    }
    else{

		CP = list_First(L2);

        while ((CP != Nil) && (!stop)){

			temp = list_elmt_Info(CP);
			tempAdr = list_Alokasi(temp);
			if (tempAdr != Nil){
				list_InsertLast(L3, tempAdr);
				CP = list_elmt_Next(CP);
			}
			else {

				list_DelAll(L3);
				stop = true;
			}
		}
    }
}

void list_PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
	int repeat = list_NbElmt(L) / 2;
	int repeatII = list_NbElmt(L) - repeat;
	list_address tempAdr;
	list_infotype temp;
	list_address CP = list_First(L);

	list_CreateEmpty(L1);
	list_CreateEmpty(L2);

	while(repeat > 0){

		temp = list_elmt_Info(CP);
		tempAdr = list_Alokasi(temp);
		if (tempAdr != Nil){
			list_InsertLast(L1, tempAdr);
			CP = list_elmt_Next(CP);
			repeat--;
		}

	}

	while(repeatII > 0){

		temp = list_elmt_Info(CP);
		tempAdr = list_Alokasi(temp);
		if (tempAdr != Nil){
			list_InsertLast(L2, tempAdr);
			CP = list_elmt_Next(CP);
			repeatII--;
		}
	}
}
