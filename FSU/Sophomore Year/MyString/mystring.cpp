/* Name: Marshall Copeland
Date: 10/27/20
Section: #10
Assignment: HW #5
Due Date: 11/04/20
About this project: Create a class called MyStr -- this will be a Str class, which allows creation of Str objects that have flexible sizes, intuitive operator syntax (through operator overloads), and other useful features. Your class will need to maintain the Str internally as an array of characters, and since Str sizes are not fixed, dynamic allocation techniques will need to be used in the class. Your class should maintain any Str ojbect in a valid state at all times, and it should not allow any memory leaks.

All work below was performed by Marshall Copeland */

#include <iostream>
#include <cstring>
#include <cctype>
#include "mystring.h"

using namespace std;

MyString::MyString() //size of one constructor
{
	Size = 1;

	Str = new char[Size];
	
	Str[0] = '\0';

}

MyString::MyString(const char* a) //converts cstrings to our strings
{
	Size = strlen(a) + 1;
	
	Str = new char[Size]; //creates the new array
		
	strncpy(Str, a, Size - 1);
	
	Str[Size - 1] = '\0'; 
}


MyString::MyString(int a) //converts the int into a string
{
	int count = 0;
	int index;
	int copy = a;
	
	while(copy != 0) //makes sure the copy isnt 0
	{
		copy = copy / 10;
		count++;
	}
	
	Size = count + 1;
	
	Str = new char[Size]; //creates the array
	
	Str[Size - 1] = '\0';
	
	for(int x = Size - 2; x >= 0; x--) //algorithm that mods and gets the ints from the back to the front
	{
		index = a % 10;
		Str[x] = index + '0'; 
		a = a / 10;
	}
}


MyString::~MyString() //destructor
{
	delete [] Str;
	Str = 0;
	
}

MyString::MyString(const MyString& a) //copy constructor
{
	Size = a.Size;
    
    Str = new char[Size];	

    for (int x = 0; x < Size; x++)
    {
		Str[x] = a.Str[x];
    }
	
}

MyString& MyString::operator=(const MyString& a) //assingment operator
{
	if(this != &a)
    {
		delete [] Str;
		
        Size = a.Size;
		
        Str = new char[Size]; //creates the new array
		
		for(int x = 0; x < Size; x++)
		{
			Str[x] = a.Str[x]; //copies the array into the new array
		}
   }

   return *this; //retursn the array
}

MyString operator+ (const MyString& a, const MyString& b) //concatenation function
{	
	int Size = strlen(a.Str) + strlen(b.Str) + 1; //adds the sizes together
		
	char * Str = new char[Size]; //creates the new array
	
	strcat(Str, a.Str); //concatenats the two into a new array
	strcat(Str, b.Str);
	
	Str[Size - 1] = '\0';

	return Str; //returns the array
}

MyString& MyString::operator+=(const MyString& a) //concatenation operator
{
	char * temp = new char[Size]; //makes a new array
	
	for(int x = 0; x < Size; x++) //copies over the old array
	{
		temp[x] = Str[x];
	}
	
	delete [] Str;
	
	Size = Size + a.Size;
	
	Str = new char[Size];
	
	strcpy(Str, temp);
	
	strcat(Str, a.Str); //concatenates them
	
	Str[Size] = '\0';

	return *this; //returns new array
}

MyString operator-(const MyString& a, const MyString& b) //i tried with an hour till i had to submit :(
{
	int aCount = 0;
	int bCount = 0;
	int aIndex = 0;
	int bIndex = 0;
	int subStringIndex;
	int tempIndex;
	int sameCount = 0;
	int tempCount = 0;
	int Size = 1;
	
	int checkCount = 0;
	
	char * Str = new char[Size];
	
	while(isprint(a[aIndex]) != 0)
	{
		aCount++;
		aIndex++;
	}
	
	while(isprint(b[bIndex]) != 0)
	{
		bCount++;
		bIndex++;
	}
	
	for(int x = 0; x < a.Size; x++)
	{
		bIndex = 0;
		
		if(a[x] == b[bIndex])
		{
			tempIndex = x;
			
			for(int y = 0; y < bCount; y++)
			{
				if(a[tempIndex] == b[y])
				{
					if(sameCount == 0)
					{
						subStringIndex = tempIndex;
					}
					
					sameCount++;
					tempIndex++;
				}
				
				else
				{
					sameCount = 0;
				}
			}
			
			if(sameCount == bCount)
			{
				if(checkCount > 0)
				{					
					char * temp = new char[Size];
					
					for(int x = 0; x < Size; x++)
					{
						temp[x] = Str[x];
					} 
					
					delete [] Str;
					
					Size = a.Size - b.Size;
					
					char * Str = new char[Size];
					
					for(int x = 0; x < subStringIndex; x++)
					{
						Str[x] = temp[x];
					}
					
					tempCount = subStringIndex;
					
					for(int x = subStringIndex + bCount; x < Size; x++)
					{
						Str[tempCount] = temp[x];
						tempCount++;
					}
				}
				
				else
				{
					Size = a.Size - b.Size;
				
					Str = new char[Size];
				
					for(int x = 0; x < subStringIndex; x++)
					{
						Str[x] = a[x];
					}
					
					tempCount = subStringIndex;
					
					for(int x = subStringIndex + bCount; x < Size; x++)
					{
						Str[tempCount] = a[x];
						tempCount++;
					}
					
					checkCount++;
				}
			}
		}
	}
	
	return Str;
}

