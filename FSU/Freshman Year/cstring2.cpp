#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	//First and Last name, Phone #, GPA
	char name[100];
	char area[4];
	char localPhone[9];
	
	double gpa;
	
	cout << "Enter your Name: ";
	cin.getline(name, 100, ',');
	cin.ignore(); //ignores one char space
	
	cout << "\nEnter your Area Code: ";
	cin.getline(area, 4, '-');
	cin.getline(localPhone, 9 , ',');
	
	cout << "\nEnter your GPA: ";
	cin >> gpa;
	
	
	
	return 0;
}
