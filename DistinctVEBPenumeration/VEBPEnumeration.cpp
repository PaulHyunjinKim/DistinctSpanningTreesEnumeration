#include "stdafx.h"
#include "VEBPEnumeration.h"
#include "HEBPEnumeration.h"
#include "EBPOperations.h"
#include <ctime>

void VEBPEnumeartion(ofstream &myFile, double &numberOfOutputs, map<int, map<int, vector<vector<int>>>> &HEBPiMap)
{
	int OneBitsNumber = 0;
	int startNumberOfBitsInVEBP = ceilf((float)(M*N - 1) / 2);
	if (M != N)
		startNumberOfBitsInVEBP = N - 1;
		
	map<int, vector<vector<int>>> VEBPiMap;
	//vector<vector<vector<int>>> VEBPiMap;
		
	ifstream readFile;
	char fileName[20];
	sprintf_s(fileName, sizeof(fileName), "VEBPi_%d.bin", N);
	readFile.open(fileName, ios::in | ios::binary);
	VEBPiMap = mapFromBinaryFile(readFile);
	readFile.close();
	
	ifstream oneBitNumberReadFile;
	char newfileName[100];
	sprintf_s(newfileName, sizeof(newfileName), "VEBPBitNumberOnEachSection_%d.bin", N);
	oneBitNumberReadFile.open(newfileName, ios::in | ios::binary);
	oneBitNumberReadFile.seekg(0, ios::end);
	int length = oneBitNumberReadFile.tellg();
	oneBitNumberReadFile.seekg(0, ios::beg);
	while (length != oneBitNumberReadFile.tellg())
	{
		
		vector<int> result;
		int tempInt = 0;
		for (int i = 0; i < N - 1; i++)
		{
			oneBitNumberReadFile.read(reinterpret_cast<char*>(&tempInt), sizeof(int));
			
			result.push_back(tempInt);
		}
		
		bool equalSwitch = false;
		int tempEqualInt = 0;
		oneBitNumberReadFile.read(reinterpret_cast<char*>(&tempEqualInt), sizeof(int));
		
		if (tempEqualInt == 1) equalSwitch = true;
		
		vector<vector<int>> VEBP;
		distinctVEBPEnumeration(result, myFile, equalSwitch, VEBPiMap, 0, VEBP, HEBPiMap);
		
	}


	
	//for (OneBitsNumber = startNumberOfBitsInVEBP; OneBitsNumber <= N*N - N; OneBitsNumber++)//enumerate VEBP based on # 1bits on VEBP
	////for (OneBitsNumber = N-1; OneBitsNumber <= N*N - N; OneBitsNumber++)//enumerate VEBP based on # 1bits on VEBP
	//{
	//	//OneBitsNumber = 30;
	//	vector<int> result;
	//	//send message to VEBPEnumeration...//
	//	//myFile << "OneBitsNumber: "<< OneBitsNumber << endl;
	//	SetOneBitNumberOnEachSectionVEBP(OneBitsNumber, 0, result, 0, myFile, numberOfOutputs, VEBPiMap, HEBPiMap);
	//}
}

map<int, vector<vector<int>>> mapFromBinaryFile(ifstream &readFile)
{
	map<int, vector<vector<int>>> VEBPiMap;
	readFile.seekg(0, ios::end);
	int length = readFile.tellg();
	readFile.seekg(0, ios::beg);
	//cout << "length"<<length << endl;
	int readSize = 0;
	vector<int> temp;
	while (length != readFile.tellg())
	{
		readFile.read(reinterpret_cast<char*>(&readSize), sizeof(int));
		temp.resize(readSize);
		readFile.read(reinterpret_cast<char*>(temp.data()), readSize * sizeof(int));

		if (VEBPiMap.end() == VEBPiMap.find(readSize))
		{

			vector<vector<int>> VEBPiSet;
			VEBPiSet.push_back(temp);
			VEBPiMap.insert(pair<int, vector<vector<int>>>(readSize, VEBPiSet));
		}
		else
		{
			VEBPiMap[readSize].push_back(temp);
		}
	}
	

	return VEBPiMap;
}

