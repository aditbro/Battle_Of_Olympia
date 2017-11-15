
#ifndef BUILDING_H
#define BUILDING_H

#include "ADT/point.h"
#include <stdio.h>

typedef struct {
    char type;
    int owner;
    POINT position;
} Build;

#define Build_Type(B) (B).type
#define Build_Owner(B) (B).owner
#define Build_Pos(B) (B).position

void init_build(Build *B, char type, int owner, int x, int y);

Build create_new_build(char type, int owner, int x, int y);

void print_build_type(Build B);


#endif
