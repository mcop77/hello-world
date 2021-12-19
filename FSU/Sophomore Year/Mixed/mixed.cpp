/* Name: Marshall Copeland
Date: 9/25/20
Section: #10
Assignment: HW #3
Due Date: 10/05/20
About this project: Create a class called Mixed. Objects of type Mixed will store and manage rational numbers in a mixed number format (integer part and a fraction part). The class, along with the required operator overloads, should be written in the files "mixed.h" and "mixed.cpp".

All work below was performed by Marshall Copeland */

#include <iostream>
#include <iomanip>
#include "mixed.h"
using namespace std;

//sorry in advance for the long program, most of the code is just the Simplify function and ToFraction functions adapted for their own specific function application

Mixed::Mixed(int integer, int numerator, int denominator) //the first Mixed constructor
{
	Integer = integer; //all values are stored at the beginning
	Numerator = numerator;
	Denominator = denominator;
	
	if(denominator == 0) //then the values get put through many levels of error checking to make suer the values fit the assignment requirements
	{
		Integer = 0;
		Numerator = 0;
		Denominator = 1;
	}
	
	if((Integer < 0 && Numerator < 0) || (Integer < 0 && Denominator < 0) || (Numerator < 0 && Denominator < 0) || (Integer < 0 && Numerator < 0 && Denominator < 0))
	{
		Integer = 0;
		Numerator = 0;
		Denominator = 1;
	}
	
	if(integer == 0 && numerator != 0 && denominator != 0)
	{
		Integer = 0;
		Numerator = numerator;
		Denominator = denominator;	
	}
}

Mixed::Mixed(int integer) //the second constructor that only takes in an integer
{
	if(integer > 0 || integer < 0) //assigns the numerator to 0 and denominator to 1, because the integer doesnt pair with non-binary numbers
	{
		Integer = integer;
		Numerator = 0;
		Denominator = 1;
	}
	
	else
	{
		Integer = 0;
		Numerator = 0;
		Denominator = 1;
	}
}

double Mixed::Evaluate() const //the Evaluate function, which takes the Mixed object and returns the decimal equivalent version
{
	double divide;
	double total;
	
	divide = static_cast<double>(Numerator) / Denominator; //either the numerator or the denominator must be cast as a double to convert the int to a double and return a double value
	
	if(Integer >= 0) //different cases hat handle whether the Mixed object is positive or negative
	{
		total = Integer + divide;
	}
	
	else if(Integer < 0)
	{
		total = Integer - divide;
	}
		
	return total; //returns the decimal equivalence
}


void Mixed::Simplify() //the original Simplify function that simplifies the Mixed object
{
	int count = 0; //counting variable that helps keep track of how many times the denominator fits in the numerator to determine how many times to increment or decrement the integer
	int fakeNumerator = Numerator; //making sure that the actual Mixed object isnt changed until it needs to be
	int fakeDenominator = Denominator;
	int euclidNumerator; //variables that helps keep track of things in the gcd finder part
	int euclidDenominator;
	int euclidMultiplier;
	int euclidRemainder;
	int gcd;
	
	if(fakeNumerator >= fakeDenominator || fakeNumerator * -1 >= fakeDenominator) //figures out if the fraction part can be simplified
	{
		while(fakeNumerator >= fakeDenominator || fakeNumerator * -1 >= fakeDenominator) //as long as the fraction part of the Mixed object can be simplified this runs
		{
			if(fakeNumerator < 0) //increments the integer correctly if its positive or negative
			{
				fakeNumerator = fakeNumerator + fakeDenominator;
				count++;
			}
			
			else if(fakeNumerator > 0)
			{
				fakeNumerator = fakeNumerator - fakeDenominator;
				count++;
			}
		}
	}
	
	if(fakeNumerator < 0 || Integer < 0) //after the fraction is simplified, if the numerator is negative it turns into a positive because only the integer can be negative
	{
		if(fakeNumerator < 0)
		{
			fakeNumerator = fakeNumerator * -1;
		}
		
		Integer = Integer - count;
	}
	
	else if(fakeNumerator > 0 || Integer > 0)
	{
		Integer = Integer + count;
	}

	euclidNumerator = fakeNumerator; //once all that happens, these variables are set to find the gcd of the numerator and the denominaotr so it can be simplified
	euclidDenominator = fakeDenominator;

	while(euclidDenominator % euclidNumerator > 0)  //fimds the gcd, im too tired to explain it lol
	{
		euclidMultiplier = (euclidDenominator / euclidNumerator) - ((euclidDenominator / euclidNumerator) % 1);
		euclidRemainder = euclidDenominator - (euclidMultiplier * euclidNumerator);
		euclidDenominator = euclidNumerator;
		euclidNumerator = euclidRemainder;
	}

	gcd = euclidNumerator;
	
	if(fakeNumerator == 0 || fakeDenominator == 0) //if the fraction can be simplified it will be simplified
	{
		Numerator = 0;
		Denominator = 1;
	}

	else if(euclidDenominator % euclidNumerator == 0)
	{
		Numerator = fakeNumerator / gcd;
		Denominator = fakeDenominator / gcd;
	}
}


