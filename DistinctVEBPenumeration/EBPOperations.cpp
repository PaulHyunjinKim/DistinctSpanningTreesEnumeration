#include "stdafx.h"
#include "EBPOperations.h"

bool checkIfDistinct(vector<vector<int>> EBP)
{
	bool checkedResult = true;

	vector<vector<vector<int>>> symmetricEBPs(3);

	symmetricEBPs[0] = inverseEBP(EBP);
	symmetricEBPs[1] = switchEBP(EBP);
	symmetricEBPs[2] = inverseEBP(switchEBP(EBP));

	/*printEBP(EBP);
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		printEBP(symmetricEBPs[i]);
		cout << endl;
	}*/


	for (int i = 0; i < 3; i++)
	{
		if (EqualEBP(EBP, LargerEBP(EBP, symmetricEBPs[i])))
			continue;
		else
		{
			checkedResult = false;
			break;
		}
	}

	return checkedResult;
}

vector<vector<int>> inverseEBP(vector<vector<int>> EBP)
{
	vector<vector<int>> inversedEBP;

	for (vector<vector<int>>::iterator it = EBP.begin(); it != EBP.end(); it++)
	{
		vector<int> inversedSection;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			int inversedBinaryPosition = M - *it2 + 1;
			inversedSection.push_back(inversedBinaryPosition);
		}
		inversedEBP.push_back(inversedSection);
	}
	return inversedEBP;
}

vector<vector<int>> switchEBP(vector<vector<int>> EBP)
{
	vector<vector<int>> switchedEBP(N - 1);
	for (int i = 0; i < N - 1; i++)
	{
		int switchedIndex = N - i - 2;
		switchedEBP[switchedIndex] = EBP[i];
	}
	return switchedEBP;
}

void printEBP(vector<vector<int>> EBP)
{
	for (vector<vector<int>>::iterator it = EBP.begin(); it != EBP.end(); ++it)
	{
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			cout << *it2;
		cout << " ";
	}
	cout << endl;
}

void allCombinationsOfKInN(int startIndex, int leftElements, int n, vector<int> result, vector<vector<int>> &EBP)
{
	if (leftElements == 0)
		EBP.push_back(result);
	else
	{
		for (int i = startIndex; i <= n - leftElements + 1; i++)
		{
			result.push_back(i);
			allCombinationsOfKInN(i + 1, leftElements - 1, n, result, EBP);
			result.pop_back();
		}
	}
}

vector<vector<int>> LargerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2)
{
	vector<vector<int>> maxEBP;
	maxEBP = EBP1;
	vector<int> EBP1Integers;
	vector<int> EBP2Integers;

	for (vector<vector<int>>::iterator it = EBP1.begin(); it != EBP1.end(); ++it)
	{
		int integer = 0;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			integer += pow(2,*it2-1);
		EBP1Integers.push_back(integer);
	}

	for (vector<vector<int>>::iterator it = EBP2.begin(); it != EBP2.end(); ++it)
	{
		int integer = 0;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			integer += pow(2, *it2 - 1);
		EBP2Integers.push_back(integer);
	}

	for (int i = 0; i < N - 1; i++)
	{
		if (EBP1Integers[i] < EBP2Integers[i])
		{
			maxEBP = EBP2;
			break;
		}
		else if (EBP1Integers[i] > EBP2Integers[i])
		{
			maxEBP = EBP1;
			break;
		}
	}


	return maxEBP;
}

vector<vector<int>> SmallerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2)
{
	vector<vector<int>> minEBP;
	minEBP = EBP1;
	vector<int> EBP1Integers;
	vector<int> EBP2Integers;

	for (vector<vector<int>>::iterator it = EBP1.begin(); it != EBP1.end(); ++it)
	{
		int integer = 0;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			integer += pow(2, *it2 - 1);
		EBP1Integers.push_back(integer);
	}

	for (vector<vector<int>>::iterator it = EBP2.begin(); it != EBP2.end(); ++it)
	{
		int integer = 0;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			integer += pow(2, *it2 - 1);
		EBP2Integers.push_back(integer);
	}

	for (int i = 0; i < N - 1; i++)
	{
		if (EBP1Integers[i] > EBP2Integers[i])
		{
			minEBP = EBP2;
			break;
		}
		else if (EBP1Integers[i] < EBP2Integers[i])
		{
			minEBP = EBP1;
			break;
		}
	}

	return minEBP;
}

bool EqualEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2)
{
	bool equalCheck = true;

	vector<int> EBP1Integers;
	vector<int> EBP2Integers;

	for (vector<vector<int>>::iterator it = EBP1.begin(); it != EBP1.end(); ++it)
	{
		int integer = 0;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			integer += pow(2, *it2 - 1);
		EBP1Integers.push_back(integer);
	}

	for (vector<vector<int>>::iterator it = EBP2.begin(); it != EBP2.end(); ++it)
	{
		int integer = 0;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			integer += pow(2, *it2 - 1);
		EBP2Integers.push_back(integer);
	}

	for (int i = 0; i < N - 1; i++)
	{
		if (EBP1Integers[i] == EBP2Integers[i])
			continue;
		else
		{
			equalCheck = false;
			break;
		}
	}


	return equalCheck;
}
