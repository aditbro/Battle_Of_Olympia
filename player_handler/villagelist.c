// #include "villagelist.h"

// /* PROTOTYPE */
// /****************** TEST LIST KOSONG ******************/
// boolean villagelist_IsEmpty (VillageList L)
// /* Mengirim true jika list kosong */
// {
//     return villagelist_First(L) == Nil;
// }

// /****************** PEMBUATAN LIST KOSONG ******************/
// void villagelist_CreateEmpty (VillageList *L)
// /* I.S. sembarang             */
// /* F.S. Terbentuk list kosong */
// {
//     villagelist_First(*L) = Nil;
// }

// /****************** Manajemen Memori ******************/
// villagelist_address villagelist_Alokasi (villagelist_infotype X)
// /* Mengirimkan villagelist_address hasil alokasi sebuah elemen */
// /* Jika alokasi berhasil, maka villagelist_address tidak nil, dan misalnya */
// /* menghasilkan P, maka villagelist_elmt_Info(P)=X, villagelist_elmt_Next(P)=Nil */
// /* Jika alokasi gagal, mengirimkan Nil */
// {
//     ElmtVillageList *P = (ElmtVillageList *) malloc(sizeof(ElmtVillageList));             // TAKE NOTES !!!

//     if (P != Nil){
//         villagelist_elmt_Info(P) = X;
//         villagelist_elmt_Next(P) = Nil;
//         return P;
//     }
//     else {
//         return Nil;
//     }
// }

// void villagelist_Dealokasi (villagelist_address *P)
// /* I.S. P terdefinisi */
// /* F.S. P dikembalikan ke sistem */
// /* Melakukan dealokasi/pengembalian villagelist_address P */
// {
//     free(*P);
// }

// /****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
// villagelist_address villagelist_Search (VillageList L, villagelist_infotype X)
// /* Mencari apakah ada elemen list dengan villagelist_elmt_Info(P)= X */
// /* Jika ada, mengirimkan villagelist_address elemen tersebut. */
// /* Jika tidak ada, mengirimkan Nil */
// {
//     boolean found = false;
//     villagelist_address found_add = Nil;
//     villagelist_address CP = villagelist_First(L);

//     if (!villagelist_IsEmpty(L)){

//         do{
//             if (villagelist_elmt_Info(CP) == X){
//                 found_add = CP;
//                 found = true;
//             }
//             else{
//                 CP = villagelist_elmt_Next(CP);
//             }

//         }while ((CP != Nil) && !found);
//     }

//     return found_add;

// }

// boolean villagelist_FSearch (VillageList L, villagelist_address P)
// /* Mencari apakah ada elemen list yang beralamat P */
// /* Mengirimkan true jika ada, false jika tidak ada */
// {
// 	boolean found = false;
// 	villagelist_address CP = villagelist_First(L);

// 	if (!villagelist_IsEmpty(L)){

//         do{
//             if (CP == P){
//                 found = true;
//             }
//             else{
//                 CP = villagelist_elmt_Next(CP);
//             }

//         }while ((CP != Nil) && !found);
//     }

//     return found;

// }

// villagelist_address villagelist_SearchPrec (VillageList L, villagelist_infotype X)
// /* Mengirimkan villagelist_address elemen sebelum elemen yang nilainya=X */
// /* Mencari apakah ada elemen list dengan villagelist_elmt_Info(P)=X */
// /* Jika ada, mengirimkan villagelist_address Prec, dengan villagelist_elmt_Next(Prec)=P dan villagelist_elmt_Info(P)=X. */
// /* Jika tidak ada, mengirimkan Nil */
// /* Jika P adalah elemen pertama, maka Prec=Nil */
// /* Search dengan spesifikasi seperti ini menghindari */
// /* traversal ulang jika setelah Search akan dilakukan operasi lain */
// {
//     boolean found = false;
//     villagelist_address prec = Nil;
//     villagelist_address found_add = Nil;
//     villagelist_address CP = villagelist_First(L);

//     if (!villagelist_IsEmpty(L)){

//         do{
//             if (villagelist_elmt_Info(CP) == X){
//                 found_add = prec;
//                 found = true;
//             }
//             else{
// 				prec = CP;
//                 CP = villagelist_elmt_Next(CP);
//             }

//         }while ((CP != Nil) && !found);
//     }

//     return found_add;

// }

// /****************** PRIMITIF BERDASARKAN NILAI ******************/
// /*** PENAMBAHAN ELEMEN ***/
// void villagelist_InsVFirst (VillageList *L, villagelist_infotype X)
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
// {
//     villagelist_address P = villagelist_Alokasi(X);
//     if (P != Nil){
//         villagelist_InsertFirst(L, P);
//     }
// }

