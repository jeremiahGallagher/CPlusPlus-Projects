/*        Author: Jeremiah Gallagher
 *        Advanced C++
 *        Monday 5:30 pm
 *        Spring 2017
 *
 *Summary: Advanced Sorts- This Program asks the user for a file containing a list of unsorted integers.
 *         It stores the ints inside an array.  It displays the a then sorts it with the quick sort
 *         algorithm. It diplays the sorted a, along with comparison and exchange counts.  It then
 *         uses the  sort again, followed by another display of the results.
 *          Finally, it reverses and resorts the array and displays results. After the quick sort
 *         demo, it continues with binary/natural merge sort and radix sorts, displaying the same sequence of results.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int comparisonCounter;
int exchangeCounter;


void quickSort(int * a, int s);
void quickSort(int * a, int lo, int hi);
int partition(int * a, int pivot, int lo, int hi);
void mergeSort(int * a, int s, bool natural);
void binaryMergeSort(int * a, int * temp, int begin, int end);
void naturalMergeSort(int * a, int * temp, int begin, int end);
void radixSort(int *a, int n);
void displayArray(const int * a, int s);
void copyArray(int* a, int* b, int size);
bool inOrder(int a, int b);
void exchange(int & a, int & b);
void reverse(int * a, int s);
void displayResults();

int main(int argc, char * argv){

	string fileName;

	if(2 == argc){
		fileName = argv[1];
	}
	else {
	cout << "Welcome to Advanced Sorting Demo!" << endl;
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

	int * b = new int[s];

	copyArray(a,b, s);

	cout << "original data" << endl;
	displayArray(b,s);
  cout << endl;
	cout << "begin of Quicksort" << endl << endl;
	displayArray(b,s);
	quickSort(b, 0, s-1);
	displayArray(b,s);
	displayResults();

	quickSort(b, 0, s-1);
	displayArray(b,s);
	displayResults();

	reverse(b,s);
	displayArray(b,s);

	comparisonCounter = 0;
	exchangeCounter = 0;

	quickSort(b, 0, s-1);
	displayArray(b,s);
	displayResults();
	cout << endl;
	delete(b);
	int * c = new int[s];
	copyArray(a,c,s);

	cout << "begin of Binary Merge Sort" << endl << endl;
	displayArray(c, s);
	mergeSort(c,s, false);
	displayArray(c,s);
	displayResults();

	mergeSort(c,s, false);
	displayArray(c,s);
	displayResults();

	reverse(c,s);
	displayArray(c,s);
	
	mergeSort(c,s, false);
	displayArray(c,s);
	displayResults();


	delete(c);

	

	cout << "begin of Natural Merge Sort" << endl << endl;
	cout << "NaturalMergeSort causes stack overflow on larger arrays and I could not find" << endl;
	cout << " A good solution even after initial due date so I commented it's iplementation out" << endl;
	cout << " So that you could test the others" << endl;
	/*
	int * d = new int[s];
	copyArray(a,d,s);
	displayArray(d, s);
	mergeSort(d,s, true);
	displayArray(d,s);
	displayResults();
	reverse(d,s);
	displayArray(d,s);
	mergeSort(d,s, true);
	displayArray(d,s);
	displayResults();

	delete (d);
	*/
	int * e = new int[s];
	copyArray(a,e,s);
	cout << "Start of  Radix Sort" << endl << endl;

	displayArray(e, s);
	radixSort(e,s);
	displayArray(e, s);
	displayResults();
	reverse(e,s);
	displayArray(e, s);
	radixSort(e,s);
	displayArray(e, s);
	displayResults();
	cout << endl << endl;
	cout << "I could not get binary radix to work so I reverted to the decimal version." << endl;
	cout << "I have sought forgiveness from the C++ Gods and will continue to try and figure it out." << endl;

  return 0;
}

