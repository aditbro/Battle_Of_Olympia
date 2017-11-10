
#ifndef BUILDING_H
#define BUILDING_H


typedef struct {
    char type;
    int owner;
} Build;

#define Build_Type(B) (B).type
#define Build_Owner(B) (B).owner



#endif
