#include "stdio.h"
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

void attack(UNIT *Attacker)
/*I.S. Attacker terdefinisi*/
/*F.S. menjalankan command attack sesuai kondisi yang terdefinisi*/
{
    /*int Found=false; 

    if(M(Absis(Pos(*Attacker))+1,Ordinat(Pos(*Attacker)))!='0'){
        Found=true;

    }
    if(M(Absis(Pos(*Attacker))-1,Ordinat(Pos(*Attacker)))!='0'){
        Found=true;
    }
    if(M(Absis(Pos(*Attacker)),Ordinat(Pos(*Attacker))+1)!='0'){
        Found=true;
    }
    if(M(Absis(Pos(*Attacker)),Ordinat(Pos(*Attacker))-1)!='0'){
        Found=true;
    }*/
}

void unit_attack(UNIT *Attacker, UNIT *Defender)
/*I.S. Attacker dan Defender letaknya bersebalahan*/
/*F.S. health dari Attacker dan Defender berubah sesuai kondisi*/
{
    Can_Atk(*Attacker)=false;
    if(Type(*Defender)!='K'){
        if(Type(*Attacker)==Type(*Defender)){
            M_Hp(*Defender)-=Atk(*Attacker);
            if(M_Hp(*Defender)!=0){
                M_Hp(*Attacker)-=Atk(*Defender);   
            } 
        }else{
            M_Hp(*Defender)-=Atk(*Attacker);
        }
    }else{
        M_Hp(*Attacker)-=Atk(*Defender);
        M_Hp(*Defender)-=Atk(*Attacker);
    }

}