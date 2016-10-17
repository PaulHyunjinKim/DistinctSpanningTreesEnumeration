#include "stdafx.h"
#include "HEBPEnumeration.h"
#include "EBPOperations.h"

void HEBPEnumeration(vector<vector<int>> VEBP)
{
	//recieve message from VEBP enumeration
	printEBP(VEBP);
	//initial CC# with VEBP'i
	vector<int> CCNumb;
	vector<vector<int>> VEBPPrime;
	CCNumb.push_back(0); CCNumb.push_back(1); CCNumb.push_back(1); CCNumb.push_back(3); CCNumb.push_back(1);//1131

	distinctHEBPEnumeartion(CCNumb, VEBPPrime);
	getchar();
}

void distinctHEBPEnumeartion(vector<int> CCNumb, vector<vector<int>> VEBPPrime)//enumerate all distinct HEBP based on VEBP
{
	map<int, vector<vector<int>>> HEBPiTree;
	vector<int> VEBPPrime_iplus1;

	VEBPPrime_iplus1.push_back(0); VEBPPrime_iplus1.push_back(1); VEBPPrime_iplus1.push_back(0); VEBPPrime_iplus1.push_back(1); //101

	HEBPiTree = generateTreeForHEBPi(CCNumb, VEBPPrime_iplus1);

	///print to see if tree is correct
	for (map<int, vector<vector<int>>>::iterator it = HEBPiTree.begin(); it != HEBPiTree.end(); it++)
	{
		cout << it->first << " --> ";
		for (vector<vector<int>>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{	
			cout << " + ";
			for (vector<int>::iterator it3 = it2->begin(); it3 != it2->end(); it3++)
			{
				cout <<"--> "<< *it3 << endl;
			}
			
		}
	}
}

map<int, vector<vector<int>>> generateTreeForHEBPi(vector<int> CCNumb, vector<int> VEBPPrime_iplus1)
{
	map<int, vector<vector<int>>> resultTree;
	for (int i = 1; i < CCNumb.size(); i++)
	{
		bool Connected = true;
		bool sameCCNumb = false;
		
		for (int j = i; j >= 1; j--)
		{
			if (VEBPPrime_iplus1[j-1] == 0)
				Connected = false;
			if (CCNumb[i] == CCNumb[j - 1])
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

			resultTree.insert(pair<int, vector<vector<int>>>(CCNumb[i], newBranchOfRoot));
		}
		else
		{
			if (Connected)
			{
				
				int lastIndexOfGrandChildNodeOfRoot = resultTree[CCNumb[i]].size()-1;
				resultTree[CCNumb[i]][lastIndexOfGrandChildNodeOfRoot].push_back(i);
			}
			else
			{
				vector<int> newBranchOfsameCCNumb;
				newBranchOfsameCCNumb.push_back(i);
				resultTree[CCNumb[i]].push_back(newBranchOfsameCCNumb);
			}
		}
	}

	return resultTree;
}