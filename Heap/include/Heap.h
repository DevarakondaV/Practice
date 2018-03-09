#ifndef __HEAP__H__
#define __HEAP__H__


template<typename T>
class Heap 
{
	public:

		//constructors. 1 is max heap. 2 is min heap
		Heap(T root_val,int heap_type);


		//Helper
		T * get_root() { return Tree;}
		int get_size() { return n_size;}
	private:
	
		//1 is max heap. 2 is min heap	
		int HEAP_TYPE;
		int n_size;
		//Base Tree size. Once filled need to increase
		int b_size = 25;

		//Binary tree implementation as array
		T * Tree;

};


#endif
