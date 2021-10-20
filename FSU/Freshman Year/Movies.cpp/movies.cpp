/* Name: Marshall Copeland
Date: 04/18/2020
Section: #4
Assignment: Homework #7
Due Date: 04/28/2020
About this project: Let's create a movie data organizer to help us organize our movie collection. This assignment will simulate the loading, manipulation, and exporting of a movie "database" which will be a collection of movie information that comes from a .txt file.
Assumptions: None

All work below was performed by Marshall Copeland */

#include <iostream> //all the libraries included, not all of them are called, i just copy and pasted from the list melina gave
#include <iomanip>
#include <fstream> //i know this ones important tho
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

struct Movies //establishes the Movies structure
{
	char genre[19]; //genre as a c string that takes up to 20 characters
	char title[99]; //title as a c string that takes up to 100 characters
	char rating[9]; //ratings as a c string that takes up to 10 characters
	int year; //normal year
	int runtime; // normal runtime int
};

char menu(); //menu function stuff
void clear(Movies movieArr[]); //clear function stuff that takes in the movie array
void year(int size, Movies movieArr[]); //year function stuff that takes in the size of the array and the actual movie array

int main() //beginning of main
{
	Movies * movieArr = 0; //fancy thing melina gave us
	
	int menuChoice; //menu choice option
	
	ifstream file; //takes in a new file
	
	char fileName[39]; //the file name can be up to 40 characters
	char cont; //variable that represents the users choice for yes or no for the overwrite thing
	
	int size; //will be the size of the movie array
	int count = 0; //the classic count variable, keeps things running only a certain number of times
	
	int sum = 0; //throwback to the og sum variable, when class was so much easier
	
	string rating2; //not sure why i didnt change this to string rating, i think it messed up with the structure rating thing or something 
	
	ofstream action; //calls a new file referenced by action
	ofstream drama; //calls a new file referenced by drama
	ofstream comedy; //calls a new file referenced by comedy
	ofstream scifi; //calls a new file referenced by sci fi
	
	do{ //the old loop in main where everything happens
		menuChoice = menu(); //calls the menu function to run
	
		if(menuChoice == '1') //if the user types in 1, the first option will run
		{
			if(count != 0) //if this already happened, run this again
			{
				do {
					cout << "\nThere is a database already loaded. This will overwrite the current database." << endl; //overwrite stuff
					cout << "Continue? (y/n) > ";
					cin >> cont;
			
					if(cont != 'y' && cont != 'n') //makes sure user types in a y or n
					{
						while(cont != 'y' && cont != 'n')
						{
							cout << "\nEnter y or n > ";
							cin >> cont;
						}
					}
			
					else if(cont == 'y') //if the user overwrites the file, count is now zero, meaning there is no file loaded
					{
						count = 0;
					}
			
				} while (cont != 'y' && cont != 'n');
			}
		
			if(cont != 'n') //makes sure they didnt type n, returns the n users back to menu through clever code structuring 
			{
				cout << "\nWhich movie file would you like to open? > ";
				cin >> fileName; //user types in a file that they want to open
	
				file.open(fileName); //the file is opened
	
				if(!file) //if there is no file that is able to be opened
				{
					do { //goes until a file is opened correctly
						file.clear();
		
						cout << "\nThat is not a valid file. Try again!" << endl;
						cout << "\nWhich movie file would you like to open? > ";
		
						cin >> fileName;
		
						file.open(fileName);
		
					} while(!file);
				}	
	
				file >> size; //reads the first number and declares the size of the array
				movieArr = new Movies[size];
		
				for(int x = 0; x < size; x++) //reads in data
				{
					file.getline(movieArr[x].genre, 20, ':');
			
					file.getline(movieArr[x].title, 100, ',');
		
					file >> movieArr[x].year;
		
					file >> movieArr[x].runtime;
				
					file.getline(movieArr[x].rating, 10, '\n');
				}
	
				file.close(); //closes file
		
				count++; //signals that the file has been read in
			}
		}
	
		else if(menuChoice == '2') //if the users enters a two
		{
			if(count != 0) //makes sure theres data read in thorugh the file
			{
				for(int x = 0; x < size; x++) //adds everything up
				{
					sum += movieArr[x].runtime;	
				}
				cout << "\nTotal Movie Database Runtime: " << sum / 60 << " hrs " << sum % 60 << " mins" << endl; //converts minutes to hours and minutes
	
				sum = 0; //reverts sum so people using option 2 over and over dont get different runtime totals
			}
		
			else cout << "\nUse option 1" << endl; //if theres no data loeded, use option 1
		}
	
		else if(menuChoice == '3') //option 3
		{
			if(count != 0) //makes sure data is loaded
			{
				cout << "\nView movies with what rating? (G, PG, PG-13, R) > ";
				cin >> rating2; //user types in a rating
		
				if(rating2 == "G") //if the user types in a G
				{
					cout << "\nMOVIES RATED G:" << endl;
			
					for(int x = 0; x < size; x++) //shows movies with rating G
					{
						if(strcmp(" G", movieArr[x].rating) == 0)
						{
							cout << movieArr[x].title << endl;
						}
					}
				}
		
				if(rating2 == "PG") //same thing as above for PG
				{
					cout << "\nMOVIES RATED PG:" << endl;
			
					for(int x = 0; x < size; x++)
					{
						if(strcmp(" PG", movieArr[x].rating) == 0)
						{
							cout << movieArr[x].title << endl;
						}
					}
				}
		
				else if(rating2 == "PG-13") //same thing but for PG-13
				{
					cout << "\nMOVIES RATED PG-13:" << endl;
			
					for(int x = 0; x < size; x++)
					{
						if(strcmp(" PG-13", movieArr[x].rating) == 0)
						{
							cout << movieArr[x].title << endl;
						}
					}
				}
		
				else if(rating2 == "R") //same thing but for R
				{
					cout << "\nMOVIES RATED R:" << endl;
			
					for(int x = 0; x < size; x++)
					{
						if(strcmp(" R", movieArr[x].rating) == 0)
						{
							cout << movieArr[x].title << endl;
						}
					}
				}
		
				else if(rating2 != "G" && rating2 != "PG" && rating2 != "PG-13" && rating2 != "R") //if the user types in anythign else, the code gets sassy
				{
					cout << "\nMOVIES RATED: " << rating2 << endl;
					cout << "No movies with rating " << rating2 << endl;
				}	
			}
	
			else cout << "\nUse option 1" << endl; //makes sure data is loaded from a file
		}
	
		else if(menuChoice == '4') //option 4
		{
			if(count != 0) //makes sure data is loaded
			{
				action.open("action.txt"); //opens a new file for action genre named action.txt
				drama.open("drama.txt"); //new file for drama genre
				comedy.open("comedy.txt"); //new file for comedy genre
				scifi.open("scifi.txt"); //sci fi genre
	
				for(int x = 0; x < size; x++) //writes out movie genres to the specific genre files
				{
					if(strcmp("ACTION", movieArr[x].genre) == 0 || strcmp("\nACTION", movieArr[x].genre) == 0)
					{
						action << movieArr[x].title << " (" << movieArr[x].year << ")" << endl;
					}
			
					else if(strcmp("DRAMA", movieArr[x].genre) == 0 || strcmp("\nDRAMA", movieArr[x].genre) == 0)
					{
						drama << movieArr[x].title << " (" << movieArr[x].year << ")" << endl;
					}
			
					else if(strcmp("COMEDY", movieArr[x].genre) == 0 || strcmp("\nCOMEDY", movieArr[x].genre) == 0)
					{
						comedy << movieArr[x].title << " (" << movieArr[x].year << ")" << endl;
					}
			
					else if(strcmp("SCIENCE FICTION", movieArr[x].genre) == 0 || strcmp("\nSCIENCE FICTION", movieArr[x].genre) == 0)
					{
						scifi << movieArr[x].title << " (" << movieArr[x].year << ")" << endl;
					}
				}
		
				cout << "\nExporting database by genre..." << endl;
		
				action.close(); //closes the opened files
				drama.close();
				comedy.close();
				scifi.close();
			
				cout << "...export complete." << endl;
			}
			
			else cout << "\nUse option 1" << endl;
		}
	
		else if(menuChoice == '5') //option 5 calls the clear function
		{
			if(count != 0)
			{
				clear(movieArr);
				cout << "\nDATABASE CLEARED" << endl;
				count = 0; //count = 0 to signify the file has been cleared and the user needs to open a new file
			}
		
			else cout << "\nMovie database already empty." << endl;
		}
	
		else if(menuChoice == '6') //calls the year sort function
		{
			if(count != 0)
			{
				year(size, movieArr);
			}
		
			else cout << "\nUse option 1" << endl;
		}
	
	} while(menuChoice != 'Q');
	
	delete [] movieArr; //clears up any stuff that is remaining
	movieArr = 0;
		
	return 0;
}

