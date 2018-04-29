

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//
// This program will find all the prime number up to 1000
//
//
//
int main()
{
    vector<int> lastFive;
    
    // outer loop 
    for (int i = 0; i < 1000; i++)
    {
	bool bPrime = true;
	for (int j = 2 ; j < i; j++)
	{
	    if (i%j === 0)
	    {
		// not a prime
		bPrime = false;
		break;
	    }
	}
	
	if (bPrime)
	{
	    //cout << i << " "; 
	    lastFive.push_back (i);
	}
    }

    for (int i = 0; i < 5 ; i++)
    {
	cout << lastFive.back() << " ";
	lastFive.pop_back();
    }

    return 0;
}
