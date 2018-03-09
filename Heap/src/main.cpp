#include <iostream>
#include "Heap.h"

using namespace std;

template<typename T>
void print_array(Heap<T> m_h);

int main() {
	
	Heap<int> h = Heap<int>(5,1);
	print_array(h);
	return -1;
}

template<typename T>
void print_array(Heap<T> m_h) {
	int size = m_h.get_size();
	T * root = m_h.get_root();

	for (int i = 0; i< size;i++) {
		cout << *root << " ";
		root++;
	}
}
	
