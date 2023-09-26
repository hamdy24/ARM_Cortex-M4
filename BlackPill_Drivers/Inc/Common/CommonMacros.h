/*
 * Common.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 23, 2023
 *	Brief		: This file contains some common Macros
 */

#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_


#define MAP(VAL,OLD_MIN,OLD_MAX,NEW_MIN,NEW_MAX)	((f32)((OLD_MIN-NEW_MAX*VAL)+(f32)((f32)(VAL-OLD_MAX)*NEW_MIN))/(OLD_MIN-OLD_MAX))

/***************************************************************************************************
                                Macros for Bit Manipulation
 ****************************************************************************************************/

#define MASK_BIT			  						1UL
// Mask Helpers
#define MASK_1BIT			  						1UL
#define MASK_2BIT			  						3UL
#define MASK_3BIT			  						7UL
#define MASK_4BIT			  						15UL


#define GET_BIT_MSK(BIT)          					(MASK_BIT<<(BIT))
#define SET_BIT(REG,BIT)          					((REG) |=  GET_BIT_MSK(BIT))
#define CLR_BIT(REG,BIT)          					((REG) &= ~GET_BIT_MSK(BIT))
#define TOG_BIT(REG,BIT)         					((REG) ^=  GET_BIT_MSK(BIT))
#define READ_BIT(REG,BIT)							((REG)  &  GET_BIT_MSK(BIT))
// Use these if the mask and set values are already shifted
#define MASK_BITS(REG,MASK)							( (REG) & (~(MASK)) )
#define UPDATE_BITS(REG,MASK,VAL)					( (REG) = MASK_BITS(REG,MASK) | VAL)

// Use these if the mask and set values are not shifted yet
#define MASK_BITS_OFFSET(REG,MSK,OFFSET)			( (REG) & (~(MSK<<OFFSET)) )
#define UPDATE_BITS_OFFSET(REG,MSK,VAL,OFFSET)		( (REG) = MASK_BITS_OFFSET(REG,MSK,OFFSET) | (VAL<<OFFSET) )

#define IS_BIT_SET(REG,BIT)          				(((REG)&(GET_BIT_MSK(BIT)))!=0u)
#define IS_BIT_CLEARED(REG,BIT)      				(((REG)&(GET_BIT_MSK(BIT)))==0u)

/**************************************************************************************************/


#endif /* COMMONMACROS_H_ */
