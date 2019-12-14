#include <iostream>
#include "Runner.h"

using namespace std;

int main(int argc, char** argv)
{
	//Runs main
	Runner r;
	if (argc == 2)
	{
		//sets fie for input
		if (r.setInputFile(argv[1]))
		{
			r.scanFile();
		}
		//catches for invalid entries
		else
		{
			cout << "\n Invalid File";
		}
	}
	//catches for too many inputs
	else
	{
		cout << "\n Only one file will be accepted at a time please";
	}
	return 0;
}