#include "unit_battle.h"


int main(){
    UNIT U1,E1,E2,E3,E4;
    MAP M=Init_map();
    boolean Win,Lose;
    U1 = Create_new_unit('S',1,1,2);
    Unit(M, 1, 2) = U1;
    E1 = Create_new_unit('S',2,1,1);
    Unit(M, 1, 1) = E1;
    E2 = Create_new_unit('K',2,1,3);
    Unit(M, 1, 3) = E2;
    E3 = Create_new_unit('W',2,2,2);
    Unit(M, 2, 2) = E3;
    E4 = Create_new_unit('A',2,0,2);
    Unit(M, 0, 2) = E4;

    char inp;
    do{
        printf("\nInput A to attack, or M to show map : ");
        scanf("%c",&inp);
        if(inp=='A'){
            attack(&U1, &M, &Win,&Lose);
        }else if(inp=='M'){
            printMap(M);
        }
    }while(inp!='X');
    return 0;
}
