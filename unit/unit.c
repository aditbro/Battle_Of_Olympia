#include "unit.h"
#include <stdio.h>
#include <stdlib.h>

void Init_unit(UNIT * U,char type,int owner,int x, int y){
    Kata utype;
    boolean found;

    Owner(*U)       = owner;
    Type(*U)        = type;    

    if (type=='S') {
        utype.TabKata[1] = 'S';
        utype.TabKata[2] = 'W';
        utype.TabKata[3] = 'O';
        utype.TabKata[4] = 'R';
        utype.TabKata[5] = 'D';
        utype.TabKata[6] = 'S';
        utype.TabKata[7] = 'M';
        utype.TabKata[8] = 'A';
        utype.TabKata[9] = 'N';
        utype.Length = 9;
    }
    else if (type=='A') {
        utype.TabKata[1] = 'A';
        utype.TabKata[2] = 'R';
        utype.TabKata[3] = 'C';
        utype.TabKata[4] = 'H';
        utype.TabKata[5] = 'E';
        utype.TabKata[6] = 'R';
        utype.Length = 6;
    }
    else if (type=='K') {
        utype.TabKata[1] = 'K';
        utype.TabKata[2] = 'I';
        utype.TabKata[3] = 'N';
        utype.TabKata[4] = 'G';
        utype.Length = 4;
    }
    else if (type=='W') {
        utype.TabKata[1] = 'W';
        utype.TabKata[2] = 'H';
        utype.TabKata[3] = 'I';
        utype.TabKata[4] = 'T';
        utype.TabKata[5] = 'E';
        utype.TabKata[6] = 'M';
        utype.TabKata[7] = 'A';
        utype.TabKata[8] = 'G';
        utype.TabKata[9] = 'E';
        utype.Length = 9;
    }

    found = false;

    if (type=='S' || type=='A' || type=='K' || type=='W') {
        STARTKATA(0);
        while (!EndKata && found==false) {
            if (IsKataSama(CKata,utype)) {
                ADVKATA();
                M_Hp(*U) = KataToInt(CKata);
                ADVKATA();
                Hp(*U) = KataToInt(CKata);
                ADVKATA();
                Atk(*U) = KataToInt(CKata);
                ADVKATA();
                Def(*U) = KataToInt(CKata);
                ADVKATA();
                Heal(*U) = KataToInt(CKata);
                ADVKATA();
                M_Mov(*U) = KataToInt(CKata);
                ADVKATA();
                Mov(*U) = KataToInt(CKata);
                ADVKATA();
                Cost(*U) = KataToInt(CKata);
                ADVKATA();
                Upkeep(*U) = KataToInt(CKata);
                ADVKATA();
                GHP(*U) = KataToInt(CKata);
                ADVKATA();
                Atk_Type(*U) = CKata.TabKata[1];
                found = true;
            }
            else{  
                ADVKATA();
            }
        }
    }
    // else if (type=='W') {
    //     M_Hp(*U)         = 100;
    //     Hp(*U)           = 100;
    //     Atk(*U)          = 5;
    //     Def(*U)          = 5;
    //     Heal(*U)         = 25;
    //     M_Mov(*U)        = 3;
    //     Mov(*U)          = 3;
    //     Cost(*U)         = 200;
    //     Upkeep(*U)       = 10;
    //     GHP(*U)          = 90;
    //     Atk_Type(*U)     = 'M';
    // }
    else {
        /* dummy for unitlist purpose */
        M_Hp(*U)        = 0;
        Hp(*U)          = 0;
        Atk(*U)         = 0;
        Def(*U)         = 0;
        Heal(*U)        = 0;
        M_Mov(*U)       = 0;
        Mov(*U)         = 0;
        Cost(*U)        = 0;
        GHP(*U)         = 0;
        Atk_Type(*U)    = 'Z';
    }
    // if(type=='S'){
    //     M_Hp(*U)		= 100;
    //     Hp(*U)			= 100;
    //     Atk(*U)			= 60;
    //     Def(*U)         = 30;
    //     Heal(*U)        = 0;
    //     M_Mov(*U)		= 3;
    //     Mov(*U)		    = 3;
    //     Cost(*U)		= 20;
    //     Upkeep(*U)      = 4;
    //     GHP(*U)          = 50;
    //     Atk_Type(*U)    = 'M';
    // }else if(type=='A'){
    //     M_Hp(*U)		= 100;
    //     Hp(*U)			= 100;
    //     Atk(*U)			= 50;
    //     Def(*U)         = 20;
    //     Heal(*U)        = 0;
    //     M_Mov(*U)		= 2;
    //     Mov(*U)		    = 2;
    //     Cost(*U)		= 10;
    //     Upkeep(*U)      = 2;
    //     GHP(*U)          = 90;
    //     Atk_Type(*U)    = 'R';
    // }else if(type=='K'){
    //     M_Hp(*U)		= 300;
    //     Hp(*U)			= 300;
    //     Atk(*U)			= 10;
    //     Def(*U)         = 50;
    //     Heal(*U)        = 0;
    //     M_Mov(*U)		= 1;
    //     Mov(*U)		    = 1;
    //     Cost(*U)		= 0;
    //     Upkeep(*U)       = 0;
    //     GHP(*U)          = 90;
    //     Atk_Type(*U)    = 'M';
    // }else if(type=='W'){
    //     M_Hp(*U)		= 100;
    //     Hp(*U)			= 100;
    //     Atk(*U)			= 5;
    //     Def(*U)         = 5;
    //     Heal(*U)        = 25;
    //     M_Mov(*U)		= 3;
    //     Mov(*U)		    = 3;
    //     Cost(*U)		= 200;
    //     Upkeep(*U)      = 10;
    //     GHP(*U)          = 90;
    //     Atk_Type(*U)    = 'M';
    // }

    // /* Dummy for unitlist purpose*/
    // else{
    //     M_Hp(*U)		= 0;
    //     Hp(*U)			= 0;
    //     Atk(*U)			= 0;
    //     Def(*U)         = 0;
    //     Heal(*U)        = 0;
    //     M_Mov(*U)		= 0;
    //     Mov(*U)		    = 0;
    //     Cost(*U)		= 0;
    //     GHP(*U)          = 0;
    //     Atk_Type(*U)    = 'Z';
    // }
    Pos(*U)			= MakePOINT(x, y);
    Can_Atk(*U)		= true;

}

