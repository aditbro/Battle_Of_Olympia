/*** INFO COMMAND HANDLER ***/

#include "map.h"
#include "unit.h"
#include "building.h"
#include "ADT/boolean.h"
#include "ADT/point.h"
#include <stdio.h>

#define Nil '0'

boolean IsUnitInCell(MAP M, POINT P);
// Return true jika ada unit di cell dan false jika tidak ada unit di cell

boolean IsBuildingInCell(MAP M, POINT P);
// Return true jika ada building di cell dan false jika tidak ada building di cell

UNIT CellUnit(MAP M, POINT P);
// Return unit di cell

Build BuildingInCell(MAP M, POINT P);
// Return tipe building di cell

void printInfo();
// Mencetak info
// Called in main if user input is INFO
