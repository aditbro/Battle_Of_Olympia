
#include "unit.h"

void Init_unit (UNIT * U){

    M_Hp(*U)    = 0;
    Hp(*U)      = 0;
    Atk(*U)     = 0;
    M_Mov(*U)   = 0;
    Mov(*U)     = 0;
    Cost(*U)    = 0;
    Pos(*U)     = MakePOINT(0, 0);
    Type(*U)    = 'U';
    Can_Atk(*U) = false;

}

UNIT Create_new_unit(){

    UNIT new_unit;
    Init_unit(&new_unit);
    return new_unit;
    }

void Show_unit_info (UNIT U){

    printf("Max HP       : %d\n", M_Hp(U));
    printf("HP           : %d\n", Hp(U));
    printf("Atk          : %d\n", Atk(U));
    printf("Max Movement : %d\n", M_Mov(U));
    printf("Movement     : %d\n", Mov(U));
    printf("Cost         : %d\n", Cost(U));
    printf("Position     : <%d, %d>\n", Absis(Pos(U)), Ordinat((Pos(U))));
    printf("Type         : %c\n", Type(U));
    printf("Can attack   : ");

    if (Can_Atk(U)){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
}
