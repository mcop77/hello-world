/* Name: Marshall Copeland
Date: 02/23/2020
Section: #4
Assignment: Homework #4
Due Date: 03/03/2020
About this project: This program presents the user with a menu, on which includes three games: Guess the Number, High Low, and Collect Pairs. The menu also allows the user to view statistics, reset statistics and read rules of the games.
Assumptions: None
All work below was performed by Marshall Copeland */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


int menu(); //menu function

bool guessNumber(); //first game guessNumber function, which returns a true or false
bool highLow(); //second game highLow function, which returns a true or false
bool collectPairs(); //third game collectPairs function, which returns a true or false


void viewStats(int wins, int losses); //outputs stats after taking in number of wins and losses
void resetStatistics(int & wins, int & losses); //resets the number of wins and losses
void printRules(); //prints rules given by Melina 



int main() //beginning of main where all of the functions are called
{
	srand(time(0)); //seeds random variables based on time to generate a random variable

	int wins = 0; //sets wins equal to zero
	int losses = 0; //sets losses equal to zero
	
	int menuChoice; //helps determine what the user inputs


	do { //do while loop that cycles the whole program
	
		menuChoice = menu(); //calls menu
	
	
		while(menuChoice > 6 || menuChoice < 0) //runs as long as correct numbers are entered, otherwise it asks for correct numbers until that happens
		{
			cout << "Enter an item on the Menu: ";
			cin >> menuChoice;
		}
	
		if(menuChoice == 0) //exit statement
		{
			viewStats(wins, losses); //shows stats of the games played
			cout << "Thanks for playing!" << endl;
		}
	
		if(menuChoice == 1) //if the user enters a one
		{
			
			if(guessNumber() == true) //calls guessNumber function which is the first game
			{
				wins++; //if the users wins the game, that win is kept track of
			}
			
			else losses++; //else the loss is kept track of
			
		}
	
		else if(menuChoice == 2) 
		{
			
			if(highLow() == true) //calls second game, keeps track of wins and losses
			{
				wins++; 
			}
			
			else losses++;
			
		}
	
		else if(menuChoice == 3)
		{
			
			if(collectPairs() == true) //third game, wins and losses are, you guessed it, kept track of
			{
				wins++;
			}
			
			else losses++; 
		}
		
	
		else if(menuChoice == 4)
		{
			viewStats(wins, losses); //outputs game stats that are recorded until resetStats is called
		}
	
		else if(menuChoice == 5)
		{
			resetStatistics(wins, losses); //resets the stats, not much really goes on here
		}
	
		else if(menuChoice == 6)
		{
			printRules(); //prints rules given by Melina, easiest function to do by far
		}
		
		
	} while(menuChoice != 0); //this makes it work, although I would think that the first if statement would take care of it, so im not quite sure
	
	
	return 0; //end of main, now on to more treacherous territory
}


/*Function definition for MENU 
this function should print the menu for the user and ask/obtain their menu choice.
this function will return the user's menu choice after verifying it's a valid choice on the menu.*/

int menu()
{
	int menuChoice;
	
		cout << "GAME MENU:" << endl;
		cout << "--------------------------" << endl;
		cout << "1: PLAY Guess the Number" << endl;
		cout << "2: PLAY High Low" << endl;
		cout << "3: PLAY Collect Pairs" << endl;
		cout << "4: View Statistics" << endl;
		cout << "5: Reset Statistics" << endl;
		cout << "6: RULES" << endl;
		cout << "0: Quit" << endl;
		cout << "--------------------------" << endl;
		cout << "> ";
		
		cin >> menuChoice; //user gives input
		
	
	return menuChoice; //input is sent to main to be checked for its content and decides what to do from there
}


/*Function definition for GUESSNUMBER
this function is invoked whenever the user wants to play Guess Number.
this function returns true/false depending on if the user wins the game or not*/

