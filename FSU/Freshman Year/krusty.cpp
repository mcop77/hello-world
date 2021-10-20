/* Name: Marshall Copeland
Date: 02/02/20
Section: #4
Assignment: #3
Due Date: 02/13/20
About this project: Write a program that calculates how much a person would ea$
Assumptions: None

All work below was performed by Marshall Copeland */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double OrderTotal(int numPatty, int numFry, int numDrink, int numPizza); //calls on function that establishes the prices

void menu(); //void function that calls the actual menu that will be printed to the screen

int main() //beginning of the main function, called main
{
	int item; //the variable that keeps track of which item is selected
	int amount; //keeps track of how much of each item you order
	int count = 0; //count equals zero so that the program makes sure that the person enters a valid number to cycle the loop
	int numPatty = 0; //sets the number of patties to zero
	int numFry = 0; //sets the number of patties to zero
	int numDrink = 0; //sets the number of patties to zero
	int numPizza = 0; //sets the number of patties to zero
	
	double ordertotal; //the double that will give the total price for everything


	cout << "Welcome to the Krusty Krab!" << endl; //initial output printed to screen
	
	do { //beginning of do while loop
	if(count == 0) //exeecutes when the loop is run once
	{
		cout << endl;
	}
	menu(); //prints out menu function that prints the menu
	cout << "\nWhat would you like? (Enter 0 to finish order!): "; //asks which item the user wants
	cin >> item; //user picks item
	
	if(item == 0 && count == 0) //if the user types 0, which is the break statement, the line below is printed
	{
		cout << "Guess you aren't hungry." << endl;
		cout << "\n 	       ,.--'''''''''--. " << endl;
		cout << "	     .'       .-.      '. " << endl;
		cout << "	    /       .-----.      \\ " << endl;
		cout << "	   /         .---.        \\ " << endl;
		cout << "	   |       .-.   .-.      | " << endl;
		cout << "	   |      /   \\ /   \\     | " << endl;
		cout << "	    \\    |____ |____ |   / " << endl;
		cout << "	     '-._| | | | | | |.-' " << endl;
		cout << "	         | '-' | '-' | " << endl;
		cout << "	          \\___/ \\___/ " << endl;
		cout << "	       _.-'  /   \\  `-._ " << endl;
		cout << "	     .' _.--|     |--._ '. " << endl;
		cout << "	     '._...-|     |-..._.' " << endl;
		cout << "	             \\___/ " << endl;

	cout << "\n(amazing ascii art copyright melina myers 2020)" << endl;
		
	}
	else if(item == 1) //if they type one, a patty is ordered
	{
		count++; //makes sure it is run at least once
		cout << "How many: ";
		cin >> amount; //takes in user input for how many of each item they want
		while(amount < 0) //if the user enters a number less than zero, it says that it is invalid
		{
			cout << "You can't order a negative amount of food!" << endl;
			cout << "Try again: "; //repeats until number is positive
			cin >> amount;
		}
		numPatty = numPatty + amount; //keeps track of how much is ordered
		cout << endl;
	}
	else if(item == 2) //next blocks are all the same, just for the other menu items
	{
		count++;
		cout << "How many: ";
		cin >> amount;
		while(amount < 0)
		{
			cout << "You can't order a negative amount of food!" << endl;
			cout << "Try again: ";
			cin >> amount;
		}
		numFry = numFry + amount;
		cout << endl;
	}
	else if(item == 3)
	{
		count++;
		cout << "How many: ";
		cin >> amount;
		while(amount < 0)
		{
			cout << "You can't order a negative amount of food!" << endl;
			cout << "Try again: ";
			cin >> amount;
		}
		numDrink = numDrink + amount;
		cout << endl;
	}
	else if(item == 4)
	{
		count++;
		cout << "How many: ";
		cin >> amount;
		while(amount < 0)
		{
			cout << "You can't order a negative amount of food!" << endl;
			cout << "Try again: ";
			cin >> amount;
		}
		numPizza = numPizza + amount;
		cout << endl;
	}
	else if(item < 0 || item > 4) //if the user enters a number other than 1 - , they have to try again while restarting the whole loop
	{
		cout << "That isn't on the menu! Try again." << endl;
	}

} while(item != 0); //ending loop as long as the value isnt the break statement which is zero

	ordertotal = OrderTotal(numPatty, numFry, numDrink, numPizza); //keeps track of the prices of each item based on what the user orders
	
	if(count != 0) //when the loop has cycled through, the total and what they ordered will appear, as lonng as the first value wasnt zero
	{
		cout << "\nYour order:" << endl;
	if(numPatty > 0)
	{
		cout << numPatty << " krabby patties." << endl;
	}
	if(numFry > 0)
	{
		cout << numFry << " barnacle fries." << endl;
	}
	if(numDrink > 0)
	{
		cout << numDrink << " kelp shakes." << endl;
	}
	if(numPizza > 0)
	{
		cout << numPizza << " krusty krab pizzas." << endl;
	}
	
	cout << "\nYour total is $" << showpoint << fixed << setprecision(2) << ordertotal << endl; //total is outputted to two decimal places due to monetary value
	cout << "Enjoy the food!" << endl; //thanks the user for ordering
	
	}
	
return 0;
}

double OrderTotal(int numPatty, int numFry, int numDrink, int numPizza) //the function that holds that prices of each item
{
	
	double pricePatty = 3.5; //sets the menu items to their given price
	double priceFry = 1.5;
	double priceDrink = 1.0;
	double pricePizza = 5.0;
	double total = (numPatty * pricePatty) + (numDrink * priceDrink) + (numFry * priceFry) + (numPizza * pricePizza); //calculates the total based on the prices and user inputted values
	
	return total; //outputs the total
}

void menu() //void function that returns nothing, just outputs the menu when called on
{
	cout << "----------- Menu -----------" << endl;
	cout << "1. Krabby Patty ...... $3.50" << endl;
	cout << "2. Barnacle Fries .... $1.50" << endl;
	cout << "3. Kelp Shake ........ $1.00" << endl;
	cout << "4. Krusty Krab Pizza . $5.00" << endl;
}

//by far the hardest program ive had to code, went into office hours twice, maybe even three times, functions are hard to use at first, but i can only imagine it gets easier with time. hopefully. actual coding wasnt too hard, just logical mapping took a little bit to understand and seeing what i was actually trying to do. overall, hard but satisfying to see it actually compile and run properly. 6.9/10