void Mixed::ToFraction() //function that converts the Mixed object to a fraction
{
	if(Integer < 0) //in every case, the integer is set to 0
	{
		Numerator = (Integer * Denominator) - Numerator;
		Integer = 0;
	}
	
	else if(Integer > 0)
	{
		Numerator = (Integer * Denominator) + Numerator;
		Integer = 0;
	}
	
	else 
	{
		Integer = 0;
		Numerator = Numerator;
		Denominator = Denominator;
	}
}

Mixed operator+(const Mixed& x, const Mixed& y) //the first of the arithmetic operators
{
	Mixed z; //creates a mixed object
	
	//const Mixed& x VARIABLES
	int fakeIntegerX = x.Integer; //changes all the variables to make sure the Mixed object isnt changed
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	
	//const Mixed& y VARIABLES
	int fakeIntegerY = y.Integer; //i made two aets of variables for the 2 different parameters
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	
	//Simplify VARIABLES 
	int count = 0;	//variables that help with the simplify function
	int euclidNumerator;
	int euclidDenominator;
	int euclidMultiplier;
	int euclidRemainder;
	int gcd;
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX; 
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//FINDING LIKE DENOMINATORS
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	fakeDenominatorX = fakeDenominatorX * fakeDenominatorY;
		
	//ADDING THE TWO TOGETHER
	fakeNumeratorX = fakeNumeratorX + fakeNumeratorY;
	
	
	//BEGINNING OF Simplify ALGORITHM FOR fakeIntegerX, fakeNumeratorX, and fakeDenominatorX
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				count++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				count++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - count;
		
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + count;
	}

	euclidNumerator = fakeNumeratorX;
	euclidDenominator = fakeDenominatorX;
	
	

	if(euclidDenominator != 1 && euclidNumerator != 0)
	{
		while(euclidDenominator % euclidNumerator > 0)
		{
			euclidMultiplier = (euclidDenominator / euclidNumerator) - ((euclidDenominator / euclidNumerator) % 1);
			euclidRemainder = euclidDenominator - (euclidMultiplier * euclidNumerator);
			euclidDenominator = euclidNumerator;
			euclidNumerator = euclidRemainder;
		}
	}

	if(euclidNumerator == 0)
	{
		gcd = 1;
	}
	
	else gcd = euclidNumerator;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if(euclidDenominator % euclidNumerator == 0)
	{
		fakeNumeratorX = fakeNumeratorX / gcd;
		fakeDenominatorX = fakeDenominatorX / gcd;
	}
	
	z.Integer = fakeIntegerX; //converts to Mixed object
	z.Numerator = fakeNumeratorX;
	z.Denominator = fakeDenominatorX;
	
	return z; //returns the Mixed object
}

