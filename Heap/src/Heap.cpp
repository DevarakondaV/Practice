#include "Heap.h"


//Defining methods

template<typename T>
Heap<T>::Heap(T root_val,int heap_type) {
	HEAP_TYPE = heap_type;

	Tree = new T[max_size];
	*Tree = root_val;
	n_size = 1;
}


template<typename T>
Heap<T>::~Heap() {
	delete [] Tree;
}

/**
 * Inserts into Heap. Worst case scenario O(n)
 * Best Case O(log n)
 * */
//Insert not correctly implemented
template<typename T>
void Heap<T>::insert(T m_val) {
	//Insert exceeds max tree size
	//Worst case scenario
	if ((n_size+1) % base_size == 0)
		reinit_Tree();

	Tree[n_size] = m_val;
	n_size++;
}



//Returns max size of tree
template<typename T>
int Heap<T>::get_max_size() {
	return max_size;
}

//Returns ptr to root node
template<typename T> 
T *  Heap<T>::get_root() {
	return Tree;
}

//Returns tree size
template<typename T>
int Heap<T>::get_size() {
	return n_size;
}

//Private methods
/**Reinitializes tree to larger size
***Worst Case Scenaro. Takes O(n)
**/
template<typename T>
void Heap<T>::reinit_Tree() {
	///Make Tree max size larger
	max_size = max_size*2;

	//Initialize new Tree
	T * new_Tree = new T[max_size];
	//Copy old values
	for(int i = 0; i< n_size;i++) {
		new_Tree[i] = Tree[i];
	}
	//Delete old tree
	delete [] Tree;
	//reassign pointer
	Tree = new_Tree;
}

template class Heap<int>;
