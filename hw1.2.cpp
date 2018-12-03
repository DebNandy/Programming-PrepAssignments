//  Programming Prep, Fall 2018
//  Homework 1.2
//  File:  hw1.2.cpp
//  Authors:  
//				(a) DEBAJYOTI NANDY
//				(b) PALLAV RAJ
//  Description:  This program analyzes the behavior of int datatype around limiting situation.
//				  It illustrates how the output of integer datatype operations behave
//				  when the values are very large and near the maximum value allowed in C++.


#include <iostream>
using namespace std;

int main()
{
	int variable = 1000000000;
	cout << variable << "\n";
	/*
	Explanation to (a)
		This 1,000,000,000 (1 billion) gets displayed correctly.
	*/
	int second_variable = 3 * variable;
	cout << second_variable << "\n";

	/*
	Explanation to (b)
		The display after tripling it for the first time doesn't show 3 billion, but rather a large 
		negative number. This shows the size of the second_variable exceeds the limit of an int 
		datatype. In my machine, C++ is assigning 4 bytes to an int data type which is why the range 
		of a variable of int datatype is between -2^31 and 2^31-1. The limit for positive number 
		turns out to be 2,147,483,647 which is less than 3 billion resulting the crazy output.
	*/
	int third_variable = 3 * second_variable;
	cout << third_variable << "\n";
	/*
	Explanation to (c)
		The display after tripling it again, is also an unexpected output, which is again due to 
		explanation given for (b). 9 billion is beyond the limit an int datatype variable can
		have and the output this time is a large positive number but again garbage.
	*/

	double floating_variable = 1.0;
	cout << floating_variable << "\n";
	for (int i = 0; i < 100; i++)
	{
		floating_variable *= 2;
		cout << floating_variable << "\n";
	}
	/*
	Explanation to (d)
		The numbers are displayed complete till 2^19, meaning till 19 times multiplication by 2.
		But after that only 5 digit after the decimal place was being shown and remaining was shown
		as an exponent, like e+06 etc. By just looking at the numbers, seems like multiplication
		by 2 is giving correct numbers beyond 2^19 as well, but the "cout" truncates the number for 
		display purposes. 
	*/
	int int_max = INT_MAX;
	cout << int_max << "\n";
	/*
	Explanation to (e)
		The display shows the int max to be 2,147,483,647 on my machine which ties to explanation
		given in (b). This value shows the max allowed integer in my machine under int datatype.
	*/

	int int_max_beyond = int_max + 1;
	cout << int_max_beyond << "\n";
	/*
	Explanation to (f)
		Adding 1 to this max integer resulted into the value of INT_MIN ( - 2,17,483,648) which is
		the minimum possible value of an integer in my machine. Apparently, addition of 1 has resulted
		into the minimum possible number as if the addition operator passes through a circle of 2^32 
		values and 2^31-1 is an entry in that circle and when 1 is added, it moves to the next
		element in the circle which is - 2^31.
	*/
	return 0;
}