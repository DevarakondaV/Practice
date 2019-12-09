#include <iostream>

using namespace std;


class BIT {
public:
	BIT(int n);
	~BIT();
	int query(int x);
	void update(int x,int uval);

	//helpers
	void print_arr();
private:
	int * a;
	int size;
};

BIT::BIT(int n) {
	/*
	args:
		n: size of BIT
	*/
	a = new int[n];
	this->size = n;
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
}

BIT::~BIT() {
	delete [] a;
}

int BIT::query(int x) {
	/*
	Function queries sum for range 0->x
	*/
	x++;
	int sum = 0;
	for (x; x > 0; x -= x & -x) //strip the trailing bit and subtract
		sum += a[x-1];
	return sum;
}


void BIT::update(int x, int uval) {
	/*
	Function updates the BIT at index xwith uval
	
	args:
		x: index
		uval: value at x
	*/
	x++;
	for (x; x <= this->size; x += x & -x) { //strip the trailing bit and add
		a[x-1] += uval;
	}
}

void BIT::print_arr() {
	for (int i = 0; i < this->size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	BIT B = BIT(4);
	B.print_arr();
	B.update(0, 5);
	B.print_arr();
	B.update(1, 2);
	B.print_arr();
	B.update(2,6);
	B.print_arr();
	B.update(3, 1);
	B.print_arr();

	cout << endl << endl;
	cout << B.query(0) << endl;
	cout << B.query(1) << endl;
	cout << B.query(2) << endl;
	cout << B.query(3) << endl;

}
