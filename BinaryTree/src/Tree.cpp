//Binary Tree Implementation
#include "Tree.h"
#include <stdexcept>
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
	//At leaf node
	if (m_node -> l_node == nullptr && m_node->r_node == nullptr)
		return 2; //Node deleted when function returns 2

	//If node exists to left
	if (m_node->l_node != nullptr)
	{
		if (erase_nodes(m_node -> l_node) == 2){
			delete m_node->l_node;
			m_node->l_node = nullptr;
		}
	}

	//if node exists to right
	if (m_node->r_node != nullptr)
	{
		if (erase_nodes(m_node->r_node) == 2) {
			delete m_node->r_node;
			m_node->r_node = nullptr;
		}
	}

	//at this point current node should be a leaf node. Hense return 2 so other nodes can be deleted
	return 2;
}

//return ptr to root node
template<typename T>
typename Tree<T>::Node * Tree<T>::get_root() {
	return root_node;
}




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
void Tree<T>::add_node_right(Node * m_node,T m_val) {
	if (m_node->r_node != nullptr)
		return;
	Node * new_node = new Node();
	new_node->val = m_val;
	m_node -> r_node = new_node;
	number_nodes++;
	return;
}

template<typename T>
void Tree<T>::add_node_left(Node * m_node, T m_val) {
	if (m_node->l_node != nullptr)
		return;
	Node * new_node = new Node();
	new_node->val = m_val;
	m_node -> l_node = new_node;
	number_nodes++;
	return;
}


//Various access and tre property methods
//Returns number of nodes in the tree
template<typename T>
int Tree<T>::get_node_count() {
	return number_nodes;
}	

//Returns the tree hight
template<typename T>
int Tree<T>::get_tree_height(Node * m_node) {
	if (m_node->l_node == nullptr && m_node->r_node == nullptr)
		return 0;

	int height_left = 0;
	int height_right = 0;

	if (m_node->l_node != nullptr)
	{
		height_left = height_left+1+get_tree_height(m_node->l_node);
	}

	if (m_node->r_node != nullptr)
	{
		height_right = height_right+1+get_tree_height(m_node->r_node);
	}

	return height_left >= height_right ? height_left : height_right;
}

//Searches tree for m_val
template<typename T>
typename Tree<T>::Node * Tree<T>::find(T m_val)
{
	return find(root_node,m_val);
}

//Binary search looking for m_val
template<typename T>
typename Tree<T>::Node * Tree<T>::find(Node * m_node,T m_val)
{
	if (m_node != nullptr && m_node->val == m_val)
		return m_node;
	
	Tree<T>::Node * l_rtnval = nullptr;
	Tree<T>::Node * r_rtnval = nullptr;
	
	
	if (m_node->l_node != nullptr)
		l_rtnval = find(m_node->l_node,m_val);
	if (m_node->r_node != nullptr)
		r_rtnval = find(m_node->r_node,m_val);

	if (l_rtnval != nullptr)
		return l_rtnval;

	if (r_rtnval  != nullptr)
		return r_rtnval;

	return nullptr;
}


//Erases all children at node of val
template<typename T>
void Tree<T>::erase_children(T val) {
	typename Tree<T>::Node * ptr= find(val);
	if (ptr != nullptr)
		erase_nodes(ptr);
}
			

template class Tree<int>;

