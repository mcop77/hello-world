/* Name: Marshall Copeland
Date: 11/06/20
Section: #10
Assignment: HW #6
Due Date: 11/18/20
About this project: To gain experience with base and derived classes, virtual functions, and using applications of polymorphism. Also, to gain further practice with file I/O, as well as dynamic allocation. You will design a set of classes for storing student information, along with a class that will manage a list of students. Data can be imported from files for storage in the list, and summary reports with computed final grades will be printed to output files.

All work below was performed by Marshall Copeland */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include <string>
#include "studentlist.h" //only need to include the studentlist.h because data.h is included in it

using namespace std;

int main() //main function that calls the other functions
{
	StudentList List; //new studentlist object called list
	
	char menuChoice; //menu choice char that the user will type their response into
	char fileName[31]; //max length of the file name
	
	cout << "\t\t *** Student List menu ***" << endl; //menu
	cout << "\tI" << "\tImport students from a file" << endl;
	cout << "\tS" << "\tShow student list (brief)" << endl;
	cout << "\tE" << "\tExport a grade report (to file)" << endl;
	cout << "\tO" << "\tSort student list" << endl;
	cout << "\tM" << "\tShow this Menu" << endl;
	cout << "\tQ" << "\tQuit Program" << endl;
	cout << "\n";
	
	do { //do while that cycles through as long as the user doenst exit
		cout << "> "; //arrow for input
		cin >> menuChoice; //takes in the user choice
		
		if(menuChoice == 'I' || menuChoice == 'i') //if the user enters an I or i
		{
			cout << "Enter a filename: "; //asks them for a file
			cin >> fileName; //takes in a file
			
			if(List.ImportFile(fileName) == false) //calls import function
			{
				cout << "File is unable to be opened" << endl; //if it cant be opened
			}
		}
		
		else if(menuChoice == 'S' || menuChoice == 's') //if the user enters an S or s
		{
			List.ShowList(); //calls show function
		}
		
		else if(menuChoice == 'E' || menuChoice == 'e') //if the user enters an E or e
		{
			cout << "Enter a filename: "; //type in a file name
			cin >> fileName; //takes in a file name
			
			if(List.CreateReportFile(fileName) == false) //calls the export function
			{
				cout << "File is unable to be opened" << endl;
			}
		}
		
		else if(menuChoice == 'O' || menuChoice == 'o') //if the user enters an O or o
		{
			List.SortList();
		}
		
		else if(menuChoice == 'M' || menuChoice == 'm') //prints out the menu if the user enters an M or m
		{
			cout << "\t\t *** Student List menu ***" << endl;
			cout << "\tI" << "\tImport students from a file" << endl;
			cout << "\tS" << "\tShow student list (brief)" << endl;
			cout << "\tE" << "\tExport a grade report (to file)" << endl;
			cout << "\tO" << "\tSort student list" << endl;
			cout << "\tM" << "\tShow this Menu" << endl;
			cout << "\tQ" << "\tQuit Program" << endl;
		}
		
		cout << "\n"; //new line after the menu
		
	} while(menuChoice != 'Q' && menuChoice != 'q'); //loops until the user types Q or q
	
	cout << "Goodbye!" << endl; //at the end it prints Goodbye!
	
	return 0;
}
