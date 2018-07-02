#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int timeToProcess;
    int val;
    int cost;
    struct Node *left, *right;
};
 
// Max Heap
struct MaxHeap
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
    temp->cost = timeToProcess*val;
    return temp;
}
 
struct MaxHeap* initMaxHeap(int capacityMax)
{
    struct MaxHeap* maxHeap =
         (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = 0;
    maxHeap->capacityMax = capacityMax;
    maxHeap->array =
     (struct Node**)malloc(maxHeap->capacityMax * sizeof(struct Node*));
    return maxHeap;
}

// Faz a troca dos nós
void swapNode(struct Node** a, struct Node** b)
{
    struct Node* t = *a;
    *a = *b;
    *b = t;
}
 
// Promover ou Rebaixar o nó
void promoteDemote(struct MaxHeap* maxHeap, int idx)
{
    int parent = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < maxHeap->size &&
        maxHeap->array[left]->cost > maxHeap->array[parent]->cost)
      parent = left;
 
    if (right < maxHeap->size &&
        maxHeap->array[right]->cost > maxHeap->array[parent]->cost)
      parent = right;
 
    if (parent != idx)
    {
        swapNode(&maxHeap->array[parent], &maxHeap->array[idx]);
        promoteDemote(maxHeap, parent);
    }
}
 
// Inserir um novo nó
void insertMaxHeap(struct MaxHeap* maxHeap, struct Node* Node)
{
    ++maxHeap->size;
    int i = maxHeap->size - 1;
    while (i && Node->val > maxHeap->array[(i - 1)/2]->val)
    {
        maxHeap->array[i] = maxHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    maxHeap->array[i] = Node;
}

void deleteMaxHeap(struct MaxHeap* maxHeap)
{
	//maxHeap->array[0]->val = maxHeap->array[maxHeap->size-1]->val;
	swapNode(&maxHeap->array[0], &maxHeap->array[maxHeap->size-1]);
	maxHeap->array[maxHeap->size-1] = NULL;
	maxHeap->size = maxHeap->size-1;
	
	promoteDemote(maxHeap, 0);
}
 
void buildMaxHeap(struct MaxHeap* maxHeap)
{
    int n = maxHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        promoteDemote(maxHeap, i);
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
 
// Funçao para criar uma árvore Heap
struct MaxHeap* generateTreeMaxHeap(int timeToProcess[], int val[], int size)
{
    struct MaxHeap* maxHeap = initMaxHeap(size);
    for (int i = 0; i < size; ++i)
        maxHeap->array[i] = newNode(timeToProcess[i], val[i]);
    maxHeap->size = size;
    buildMaxHeap(maxHeap);
    return maxHeap;
}
