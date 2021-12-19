/* Name: Marshall Copeland
Date: 11/20/20
Section: #10
Assignment: HW #7
Due Date: 12/04/20
About this project: Write a program that uses a stack object to determine if a string is a palindrome (i.e. the string is spelled identically backward and forward). The program should ignore spaces and punctuation.

All work below was performed by Marshall Copeland */

#include <iostream>
#include <cstring> 
#include <cctype>
#include "stack.h"

using namespace std;

int main()
{
	Stack <char> stackList; //creates a stack of type char
	
	char String[100];     //c string of length 100
	char tempString[100]; //temp c string of size 100
	char Check[100];      //check c string of size 100
		
	cout << "Please enter a string:" << endl; //user enters a string
	cout << "> ";
	
	cin.getline(String, 100); 		//what the user types is stored in the first string
	
	int length = strlen(String);    //keeps track of the size of the string the user entered
	int count = 0;					//count variable
	int lengthCount = 0;			//length count variable
	
	for(int x = 0; x < length; x++) //for loop cycles throught th c string
	{
		if(isalpha(String[x]) != 0 && isspace(String[x]) == 0) //if the currrent char in the string isalpha and not a space
		{
			tempString[count] = String[x]; //the char is stored in the temp string
			count++; 					   //count is incremented
		}
	}
	
	lengthCount = count; 				//length count is now the same size as the string with no spaces and only chars
	
	for(int x = 0; x < lengthCount; x++)	//loop that converts the tempstring chars into uppercase so it is easier to compare
	{
		if(islower(tempString[x]) != 0) //if lowercase
		{
			tempString[x] = toupper(tempString[x]); //turns into uppercase
		}
			
		stackList.push(tempString[x]); //char is then pushed into the stack
	}
	
	for(int x = 0; x < lengthCount; x++) //char is then pushed out of the stack
	{
		stackList.pop(Check[x]); //and inserted into the check string
	}
	
	Check[lengthCount] = '\0'; //inserts null char at the end
	
	if(strcmp(tempString, Check) == 0 && lengthCount > 0) //compares the temp string before and after it was pused and popped in the stack
	{
		cout << "\""; //if they are the same the original string is printed
		
		for(int x = 0; x < length; x++)
		{
			cout << String[x];
		}
		
		cout << "\"" << " IS a palindrome" << endl; //and it says that it IS a palindrome
	}
	
	else //if the check string and the temp string are not the same, the sentence/word is not a palindrome
	{
		cout << "\"";
		
		for(int x = 0; x < length; x++)
		{
			cout << String[x];
		}
		
		cout << "\"" << " is NOT a palindrome" << endl; //prints string and says its NOT a palindrome
	}

	return 0; //end of program
}