Mixed operator-(const Mixed& x, const Mixed& y)
{
	Mixed z; //this is the same code as above but instead of adding, it is subtracting
	
	//const Mixed& x VARIABLES
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	
	//const Mixed& y VARIABLES
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	
	//Simplify VARIABLES
	int count = 0;
	int euclidNumerator;
	int euclidDenominator;
	int euclidMultiplier;
	int euclidRemainder;
	int gcd;
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//FINDING LIKE DENOMINATORS
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	fakeDenominatorX = fakeDenominatorX * fakeDenominatorY;
		
	//ADDING THE TWO TOGETHER
	fakeNumeratorX = fakeNumeratorX - fakeNumeratorY;
	
	
	//BEGINNING OF Simplify ALGORITHM FOR fakeIntegerX, fakeNumeratorX, and fakeDenominatorX
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				count++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				count++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - count;
		
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + count;
	}

	euclidNumerator = fakeNumeratorX;
	euclidDenominator = fakeDenominatorX;
	
	

	if(euclidDenominator != 1 && euclidNumerator != 0)
	{
		while(euclidDenominator % euclidNumerator > 0)
		{
			euclidMultiplier = (euclidDenominator / euclidNumerator) - ((euclidDenominator / euclidNumerator) % 1);
			euclidRemainder = euclidDenominator - (euclidMultiplier * euclidNumerator);
			euclidDenominator = euclidNumerator;
			euclidNumerator = euclidRemainder;
		}
	}

	if(euclidNumerator == 0)
	{
		gcd = 1;
	}
	
	else gcd = euclidNumerator;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if(euclidDenominator % euclidNumerator == 0)
	{
		fakeNumeratorX = fakeNumeratorX / gcd;
		fakeDenominatorX = fakeDenominatorX / gcd;
	}
	
	z.Integer = fakeIntegerX;
	z.Numerator = fakeNumeratorX;
	z.Denominator = fakeDenominatorX;
	
	return z; //converts and returns the Mixd object
}
	
Mixed operator*(const Mixed& x, const Mixed& y)
{
	Mixed z; //same as above but the Mixed objects are multiplied together
	
	//const Mixed& x VARIABLES
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	
	//const Mixed& y VARIABLES
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	
	//Simplify VARIABLES
	int count = 0;
	int euclidNumerator;
	int euclidDenominator;
	int euclidMultiplier;
	int euclidRemainder;
	int gcd;
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	

	//MULTIPLIES FRACTIONS TOGETHER
	fakeNumeratorX = fakeNumeratorX * fakeNumeratorY;
	fakeDenominatorX = fakeDenominatorX * fakeDenominatorY;
	
	//BEGINNING OF Simplify ALGORITHM FOR fakeIntegerX, fakeNumeratorX, and fakeDenominatorX
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				count++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				count++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - count;
		
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + count;
	}

	euclidNumerator = fakeNumeratorX;
	euclidDenominator = fakeDenominatorX;
	
	

	if(euclidDenominator != 1 && euclidNumerator != 0)
	{
		while(euclidDenominator % euclidNumerator > 0)
		{
			euclidMultiplier = (euclidDenominator / euclidNumerator) - ((euclidDenominator / euclidNumerator) % 1);
			euclidRemainder = euclidDenominator - (euclidMultiplier * euclidNumerator);
			euclidDenominator = euclidNumerator;
			euclidNumerator = euclidRemainder;
		}
	}

	if(euclidNumerator == 0)
	{
		gcd = 1;
	}
	
	else gcd = euclidNumerator;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if(euclidDenominator % euclidNumerator == 0)
	{
		fakeNumeratorX = fakeNumeratorX / gcd;
		fakeDenominatorX = fakeDenominatorX / gcd;
	}
	
	z.Integer = fakeIntegerX;
	z.Numerator = fakeNumeratorX;
	z.Denominator = fakeDenominatorX;
	
	return z; //converts and returns the Mixed object
}