vector<vector<vector<int>>> vectorFromBinaryFile(ifstream &readFile)
{
	vector<vector<vector<int>>> VEBPiMap(M+1);
	readFile.seekg(0, ios::end);
	int length = readFile.tellg();
	readFile.seekg(0, ios::beg);
	//cout << "length"<<length << endl;
	int readSize = 0;
	vector<int> temp;
	while (length != readFile.tellg())
	{
		readFile.read(reinterpret_cast<char*>(&readSize), sizeof(int));
		temp.resize(readSize);
		readFile.read(reinterpret_cast<char*>(temp.data()), readSize * sizeof(int));

		//cout << readSize << endl;
		//cout << VEBPiMap[readSize].size() << endl;
		//if (VEBPiMap.end() == VEBPiMap.find(readSize))
		VEBPiMap[readSize].push_back(temp);
		//cout << readSize << endl;
	}
	readFile.close();

	return VEBPiMap;
}

//void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentRow, vector<int> result, int LastOneBitsNumber, ofstream &myFile, double &numberOfOutputs, map<int, vector<vector<int>>> VEBPiMap)
void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentRow, vector<int> &result, int LastOneBitsNumber, ofstream &myFile, double &numberOfOutputs, map<int, vector<vector<int>>> &VEBPiMap, map<int, map<int, vector<vector<int>>>> &HEBPiMap)
{
	currentRow += 1;
	LeftOneBitsNumber -= LastOneBitsNumber;

	if (currentRow > N - 1)
	{
		bool equalSwitch = true;
		if (checkIFDistinctBitsComb(result, equalSwitch))
		{

			//clock_t begin = clock();
			//distinctVEBPEnumeration(result, myFile, numberOfOutputs, equalSwitch);
			
			/*for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
				myFile.write(reinterpret_cast<char*>(&(*it)), sizeof(int));
			int equalInt = 0;
			if (equalSwitch) equalInt = 1;
				myFile.write(reinterpret_cast<char*>(&equalInt), sizeof(int));*/
			
			vector<vector<int>> VEBP;
			
			distinctVEBPEnumeration(result, myFile, equalSwitch, VEBPiMap, 0, VEBP, HEBPiMap);
			
			
			//clock_t begin = clock();
			/*clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "elapsed time: " << elapsed_secs << endl;*/
		}
			
	}
	else
	{
		int MinNumber = max(1, LeftOneBitsNumber - M*(N - 1 - currentRow));
		int MaxNumber = min(M, LeftOneBitsNumber - (N - 1 - currentRow));
		for (LastOneBitsNumber = MinNumber; LastOneBitsNumber <= MaxNumber; LastOneBitsNumber++)
		{
			result.push_back(LastOneBitsNumber);
			SetOneBitNumberOnEachSectionVEBP( LeftOneBitsNumber, currentRow, result, LastOneBitsNumber, myFile, numberOfOutputs, VEBPiMap, HEBPiMap);
			result.pop_back();
		}
	}
}

bool checkIFDistinctBitsComb(vector<int> &result, bool &equalSwitch)
{
	bool checkedResult = true;
	
	for (int i = 0; i < (M - 1)/2; i++)
	{
		int bitNumb1 = result[i];
		int bitNumb2 = result[M - 2 - i];
		if (bitNumb1 != bitNumb2)
		{
			equalSwitch = false;
			if (bitNumb1 < bitNumb2)
				checkedResult = false;
			break;
		}
	}


	return checkedResult;
}

void distinctVEBPEnumeration(vector<int> &result, ofstream &myFile, double &numberOfOutputs, bool equalSwitch)
{
	//cout << "result " << endl;
	//myFile << "result " << endl;
	vector<vector<vector<int>>> VEBPSet;
	///combinatorics based on #1bits in each section of VEBP///
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
	{		
		int K = *it;
		vector<int> resultForCombinations;
		vector<vector<int>> VEBPi;
		//myFile << K << " ";
		allCombinationsOfKInN(1, K, M, resultForCombinations, VEBPi);
		
		VEBPSet.push_back(VEBPi);
	}
	//cout << endl;
	//myFile << endl;
	vector<vector<int>> VEBP;
	completeEachVEBP(0, VEBPSet, VEBP, myFile, numberOfOutputs, equalSwitch);
	//cout << endl;
	//myFile << endl;
}

