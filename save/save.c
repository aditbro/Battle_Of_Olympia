#include "save.h"

void SaveGame(Player P1, Player P2) {

    FILE *f = fopen("playerprofile.txt", "w");
    
    fprintf(f, "PLAYER %d %d %d %d ", ID(P1), gold(P1), income(P1), upkeep(P1));
    fprintf(f, "PLAYER %d %d %d %d.", ID(P2), gold(P2), income(P2), upkeep(P2));

    fclose(f);
}

void LoadGame(Player *P1, Player*P2) {
    Kata player;
    int count, dummy;

    player.TabKata[1] = 'P';
    player.TabKata[2] = 'L';
    player.TabKata[3] = 'A';
    player.TabKata[4] = 'Y';
    player.TabKata[5] = 'E';
    player.TabKata[6] = 'R';
    player.Length = 6;

    STARTKATA(1);
    count = 1;
    while (!EndKata) {
        if (IsKataSama(player,CKata)) {
            count += 1;
        }
        else {
            if (count==2) {
                dummy = KataToInt(CKata);
                ID(*P1) = dummy;
            }
            else if (count==3) {
                dummy = KataToInt(CKata);
                gold(*P1) = dummy;
            }
            else if (count==4) {
                dummy = KataToInt(CKata);
                income(*P1) = dummy;
            }
            else if (count==5) {
                dummy = KataToInt(CKata);
                upkeep(*P1) = dummy;
            }
            else if (count==7) {
                dummy = KataToInt(CKata);
                ID(*P2) = dummy;
            }
            else if (count==8) {
                dummy = KataToInt(CKata);
                gold(*P2) = dummy;
            }
            else if (count==9) {
                dummy = KataToInt(CKata);
                income(*P2) = dummy;
            }
            else if (count==10) {
                dummy = KataToInt(CKata);
                upkeep(*P2) = dummy;
            }
            count += 1;
        }
        IgnoreBlank();
        ADVKATA();
    }

}