// void villagelist_InsVLast (VillageList *L, villagelist_infotype X)
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen list di akhir: elemen terakhir yang baru */
// /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
// {
//     villagelist_address P = villagelist_Alokasi (X);
//     if (P != Nil){
//         villagelist_InsertLast(L, P);
//     }
// }

// /*** PENGHAPUSAN ELEMEN ***/
// void villagelist_DelVFirst (VillageList *L, villagelist_infotype *X)
// /* I.S. VillageList L tidak kosong  */
// /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen pertama di-dealokasi */
// {
//     villagelist_address P;
//     villagelist_DelFirst(L, &P);
//     *X = villagelist_elmt_Info(P);
//     villagelist_Dealokasi(&P);
// }
// void villagelist_DelVLast (VillageList *L, villagelist_infotype *X)
// /* I.S. list tidak kosong */
// /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen terakhir di-dealokasi */
// {
//     villagelist_address P;
//     villagelist_DelLast(L, &P);
//     *X = villagelist_elmt_Info(P);
//     villagelist_Dealokasi(&P);
// }

// /****************** PRIMITIF BERDASARKAN ALAMAT ******************/
// /*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void villagelist_InsertFirst (VillageList *L, villagelist_address P)
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-villagelist_address P sebagai elemen pertama */
// {
//     villagelist_elmt_Next(P) = villagelist_First(*L);
//     villagelist_First(*L) = P;
// }

// void villagelist_InsertAfter (VillageList *L, villagelist_address P, villagelist_address Prec)
// /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// {
//     villagelist_elmt_Next(P) = villagelist_elmt_Next(Prec);
//     villagelist_elmt_Next(Prec) = P;
// }

// void villagelist_InsertLast (VillageList *L, villagelist_address P)
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
// {

//     if (villagelist_IsEmpty(*L)){ // empty list
//         villagelist_elmt_Next(P) = Nil;
//         villagelist_First(*L) = P;
//     }
//     else{
//         villagelist_address last = villagelist_First(*L);

//         while(villagelist_elmt_Next(last) != Nil) {
//             last = villagelist_elmt_Next(last);
//         }

//         villagelist_InsertAfter(L, P, last);
//     }
// }

// ** PENGHAPUSAN SEBUAH ELEMEN **
// void villagelist_DelFirst (VillageList *L, villagelist_address *P)
// /* I.S. VillageList tidak kosong */
// /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
// {
//     *P = villagelist_First(*L);
//     if (villagelist_elmt_Next(villagelist_First(*L)) == Nil)    // 1 element only
//         villagelist_CreateEmpty(L);
//     else
//         villagelist_First(*L) = villagelist_elmt_Next(villagelist_First(*L));

// }
// void villagelist_DelP (VillageList *L, villagelist_infotype X)
// /* I.S. Sembarang */
// /* F.S. Jika ada elemen list bervillagelist_address P, dengan villagelist_elmt_Info(P)=X  */
// /* Maka P dihapus dari list dan di-dealokasi */
// /* Jika tidak ada elemen list dengan villagelist_elmt_Info(P)=X, maka list tetap */
// /* VillageList mungkin menjadi kosong karena penghapusan */
// {
//     villagelist_address P = villagelist_Search(*L, X);

//     if (P != Nil){   // Found
//         villagelist_address prec = villagelist_First(*L);

//         if (prec == P){ // If its on first element
//             villagelist_DelFirst(L, &P);
//         }
//         else {

//             while(villagelist_elmt_Next(prec) != P) { // search for the predecesor
//                 prec = villagelist_elmt_Next(prec);
//             }

//             villagelist_DelAfter(L, &P, prec);
//         }
//     }
//     villagelist_Dealokasi(&P);
// }
// void villagelist_DelLast (VillageList *L, villagelist_address *P)
// /* I.S. VillageList tidak kosong */
// /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen pertama yg lama, */
// /* jika ada */
// {
//     if (villagelist_elmt_Next(villagelist_First(*L)) == Nil){    // 1 element only

//         *P = villagelist_First(*L);
//         villagelist_CreateEmpty(L);

//     }
//     else {
//         villagelist_address prec = villagelist_First(*L);

//         while(villagelist_elmt_Next(villagelist_elmt_Next(prec)) != Nil) {
//             prec = villagelist_elmt_Next(prec);
//         }

//         // Next Next (prec ) == nil , got the prec of last element

//         villagelist_DelAfter(L, P, prec);

//     }
// }

