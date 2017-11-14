
/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 04   */
/*   12 Sept 2017   */
/*------------------*/


#include <stdio.h>
#include "matriks.h"

/* matriks_NBrsEff <= 1 dan matriks_NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk MATRIKS *** */
void matriks_MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    //matriks_ElType *M.Mem[NB+1][NK+1];      /* !!!!!!!! check whether this need to be aplied !!!!!!!!!!! */
    matriks_NBrsEff(*M) = NB;
    matriks_NKolEff(*M) = NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean matriks_IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah matriks_indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}


/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
matriks_indeks matriks_GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan matriks_indeks baris terkecil M */
{
    return BrsMin;
}

matriks_indeks matriks_GetFirstIdxKol (MATRIKS M)
/* Mengirimkan matriks_indeks kolom terkecil M */
{
    return KolMin;
}

matriks_indeks matriks_GetLastIdxBrs (MATRIKS M)
/* Mengirimkan matriks_indeks baris terbesar M */
{
    return matriks_NBrsEff(M);
}

matriks_indeks matriks_GetLastIdxKol (MATRIKS M)
/* Mengirimkan matriks_indeks kolom terbesar M */
{
    return matriks_NKolEff(M);
}

boolean matriks_IsIdxEff (MATRIKS M, matriks_indeks i, matriks_indeks j)
/* Mengirimkan true jika i, j adalah matriks_indeks efektif bagi M */
{
    return ( ( i>= BrsMin) && (i <= matriks_NBrsEff(M)) && (j >= KolMin) && (j<= matriks_NKolEff(M)) );
}

matriks_ElType matriks_Getmatriks_ElmtDiagonal (MATRIKS M, matriks_indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return matriks_Elmt(M,i,i);
}


/* ********** Assignment  MATRIKS ********** */
void matriks_CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    matriks_indeks i,j;

    matriks_MakeMATRIKS(matriks_NBrsEff(MIn),matriks_NKolEff(MIn),MHsl);
    for (i = BrsMin; i <= matriks_NBrsEff(MIn); i++){
        for (j = KolMin; j <= matriks_NKolEff(MIn); j++){
            matriks_Elmt(*MHsl, i, j) = matriks_Elmt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void matriks_BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    matriks_indeks i, j;
    matriks_ElType num;

    matriks_MakeMATRIKS(NB, NK, M);

    for (i = BrsMin; i <= matriks_NBrsEff(*M); i++){
        for (j = KolMin; j <= matriks_NKolEff(*M); j++){
            scanf("%d",&num);
            matriks_Elmt(*M, i, j) = num;
        }
    }

}

void matriks_TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    matriks_indeks i, j;
     for (i = BrsMin; i <= matriks_NBrsEff(M); i++){
        for (j = KolMin; j <= matriks_NKolEff(M); j++){
            printf("%d",matriks_Elmt(M, i, j));

            if (j < matriks_NKolEff(M)) {
                printf(" ");
            }
            else if ((j = matriks_NKolEff(M)) && (i != matriks_NBrsEff(M)) ) {
                printf("\n");
            }
        }
    }

}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS matriks_TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    matriks_indeks i, j;
    MATRIKS MHsl;

    matriks_MakeMATRIKS(matriks_NBrsEff(M1), matriks_NKolEff(M1), &MHsl);

    for (i = BrsMin; i <= matriks_NBrsEff(M1); i++){
        for (j = KolMin; j <= matriks_NKolEff(M1); j++){

            matriks_Elmt(MHsl, i, j) = matriks_Elmt(M1, i, j) + matriks_Elmt(M2, i, j);

        }
    }

    return MHsl;
}

MATRIKS matriks_KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    matriks_indeks i, j;
    MATRIKS MHsl;

    matriks_MakeMATRIKS(matriks_NBrsEff(M1), matriks_NKolEff(M1), &MHsl);

    for (i = BrsMin; i <= matriks_NBrsEff(M1); i++){
        for (j = KolMin; j <= matriks_NKolEff(M1); j++){

            matriks_Elmt(MHsl, i, j) = matriks_Elmt(M1, i, j) - matriks_Elmt(M2, i, j);

        }
    }

    return MHsl;
}

MATRIKS matriks_KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    matriks_indeks i, j, k;
    matriks_ElType sum;
    MATRIKS MHsl;

    matriks_MakeMATRIKS(matriks_NBrsEff(M1), matriks_NKolEff(M2), &MHsl);

    for (i = BrsMin; i <= matriks_NBrsEff(MHsl); i++){
        for (j = KolMin; j <= matriks_NKolEff(MHsl); j++){

            sum = 0;
            for (k = KolMin; k <= matriks_NKolEff(M1) ; k++){
                sum += matriks_Elmt(M1,i,k) * matriks_Elmt(M2,k, j);
            }

            matriks_Elmt(MHsl, i, j) = sum;

        }
    }

    return MHsl;
}


