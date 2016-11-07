#include "stdafx.h"
#include "VEBPEnumeration.h"
#include <ctime>
int main()
{
	clock_t begin = clock();
	
	ofstream EBPFile;
	EBPFile.open("EBPFile.txt");

	double numberOfOuputs = 14;

	VEBPEnumeartion(EBPFile, numberOfOuputs);
	EBPFile.close();
	cout << "Finished...hit Enter to exit.." << endl;
	

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "elapsed time: " << elapsed_secs << endl;
	//cout << "number of outputs from VEBP " << ii << endl;
	getchar();
	return 0;
}
