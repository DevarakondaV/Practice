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
	
	
	nTree.add_node_right(nTree.get_root(),2);
	nTree.add_node_left(nTree.get_root(),3);
	nTree.add_node_right(nTree.get_root()->r_node,4);
	nTree.add_node_left(nTree.get_root()->r_node,5);
	nTree.add_node_right(nTree.get_root()->l_node,6);
	nTree.add_node_right(nTree.get_root()->r_node->r_node,7);

	Tree<int>::Node* rtn = nTree.find(10);

	if (rtn != nullptr)
	{
		cout << "Found val" << endl;
	}
	else
	{
		cout << "Not Found " << endl;
	}	
	in_order_print(nTree.get_root()); cout << endl;
	cout << nTree.get_tree_height(nTree.get_root()) << endl;
	return(-1);
}


