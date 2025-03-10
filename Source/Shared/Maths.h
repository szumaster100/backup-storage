#ifndef MATH_H
#define MATH_H
#pragma once

#include <math.h>
#include "typedefs.h"

inline double randn_notrig(double mu=0.0, double sigma=1.0) {
	static bool deviateAvailable=false;	//	flag
	static double storedDeviate;			//	deviate from previous calculation
	double polar, rsquared, var1, var2;

	//	If no deviate has been stored, the polar Box-Muller transformation is 
	//	performed, producing two independent normally-distributed random
	//	deviates.  One is stored for the next round, and one is returned.
	if (!deviateAvailable) {

		//	choose pairs of uniformly distributed deviates, discarding those 
		//	that don't fall within the unit circle
		do {
			var1=2.0*( double(rand())/double(RAND_MAX) ) - 1.0;
			var2=2.0*( double(rand())/double(RAND_MAX) ) - 1.0;
			rsquared=var1*var1+var2*var2;
		} while ( rsquared>=1.0 || rsquared == 0.0);

		//	calculate polar tranformation for each deviate
		polar=sqrt(-2.0*log(rsquared)/rsquared);

		//	store first deviate and set flag
		storedDeviate=var1*polar;
		deviateAvailable=true;

		//	return second deviate
		return var2*polar*sigma + mu;
	}

	//	If a deviate is available from a previous call to this function, it is
	//	returned, and the flag is set to false.
	else {
		deviateAvailable=false;
		return storedDeviate*sigma + mu;
	}
}

inline int32 ndice(int _throw, int range)
{
	int32 i, ret;

	if (range <= 0 || _throw <= 0) return 0;

	ret = 0;
	for (i = 1; i <= _throw; i++) {

		ret += (rand() % range) + 1;
	}

	return ret;
}

inline int32 dice(int _throw, int range)
{
	if(_throw > 10)
		return (int32)(
		(_throw * range / 2) + (_throw * randn_notrig()/3) + (_throw / 2)
		);
	else
		return ndice(_throw, range);
	//for decimal mean values
	//return (_throw * range / 2) + (_throw * randn_notrig()/3) + ((range%2) / 2.0) + (_throw / 2);
}

#define GetNibble(var, index)		(  ( var & ( 0xF << (4*index) ) ) >> (4*index)  )
#define GetBit(var, index)			( (var & (1 << index)) >> index )
#define ToBit(index)					(1 << index)

inline void SetNibble(uint32 &var, uint8 index, uint8 val)
{
	index *= 4;
	var &= ~(0xF << index);
	var |= val << index;	
}

inline void SetBit(uint32 &var, uint8 index, bool val)
{
	var &= UINT_MAX - (0x1 << index);
	var |= val << index;
}

#endif // MATH_H