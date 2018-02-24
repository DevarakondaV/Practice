#include "LList.h"
#include <iostream>


using namespace std;


int main()
{
	List<int> l = List<int>(5);
	l.add_value(6);
	l.add_value(9);
	l.add_value(14);
	l.add_value(6);
	l.print();
	return -1;
}
