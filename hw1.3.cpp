//  Programming Prep, Fall 2018
//  Homework 1.3
//  File:  hw1.3.cpp
//  Authors:  DEBAJYOTI NANDY & PALLAV RAJ
//  Description:  Program displays the size and range of various data types

#include<iostream>

#include <fstream>    
using namespace std;


int main()
{

	cout << "Data_type: \t" << "Size (bytes) \t" << "Min\t" << "Max\t" << "\n";
	cout << "bool" << "\t" << sizeof(bool) << "\t" << numeric_limits<bool>::min() << "\t" << numeric_limits<bool>::max() << "\n";
	cout << "char" << "\t" << sizeof(char) << "\t" << CHAR_MIN << "\t" << CHAR_MAX<< "\n";
	cout << "signed char" << "\t" << sizeof(signed char) << "\t" << SCHAR_MIN << "\t" << SCHAR_MAX << "\n";
	cout << "unsigned char" << "\t" << sizeof(unsigned char) << "\t" << '0' << "\t" << UCHAR_MAX << "\n";
	cout << "short" << "\t" << sizeof(short) << "\t" << SHRT_MIN << "\t" << SHRT_MAX << "\n";
	cout << "int" << "\t" << sizeof(int) << "\t" << INT_MIN << "\t" << INT_MAX << "\n";
	cout << "long" << "\t" << sizeof(long) << "\t" << INT_MIN << "\t" << INT_MAX << "\n";
	cout << "long long" << "\t" << sizeof(long long) << "\t" << numeric_limits<long long>::min() << "\t" << numeric_limits<long long>::max() << "\n";
	cout << "unsigned" << "\t" << sizeof(unsigned) << "\t" << numeric_limits<unsigned>::min() << "\t" << numeric_limits<unsigned>::max() << "\n";
	cout << "short unsigned" << "\t" << sizeof(short unsigned) << "\t" << '0' << "\t" << USHRT_MAX<< "\n";
	cout << "unsigned long" << "\t" << sizeof(unsigned long) << "\t" << '0' << "\t" << ULONG_MAX << "\n";
	cout << "unsigned long long" << "\t" << sizeof(unsigned long long) << "\t" << '0' << "\t" << numeric_limits<unsigned long long>::max() << "\n";
	cout << "float" << "\t" << sizeof(float) << "\t" << FLT_MIN << "\t" << FLT_MAX << "\n";
	cout << "double" << "\t" << sizeof(double) << "\t" << DBL_MIN << "\t" << DBL_MAX << "\n";
	cout << "long double" << "\t" << sizeof(long double) << "\t" << numeric_limits<long double>::min() << "\t" << numeric_limits<long double>::max() << "\n";

		//Store the results in a text file for better display
	ofstream outfile;
	outfile.open("result.txt");

	outfile << "Data_type: \t" << "Size (bytes) \t" << "Min\t" << "Max\t" << "\n";
	outfile << "bool" << "\t" << sizeof(bool) << "\t" << numeric_limits<bool>::min() << "\t" << numeric_limits<bool>::max() << "\n";
	outfile << "char" << "\t" << sizeof(char) << "\t" << CHAR_MIN << "\t" << CHAR_MAX << "\n";
	outfile << "signed char" << "\t" << sizeof(signed char) << "\t" << SCHAR_MIN << "\t" << SCHAR_MAX << "\n";
	outfile << "unsigned char" << "\t" << sizeof(unsigned char) << "\t" << '0' << "\t" << UCHAR_MAX << "\n";
	outfile << "short" << "\t" << sizeof(short) << "\t" << SHRT_MIN << "\t" << SHRT_MAX << "\n";
	outfile << "int" << "\t" << sizeof(int) << "\t" << INT_MIN << "\t" << INT_MAX << "\n";
	outfile << "long" << "\t" << sizeof(long) << "\t" << LONG_MIN << "\t" << LONG_MAX << "\n";
	outfile << "long long" << "\t" << sizeof(long long) << "\t" << numeric_limits<long long>::min() << "\t" << numeric_limits<long long>::max() << "\n";
	outfile << "unsigned" << "\t" << sizeof(unsigned) << "\t" << numeric_limits<unsigned>::min() << "\t" << numeric_limits<unsigned>::max() << "\n";
	outfile << "short unsigned" << "\t" << sizeof(short unsigned) << "\t" << '0' << "\t" << USHRT_MAX << "\n";
	outfile << "unsigned long" << "\t" << sizeof(unsigned long) << "\t" << '0' << "\t" << ULONG_MAX << "\n";
	outfile << "unsigned long long" << "\t" << sizeof(unsigned long long) << "\t" << '0' << "\t" << numeric_limits<unsigned long long>::max() << "\n";
	outfile << "float" << "\t" << sizeof(float) << "\t" << FLT_MIN << "\t" << FLT_MAX << "\n";
	outfile << "double" << "\t" << sizeof(double) << "\t" << DBL_MIN << "\t" << DBL_MAX << "\n";
	outfile << "long double" << "\t" << sizeof(long double) << "\t" << numeric_limits<long double>::min() << "\t" << numeric_limits<long double>::max() << "\n";

	outfile.close();

	/* RESULTS:

	Data_type: 	Size (bytes) 	Min	Max
	bool	1	0	1
	char	1	-128	127
	signed char	1	-128	127
	unsigned char	1	0	255
	short	2	-32768	32767
	int	4	-2147483648	2147483647
	long	4	-2147483648	2147483647
	long long	8	-9.22337E+18	9.22337E+18
	unsigned	4	0	4294967295
	short unsigned	2	0	65535
	unsigned long	4	0	4294967295
	unsigned long long	8	0	1.84467E+19
	float	4	1.18E-38	3.40E+38
	double	8	0.00E+00	1.79769e+308
	long double	8	0.00E+00	1.79769e+308
	
	*/

	return 0;

}