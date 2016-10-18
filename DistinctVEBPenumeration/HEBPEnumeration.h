#pragma once

void HEBPEnumeration(vector<vector<int>> VEBP);
void distinctHEBPEnumeartion(int currentColumn, vector<int> CCNumb, vector<vector<int>> VEBPPrime, int HENumb);
map<int, vector<vector<int>>> generateTreeForHEBPi(vector<int> CCNumb, vector<int> VEBPPrime_iplus1);
void VEBPPrimeAndVENumbFromVEBP(vector<vector<int>> VEBP, vector<vector<int>> &VEBPPrime, int &VENumb);
void printHEBPiTree(map<int, vector<vector<int>>> HEBPiTree);
void generateHEBPi(int HENumbi, int leftHENumbi, int currentRow, int currentColumn, vector<int> CCNumb, vector<vector<int>> VEBPPrime, int size1Numb, int size2Numb, map<int, vector<vector<int>>> HEBPiTree);