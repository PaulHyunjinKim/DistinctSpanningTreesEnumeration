#include "stdafx.h"
#include "VEBPEnumeration.h"
#include "HEBPEnumeration.h"
#include "EBPOperations.h"


void VEBPEnumeartion()
{
	int OneBitsNumber = 0;
	int startNumberOfBitsInVEBP = ceilf((float)(M*N - 1) / 2);
	if (M != N)
		startNumberOfBitsInVEBP = N - 1;


	for (OneBitsNumber = startNumberOfBitsInVEBP; OneBitsNumber <= N*N - N; OneBitsNumber++)//enumerate VEBP based on # 1bits on VEBP
	{
		vector<int> result;
		//send message to VEBPEnumeration...//
		SetOneBitNumberOnEachSectionVEBP(OneBitsNumber, 0, result, 0);
	}

}

void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentRow, vector<int> result, int LastOneBitsNumber)
{
	currentRow += 1;
	LeftOneBitsNumber -= LastOneBitsNumber;

	if (currentRow > N - 1)
	{
		distinctVEBPEnumeration(result);
	}
	else
	{
		int MinNumber = max(1, LeftOneBitsNumber - M*(N - 1 - currentRow));
		int MaxNumber = min(M, LeftOneBitsNumber - (N - 1 - currentRow));
		
		for (LastOneBitsNumber = MinNumber; LastOneBitsNumber <= MaxNumber; LastOneBitsNumber++)
		{
			result.push_back(LastOneBitsNumber);
			SetOneBitNumberOnEachSectionVEBP(LeftOneBitsNumber, currentRow, result, LastOneBitsNumber);
			result.pop_back();
		}
	}
}

void distinctVEBPEnumeration(vector<int> result)
{
	cout << "result " << endl;
	
	vector<vector<vector<int>>> VEBPSet;
	///combinatorics based on #1bits in each section of VEBP///
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
	{		
		int K = *it;
		vector<int> resultForCombinations;
		vector<vector<int>> VEBPi;
		cout << K << " ";
		allCombinationsOfKInN(1, K, M, resultForCombinations, VEBPi);
		
		VEBPSet.push_back(VEBPi);
	}
	cout << endl;
	
	vector<vector<int>> VEBP;
	completeEachVEBP(0, VEBPSet, VEBP);
	cout << endl;
}



void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> VEBPSet, vector<vector<int>> VEBP)
{
	if (sectionNumber == N - 1)
	{
		
		if (checkIfDistinct(VEBP))
		{
			//printEBP(VEBP);
			//send message to HEBP enumeration..//
			HEBPEnumeration(VEBP);
			//////////
		}
		
		
	}
	else
	{
		for (int i = 0; i < VEBPSet[sectionNumber].size(); i++)
		{
			VEBP.push_back(VEBPSet[sectionNumber][i]);
			
			completeEachVEBP(sectionNumber + 1, VEBPSet, VEBP);

			VEBP.pop_back();
		}
	}
}

