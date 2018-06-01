//pc 23 Prime Number List
#include<iostream>
#include<fstream>
using namespace std;

bool isPrime(int);

int main ()
{
	ofstream myPrimeList;
	myPrimeList.open ("PrimeList.txt");
	
	// checks num for to see if its a prime number by calling isPrime, then adds 1 and repeats until 100.
	for(int num = 0; num <= 100; num++)
	{

		bool prime = isPrime(num);

		if(prime == true)
		{
			//writes prime numbers to text file
			  
              myPrimeList << num << endl;
		}
 
		

	}
	 myPrimeList.close();

	return 0;
}

    bool isPrime (int num)
      {
		  bool prime = true; 
		  //eliminates 1 from prime list
          if( num < 2 ) 
		  {
			  prime = false;
		  }
		  //returns 2 as prime before loop testing
		  else if( num == 2 )
		  {
			  prime = true;
		  }
		  //returns even numbers as false before loop test
		  else if( num % 2 == 0 ) 
			  prime = false;
		  //declares square root of num  +1 to shorten loop cycles
		  else
		  {
			  int numCheck = sqrt(num)  + 1 ;
		  //tests from 3 to sqrt =+1 , adds 2 to n each cycle to avoid checking even numbers since they were tested above
          for ( int n = 3 ; n <= numCheck; n += 2 )
              if( num % n == 0 ) 
				  prime = false;
		  }
		  return prime;

    }