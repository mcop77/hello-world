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
#include "studentlist.h"

using namespace std;


StudentList::StudentList() //student list constructor
{
	countA = 0; //keeps track of how many of each grade there are
	countB = 0;
	countC = 0;
	countD = 0;
	countF = 0;
	
	Size = 0; //size of the array is 0
	
	List = new Student*[Size]; //creates a new array of students
}

StudentList::~StudentList() //destructor
{
	for(int x = 0; x < Size; x++)
	{
		delete List[x]; //deletes each individual element in the array
	}
	
	delete [] List; //deletes the array
	
	
}

bool StudentList::ImportFile(const char* filename) //imports file
{
	int tempSize = 0; //temp size variable that allwos another size of an array to be added
	
	char firstname[21]; //local variables that store the names and course
	char lastname[21];
	char course[8];
	
	const char english[8] = "English"; //char arrays that help check the course 
	const char history[8] = "History";
	const char math[5] = "Math";
	
	if(Size == 0) //if the array is new, the amount of each type of student is 0
	{
		englishSize = 0;
		historySize = 0;
		mathSize = 0;
	}

	ifstream file; //takes in a new file

	file.open(filename); //opens the new file

	if(Size == 0) //if the array is new
	{
		file >> tempSize; //the first element of the file is read in as the size
		
		Size = tempSize; //the Size is now the size that was read in
		List = new Student*[Size]; //creates a new array of the new Size
				
		for(int x = 0; x < Size; x++) //reads in the names and courses
		{
			file.ignore();
			file.getline(lastname, 21, ','); //reads in the last name
			file.ignore();
			file.getline(firstname, 21, '\n'); //reads in the first name
			file >> course; //reads in the course
		
			if(strcmp(course, english) == 0) //if the course is english
			{
				int termPaper; //creates new local variables to take in grade information
				int midterm;
				int finalExam;
				
				file >> termPaper >> midterm >> finalExam;
				
				List[x] = new English(firstname, lastname, course, termPaper, midterm, finalExam); //makes a new english student with the information form the file
				englishSize++; //the number of english students increases each time 
			}
			
			else if(strcmp(course, history) == 0) //same thing as above but for history students 
			{
				int attendance; //local variables
				int project;
				int midterm;
				int finalExam;
				
				file >> attendance >> project >> midterm >> finalExam;
				
				List[x] = new History(firstname, lastname, course, attendance, project, midterm, finalExam); //makes the new history student
				historySize++;
			}
			
			else if(strcmp(course, math) == 0) //same thing as above but for math students
			{
				int quiz1; //math grade variables
				int quiz2;
				int quiz3;
				int quiz4;
				int quiz5;
				int test1;
				int test2;
				int finalExam;
				
				file >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> quiz5 >> test1 >> test2 >> finalExam;
						
				List[x] = new Math(firstname, lastname, course, quiz1, quiz2, quiz3, quiz4, quiz5, test1, test2, finalExam); //new math student
				mathSize++;
			}
		}
	}

	else //if the array alrerady has students in it
	{
		file >> tempSize; //reads in the size
			
		Size = Size + tempSize; //adds the new size to the old size
		
		Student ** temp = new Student*[Size]; //makes a temp array to copy over the students
		
		for(int x = 0; x < Size - tempSize; x++) 
		{
			temp[x] = List[x]; //copies the old array into the temp
		}
		
		delete [] List; //deletes old array
		
		List = temp; //List is now the new arrays name
		
		for(int x = Size - tempSize; x < Size; x++) //now same thing as the if statement above
		{
			file.ignore();
			file.getline(lastname, 21, ','); //reads in student info from the file
			file.ignore();
			file.getline(firstname, 21, '\n');
			file >> course;
		
			if(strcmp(course, english) == 0) //if they are an english student
			{
				int termPaper;
				int midterm;
				int finalExam;
				
				//declare ints
				file >> termPaper >> midterm >> finalExam;
				
				List[x] = new English(firstname, lastname, course, termPaper, midterm, finalExam);
				englishSize++;
			}
			
			else if(strcmp(course, history) == 0) //history student
			{
				int attendance;
				int project;
				int midterm;
				int finalExam;
				
				file >> attendance >> project >> midterm >> finalExam;
				
				List[x] = new History(firstname, lastname, course, attendance, project, midterm, finalExam);
				historySize++;
			}
			
			else if(strcmp(course, math) == 0) //math student
			{
				int quiz1;
				int quiz2;
				int quiz3;
				int quiz4;
				int quiz5;
				int test1;
				int test2;
				int finalExam;
				
				file >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> quiz5 >> test1 >> test2 >> finalExam;
				
				List[x] = new Math(firstname, lastname, course, quiz1, quiz2, quiz3, quiz4, quiz5, test1, test2, finalExam);
				mathSize++;
			}
		}	
	}	
	
	if(!file) //if the file wasnt opened properly
	{
		return false;
	}
	
	else return true;
	
	file.close(); //closes the file
}

