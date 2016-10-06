// DistinctVEBPenumeration.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VEBPEnumeration.h"



int main()
{
	int OneBitsNumber = 0;
	int startNumberOfBits = ceilf((float)(N*N - 1) / 2);

	/*vector<int> resultForCombinations;
	allCombinationsOfKInN(1, 2, resultForCombinations);*/

	for (OneBitsNumber = startNumberOfBits; OneBitsNumber <= N*N - N; OneBitsNumber++)
	{
		vector<int> result;
		//send message...//
		SetOneBitNumberOnEachSectionVEBP(OneBitsNumber, 0, result, 0);
	}

	getchar();
	return 0;
}

