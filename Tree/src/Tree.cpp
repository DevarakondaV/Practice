//Tree Implementation
#include "Tree.h"

template<class T>
Tree<T>::Tree() {

	root_node = new Node; 
	root_node.l_node = nullptr;
	root_node.r_node = nullptr;	
}


