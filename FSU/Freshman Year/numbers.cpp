/* Name: Marshall Copeland
Date: 02/02/20
Section: #4
Assignment: #3
Due Date: 02/13/20
About this project: Write a program that will allow the user to enter a set of integers (as many as they want), then prints out a summary of information
Assumptions: None

All work below was performed by Marshall Copeland */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int input; //tracks the numbers that the user inputs
	int total = 0; //keeps track of the running total based on how many values that the user inputs
	double sum = 0; //keeps track of the running total based on the actual values that the user inputs
	int divTen = 0; //keeps track of how many values that the user inputs that are divisible by ten
	int max = 0; //keeps track of the maximum number that the user inputs
	int min = 0; //keeps track of the minimum number that the user inputs
	double average;	//the double value that will output the average of all the numbers inputted
		
	do { //the do while loop that will cycle through the values as long as the value is not zero, which is the break statement
	cout << "Input integer (0 to stop): ";
	cin >> input;
	total++; //keeps track of each time that loop runs, counting how many times the user inputs a value
	if(input != 0)
	{
		sum += input; //keeps track of the sum of values, as long as the value isnt zero
	}
	if(input % 10 == 0)
	{
		divTen++; //keeps track of how many values are divisible by ten
	}
		

	if(min == 0 || max == 0) //takes care of scenario when the first value entered is zero
	{
	min = input; //sets min to zero
	max = input; //sets max to zero
	}
		
	else if(input < min && input != 0) //when the value is not zero, and less than zero, a new min is set
	{
		min = input;
	}
	else if(input > max) //when the value is greater than zero, a new max is set
	{
		max = input;
	}
	if(input != 0) //the average is calculated as long as the value isnt zero, by dividing the sum by the total
	{
	average = (sum / total);
	}
	else if(input == 0 && total == 1) //if the person enters a zero first, the average will also be zero
	{
	average = 0;
	}
	} while(input != 0); //this is all done as long as the number isnt zero

		cout << "\nTotal: " << total - 1 << endl; //outputs total - 1 due to the do while
		cout << "Sum: " << sum << endl; //outputs the sum of the numbers entered
		cout << "Divisible by 10: " << divTen - 1 << endl; //outu=puts the number of times the number inputted is divisible by ten - 1 due to do while loop
		cout << "Max: " << max << endl; //outputs max input
		cout << "Min: " << min << endl; //outputs min input
		cout << "Avg: " << showpoint << fixed << setprecision(1) << average << endl; //outputs average set to one decimal place 

return 0;
}
//definetly harder than pennies, due to the min exclusion of zero that kept messing me up, as well as the - 1 for the dividing by ten and total calculator. Got confused and ready to quit a couple times, but in the end I got it right so thats good I guess. Also had a mid code crisis while using a do while loop and switched to a while loop, that didnt work for me so I switched back to a while. Only a couple hours wasted, unlucky.
