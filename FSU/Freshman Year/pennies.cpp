/* Name: Marshall Copeland
Date: 02/02/20
Section: #4
Assignment: #3
Due Date: 02/13/20
About this project: Write a program that calculates how much a person would earn over a period of time if his or her salary is one penny the first day, two pennies the second day, and continues to double each day.
Assumptions: User entered value for the number of days worked is an integer

All work below was performed by Marshall Copeland */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int numDay; //establishes a variable that keeps track of the number of days the user inputs
	int day = 1; //day is set to one so the for loop works
	double earned = .01; //this is the base amount of money earned for one day
	double total; //the final total that adds up all of the values, it is a double because it is money

	cout << "Please enter the number of days worked: "; //first lein user reads
	cin >> numDay; //user input for the number of days
	
	if(numDay > 0) //loop that runs when the user inputs a value greater than zero
	{
		cout << "\nDay 			Amount Earned" << endl;
		cout << "-------------------------------------------" << endl;
	
		for(int x = 0; x < numDay; x++) //the for loop that will run and output the amount earned for each day the user inputted
		{
		
		cout << day++ << "		$ " << earned << endl;		

		total += earned; //keeps track of running total
		earned = earned * 2; //changes the amount earned by multiplying by two for each day the person works
		}	
	}
	else if(numDay <= 0) //if the user inputs a number less than zero, the user is put into a loop until they enter a vlaue greater than zero
	{
		while(numDay <= 0) //this is the same while/for loop block as above, but takes care of the case where they dont enter a value over zzero on the first try
		{ 
 			cout << "Invalid number of days. Try again" << endl;
			cout << "Please enter the number of days worked: ";
			cin >> numDay;
		}
		cout << "\nDay                  Amount Earned" << endl;
                cout << "-------------------------------------------" << endl;

                for(int x = 0; x < numDay; x++)
                {

                cout << day++ << "		$ " << earned << endl;

                total += earned;
                earned = earned * 2;
		}
	}	
cout << "\nTotal earnings : $ " << showpoint << fixed << setprecision(2) << total << endl; //outputs the total earnings, using setprecision to round by two decimal places because it is money

return 0;
} //overall not too hard, only problem was trying to figure out how to multiply by two and then keep track of it, but after that it was a breeze
