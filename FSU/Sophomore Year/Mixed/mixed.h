/* Name: Marshall Copeland
Date: 9/25/20
Section: #10
Assignment: HW #3
Due Date: 10/05/20
About this project: Create a class called Mixed. Objects of type Mixed will store and manage rational numbers in a mixed number format (integer part and a fraction part). The class, along with the required operator overloads, should be written in the files "mixed.h" and "mixed.cpp".

All work below was performed by Marshall Copeland */

#include <iostream>
using namespace std;

class Mixed
{
	//friend operator functions, which take in 2 const Mixed objects by reference
	friend Mixed operator+(const Mixed& x, const Mixed& y);
	friend Mixed operator-(const Mixed& x, const Mixed& y);
	
	friend Mixed operator*(const Mixed& x, const Mixed& y);
	friend Mixed operator/(const Mixed& x, const Mixed& y);
	
	friend bool operator==(const Mixed& x, const Mixed& y);
	friend bool operator!=(const Mixed& x, const Mixed& y);
	
	friend bool operator<(const Mixed& x, const Mixed& y);
	friend bool operator>(const Mixed& x, const Mixed& y);
	
	friend bool operator<=(const Mixed& x, const Mixed& y);
	friend bool operator>=(const Mixed& x, const Mixed& y);
	
	friend ostream& operator<<(ostream& x, const Mixed& y);
	friend istream& operator>>(istream& x, Mixed& y);

	//public member functions
	public:
	Mixed(int defaultInteger, int defaultNumerator, int defaultDenominator); //two constructors, one to take in an integer, numerator, and denominator, and the other takes in just an integer
	Mixed(int defaultInteger = 0); 
	
	double Evaluate() const;
	void Simplify();
	void ToFraction();
	
	Mixed& operator++();	//pre/post increment/decrement operator functions
	Mixed& operator--();
	Mixed operator++(int);
	Mixed operator--(int);
	
	
	//private member data
	private:
	int Integer;
	int Numerator;
	int Denominator;
	int MixedNumber;
	int Fraction;
	
};
