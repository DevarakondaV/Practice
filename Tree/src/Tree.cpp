//Tree Implementation
#include "Tree.h"

//Class Tree Definitions

//Constructor simply defines root node
template<typename T>
Tree<T>::Tree() {

	root_node = new Node; 
	root_node.l_node = nullptr;
	root_node.r_node = nullptr;	
}


//Method returns iterator pointer to first node in the tree (root node)
template<typename T>
typename Tree<T>::iterator Tree<T>::begin() {
	
}

//Class iter defintions
template<typename T>
iter<T>::iter(T & mTree) {
	m_tree = mTree;
}
