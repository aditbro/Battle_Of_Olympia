#include "../ADT/array.h"
#include "../ADT/boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unit_battle.h"

void heal(UNIT  Mage, MAP *M)
/* Heal other unit */
{
    int Xmage=Absis(Pos(Mage));
    int Ymage=Ordinat(Pos(Mage));
    if(Type(Unit(*M,Xmage+1,Ymage))!=Nil&& Owner(Unit(*M,Xmage+1,Ymage))==Owner(Mage)&&Hp(Unit(*M,Xmage+1,Ymage))!=0&&Hp(Unit(*M,Xmage+1,Ymage))!=100){
        Hp(Unit(*M,Xmage+1,Ymage))+=Heal(Mage);
        if(Hp(Unit(*M,Xmage+1,Ymage))>100){
            Hp(Unit(*M,Xmage+1,Ymage))=100;
        }
    }
    if(Type(Unit(*M,Xmage-1,Ymage))!=Nil&& Owner(Unit(*M,Xmage-1,Ymage))==Owner(Mage)&&Hp(Unit(*M,Xmage-1,Ymage))!=0&&Hp(Unit(*M,Xmage-1,Ymage))!=100){
        Hp(Unit(*M,Xmage-1,Ymage))+=Heal(Mage);
        if(Hp(Unit(*M,Xmage-1,Ymage))>100){
            Hp(Unit(*M,Xmage-1,Ymage))=100;
        }
    }
    if(Type(Unit(*M,Xmage,Ymage+1))!=Nil&& Owner(Unit(*M,Xmage,Ymage+1))==Owner(Mage)&&Hp(Unit(*M,Xmage,Ymage+1))!=0&&Hp(Unit(*M,Xmage,Ymage+1))!=100){
        Hp(Unit(*M,Xmage,Ymage+1))+=Heal(Mage);
        if(Hp(Unit(*M,Xmage,Ymage+1))>100){
            Hp(Unit(*M,Xmage,Ymage+1))=100;
        }
    }
    if(Type(Unit(*M,Xmage,Ymage-1))!=Nil&& Owner(Unit(*M,Xmage,Ymage-1))==Owner(Mage)&&Hp(Unit(*M,Xmage,Ymage-1))!=0&&Hp(Unit(*M,Xmage+1,Ymage-1))!=100){
        Hp(Unit(*M,Xmage,Ymage-1))+=Heal(Mage);
        if(Hp(Unit(*M,Xmage,Ymage-1))>100){
            Hp(Unit(*M,Xmage,Ymage-1))=100;
        }
    }
}


boolean get_hit (UNIT Defender) {
    TabInt Prob;
    int i, r;

    array_Neff(Prob) = 100;
    for (i=1;i<=100;i++){
        array_Elmt(Prob, i) = (i<=GHP(Defender)) ? 1 : 0;
    }

    r = (rand() % 100) + 1;

    return (array_Elmt(Prob, r)==1) ? true : false;
}

void unit_attack(UNIT * Attacker, UNIT * Defender,boolean *Win, boolean *Lose)
/*I.S. Attacker dan Defender letaknya bersebalahan*/
/*F.S. health dari Attacker dan Defender berubah sesuai kondisi*/
{
    srand (time(NULL));
    Can_Atk(*Attacker)=false;
    Mov(*Attacker)=0;
    *Win=false;
    *Lose=false;
    if (get_hit(*Defender)){
        if(Type(*Defender)!='K'){
            if(Atk_Type(*Attacker)==Atk_Type(*Defender)){
                Hp(*Defender)-=Atk(*Attacker);
                printf("Enemy's ");
                print_unit_type(*Defender);
                printf("is damaged by %d\n",Atk(*Attacker));
                if(Hp(*Defender)>0){
                    printf("Enemy's ");
                    print_unit_type(*Defender);
                    printf("retaliates.\n");
                    if(get_hit(*Attacker)){
                        Hp(*Attacker)-=Def(*Defender);
                        printf("Your ");
                        print_unit_type(*Attacker);
                        printf("is damaged by %d\n",Def(*Defender)); 
                        if(Type(*Attacker)=='K' && Hp(*Attacker)){
                            *Lose=true;
                        } 
                    }else{
                        printf("But your unit avoided their attack\n");
                    }
                }else{
                    Type(*Defender)=Nil;
                    printf("Your enemy's unit died\n");
                }
            }else{
                Hp(*Defender)-=Atk(*Attacker);
                printf("Enemy's ");
                print_unit_type(*Defender);
                printf("is damaged by %d\n",Atk(*Attacker));
            }
        }else{
            Hp(*Defender)-=Atk(*Attacker);
            printf("Enemy's ");
            print_unit_type(*Defender);
            printf("is damaged by %d\n",Atk(*Attacker));
            if(Hp(*Defender)>0){
                printf("Enemy's ");
                print_unit_type(*Defender);
                printf("retaliates.\n");
                if(get_hit(*Attacker)){
                    Hp(*Attacker)-=Def(*Defender);
                    printf("Your ");
                    print_unit_type(*Attacker);
                    printf("is damaged by %d\n",Def(*Defender));   
                }else{
                    printf("But your unit avoided their attack\n");
                }
            }else{
                Type(*Defender)=Nil;
                *Win=true;
                printf("Your enemy king died\n");
            }
        }
        if(Hp(*Attacker)<=0){
            printf("Your ");
            print_unit_type(*Attacker);
            printf("is dead :(");
            Type(*Attacker)=Nil;
        }
    }
    else{
        printf("Oops, enemy avoided your attack! Better luck next time ;-)\n");
    }

}
void attack(UNIT *Attacker, MAP *M,boolean *Win, boolean *Lose)
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
                printf("\nPlease select enemy you want to attack:\n\n");
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
                printf("\nPlease select enemy you want to attack:\n\n");
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
                printf("\nPlease select enemy you want to attack:\n\n");
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
                printf("\nPlease select enemy you want to attack:\n\n");
            }
            printf("%d. ",count);
            if(Atk_Type(Unit(*M,Xatk,Yatk-1))==Atk_Type(*Attacker)){
                show_unit_available(Unit(*M,Xatk,Yatk-1),true);
            }else{
                show_unit_available(Unit(*M,Xatk,Yatk-1),false);
            }
        }
        if(Found){
            printf("\nSelect enemy you want to attack : ");
            do{
                scanf("%d",&inp);
                printf("\n\nBattle logs : \n");
                if(inp<=count){
                    inpmusuh=array_Elmt(lokasi,inp);
                    boolean Wins,Loses;
                    if(inpmusuh==1){     
                        unit_attack(Attacker,&Unit(*M,Xatk+1,Yatk),&Wins,&Loses);
                    }else if(inpmusuh==2){
                        unit_attack(Attacker,&Unit(*M,Xatk-1,Yatk),&Wins,&Loses);
                    }else if(inpmusuh==3){
                        unit_attack(Attacker,&Unit(*M,Xatk,Yatk+1),&Wins,&Loses);
                    }else if(inpmusuh==4){
                        unit_attack(Attacker,&Unit(*M,Xatk,Yatk-1),&Wins,&Loses);
                    }
                    *Win=Wins;
                    *Lose=Loses;
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
        printf("Your unit is resting...\n");
    }
}
