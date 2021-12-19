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
#include "data.h"

using namespace std;

Student::Student(const char * first, const char * last, const char * course) //student constructor
{	
	firstName = new char[strlen(first)]; //stores the first name
	
	strcpy(firstName, first); 
	
	lastName = new char[strlen(last)]; //stores the last name
	
	strcpy(lastName, last);
	
	Course = new char[strlen(course)]; //stores the course
	
	strcpy(Course, course);
}

char * Student::FirstNameGetter() const //retrieves the first name
{
	return firstName;
}

char * Student::LastNameGetter() const //retrieves the last name
{
	return lastName;
}

char * Student::CourseGetter() const //retrieves the course
{
	return Course;
}

English::English(const char * first, const char * last, const char * course, const int paper, const int mid, const int exam) : Student(first, last, course) //stores the grade info from an english student
{
	termPaper = paper;
	midterm = mid;
	finalExam = exam;
}

double English::GradeReport() //calculates the english students grade
{	
	finalGrade = (termPaper * .25) + (midterm * .35) + (finalExam * .4);
	
	return finalGrade; //returns the final grade
}

int English::FinalExam() //final exam getter for the english students exam
{
	return finalExam;
}

History::History(const char * first, const char * last, const char * course, const int att, const int proj, const int mid, const int exam) : Student(first, last, course) //stores the grade info from an english student
{
	attendance = att;
	project = proj;
	midterm = mid;
	finalExam = exam;
}

double History::GradeReport() //calculates the englsih students grade
{	
	finalGrade = (attendance * .1) + (project * .3) + (midterm * .3) + (finalExam * .3);
	
	return finalGrade; //returns the final grade
}

int History::FinalExam() //final exam getter for the history students exam
{
	return finalExam;
}

Math::Math(const char * first, const char * last, const char * course, const int q1, const int q2, const int q3, const int q4, const int q5, const int t1, const int t2, const int exam) : Student(first, last, course) //stores the grade info from an english student
{	
	quiz1 = q1;
	quiz2 = q2;
	quiz3 = q3;
	quiz4 = q4;
	quiz5 = q5;
	
	test1 = t1;
	test2 = t2;
	
	finalExam = exam;
}

double Math::GradeReport() //calculates the englsih students grade
{
	quizAverage = (quiz1 + quiz2 + quiz3 + quiz4 + quiz5) / 5; //calculates the quiz average first
	 
	finalGrade = (quizAverage * .2) + (test1 * .25) + (test2 * .25) + (finalExam * .3);
	
	return finalGrade; //returns the final grade
}

int Math::FinalExam() //final exam getter for the math students exam
{
	return finalExam;
}