//void distinctVEBPEnumeration(vector<int> result, ofstream &myFile, double &numberOfOutputs, bool equalSwitch, map<int, vector<vector<int>>> VEBPiMap, int numbSection, vector<vector<int>> VEBP, vector<int> VEBPi)
//void distinctVEBPEnumeration(vector<int> &result, ofstream &myFile, bool equalSwitch, vector<vector<vector<int>>> &VEBPiMap, int numbSection, vector<vector<int>> &VEBP)
void distinctVEBPEnumeration(vector<int> &result, ofstream &myFile, bool equalSwitch, map<int, vector<vector<int>>> &VEBPiMap, int numbSection, vector<vector<int>> &VEBP, map<int, map<int, vector<vector<int>>>> &HEBPiMap)
{
	//if(numbSection >=0 )VEBP.push_back(VEBPi);
	//numbSection++;
	
	if (numbSection == N-1)
	{
		if (!equalSwitch)
		{
			if (EqualEBP(VEBP, LargerEBP(VEBP, inverseEBP(VEBP, M), N), N))
			{
				//myFile << numberOfOutputs << endl;
				//numberOfOutputs++;
				printEBP(VEBP);
				//writeEBP(VEBP, myFile);
				
				//HEBPEnumeration(VEBP, myFile, HEBPiMap);
			}
		}
		else
		{
			
			if (checkIfDistinct(VEBP))
			{
				
				//myFile << numberOfOutputs << endl;
				//numberOfOutputs++;
				//cout << "number of outputs from VEBP " << ii << endl;
				printEBP(VEBP);
				//writeEBP(VEBP, myFile);
				//send message to HEBP enumeration..//
				
				//HEBPEnumeration(VEBP, myFile, HEBPiMap);
				//////////
			}
		}
	}
	else
	{
		
		int mapIndex = result[numbSection];
		//cout << "mapIndex " << mapIndex << endl;
		
		for (vector<vector<int>>::iterator it = VEBPiMap[mapIndex].begin(); it != VEBPiMap[mapIndex].end(); it++)
		//for(int i=0; i<VEBPiMap[mapIndex].size(); i++)
		{

			//printEBPi(*it);
			VEBP.push_back(*it);
			distinctVEBPEnumeration(result, myFile, equalSwitch, VEBPiMap, numbSection + 1, VEBP, HEBPiMap);
			VEBP.pop_back();
		}
	}
}

void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> &VEBPSet, vector<vector<int>> &VEBP, ofstream &myFile, double &numberOfOutputs, bool equalSwitch)
{
	if (sectionNumber == N - 1)
	{
		if (!equalSwitch)
		{
			if (EqualEBP(VEBP, LargerEBP(VEBP, inverseEBP(VEBP, M),N),N))
			{
				//myFile << numberOfOutputs << endl;
				//numberOfOutputs++;
				//printEBP(VEBP);
				//writeEBP(VEBP, myFile);
				//HEBPEnumeration(VEBP, myFile);
			}		
		}
		else
		{
			if (checkIfDistinct(VEBP))
			{
				//myFile << numberOfOutputs << endl;
				//numberOfOutputs++;
				//cout << "number of outputs from VEBP " << ii << endl;
				//printEBP(VEBP);
				//writeEBP(VEBP, myFile);
				//send message to HEBP enumeration..//
				//HEBPEnumeration(VEBP, myFile);
				//////////
			}
		}
	}
	else
	{
		for (vector<vector<int>>::iterator it = VEBPSet[sectionNumber].begin(); it!= VEBPSet[sectionNumber].end();it++ )
		{

			VEBP.push_back(*it);
			
			
			completeEachVEBP(sectionNumber + 1, VEBPSet, VEBP, myFile, numberOfOutputs, equalSwitch);
			
			//getchar();
			VEBP.pop_back();
		}
	}
}

