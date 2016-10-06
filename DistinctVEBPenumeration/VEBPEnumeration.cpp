#include "stdafx.h"
#include "VEBPEnumeration.h"
#include "EBPOperations.h"


void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentColumn, vector<int> result, int LastOneBitsNumber)
{
	currentColumn += 1;
	LeftOneBitsNumber -= LastOneBitsNumber;

	if (currentColumn > N - 1)
	{
		//send message...////
		distinctVEBPEnumeration(result);
	}
	else
	{
		int MinNumber = max(1, LeftOneBitsNumber - N*(N - 1 - currentColumn));
		int MaxNumber = min(N, LeftOneBitsNumber - (N - 1 - currentColumn));
		
		for (LastOneBitsNumber = MinNumber; LastOneBitsNumber <= MaxNumber; LastOneBitsNumber++)
		{
			result.push_back(LastOneBitsNumber);
			SetOneBitNumberOnEachSectionVEBP(LeftOneBitsNumber, currentColumn, result, LastOneBitsNumber);
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
		vector<vector<int>> VEBP;
		cout << K << " ";
		allCombinationsOfKInN(1, K, resultForCombinations, VEBP);
		
		VEBPSet.push_back(VEBP);
	}
	cout << endl;
	
	vector<vector<int>> VEBP;
	completeEachVEBP(0, VEBPSet, VEBP);
	cout << endl;
}

void allCombinationsOfKInN(int startIndex, int leftElements, vector<int> result, vector<vector<int>> &VEBP)
{
	if (leftElements == 0)
		VEBP.push_back(result);
	else
	{
		for (int i = startIndex; i <= N - leftElements + 1; i++)
		{
			result.push_back(i);
			allCombinationsOfKInN(i + 1, leftElements - 1, result, VEBP);
			result.pop_back();
		}
	}
}

void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> VEBPSet, vector<vector<int>> VEBP)
{
	if (sectionNumber == N-1)
	{
		if(checkIfDistinct(VEBP))
			printEBP(VEBP);
		//send message to HEBP enumeration..//


		
		//getchar();

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

