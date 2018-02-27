#include "LList.h"
#include <iostream>


//Constructors and destructors
template<typename T>
List<T>::List(T m_val)
{
	Node * new_root = new Node();
	new_root->next = nullptr;
	new_root->parent = nullptr;
	new_root->val = m_val;
	root = new_root;
	end = root;
	n_size = 1;
	ordered = false;
}


template<typename T>
void List<T>::add_value(T m_val)
{
	//Adding new value
	Node * new_val = new Node();
	new_val->val = m_val;
	new_val->parent = nullptr;
	root->parent = new_val;
	new_val->next = root;
	root = new_val;
	n_size++;
	return;
}

//Access methods
//return size
template<typename T>
int List<T>::size() {
	return n_size+1;
}

template<typename T>
T List<T>::pop() {
	Node * cpy = root;
	T val = root->val;
	root->next->parent = nullptr;
	root = root->next;
	n_size--;
	delete cpy;
	return val;
}

template<typename T>
void List<T>::push(T m_val)
{
	Node * new_node = new Node;
	new_node->val = m_val;
	new_node->next = nullptr;
	new_node->parent = end;
	end->next = new_node;
	end = new_node;
	n_size++;
}


//prints entire list
template<typename T>
void List<T>::print()
{
	Node * cur = root;
	while(cur != nullptr )
	{
		std::cout << cur->val << " ";
		cur = cur->next;
	}
}

template class List<int>;