char menu() //the menu function that we all know and love
{
	char menuChoice; // the menu choice variable, which is a char so it can also take in ints
	
	cout << "\n1 - Load Movie File" << endl;
	cout << "2 - View Total Move Database Runtime" << endl;
	cout << "3 - View Movies by Rating" << endl;
	cout << "4 - Export Movies by Genre" << endl;
	cout << "5 - Clear Currently Loaded Database" << endl;
	cout << "6 - Print Database Sorted by Year" << endl;
	cout << "Q - Quit" << endl;
	
	cout << "Enter Choice > ";
	
	cin >> menuChoice;
	
	if(menuChoice != '1' && menuChoice != '2' && menuChoice != '3' && menuChoice != '4' && menuChoice != '5' && menuChoice != '6' && menuChoice != 'Q') //if the user doesnt type in a valid menu option
	{
		do {
			cout << "\nPlease enter a valid menu option!" << endl;
		
			cout << "\n1 - Load Movie File" << endl;
			cout << "2 - View Total Move Database Runtime" << endl;
			cout << "3 - View Movies by Rating" << endl;
			cout << "4 - Export Movies by Genre" << endl;
			cout << "5 - Clear Currently Loaded Database" << endl;
			cout << "6 - Print Database Sorted by Year" << endl;
			cout << "Q - Quit" << endl;
		
			cout << "Enter Choice > ";
		
			cin >> menuChoice;
		
		} while(menuChoice != '1' && menuChoice != '2' && menuChoice != '3' && menuChoice != '4' && menuChoice != '5' && menuChoice != '6' && menuChoice != 'Q');
	}
	
	return menuChoice; //shoots off the menu choice to main so it can be used to see which option the user picked
}

