#include <iostream>
#include<malloc.h>
#include "Node.h"
#include "MinHeap.h"
#include "Lista.h"

using namespace std;

int atendimento(MinHeap* filaCaixa, fila* filaCliente, int quantidadeClientes) {

	struct MinHeap* filaCaixasOcupados = initMinHeap(filaCaixa->size);
	int custo;
	int tempo = 0;
	int clientesProcessados = 0;

	while (clientesProcessados < quantidadeClientes) {
		//Retirar caixa com prioridade
		Node* caixa = topMinHeap(filaCaixa);
		
		if (caixa != NULL) {
			popMinHeap(filaCaixa);		
		
			//Inserir tempo de processamento			
			custo = filaCliente->prox->QIT * caixa->val;			
			caixa->auxVal = caixa->val;			
			caixa->val = custo;
			
			pushMinHeap(filaCaixasOcupados, caixa);
		} else {
			Node* caixaOcupado = topMinHeap(filaCaixasOcupados);
			
			if (caixaOcupado != NULL) {					
				popMinHeap(filaCaixasOcupados);
				
				//Inserir tempo de processamento
				if (filaCliente->prox != NULL) {
					custo = filaCliente->prox->QIT * caixaOcupado->auxVal;
					caixaOcupado->val += custo;
				} 			
				
				if (tempo < caixaOcupado->val)	{
					tempo = caixaOcupado->val;
				}
				
				pushMinHeap(filaCaixasOcupados, caixaOcupado);
				clientesProcessados++;
			}	
		}		
		
		retiraCliente(filaCliente);
	}
	
	cout << "------------------------------------------MIN HEAP-----------------------------------------------\n ";
	int i = 0;

    while (i < filaCaixasOcupados->size)
    {
        printf("pos %d - %d [%d]\n ", i ,filaCaixasOcupados->array[i]->val, filaCaixasOcupados->array[i]->auxVal);
        i++;
    }
    
    free (filaCaixasOcupados);
    return tempo;	
}

int main()
{	
	const int MAX_NUMBER_OF_CLIENTS =  7;//rand() % 10 + 1;
	const int MAX_NUMBER_OF_CASHIERS =  3;//rand() % MAX_NUMBER_OF_CLIENTS + 1;
	
    int cashierPriority[MAX_NUMBER_OF_CASHIERS];
    
    for (int n = 0; n < MAX_NUMBER_OF_CASHIERS; n++) {
    	cashierPriority[n] = rand() % 100 + 1;
	}

    struct MinHeap* filaCaixa = generateTreeMinHeap(cashierPriority, MAX_NUMBER_OF_CASHIERS);
	
	int i = 0;

    while (i < MAX_NUMBER_OF_CASHIERS)
    {
        printf("pos %d - %d\n ", i ,filaCaixa->array[i]->val);
        i++;
    }	
	
	fila *filaCliente = (fila *) malloc(sizeof(fila));
	if(!filaCliente){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else {
        iniciaFila(filaCliente);
    }
    
	preencheFila(filaCliente, MAX_NUMBER_OF_CLIENTS);
	
	cout << "------------------------------------------CLIENTES-----------------------------------------------\n ";
	exibeFila(filaCliente, MAX_NUMBER_OF_CLIENTS);
	
	int tempo = atendimento(filaCaixa, filaCliente, MAX_NUMBER_OF_CLIENTS);
	printf("--> TEMPO: %d ", tempo);
	
	free (filaCliente);
	free (filaCaixa);
    return 0;
}


	
