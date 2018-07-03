#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int timeToProcess;
    int val;
    int cost;
    struct Node *left, *right;
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

// Faz a troca dos nós
void swapNode(struct Node** a, struct Node** b)
{
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Verifica se o nó é uma folha
int isLeaf(struct Node* root)
{
    return !(root->left) && !(root->right) ;
}

