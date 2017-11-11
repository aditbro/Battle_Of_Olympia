/*** INFO COMMAND HANDLER ***/

#include "map.h"
#include "unit.h"
#include "ADT/boolean.h"
#include <stdio.h>

typedef struct {
	int Row;
	int Column;
	UNIT Unit;
} Cell;

#define Row(C)		 (C).Row
#define Col(C)		 (C).Column
#define UnitInCell(C) (C).Unit

/* CTOR */
void CreateCell(Cell *C, int row, int col);

boolean IsUnitInCell(Map M, Cell C);
// Return true jika ada unit di cell dan false jika tidak ada unit di cell

boolean IsBuildingInCell(Map M, Cell C);
// Return true jika ada building di cell dan false jika tidak ada building di cell

void CellUnit(Map M, Cell C, Unit* U);
// Return unit di cell

char BuildingInCell(Map M, int row, Cell C);
// Return tipe building di cell

void printInfo();
// Mencetak info
// Called in main if user input is INFO