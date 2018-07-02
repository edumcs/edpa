#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main()
{
	const int MAX_NUMBER_OF_CASHIERS = 7;
	
    int cashierTimeToProcess[MAX_NUMBER_OF_CASHIERS];
    int cashierPriority[MAX_NUMBER_OF_CASHIERS];
    
    for (int n = 0; n < MAX_NUMBER_OF_CASHIERS; n++) {
    	cashierPriority[n] = rand() % 100 + 1;
    	cashierTimeToProcess[n] = rand() % 100 + 1;
		printf("pos %d - %d\n ", n , cashierPriority[n]);  	
	}
	
	cout << "------------------------------------------MAX HEAP-----------------------------------------------\n ";

    struct MaxHeap* maxHeap = generateTreeMaxHeap(cashierTimeToProcess, cashierPriority, MAX_NUMBER_OF_CASHIERS);
 
    int i = 0;

    //while (i < MAX_NUMBER_OF_CASHIERS)
    while(i< maxHeap->size)
    {
        printf("pos %d - %d [%d] - cost: [%d]\n ", i ,maxHeap->array[i]->val, maxHeap->array[i]->timeToProcess, maxHeap->array[i]->cost);
        i++;
    }
    

    deleteMaxHeap(maxHeap);
    printf("\n novo topo: %d\n", maxHeap->array[0]->cost);
    deleteMaxHeap(maxHeap);
    printf("\n novo topo: %d \n", maxHeap->array[0]->cost);
    deleteMaxHeap(maxHeap);
    printf("\n novo topo: %d \n", maxHeap->array[0]->cost);
    
    printf("\n Heap depois de 3 saidas: \n\n");
    
    i=0;
    while (i < maxHeap->size)
    {
        printf("pos %d - %d [%d] - cost: [%d]\n ", i ,maxHeap->array[i]->val, maxHeap->array[i]->timeToProcess, maxHeap->array[i]->cost);
        i++;
    }
    
    return 0;
}
