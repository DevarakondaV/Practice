//Tree Decleration
#ifndef __TREE_H_
#define __TREE_H_


template<class T>
class Tree {
	public:

		struct Node{
			T val;
			Node * l_node;
			Node * r_node;
		};

		Tree();
		~Tree();
		
		//modifiers
		void erase(); //Clears all the tree
		void erase_children(T val);	//Erase all childrend of node val
		void erase_left_child(T val);	//Erases left child
		void erase_right_child(T val); //Erases right child
		void append_child();	//Inserts empty node
		void append_node(Node & val); //Inserts Node into tree
		void insert_subtree(Node & val); //Inserts subtree into array



		bool insert(T m_val);
		bool erase(T m_val);
		bool find(T m_val);
		
		bool empty();


	private:
		
		/*
		 * struct Node {
		 * 	T val;
		 * 	Node * l_node;
		 * 	Node * r_node;
		 * };
		 * */

		Node * root_node;
};



#endif
