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
	back = root;
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
	return n_size;
}

//pops root value and returns
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

//pushes value to the back of list
template<typename T>
void List<T>::push(T m_val)
{
	Node * new_node = new Node;
	new_node->val = m_val;
	new_node->next = nullptr;
	new_node->parent = back;
	back->next = new_node;
	back = new_node;
	n_size++;
}

//returns iterator for list
template<typename T>
iter<T> List<T>::begin() {
	iterator it = iter<T>(*this,false);
	return it;
}

template<typename T>
iter<T> List<T>::end() {
	iterator it = iter<T>(*this,true);
	return it;
}

//returns index of m_val or returns -1
template<typename T>
int List<T>::get_index(T m_val) {
	return find(m_val);
}

//access values in List using [] operator
template<typename T>
T List<T>::operator[](int idx) {
	int idx_cpy = 0;
	Node * cur = root;
	for(idx_cpy;idx_cpy < idx;idx_cpy++)
		cur = cur->next;

	return cur->val;
}

//inserts value in List at specified index
template<typename T>
void List<T>::insert(T m_val,int idx) {
	if (idx<0 || idx>n_size-1)
		return;
	if (idx == 0) {
		add_value(m_val);
		return;
	}

	int idx_cpy = 0;
	Node * cur = root;
	for(idx_cpy;idx_cpy < idx-1;idx_cpy++)
		cur = cur->next;

	Node * new_node = new Node();
	new_node->parent = cur;
	new_node->next = cur->next;
	new_node->val = m_val;
	cur->next = new_node;
	new_node->next->parent = new_node;
	n_size++;
	return;
}
	

//Private functions
//returns root node
template<typename T>
typename List<T>::Node * List<T>::get_root() {
	return root;
}

//Finds index of m_val
template<typename T>
int List<T>::find(T m_val) {
	int idx = -1;
	Node * cur = root;
	while(cur != nullptr) {
		if (cur->val == m_val){
			idx++;
			break;
		}
		idx++;
		cur = cur->next;
	}
	return idx;
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

//iterator definitions
//iterator constructor
template<typename T>
iter<T>::iter(List<T> & my_list,bool end):m_list(my_list){
	//m_list = my_list;
	if (end)
		cur_node = nullptr;
	else
		cur_node = m_list.get_root();
}

//opertor * returns val of current node
template<typename T>
T iter<T>::operator*() {
	return cur_node->val;
}

//Increment iterator
template<typename T>
void iter<T>::operator++() {
	cur_node = cur_node->next;
}

//Post increment iterator
template<typename T>
void iter<T>::operator++(int){
	cur_node = cur_node->next;
}

template<typename T>
bool iter<T>::operator==(iter<T> test_iter) {
	if (test_iter.cur_node == nullptr || this->cur_node == nullptr)
		return false;
	if (*(*this) == *test_iter)
		return true;
	else
		return false;
	
}

template<typename T>
bool iter<T>::operator!=(iter<T> test_iter) {
	if (this->cur_node == nullptr && test_iter.cur_node == nullptr)
		return false;
	else 
		return true;
}

template class List<int>;
template class iter<int>;