MATRIKS matriks_KaliKons (MATRIKS M, matriks_ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    matriks_indeks i, j;
    MATRIKS MHsl;

    matriks_MakeMATRIKS(matriks_NBrsEff(M), matriks_NKolEff(M), &MHsl);

    for (i = BrsMin; i <= matriks_NBrsEff(M); i++){
        for (j = KolMin; j <= matriks_NKolEff(M); j++){

            matriks_Elmt(MHsl, i, j) = matriks_Elmt(M, i, j) * X ;
        }
    }

    return MHsl;
}

void matriks_PKaliKons (MATRIKS * M, matriks_ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{

    matriks_indeks i, j;

    for (i = BrsMin; i <= matriks_NBrsEff(*M); i++){
        for (j = KolMin; j <= matriks_NKolEff(*M); j++){

            matriks_Elmt(*M, i, j) *= K;

        }
    }
}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean matriks_EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan matriks_indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    matriks_indeks i,j;

     if ( (matriks_NBrsEff(M1) != matriks_NBrsEff(M2)) || (matriks_NKolEff(M1) != matriks_NKolEff(M2)) ){
        return false;
     }
     else if ( (matriks_GetFirstIdxBrs(M1) != matriks_GetFirstIdxBrs(M2)) || (matriks_GetLastIdxKol(M1) != matriks_GetLastIdxKol(M2)) ){
        return false;
     }
     else{
        for (i = BrsMin; i <= matriks_NBrsEff(M1); i++){
            for (j = KolMin; j <= matriks_NKolEff(M1); j++){

                if ( matriks_Elmt(M1, i, j) != matriks_Elmt(M2, i, j) ){
                    return false;
                }
            }
        }
     }

     return true;

}

boolean matriks_NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !(matriks_EQ(M1,M2));
}

boolean matriks_EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = Getmatriks_NBrsEff (M2) dan Getmatriks_NKolEff (M1) = Getmatriks_NKolEff (M2) */
{
    return ( (matriks_NBrsEff(M1) == matriks_NBrsEff (M2)) && (matriks_NKolEff (M1) == matriks_NKolEff (M2)) );
}


/* ********** Operasi lain ********** */
int matriks_NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (matriks_NBrsEff(M)*matriks_NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean matriks_IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (matriks_NBrsEff(M) == matriks_NKolEff(M));
}

boolean matriks_IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    matriks_indeks i, j;

    if (!(matriks_IsBujurSangkar(M))){
        return false;
    }
    else {
        for (i = BrsMin; i <= matriks_NBrsEff(M); i++){
            for (j = KolMin; j <= matriks_NKolEff(M); j++){
                if (matriks_Elmt(M, i, j) != matriks_Elmt(M, j, i)){
                    return false;
                }
            }
        }
    }

    return true;

}

boolean matriks_IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
   matriks_indeks i, j;

    if (!(matriks_IsBujurSangkar(M))){
        return false;
    }
    else {
        for (i = BrsMin; i <= matriks_NBrsEff(M); i++){
            for (j = KolMin; j <= matriks_NKolEff(M); j++){
                if (i == j){
                    if (matriks_Elmt(M, i, j) != 1 ){
                        return false;
                    }
                }
                else{
                    if (matriks_Elmt(M, i, j) != 0 ){
                        return false;
                    }
                }

            }
        }
    }

    return true;
}


boolean matriks_IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    matriks_indeks i,j;
    int counter = 0;
    int limit = matriks_NBrsEff(M) * matriks_NKolEff(M) * 0.05;

    for (i = BrsMin; i <= matriks_NBrsEff(M); i++){
            for (j = KolMin; j <= matriks_NKolEff(M); j++){
                if (matriks_Elmt(M, i, j) != 0){
                    counter += 1;
                }
            }
        }

    return (counter <= limit);    /*  !!!!!!!!!!!    check if <= or < only !!!!!!!!!!!    */
}


MATRIKS matriks_Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    return matriks_KaliKons(M, -1);
}

