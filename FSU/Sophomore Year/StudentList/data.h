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


class Student //class student, individual student information
{
	public:
		virtual double GradeReport() = 0; //pure virtual function that gets the final grades
		
		virtual int FinalExam() = 0; //pure virtual function that gets the final exams
		
		char * FirstNameGetter() const; //gets the first name of the student
		char * LastNameGetter() const; //gets the first name of the student
		char * CourseGetter() const; //gets the first name of the student
		
		Student(const char * first, const char * last, const char * course); //student constructor
		
	private:
		char * firstName; //first name c string
		
		char * lastName; //last name c string
		
		char * Course; //course c string
	
};

class English: public Student //english student is a child of student
{
	public:
		English(const char * first, const char * last, const char * course, const int paper, const int mid, const int exam); //english construcotr with parameters
		double GradeReport(); //grade report function
		int FinalExam(); //final exam function
	
	private:
		int termPaper; //specific grades that the english student has
		int midterm;
		int finalExam;
		
		double finalGrade; //englsih student final grade
	
};

class History: public Student //same as above but for a history student
{
	public:
		History(const char * first, const char * last, const char * course, const int att, const int proj, const int mid, const int exam);
		double GradeReport();
		int FinalExam();
	
	private:
		int attendance; //different grades but same idea
		int project;
		int midterm;
		int finalExam;
		
		double finalGrade;
	
};

class Math: public Student //same thing but for math students
{
	public:
		Math(const char * first, const char * last, const char * course, const int q1, const int q2, const int q3, const int q4, const int q5, const int t1, const int t2, const int exam);
		double GradeReport();
		int FinalExam();
	
	private:
		int quiz1; //different grades but same idea
		int quiz2;
		int quiz3;
		int quiz4;
		int quiz5;
		
		double quizAverage;
		
		int test1;
		int test2;
		
		int finalExam;
		
		double finalGrade;
			
};