bool guessNumber()
{
	int num; //this int will grow up and hold the random number that will be checked against the user input
	int guess; //this int will grow up and hold the user input that will be checked against the random number
	int count = 1; //as you will see as the program goes on, i prefer to use count and while loops rather than for loops, not quite sure but it gets the job done
	
	num = rand() % 100 + 1;
	
	cout << "\n\nGuess the Number, 1 --> 100!" << endl; //outputs instructions to screen
	
	while(count < 7)
	{
		cout << "Attempt " << count << "/6 : "; //lets user know which attempt it is out of 6
		cin >> guess;
		
		while(guess > 100 || guess < 1) //error checking 
		{
			cout << "Enter a number 1 --> 100!" << endl;
			cout << "Attempt " << count << "/6 : ";
			cin >> guess;
		}
		
		if(guess < num) //if the user input is less than the random number...
		{
			cout << "TOO SMALL." << endl; //...it lets the user know that they need to guess higher next time
			count++; //good 'ol count making sure the code keeps cycling until six attempts
		}
		
		else if(guess > num) //otherwise the number guessed was too big and needs to be lower
		{
			cout << "TOO BIG." << endl;
			count++;
		}
		
		else if(guess == num) //if you guess the random number in 6 tries or less you get an epic victory royale *insert face with sunglasses emoji or other ironic epic win conveying emoji
		{
			cout << "You Win!\n" << endl;
			return true; //returns true ti keep track of wins, which is kept track of in main
		}
		
		if(count == 7) //if count gets to seven, you didnt guess the number in enough tries and you lose
		{
			cout << "Sorry, you lose. The number was " << num << "\n" << endl;
			return false; //keeps track of losses in main
		}
	}
}


/*Function definition for HIGHLOW
this function is invoked whenever the user wants to play high low.
this function returns true/false depending on if the user wins the game or not*/

