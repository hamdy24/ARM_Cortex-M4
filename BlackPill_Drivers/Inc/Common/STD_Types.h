/*
 * STD_Types.h
 *
 *  Created on: Aug 3, 2023
 *      Author: hamdy
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*typedef <dataType> <newName>*/

typedef unsigned char         	uint8_t;
typedef unsigned short int    	uint16_t;
typedef unsigned long int     	uint32_t;

typedef signed char           	sint8_t;
typedef signed short int      	sint16_t;
typedef signed long int       	sint32_t;

typedef float                 	f32;
typedef double                	f64;
typedef long double           	f80;

typedef volatile void (*CallBackFunc_t)(void);

typedef enum{
	false,
	true,
}bool;

#define NULL 		     	 	(void*)0


#endif /* STD_TYPES_H_ */
