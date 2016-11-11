#include "stdafx.h"
#include "EBPOperations.h"

bool checkIfDistinct(vector<vector<int>> EBP)
{
	bool checkedResult = true;

	vector<vector<vector<int>>> symmetricEBPs(3);

	symmetricEBPs[0] = inverseEBP(EBP, M);
	symmetricEBPs[1] = inverseEBP(switchEBP(EBP, N), M);
	symmetricEBPs[2] = switchEBP(EBP, N);

	for (int i = 0; i < 3; i++)
	{
		if (EqualEBP(EBP, LargerEBP(EBP, symmetricEBPs[i],N),N))
			continue;
		else
		{
			checkedResult = false;
			break;
		}
	}

	return checkedResult;
}

bool checkIfDistinctHEBP(vector<vector<int>> VEBP, vector<vector<int>> HEBP)
{
	bool checkedResult = true;
	vector<vector<vector<int>>> symmetricVEBPs(3);
	vector<vector<vector<int>>> symmetricHEBPs(3);

	symmetricVEBPs[0] = inverseEBP(VEBP, M);
	symmetricVEBPs[1] = switchEBP(VEBP, N);
	symmetricVEBPs[2] = inverseEBP(switchEBP(VEBP, N), M);

	symmetricHEBPs[0] = switchEBP(HEBP, M);
	symmetricHEBPs[1] = inverseEBP(HEBP, N);
	symmetricHEBPs[2] = inverseEBP(switchEBP(HEBP,M), N);

	for (int i = 0; i < 3; i++)
	{
		if (EqualEBP(VEBP, symmetricVEBPs[i],N))
		{
			if (EqualEBP(HEBP, LargerEBP(HEBP, symmetricHEBPs[i],M),M))
				continue;
			else
			{
				checkedResult = false;
				break;
			}
		}
	}

	return checkedResult;
}

bool checkRotationalSymmetryOfHEBP(vector<vector<int>> VEBP, vector<vector<int>> HEBP)
{
	bool checkedResult = true;
	vector<vector<vector<int>>> symmetricHEBPs(4);
	vector<vector<vector<int>>> symmetricVEBPs(4);
	symmetricHEBPs[0] = switchEBP(rotateHEBP(HEBP), N);
	symmetricHEBPs[1] = inverseEBP(rotateHEBP(HEBP), M);
	symmetricHEBPs[2] = inverseEBP(switchEBP(rotateHEBP(HEBP), N), M);
	symmetricHEBPs[3] = rotateHEBP(HEBP);

	symmetricVEBPs[0] = switchEBP(rotateVEBP(VEBP), M);
	symmetricVEBPs[1] = inverseEBP(rotateVEBP(VEBP), N);
	symmetricVEBPs[2] = inverseEBP(switchEBP(rotateVEBP(VEBP), M), N);
	symmetricVEBPs[3] = rotateVEBP(VEBP);

	for (int i = 0; i < 4; i++)
	{
		if (EqualEBP(VEBP, LargerEBP(VEBP, symmetricHEBPs[i],N),N))
		{
			if (EqualEBP(VEBP, symmetricHEBPs[i],N))
			{
				if (EqualEBP(HEBP, LargerEBP(HEBP, symmetricVEBPs[i], M),M))
					continue;
				else
				{
					checkedResult = false;
					break;
				}
			}
		}
		else
		{
			checkedResult = false;
			break;
		}
	}

	return checkedResult;
}

vector<vector<int>> inverseEBP(vector<vector<int>> EBP, int numbBins)
{
	vector<vector<int>> inversedEBP;

	for (vector<vector<int>>::iterator it = EBP.begin(); it != EBP.end(); it++)
	{
		vector<int> inversedSection;
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			int inversedBinaryPosition = numbBins - *it2 + 1;
			inversedSection.push_back(inversedBinaryPosition);
		}
		inversedEBP.push_back(inversedSection);
	}
	return inversedEBP;
}

vector<vector<int>> switchEBP(vector<vector<int>> EBP, int numbSection)
{
	vector<vector<int>> switchedEBP(numbSection - 1);
	for (int i = 0; i < numbSection - 1; i++)
	{
		int switchedIndex = numbSection - i - 2;
		switchedEBP[switchedIndex] = EBP[i];
	}
	return switchedEBP;
}

vector<vector<int>> rotateHEBP(vector<vector<int>> HEBP)
{	
	vector<vector<int>> rotatedHEBP = inverseEBP(HEBP, N);
	return rotatedHEBP;
}

vector<vector<int>> rotateVEBP(vector<vector<int>> VEBP)
{
	vector<vector<int>> rotatedHEBP = inverseEBP(VEBP, M);
	return rotatedHEBP;
}


void writeEBP(vector<vector<int>> EBP, ofstream &myfile)
{
	for (vector<vector<int>>::iterator it = EBP.begin(); it != EBP.end(); ++it)
	{
		for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
			myfile << *it2;
		myfile << " ";
	}
	myfile << endl;
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


void printEBPi(vector<int> EBPi)
{
	for (vector<int>::iterator it = EBPi.begin(); it != EBPi.end(); ++it)
		cout << *it;
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

vector<vector<int>> LargerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2, int numbSection)
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

	for (int i = 0; i <numbSection - 1; i++)
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

vector<vector<int>> SmallerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2, int numbSection)
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

	for (int i = 0; i < numbSection - 1; i++)
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

bool EqualEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2, int numbSection)
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

	for (int i = 0; i < numbSection - 1; i++)
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
