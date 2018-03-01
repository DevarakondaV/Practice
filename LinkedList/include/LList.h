#ifndef __LLIST_H__
#define __LLIST_H__

template<typename T>
class iter;

template<typename T>
class List {
	public:

		//iterator functions
		typedef  iter<T> iterator;
		iterator begin();
		iterator end();
		//Constructors and Destructors
		List(T m_val);


		//Modifiers
		void add_value(T m_val); //adds value to the front of the list
		void remove_value(T m_val); //finds m_val and remove it 
		T pop(); // pops the first value and returns it. Will remove from list
		void push(T m_val); //pushes to the back of list

		
		//
		void operator[](T m_val);

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
		Node * back;
		int n_size;
		bool ordered;

		//iterator private
		friend class iter<T>;
		Node * front();
};


template<typename T>
class iter{
	public:
		iter(List<T> & m_list);
	private:
		T cur_val;
		List<T> & m_list;
		friend class List<T>;
};

#endif
