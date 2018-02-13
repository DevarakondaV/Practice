//Tree Decleration
#ifndef __TREE_H_
#define __TREE_H_

template<typename T> class iter;

template<typename T>
class Tree {
	public:

		//Iterator declerations
		typedef iter<T> iterator;
		friend class iter<T>;

		//Iterator functions
		iterator begin();	//Returns iterator to first item
		iterator end();		//Returns iterattor to last item


		//Tree Node
		struct Node {
			T val;
			Node * l_node;
			Node * r_node;
			//bool operator==(); //Compares two Nodes by checking their Children
		};

		//Constructors and access
		Tree();
		~Tree();
		Node * get_root();
		int get_depth(const T m_val);
		int get_tree_depth();
		int get_height(const T m_val);
		int get_tree_height();
		
		//modifiers
		void erase();	//Clears all the tree
		void erase_children(T val);	//Erase all children of node val
		void erase_left_child(T val);	//Erases left child
		void erase_right_child(T val); //Erases right child
		
		void append_child();	//Inserts empty node
		void append_node(T m_val); //Inserts Node into tree
		void append_tree(Node * val); //Adds node or tree to the tree


		iterator find_inorder(const T m_val); //In order traversal
		iterator find_preorder(const T m_val); //preorder traversal
		iterator find_postorder(const T m_val); //Postorder traversal

	private:

		Node * root_node;
};



template<typename T> class iter{
	public:
		iter();
		iter(T & mTree);
		typename Tree<T>::Node operator*(iter<T> m_iter);
		iter<T> operator++(iter<T> m_iter);
	private:
		typename Tree<T>::Node * curNode;
		Tree<T> & m_tree;
};


#endif
