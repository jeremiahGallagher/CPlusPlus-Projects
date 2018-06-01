// Jeremiah Gallagher
// C++ 
// Monday 5:30 pm
// Spring 2017

#include <iostream>
#include <ctime>

using namespace std;

unsigned __int64 fib_rec(int n);

int main(int argc, char * argv[]){

	int n;
	unsigned __int64 result;

	if(argc == 2){
		n = atoi(argv[1]);
	}
	else{
		cout << "Please enter an integer: " << endl;
		cin >> n;
	}
	clock_t start, finish;

	start = clock();
	
	cout << "Fib(" << n << ") = "  << fib_rec(n) << endl;
	finish = clock();
	cout << "Elapsed time Approx: " 
		<< ((finish-start)/CLOCKS_PER_SEC) << " Seconds. " << endl;

	return 0;
}
	
unsigned __int64 fib_rec(int n){
	unsigned __int64 result = 1;

	if (n > 2){
		result = fib_rec(n-1) + fib_rec(n-2);
		}
	}
	return result;
}