bool StudentList::CreateReportFile(const char* filename) //creates a file to be exported
{
	int firstSize; //ints that help with formatting the spacing in the file
	int lastSize;
	int fullNameSize;
	int courseSize;
	
	int maxSize = 40; //max size that helps align everything, not the actual max size of the added string lengths
	
	const char english[8] = "English"; //as seen above, helps see what course the student is in
	const char history[8] = "History";
	const char math[5] = "Math";
			
	ofstream file; //takes in a new file

	file.open(filename); //opens the file under the passed in name
	
	file << "Student Grade Summary" << endl; //file header
	file << "---------------------" << endl;
	
	if(englishSize > 0) //if there is at least one english student
	{
		file << "\n";
		file << "ENGLISH CLASS" << endl; //english category header
		file << "\n";
		file << "Student" << "\t\t\t\t\t\t\t\t\tFinal\tFinal\tLetter" << endl;
		file << "Name" << "\t\t\t\t\t\t\t\t\tExam\tAvg\t\tGrade" << endl;
		file << "----------------------------------------------------------------------" << endl;
		
		for(int x = 0; x < Size; x++) //prints out all the english students and their info
		{
			if(strcmp(List[x]->CourseGetter(), english) == 0) //makes sure they are an english student
			{
				file << List[x]->FirstNameGetter(); //prints their first name
				firstSize = strlen(List[x]->FirstNameGetter()); //gets the length of the first name

				file << " "; //prints a space between the first and last name

				file << List[x]->LastNameGetter(); //prints the last name
				lastSize = strlen(List[x]->LastNameGetter()); //gets the length of the last name
				
				fullNameSize = firstSize + lastSize + 1; //adds the length of the first and last name as well as the 1 for the space
				
				for(int y = 0; y < maxSize - fullNameSize; y++) //prints out the amount of spaces left out of maxSize that the name didnt take up
				{
					file << " ";
				}
				
				file << List[x]->FinalExam() << "\t\t" << showpoint << fixed << setprecision(2) << List[x]->GradeReport() << "\t"; //makes sure there are two digits after the decimal point
				
				if(List[x]->GradeReport() >= 90.0) //if the grade is an A
				{
					file << "A" << endl;
					countA++;
				}
				
				else if(List[x]->GradeReport() >= 80.0) //if the grade is an A
				{
					file << "B" << endl;
					countB++;
				}
				
				else if(List[x]->GradeReport() >= 70.0) //if the grade is an A
				{
					file << "C" << endl;
					countC++;
				}
				
				else if(List[x]->GradeReport() >= 60.0) //if the grade is an A
				{
					file << "D" << endl;
					countD++;
				}
				
				else //otherwise it is an F
				{
					file << "F" << endl;
					countF++;
				}
			}
		}
	}
	
	if(historySize > 0) //same thing as above but for history students, im not commenting cuz its literally the same
	{
		file << "\n";
		file << "HISTORY CLASS" << endl;
		file << "\n";
		file << "Student" << "\t\t\t\t\t\t\t\t\tFinal\tFinal\tLetter" << endl;
		file << "Name" << "\t\t\t\t\t\t\t\t\tExam\tAvg\t\tGrade" << endl;
		file << "----------------------------------------------------------------------" << endl;
		
		for(int x = 0; x < Size; x++)
		{
			if(strcmp(List[x]->CourseGetter(), history) == 0)
			{
				file << List[x]->FirstNameGetter();
				firstSize = strlen(List[x]->FirstNameGetter());

				file << " ";

				file << List[x]->LastNameGetter();
				lastSize = strlen(List[x]->LastNameGetter());
				
				fullNameSize = firstSize + lastSize + 1;
				
				for(int y = 0; y < maxSize - fullNameSize; y++)
				{
					file << " ";
				}
				
				file << List[x]->FinalExam() << "\t\t" << showpoint << fixed << setprecision(2) << List[x]->GradeReport() << "\t";
				
				if(List[x]->GradeReport() >= 90.0)
				{
					file << "A" << endl;
					countA++;
				}
				
				else if(List[x]->GradeReport() >= 80.0)
				{
					file << "B" << endl;
					countB++;
				}
				
				else if(List[x]->GradeReport() >= 70.0)
				{
					file << "C" << endl;
					countC++;
				}
				
				else if(List[x]->GradeReport() >= 60.0)
				{
					file << "D" << endl;
					countD++;
				}
				
				else
				{
					file << "F" << endl;
					countF++;
				}
			}
		}
	}
	
	if(mathSize > 0) //same thing as english and history but for math students
	{
		file << "\n";
		file << "MATH CLASS" << endl;
		file << "\n";
		file << "Student" << "\t\t\t\t\t\t\t\t\tFinal\tFinal\tLetter" << endl;
		file << "Name" << "\t\t\t\t\t\t\t\t\tExam\tAvg\t\tGrade" << endl;
		file << "----------------------------------------------------------------------" << endl;
		
		for(int x = 0; x < Size; x++)
		{
			if(strcmp(List[x]->CourseGetter(), math) == 0)
			{
				file << List[x]->FirstNameGetter();
				firstSize = strlen(List[x]->FirstNameGetter());

				file << " ";

				file << List[x]->LastNameGetter();
				lastSize = strlen(List[x]->LastNameGetter());
				
				fullNameSize = firstSize + lastSize + 1;
				
				for(int y = 0; y < maxSize - fullNameSize; y++)
				{
					file << " ";
				}
				
				file << List[x]->FinalExam() << "\t\t" << showpoint << fixed << setprecision(2) << List[x]->GradeReport() << "\t";
				
				if(List[x]->GradeReport() >= 90.0)
				{
					file << "A" << endl;
					countA++;
				}
				
				else if(List[x]->GradeReport() >= 80.0)
				{
					file << "B" << endl;
					countB++;
				}
				
				else if(List[x]->GradeReport() >= 70.0)
				{
					file << "C" << endl;
					countC++;
				}
				
				else if(List[x]->GradeReport() >= 60.0)
				{
					file << "D" << endl;
					countD++;
				}
				
				else
				{
					file << "F" << endl;
					countF++;
				}
			}
		}
	}
	
	file << "\n"; //footer formatting
	file << "\n";
	
	file << "OVERALL GRADE DISTRIBUTION" << endl; //grade distribution chart
	file << "\n";
	file << "A:\t" << countA << endl; //prints the amount of A's
	file << "B:\t" << countB << endl; //prints the amount of B's
	file << "C:\t" << countC << endl; //prints the amount of C's
	file << "D:\t" << countD << endl; //prints the amount of D's
	file << "F:\t" << countF << endl; //prints the amount of F's

	if(!file) //if the fie doesnt open properly
	{
		return false;
	}
	
	else return true;
	
	file.close(); //closes the file
}