UNIT Create_new_unit(char type,int owner,int x, int y){

    UNIT new_unit;
    Init_unit(&new_unit,type,owner,x,y);
    return new_unit;
    }

void Show_unit_info (UNIT U){

    printf("Unit Type            : ");print_unit_type(U);printf(" \n");
    printf("Max HP               : %d\n", M_Hp(U));
    printf("Owner                : %d\n", Owner(U));
    printf("HP                   : %d\n", Hp(U));
    printf("Atk                  : %d\n", Atk(U));
    printf("Def                  : %d\n", Def(U));
    if (Type(U)=='W'){
        printf("Healing (White Mage) : %d\n", Heal(U));
    }
    printf("Max Movement         : %d\n", M_Mov(U));
    printf("Movement             : %d\n", Mov(U));
    printf("Cost                 : %d\n", Cost(U));
    printf("Upkeep               : %d\n", Upkeep(U));
    printf("Position             : <%d, %d>\n", Absis(Pos(U)), Ordinat((Pos(U))));
    printf("Attack Type          : %c\n", Atk_Type(U));
    printf("Can attack           : ");

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
    print_unit_type(U);
    TulisPOINT(Pos(U));
    printf(" | ");
    printf("Health %d/%d  ",Hp(U),M_Hp(U));
    if(Retaliates){
        printf("(Retaliates)");
    }
    printf("\n");
}

void print_unit_type(UNIT U)
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