bool highLow() //the second game called high low that returns a true or false value depending on whether the usser wins or loses
{
	int num; //first round random number
	int num2; //second random number
	int num3; //same thing
	int num4;
	int num5;
	int num6;
	
	char guess; //whatever the user enters
	int count = 1; //count that cycles through the loop
	

	cout << "High or Low! Stay alive for 5 rounds to win! (Numbers range from 1 to 1000)" << endl; //output to screen
	
	
	while(count < 6) //runs throught the loop 5 times max
	{
		num = rand() % 1000 + 1; //actually generates the random number
		num2 = rand() % 1000 + 1;
		num3 = rand() % 1000 + 1;
		num4 = rand() % 1000 + 1;
		num5 = rand() % 1000 + 1;
		num6 = rand() % 1000 + 1;
		
		if(count == 1) //the first round
		{
			cout << "Round " << count << " of 5. The number is " << num << endl;
			cout << "\t... is the next number [H]igher or [L]ower?: ";
			cin >> guess;
			
			while(guess != 'H' && guess != 'L' && guess != 'h' && guess != 'l') //makes sure the user enters in a valid number
			{
				cout << "\tEnter H or L: ";
				cin >> guess; //takes in the guess
			}
			
			if((guess == 'H' || guess == 'h') && num2 > num) //if the user guesses high and that is correct, they move on to the next round
			{
				cout << "The next number is: " << num2 << endl;
				cout << "Correct!" << endl;
				count++; //count increases as they move on
			}
			
			else if((guess == 'L' || guess == 'l') && num > num2) //if the user guesses low and that is correct, they move on to the next round
			{
				cout << "The next number is: " << num2 << endl;
				cout << "Correct!" << endl;
				count++;
			}
		
			else 
			{
				cout << "The next number is: " << num2 << endl; //otherwise the loop is broken 
				cout << "Sorry, you lose\n" << endl;
				return 0;
			}
		}
		
		if(count == 2) //same thing for all of the rounds
		{
			cout << "Round " << count << " of 5. The number is " << num2 << endl;
			cout << "\t... is the next number [H]igher or [L]ower?: ";
			cin >> guess;
			
			while(guess != 'H' && guess != 'L' && guess != 'h' && guess != 'l')
			{
				cout << "\tEnter H or L: ";
				cin >> guess;
			}
			
			if((guess == 'H' || guess == 'h') && num3 > num2)
			{
				cout << "The next number is: " << num3 << endl;
				cout << "Correct!" << endl;
				count++;
			}
			
			else if((guess == 'L' || guess == 'l') && num2 > num3)
			{
				cout << "The next number is: " << num3 << endl;
				cout << "Correct!" << endl;
				count++;
			}
		
			else 
			{
				cout << "The next number is: " << num3 << endl;
				cout << "Sorry, you lose\n" << endl;
				return 0;
			}
		}
		
		if(count == 3)
		{
			cout << "Round " << count << " of 5. The number is " << num3 << endl;
			cout << "\t... is the next number [H]igher or [L]ower?: ";
			cin >> guess;
			
			while(guess != 'H' && guess != 'L' && guess != 'h' && guess != 'l')
			{
				cout << "\tEnter H or L: ";
				cin >> guess;
			}
			
			if((guess == 'H' || guess == 'h') && num4 > num3)
			{
				cout << "The next number is: " << num4 << endl;
				cout << "Correct!" << endl;
				count++;
			}
			
			else if((guess == 'L' || guess == 'l') && num3 > num4)
			{
				cout << "The next number is: " << num4 << endl;
				cout << "Correct!" << endl;
				count++;
			}
		
			else 
			{
				cout << "The next number is: " << num4 << endl;
				cout << "Sorry, you lose\n" << endl;
				return 0;
			}
		}
		
		if(count == 4)
		{
			cout << "Round " << count << " of 5. The number is " << num4 << endl;
			cout << "\t... is the next number [H]igher or [L]ower?: ";
			cin >> guess;
			
			while(guess != 'H' && guess != 'L' && guess != 'h' && guess != 'l')
			{
				cout << "\tEnter H or L: ";
				cin >> guess;
			}
			
			if((guess == 'H' || guess == 'h') && num5 > num4)
			{
				cout << "The next number is: " << num5 << endl;
				cout << "Correct!" << endl;
				count++;
			}
			
			else if((guess == 'L' || guess == 'l') && num4 > num5)
			{
				cout << "The next number is: " << num5 << endl;
				cout << "Correct!" << endl;
				count++;
			}
		
			else 
			{
				cout << "The next number is: " << num5 << endl;
				cout << "Sorry, you lose\n" << endl;
				return 0;
			}
		}
		
		if(count == 5)
		{
			cout << "Round " << count << " of 5. The number is " << num5 << endl;
			cout << "\t... is the next number [H]igher or [L]ower?: ";
			cin >> guess;
			
			while(guess != 'H' && guess != 'L' && guess != 'h' && guess != 'l')
			{
				cout << "\tEnter H or L: ";
				cin >> guess;
			}
			
			if((guess == 'H' || guess == 'h') && num6 > num5)
			{
				cout << "The next number is: " << num6 << endl;
				cout << "Correct!" << endl;
				cout << "You WIN!\n" << endl;
				count++;
				return true; //on the final try if they guess correctly they win the game and true is returned to show a win
			}
			
			else if((guess == 'L' || guess == 'l') && num5 > num6)
			{
				cout << "The next number is: " << num6 << endl;
				cout << "Correct!" << endl;
				cout << "You WIN!\n" << endl;
				count++;
				return true; //same thing as above but by guessing low correctly and winning on the last round
			}
		
			else 
			{
				cout << "The next number is: " << num6 << endl;
				cout << "Sorry, you lose\n" << endl;
				return 0;
			}
		}
		
		else return 0;
	}
	
	return false; //otherwise they lose the game
}


/*Function definition for COLLECTPAIRS
this function is invoked whenever the user wants to play Collect Pairs.
this function returns true/false depending on if the user wins the game or not*/

