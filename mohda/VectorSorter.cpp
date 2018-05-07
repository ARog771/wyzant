
#include <climits>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

std::vector<int> bubbleSortedVector;
std::vector<int> insertionSortedVector;
std::vector<int> selectionSortedVector;

bool validateInput()
{
    bool valid = true;
    if (!std::cin)
    {
	std::cout << "[INVALID INPUT]" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	valid = false;
    }
    return valid;
}

void BubbleSort(void)
{
    bool sorted = false;
    
    while (!sorted)
    {
	sorted = true;
	for (int i = 0; i < bubbleSortedVector.size() - 1; i++)
	{
	    if (bubbleSortedVector[i] > bubbleSortedVector[i+1])
	    {
		unsigned temp = bubbleSortedVector[i];
		bubbleSortedVector[i] = bubbleSortedVector[i+1];
		bubbleSortedVector[i+1] = temp;
		sorted = false;
	    }
	}
    }
}

void InsertionSort(void)
{
    int j, t;
    for (int i = 0; i < insertionSortedVector.size(); i++){
	j = i;
	while (j > 0 && insertionSortedVector[j] < insertionSortedVector[j-1]){
	    t = insertionSortedVector[j];
	    insertionSortedVector[j] = insertionSortedVector[j-1];
	    insertionSortedVector[j-1] = t;
	    j--;
	}
    }
}

void SelectionSort(void)
{
    int pmin,temp;
    
    for (int i = 0; i < selectionSortedVector.size()-1; i++)
    {
	pmin = i;
	
	for (int j= i + 1; j < selectionSortedVector.size(); j++)
	{

	    if (selectionSortedVector[j] < selectionSortedVector[pmin])
		pmin = j;
	}

	if (pmin != i)
	{
	    temp = selectionSortedVector[i];
	    selectionSortedVector[i] = selectionSortedVector[pmin];
	    selectionSortedVector[pmin] = temp;
	}
    }
}

int main(void)
{
    unsigned vectorSize;

    /* initialize random seed: */
    srand (time(NULL));

    do {
	std::cout << "Please enter the size of the vector(100-50000):";
	std::cin >> vectorSize;
    } while (!validateInput() || vectorSize < 100 || vectorSize > 50000);

    for (int i; i<vectorSize; i++)
    {
	unsigned int r = rand()%65536;
	bubbleSortedVector.push_back(r);
	insertionSortedVector.push_back(r);
	selectionSortedVector.push_back(r);
    }
    
    std::clock_t start;
    double duration;

    start = std::clock();
    
    BubbleSort();
    
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    
    std::cout.setf(std::ios::fixed);
    std::cout << "Bubble Sort of: " << vectorSize << " took: " << duration << " seconds" << std::endl;

    //for (int j = 0; j < bubbleSortedVector.size(); j++)
    //	std::cout << bubbleSortedVector[j] << " ";
    //std::cout << std::endl;

    start = std::clock();
    
    InsertionSort();
    
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    
    std::cout.setf(std::ios::fixed);
    std::cout << "Insertion Sort of: " << vectorSize << " took: " << duration << " seconds" << std::endl;
   
    //for (int j = 0; j < insertionSortedVector.size(); j++)
    //	std::cout << insertionSortedVector[j] << " ";
    //std::cout << std::endl;

    start = std::clock();
    
    SelectionSort();
    
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    
    std::cout.setf(std::ios::fixed);
    std::cout << "Selection Sort of: " << vectorSize << " took: " << duration << " seconds" << std::endl;

    //for (int j = 0; j < selectionSortedVector.size(); j++)
    //	std::cout << selectionSortedVector[j] << " ";
    //std::cout << std::endl;

    return 0;
}

