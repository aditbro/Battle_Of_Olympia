/* File: jam.c */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#include "jam.h"
#include <stdio.h>
void print_JAM(){
    time_t t;
    struct tm * timeinfo;

    time ( &t );
    timeinfo = localtime ( &t );
    printf ( "Current time : %s", asctime (timeinfo) );
}