// void villagelist_DelAfter (VillageList *L, villagelist_address *Pdel, villagelist_address Prec)
// /* I.S. VillageList tidak kosong. Prec adalah anggota list  */
// /* F.S. Menghapus villagelist_elmt_Next(Prec): */
// /*      Pdel adalah alamat elemen list yang dihapus  */
// {
//     *Pdel = villagelist_elmt_Next(Prec);
//     if (*Pdel != Nil)
//         villagelist_elmt_Next(Prec) = villagelist_elmt_Next(villagelist_elmt_Next(Prec));
// }

// /****************** PROSES SEMUA ELEMEN LIST ******************/
// void villagelist_PrintInfo (VillageList L)
// /* I.S. VillageList mungkin kosong */
// /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
// {
//     printf("[");
//     if (!villagelist_IsEmpty(L)){

//         villagelist_address CP = villagelist_First(L);

//         do{

//             printf("%d",villagelist_elmt_Info(CP));
//             CP = villagelist_elmt_Next(CP);

//             if (CP != Nil){ // last element no ','
//                 printf(",");
//             }

//         } while (CP != Nil);

//     }

//     printf("]");
// }

// int villagelist_NbElmt (VillageList L)
// /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
// {
//     int Count = 0;
//     villagelist_address CP = villagelist_First(L);

//     while(CP != Nil){
//         CP = villagelist_elmt_Next(CP);
//         Count++;
//     }

//     return Count;
// }

// /*** Prekondisi untuk Max/Min/rata-rata : VillageList tidak kosong ***/\

// villagelist_address villagelist_AdrMax (VillageList L){

// 	villagelist_address Max = villagelist_First(L);
//     villagelist_address CP = villagelist_First(L);

//     while(CP != Nil){

//         if (villagelist_elmt_Info(CP) > villagelist_elmt_Info(Max)){
//             Max = CP;
//         }

//         CP = villagelist_elmt_Next(CP);
//     }

//     return Max;
// }

// villagelist_address villagelist_AdrMin (VillageList L){

// 	villagelist_address Min = villagelist_First(L);
//     villagelist_address CP = villagelist_First(L);

//     while(CP != Nil){

//         if (villagelist_elmt_Info(CP) < villagelist_elmt_Info(Min)){
//             Min = CP;
//         }

//         CP = villagelist_elmt_Next(CP);
//     }

//     return Min;
// }

// villagelist_infotype villagelist_Max (VillageList L)
// /* Mengirimkan nilai villagelist_elmt_Info(P) yang maksimum */
// {
// 	return villagelist_elmt_Info(villagelist_AdrMax(L));
// }

// villagelist_infotype villagelist_Min (VillageList L)
// /* Mengirimkan nilai villagelist_elmt_Info(P) yang maksimum */
// {
// 	return villagelist_elmt_Info(villagelist_AdrMin(L));
// }

// float villagelist_Average (VillageList L)
// /* Mengirimkan nilai rata rata villagelist_elmt_Info(P) */
// {
//     int Count = 0;
//     float Sum = 0;
//     villagelist_address CP = villagelist_First(L);

//     while(CP != Nil){

//         Sum += villagelist_elmt_Info(CP);
//         Count++;
//         CP = villagelist_elmt_Next(CP);
//     }

//     return (Sum/Count);
// }

// /****************** PROSES TERHADAP LIST ******************/
// void villagelist_Konkat1 (VillageList *L1, VillageList *L2, VillageList *L3)
// /* I.S. L1 dan L2 sembarang */
// /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
// /* Konkatenasi dua buah list : L1 dan L2    */
// /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
// /* dan L1 serta L2 menjadi list kosong.*/
// /* Tidak ada alokasi/dealokasi pada prosedur ini */
// {
//     villagelist_CreateEmpty(L3);

//     if (!(villagelist_IsEmpty(*L1))){
//         villagelist_First(*L3) = villagelist_First(*L1);

//         villagelist_address last1 = villagelist_First(*L1);

//         while(villagelist_elmt_Next(last1) != Nil) {
//             last1 = villagelist_elmt_Next(last1);
//         }

//         villagelist_elmt_Next(last1) = villagelist_First(*L2);
//     }
//     else{
//         villagelist_First(*L3) = villagelist_First(*L2);
//     }


//     villagelist_CreateEmpty(L1);
//     villagelist_CreateEmpty(L2);

// }

// /****************** PROSES TERHADAP LIST ******************/
// void villagelist_DelAll (VillageList *L)
// /* Delete semua elemen list dan alamat elemen di-dealokasi */
// {
// 	villagelist_infotype temp;

// 	while(!villagelist_IsEmpty (*L)){
// 		villagelist_DelVFirst(L, &temp);
// 	}

// 	villagelist_CreateEmpty(L);
// }