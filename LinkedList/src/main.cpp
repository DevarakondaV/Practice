#include "LList.h"
#include <iostream>


using namespace std;


int main()
{
	List<int> l = List<int>(5);
	l.add_value(3);
	l.add_value(9);
	l.push(14);
	l.push(6);
	l.insert(8,4);
	l.print();
	l.remove_by_idx(3);
	cout << endl;
	l.print();	
	return -1;
}
