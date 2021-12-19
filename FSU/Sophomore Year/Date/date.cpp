/* Name: Marshall Copeland
Date: 09/15/20
Section: #10
Assignment: HW #2
Due Date: 09/25/20
About this project: For this homework, you will write a class called Date, in the files date.h and date.cpp, for creating and using objects that will store valid dates of the year.

All work below was performed by Marshall Copeland */

#include <iostream>
#include <iomanip>
#include <string>
#include "date.h"
using namespace std;

/* 
January - 31 days
February - 28 days, 29 in leap years
March - 31 days
April - 30 days
May - 31 days
June - 30 days
July - 31 days
August - 31 days
September - 30 days
October - 31 days
November - 30 days
December - 31 days 
*/

Date::Date(int newMonth, int newDay, int newYear) //where the newMonth, newDay, and the newYear are going to be passed in as parameters in the constructor
{
	Format = 'D'; //the format will always be default (M/D/Y) at the start of the program
	
	if(newMonth == 1) //begins the error checking loops of making sure the parameters are correct, otherwise the date will be defaulted to 1/1/2000
	{
		if(newDay > 0 && newDay < 32) //if the day fits with how many days there are in this month
		{
			if(newYear > 0) //makes sure the year is a valid AD year, which starts at 1 AD.
			{
				Month = newMonth; //if the year, day, and month are all correct, the date is set up to what it is
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1; //otherwise it is defaulted to 1/1/2000
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1; //otherwise it is defaulted to 1/1/2000
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 2) //these blocks of if statements carry through all of the months, checking their specific number of days with the parameters
	{
		if(newDay > 0 && newDay < 29)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 3)
	{
		if(newDay > 0 && newDay < 32)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 4)
	{
		if(newDay > 0 && newDay < 31)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 5)
	{
		if(newDay > 0 && newDay < 32)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 6)
	{
		if(newDay > 0 && newDay < 31)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;	
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
	
	else if(newMonth == 7)
	{
		if(newDay > 0 && newDay < 32)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;	
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 8)
	{
		if(newDay > 0 && newDay < 32)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}	
	}
		
	else if(newMonth == 9)
	{
		if(newDay > 0 && newDay < 31)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 10)
	{
		if(newDay > 0 && newDay < 32)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 11)
	{
		if(newDay > 0 && newDay < 31)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}
		
	else if(newMonth == 12)
	{
		if(newDay > 0 && newDay < 32)
		{
			if(newYear > 0)
			{
				Month = newMonth;
				Day = newDay;
				Year = newYear;
			}
			
			else
			{
				Day = 1;
				Month = 1;
				Year = 2000;
			}
		}
		
		else
		{
			Day = 1;
			Month = 1;
			Year = 2000;
		}
	}	
	
	else if(newMonth > 12 || newMonth < 0) //if there isnt a valid month given, the default date is used
	{
		Day = 1;
		Month = 1;
		Year = 2000;
	}
}

void Date::Input() //the input function, which allows the user to type in a valid date with the same restrictions as above
{
	char slash; //two char variables to handle the user typing in the 2 /'s in the date, since the date is in M/D/Y format
	char slash2;
	
	int newMonth; //int variables that are assigned the new input for the month, day, and year that the user enters
	int newDay;
	int newYear;
	
	int count = 0; //int variable that will help the do while loop run the neccessary amount of times it needs to run
	
	cout << "\nEnter a date: "; //the user i prompted to first enter a date
	
	do {
		cin >> newMonth >> slash >> newDay >> slash2 >> newYear;
		
		if(newMonth == 1) //the user entered date is compared with the neccessary restrictions
		{
			if(newDay > 0 && newDay < 32)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1; //if the date is a valid date, count = 1 and the loop will break
					}
				}
			}
		}
		
		else if(newMonth == 2)
		{
			if(newDay > 0 && newDay < 29)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 3)
		{
			if(newDay > 0 && newDay < 32)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 4)
		{
			if(newDay > 0 && newDay < 31)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 5)
		{
			if(newDay > 0 && newDay < 32)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 6)
		{
			if(newDay > 0 && newDay < 31)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 7)
		{
			if(newDay > 0 && newDay < 32)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 8)
		{
			if(newDay > 0 && newDay < 32)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 9)
		{
			if(newDay > 0 && newDay < 31)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 10)
		{
			if(newDay > 0 && newDay < 32)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 11)
		{
			if(newDay > 0 && newDay < 31)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		else if(newMonth == 12)
		{
			if(newDay > 0 && newDay < 32)
			{
				if(newYear > 0)
				{
					if(slash == '/' && slash2 == '/')
					{
						count = 1;
					}
				}
			}
		}
		
		if(count == 0)
		{
			cout << "Invalid date.  Try again: "; //if the user has not entered in a valid date, they will be prompted to enter in another one
		}
		
	} while(count == 0); //the loop runs while there is an invalid date
	
	Month = newMonth; //once the user enters a valid date, the new date is set
	Day = newDay;
	Year = newYear;
}

