#include <stdio.h>
#include "unit.h"
/*void Init_unit (UNIT * U){

	Owner(*U)		= 0;
	Type(*U)		= '0';
    M_Hp(*U)		= 0;
    Hp(*U)			= 0;
    Atk(*U)			= 0;
    M_Mov(*U)		= 0;
    Mov(*U)		    = 0;
    Cost(*U)		= 0;
    Pos(*U)			= MakePOINT(0, 0);
    Atk_Type(*U)    = 'U';
    Can_Atk(*U)		= false;

}

UNIT Create_new_unit(){

    UNIT new_unit;
    Init_unit(&new_unit);
    return new_unit;
    }*/

void Show_unit_info (UNIT U){

    printf("Unit Type    : %c\n", Type(U));
    printf("Max HP       : %d\n", M_Hp(U));
    printf("HP           : %d\n", Hp(U));
    printf("Atk          : %d\n", Atk(U));
    printf("Max Movement : %d\n", M_Mov(U));
    printf("Movement     : %d\n", Mov(U));
    printf("Cost         : %d\n", Cost(U));
    printf("Position     : <%d, %d>\n", Absis(Pos(U)), Ordinat((Pos(U))));
    printf("Attack Type  : %c\n", Atk_Type(U));
    printf("Can attack   : ");

    if (Can_Atk(U)){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
}
void show_unit_available(UNIT U,boolean Retaliates)
/*I.S. U terdefinisi*/
/*F.S. menuliskan atribut dari unit yang available*/
{
    print_type(U);
    TulisPOINT(Pos(U));
    printf(" | ");
    printf("Health %d/%d  ",Hp(U),M_Hp(U));
    if(Retaliates){
        printf("(Retaliates)");
    }
    printf("\n");
}

void print_type(UNIT U)
/*I.S. U terdefinisi*/
/*F.S. menuliskan jenis dari U*/
{
    if(Type(U)=='K'){
        printf("King ");
    }else if(Type(U)=='A'){
        printf("Archer ");
    }else if(Type(U)=='S'){
        printf("Swordman ");
    }else if(Type(U)=='W'){
        printf("White Mage ");
    }
}