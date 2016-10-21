#pragma once
void VEBPEnumeartion(ofstream &myFile);
void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentColumn, vector<int> result, int LastOneBitsNumber, ofstream &myFile);
void distinctVEBPEnumeration(vector<int> result, ofstream &myFile);
void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> VEBPSet, vector<vector<int>> VEBP, ofstream &myFile);