void Date::Show() const //const show function that o nly outputs what the current date is when it is called
{
	int january = 31; //ints of the days in the months
	int february = 28;
	int march = 31;
	int april = 30;
	int may = 31;
	int june = 30;
	int july = 31;
	int august = 31;
	int september = 30;
	int october = 31;
	int november = 30;
	int december = 31;
	
	int days = 0; //helps with the julian output
	int modYear = Year % 100; //helps with the two format and the julian format
	
	char slash = '/'; //helps print the characters that go in between the months in the different formats
	string comma = ", ";
	char dash = '-';
	
	if(Format == 'D') //if the format is default, this will print out what ever month / day / year it is
	{
		cout << Month << slash << Day << slash << Year << endl;
	}
	
	else if(Format == 'T') //if the format is T, only two of the digits for each month, day, adn year will be output. if there is only one digit for any of the values, it will be padded with a zero
	{
		if(Month < 10)
		{
			cout << "0" << Month << slash;
			
			if(Day < 10)
			{
				cout << "0" << Day << slash;
			}
			
			else if(Day > 9)
			{
				cout << Day << slash;
			}
			
			if(Year > 9)
			{
				if(modYear > 9)
				{
					cout << Year;
				}
				
				else if(modYear < 10)
				{
					cout << "0" << modYear;
				}
			}
			
			else if(Year < 10)
			{
				cout << "0" << Year;
			}
		}
		
		else if(Month > 9)
		{
			cout << Month << slash;
			
			if(Day < 10)
			{
				cout << "0" << Day << slash;
			}
			
			else if(Day > 9)
			{
				cout << Day << slash;
			}
			
			if(Year > 9)
			{
				if(modYear > 9)
				{
					cout << Year;
				}
				
				else if(modYear < 10)
				{
					cout << "0" << modYear;
				}
			}
			
			else if(Year < 10)
			{
				cout << "0" << Year;
			}
		}
	}
	
	else if(Format == 'L') //this format prints the abbreviated month, followed by a space, and then the date followed by a commoa, and then another space and then the year
	{
		if(Month == 1)
		{
			cout << "Jan ";
		}
		
		else if(Month == 2)
		{
			cout << "Feb ";
		}
		
		else if(Month == 3)
		{
			cout << "Mar ";
		}
		
		else if(Month == 4)
		{
			cout << "Apr ";
		}
		
		else if(Month == 5)
		{
			cout << "May ";
		}
		
		else if(Month == 6)
		{
			cout << "June ";
		}
		
		else if(Month == 7)
		{
			cout << "July ";
		}
		
		else if(Month == 8)
		{
			cout << "Aug ";
		}
		
		else if(Month == 9)
		{
			cout << "Sept ";
		}
		
		else if(Month == 10)
		{
			cout << "Oct ";
		}
		
		else if(Month == 11)
		{
			cout << "Nov ";
		}
		
		else if(Month == 12)
		{
			cout << "Dec ";
		}
		
		cout << Day << comma << Year << endl;
	}
	
	else if(Format == 'J') //if the format is J, the julian date will be printed, which is the last 2 digits of the year, and then a hypon, and the the date out of the 365 days
	{
		if(Month == 1)
		{
			days = Day;
		}
		
		else if(Month == 2)
		{
			days = january + Day;
		}
		
		else if(Month == 3)
		{
			days = january + february + Day;
		}
		
		else if(Month == 4)
		{
			days = january + february + march + Day;
		}
		
		else if(Month == 5)
		{
			days = january + february + march + april + Day;
		}
		
		else if(Month == 6)
		{
			days = january + february + march + april + may + Day;
		}
		
		else if(Month == 7)
		{
			days = january + february + march + april + may + june + Day;
		}
		
		else if(Month == 8)
		{
			days = january + february + march + april + may + june + july + Day;
		}
		
		else if(Month == 9)
		{
			days = january + february + march + april + may + june + july + august + Day;
		}
		
		else if(Month == 10)
		{
			days = january + february + march + april + may + june + july + august + september + Day;
		}
		
		else if(Month == 11)
		{
			days = january + february + march + april + may + june + july + august + september + october + Day;
		}
		
		else if(Month == 12)
		{
			days = january + february + march + april + may + june + july + august + september + october + november + Day;
		}
		
		if(Year < 10)
		{
			cout << "0" << Year << dash;
		}
		
		else if(Year > 10)
		{			
			if(modYear < 10 || modYear == 0)
			{
				cout << "0" << modYear << dash;
			}
			
			else if(modYear > 10)
			{
				cout << modYear << dash;
			}
		}
		
		if(days < 10)
		{
			cout << "00" << days;
		}
		
		else if(days > 9 && days < 100)
		{
			cout << "0" << days;			
		}
		
		else cout << days;
	}
}

