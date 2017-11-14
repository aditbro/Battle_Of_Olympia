#include "recruit.h"

Build SearchTower(MAP M, UNIT K) {
    int owner_unit = Owner(K);
    int i = 0;
    int j = 0;
    boolean found = false;

    while (i<=MapBrsEff(M) && found==false) {
        while (j<=MapKolEff(M) && found==false) {
            if (Build_Type(Build(M,i,j)=='T') && Build_Owner(Build(M,i,j))==owner_unit) {
                found = true;
            }
            else{
                j++;
            }
        }
        if (found==false){
            i++;
        }
    }

    return Build(M,i,j);
}

void IsCastleEmpty (MAP M, int x, int y){
    return (Unit(M, x, y)==Nil) ? true : false;
}

boolean castle_available(MAP M, Build T) {
    POINT tower = Build_Pos(T);
    Build C1, C2, C3, C4;

    PC1 = MakePOINT(Absis(tower)+1, Ordinat(tower));
    PC2 = MakePOINT(Absis(tower), Ordinat(tower)+1);
    PC3 = MakePOINT(Absis(tower)-1, Ordinat(tower));
    PC4 = MakePOINT(Absis(tower), Ordinat(tower)-1);

    C1 = Build(M, Absis(tower)+1, Ordinat(tower));
    C2 = Build(M, Absis(tower), Ordinat(tower)+1);
    C3 = Build(M, Absis(tower)-1, Ordinat(tower));
    C4 = Build(M, Absis(tower), Ordinat(tower)-1);

    if (IsCastleEmpty(C1) || IsCastleEmpty(C2) || IsCastleEmpty(C3) || IsCastleEmpty(C4)) {
        return true;
    }
    else{
        return false;
    }
}

void recruit_unit(MAP M, UNIT K, UNIT *U){
    int x, y;
    int choice;
    Build Tower = SearchTower(M, K);

    if (Pos(K)==Build_Pos(Tower)){
        if (castle_available(M, Tower)){
            do {
                printf("Enter coordinate of empty castle: ");
                scanf("%d %d", &x, &y);
                if (!IsCastleEmpty(M, x, y)){
                    printf("That castle is occupied!\n");
                }
            } while (!IsCastleEmpty(M, x, y));

            printf("\n=== List of Recruits ===");
            printf("1. Archer | Health 100 | ATK 15 | DEF 15 | 3G\n");
            printf("2. Swordsman | Health 100 | ATK 20 | DEF 15 | 1G\n");
            printf("3. White Mage | Health 100 | ATK 5 | DEF 5 | HEAL 25 | 5G\n");
            printf("Enter no. of unit you want to recruit: ");
            scanf("%d", &choice);

            if (choice==1) {
                *U = Create_new_unit('A', Owner(K), x, y);
            }
            else if (choice==2) {
                *U = Create_new_unit('S', Owner(K), x, y);
            }
            else if (choice==3) {
                *U = Create_new_unit('W', Owner(K), x, y);
            }

            printf("You have successfully recruited an ");
            print_unit_type(*U);
            printf("!\n");
        }
        else{
            printf("You don't have any availabe tower.\n");
        }
    }
    else{
        printf("Your king must be inside your tower if you want to recruit any unit.");
    }

}