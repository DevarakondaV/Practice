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
		T pop_back(); //pops the last value and returns it. Will remove last value from list;
		void push(T m_val); //pushes to the back of list
		void insert(T m_val,int idx); //inserts m_val at index idx
		void remove(T m_val); //removes m_val if it exists
		void remove_by_idx(int idx); //remove element at index idx		

		//
		T operator[](int idx);

		//Access
		int size(); //retrun size of the list;
		void print(); //prints entire list
		int get_index(T m_val); //return index of m_val or return -1	

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
		Node * get_root();

		int find(T m_val); //return index of m_val or -1 if doesn't exit
};


template<typename T>
class iter{
	public:
		iter(List<T> & my_list,bool end);	
		T operator*();
		void operator++();
		void operator++(int);
		bool operator==(iter<T> test_iter);
		bool operator!=(iter<T> test_iter);
	private:
		typename List<T>::Node * cur_node;
		List<T> & m_list;
		friend class List<T>;
};

#endif
