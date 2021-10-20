/* Name: Marshall Copeland
Date: 03/08/2020
Section: #4
Assignment: Homework #5
Due Date: 03/25/2020
About this project: This assignment will consist of writing several functions that manipulate arrays or access data from arrays, as well as a test program that will allow interactive testing of the array functions.
Assumptions: None
All work below was performed by Marshall Copeland */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Given Global CONST variables reperesnting MAX and MIN size 
array in program is able to be within. 
Use these variables throughout your program whenever referring to 
the array's MAX and MIN size bounds*/

const int MAX = 40;
const int MIN = 5;

/*Given Function prototypes*/
void PrintArray (const int arr[], const int size);

char menu(); //declares menu function that returns a char value
void Shift(int arr[], int size, int amount); //declares Shift function, which moves valuse right based on how much the user decides
void Delete(int arr[], int size, int index); //declares the Delete function that deletes a value at and index, shifts everything over, and then at the end there is a zero in place of the deleted value
void Reverse(int arr[], int size); //declares the function Reverse that reverses the elements in the array

/*Your function prototypes here*/

int main()
{
	srand(time(0)); //seeds random variables based on time to generate a random variable
	int size; //the size of the array
	char menuChoice; //what the user enters
	int arr[MAX]; //creation of array, with max size MAX.
	int count = 0; //counter variable to help things only run once
	int amount; //amount user inputs that relates to the shift function
	int index; //used in the delete function, its the index of what the user wants deleted
	int indexValue; //the new value inputted in the change array element if statement
	
	bool check = false; //helps check if correct user input was inputted
	
	
	cout << "Welcome to the array manipulator!\n" << endl;
	//Promput user for starting current size of array (between MIN and MAX).
	do { //eveything runs in this do while
	
		while(count == 0) //this only runs once
		{
			 count++;
			do {
		
				cout << "How big would you like to make your array?" << endl; //user prompted with what they need to input
			
				cout << "Enter a value " << MIN << " --> " << MAX << ": ";
				cin >> size;
				cout << "\n";
			
				while(size < MIN || size > MAX) //checks iff array size is between min and max
				{
					cout << "Enter a value " << MIN << " --> " << MAX << ": ";
					cin >> size;
				}
	
			} while(size < MIN || size > MAX);
		}
			menuChoice = menu(); //helps determine what the user inputs //calls menu function


			if(count == 1) //runs once after menu and setting array sizes are finished
			{
				for(int i = 0; i < size; i++) //fills the array with random numbers
				{
					arr[i] = rand() % 100 + 1;
				}		
				count++; //makes sure it is only run once
			}
	
			if(menuChoice == 'F' || menuChoice == 'f') //fills array with random elements again to change them
			{
				cout << "\nRandomizing Array Data...\n" << endl;
				for(int i = 0; i < size; i++)
				{
					arr[i] = rand() % 100 + 1;
				}
				check = true; //makes sure menuChoice input was correct
			}
	
			else if(menuChoice == 'R' || menuChoice == 'r') //calls reverse function
			{
				cout << "\nReversing Array..." << endl;
				Reverse(arr, size);
				PrintArray(arr, size); //prints the array after reversing it with the reverse function
				check = true;
			}
		
			else if(menuChoice == 'X' || menuChoice == 'x') //calls shift function
			{
				cout << "\nShift Right by: ";
				cin >> amount;
				Shift(arr, size, amount);
				PrintArray(arr, size); //prints array after shifting array right by user amount
				check = true;
			}
		
			else if(menuChoice == 'C' || menuChoice == 'c') //changes element to user inputted element
			{
				cout << "\nWhat array index would you like to update? > "; //user picks which index they want to change
				cin >> index;
				
				while(index >= size || index < 0) //if the index is not an index in the array, the have to type in a correct index value
				{
					cout << "\nWhat array index would you like to update? (0 -- > " << size - 1 << ") > ";

					cin >> index;
				}
				
				cout << "\nChange arr[" << index << "] to what value? > ";
				cin >> indexValue;
				
				arr[index] = indexValue; //changes the element
				
				cout << "\nArr[" << index << "] is now " << indexValue << endl;
				
				PrintArray(arr, size); //prints changed array
				check = true;
			}
		
			else if(menuChoice == 'D' || menuChoice == 'd') //will call the delete function
			{
				cout << "\nDelete element at which index? > ";
				cin >> index;
				
				while(index < 0 || index > size - 1) //makes sure the chose index is in the array
				{
					cout << "Enter a value 0" << " --> " << size - 1 << ": ";
					cin >> index;
				}
				
				
				cout << "\nDeleting item at index " << index << "..." << endl;
				Delete(arr, size, index); //actually calls the delete function
				PrintArray(arr, size); //prints change array
				check = true;
				
			}
		
			else if(menuChoice == 'A' || menuChoice == 'a') //calculates average
			{
				double total = 0; //total is zero
				double count = 0; //count is zero
				double average = 0; //average is zero
				
				
				for(int x = 0; x < size; x++) //cycles through the array
				{
					total += arr[x]; //adds up all the values
					count++; //keeps track of how many valuse there are, i couldve just used size but oh well
				}
				 average = total / count; //divides the total by the amount, getting the average of the array
				
				cout << "\nArray Average: " << average << showpoint << fixed << setprecision(1) << "\n" << endl; //outputs the average
				check = true;
			}
		
			else if(menuChoice == 'M' || menuChoice == 'm')
			{
				int max; //establishes a max variable

				max = arr[0]; //max equals the first value of the array
					
				for(int x = 0; x < size; x++) //cycles through thea array
				{

					if(arr[x] > max) //is there is an element in the array that is greater than the current max, that value is set to the new max
					{
						max = arr[x]; //max equals the greater element
					}
				}
				
				cout << "\nMax Value: " << max << "\n" << endl; //prints the max
				check = true;
			}
		
			else if(menuChoice == 'G' || menuChoice == 'g')
			{
				int count = 0; //helps things only run a certain number of times
				bool output = true; //checks if the output is correct
				
				while(size + 5 > 40 && count == 0) //if the size + 5 is greater than the max array size
				{
					cout << "\nCannot Grow Array. Current Size: " << size << " Maximum Size: " << MAX << "\n" << endl;
					
					count++;
					output = false; //i forgot what this does, probably past code that i forgot to delete
				}
				
				for(int x = 0; x < size; x++) //cycles through the array
				{
					arr[x];
				}
				
				if(size + 5 <= 40) //if the array + 5 is less thatn or equal to the max 
				{
					for(int x = size; x < size + 5; x++) //cycles through the array
					{
						arr[x] = 0; //new values att the end are zero
					}
				
					size = size + 5; //helps make sure it only runs a certain amount of times
				}
				
				if(size <= 40 && output == true) //i remember what that output = false means, it checks and makes sure that the size is <= 40
				{
					cout << "\nArray size is now: " << size << "\n" << endl;	//outputs new size
				}		
				check = true;
			}
		
			else if(menuChoice == 'S' || menuChoice == 's') //same thing as above, but shrinks the array by five
			{
				int count = 0; //count = 0, makes sure it only runs once
				bool output = true; //checks size
				
				while(size - 5 < 5 && count == 0) //checks to see if array size - 5 is less than min
				{
					cout << "\nCannot Shrink Array. Current Size: " << size << " Minimum Size: " << MIN << "\n" << endl;
					
					count++;
					output = false; //loops back to input
				}
				
				
				if(size - 5 >= 5) 
				{
					for(int x = 0; x < size - 5; x++) //cycles through array size - 5 times, deleting 5 values
					{
						arr[x];
					}
					size = size - 5;
				}
			
				if(size >= 5 && output == true)
				{
					cout << "\nArray size is now: " << size << "\n" << endl; //outputs new size
				}
				
				check = true;
			}
		
			else if(menuChoice == 'P' || menuChoice == 'p')
			{
				PrintArray(arr, size); //calls print function, prints array
				check = true;
			}
	
			else if(menuChoice == 'Q' || menuChoice == 'q')
			{
				PrintArray(arr, size); //calls print array when user exits
				cout << "Goodbye!" << endl;
				check = true;
				return 0; //ends program
			}
			
			while(check == false) //if correct user entry was not inputted
			{
				cout << "\n";
				
				menuChoice = menu(); //try again
				
				if(menuChoice == 'F' || menuChoice == 'f' || menuChoice == 'R' || menuChoice == 'r' || menuChoice == 'X' || menuChoice == 'x' || menuChoice == 'C' || menuChoice == 'c' || menuChoice == 'D' || menuChoice == 'd' || menuChoice == 'A' || menuChoice == 'a' || menuChoice == 'M' || menuChoice == 'm' || menuChoice == 'G' || menuChoice == 'g' || menuChoice == 'S' || menuChoice == 's' || menuChoice == 'P' || menuChoice == 'p' || menuChoice == 'Q' || menuChoice == 'q')
				{	
					return true; //if the user inputs corret input, it cycles back through do while above
				}
				cout << "\n" << endl;
			}
			
			
		} while(menuChoice != 'Q' || menuChoice != 'q');
		//Enter a loop that presents the user with the menu and manipulates array based on menu choice.
		
		
	return 0;
	
}


