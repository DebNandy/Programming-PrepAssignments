
// File: hw2.2.cpp – pointers and arrays
// Author(s):
// DEBAJYOTI NANDY
// PALLAV RAJ

#include <iostream>
using namespace std;

int main()
{
	int i = 3;
	int j(-7);
	int k{ 21 };

	cout << "i: " << i << "\n";
	cout << "j: " << j << "\n";
	cout << "k: " << k << "\n";

	// (b)
	cout << "address of i: " << &i << "\n";
	cout << "address of j: " << &j << "\n";
	cout << "address of k: " << &k << "\n";
	/* Above statements display below information
	   Address of i : 00CFF9D0
	   Address of j : 00CFF9C4
	   Address of k : 00CFF9B8
	   The addresses are in descending order and the difference between 
	   two memory locations shows the amount of memory allocated to each
	   variable and the address locations are 12 memory units apart.
	*/

	// (c)
	int *pi = &i;
	int *pj = &j;
	int *pk = &k;

	cout << "value of pi: " << pi << ", contents at pi: " << *pi << '\n';
	cout << "value of pj: " << pj << ", contents at pj: " << *pj << '\n';
	cout << "value of pk: " << pk << ", contents at pk: " << *pk << '\n';
	/*
	   values of pi, pj, pk are displayed and the values are the addresses
	   of corresponding int variables. pi, pj, pk variables are pointers
	   to the corresponding addresses of i, j, k. * operator allows us to
	   access the content of those pointer variables. In this case, it's
	   simply the values of the int variables i,j,k
	*/

	// (d)
	double a[]{ 0.9, 1.8, 2.7, 3.6, 4.5 };
	for (int i(0); i < 5; i++)
		cout << a[i] << '\n';

	// (e)
	double * pa2 = &a[2];
	cout << "value of a[2]: " << a[2] << ", contents at pa2: " << *pa2 << '\n';
	/*
		The displayed values are the same and equal to 2.7 which is the 
		3rd element of a. pa2 is a pointer to the memory location/address
		of the a sub-2 element and this the contents at the location which
		pa2 points to, is same as the value of a sub-2 element
	*/

	// (f)
	cout << "*pa2 - 1: " << *pa2 - 1 << "\n";
	cout << "*(pa2 - 1): " << *(pa2 - 1) << "\n";
	cout << "*pa2 + 1: " << *pa2 + 1 << "\n";
	cout << "*(pa2 + 1): " << *(pa2 + 1) << "\n";
	/*
		The outputs are 1.7, 1.8, 3.7 and 3.6. This shows that the * operator
		has higher precedence over + and - operator. In the first case, 1 is 
		subtracted from the contents at pa2, which is 2.7-1 = 1.7. In the second
		case, due to use of parenthesis, 1 is subtracted from the pointer location
		which shifts the location one 'double' type worth of amount to the left 
		and element at that memory location is a sub-1 which is 1.8, the second 
		element of a. Similarly for the 3rd and 4th case, it's 2.7+1 = 3.7 and
		the 4th element 3.6, respectively.
	*/

	// (g)
	cout << 1[pa2] << '\n';
	/*
		Above compiled just fine and the output was 3.6 which is same as the value 
		of pa2[1], that is the next element after pa2 (to the right) in memory 
		location, that's 4th element of a which is 3.6.
	*/

	// (h)
	for (int i(-2); i < 3; i++)
		cout << pa2[i] << '\n';

	// (i)
	for (int i(0); i < 5; i++)
		cout << *(a + i) << '\n';

}