bool collectPairs()
{
	int onesCount = 0; //count the number of times a pair of ones are rolled
	int twosCount = 0; //same thing for twos
	int threesCount = 0; //you get the gist
	int foursCount = 0;
	int fivesCount = 0;
	int sixesCount = 0;
	
	
	for(int x = 0; x < 101; x++) //for loop that will cycle the rolling of two dice 100 times
	{
		int die = rand() % 6 + 1; //establishes a random number 1 - 6 for die 1
		int die2 = rand() % 6 + 1; //establishes a random number 1 - 6 for die 2
		
		if(die == 1 && die2 == 1) //if both of the dice are ones
		{
			onesCount++; //the count of ones is increased every time a pair of ones is rolled
			
			if(onesCount == 1) //if the pair of dice is rolled and they are both ones
			{
				cout << "PAIR OF ONES found" << endl; //a pair of ones is printed to the screen
			}
		}
		
		else if(die == 2 && die2 == 2) //same thing as above but for twos
		{
			twosCount++;
			
			if(twosCount == 1)
			{
				cout << "PAIR OF TWOS found" << endl;
			}
		}
		
		else if(die == 3 && die2 == 3) //same thing for threes
		{
			threesCount++;
			
			if(threesCount == 1)
			{
				cout << "PAIR OF THREES found" << endl;
			}
		}
		
		else if(die == 4 && die2 == 4) //nothing different here
		{
			foursCount++;
			
			if(foursCount == 1)
			{
				cout << "PAIR OF FOURS found" << endl;
			}
		}
		
		else if(die == 5 && die2 == 5)
		{
			fivesCount++;
			
			if(fivesCount == 1)
			{
				cout << "PAIR OF FIVES found" << endl;
			}
		}
		
		else if(die  == 6 && die2 == 6)
		{
			sixesCount++;
			
			if(sixesCount == 1)
			{
				cout << "PAIR OF SIXES found" << endl;
			}
		}
	}
	
		if(onesCount >= 1 && twosCount >= 1 && threesCount >= 1 && foursCount >= 1 && fivesCount >= 1 && sixesCount >= 1) //if all the numbers were rolled as a pair
		{
			cout << "\nYou WIN!\n" << endl; //you win the game
			return true; //and true is returned to main to keep track of the wins
		}
		
		else cout << "\nSorry, you lose.\n" << endl; //otherwise they lose and false is returned

	return false;
}

/*Function definition for VIEWSTATS
this function takes in the number of wins, and losses that the user had while playing their games
this function then prints the win and loss stats neatly to the screen, and returns no value*/

void viewStats(int wins, int losses)
{
	int menuChoice; //keeps track of the menu choice
	double total = wins + losses; //total number of games by adding wins and losses, is a double because the win percent is a double
	
	double winPercent; //total wins divided by total games to get a percentage
	
	if(total == 0) //if stats are called first, the wins, losses, and win percent are all zero
	{
		winPercent = 0;
	}
	
	else winPercent = wins / total; //otherwise if games are won or lost, the win perentage is calculated
	

	cout << "\n\nSTATISTICS:" << endl; //outputs the wins and losses and win percentage
	cout << "--------------------------" << endl;
	cout << "Wins: " << wins << "          Losses: " << losses << endl;
	cout << "Total Win Percent: " << showpoint << fixed << setprecision(1) << winPercent * 100 << "%\n" << endl;
	
}

void resetStatistics(int & wins, int & losses) //clears the games history and sets wins and losses to zero
{
	wins = 0;
	losses = 0;
	
	cout << "\nStatistics Reset!\n" << endl; //once the stats are reset it will let you know
}


void printRules() //thx melina, rules that are given to show the user how to play the games correctly
{
    cout << "\nRULES:\n\nGuess the Number Game:\nYou'll only get 6 tries to guess a number between 1 and 100!\nGuess Wisely!\n\n";
    cout << "High/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then YOU WIN!\n\n";
    return;
}


//i cant stress this enough, there is no way i would ever in a million years be able code all of this by myself. shoutout to office hours that i went to like four times to help me with a lot of stuff. this is waaaay to long and hard to do at our skill level imo, like over 500 lines of code only a month and a half into programming in a new language seems very excessive. thats it, not very fun coding and took up a lot of time. games arent that fun either. rate 3/10
