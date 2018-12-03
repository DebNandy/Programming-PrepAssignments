
// File: hw2.2.cpp – pointers and arrays
// Author(s):
// DEBAJYOTI NANDY
// PALLAV RAJ


// File: hw2.1.cpp
// Author(s):

#include <iostream>
using namespace std;

int main()
{
	int a[5];
	int b[5]{ 1, 2, 3, 4, 5 };
	int c[5]{ 6, 7 };
	int d[5]{ 8, 9, 10, 11, 12 };
	// removed the 6th element which is beyond the provided size
	// to make the code compile. 
	int e[5]{};
	int f[]{ 14, 15, 16, 17, 18, 19, 20, 21 };

	cout << "In hw2.1:\n";
	for (int i = 0; i < 5; i++)
		cout << a[i] << ' ';
	cout << '\n';
	/*
	(b)
		Output : -858993460 -858993460 -858993460 -858993460 -858993460
		The values are garbage but the same. This tells that the same garbage
		value is intialized in the 5 memory locations when the array is
		declared but not initialized explicitly.
	*/
	for (int i{ 0 }; i < 5; i++)
		cout << b[i] << ' ';
	cout << '\n';
	/*
	(c)
		Output : 1 2 3 4 5
		The displayed values are the initialized values of the array b
		This output is inline with what has been initialized
	*/
	for (int i{ 0 }; i < 5; i++)
		cout << c[i] << ' ';
	cout << '\n';
	/*
	(d)
	Output : 6 7 0 0 0
	First two elements in the display are the initialized values and
	rest of the uninitialized values of the array got initialized to
	value 0.
	This for loop also utilizes the same index, showing that the index
	got re-declared and initialized to 0, to be used within the above 
	for loop.
	*/
	// (e)
	double g[4]{};
	for (int i(0); i < 4; i++)
		cout << g[i] << ' ';
	cout << '\n';

	cout << "size of b : " << sizeof(b) << '\n';
	cout << "size of f : " << sizeof(f) << '\n';
	cout << "size of g : " << sizeof(g) << '\n';

	/*
	(f)
		Output: size of b : 20
				size of f : 32
				size of g : 32
		b and f are arrays of int data types of length 5, 8 
		respectively. Each int data type occupies 4 bytes of
		memory, thus size of b and f were 20 and 32.
		Whereas g is an array of double data type of length 4.
		Double type is of 8 bytes and this size of g is 32
	*/
	cout << "size of b[0] : " << sizeof(b[0]) << '\n';
	cout << "size of f[0] : " << sizeof(f[0]) << '\n';
	cout << "size of g[0] : " << sizeof(g[0]) << '\n';
	/*
	(g)
		Output: size of b[0] : 4
				size of f[0] : 4
				size of g[0] : 8
		As expected, the first element of these arrays will 
		be of size corresponding to the individual data types.
		In the case of b[0], f[0] which are of int data types, 
		the size is 4 bytes and in the case of g which is of
		double, the size is 8 bytes.
	*/
	int size = sizeof(f);
	int element_size = sizeof(f[0]);
	int length = size / element_size;
	cout << "Size of f : " << size << '\n';
	cout << "Size of f[0]: " << element_size << '\n';
	cout << "Length of f : " << length << '\n';
	/*
	(h)
		Number of elements can be calculated using the total
		initialized size of the array (in bytes) and dividing
		it by the size of one element (in bytes) in the array.
		As done above, the displayed length of the array is 8
	*/
	// (i)
	double h[] = { 2.2, 4.4, 1.1, 5.5,
		3.3, 6.6, 8.8, 0.0 };
	char ca[] = { 65, 'p', 112, 108, 'e' };

	cout << "Size of h : " << sizeof(h) << '\n';
	cout << "Size of h[0]: " << sizeof(h[0]) << '\n';
	cout << "Length of h : " << sizeof(h) / sizeof(h[0]) << '\n';
	for (int i(0); i < sizeof(h) / sizeof(h[0]); i++)
		cout << h[i] << ' ';
	cout << '\n';

	cout << "Size of ca : " << sizeof(ca) << '\n';
	cout << "Size of ca[0]: " << sizeof(ca[0]) << '\n';
	cout << "Length of ca : " << sizeof(ca) / sizeof(ca[0]) << '\n';
	for (int i(0); i < sizeof(ca) / sizeof(ca[0]); i++)
		cout << ca[i] << ' ';
	cout << '\n';



}