Mixed operator/(const Mixed& x, const Mixed& y)
{
	Mixed z; //same as above but the Mixed objects are being divided
	
	//const Mixed& x VARIABLES
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	
	//const Mixed& y VARIABLES
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	
	//Simplify VARIABLES
	int count = 0;
	int euclidNumerator;
	int euclidDenominator;
	int euclidMultiplier;
	int euclidRemainder;
	int gcd;
	
	if(y.Integer == 0 && y.Numerator == 0 && y.Denominator == 1) //if the Mixed object is 0, return 0
	{
		return 0;
	}
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//DIVIDING THE TWO
		
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeDenominatorX = fakeDenominatorX * fakeNumeratorY;	
	
	//BEGINNING OF Simplify ALGORITHM FOR fakeIntegerX, fakeNumeratorX, and fakeDenominatorX
	
	if(fakeDenominatorX < 0) //if the denominator is negative after dividing, the negative goes to the numerator
	{
		fakeDenominatorX = fakeDenominatorX * -1;
		fakeNumeratorX = fakeNumeratorX * -1;
	}
	
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				count++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				count++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - count;
		
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + count;
	}

	euclidNumerator = fakeNumeratorX;
	euclidDenominator = fakeDenominatorX;
	
	

	if(euclidDenominator != 1 && euclidNumerator != 0)
	{
		while(euclidDenominator % euclidNumerator > 0)
		{
			euclidMultiplier = (euclidDenominator / euclidNumerator) - ((euclidDenominator / euclidNumerator) % 1);
			euclidRemainder = euclidDenominator - (euclidMultiplier * euclidNumerator);
			euclidDenominator = euclidNumerator;
			euclidNumerator = euclidRemainder;
		}
	}

	if(euclidNumerator == 0)
	{
		gcd = 1;
	}
	
	else gcd = euclidNumerator;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if(euclidDenominator % euclidNumerator == 0)
	{
		fakeNumeratorX = fakeNumeratorX / gcd;
		fakeDenominatorX = fakeDenominatorX / gcd;
	}
	
	z.Integer = fakeIntegerX;
	z.Numerator = fakeNumeratorX;
	z.Denominator = fakeDenominatorX;
	
	return z; //return the Mixed object
}
	
Mixed& Mixed::operator++() //operator function that increments the Integer
{
	Integer++; //increments the Integer
	
	return *this; //returns Integer
}

Mixed& Mixed::operator--() //same as above but decremented
{
	Integer--;
	
	return *this;
}


Mixed Mixed::operator++(int) //this operator function increments the Integer but returns the incremented Integer
{
	Mixed z = *this;

	Integer++;
	
	return z;
}

Mixed Mixed::operator--(int) //same as above but it returns the decremented Integer
{
	Mixed z = *this;

	Integer--;
	
	return z;
}
	
