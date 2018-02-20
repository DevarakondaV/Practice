//Tree Decleration
#ifndef __TREE_H_
#define __TREE_H_

//template<typename T> class iter;

template<typename T>
class Tree {
	public:

		//Iterator declerations
		//typedef iter<T> iterator;
		//friend class iter<T>;

		//Iterator functions
		///iterator begin();	//Returns iterator to first item
		//iterator end();		//Returns iterattor to last item


		//Tree Node
		struct Node {
			T val;
			Node * l_node;
			Node * r_node;
			bool operator==(Node comp_node); //Compares two Nodes by checking their Children
		};

		//Constructors and access
		Tree(T root_val);
		~Tree();
		Node * get_root();
		int get_tree_depth(Node * m_node);
		int get_tree_height(Node * m_node);
		int get_node_count();
		Node * find(T m_val);

		
		//modifiers
		void erase();	//Clears all the tree
		void erase_children(T val);	//Erase all children of node val
		void erase_left_child(T val);	//Erases left child
		void erase_right_child(T val); //Erases right child
		
		//& these methods below may not be necessary
		//void append_child();	//Inserts empty node
		//void append_node(T m_val); //Inserts Node into tree
		//void append_tree(Node * val); //Adds node or tree to the tree
		//&
	
		//iterator find_inorder(const T m_val); //In order traversal
		//iterator find_preorder(const T m_val); //preorder traversal
		//iterator find_postorder(const T m_val); //Postorder traversal

		void add_node_right(Node * m_node, T m_val); //Function adds node or tree to left o m_node
		void add_node_left(Node * m_node,T m_val);	//Function add node or tree to left of m_node

	private:

		Node * root_node;
		void in_order_add(Node * m_node,T m_val);
		//void add_node_right(Node * m_node, T m_val); //Adds new node to right of m_node
		//void add_node_left(Node * m_node, T m_val); //Adds new node to left of m_node
		int erase_nodes(Node * m_node); // Erases all nodes;
		Node * find(Node * m_node, T m_val);

		int number_nodes;
		int tree_height;
		int tree_depth;
};


/*
template<typename T> class iter{
	public:
		iter();
		iter(T & mTree);
		typename Tree<T>::Node operator*(iter<T> m_iter);
		//For trees...operator++ cannot interate without parent node
		iter<T> operator++();
	private:
		typename Tree<T>::Node * curNode;
		Tree<T> & m_tree;
};*/


#endif
