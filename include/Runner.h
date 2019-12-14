using namespace std;

class Runner
{
	private:
	//for file
	string fileName;
	int numElements;
	//arrays for sorts
	double *bubbleSortArray;
	double *insertSortArray;
	double *selectionSortArray;
	double *gnomeSortArray;

	public:
		Runner();
		~Runner();
		//fileInput
		bool setInputFile(string name);
		void scanFile();
		//sort methods
		void bubbleSort(double array[]);
		void insertSort(double array[]);
		void selectionSort(double array[], int n);
		void gnomeSort(double array[]);

		void sortAll();

};