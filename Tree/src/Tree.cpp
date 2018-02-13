//Binary Tree Implementation
#include "Tree.h"

//Class Tree Definitions

//Constructor simply defines root node
template<typename T>
Tree<T>::Tree() {

	root_node = new Node; 
	root_node.l_node = nullptr;
	root_node.r_node = nullptr;	
}

//destructor
template<typename T>
Tree<T>::~Tree() {
	erase();
	delete root_node;
}

//return ptr to root node
template<typename T>
typename Tree<T>::Node * Tree<T>::get_root() {
	return root_node;
}


//Method returns iterator pointer to first node in the tree (root node)
template<typename T>
iter<T> Tree<T>::begin() {
	iter<T> rtnIter = iter<T>(this);
	return rtnIter;	
}

template<typename T>
iter<T> Tree<T>::end() {
	return iter<T>();
}


//Class iter defintions
template<typename T>
iter<T>::iter(T & mTree) {
	m_tree = mTree;
	curNode = m_tree->get_root();
}

template<typename T>
iter<T>::iter() {
	m_tree = nullptr;
	curNode = nullptr;
}

//Dereferences curNode and returns Node
template<typename T>
typename Tree<T>::Node iter<T>::operator*(iter<T> m_iter) {
	return *curNode;
}


