//Binary Tree Implementation
#include "Tree.h"

//Class Tree Definitions

//Constructor simply defines root node
template<typename T>
Tree<T>::Tree(T root_val) {
	root_node = new Node;
	root_node->val = root_val;	
	root_node->l_node = nullptr;
	root_node->r_node = nullptr;
	number_nodes = 0;
	tree_height = 0;
	tree_depth = 0;
	number_nodes++;	
}

//destructor
template<typename T>
Tree<T>::~Tree() {
	erase();
	delete root_node;
}

//erases all data in tree
template<typename T>
void Tree<T>::erase() {
	erase_nodes(root_node);
}

template<typename T>
int Tree<T>::erase_nodes(Node * m_node) {
	if (m_node->l_node == nullptr && m_node->r_node == nullptr) {
		delete m_node->l_node;
		delete m_node->r_node;
		return 2;
	}

	if (m_node->l_node != nullptr) {
		if (erase_nodes(m_node->l_node) == 2)
			delete m_node->l_node;
	}

	if (m_node->r_node != nullptr) {
		if (erase_nodes(m_node->r_node) == 2)
			delete m_node->r_node;
	}
}

//return ptr to root node
template<typename T>
typename Tree<T>::Node * Tree<T>::get_root() {
	return root_node;
}


/*
//Method returns iterator pointer to first node in the tree (root node)
template<typename T>
iter<T> Tree<T>::begin() {
	iter<T> rtnIter = iter<T>(this);
	return rtnIter;	
}

template<typename T>
iter<T> Tree<T>::end() {
	return iter<T>();
}*/


//Adds m_val to the tree. If m_val< root.val, Node added left. else added right.

//Defining Node equal operator
template <typename T>
bool Tree<T>::Node::operator==(Node comp_node) {
	if (this->val ==  comp_node.val)
		return true;
	else
		return false;
}

template<typename T>
void Tree<T>::append_node(T m_Val) {
	in_order_add(root_node,m_Val);
}

//Private member of tree class
template<typename T>
void Tree<T>::in_order_add(Node * m_node, T m_val)
{
	if (m_node->val < m_val)
		return m_node->r_node == nullptr ? add_node_right(m_node,m_val) : in_order_add(m_node->r_node,m_val);
	else 
		return m_node->l_node == nullptr ? add_node_left(m_node,m_val) : in_order_add(m_node->l_node, m_val);
}

template<typename T>
void Tree<T>::add_node_right(Node * m_node,T m_val) {
	Node * new_node = new Node();
	new_node->val = m_val;
	m_node -> r_node = new_node;
	number_nodes++;
	return;
}

template<typename T>
void Tree<T>::add_node_left(Node * m_node, T m_val) {
	Node * new_node = new Node();
	new_node->val = m_val;
	m_node -> r_node = new_node;
	number_nodes++;
	return;
}


//Various access and tre property methods
//Returns number of nodes in the tree
template<typename T>
int Tree<T>::get_node_count() {
	return number_nodes;
}	

//Returns the tree high
//Not correctly implemented yet
template<typename T>
int Tree<T>::get_tree_height(Node * m_node) {
	if (m_node->l_node == nullptr && m_node->r_node == nullptr)
		return 1;

	return get_tree_height(m_node->l_node)+get_tree_height(m_node->r_node);
}


/*
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
}*/

template class Tree<int>;

