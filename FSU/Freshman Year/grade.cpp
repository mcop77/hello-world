/* Name: Marshall Copeland
Date: 01/22/2020
Section: #4
Assignment: Homework #2
Due Date: 01/30/2020
About this project: This assignment will consist of writing a program that gives
practice with basic selection statements (if,else,switch), as well as further 
practice with basic I/O, and output formatting. Real world application, this program 
will help you calculate your overall course grade at the end of the class if done
correctly :)
Assumptions: None

All work below was performed by Marshall Copeland */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double hw; //this is where i declare all the variables, i used doubles because it worked that way so i didn't mess with it. Also, these are the hw assignments that the user enters
	double hw2;
	double hw3;
	double hw4;
	double hw5;
	double hw6;
	double hw7;

	double rec; //these record the recitaion inputs
	double rec2;
	double rec3;
	double rec4;
	double rec5;
	double rec6;

	double mid1; //these record the midterm and final grades
	double mid2;
	double fin;

	char ec; //these variables keep track of the extra credit the user inputs
	double ecnum;

	double hwAvg; //these all will be used to calculate the values when the inputs are put together to calculate grades
	double testAvg;
	double courseAvg;
	double courseAvg2;
	char grade;

	cout << "Welcome to the Grade Calculator!" << endl; //first output

	cout << "\nHOMEWORK GRADES -->"; //prompts user to enter in hw values
	cin >> hw;
	cin >> hw2;
	cin >> hw3;
	cin >> hw4;
	cin >> hw5;
	cin >> hw6;


	cout << "\nRECITATION GRADES -->"; //prompts user to enter recitation values
	cin >> rec >> rec2 >> rec3 >> rec4 >> rec5;

	cout << "\nTEST GRADES -->" << endl; //user entered midterm one score
	cout << "Midterm I: ";
	cin >> mid1;

	cout << "Midterm II: "; //second midterm score
	cin >> mid2;

	cout << "Final: "; //final score
	cin >> fin;

	testAvg = ((mid1 * 17.5) + (mid2 * 17.5) + (fin * 25)) / 60; //calculates the test average using given formula
	hwAvg = hw + hw2 + hw3 + hw4 + hw5 + hw6 + rec + rec2 + rec3 + rec4 + rec5; //calculates hw average without extra credit because i didn't know how to get it to work with it in the equation
	courseAvg =  ((mid1 * .175) + (mid2 * .175) + (fin * .25)); //course average without hw average due to extra credit issue

	cout << "\nIs there any extra credit to add in? (Y or N) --> "; //promts user if there is any extra credit to enter
	cin >> ec;

	if(ec == 'Y' || ec == 'y') //if yes, the user enters in the extra credit amount
	{
		cout << "How many extra credit points should be added? --> ";
		cin >> ecnum;
		cout << "\nHomework Average: " << showpoint << fixed << setprecision(2) << (((hwAvg + ecnum) / 680) * 100) << "%" << endl; //hw average takes into user entered extra credit amount in the formula
		
		if(testAvg < 69) //if the test average is below a 69, it prints outthat the test average was not met
		{
	        	cout << "Test Average: " << testAvg << "% ***Test average requirement not met***" << endl;
		}
        	else cout << "Test Average: " << testAvg << "%" << endl; //if the test average is greater than or equal to 69, than you are fine
        	
		cout << "Course Average: " << showpoint << fixed << setprecision(2) << courseAvg + ((((hwAvg + ecnum) / 820) * 100) * .40) << "%" << endl;

 		if ((courseAvg + ((((hwAvg + ecnum) / 820) * 100)) * .40) >= 90) //now begins the set of if statements that determines what letter grade you get based on your test average
		{
	        cout << "Course Grade: A "<< endl;
		}
	
		else  if ((courseAvg + ((((hwAvg + ecnum) / 820) * 100)) * .40)  >= 80)
                {
                cout << "Course Grade: B "<< endl;
                }

		else  if ((courseAvg + ((((hwAvg + ecnum) / 820) * 100)) * .40)  >= 69)
                {
                cout << "Course Grade: C "<< endl;
                }

		else  if ((courseAvg + ((((hwAvg + ecnum) / 820) * 100)) * .40)  >= 60)
                {
                cout << "Course Grade: D "<< endl;
                }

		else cout << "Course Grade: F "<< endl;
	}

	else if(ec == 'N' || ec == 'n') //if the user does not have any extra cred to enter, than the regular hw average is used to determine final grades
	{
                cout << "\nHomework Average: " << showpoint << fixed << setprecision(2) << (((hwAvg) / 820) * 100) << "%" << endl;

		if(testAvg < 69) //same if statement as the previous if block
                {
                        cout << "Test Average: " << testAvg << "% ***Test average requirement not met***" << endl;
                }
                else cout << "Test Average: " << testAvg << "%" << endl;

                cout << "Course Average: " << showpoint << fixed << setprecision(2) << courseAvg + (((hwAvg / 820) * 100) * .40) << "%" << endl;

		if ((courseAvg + ((((hwAvg) / 820) * 100)) * .40) >= 90) //same if statements omitting extra credit are used to determine grade letters that were used in the extra credit if statements
                {
                cout << "Course Grade: A "<< endl;
		}
                
		else  if ((courseAvg + ((((hwAvg) / 820) * 100)) * .40)  >= 80)
                {
                cout << "Course Grade: B "<< endl;
		}
                
		else  if ((courseAvg + ((((hwAvg) / 820) * 100)) * .40)  >= 69)
                {
                cout << "Course Grade: C "<< endl;
		}
                
		else  if ((courseAvg + ((((hwAvg) / 820) * 100)) * .40)  >= 60)
                {
                cout << "Course Grade: D "<< endl;
		}
                else cout << "Course Grade: F "<< endl;
	}
	else cout << "Invalid option, exiting program." << endl; //if the user does not enter a Y, y, N, or n, when asked if they have any extra credit, than the program will shut down and Invalid option will print
	
return 0; //overall, pretty hard and time consuming assignment, stuggled with extra credit being incorporated into the hw average and compilation errors due to extra parentheses, as well as trouble getting values to be doubles. Also tried to implement the given switch statement for the grade letter but after an hour or two i still couldnt get it to work since test avg was a double, so i tried casting it to an int and other stuff but nothign worked. I think there are still some variables that pertain to the switch statement, but i dont want to remove them and have it mess everything up because i'm tired of working on this after a week and just want to submit this. Pretty challenging overall, but i got it done so i guess that says something.  
}
