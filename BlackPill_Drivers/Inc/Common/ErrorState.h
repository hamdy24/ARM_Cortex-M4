/*
 * ErrorState.h
 *
 *  Created on: August 3, 2023
 *      Author: Hamdy Aouf
 */

#ifndef ERRORSTATE_H_
#define ERRORSTATE_H_


typedef enum {
	ES_NOK ,
	ES_OK ,
	ES_OUT_OF_RANGE ,
	ES_POINTER_TO_VOID,
	ES_INVALID_ACCESS,
	ES_INVALID_INPUTS,
}ES_t;


#endif /* ERRORSTATE_H_ */
