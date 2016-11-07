#pragma once
void VEBPEnumeartion(ofstream &myFile, double &numberOfOutputs);
void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentColumn, vector<int> result, int LastOneBitsNumber, ofstream &myFile, double &numberOfOutputs);
void distinctVEBPEnumeration(vector<int> result, ofstream &myFile, double &numberOfOutputs, bool equalSwitch);
void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> VEBPSet, vector<vector<int>> VEBP, ofstream &myFile, double &numberOfOutputs, bool equalSwitch);
bool checkIFDistinctBitsComb(vector<int> result, bool &equalSwitch);