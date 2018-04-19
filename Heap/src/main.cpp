#include <iostream>
#include "Heap.h"

using namespace std;

template<typename T>
void print_array(Heap<T> & m_h);

int main() {
	
	int vals [7] = {13,67,3,5,92,7,6};
	
	Heap<int> h = Heap<int>(61,1);
	
	/*
	for(int i = 2; i< 35; i++) {
		h.insert(i);
	}*/

	//7
	for (int i = 0; i< 7;i++)
		h.insert(vals[i]);

	
	//print_array(h);
	//h.erase(13);
	//cout << endl;
	//print_array(h);
	//h.erase(92);
	//cout << endl;
	//print_array(h);
	//h.erase(67);
	//cout << endl;
	//print_array(h);
	//h.erase(61);
	//cout << endl;
	//print_array(h);
	//cout << endl;
	h.heapify(0,0);
	print_array(h);
	return -1;
}

template<typename T>
void print_array(Heap<T> & m_h) {
	int size = m_h.get_size();
	T * root = m_h.get_root();
	cout << size << endl;
	for (int i = 0; i< size;i++) {
		cout << root[i] << " ";
	}
}
	
