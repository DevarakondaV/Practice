#include "Tree.h"
#include <stdio.h>
#include <iostream>



using namespace std;

//template<typename T> 
void in_order_print(Tree<int>::Node * m_node) {
		if (m_node->l_node != nullptr)
			in_order_print(m_node->l_node);
		
		cout << m_node->val << " ";

		if (m_node->r_node != nullptr)
			in_order_print(m_node->r_node);
}

int main() {

	Tree <int> nTree = Tree<int>(1);
	nTree.append_node(2);
	nTree.append_node(3);
	nTree.append_node(4);
	nTree.append_node(5);
	nTree.append_node(6);
	in_order_print(nTree.get_root()); cout << endl;
	cout << nTree.get_tree_height(nTree.get_root()) << endl;
	return(-1);
}