void StudentList::ShowList() const
{
	int firstSize; //first name length variable
	int lastSize; //first name length variable
	int courseSize; //course length variable
	
	int maxSize = 24; //max length that keeps everything aligned, isnt acutally the max size of the info
	
	cout << "Last" << "\t\t\tFirst" << "\t\t\tCourse" << endl; //header info
	cout << "\n";
	
	for(int x = 0; x < Size; x++) //for each student in the array
	{
		cout << List[x]->LastNameGetter(); //prints the last name
		lastSize = strlen(List[x]->LastNameGetter()); //gets the length of the last name
		
		for(int y = 0; y < maxSize - lastSize; y++) //prints out the number of spaces that the name doesnt take up form the max size to even it out
		{
			cout << " ";
		}

		cout << List[x]->FirstNameGetter(); //prints the first name
		firstSize = strlen(List[x]->FirstNameGetter()); //gets the length of the first name
		
		for(int y = 0; y < maxSize - firstSize; y++) //prints out the number of spaces that the name doesnt take up form the max size to even it out
		{
			cout << " ";
		}

		cout << List[x]->CourseGetter() << endl; //prints out the course that the student is in
	}	
}


void StudentList::SortList()
{
	int count;
	bool greater;
	bool lesser;
	bool equal;
	
	int lastNameLength;
	int firstNameLength;
	
	int nextLastNameLength;
	int nextFirstNameLength;
	
	for(int x = 0; x < Size; x++)
	{
		for(int y = 0; y < Size; y++)
		{
			lastNameLength = strlen(List[y]->LastNameGetter());
			firstNameLength = strlen(List[y]->FirstNameGetter());
			
			nextLastNameLength = strlen(List[y + 1]->LastNameGetter());
			nextFirstNameLength = strlen(List[y + 1]->FirstNameGetter());
			
			if(lastNameLength < nextLastNameLength)
			{
				int j = 0; 
				equal = true;
				
				while(equal == true)
				{
					if(List[y]->LastNameGetter()[j] < List[y + 1]->LastNameGetter()[j] && ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) - 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) != (int(List[y + 1]->LastNameGetter()[j]) + 32))) || ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]) - 32)))
					{
						lesser = true;
						equal = false;
					}
					
					else if(List[y]->LastNameGetter()[j] > List[y + 1]->LastNameGetter()[j] && ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) - 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) != (int(List[y + 1]->LastNameGetter()[j]) + 32))) || ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]) - 32)))
					{
						greater = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j]) + 32) == (int(List[y + 1]->LastNameGetter()[j])))
					{
						lesser = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j]) - 32) == (int(List[y + 1]->LastNameGetter()[j])))
					{
						greater = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j])) == (int(List[y + 1]->LastNameGetter()[j]) + 32))
					{
						lesser = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j])) == (int(List[y + 1]->LastNameGetter()[j]) - 32))
					{
						greater = true;
						equal = false;
					}
					
					else if(j == lastNameLength)
					{
						lesser = true;
						equal= false;
					}
					
					else j++;
				}
			}
			
			
			
			else if(lastNameLength > nextLastNameLength)
			{
				int j = 0; 
				equal = true;
				
				while(equal == true)
				{
					if(List[y]->LastNameGetter()[j] < List[y + 1]->LastNameGetter()[j] && ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) - 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) != (int(List[y + 1]->LastNameGetter()[j]) + 32))) || ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]) - 32)))
					{
						lesser = true;
						equal = false;
						
					}
					
					else if(List[y]->LastNameGetter()[j] > List[y + 1]->LastNameGetter()[j] && ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) - 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) != (int(List[y + 1]->LastNameGetter()[j]) + 32))) || ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]) - 32)))
					{
						greater = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j]) + 32) == (int(List[y + 1]->LastNameGetter()[j])))
					{
						lesser = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j]) - 32) == (int(List[y + 1]->LastNameGetter()[j])))
					{
						greater = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j])) == (int(List[y + 1]->LastNameGetter()[j]) + 32))
					{
						lesser = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j])) == (int(List[y + 1]->LastNameGetter()[j]) - 32))
					{
						greater = true;
						equal = false;
					}
					
					else if(j == nextFirstNameLength)
					{
						lesser = true;
						equal= false;
					}
					
					else j++;
				}
			}
			
			
			
			
			else if(lastNameLength < nextLastNameLength)
			{
				int j = 0; 
				equal = true;
				
				while(equal == true)
				{
					if(List[y]->LastNameGetter()[j] < List[y + 1]->LastNameGetter()[j] && ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) - 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) != (int(List[y + 1]->LastNameGetter()[j]) + 32))) || ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]) - 32)))
					{
						lesser = true;
						equal = false;
						
					}
					
					else if(List[y]->LastNameGetter()[j] > List[y + 1]->LastNameGetter()[j] && ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) - 32) != (int(List[y + 1]->LastNameGetter()[j]))) || ((int(List[y]->LastNameGetter()[j]) != (int(List[y + 1]->LastNameGetter()[j]) + 32))) || ((int(List[y]->LastNameGetter()[j]) + 32) != (int(List[y + 1]->LastNameGetter()[j]) - 32)))
					{
						greater = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j]) + 32) == (int(List[y + 1]->LastNameGetter()[j])))
					{
						lesser = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j]) - 32) == (int(List[y + 1]->LastNameGetter()[j])))
					{
						greater = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j])) == (int(List[y + 1]->LastNameGetter()[j]) + 32))
					{
						lesser = true;
						equal = false;
					}
					
					else if((int(List[y]->LastNameGetter()[j])) == (int(List[y + 1]->LastNameGetter()[j]) - 32))
					{
						greater = true;
						equal = false;
					}
					
					else if(j == lastNameLength)
					{
//-------------------------------------------------------------------------------------------------
						if(firstNameLength < nextFirstNameLength)
						{
							int j = 0; 
							equal = true;
							
							while(equal == true)
							{
								if(List[y]->FirstNameGetter()[j] < List[y + 1]->FirstNameGetter()[j] && ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) - 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) != (int(List[y + 1]->FirstNameGetter()[j]) + 32))) || ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]) - 32)))
								{
									lesser = true;
									equal = false;
								}
								
								else if(List[y]->FirstNameGetter()[j] > List[y + 1]->FirstNameGetter()[j] && ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) - 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) != (int(List[y + 1]->FirstNameGetter()[j]) + 32))) || ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]) - 32)))
								{
									greater = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j]) + 32) == (int(List[y + 1]->FirstNameGetter()[j])))
								{
									lesser = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j]) - 32) == (int(List[y + 1]->FirstNameGetter()[j])))
								{
									greater = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j])) == (int(List[y + 1]->FirstNameGetter()[j]) + 32))
								{
									lesser = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j])) == (int(List[y + 1]->FirstNameGetter()[j]) - 32))
								{
									greater = true;
									equal = false;
								}
								
								else if(j == firstNameLength)
								{
									lesser = true;
									equal= false;
								}
								
								else j++;
							}
						}
						
						
						
						else if(firstNameLength > nextFirstNameLength)
						{
							int j = 0; 
							equal = true;
							
							while(equal == true)
							{
								if(List[y]->FirstNameGetter()[j] < List[y + 1]->FirstNameGetter()[j] && ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) - 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) != (int(List[y + 1]->FirstNameGetter()[j]) + 32))) || ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]) - 32)))
								{
									lesser = true;
									equal = false;
									
								}
								
								else if(List[y]->FirstNameGetter()[j] > List[y + 1]->FirstNameGetter()[j] && ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) - 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) != (int(List[y + 1]->FirstNameGetter()[j]) + 32))) || ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]) - 32)))
								{
									greater = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j]) + 32) == (int(List[y + 1]->FirstNameGetter()[j])))
								{
									lesser = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j]) - 32) == (int(List[y + 1]->FirstNameGetter()[j])))
								{
									greater = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j])) == (int(List[y + 1]->FirstNameGetter()[j]) + 32))
								{
									lesser = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j])) == (int(List[y + 1]->FirstNameGetter()[j]) - 32))
								{
									greater = true;
									equal = false;
								}
								
								else if(j == nextFirstNameLength)
								{
									lesser = true;
									equal= false;
								}
								
								else j++;
							}
						}
						
						
						
						
						else if(firstNameLength < nextFirstNameLength)
						{
							int j = 0; 
							equal = true;
							
							while(equal == true)
							{
								if(List[y]->FirstNameGetter()[j] < List[y + 1]->FirstNameGetter()[j] && ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) - 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) != (int(List[y + 1]->FirstNameGetter()[j]) + 32))) || ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]) - 32)))
								{
									lesser = true;
									equal = false;
									
								}
								
								else if(List[y]->FirstNameGetter()[j] > List[y + 1]->FirstNameGetter()[j] && ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) - 32) != (int(List[y + 1]->FirstNameGetter()[j]))) || ((int(List[y]->FirstNameGetter()[j]) != (int(List[y + 1]->FirstNameGetter()[j]) + 32))) || ((int(List[y]->FirstNameGetter()[j]) + 32) != (int(List[y + 1]->FirstNameGetter()[j]) - 32)))
								{
									greater = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j]) + 32) == (int(List[y + 1]->FirstNameGetter()[j])))
								{
									lesser = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j]) - 32) == (int(List[y + 1]->FirstNameGetter()[j])))
								{
									greater = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j])) == (int(List[y + 1]->FirstNameGetter()[j]) + 32))
								{
									lesser = true;
									equal = false;
								}
								
								else if((int(List[y]->FirstNameGetter()[j])) == (int(List[y + 1]->FirstNameGetter()[j]) - 32))
								{
									greater = true;
									equal = false;
								}
					
								else if(j == firstNameLength)
								{
									cout << "Names are identical" << endl;
								}
					
								else j++;
							}
						}
					}
				}
			}
			
			cout << "test" << endl;
			if(greater == true)
			{
				swap(List[y], List[y + 1]);
			}		
			
			cout << "test2" << endl;
		
		}
	}
	
}