//Copy contents of one array to another
void copyArray(int* a, int* b, int size){
	for (int i = 0; i < size; i++){
		b[i] = a[i];
	}
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

//Function to reverse elements
void reverse(int * a, int s){
   int temp;
   for(int i = 0; i < s/2; ++i){
      temp = a[s-i-1];
      a[s-i-1] = a[i];
      a[i] = temp;
    }
   cout << endl;
   cout << "reversed" << endl;
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
//helper function for quicksort
int partition(int * a, int low, int high) {

   int mid = low + ( high - low) / 2;
   int pivot = a[mid];
   a[mid] = a[low];
   while(low < high) {
      while(low < high && a[high] >= pivot) {
         high--;
      }
      a[low] = a[high];
      while(low < high && a[low] <= pivot) {
         low++;
      }
      a[high] = a[low];
      a[low] = pivot;
   }
   return low;
}

void quickSort(int * a, int low, int high) {
	while(low < high){
		comparisonCounter++;
		int j = partition(a, low, high);
		if(j - low < high - j){
			quickSort(a, low, j - 1);
			low = j + 1;
			comparisonCounter++;
			exchangeCounter++;
		}
		else{
			quickSort(a, j + 1, high);
			high = j - 1;
			comparisonCounter++;
			exchangeCounter++;
		}
	}
}

void quickSort(int * a, int n) {
   quickSort(a, 0, n - 1);
}
void displayResults(){
  cout << "Comparisons " << comparisonCounter << endl;
  cout << "Exchanges " << exchangeCounter << endl;
  comparisonCounter = 0;
  exchangeCounter = 0;
}
// binary merge sort sp
void binaryMergeSort(int * a, int * temp, int begin, int end){
  if(begin >= end){
	  comparisonCounter++;

    return;
  }
  int mid = begin + (end - begin) / 2;
  int begin1 = begin;
  int end1 = mid;
  int begin2 = mid + 1;
  int end2 = end;
  binaryMergeSort(a, temp, begin1, end1);
  binaryMergeSort(a, temp, begin2, end2);
  int k = begin;
  while(begin1 <= end1 && begin2 <= end2){
    temp[k++] = a[begin1] <= a[begin2] ? a[begin1++] : a[begin2++];
	comparisonCounter++;
	exchangeCounter++;
  }
  while(begin1 <= end1)
    temp[k++] = a[begin1++];
	comparisonCounter++;
	exchangeCounter++;

  while(begin2 <= end2){
    temp[k++] = a[begin2++];
	comparisonCounter++;
	exchangeCounter++;
  }
  for(k = begin; k <= end; k ++){
    a[k] = temp[k];
  }
}
//natural merge sort, finds existing groups of ordered data
void naturalMergeSort(int * a, int * temp, int begin, int end){
	if(begin >= end){
		comparisonCounter++;
	return;
	}
  int mid = begin;
  while(mid < end && a[mid] <= a[mid+1]){
    mid ++;
	comparisonCounter++;

	if(mid == end){
		comparisonCounter++;
	 return;
	}
  }

  int begin1 = begin;
  int end1 = mid;
  int begin2 = mid + 1;
  int end2 = end;
  naturalMergeSort(a, temp, begin1, end1);
  naturalMergeSort(a, temp, begin2, end2);
  int k = begin;
  while(begin1 <= end1 && begin2 <= end2){
    temp[k++] = a[begin1] <= a[begin2] ? a[begin1++] : a[begin2++];
	comparisonCounter++;

  }

	while(begin1 <= end1){
		temp[k++] = a[begin1++];
		comparisonCounter++;
		exchangeCounter++;
	}

	while(begin2 <= end2){
		temp[k++] = a[begin2++];
		comparisonCounter++;
		exchangeCounter++;
	}


  for(k = begin; k <= end; k ++)
    a[k] = temp[k];

}
//mergesort will run natural or binary depending on bool value
void mergeSort(int * a, int s, bool natural){
  int * temp = new int [s];
  if(natural){
	naturalMergeSort(a, temp, 0, s - 1);
  }
  else{
	  binaryMergeSort(a,temp, 0, s - 1);
  }
  delete(temp);
}
//radix sort, algorithm referenced from Stackoverflow.com forum
void radixSort(int *a, int n)
{
  int i;
  int maxNumber = a[0];
  for (i = 1; i < n; i++)
  {
    if (a[i] > maxNumber)
      maxNumber = a[i];
  }
  int exp = 1;
  int *temp = new int[n];
  while (maxNumber / exp > 0)
  {
    int bucket[10] = {  0 };
    for (i = 0; i < n; i++){
      bucket[a[i] / exp % 10]++;
	}
    for (i = 1; i < 10; i++){
      bucket[i] += bucket[i - 1];
	}
    for (i = n - 1; i >= 0; i--){
      temp[--bucket[a[i] / exp % 10]] = a[i];
	  exchangeCounter++;
	}
    for (i = 0; i < n; i++){
      a[i] = temp[i];
	}
    exp *= 10;
  }
  delete(temp);
}
