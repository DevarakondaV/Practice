#ifndef __HEAP__H__
#define __HEAP__H__


template<typename T>
class Heap 
{
	public:
		
		//constructors. 1 is max heap. 2 is min heap
		Heap(T root_val,int heap_type);
		~Heap();
		//Modifier
		void insert(T m_val);
		void erase(T m_val);

		//Helper
		T * get_root();
		int get_size();
		T * get_last_left();
		int get_max_size();
			
	private:
	
		//1 is max heap. 0 is min heap	
		bool HEAP_TYPE;
		int n_size;
		//Base Tree size. Once filled need to increase
		int base_size = 50;
		int max_size = 50;
		//If Tree is full. Need to reinitialize with larger size
		void reinit_Tree();
		
		//Binary tree implementation as array
		T * Tree;

};


#endif
