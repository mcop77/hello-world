/* Name: Marshall Copeland
Date: 09/06/20
Section: #10
Assignment: HW #1
Due Date: 09/14/20
About this project: You are to write a class called House, using filenames house.h and house.cpp, that will allow creation and handling of House objects, as described below.
Assumptions: None

All work below was performed by Marshall Copeland */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "house.h"

using namespace std;

House::House(int s, char borderChar, char fillChar) //main function with parameters
{
	if(s < 3) //if the size is less than 3 or greater than 37, the default size will be 3
	{
		size = 3;
	}
	
	else if(s > 37)
	{
		size = 37;
	}
	
	else size = s; //otherwise, the size is what is entered
	
	
	if(int(borderChar) < 33) //if the ASCII values of the entered character are greater than 126 or less than 33, the default characters are 'X' for the border and '*' for the fill
	{
		border = 'X';
	}
	
	else if(int(borderChar) > 126)
	{
		border = 'X';
	}
	
	else border = borderChar; //otherwise the entered character will be used
	
	SetBorder(borderChar); //calls the SetBorder function
	
	
	if(int(fillChar) < 33) //same as above, but for the fill characters
	{
		fill = '*';
	}
	
	else if(int(fillChar) > 126)
	{
		fill = '*';
	}
	
	else fill = fillChar;
	
	SetFill(fillChar); //calls the SetFill function
}

int House::GetSize() const //size function, is a const because no varaibles are beingn changed
{
	return size; //all it does is return the size of the base
}

int House::Perimeter() const //perimeter function, is const because no variables are changed
{
	int perimeter; //perimeter variable
	int square; //variable for the perimeter of the square part of the house
	int triangle; //variable for the perimeter of the triangle part of the house
	int tribase = size + 2; //the side of the equilateral triangle is the base size + 2
	
	square = size * 3; //the perimeter of the base part of the house is the 3 sides of the square, which is represented by the size * 3
	triangle = (tribase) * 3 - size; //the triangle perimeter is represented by the size + 2 multiplied by the 3 sides of the triangle, minus the original size because of the overlap between the triangle and the square in the house
	
	perimeter = square + triangle; //the total perimeter is then just the perimeter of the square added to the perimeter of the triangle
	
	return perimeter; //returns the perimeter
}

double House::Area() const //same as the perimeter function, but calculating the area instead
{
	double area; //the are is a double becuse the area of an equilateral triangle involves decimals
	int square; //the area of the square will not be a double because the base size will never be a double
	double triangle; //area of the triangle, which will have a decimal
	int tribase = size + 2; //the triangle base is the length of the size + 2, because of the overhang of +1 on each side of the house
		
	square = size * size; //the are of a square is jsut one side squared, or the size multiplied by itself
	triangle = (sqrt(3) / 4) * (tribase * tribase); //this is the formula for the area of an equilateral triangle
	
	area = square + triangle; //after calculating the area of the square and the triangle, add them togethere and you will get the are of the house
	
	return area;	//return the area of the house
}

void House::Grow() //this function actually changes the base size of the house
{
	if(size < 37) //in this case, the house grows +1 every time it is called, as long as the base size does not exceed 37
	{
		size = size + 1;
	}
	
	else size = 37;
}

void House::Shrink() //this function shrinks the base size by -1 each time it is called, as long as the base size is greater than 3
{
	if(size > 3)
	{
		size = size - 1;
	}
	
	else size = 3;
}

void House::SetBorder(char borderChar) //this function takes in a character for the border of the house is it is in the valid ASCII range, the if stements are identical to the ones in the House function
{
	if(int(borderChar) < 33)
	{
		border = 'X';
	}
	
	else if(int(borderChar) > 126)
	{
		border = 'X';
	}
	
	else border = borderChar;
}

void House::SetFill(char fillChar) //same as the border function, but is used instead for the fill characters, as long as the ASCII values are between 33 and 126
{
	if(int(fillChar) < 33)
	{
		fill = '*';
	}
	
	else if(int(fillChar) > 126)
	{
		fill = '*';
	}
	
	else fill = fillChar;
}

void House::Draw() const //the function that actually "draws" the house using loops and if statements
{
	for(int i = size + 1; i > 0; i--) //the function begins with a loops that iterates one more time than the size of the base size, printing the top triangle side length - 1
	{
		for(int j = 0; j < i; j++) //the next for loop prints out the spaces needed to offset the actual house
		{
			cout << " ";	
		}
		
		for(int y = size + 2; y > i; y--) //after the spaces are printed, the first element of the border can be printed
		{
			if(y == size + 2) //if the for loop reaches the end of the house, it prints the final border character
			{
				cout << border << " ";
			}
			
			if(y < size + 1) //otherwise, the fill characters are printed
			{					
				cout << fill << " ";
			}	
		}
		
		if(i < size + 1) //if the 
		{
			cout << border << " "; //prints a border character
		}
		
		cout << "\n"; //after one iteration of line, the new line begins
	}
	
	for(int x = 0; x < size + 2; x++) //this loop takes care of the spot where the triangle and the square meet
	{
		if(x == 0 || x == 1 || x == size || x == size + 1) //if the loop gets to the first, second, second to last, or last character, a border character will be printed becuase that is the same among all of the houses
		{
			cout << border << " ";
		}
		
		else cout << fill << " "; //otherwise, a fill character will be printed 
	}
	
	cout << "\n"; //a newline is printed after this one line
	
	for(int a = 0; a < size - 2; a++) //now the square is being printed, which follows the same format for similar sizes
	{
		cout << "  "; //first, an offset of 2 spaces is includes to compensate for the overhang of the triangle and the space that follows
		
		for(int q = 0; q < size; q++) //loops that prints out the format of each line, a border character, a size amount of fill characters, and another border character at the end
		{
			if(q == 0 || q == size - 1) //an if statement regarding the previous explanation
			{
				cout << border << " ";
			}
			
			else cout << fill << " ";
		}
		
		cout << "\n";
	}
	
	cout << "  ";
	
	for(int z = 0; z < size; z++) //prints the bottom of the house, which is just the border character size amount of times
	{
		cout << border << " ";
	}
	
	cout << "\n";
}

void House::Summary() const //the summary function, which just gives an overview of the data from the houses, and then prints out the final house. Is a const because no variables are being changed
{
	cout << "House width and height base to roof = " << size << " units." << endl;
	cout << "Perimeter of house = " << Perimeter() << " units." << endl;
	cout << "Area of house = " << showpoint << fixed << setprecision(2) << Area() << " units." << endl;
	
	cout << "House looks like: " << endl;
	
	Draw();
}

