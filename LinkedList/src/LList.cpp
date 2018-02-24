#include "LList.h"
#include <iostream>


//Constructors and destructors
/*
template<typename T>
List<T>::List()
{
	Node * new_root = new Node();
	new_root->next = nullptr;
	new_root->parent = nullptr;
	new_root->val = NULL;
	root = new_root;
	n_size = 0;
}*/


template<typename T>
List<T>::List(T m_val)
{
	Node * new_root = new Node();
	new_root->next = nullptr;
	new_root->parent = nullptr;
	new_root->val = m_val;
	root = new_root;
	n_size = 1;
}


template<typename T>
void List<T>::add_value(T m_val)
{
	/*
	//if root val is null
	if (root->val == NULL) {
		root->val = m_val;
		n_size = 1;
		return;
	}*/


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

