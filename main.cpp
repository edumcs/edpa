#include <iostream>
#include<malloc.h>
#include "Node.h"
#include "MinHeap.h"
#include "MaxHeap.h"
#include "Lista.h"

using namespace std;

 fila *Cliente = (fila *) malloc(sizeof(fila));

int main()
{	
	int MAX_NUMBER_OF_CLIENTS =  rand() % 10000 + 1;
	int MAX_NUMBER_OF_CASHIERS =  rand() % MAX_NUMBER_OF_CLIENTS + 1;
	
    int cashierTimeToProcess[MAX_NUMBER_OF_CASHIERS];
    int cashierPriority[MAX_NUMBER_OF_CASHIERS];
    
    for (int n = 0; n < MAX_NUMBER_OF_CASHIERS; n++) {
    	cashierPriority[n] = rand() % 100 + 1;
    	cashierTimeToProcess[n] = 0;	
	}
	
	cout << "------------------------------------------MIN HEAP-----------------------------------------------\n ";

    struct MinHeap* minHeap = generateTreeMinHeap(cashierTimeToProcess, cashierPriority, MAX_NUMBER_OF_CASHIERS);
 
	
    int i = 0;
/*
    while (i < MAX_NUMBER_OF_CASHIERS)
    {
        printf("pos %d - %d [%d]\n ", i ,minHeap->array[i]->val, minHeap->array[i]->timeToProcess);
        i++;
    }
*/	
	cout << "------------------------------------------LISTA-----------------------------------------------\n ";
	
    if(!Cliente){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else {
        iniciaFila(Cliente);
    }
    
	preencheFila(Cliente, MAX_NUMBER_OF_CLIENTS);  // preenche a fila com a quantidade de itens para cada cliente
//    exibeFila(Cliente, MAX_NUMBER_OF_CLIENTS);  //se quiser mostrar a fila existente
    
//    retiraCliente(Cliente);
	
    cout << "------------------------------------------MAX HEAP-----------------------------------------------\n ";

    struct MaxHeap* maxHeap = generateTreeMaxHeap(cashierTimeToProcess, cashierPriority, MAX_NUMBER_OF_CASHIERS);
 
    i = 0;

    while(i < maxHeap->size)
    {
        //printf("pos %d - %d [%d] - cost: [%d]\n ", i ,maxHeap->array[i]->val, maxHeap->array[i]->timeToProcess, maxHeap->array[i]->cost);
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
       // printf("pos %d - %d [%d] - cost: [%d]\n ", i ,maxHeap->array[i]->val, maxHeap->array[i]->timeToProcess, maxHeap->array[i]->cost);
        i++;
    }
    
    return 0;
}

void atendimento(MinHeap* filaCaixa, fila* cliente) {
	while (client->prox != NULL) {
		//Retirar caixa com prioridade
		Node* caixa = topMinHeap(filaCaixa);
		popMinHeap(filaCaixa);		
		
		//Inserir tempo de processamento
		caixa->cost = cliente->QIT * caixa->val;
		retiraCliente(cliente);
		
		
		
		
	}
}
	
