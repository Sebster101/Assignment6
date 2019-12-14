#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Runner.h"

using namespace std;
//constructor
Runner::Runner(){};
//Decon
Runner::~Runner()
{
	delete [] bubbleSortArray;
	delete [] insertSortArray;
	delete [] selectionSortArray;
	delete [] gnomeSortArray;
}
//Opens file for use
bool Runner::setInputFile(string name)
{
	ifstream fileTest;
	fileTest.open(name.c_str());

	if (fileTest.is_open())
	{
		cout << "\nFile " << name.c_str() << " was loaded." << endl;
		fileTest.close();
		fileName = name;
		return true;
	}
	else
	{
		return false;
	}
}
//Scans file into arrays
void Runner::scanFile()
{
	ifstream inputFile;
	inputFile.open(fileName.c_str());
	string numElementsString;
	string line;
	double value;
	int lineNum = 1;

	getline(inputFile, numElementsString);
	try
	{
		numElements = stoi(numElementsString);
	}
	catch (exception e)
	{
		cout << "\nError reading file" << lineNum << "\n" << endl;
		return;
	}

	bubbleSortArray = new double[numElements];
	insertSortArray = new double[numElements];
	selectionSortArray = new double[numElements];
	gnomeSortArray = new double[numElements];

	for (int i = 0; i< numElements; i++)
	{
		lineNum++;

		getline(inputFile, line);

		try
		{
			value = stod(line);
		}
		catch (exception e)
		{
			cout << "\nError Reading File" << lineNum << "\n" << endl;
			return;
		}

		bubbleSortArray[i] = value;
		insertSortArray[i] = value;
		selectionSortArray[i] = value;
		gnomeSortArray[i] = value;

	}
	inputFile.close();
	sortAll();
}
//All sorts located below
void Runner::bubbleSort(double array[])
{
	for(int i = 0; i < numElements; ++i)
	{
		int temp = 0;
		for (int j = i; j < numElements-1; ++j)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}
void Runner::insertSort(double array[])
{
	for(int j = 1; j < numElements; ++j)
	{
		double temp = array[j];
		int k = j;
		while (k>0 && array[k-1] >= temp)
		{
			array[k] = array[k-1];
			--k;
		}
		array[k] = temp;
	}
}
void Runner::selectionSort(double array[], int n)
{
	int i;
	int j;
	int minIndex;
	int temp;
	for(i = 0; i < n-1;i++)
	{
		minIndex = i;
		for(j = i + 1; j < n; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		if(minIndex != i)
		{
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}

void Runner::gnomeSort(double array[])
{
	int i = 0;

	while (i < numElements)
	{
		if(i == 0 || array[i-1] <= array[i])
		{
			i++;
		}
		else
		{
			double temp = array[i];
			array[i] = array[i-1];
			array[--i] = temp;
		}
	}
}
//times the sort functions
void Runner::sortAll()
{
	clock_t timeStart;
	clock_t timeEnd;
	float timeTotal;

	cout << "\n Sorting \n";

	timeStart = clock();
	bubbleSort(bubbleSortArray);
	timeEnd = clock();
	timeTotal = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
	cout << "\nBubbleSort: " << timeTotal << " MS Elapsed" << " For " << numElements << " Numbers";
	

	timeStart = clock();
	insertSort(insertSortArray);
	timeEnd = clock();
	timeTotal = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
	cout << "\nInsertSort: " << timeTotal << " MS Elapsed" << " For " << numElements << " Numbers";
	

	timeStart = clock();
	selectionSort(selectionSortArray, numElements-1);
	timeEnd = clock();
	timeTotal = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
	cout << "\nSelectionSort: " << timeTotal << " MS Elapsed" << " For " << numElements << " Numbers";
	
	timeStart = clock();
	gnomeSort(gnomeSortArray);
	timeEnd = clock();
	timeTotal = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
	cout << "\nGnomeSort: " << timeTotal << " MS Elapsed" << " For " << numElements << " Numbers" << endl;

}