char& MyString::operator[] (unsigned int index) //bracket operator
{
	int tempSize = Size; //temporary size variable
	
	if(index > Size - 1) //if the index is bigger than the size this will happen
	{
		char * temp = new char[Size];
	
		for(int x = 0; x < Size; x++)
		{
			temp[x] = Str[x];
		}
	
		delete [] Str;
	
		Size = index + 1;
	
		Str = new char[Size];
		
		strcpy(Str, temp); //copies the old array over
		
		for(int x = tempSize - 1; x < Size - 1; x++)
		{
			Str[x] = ' ';	//adds spaces
		}
	}
	
	return Str[index]; //returns the index
}

const char& MyString::operator[] (unsigned int index) const
{
	if(index > Size - 1)
	{
		return '\0';
	}
	
	else return Str[index]; //returns the index
}


MyString& MyString::insert(unsigned int index, const MyString& s) //insertrion func
{
	int count = 0;
	int sIndex = 0;
	int index2 = index;
	int tempSize = Size;
	
	while(isprint(s[sIndex]) != 0) //gets the size of the passed in word
	{
		sIndex++;
		count++;
	}
	
	sIndex = 0;

	char * temp = new char[Size + count]; //new array
	
	if(index < Size) //if the index passed in is within the range, the word will be inserted
	{
		for(int x = 0; x < index; x++) //copy over the array
		{
			temp[x] = Str[x];
		}
		
		for(int x = index; x < index + count; x++) //adds the word
		{
			temp[x] = s[sIndex];
			sIndex++;
		}
		
		for(int x = index + count; x < Size + count; x++) //continues with the rest
		{
			temp[x] = Str[index2];
			index2++;
		}
		
		delete Str;
		
		Size = Size + count;
		
		char * Str = new char[Size]; //creates the new array
		
		for(int x = 0; x < Size; x++)
		{
			Str[x] = temp[x];
		}
	}
	
	else //otherwise it will be added at the end
	{
		sIndex = 0;
		
		for(int x = 0; x < Size; x++) //same thing as above but the word is inserted at the end of the string
		{
			temp[x] = Str[x];
		}
		
		for(int x = Size; x < Size + count; x++)
		{
			temp[x] = s[sIndex];
			sIndex++;
		}
		
		delete Str;
		
		Size = Size + count;
		
		char * Str = new char[Size];
		
		for(int x = 0; x < Size; x++)
		{
			Str[x] = temp[x];
		}
	}
	
	return *this; //returns the new array
}


int MyString::indexOf(const MyString& s) const //returns the index of the first character of the passed in word if its in the string
{
	int count = 0;
	int sIndex = 0;
	int subStringIndex;
	int tempIndex;
	int sameCount = 0;
	
	bool match = false;

	while(isprint(s[sIndex]) != 0) //gets the size of the passed in word
	{
		sIndex++;
		count++;
	}
	
	for(int x = 0; x < Size; x++) //checks if the word is in the string
	{
		sIndex = 0;
		
		if(Str[x] == s[sIndex])
		{
			tempIndex = x;
			
			for(int y = 0; y < count; y++) //if it is, it checks each letter to eachother
			{
				if(Str[tempIndex] == s[y])
				{
					if(sameCount == 0 && match != true)
					{
						subStringIndex = tempIndex; //if the first character matches, the index is saved
					}
					
					sameCount++;
					tempIndex++;
				}
				
				else
				{
					sameCount = 0;
				}
			}
			
			if(sameCount == count) //if the word matched in the string is equal to the word length that was passed in, it matches
			{
				match = true;
				x = Size - 1;
			}
		}		
	}
	
	if(match == true) //if the word is in the string, it returns the index of the first character in the string
	{
		return subStringIndex;
	}
	
	else return -1; //otherwise it will return -1
}


