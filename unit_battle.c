#include "ADT/array.h"
#include "ADT/boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unit_battle.h"

int getrandom(int low, int high) {
    int r;
    srand (time(NULL));
    r = low + rand() / (RAND_MAX / (high - low + 1) + 1); // using this because the low-order bits of many random number generators are distressingly non-random
    return r;
}

boolean get_hit (UNIT Defender) {
    TabInt Prob;
    int i;

    array_Neff(Prob) = 100;
    for (i=1;i<=100;i++){
        array_Elmt(Prob, i) = (i<=GHP(Defender)) ? 1 : 0;
    }

    return (array_Elmt(Prob, getrandom(1,100))==1) ? true : false;
}

void unit_attack(UNIT * Attacker, UNIT * Defender)
/*I.S. Attacker dan Defender letaknya bersebalahan*/
/*F.S. health dari Attacker dan Defender berubah sesuai kondisi*/
{
    //if (get_hit(*Defender)){
        Can_Atk(*Attacker)=false;
        if(Type(*Defender)!='K'){
            if(Atk_Type(*Attacker)==Atk_Type(*Defender)){
                Hp(*Defender)-=Atk(*Attacker);
                printf("Enemy's ");
                print_unit_type(*Defender);
                printf("is damaged by %d\n",Atk(*Attacker));
                if(Hp(*Defender)!=0){
                    Hp(*Attacker)-=Def(*Defender);
                    printf("Enemy's ");
                    print_unit_type(*Defender);
                    printf("retaliates.\n");
                    printf("Your ");
                    print_unit_type(*Attacker);
                    printf("is damaged by %d\n",Def(*Defender));  
                }else{
                    Type(*Defender)=Nil;
                }
            }else{
                Hp(*Defender)-=Atk(*Attacker);
                printf("Enemy's ");
                print_unit_type(*Defender);
                printf("is damaged by %d\n",Atk(*Attacker));
            }
        }else{
            Hp(*Defender)-=Atk(*Attacker);
            Hp(*Attacker)-=Def(*Defender);
            printf("Enemy's ");
            print_unit_type(*Defender);
            printf("is damaged by %d\n",Atk(*Attacker));
            printf("Enemy's ");
            print_unit_type(*Defender);
            printf("retaliates.\n");
            printf("Your ");
            print_unit_type(*Attacker);
            printf("is damaged by %d\n",Def(*Defender));   
        }
        if(Hp(*Attacker)==0){
            printf("Your ");
            print_unit_type(*Attacker);
            printf("is dead :(");
            Type(*Attacker)=Nil;
        }
    //}
    //else{
        //printf("Oops, enemy avoided your attack! Better luck next time ;-)\n");
    //}

}
void attack(UNIT *Attacker, MAP *M)
/*I.S. Attacker terdefinisi*/
/*F.S. menjalankan command attack sesuai kondisi yang terdefinisi*/
{
    int Found=false; 
    int count=0;
    int inp;        //input
    int inpmusuh;    //musuh mana yang dipilih
    TabInt lokasi;   //bila ada di semua tempat  maka [1,2,3,4]
    int Xatk=Absis(Pos(*Attacker));
    int Yatk=Ordinat(Pos(*Attacker));
    if(Can_Atk(*Attacker)){
        array_MakeEmpty(&lokasi);
        if(Type(Unit(*M,Xatk+1,Yatk))!=Nil&& Owner(Unit(*M,Xatk+1,Yatk))!=Owner(*Attacker)&&Hp(Unit(*M,Xatk+1,Yatk))!=0){
            Found=true;
            array_AddAsLastEl(&lokasi,1);
            count+=1;
            if(count==1){
                printf("Please select enemy you want to attack:\n");
            }
            printf("%d. ",count);
            if(Atk_Type(Unit(*M,Xatk+1,Yatk))==Atk_Type(*Attacker)){
                show_unit_available(Unit(*M,Xatk+1,Yatk),true);
            }else{
                show_unit_available(Unit(*M,Xatk+1,Yatk),false);
            }
        }
        if(Type(Unit(*M,Xatk-1,Yatk))!=Nil&& Owner(Unit(*M,Xatk-1,Yatk))!=Owner(*Attacker)&&Hp(Unit(*M,Xatk-1,Yatk))!=0){
            Found=true;
            array_AddAsLastEl(&lokasi,2);
            count+=1;
            if(count==1){
                printf("Please select enemy you want to attack:\n");
            }
            printf("%d. ",count);
            if(Atk_Type(Unit(*M,Xatk-1,Yatk))==Atk_Type(*Attacker)){
                show_unit_available(Unit(*M,Xatk-1,Yatk),true);
            }else{
                show_unit_available(Unit(*M,Xatk-1,Yatk),false);
            }
        }
        if(Type(Unit(*M,Xatk,Yatk+1))!=Nil&& Owner(Unit(*M,Xatk,Yatk+1))!=Owner(*Attacker)&&Hp(Unit(*M,Xatk,Yatk+1))!=0){
            Found=true;
            array_AddAsLastEl(&lokasi,3);
            count+=1;
            if(count==1){
                printf("Please select enemy you want to attack:\n");
            }
            printf("%d. ",count);
            if(Atk_Type(Unit(*M,Xatk,Yatk+1))==Atk_Type(*Attacker)){
                show_unit_available(Unit(*M,Xatk,Yatk+1),true);
            }else{
                show_unit_available(Unit(*M,Xatk,Yatk+1),false);
            }
        }
        if(Type(Unit(*M,Xatk,Yatk-1))!=Nil&& Owner(Unit(*M,Xatk,Yatk-1))!=Owner(*Attacker)&&Hp(Unit(*M,Xatk,Yatk-1))!=0){
            Found=true;
            array_AddAsLastEl(&lokasi,4);
            count+=1;
            if(count==1){
                printf("Please select enemy you want to attack:\n");
            }
            printf("%d. ",count);
            if(Atk_Type(Unit(*M,Xatk,Yatk-1))==Atk_Type(*Attacker)){
                show_unit_available(Unit(*M,Xatk,Yatk-1),true);
            }else{
                show_unit_available(Unit(*M,Xatk,Yatk-1),false);
            }
        }
        if(Found){
            printf("Select enemy you want to attack : ");
            do{
                scanf("%d",&inp);
                if(inp<=count){
                    inpmusuh=array_Elmt(lokasi,inp);
                    if(inpmusuh==1){     
                        unit_attack(Attacker,&Unit(*M,Xatk+1,Yatk));
                    }else if(inpmusuh==2){
                        unit_attack(Attacker,&Unit(*M,Xatk-1,Yatk));
                    }else if(inpmusuh==3){
                        unit_attack(Attacker,&Unit(*M,Xatk,Yatk+1));
                    }else if(inpmusuh==4){
                        unit_attack(Attacker,&Unit(*M,Xatk,Yatk-1));
                    }
                }else{
                    printf("Wrong target\n");
                    printf("Select enemy you want to attack : ");
                }
            }while(inp>count);
        }
        else{
            printf("Enemy not found\n");
        }
    }else{
        printf("You have attacked\n");
    }
}
