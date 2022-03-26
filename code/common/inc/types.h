#ifndef _TYPES_H_
#define _TYPES_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef unsigned char           UInt8;  /* 1 byte */
typedef unsigned short          UInt16; /* 2 byte */
typedef unsigned int            UInt32; /* 4 byte */
typedef unsigned long long      UInt64; /* 8 byte */
typedef signed char             SInt8;  /* 1 byte */
typedef signed short            SInt16; /* 2 byte */
typedef signed int              SInt32; /* 4 byte */
typedef signed long long        SInt64; /* 8 byte */

/*===================== Define Method Common porting =====================*/
void genarate_random_number(
	UInt8 *a,
	UInt8 num 
);
void handler_array(
	UInt8 *a, 
	UInt8 *size
);
void show_array(
	UInt8 *a,
	const UInt8 size
);
#endif