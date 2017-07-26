/*
 * Time.hpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_NANNY_TIME_HPP_
#define APPLICATION_NANNY_TIME_HPP_

struct Time
{
	u32 miliseconds;
	Time()
		: miliseconds(0)
	{

	}
	Time& operator +=(u32 _ms)
	{
		this->miliseconds += _ms;
		return *this;
	}
	u32 getMilisecond()
	{
		return miliseconds%1000;
	}
	u32 getSecond()
	{
		return (miliseconds%60000) / 1000;
	}
	u32 getMinute()
	{
		return miliseconds/60000;
	}
};



#endif /* APPLICATION_NANNY_TIME_HPP_ */
