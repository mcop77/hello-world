/* Name: Marshall Copeland
Date: 10/27/20
Section: #10
Assignment: HW #5
Due Date: 11/04/20
About this project: Create a class called MyString -- this will be a string class, which allows creation of string objects that have flexible sizes, intuitive operator syntax (through operator overloads), and other useful features. Your class will need to maintain the string internally as an array of characters, and since string sizes are not fixed, dynamic allocation techniques will need to be used in the class. Your class should maintain any string ojbect in a valid state at all times, and it should not allow any memory leaks.

All work below was performed by Marshall Copeland */

#include <iostream>
using namespace std;

class MyString
{
	 friend ostream& operator<< (ostream& a, const MyString& b);
	 friend istream& operator>> (istream& a, MyString& b);
	 friend istream& getline (istream& a, MyString& b);
	 friend istream& getline (istream& a, MyString& b, char delim);

	 friend MyString operator+ (const MyString& , const MyString& );
	 
	 friend MyString operator-(const MyString& a, const MyString& b);

	 friend bool operator< (const MyString& a, const MyString& b);
	 friend bool operator> (const MyString& a, const MyString& b);
	 friend bool operator<=(const MyString& a, const MyString& b);
	 friend bool operator>=(const MyString& a, const MyString& b);
	 friend bool operator==(const MyString& a, const MyString& b);
	 friend bool operator!=(const MyString& a, const MyString& b);

	 public:
	 MyString();				// empty string
	 MyString(const char* a);		// conversion from c-string
	 MyString(int a);			// conversion from int
	 ~MyString();				// destructor
	 MyString(const MyString& a);		// copy constructor
	 MyString& operator=(const MyString& a);   // assignment operator

	 MyString& operator+=(const MyString& a);  // concatenation/assignment
	 
	

	 // bracket operators to access char positions
	 char& operator[] (unsigned int index);
	 const char& operator[] (unsigned int index) const;

	 // insert s into the string at position "index"
	 MyString& insert(unsigned int index, const MyString& s);

	 // find index of the first occurrence of s inside the string
	 //  return the index, or -1 if not found
	 int indexOf(const MyString& s) const;
	  
	 int getLength() const;		// return string length
	 const char* getCString() const;	// return c-string equiv

	 MyString substring(unsigned int a, unsigned int b) const;
	 MyString substring(unsigned int a) const;

	 private:
	 int Size;
	 int CurrentSize;
	 int MaxSize;
	  
	 int Index;
	 char* Str;
	 
	 void addCharacter(char a);
	 

	  // declare your member data here


};
