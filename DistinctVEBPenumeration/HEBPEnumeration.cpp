#include "stdafx.h"
#include "HEBPEnumeration.h"
#include "EBPOperations.h"

void HEBPEnumeration(vector<vector<int>> VEBP)
{
	//recieve message from VEBP enumeration
	cout << "VEBP: VEBP:///////////////";printEBP(VEBP);
	
	int VENumb = 0;
	int HENumb = 0;
	vector<vector<int>> VEBPPrime(M, vector<int>(N, 0));
	VEBPPrimeAndVENumbFromVEBP(VEBP, VEBPPrime, VENumb);
	HENumb = M*N - 1 - VENumb;

	vector<vector<int>> CCNumbMatrix(M, vector<int>(N + 1, 0));
	CCNumbMatFromVEBPPrime(CCNumbMatrix, VEBPPrime);
		
	vector<vector<int>> HEBP;
	distinctHEBPEnumeartion(0, CCNumbMatrix, HENumb, VENumb, HEBP);
	getchar();
}

void CCNumbMatFromVEBPPrime(vector<vector<int>> &CCNumbMatrix, vector<vector<int>> VEBPPrime)
{
	int CCNumbIndex = 0;
	for (int column = 0; column < VEBPPrime.size(); column++)
	{
		for (int row = 0; row < VEBPPrime[column].size(); row++)
		{
			if (VEBPPrime[column][row] == 1)
			{
				CCNumbMatrix[column][row + 1] = CCNumbMatrix[column][row];
			}
			else
			{
				CCNumbIndex++;
				CCNumbMatrix[column][row + 1] = CCNumbIndex;
			}
		}
	}
}

void VEBPPrimeAndVENumbFromVEBP(vector<vector<int>> VEBP, vector<vector<int>> &VEBPPrime, int &VENumb)
{
	for (int i = 0; i < VEBP.size(); i++)
	{
		for (int j = 0; j < VEBP[i].size(); j++)
		{
			int sectionNumb = VEBP[i][j] - 1;
			int binNumb = i;

			VENumb++;
			VEBPPrime[sectionNumb][binNumb + 1] = 1;
		}
	}
}


void distinctHEBPEnumeartion(int currentColumn, vector<vector<int>> CCNumbMatrix, int HENumb, int VENumb, vector<vector<int>> HEBP)//enumerate all distinct HEBP based on VEBP
{
	
	if (currentColumn > M - 2)
	{
		cout << "CCNumbMAtrix: "; printEBP(CCNumbMatrix); cout << endl;
		cout << "final CC#://////////////////// "; printEBPi(CCNumbMatrix[currentColumn]); cout << endl;

		//end..finish enumeration.. after check symmetry.. print or store HEBP
		//if VEBPprime == inv sym, switch op on HEBP --> if HEBP >= max(HEBP, switch(HEBP)) --> OK. 
		//if VEBPPrime == switch sym, inv on HEBP
		// if VEBPPrime == invSwitch, invSwitch on HEBP
		cout << "HEBP: ";printEBP(HEBP);
		bool HEBPIsDistinct = true;
		/*if (EqualEBP(VEBPPrime, inverseEBP(VEBPPrime)))
		{
			if (!EqualEBP(HEBP, LargerEBP(HEBP, switchEBP(HEBP))))
				HEBPIsDistinct = false;
		}
		if (EqualEBP(VEBPPrime, switchEBP(VEBPPrime)))
		{
			if (!EqualEBP(HEBP, LargerEBP(HEBP, inverseEBP(HEBP))))
				HEBPIsDistinct = false;
		}
		if (EqualEBP(VEBPPrime, inverseEBP(switchEBP(VEBPPrime))))
		{
			if (!EqualEBP(HEBP, LargerEBP(HEBP, switchEBP(inverseEBP(HEBP)))))
				HEBPIsDistinct = false;
		}*/
		if((M == N) && (M / 2 == 1)  && (VENumb == (M*N - 1) / 2))
		{
			//cout << "check rotational" << endl;
			//check rotational symmetry
		}

		if (HEBPIsDistinct)
		{
			//cout << "end enumeration" << endl;
		}
		
	}
	else 
	{
		map<int, vector<vector<int>>> HEBPiTree;


		HEBPiTree = generateTreeForHEBPi(CCNumbMatrix[currentColumn], CCNumbMatrix[currentColumn+1]);
		printHEBPiTree(HEBPiTree);

		int size1Numb = HEBPiTree.size();
		int size2Numb = 0;
		for (map<int, vector<vector<int>>>::iterator it = HEBPiTree.begin(); it != HEBPiTree.end(); it++)
			size2Numb += it->second.size();

		int MinNumber = max(size1Numb, HENumb - N*(M - 1 - (currentColumn + 1)));
		int MaxNumber = min(size2Numb, HENumb - (M - 1 - (currentColumn + 1)));
		
		for (int HENumbi = MinNumber; HENumbi <= MaxNumber; HENumbi++)
		{
			vector<int> HEBPi;
			generateHEBPi(VENumb, HENumb, HENumbi, HENumbi, 0, currentColumn, CCNumbMatrix, size1Numb, size2Numb, HEBPiTree, HEBPi, HEBP);
		}
		
	}
}


