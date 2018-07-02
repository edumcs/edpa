#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int timeToProcess;
    int val;
    struct Node *left, *right;
};
 
// Min Heap
struct MinHeap
{
    int size;
    int capacityMax;
    struct Node **array;
};
 
//Criar novo nó
struct Node* newNode(int timeToProcess, int val)
{
    struct Node* temp =
          (struct Node*) malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->timeToProcess = timeToProcess;
    temp->val = val;
    return temp;
}
 
struct MinHeap* initMinHeap(int capacityMax)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacityMax = capacityMax;
    minHeap->array =
     (struct Node**)malloc(minHeap->capacityMax * sizeof(struct Node*));
    return minHeap;
}

// Faz a troca dos nós
void swapNode(struct Node** a, struct Node** b)
{
    struct Node* t = *a;
    *a = *b;
    *b = t;
}
 
// Promover ou Rebaixar o nó
void promoteDemote(struct MinHeap* minHeap, int idx)
{
    int parent = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->val < minHeap->array[parent]->val)
      parent = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->val < minHeap->array[parent]->val)
      parent = right;
 
    if (parent != idx)
    {
        swapNode(&minHeap->array[parent], &minHeap->array[idx]);
        promoteDemote(minHeap, parent);
    }
}
 
// Inserir um novo nó
void insertMinHeap(struct MinHeap* minHeap, struct Node* Node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && Node->val < minHeap->array[(i - 1)/2]->val)
    {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = Node;
}

void deleteMinHeap(struct MinHeap* minHeap)
{
	swapNode(&minHeap->array[0], &minHeap->array[minHeap->size-1]);
	minHeap->array[minHeap->size-1] = NULL;
	minHeap->size = minHeap->size-1;
	
	promoteDemote(minHeap, 0);
}
 
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        promoteDemote(minHeap, i);
}
 
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
 
// Verifica se o nó é uma folha
int isLeaf(struct Node* root)
{
    return !(root->left) && !(root->right) ;
}
 
// Funçăo para criar uma árvore Heap
struct MinHeap* generateTreeMinHeap(int timeToProcess[], int val[], int size)
{
    struct MinHeap* minHeap = initMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(timeToProcess[i], val[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
 
