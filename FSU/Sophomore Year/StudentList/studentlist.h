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
#include "data.h" //includes the stuff from the student data header


class StudentList //class studentlist
{
	public:
		StudentList();		// starts out empty
		~StudentList();		// cleanup (destructor)

		bool ImportFile(const char* filename); //imports the file
		bool CreateReportFile(const char* filename); //exports the file
		void ShowList() const;	// print basic list data
		
		void SortList();
	
	private:
		Student ** List; //double pointer, pointer to an array of pointers
		
		Student ** temp;
		
		int Size; //size of the array
		
		int englishSize; //number of english students
		int historySize; //number of history students
		int mathSize; //number of math students
		
		int countA; //counts how many of each grade there are
		int countB;
		int countC;
		int countD;
		int countF;
		
};