/*Your function declarations here*/

char menu() //menu function
{
	char menuChoice; 
	bool check = true; //ok im pretty sure this is old code that i didnt delete
	
		cout << "---MENU---" << endl;
		cout << "F - Fill Array: RANDOM values 1 - 100" << endl;
		cout << "R - Reverse Array Contents" << endl;
		cout << "X - Shift Right" << endl;
		cout << "C - Change Array Element" << endl;
		cout << "D - Delete Array Element" << endl;
		cout << "A - Print Average" << endl;
		cout << "M - Print Max Value" << endl;
		cout << "G - Grow Array Size by 5" << endl;
		cout << "S - Shrink Array size by 5" << endl;
		cout << "P - Print Array" << endl;
		cout << "Q - Quit" << endl;
		cout << "------------------------------------------" << endl;

		cout << "Selection > ";
		
		cin >> menuChoice; //user gives input
		
		
	return menuChoice; //returns user input to main and decides what to do from there
		
}

void Shift(int arr[], int size, int amount) //shift function, takes in the array, the size of the array, and the amount the user wants to shift by
{
	int helper[size]; //helper array
	
	for(int x = 0; x < size; x++) //cycles thorugh, changes helper array elements to changed array elements
	{
		helper[(x + amount) % size] = arr[x];
	}
	
	for(int x = 0; x < size; x++)
	{
		arr[x] = helper[x]; //arr is equal to the shifted contents of helper
	}
}