void clear(Movies movieArr[]) //the clear function, takes in the movie array so it can be deleted when called upon
{
	delete [] movieArr;
	movieArr = 0;
}

void year(int size, Movies movieArr[]) //the extra credit year sort, takes in the size of the array and the actual array so structure stuff can be called on
{
	Movies helper; //this tripped me up for a good bit, kept using ints and stuff like that
	
	for(int x = 0; x < size; x++) //double for loop to go through the data and sort it
	{
		for(int z = x + 1; z < size; z++) //this first thing took a while to understand
		{
			if(movieArr[x].year > movieArr[z].year) //if there is year greater than another
			{
				helper = movieArr[x]; //sets the stuff equal to a helper, which eventually gets set correctly after the array elements switchign places a bunch of times
				movieArr[x] = movieArr[z];
				movieArr[z] = helper;
			}
		}
	}
		
	cout << "\n";
		
	for(int x = 0; x < size; x++) //code melina gave us, free points
	{
		cout << movieArr[x].year << " : " << movieArr[x].title << endl;  
	}
}

//imma be honest, i was considering other majors while working on the beginning of option 1. then i figured out that you dont use cin for file stuff, you use the file name. everything after that was a piece of cake, unless i completely fail this and dont pass the class. that would be tragic. even though this class was rough while taking it, looking back it wasnt too bad. anyways thanks, and have a great life

//a little heads up, i need at least an 83 on this to pass this class. although i definetly should be getting over a hundred, you never know, so keep that in mind before you decide my fate :)
