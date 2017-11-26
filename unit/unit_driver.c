#include "unit.h"
#include <stdio.h>

int main(){
    UNIT U1,E1,E2,E3,E4;
    boolean Win,Lose;
    U1 = Create_new_unit('S',1,1,2);
    E1 = Create_new_unit('S',2,1,1);
    E2 = Create_new_unit('K',2,1,3);
    E3 = Create_new_unit('W',2,2,2);
    E4 = Create_new_unit('A',2,0,2);
    char inp;
    boolean retalities;
    do{
        printf("\nInput S to show unit info, or A to show unit available : ");
        scanf("%c",&inp);
        if(inp=='S'){
            Show_unit_info(U1);
        }else if(inp=='A'){
            show_unit_available(E1,retalities);
            show_unit_available(E2,retalities);
            show_unit_available(E3,retalities);
            show_unit_available(E4,retalities);
        }
    }while(inp!='X');

    return 0;
}