bool operator==(const Mixed& x, const Mixed& y) //operator function that returns a true/false value
{
	//const Mixed& x VARIABLES
	int countX = 0; //take a deep breath before reading this code, its 2 Simplify functions and 2 ToFraction functions, good luck
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	int gcdX;
	
	//const Mixed& y VARIABLES
	int countY = 0;
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	int gcdY;
	
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& x
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				countX++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				countX++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - countX;
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + countX;
	}

	gcdX = fakeNumeratorX % fakeDenominatorX;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if((fakeNumeratorX % (fakeNumeratorX % fakeDenominatorX) == 0) && (fakeDenominatorX % (fakeNumeratorX % fakeDenominatorX) == 0))
	{
		fakeNumeratorX = fakeNumeratorX / gcdX;
		fakeDenominatorX = fakeDenominatorX / gcdX;
	}
	
	else 
	{
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& y
	if(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
	{
		while(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
		{
			if(fakeNumeratorY < 0)
			{
				fakeNumeratorY = fakeNumeratorY + fakeDenominatorY;
				countY++;
			}
			
			else if(fakeNumeratorY > 0)
			{
				fakeNumeratorY = fakeNumeratorY - fakeDenominatorY;
				countY++;
			}
		}
	}
	
	if(fakeNumeratorY < 0 || fakeIntegerY < 0)
	{
		if(fakeNumeratorY < 0)
		{
			fakeNumeratorY = fakeNumeratorY * -1;
		}
		
		fakeIntegerY = fakeIntegerY - countY;
	}
	
	else if(fakeNumeratorY > 0 || fakeIntegerY > 0)
	{
		fakeIntegerY = fakeIntegerY + countY;
	}

	gcdY = fakeNumeratorY % fakeDenominatorY;
	
	if(fakeNumeratorY == 0 || fakeDenominatorY == 0)
	{
		fakeNumeratorY = 0;
		fakeDenominatorY = 1;
	}

	else if((fakeNumeratorY % (fakeNumeratorY % fakeDenominatorY) == 0) && (fakeDenominatorY % (fakeNumeratorY % fakeDenominatorY) == 0))
	{
		fakeNumeratorY = fakeNumeratorY / gcdY;
		fakeDenominatorY = fakeDenominatorY / gcdY;
	}
	
	else 
	{
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	//BEGINNING OF COMPARISON BETWEEN x AND y
	
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	
	
	if(fakeNumeratorX == fakeNumeratorY && fakeDenominatorX == fakeDenominatorY) //returns true if the are the same and false if they arent
	{
		return true;
	}
	
	else return false;
}

bool operator!=(const Mixed& x, const Mixed& y) //same format as above but comparing to see if they arent the same
{
	//const Mixed& x VARIABLES
	int countX = 0;
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	int gcdX;
	
	//const Mixed& y VARIABLES
	int countY = 0;
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	int gcdY;
	
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& x
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				countX++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				countX++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - countX;
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + countX;
	}

	gcdX = fakeNumeratorX % fakeDenominatorX;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if((fakeNumeratorX % (fakeNumeratorX % fakeDenominatorX) == 0) && (fakeDenominatorX % (fakeNumeratorX % fakeDenominatorX) == 0))
	{
		fakeNumeratorX = fakeNumeratorX / gcdX;
		fakeDenominatorX = fakeDenominatorX / gcdX;
	}
	
	else 
	{
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& y
	if(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
	{
		while(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
		{
			if(fakeNumeratorY < 0)
			{
				fakeNumeratorY = fakeNumeratorY + fakeDenominatorY;
				countY++;
			}
			
			else if(fakeNumeratorY > 0)
			{
				fakeNumeratorY = fakeNumeratorY - fakeDenominatorY;
				countY++;
			}
		}
	}
	
	if(fakeNumeratorY < 0 || fakeIntegerY < 0)
	{
		if(fakeNumeratorY < 0)
		{
			fakeNumeratorY = fakeNumeratorY * -1;
		}
		
		fakeIntegerY = fakeIntegerY - countY;
	}
	
	else if(fakeNumeratorY > 0 || fakeIntegerY > 0)
	{
		fakeIntegerY = fakeIntegerY + countY;
	}

	gcdY = fakeNumeratorY % fakeDenominatorY;
	
	if(fakeNumeratorY == 0 || fakeDenominatorY == 0)
	{
		fakeNumeratorY = 0;
		fakeDenominatorY = 1;
	}

	else if((fakeNumeratorY % (fakeNumeratorY % fakeDenominatorY) == 0) && (fakeDenominatorY % (fakeNumeratorY % fakeDenominatorY) == 0))
	{
		fakeNumeratorY = fakeNumeratorY / gcdY;
		fakeDenominatorY = fakeDenominatorY / gcdY;
	}
	
	else 
	{
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	//BEGINNING OF COMPARISON BETWEEN x AND y
	
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	
	
	if(fakeNumeratorX != fakeNumeratorY || fakeDenominatorX != fakeDenominatorY) //i feel like i could have simplified this but its 24 min until i need to submit and im tired
	{
		return true;
	}
	
	else return false;
}
	
bool operator<(const Mixed& x, const Mixed& y) //less than operator function
{
	//const Mixed& x VARIABLES
	int countX = 0;
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	int gcdX;
	
	//const Mixed& y VARIABLES
	int countY = 0;
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	int gcdY;
	
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& x
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				countX++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				countX++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - countX;
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + countX;
	}

	gcdX = fakeNumeratorX % fakeDenominatorX;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if((fakeNumeratorX % (fakeNumeratorX % fakeDenominatorX) == 0) && (fakeDenominatorX % (fakeNumeratorX % fakeDenominatorX) == 0))
	{
		fakeNumeratorX = fakeNumeratorX / gcdX;
		fakeDenominatorX = fakeDenominatorX / gcdX;
	}
	
	else 
	{
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& y
	if(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
	{
		while(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
		{
			if(fakeNumeratorY < 0)
			{
				fakeNumeratorY = fakeNumeratorY + fakeDenominatorY;
				countY++;
			}
			
			else if(fakeNumeratorY > 0)
			{
				fakeNumeratorY = fakeNumeratorY - fakeDenominatorY;
				countY++;
			}
		}
	}
	
	if(fakeNumeratorY < 0 || fakeIntegerY < 0)
	{
		if(fakeNumeratorY < 0)
		{
			fakeNumeratorY = fakeNumeratorY * -1;
		}
		
		fakeIntegerY = fakeIntegerY - countY;
	}
	
	else if(fakeNumeratorY > 0 || fakeIntegerY > 0)
	{
		fakeIntegerY = fakeIntegerY + countY;
	}

	gcdY = fakeNumeratorY % fakeDenominatorY;
	
	if(fakeNumeratorY == 0 || fakeDenominatorY == 0)
	{
		fakeNumeratorY = 0;
		fakeDenominatorY = 1;
	}

	else if((fakeNumeratorY % (fakeNumeratorY % fakeDenominatorY) == 0) && (fakeDenominatorY % (fakeNumeratorY % fakeDenominatorY) == 0))
	{
		fakeNumeratorY = fakeNumeratorY / gcdY;
		fakeDenominatorY = fakeDenominatorY / gcdY;
	}
	
	else 
	{
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	//BEGINNING OF COMPARISON BETWEEN x AND y
	
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	
	
	if(fakeNumeratorX < fakeNumeratorY)
	{
		return true;
	}
	
	else return false;
}

bool operator>(const Mixed& x, const Mixed& y) //greater than operator function
{
	//const Mixed& x VARIABLES
	int countX = 0;
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	int gcdX;
	
	//const Mixed& y VARIABLES
	int countY = 0;
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	int gcdY;
	
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& x
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				countX++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				countX++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - countX;
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + countX;
	}

	gcdX = fakeNumeratorX % fakeDenominatorX;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if((fakeNumeratorX % (fakeNumeratorX % fakeDenominatorX) == 0) && (fakeDenominatorX % (fakeNumeratorX % fakeDenominatorX) == 0))
	{
		fakeNumeratorX = fakeNumeratorX / gcdX;
		fakeDenominatorX = fakeDenominatorX / gcdX;
	}
	
	else 
	{
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& y
	if(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
	{
		while(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
		{
			if(fakeNumeratorY < 0)
			{
				fakeNumeratorY = fakeNumeratorY + fakeDenominatorY;
				countY++;
			}
			
			else if(fakeNumeratorY > 0)
			{
				fakeNumeratorY = fakeNumeratorY - fakeDenominatorY;
				countY++;
			}
		}
	}
	
	if(fakeNumeratorY < 0 || fakeIntegerY < 0)
	{
		if(fakeNumeratorY < 0)
		{
			fakeNumeratorY = fakeNumeratorY * -1;
		}
		
		fakeIntegerY = fakeIntegerY - countY;
	}
	
	else if(fakeNumeratorY > 0 || fakeIntegerY > 0)
	{
		fakeIntegerY = fakeIntegerY + countY;
	}

	gcdY = fakeNumeratorY % fakeDenominatorY;
	
	if(fakeNumeratorY == 0 || fakeDenominatorY == 0)
	{
		fakeNumeratorY = 0;
		fakeDenominatorY = 1;
	}

	else if((fakeNumeratorY % (fakeNumeratorY % fakeDenominatorY) == 0) && (fakeDenominatorY % (fakeNumeratorY % fakeDenominatorY) == 0))
	{
		fakeNumeratorY = fakeNumeratorY / gcdY;
		fakeDenominatorY = fakeDenominatorY / gcdY;
	}
	
	else 
	{
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	//BEGINNING OF COMPARISON BETWEEN x AND y
	
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	
	
	if(fakeNumeratorX > fakeNumeratorY)
	{
		return true;
	}
	
	else return false;
}
	
bool operator<=(const Mixed& x, const Mixed& y) //less than or equal to operator 
{
	//const Mixed& x VARIABLES
	int countX = 0;
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	int gcdX;
	
	//const Mixed& y VARIABLES
	int countY = 0;
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	int gcdY;
	
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& x
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				countX++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				countX++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - countX;
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + countX;
	}

	gcdX = fakeNumeratorX % fakeDenominatorX;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if((fakeNumeratorX % (fakeNumeratorX % fakeDenominatorX) == 0) && (fakeDenominatorX % (fakeNumeratorX % fakeDenominatorX) == 0))
	{
		fakeNumeratorX = fakeNumeratorX / gcdX;
		fakeDenominatorX = fakeDenominatorX / gcdX;
	}
	
	else 
	{
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& y
	if(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
	{
		while(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
		{
			if(fakeNumeratorY < 0)
			{
				fakeNumeratorY = fakeNumeratorY + fakeDenominatorY;
				countY++;
			}
			
			else if(fakeNumeratorY > 0)
			{
				fakeNumeratorY = fakeNumeratorY - fakeDenominatorY;
				countY++;
			}
		}
	}
	
	if(fakeNumeratorY < 0 || fakeIntegerY < 0)
	{
		if(fakeNumeratorY < 0)
		{
			fakeNumeratorY = fakeNumeratorY * -1;
		}
		
		fakeIntegerY = fakeIntegerY - countY;
	}
	
	else if(fakeNumeratorY > 0 || fakeIntegerY > 0)
	{
		fakeIntegerY = fakeIntegerY + countY;
	}

	gcdY = fakeNumeratorY % fakeDenominatorY;
	
	if(fakeNumeratorY == 0 || fakeDenominatorY == 0)
	{
		fakeNumeratorY = 0;
		fakeDenominatorY = 1;
	}

	else if((fakeNumeratorY % (fakeNumeratorY % fakeDenominatorY) == 0) && (fakeDenominatorY % (fakeNumeratorY % fakeDenominatorY) == 0))
	{
		fakeNumeratorY = fakeNumeratorY / gcdY;
		fakeDenominatorY = fakeDenominatorY / gcdY;
	}
	
	else 
	{
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	//BEGINNING OF COMPARISON BETWEEN x AND y
	
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	
	if(fakeNumeratorX <= fakeNumeratorY)
	{
		return true;
	}
	
	else return false;
}

bool operator>=(const Mixed& x, const Mixed& y) //greater than or equal to operator function
{
	//const Mixed& x VARIABLES
	int countX = 0;
	int fakeIntegerX = x.Integer;
	int fakeNumeratorX = x.Numerator;
	int fakeDenominatorX = x.Denominator;
	int gcdX;
	
	//const Mixed& y VARIABLES
	int countY = 0;
	int fakeIntegerY = y.Integer;
	int fakeNumeratorY = y.Numerator;
	int fakeDenominatorY = y.Denominator;
	int gcdY;
	
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& x
	if(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
	{
		while(fakeNumeratorX >= fakeDenominatorX || fakeNumeratorX * -1 >= fakeDenominatorX)
		{
			if(fakeNumeratorX < 0)
			{
				fakeNumeratorX = fakeNumeratorX + fakeDenominatorX;
				countX++;
			}
			
			else if(fakeNumeratorX > 0)
			{
				fakeNumeratorX = fakeNumeratorX - fakeDenominatorX;
				countX++;
			}
		}
	}
	
	if(fakeNumeratorX < 0 || fakeIntegerX < 0)
	{
		if(fakeNumeratorX < 0)
		{
			fakeNumeratorX = fakeNumeratorX * -1;
		}
		
		fakeIntegerX = fakeIntegerX - countX;
	}
	
	else if(fakeNumeratorX > 0 || fakeIntegerX > 0)
	{
		fakeIntegerX = fakeIntegerX + countX;
	}

	gcdX = fakeNumeratorX % fakeDenominatorX;
	
	if(fakeNumeratorX == 0 || fakeDenominatorX == 0)
	{
		fakeNumeratorX = 0;
		fakeDenominatorX = 1;
	}

	else if((fakeNumeratorX % (fakeNumeratorX % fakeDenominatorX) == 0) && (fakeDenominatorX % (fakeNumeratorX % fakeDenominatorX) == 0))
	{
		fakeNumeratorX = fakeNumeratorX / gcdX;
		fakeDenominatorX = fakeDenominatorX / gcdX;
	}
	
	else 
	{
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& x
	if(fakeIntegerX < 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) - fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else if(fakeIntegerX > 0)
	{
		fakeNumeratorX = (fakeIntegerX * fakeDenominatorX) + fakeNumeratorX;
		fakeIntegerX = 0;
	}
	
	else 
	{
		fakeIntegerX = 0;
		fakeNumeratorX = fakeNumeratorX;
		fakeDenominatorX = fakeDenominatorX;
	}
	
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
	
	//BEGINNING OF Simplify ALGORITHM for const Mixed& y
	if(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
	{
		while(fakeNumeratorY >= fakeDenominatorY || fakeNumeratorY * -1 >= fakeDenominatorY)
		{
			if(fakeNumeratorY < 0)
			{
				fakeNumeratorY = fakeNumeratorY + fakeDenominatorY;
				countY++;
			}
			
			else if(fakeNumeratorY > 0)
			{
				fakeNumeratorY = fakeNumeratorY - fakeDenominatorY;
				countY++;
			}
		}
	}
	
	if(fakeNumeratorY < 0 || fakeIntegerY < 0)
	{
		if(fakeNumeratorY < 0)
		{
			fakeNumeratorY = fakeNumeratorY * -1;
		}
		
		fakeIntegerY = fakeIntegerY - countY;
	}
	
	else if(fakeNumeratorY > 0 || fakeIntegerY > 0)
	{
		fakeIntegerY = fakeIntegerY + countY;
	}

	gcdY = fakeNumeratorY % fakeDenominatorY;
	
	if(fakeNumeratorY == 0 || fakeDenominatorY == 0)
	{
		fakeNumeratorY = 0;
		fakeDenominatorY = 1;
	}

	else if((fakeNumeratorY % (fakeNumeratorY % fakeDenominatorY) == 0) && (fakeDenominatorY % (fakeNumeratorY % fakeDenominatorY) == 0))
	{
		fakeNumeratorY = fakeNumeratorY / gcdY;
		fakeDenominatorY = fakeDenominatorY / gcdY;
	}
	
	else 
	{
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	
	//BEGINNING OF ToFraction ALGORITHM FOR const Mixed& y
	if(fakeIntegerY < 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) - fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else if(fakeIntegerY > 0)
	{
		fakeNumeratorY = (fakeIntegerY * fakeDenominatorY) + fakeNumeratorY;
		fakeIntegerY = 0;
	}
	
	else 
	{
		fakeIntegerY = 0;
		fakeNumeratorY = fakeNumeratorY;
		fakeDenominatorY = fakeDenominatorY;
	}
	
	//BEGINNING OF COMPARISON BETWEEN x AND y
	
	fakeNumeratorX = fakeNumeratorX * fakeDenominatorY;
	fakeNumeratorY = fakeNumeratorY * fakeDenominatorX;
	
	
	if(fakeNumeratorX >= fakeNumeratorY)
	{
		return true;
	}
	
	else return false;
}
	
ostream& operator<<(ostream& x, const Mixed& y) //operator function that reads output to be read in and assigned to the Mixed object
{	
	char space = ' '; //space character
	char slash = '/'; //slash character
	
	if(y.Integer == 0 && y.Numerator == 0 && y.Denominator == 1) //if the Mixed object is 0 it returns 0
	{
		return (x << 0);
	}
	
	else if(y.Integer != 0 && y.Numerator == 0 && y.Denominator == 1) //returns the Integer if the Integer constructor is used
	{
		return (x << y.Integer);
	}
	
	else if(y.Integer == 0 && y.Numerator != 0 && y.Denominator != 0) //if the Integer is 0, only the Numerator and Denominator are returned
	{
		return (x << y.Numerator << slash << y.Denominator);
	}
	
	else return (x << y.Integer << space << y.Numerator << slash << y.Denominator); //otherwise, the full Mixed object is returned
}

istream& operator>>(istream& x, Mixed& y) //operator function that reads in input to be assigned to the Mixed object
{
	char slash; //reads in the slash character
	
	x >> y.Integer >> y.Numerator >> slash >> y.Denominator; //reads in the Mixed object
		
	if(y.Denominator == 0) //all the error checking is the same as the first constructor
	{
		y.Integer = 0;
		y.Numerator = 0;
		y.Denominator = 1;
		
		return x;
	}
	
	if((y.Integer < 0 && y.Numerator < 0) || (y.Integer < 0 && y.Denominator < 0) || (y.Numerator < 0 && y.Denominator < 0) || (y.Integer < 0 && y.Numerator < 0 && y.Denominator < 0) || y.Numerator < 0 || y.Denominator < 0)
	{
		y.Integer = 0;
		y.Numerator = 0;
		y.Denominator = 1;
		
		return x;
	}
	
	if(y.Integer == 0)
	{
		if((y.Numerator < 0 && y.Denominator < 0) || (y.Denominator < 0))
		{
			y.Integer = 0;
			y.Numerator = 0;
			y.Denominator = 1;
			
			return x;
		}
	}
}