int MyString::getLength() const //returns the length
{
	return strlen(Str);
}

const char* MyString::getCString() const //returns the cstring
{
	return Str;
}

MyString MyString::substring(unsigned int a, unsigned int b) const //retrns a substring of the original
{
	char * temp = new char[b]; //creates a new array of size b
	int count = 0;
	
	if(a + b > Size) //if the length and the index are bigger than the size
	{
		for(int x = a; x < Size; x++) //it will go from the index to the end of the string
		{
			temp[count] = Str[x];
			count++;
		}
	}
	
	else //otherwise it will start at the index and be "b" length
	{
		for(int x = a; x < a + b; x++)
		{
			temp[count] = Str[x];
			count++;
		}
	}
	
	return temp; //returns the array
}

MyString MyString::substring(unsigned int a) const //one parameter substring
{
	char * temp = new char[Size - a]; //this one just runs form the index tothe end of the string
	int count = 0;
	
	for(int x = a; x < Size; x++)
	{
		temp[count] = Str[x];
		count++;
	}
	
	return temp; //returns the new string
}


ostream& operator<< (ostream& a, const MyString& b) //extraction operator
{
	a << b.Str;
	
	return a;
}

istream& operator>> (istream& a, MyString& b) //insertion operator
{
	b.Size = 1; //makes sure there arent spaces
	
	delete [] b.Str;
	
	b.Str = new char[b.Size];
	
	b.Index = 0;
	
	while(a.peek() == ' ')
	{
		a.ignore();
	}
		
	while(a.peek() != ' ')
	{
		b.Size++;
		b.addCharacter(a.get()); //calls a fucntion that adds characters
		b.Index++;
		
	}
	
	return a; //reutrns the new array
}
	
istream& getline (istream& a, MyString& b) //reads everythign up to newlines
{	
	b.Size = 1;
	
	delete [] b.Str;
	
	b.Str = new char[b.Size];
	
	b.Index = 0;
	
	while(a.peek() != '\n')
	{
		b.Size++;
		b.addCharacter(a.get());
		b.Index++;
	}
	
	if(a.peek() == '\n')
	{
		a.ignore();
	}
}

istream& getline (istream& a, MyString& b, char delim) //reads everythign up to the delimeter passed in
{
	b.Size = 1;
	
	delete [] b.Str;
	
	b.Str = new char[b.Size];
	
	b.Index = 0;
	
	while(a.peek() != delim)
	{
		b.Size++;
		b.addCharacter(a.get());
		b.Index++;
	}
	
	if(a.peek() == delim)
	{
		a.ignore();
	}
}
	
bool operator< (const MyString& a, const MyString& b)
{	
	if(strcmp(a.Str , b.Str) < 0)
	{
		return true;
	}
	
	else return false;
}
	
bool operator> (const MyString& a, const MyString& b)
{
	if(strcmp(a.Str , b.Str) > 0)
	{
		return true;
	}
	
	else return false;
}
	
bool operator<=(const MyString& a, const MyString& b)
{
	if(strcmp(a.Str , b.Str) < 0 || strcmp(a.Str , b.Str) == 0)
	{
		return true;
	}
	
	else return false;
}

bool operator>=(const MyString& a, const MyString& b)
{
	if(strcmp(a.Str , b.Str) > 0 || strcmp(a.Str , b.Str) == 0)
	{
		return true;
	}
	
	else return false;
}

bool operator==(const MyString& a, const MyString& b)
{
	if(strcmp(a.Str , b.Str) == 0)
	{
		return true;
	}
	
	else return false;
}

bool operator!=(const MyString& a, const MyString& b)
{
	if(strcmp(a.Str , b.Str) != 0)
	{
		return true;
	}
	
	else return false;
}

void MyString::addCharacter(char a) //function that adds the charactrs and manages the size of the asrray one character at a time
{
	char * temp = new char[Size];
	
	for(int x = 0; x < Size; x++)
	{
		temp[x] = Str[x];
	}
	
	delete [] Str;
	
	Str = temp;

	Str[Index] = a;
	
	Str[Size - 1] = '\0';
}

