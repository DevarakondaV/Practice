#include "Heap.h"


//Defining methods

template<typename T>
Heap<T>::Heap(T root_val,int heap_type) {
	
	HEAP_TYPE = heap_type == 1? true: false;

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
	
	int loc = n_size; //Insert location
	int parent_loc = 0; //Parent location of node at loc
	//parent_loc = loc%2 == 0 ? (loc/2) -1 :  loc/2; 
	parent_loc = ((loc%2 == 0) && (loc != 0)) ? (loc-2)/2 : (loc-1)/2;

	// 0 is min heap, 1 is max heap
	bool chk_parent_less_than;
	bool chk_parent_greater_than;
	while (true) {
		chk_parent_less_than = false;
		chk_parent_greater_than = false;
		if (HEAP_TYPE)
			chk_parent_less_than = Tree[parent_loc] < Tree[loc];
		else
			chk_parent_greater_than = Tree[parent_loc] > Tree[loc];
					
		if (chk_parent_less_than || chk_parent_greater_than){
			T cpy = Tree[parent_loc];
			Tree[parent_loc] = Tree[loc];
			Tree[loc] = cpy;
			loc = parent_loc;
			parent_loc = ((loc%2 == 0) && (loc != 0)) ? (loc-2)/2 : (loc-1)/2;
		}
		else
			break;
	}
	n_size++;
}

//erases element if it exists. returns 1 if erased and -1  else
template<typename T>
int Heap<T>::erase(T m_val) {
	int idx = -1;
	for(int i = 0; i<n_size;i++) {
		if (Tree[i] == m_val) {
			idx = i;
			break;
		}
	}
	Tree[idx] = Tree[n_size-1];
	n_size--;

	heapify(HEAP_TYPE,idx);
	return idx;
}

//Heapifies an out of order heap
template<typename T>
void Heap<T>::heapify(int heap_type, int p_idx) {

	T cpy[n_size];
	for(int i = 0;i<n_size;i++) {
		cpy[i] = Tree[i];
	}
	delete[] Tree;
	Tree = new T[max_size];
	
	int n_sizecpy = n_size;
	n_size = 0;
	HEAP_TYPE = heap_type;
	for(int i = 0;i<n_sizecpy;i++) {
		insert(cpy[i]);
	}
}

//Reheapifies with current heap setting from the base_size
template<typename T>
void Heap<T>::reheapify() {
	heapify(HEAP_TYPE,0);
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

//returns root val
template<typename T>
T Heap<T>::get_root_val() {
	return Tree[0];
}

//Private methods
/**Reinitializes tree to larger size
***Worst Case Scenaro. Takes O(n)
**/
template<typename T>
int Heap<T>::switch_parent_child(int heap_type,int p_idx) {
	int rtn_val = -1;
	int child1 = (p_idx*2)+1;
	int child2 = (p_idx*2)+2;
	if (heap_type == 1) {
		if (Tree[p_idx] < Tree[child1] || Tree[p_idx] < Tree[child2] ) {
			rtn_val = Tree[child1] < Tree[child2] ? child2 : child1;
		}
	}
	else {
		if (Tree[p_idx] > Tree[child1] || Tree[p_idx] > Tree[child2] ) {
			rtn_val = Tree[child1] < Tree[child2] ? child1 : child2;
		}
	}

	//check if rtn_val has been updated to new idx
	if (rtn_val == -1)
		return rtn_val;

	T cpy = Tree[p_idx];
	Tree[p_idx] = Tree[rtn_val];
	Tree[rtn_val] = cpy;
	return rtn_val;
}

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