float matriks_Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    int brsneff = matriks_NBrsEff(M);
    int kolneff = matriks_NKolEff(M);
    float Mcopy[brsneff+1][kolneff+1];

    matriks_indeks i, j;
    float det = 1;

    void swap_rows(float M[brsneff+1][kolneff+1], int a, int b, float * det){
    /* a dan b adalah baris yang akan ditukar */
        float Temp;
        matriks_indeks i;

        for (i = KolMin; i <= kolneff; i++){
            Temp = M[a][i];
            M[a][i] = M[b][i];
            M[b][i] = Temp;
        }

        *det = -(*det); /* setelah 2 baris ditukar, determinan menjadi -determinan */
    }

    void make_one(float M[brsneff+1][kolneff+1], int a, float * det){
    /* a,a adalah index element diagonal yang akan dibuat 1 */

        matriks_indeks i;
        int z = 1;

        float divider = M[a][a] ;

        /* tukar baris jika elemen diagonal determinannya sudah 0  */
        while ((divider == 0) && (a+z <= kolneff)){
            swap_rows(M, a, a+z, det);
            divider = M[a][a];
            z += 1;
        }

        if ((divider == 0) && (a+z > kolneff)){ /* matriks unsolvable */
            *det = 0;
            return;
        }

        for (i = a; i <= kolneff; i++){
            M[a][i]  = M[a][i]  / divider;
        }
        *det = *det * divider;
    }

    void make_zero(float M[brsneff+1][kolneff+1], int a){
    /* reduce column a to 0 */
        matriks_indeks i,j ;

        for (i = a+1; i <= brsneff; i++){
            for (j = kolneff; j >= a; j--){
                M[i][j] -= (M[i][a] * M[a][j] / M[a][a]);
            }
        }
    }



    /* copy matriks M ke matriks Mcopy */
    for (i = BrsMin; i <= brsneff; i++){
        for (j = KolMin; j <= kolneff; j++){
            Mcopy[i][j] = matriks_Elmt(M, i, j);
        }
    }

    /* untuk setiap kolom, lakukan operasi baris elementer */
    for (i = KolMin; i <= kolneff; i++){
        make_one(Mcopy,i, &det);  /* bagi Mcopy[i,i] sehingga menjadi 1 */


        if (det == 0){
            return 0.000000;
        }

        /*
        printf("\n\n");
        for (k = BrsMin; k <= brsneff; k++){
            for (j = KolMin; j <= kolneff; j++){
                printf("%.2f ",Mcopy[k][j]);
            }
            printf("\n");
        }*/

        make_zero(Mcopy,i); /* kurangi baris sisasnya hingga menjadi 0 */

        /*
        printf("\n\n");
        for (k = BrsMin; k <= brsneff; k++){
            for (j = KolMin; j <= kolneff; j++){
                printf("%.2f ",Mcopy[k][j]);
            }
            printf("\n");
        }
        */

    }
    return det;
}


void matriks_PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    return matriks_PKaliKons(M, -1);
}


void matriks_Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    matriks_ElType temp;
    matriks_indeks i,j;

    for (i = BrsMin; i <= matriks_NBrsEff(*M); i++){
            for (j = i; j <= matriks_NKolEff(*M); j++){
                temp = matriks_Elmt(*M, i, j);
                matriks_Elmt(*M, i, j) = matriks_Elmt(*M, j, i);
                matriks_Elmt(*M, j, i) = temp;
            }
        }
}

float matriks_RataBrs (MATRIKS M, matriks_indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah matriks_indeks baris efektif dari M */
{
	float sum = 0;
	matriks_indeks j;
	
	for (j = KolMin; j <= matriks_NKolEff(M); j++){
		sum += matriks_Elmt(M,i,j);
	}
	
	return (sum / (matriks_NKolEff(M)));
}

float matriks_RataKol (MATRIKS M, matriks_indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah matriks_indeks kolom efektif dari M */
{
	float sum = 0;
	matriks_indeks i;
	
	for (i = BrsMin; i <= matriks_NBrsEff(M); i++){
		sum += matriks_Elmt(M,i,j);
	}
	
	return (sum / (matriks_NBrsEff(M)));
}

void matriks_MaxMinBrs (MATRIKS M, matriks_indeks i, matriks_ElType * max, matriks_ElType * min)
/* I.S. i adalah matriks_indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	*max = -9999;
	*min = 9999;
	matriks_indeks j;
	
	for (j = KolMin; j <= matriks_NKolEff(M); j++){
		if (matriks_Elmt(M,i,j) > *max) {
			*max = matriks_Elmt(M,i,j);
		}
		if (matriks_Elmt(M,i,j) < *min) {
			*min = matriks_Elmt(M,i,j);
		}
	}
}

void matriks_MaxMinKol (MATRIKS M, matriks_indeks j, matriks_ElType * max, matriks_ElType * min)
/* I.S. j adalah matriks_indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	*max = -9999;
	*min = 9999;
	matriks_indeks i;
	
	for (i = BrsMin; i <= matriks_NBrsEff(M); i++){
		if (matriks_Elmt(M,i,j) > *max) {
			*max = matriks_Elmt(M,i,j);
		}
		if (matriks_Elmt(M,i,j) < *min) {
			*min = matriks_Elmt(M,i,j);
		}
	}
}

int matriks_CountXBrs (MATRIKS M, matriks_indeks i, matriks_ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	int counter = 0;
	matriks_indeks j;
	
	for (j = KolMin; j <= matriks_NKolEff(M) ; j++ ){
		if ( matriks_Elmt(M,i,j) == X){
			counter += 1;
		}
	}
	
	return counter;
}	

int matriks_CountXKol (MATRIKS M, matriks_indeks j, matriks_ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	int counter = 0;
	matriks_indeks i;
	
	for (i = BrsMin; i <= matriks_NBrsEff(M) ; i++ ){
		if ( matriks_Elmt(M,i,j) == X){
			counter += 1;
		}
	}
	
	return counter;
}
