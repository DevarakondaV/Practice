#include <iostream>
#include "Heap.h"

using namespace std;

template<typename T>
void print_array(Heap<T> & m_h);

int main() {
	
	Heap<int> h = Heap<int>(1,1);
	
	for(int i = 2; i< 35; i++) {
		h.insert(i);
	}
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
	
