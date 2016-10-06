#pragma once

void SetOneBitNumberOnEachSectionVEBP(int LeftOneBitsNumber, int currentColumn, vector<int> result, int LastOneBitsNumber);
void distinctVEBPEnumeration(vector<int> result);
void allCombinationsOfKInN(int startIndex, int leftElements, vector<int> result, vector<vector<int>> &VEBP);
void completeEachVEBP(int sectionNumber, vector<vector<vector<int>>> VEBPSet, vector<vector<int>> VEBP);