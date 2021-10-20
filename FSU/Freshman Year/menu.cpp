/* Name: Marshall Copeland
Date: 01/14/2020
Section: #4
Assignment: Homework #1
Due Date: 01/21/2020
About this project: Create a program (Filename: menu.cpp) that will simulate
ordering different goodies from the Trolley as if you are on your way to Hogwarts.
You will ask the user how many of certain candy items they'd like, calculate, and
print the total for the customer, including wizard tax. (Yes, there's even taxes in
the wizarding world).
Assumptions: None

All work below was performed by Marshall Copeland */

#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	int numbeans; // these variables will track user input, they are integers because we will assume that the person ordering wants an integer amount of each item
	int numfrog;
	int numbon;
	int numcake;
	
	double beans = 4.00; // these variables will show the price of each item, they are doubles because the price is rounded to the nearest cent
	double frog = 1.50;
	double bon  = 2.50;
	double cake = 6.25;

	cout << "Anything off of the trolley, dears?" << endl << endl;

	cout << "\tTROLLEY MENU" << endl;
	cout << "\t----------------------" << endl;
	cout <<  "\tBertie Bott's Every Flavour Beans: $" << showpoint << fixed <<  setprecision(2) << beans << endl; // these lines will display menu prices while rounding price to nearest cent
	cout << "\tChocolate Frog: $" << showpoint << fixed << setprecision(2) << frog << endl;
	cout << "\tExploding Bonbons: $" << showpoint << fixed << setprecision(2) << bon << endl;
	cout << "\tCauldron Cakes: $" << showpoint << fixed << setprecision(2) << cake << endl;
	cout << "\t----------------------" << endl;

	cout << "\nHow many Bertie Bott's Every Flavour Beans? --> "; // these lines will ask the user how many of each item they want, and keep track of the amount using the first group of declared variables
	cin >> numbeans;
	cout << "How many Chocolate Frogs? --> ";	
	cin >> numfrog;
	cout << "How many Exploding Bonbons? --> ";	
	cin >> numbon;
	cout << "How many Cauldron Cakes? --> ";	
	cin >> numcake;

	double total = ((numbeans * beans) + (numfrog * frog) + (numbon * bon) + (numcake * cake)); // this line calculate the total by multiplying the user entered amount by the price for each item and adding the totals together to create a grand total

	cout << "\nTotal (Before Wizard Tax): $" << showpoint << fixed << setprecision(2) << total; // this outputs the grand total before tax

	double tax = total * .065; // this double will multiply the grand total by the tax rate to create the wizard tax for the order

	cout << "\nTax (6.50%): $" << showpoint << fixed  << setprecision(2) << tax << endl; // this line gives the orderer the tax amount as a double rounded to the nearest cent	
	cout << "Total (After Wizard Tax): $" << showpoint << fixed << setprecision(2) << total + tax << endl; // now the final total with tax is displayed, which is what the oreder is going to end up paying

	cout << "\nEnjoy your candies!" << endl; // easy first project, only took 6 days 

return 0;
}