bool Date::Set(int m, int d, int y) //this function returns true if the date passed in is a valid date, and false if it is not, and if it is true the date will  be set to whatever the passed in date is
{
	if(m == 1)
	{
		if(d > 0 && d < 32)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 2)
	{
		if(d > 0 && d < 29)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 3)
	{
		if(d > 0 && d < 32)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
				
				return true;
			}
			
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 4)
	{
		if(d > 0 && d < 31)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 5)
	{
		if(d > 0 && d < 32)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
			
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 6)
	{
		if(d > 0 && d < 31)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 7)
	{
		if(d > 0 && d < 32)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 8)
	{
		if(d > 0 && d < 32)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 9)
	{
		if(d > 0 && d < 31)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
			
		else return false;
	}
		
	else if(m == 10)
	{
		if(d > 0 && d < 32)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 11)
	{
		if(d > 0 && d < 31)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
		
	else if(m == 12)
	{
		if(d > 0 && d < 32)
		{
			if(y > 0)
			{
				Month = m; 
				Day = d;
				Year = y;
					
				return true;
			}
				
			else return false;
		}
		
		else return false;
	}
	
	else return false;
}

int Date::GetMonth() const //a const function that returns the month
{
	return Month;
}

int Date::GetDay() const //a const function that returns the year
{
	return Day;
}

int Date::GetYear() const //a const function that returns the year
{
	return Year;	
}

bool Date::SetFormat(char f) //a function that changes what format the date can be set, either D, T, L, or J
{
	if(f == 'D') //if the char passed in is not D,T,L,or J, the func returns false, else it returns true
	{
		Format = 'D';
		
		return true;
	}
	
	else if(f == 'T')
	{
		Format = 'T';
		
		return true;
	}
	
	else if(f == 'L')
	{
		Format = 'L';
		
		return true;
	}
	
	else if(f == 'J')
	{
		Format = 'J';
		
		return true;
	}
	
	else return false;
}
		