void generateHEBPi(int VENumb, int HENumb, int HENumbi, int leftHENumbi, int indexInMapKey, int currentColumn, vector<vector<int>> CCNumbMatrix, int size1Numb, int size2Numb, map<int, vector<vector<int>>> HEBPiTree, vector<int> HEBPi, vector<vector<int>> HEBP)
{
	if (indexInMapKey > HEBPiTree.size()-1)
	{
		cout << "hebp"<<currentColumn<<": " << endl;
		if (HEBPi.size() != 1)
			sort(HEBPi.begin(), HEBPi.end());
		printEBPi(HEBPi);

		vector<int>::iterator minValue = min_element(CCNumbMatrix[currentColumn + 1].begin() + 1, CCNumbMatrix[currentColumn + 1].end());
		newCCNumb_iplus1(CCNumbMatrix[currentColumn], HEBPi, CCNumbMatrix[currentColumn+1] , *minValue);

		HENumb -= HENumbi;
		HEBP.push_back(HEBPi);
		
		distinctHEBPEnumeartion(currentColumn + 1, CCNumbMatrix, HENumb, VENumb, HEBP);
		//HEBP.pop_back();
		//end
	}
	else
	{
		map<int, vector<vector<int>>>::iterator iter = HEBPiTree.begin();
		advance(iter, indexInMapKey);
		
		vector<vector<int>> treeInEachCC = iter->second;
		int sizeOFEachCC = treeInEachCC.size();
		int minNumber = max(1, leftHENumbi - (size2Numb - sizeOFEachCC));
		int maxNumber = min(sizeOFEachCC, leftHENumbi - (size1Numb - 1));

		for (int oneBitsInEachCC = minNumber; oneBitsInEachCC <= maxNumber; oneBitsInEachCC++)
		{
			//comb
			vector<int> resultForCombinations;
			vector<vector<int>> combSetInEachCC;
			allCombinationsOfKInN(1, oneBitsInEachCC, sizeOFEachCC, resultForCombinations, combSetInEachCC);
			
			leftHENumbi -= oneBitsInEachCC;
			size2Numb -= sizeOFEachCC;
			size1Numb -= 1;
			//cout << leftHENumbi << " " << size2Numb << " " << size1Numb << endl;
			for (vector<vector<int>>::iterator comb = combSetInEachCC.begin(); comb != combSetInEachCC.end(); comb++)
			{		
				//cout << "comb: ";printEBPi(*comb);
				vector<vector<int>> CCCombInHEBPiSet;
				vector<int> CCCombInHEBPi;
				combinationOneBitForEachCCinHEBPTree(treeInEachCC, 0, *comb, CCCombInHEBPiSet, CCCombInHEBPi);
				//cout << "combSet: ";printEBP(CCCombInHEBPiSet);
				for (vector<vector<int>>::iterator eachCombInSet = CCCombInHEBPiSet.begin(); eachCombInSet != CCCombInHEBPiSet.end(); eachCombInSet++)
				{
					for (vector<int>::iterator it = eachCombInSet->begin(); it != eachCombInSet->end(); it++)
					{
						HEBPi.push_back(*it);
					}
					generateHEBPi(VENumb, HENumb, HENumbi, leftHENumbi, indexInMapKey + 1, currentColumn, CCNumbMatrix, size1Numb, size2Numb, HEBPiTree, HEBPi, HEBP);
					for (vector<int>::iterator it = eachCombInSet->begin(); it != eachCombInSet->end(); it++)
					{
						HEBPi.pop_back();
					}
				}	
			}
		}
	}
}

