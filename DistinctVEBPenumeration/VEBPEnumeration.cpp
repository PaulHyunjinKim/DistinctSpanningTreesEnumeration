#include "stdafx.h"
#include "VEBPEnumeration.h"


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

void allCombinationsOfKInN(int startIndex, int leftElements, vector<int> result, vector<vector<int>> &VEBP)
{
	if (leftElements == 0)
	{
		/*for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
		{
			cout << *it;
		}
		cout << endl;*/
		VEBP.push_back(result);
		//send message to HEBP enumeration..//
	}
	else
	{
		for (int i = startIndex; i <= N - leftElements + 1; i++)
		{
			result.push_back(i);
			allCombinationsOfKInN(startIndex + 1, leftElements - 1, result, VEBP);
			result.pop_back();
		}
	}
}

void distinctVEBPEnumeration(vector<int> result)
{
	//cout << "result " << endl;
	
	vector<vector<vector<int>>> VEBPSet;
	///combinatorics based on #1bits in each section of VEBP///
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
	{		
		int K = *it;
		vector<int> resultForCombinations;
		vector<vector<int>> VEBP;
				
		allCombinationsOfKInN(1, K, resultForCombinations, VEBP);
		VEBPSet.push_back(VEBP);
	}
	/*for (int i = 0; i < VEBPSet.size(); i++)
	{
		cout << "section Number: " << i + 1 << endl;
		for (int j = 0; j < VEBPSet[i].size(); j++)
		{
			cout << "size: " << VEBPSet[i][j].size() << endl;
			for (int k = 0; k < VEBPSet[i][j].size(); k++)
				cout << VEBPSet[i][j][k] << " ";
			cout << endl;
		}
	}
	cout << endl;*/
}

void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> VEBPSet, vector<vector<int>> result)
{
	if (sectionNumber == N)
	{
		for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it)
		{
			//cout << *it;
		}
		cout << endl;
	}
	else
	{

	}
}