//Jeremiah Gallagher
//Advanced C++
//Spring 2017, Monday 5:30 pm
//Searching and sorting demo

#include <iostream>
#include <iomanip>
using namespace std;

int comparisonCounter;
int exchangeCounter;

void displayArray(const int * a, int s);
void randomizeArray(int * a, int s, int m = 10000);
bool inOrder(int a, int b);
void exchange(int & a, int & b);
void exchangeSort(int * a, int s);
/*void insertionSort(int * a, int s);
void insertionSort(int * a, int start, int stop);



void insertionSort(int * a, int s){
	insertionSort(a, 0, s-1);
}
*/










int main(){

	srand((unsigned)time(0));

	int size = 1000;

	int * theArray = new int [size];
	randomizeArray(theArray, size);
	displayArray(theArray, size);

	exchangeCounter = 0;
	comparisonCounter = 0;

	exchangeSort(theArray, size);
	displayArray(theArray, size);

	cout << "Comparisons:  " << comparisonCounter << endl;
	cout << " Exchanges:  " << exchangeCounter << endl;

	exchangeCounter = 0;
	comparisonCounter = 0;

	exchangeSort(theArray, size);
	displayArray(theArray, size);

	cout << "Comparisons:  " << comparisonCounter << endl;
	cout << " Exchanges:  " << exchangeCounter << endl;


	return 0;
}

//function to display the array
void displayArray(const int * a, int s){
	if (s <= 200){
		for (int i = 0; i < s; ++i){
			if (i % 10 == 0){
				cout << endl;
			}
			cout << setw(7) << a[i];
		}
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
//Fill array with random numbers
void randomizeArray(int * a, int s, int m ){
	for (int i = 0; i < s; ++i){
		a[i] = rand()%m;
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

