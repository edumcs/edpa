#include <iostream>
#include "MinHeap.h"

using namespace std;

int main()
{
	const int MAX_NUMBER_OF_CASHIERS = 10000;
	
    int cashierTimeToProcess[MAX_NUMBER_OF_CASHIERS];
    int cashierPriority[MAX_NUMBER_OF_CASHIERS];
    
    for (int n = 0; n < MAX_NUMBER_OF_CASHIERS; n++) {
    	cashierPriority[n] = rand() % 100 + 1;
    	cashierTimeToProcess[n] = rand() % 100 + 1;
		printf("pos %d - %d\n ", n , cashierPriority[n]);  	
	}
	
	cout << "------------------------------------------MIN HEAP-----------------------------------------------\n ";

    struct MinHeap* minHeap = generateTreeMinHeap(cashierTimeToProcess, cashierPriority, MAX_NUMBER_OF_CASHIERS);
 
    int i = 0;

    while (i < MAX_NUMBER_OF_CASHIERS)
    {
        printf("pos %d - %d [%d]\n ", i ,minHeap->array[i]->val, minHeap->array[i]->timeToProcess);
        i++;
    }
    
    return 0;
}
