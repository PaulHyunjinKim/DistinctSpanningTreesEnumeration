#pragma once

void HEBPEnumeration(vector<vector<int>> VEBP);
void distinctHEBPEnumeartion(int currentColumn, vector<vector<int>> CCNumbMatrix, int HENumb, int VENumb, vector<vector<int>> HEBP);
map<int, vector<vector<int>>> generateTreeForHEBPi(vector<int> CCNumb, vector<int> VEBPPrime_iplus1);
void VEBPPrimeAndVENumbFromVEBP(vector<vector<int>> VEBP, vector<vector<int>> &VEBPPrime, int &VENumb);
void printHEBPiTree(map<int, vector<vector<int>>> HEBPiTree);
void generateHEBPi(int VENumb, int HENumb, int HENumbi, int leftHENumbi, int indexInMapKey, int currentColumn, vector<vector<int>> CCNumbMatrix, int size1Numb, int size2Numb, map<int, vector<vector<int>>> HEBPiTree, vector<int> HEBPi, vector<vector<int>> HEBP);
void combinationOneBitForEachCCinHEBPTree(vector<vector<int>> treeInEachCC, int indexOfEachGroupInCC, vector<int> comb, vector<vector<int>> &CCCombInHEBPiSet, vector<int> CCCombInHEBPi);
void CCNumbMatFromVEBPPrime(vector<vector<int>> &CCNumbMatrix, vector<vector<int>> VEBPPrime);
void newCCNumb_iplus1(vector<int> CCNumb_i, vector<int> HEBPi, vector<int> &CCNumb_iplus1, int minValue);