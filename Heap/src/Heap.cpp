#include "Heap.h"


//Defining methods

template<typename T>
Heap<T>::Heap(T root_val,int heap_type) {
	HEAP_TYPE = heap_type;

	Tree = new T[b_size];
	*Tree = root_val;
	n_size = 1;
}




template class Heap<int>;
