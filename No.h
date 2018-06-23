#include <cstddef>

template <class T>
class No {
	
public: 
   T valor;
   No *esq = NULL;
   No *dir = NULL;
   
   No(T valor) 
   { 
   		this->valor = valor; 
   }  
};