void Date::Increment(int numDays) //the hardest function of them all, the increment function, which can either add a day to the current date when called by itself, or if the function is called with parameters, the date will increase by that amount of days
{	
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //i used an array to keep track of all the days in each month
	
	int monthNum = months[Month - 1]; //monthNum is always the number of days in the current month
	
	int total = (Day + numDays); //int total checks if the numdays causes the date to go to a new month or not
	
	if((total < 32 && Month == 1) || (total < 32 && Month == 3) || (total < 32 && Month == 5) || (total < 32 && Month == 7) || (total < 32 && Month == 8) || (total < 32 && Month == 10) || (total < 32 && Month == 12)) //if the date is in a month with 31 days and the month doesnt change, this executes
	{
		Day = total; //the date + the numdays is the new date
	}
	
	else if((total < 31 && Month == 4) || (total < 31 && Month == 6) || (total < 31 && Month == 9) || (total < 31 && Month == 11)) //if the date is in a month with 30 days and the month doesnt change, this executes
	{
		Day = total;
	}
	
	else if(total < 29 && Month == 2) //if the date is in february and the month doesnt change, this executes
	{
		Day = total;
	}
	
	else if(total >= monthNum) //if the numdays causes there to be a new month
	{
		while(numDays != 0) //while there are still days in the numdays to count by
		{
			if(monthNum == Day && Month != 12) //if the numdays causes the month to go to a new month but it isnt december
			{
				Month = Month + 1; //the month is now the next month
				Day = 1; //the day is set to one because it is a new month
				monthNum = months[Month - 1]; //the new monthNum is now the new months number of days (too many month variables in one line LOL)
				numDays--; //the numdays is then subtracted by one
			}
			
			else if(monthNum == Day && Month == 12) //same thing as above, except it handles a new year
			{
				Year = Year + 1;
				Month = 1;
				Day = 1;
				monthNum = months[Month - 1];
				numDays--;
			}
			
			else 
			{
				Day = Day + 1; //otherwise, the day increases and the numdays decreases
				numDays--;
			}	
		}
	}
}
	
int Date::Compare(const Date& d) const // the final function, where the dates are compared to eachother and return -1, 0, or 1 if they are greater than, less than, or equal to eachother
{
	if(Year > d.Year) //a long sequence of if statements that compare the year, then the month, and then the day
	{
		if(Month > d.Month)
		{
			if(Day > d.Day)
			{
				return -1;
			}
			
			else if(Day == d.Day)
			{
				return -1;
			}
			
			else if(Day < d.Day)
			{
				return -1;
			}
		}
		
		else if(Month == d.Month)
		{
			if(Day > d.Day)
			{
				return -1;
			}
			
			else if(Day == d.Day)
			{
				return -1;
			}
			
			else if(Day < d.Day)
			{
				return -1;
			}
		}
		
		else if(Month < d.Month)
		{
			if(Day > d.Day)
			{
				return -1;
			}
			
			else if(Day == d.Day)
			{
				return -1;
			}
			
			else if(Day < d.Day)
			{
				return -1;
			}
		}
	}
	
	else if(Year == d.Year)
	{
		if(Month > d.Month)
		{
			if(Day > d.Day)
			{
				return -1;
			}
			
			else if(Day == d.Day)
			{
				return -1;
			}
			
			else if(Day < d.Day)
			{
				return -1;
			}
		}
		
		else if(Month == d.Month)
		{
			if(Day > d.Day)
			{
				return -1;
			}
			
			else if(Day == d.Day)
			{
				return 0;				
			}
			
			else if(Day < d.Day)
			{
				return 1;
			}
		}
		
		else if(Month < d.Month)
		{
			if(Day > d.Day)
			{
				return 1;
			}
			
			else if(Day == d.Day)
			{
				return 1;
			}
			
			else if(Day < d.Day)
			{
				return 1;
			}
		}
	}
	
	else if(Year < d.Year)
	{
		if(Month > d.Month)
		{
			if(Day > d.Day)
			{
				return 1;
			}
			
			else if(Day == d.Day)
			{
				return 1;
			}
			
			else if(Day < d.Day)
			{
				return 1;
			}
		}
		
		else if(Month == d.Month)
		{
			if(Day > d.Day)
			{
				return 1;
			}
			
			else if(Day == d.Day)
			{
				return 1;
			}
			
			else if(Day < d.Day)
			{
				return 1;
			}
		}
		
		else if(Month < d.Month)
		{
			if(Day > d.Day)
			{
				return 1;
			}
			
			else if(Day == d.Day)
			{
				return 1;
			}
			
			else if(Day < d.Day)
			{
				return 1;
			}
		}
	}
}
