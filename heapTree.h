#include <iostream>
#include "No.h"

template <class T>
class Heap {  

public:
  No<T> * no = NULL;
  
  Heap();    
  void inserir(T );
  //No<T> getNo();  
};

template <class T>
Heap<T> :: Heap()
{
  
}

template <class T>
void Heap<T> :: inserir(T valor)
{
	this->no = new No<T>(valor);
	this->no->esq = NULL;
	this->no->dir = NULL;
}

