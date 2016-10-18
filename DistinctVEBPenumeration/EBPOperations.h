#pragma once
bool checkIfDistinct(vector<vector<int>> EBP);
bool EqualEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2);
vector<vector<int>> inverseEBP(vector<vector<int>> EBP);
vector<vector<int>> switchEBP(vector<vector<int>> EBP);
vector<vector<int>> LargerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2);
vector<vector<int>> SmallerEBP(vector<vector<int>> EBP1, vector<vector<int>> EBP2);
void printEBP(vector<vector<int>> EBP);
void printEBPi(vector<int> EBPi);
void allCombinationsOfKInN(int startIndex, int leftElements, int n, vector<int> result, vector<vector<int>> &EBP);

