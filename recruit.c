#include "recruit.h"

Build SearchTower(MAP M, UNIT K) {
    int owner_unit = Owner(K);
    int i = 0;
    int j = 0;
    boolean found = false;

    while (i<=MapBrsEff(M) && found==false) {
        while (j<=MapKolEff(M) && found==false) {
            if (Build_Type(Build(M,i,j)) == 'T' && Build_Owner(Build(M,i,j)) == owner_unit) {
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

boolean IsCastleEmpty (MAP M, int x, int y){
    return (Type(Unit(M, x, y)) == Nil) ? true : false;
}

boolean castle_available(MAP M, Build T) {
    POINT tower = Build_Pos(T);
    POINT PC1, PC2, PC3, PC4;
    Build C1, C2, C3, C4;

    /* Get castle building info */
    C1 = Build(M, Absis(tower)+1, Ordinat(tower));
    C2 = Build(M, Absis(tower), Ordinat(tower)+1);
    C3 = Build(M, Absis(tower)-1, Ordinat(tower));
    C4 = Build(M, Absis(tower), Ordinat(tower)-1);

    /* Get castle position */
    PC1 = Build_Pos(C1);
    PC2 = Build_Pos(C2);
    PC3 = Build_Pos(C3);
    PC4 = Build_Pos(C4);

    /* Check if there's availabe castle */
    boolean castle_available = IsCastleEmpty(M, Absis(PC1), Ordinat(PC1)) || IsCastleEmpty(M, Absis(PC2), Ordinat(PC2)) || IsCastleEmpty(M, Absis(PC3), Ordinat(PC3)) || IsCastleEmpty(M, Absis(PC4), Ordinat(PC4)) ;

    if (castle_available) {
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


    if (point_EQ(Pos(K), Build_Pos(Tower))){
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