void Delete(int arr[], int size, int index) //delete function, takes in the array and array size, and the index of the element the user wants deleted
{
	for(int x = 0; x < size; x++) //cylces through array
	{
		arr[x];
		
		if(x == index) //if the index is the one the user selscted
		{
			for(int x = index; x < size - 1; x++)
			{
				arr[x] = arr[x + 1]; //the elements get shifted left
			}
			
			arr[size - 1] = 0; //the last value becomes a zero
		}
	}
}


void Reverse(int arr[], int size) //reverse function, takes in the array and array size
{
	int helper[size];	//helper array
	
		for(int x = 0; x < size; x++) //cycles through the array
		{
			helper[x] = arr[(size - 1) - x]; //reverses arr elements and puts them into helper elements
		}	
		
		for(int x = 0; x < size; x++)
		{
			arr[x] = helper[x]; //reversed helper elements become the arr elements
		}
}


//GIVEN: PrintArray Function
//This function prints the contents of any interger array of any size seperated by commas
void PrintArray(const int arr[], const int size)
{
	cout << "\nThe array:\n { ";
	for (int i = 0; i < size-1; i++)	// for loop, prints each item (not last due to comma handling)
		cout << arr[i] << ", ";

	cout << arr[size-1] << " }\n\n";	// prints last item , no comma
}
