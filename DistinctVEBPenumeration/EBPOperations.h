#pragma once
bool checkIfDistinct(vector<vector<int>> EBP);
bool checkIfDistinctHEBP(vector<vector<int>> VEBP, vector<vector<int>> HEBP);
bool EqualEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2, int numbSection);
bool checkRotationalSymmetryOfHEBP(vector<vector<int>> VEBP, vector<vector<int>> HEBP);
vector<vector<int>> inverseEBP(vector<vector<int>> EBP, int numbBins);
vector<vector<int>> switchEBP(vector<vector<int>> EBP, int numbSection);
vector<vector<int>> LargerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2, int numbSection);
vector<vector<int>> SmallerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2, int numbSection);
vector<vector<int>> rotateHEBP(vector<vector<int>> HEBP);
vector<vector<int>> rotateVEBP(vector<vector<int>> VEBP);
void writeEBP(vector<vector<int>> EBP, ofstream &myfile);
void printEBP(vector<vector<int>> EBP);
void printEBPi(vector<int> EBPi);
void allCombinationsOfKInN(int startIndex, int leftElements, int n, vector<int> result, vector<vector<int>> &EBP);
vector<int> decimalToBinary(int decimal);
vector<int> decimalToNnary(int decimal);

