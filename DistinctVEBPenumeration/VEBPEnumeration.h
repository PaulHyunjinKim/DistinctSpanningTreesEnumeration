#pragma once
void VEBPEnumeartion(ofstream &myFile, double &numberOfOutputs, map<int, map<int, vector<vector<int>>>> &HEBPiMap);
//void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentColumn, vector<int> result, int LastOneBitsNumber, ofstream &myFile, double &numberOfOutputs, map<int, vector<vector<int>>> VEBPiMap);
void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentColumn, vector<int> &result, int LastOneBitsNumber, ofstream &myFile, double &numberOfOutputs, map<int, vector<vector<int>>> &VEBPiMap, map<int, map<int, vector<vector<int>>>> &HEBPiMap);
void distinctVEBPEnumeration(vector<int> &result, ofstream &myFile, double &numberOfOutputs, bool equalSwitch);
//void distinctVEBPEnumeration(vector<int> result, ofstream &myFile, double &numberOfOutputs, bool equalSwitch, map<int, vector<vector<int>>> VEBPiMap, int numbSection, vector<vector<int>> VEBP, vector<int> VEBPi);
void distinctVEBPEnumeration(vector<int> &result, ofstream &myFile, bool equalSwitch, map<int, vector<vector<int>>> &VEBPiMap, int numbSection, vector<vector<int>> &VEBP, map<int, map<int, vector<vector<int>>>> &HEBPiMap);

void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> &VEBPSet, vector<vector<int>> &VEBP, ofstream &myFile, double &numberOfOutputs, bool equalSwitch);
bool checkIFDistinctBitsComb(vector<int> &result, bool &equalSwitch);
map<int, vector<vector<int>>> mapFromBinaryFile(ifstream &readFile);
vector<vector<vector<int>>> vectorFromBinaryFile(ifstream &readFile);