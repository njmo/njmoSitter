/*
 * defines.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: njmo
 */

#ifndef DEFINES_HPP_
#define DEFINES_HPP_

typedef float							r32;
typedef double						r62;

typedef unsigned int			u32;
typedef unsigned char			u8;
typedef	unsigned long		u16;
typedef unsigned long int 	u64;

typedef int								i32;
typedef char							i8;
typedef	long							i16;
typedef long int 					i64;

enum class msgID: u8
{
	MESSAGE_IN=0,
	MESSAGE_OUT
};

#endif /* DEFINES_HPP_ */
