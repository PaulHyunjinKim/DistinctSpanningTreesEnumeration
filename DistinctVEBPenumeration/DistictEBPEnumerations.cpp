#include "stdafx.h"
#include "VEBPEnumeration.h"
#include "HEBPEnumeration.h"
#include <ctime>

int main()
{

	
	
	clock_t begin = clock();

	map<int, map<int, vector<vector<int>>>> HEBPiMap;
	ifstream readFile;
	char fileName[100];
	sprintf_s(fileName, sizeof(fileName), "newHEBPiSet_%d.bin", N);
	readFile.open(fileName, ios::in | ios::binary);
	HEBPiMap = hebpMapFromBinaryFile(readFile);
	readFile.close();
	//getchar();
	
	ofstream EBPFile;
	//EBPFile.open("EBPFile.txt");
	char newfileName[100];
	//sprintf_s(newfileName, sizeof(newfileName), "VEBPBitNumberOnEachSection_%d.bin", N);
	sprintf_s(newfileName, sizeof(newfileName), "VEBPSet_%d.bin", N);
	EBPFile.open(newfileName, ios::out | ios::binary);

	double numberOfOuputs = 14;


	VEBPEnumeartion(EBPFile, numberOfOuputs, HEBPiMap);
	
	EBPFile.close();
	cout << "Finished...hit Enter to exit.." << endl;
	
	//**
	//ifstream VEBPreadFile;
	//VEBPreadFile.open(newfileName, ios::in | ios::binary);
	//VEBPreadFile.seekg(0, ios::end);

	//int length = VEBPreadFile.tellg();
	//VEBPreadFile.seekg(0, ios::beg);
	////cout << "length"<<length << endl;
	//unsigned long VEInt = 0;
	//
	//
	//while (length != VEBPreadFile.tellg())
	//{
	//	VEBPreadFile.read(reinterpret_cast<char*>(&VEInt), sizeof(unsigned long));
	//	bitset<M*(N - 1)>VEBPBits(VEInt);
	//	cout << VEBPBits << endl;
	//	cout << VEBPBits.size() << endl;
	//}



	
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "elapsed time: " << elapsed_secs << endl;
	//cout << "number of outputs from VEBP " << ii << endl;
	getchar();
	return 0;
}
