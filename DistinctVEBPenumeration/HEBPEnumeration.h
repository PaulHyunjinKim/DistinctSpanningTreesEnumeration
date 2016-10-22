#pragma once

void HEBPEnumeration(vector<vector<int>> VEBP, ofstream &myFile);
void distinctHEBPEnumeartion(int currentColumn, vector<vector<int>> CCNumbMatrix,vector<int> maxHEi, vector<int> minHEi, int leftMaxHEi, int leftMinHEi, int HENumb, int VENumb, vector<vector<int>> HEBP, vector<vector<int>> VEBP, ofstream &myFile);
map<int, vector<vector<int>>> generateTreeForHEBPi(vector<int> CCNumb, vector<int> VEBPPrime_iplus1);
void VEBPPrimeAndVENumbFromVEBP(vector<vector<int>> VEBP, vector<vector<int>> &VEBPPrime, int &VENumb);
void printHEBPiTree(map<int, vector<vector<int>>> HEBPiTree);
void generateHEBPi(vector<int> maxHEi, vector<int> minHEi, int leftMaxHEi, int leftMinHEi, int VENumb, int HENumb, int HENumbi, int leftHENumbi, int indexInMapKey, int currentColumn, vector<vector<int>> CCNumbMatrix, int size1Numb, int size2Numb, map<int, vector<vector<int>>> HEBPiTree, vector<int> HEBPi, vector<vector<int>> HEBP, vector<vector<int>> VEBP, ofstream &myFile);
void combinationOneBitForEachCCinHEBPTree(vector<vector<int>> treeInEachCC, int indexOfEachGroupInCC, vector<int> comb, vector<vector<int>> &CCCombInHEBPiSet, vector<int> CCCombInHEBPi);
void CCNumbMatFromVEBPPrime(vector<vector<int>> &CCNumbMatrix, vector<vector<int>> VEBPPrime);
bool newCCNumb_iplus1(int currentColumn, vector<vector<int>> &CCNumbMatrix, vector<int> HEBPi);
void initCCNumbTree(map<int, vector<int>> &CCNumbTree, vector<vector<int>> CCNumbMatrix, int currentColumn);
void maxMinHeiFromVEBPPrime(vector<vector<int>> VEBPPrime, vector<int> &maxHEi, vector<int> &minHEi);
