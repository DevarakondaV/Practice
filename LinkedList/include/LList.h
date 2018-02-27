#ifndef __LLIST_H__
#define __LLIST_H__


template<typename T>
class List {
	public:
		//Constructors and Destructors
		List(T m_val);


		//Modifiers
		void add_value(T m_val); //adds value to the front of the list
		void remove_value(T m_val); //finds m_val and remove it 
		T pop(); // pops the first value and returns it. Will remove from list
		void push(T m_val); //pushes to the back of list


		//Access
		int size(); //retrun size of the list;
		void print(); //prints entire list	

	private:

		struct Node{
			Node * next;
			Node * parent;
			T val;
		};


		Node * root;
		Node * end;
		int n_size;
		bool ordered;
};


#endif
