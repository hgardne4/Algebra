#include "Vector.h"
#include <stdexcept>
#include <iostream>
#include "Vector.cpp"
using namespace DataGrouping;
using namespace std;

int main() {
	Vector<int> v;
	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(5);
	v.push(6);
	v.push(10,3);
	v.output();
	int x = v.pop(2);
	

	cout << x << "\n";
	v.output();

	cout << v.length() << " " << v.capacity() << "\n"; 
	return 0;
}