void newCCNumb_iplus1(vector<int> CCNumb_i, vector<int> HEBPi, vector<int> &CCNumb_iplus1, int minValue)
{
	
	for (vector<int>::iterator it = HEBPi.begin(); it != HEBPi.end(); it++)
	{
		int previousValue = CCNumb_iplus1[*it];
		if (previousValue >= minValue)
		{
			
			CCNumb_iplus1[*it] = CCNumb_i[*it];
			int currentValue = CCNumb_iplus1[*it];
	
			for (int nextIndex = *it + 1; nextIndex <= N; nextIndex++)
			{
				if (CCNumb_iplus1[nextIndex] == previousValue)
					CCNumb_iplus1[nextIndex] = currentValue;
				else
					break;
			}
			for (int nextIndex = *it - 1; nextIndex >= 1; nextIndex--)
			{
				if (CCNumb_iplus1[nextIndex] == previousValue)
					CCNumb_iplus1[nextIndex] = currentValue;
				else
					break;
			}
		}
	}
	
}


void combinationOneBitForEachCCinHEBPTree(vector<vector<int>> treeInEachCC, int indexOfEachGroupInCC, vector<int> comb, vector<vector<int>> &CCCombInHEBPiSet, vector<int> CCCombInHEBPi)
{
	if (indexOfEachGroupInCC > comb.size() - 1)
	{
		CCCombInHEBPiSet.push_back(CCCombInHEBPi);
	}
	else
	{
		int indexOfOneBitInCC = comb[indexOfEachGroupInCC] - 1;
		vector<int> resultForCombinations;
		vector<vector<int>> combInEachGroupInCCSet;
		allCombinationsOfKInN(1, 1, treeInEachCC[indexOfOneBitInCC].size(), resultForCombinations, combInEachGroupInCCSet);
		for (vector<vector<int>>::iterator eachComb = combInEachGroupInCCSet.begin(); eachComb != combInEachGroupInCCSet.end(); eachComb++)
		{
			int indexOFOneBitInHEBPi = treeInEachCC[indexOfOneBitInCC][eachComb[0][0] - 1];
			CCCombInHEBPi.push_back(indexOFOneBitInHEBPi);
			combinationOneBitForEachCCinHEBPTree(treeInEachCC, indexOfEachGroupInCC + 1, comb, CCCombInHEBPiSet, CCCombInHEBPi);
			CCCombInHEBPi.pop_back();
		}
	}
}

map<int, vector<vector<int>>> generateTreeForHEBPi(vector<int> CCNumb_i, vector<int> CCNumb_iplus1)
{
	map<int, vector<vector<int>>> resultTree;
	for (int i = 1; i < CCNumb_i.size(); i++)
	{
		bool Connected = true;
		bool sameCCNumb = false;
		
		for (int j = i; j >= 1; j--)
		{
			if (CCNumb_iplus1[j-1] != CCNumb_iplus1[j])
				Connected = false;
			if (CCNumb_i[i] == CCNumb_i[j - 1])
			{
				sameCCNumb = true;
				break;
			}
		}

		
		if (!sameCCNumb)
		{
			
			vector<vector<int>> newBranchOfRoot;
			vector<int> newBranchOfsameCCNumb;
			newBranchOfsameCCNumb.push_back(i);
			newBranchOfRoot.push_back(newBranchOfsameCCNumb);

			resultTree.insert(pair<int, vector<vector<int>>>(CCNumb_i[i], newBranchOfRoot));
		}
		else
		{
			if (Connected)
			{
				
				int lastIndexOfGrandChildNodeOfRoot = resultTree[CCNumb_i[i]].size()-1;
				resultTree[CCNumb_i[i]][lastIndexOfGrandChildNodeOfRoot].push_back(i);
			}
			else
			{
				vector<int> newBranchOfsameCCNumb;
				newBranchOfsameCCNumb.push_back(i);
				resultTree[CCNumb_i[i]].push_back(newBranchOfsameCCNumb);
			}
		}
	}

	return resultTree;
}



void printHEBPiTree(map<int, vector<vector<int>>> HEBPiTree)
{
	///print tree to see if tree is correct
	for (map<int, vector<vector<int>>>::iterator it = HEBPiTree.begin(); it != HEBPiTree.end(); it++)
	{
		cout << it->first << " --> ";
		for (vector<vector<int>>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			cout << " + ";
			for (vector<int>::iterator it3 = it2->begin(); it3 != it2->end(); it3++)
			{
				cout << "--> " << *it3 << endl;
			}

		}
	}
}