/*        Author: Jeremiah Gallagher
 *        Advanced C++
 *        Monday 5:30 pm
 *        Spring 2017
 *
 *Summary: Simple Sorts- This Program asks the user for a file containing a list of unsorted integers.
 *         It stores the ints inside an a.  It displays the a then sorts it with the exchange sort
 *         algorithm. It diplays the sorted a, along with comparison and exchange counts.  It then
 *         uses the exchange sort again, followed by another display of the results.
 *          Finally, it reverses and resorts the array and displays results. After the exchange sort
 *         demo, it continues with selection sort and insertion sorts, displaying the same sequence of results.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int comparisonCounter;
int exchangeCounter;

void displayArray(const int * a, int s);
bool inOrder(int a, int b);
void exchange(int & a, int & b);
void exchangeSort(int * a, int s);
void selectionSort(int * a, int s);
void insertionSort(int * a, int s);
void reverse(int * a, int s);
void copyArray(int* a, int* b, int size);

int main(int argc, char * argv){

	string fileName;

	if(2 == argc){
		fileName = argv[1];
	}
	else {
	cout << "Welcome to Simple Sorting Demo!" << endl;
	cout << "Please enter a file name: " << endl;
	}
	getline(cin, fileName);

	ifstream fin;
	fin.open(fileName);

	if(!fin){
		cout << "There was a problem accessing the file. Please try again." << endl;
		exit(1);
	}

	int s;
	fin >> s; //read first int from file as size for a
	int * a = new int[s];
	for(int i = 0; i < s; ++i){
		fin >> a[i];
	}
		//Allocate memory for and make copies of original array.
	int * b = new int[s];
	copyArray(a, b, s);
	

	/********Exchange Sort ***************/
	cout << "Exchange Sort" << endl;
	displayArray(b,s);

	exchangeSort(b,s);
	displayArray(b,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

	exchangeSort(b,s);
	displayArray(b,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

	reverse(b,s);
	displayArray(b,s);

	exchangeSort(b,s);
	displayArray(b,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

	delete(b);
	/********Selection Sort ***************/
	cout << "Selection Sort" << endl << endl;

	int * c = new int[s];
	copyArray(a, c, s);

	displayArray(c,s);

	selectionSort(c,s);
	displayArray(c,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

	selectionSort(c,s);
	displayArray(c,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

	reverse(c,s);
	displayArray(c,s);

	selectionSort(c,s);
	displayArray(c,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

  delete(c);
/********Insertion Sort ***************/
	cout << "Insertion Sort" << endl << endl;

	int * d = new int[s];
	copyArray(a, d, s);

	displayArray(d,s);

	insertionSort(d,s);
	displayArray(d,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

	insertionSort(d,s);
	displayArray(d,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl;

	comparisonCounter = 0;//reset counters
	exchangeCounter = 0;

	reverse(d,s);
	displayArray(d,s);

	insertionSort(d,s);
	displayArray(d,s);

	cout << "Comparisons " << comparisonCounter << endl;
	cout << "Exchanges " << exchangeCounter << endl;



	return 0;
}

//function to display the a
void displayArray(const int * a, int s){
	if (s <= 200){
		for (int i = 0; i < s; ++i){
			if (i % 10 == 0){
				cout << endl;
			}
			cout << setw(7) << a[i];
		}
		cout << endl;
		cout << endl;
	}
	else{
		for (int i = 0; i < 100; ++i){
			if (i % 10 == 0){
				cout << endl;
			}
			cout << setw(7) << a[i];
		}
		cout << endl;
		cout << endl;
		for ( int i = s -100; i < s; ++i){
			if(i % 10 == 0){
				cout << endl;
			}
			cout << setw(7) << a[i];
		}
		cout << endl;
		cout << endl;
	}
}

//Exchange Sort
void exchangeSort(int * a, int s){
	for(int k = 1; k < s; ++k){
		for(int i = 0; i < s-k; ++i){
			if(!inOrder(a[i], a[i + 1])){
				exchange(a[i], a[i+1]);
			}
		}
	}
}
///Selection Sort algorithm, referenced from algolist.com
void selectionSort(int *a, int s){
	int i, j, minIndex, tmp;
	for (i = 0; i < s - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < s; j++){
			if (a[j] < a[minIndex]){
			minIndex = j;
			++comparisonCounter;
			}
			if (minIndex != i) {
			tmp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = tmp;
			++exchangeCounter;
			}
		}
	}
}

//Insertion Sort algorithm. Referenced from discussion on cplusplus.com
void insertionSort(int *a, int s){
    int temp;
    int loc;
    int i;

    for (i=1; i<s; i++){
        if (a[i] < a[i-1]){
            loc = i;
            temp = a[i];
			++comparisonCounter;
            do{
                a[loc] = a[loc-1];
                loc--;
            }
            while(loc>0 && a[loc-1]>temp);

            a[loc] = temp;
			++exchangeCounter;
        }
    }
}



//Function to compare 2 values
bool inOrder(int a, int b){
	++ comparisonCounter;
	return a <= b;
}
//Function to swap two values
void exchange(int & a, int & b){
	++ exchangeCounter;
	int t = a;
	a = b;
	b = t;

}
//Function to reverse elements
void reverse(int * a, int s){
   int temp;
   for(int i = 0; i < s/2; ++i){
      temp = a[s-i-1];
      a[s-i-1] = a[i];
      a[i] = temp;
    }
}

//Copy contents of one array to another
void copyArray(int* a, int* b, int size){
	for (int i = 0; i < size; i++){
		b[i] = a[i];
	}
}
