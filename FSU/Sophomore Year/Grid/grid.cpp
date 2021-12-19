/* Name: Marshall Copeland
Date: 10/07/20
Section: #10
Assignment: HW #4
Due Date: 10/19/20
About this project: You will write a class called Grid, and test it with a couple of programs. A Grid object will be made up of a grid of positions, numbered with rows and columns. Row and column numbering start at 0, at the top left corner of the grid. A grid object also has a "mover", which can move around to different locations on the grid. Obstacles (which block the mover) and other objects (that can be placed or picked up) are also available.

All work below was performed by Marshall Copeland */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "grid.h"

using namespace std;

//This is made possible through an INT ARRAY, see display function for the key

Grid::Grid() //no parameter constructor
{
	//row and column are both 1 length long
	Row = 1;
	Col = 1;
	
	//default direction for this constructor is east
	East = true;
	
	//initializes array to be all dots
	for(int x = 0; x < Row; x++)
	{
		for(int y = 0; y < Col; y++)
		{
			if(x == 1 && y == 1)
			{
				array[x][y] = 9;
			}
			
			array[x][y] = 0;
		}
	}
	
	PathSetting = true; //not really sure what these do
	OneXOne = true;
	Count = 3;
}

Grid::Grid(int r, int c) //2 parameter constructor for the trapped program
{
	srand(time(0)); //seeds the random variable
	
	Row = r; //the inputted rows and columns are set to these private variables
	Col = c;
	
	if(Row < 3 || Col < 3) //these 2 if statements check if the inputted numbers are in the allowable range
	{
		Row = 3;
		Col = 3;
	}
	
	else if(Row > 40 || Col > 40)
	{
		Row = 40;
		Col = 40;
	}
	
	int moverX = rand() % (Row - 2) + 1; //random variables
	int moverY = rand() % (Col - 2) + 1;
	int moverDirection = rand() % 4;
	
	int wallNum = rand() % 4;
	int wallPositionX = rand() % (Row - 2) + 1;
	int wallPositionY = rand() % (Col - 2) + 1;
	
	
	//initializes the array
	for(int x = 0; x < Row; x++)
	{
		for(int y = 0; y < Col; y++)
		{
			if(x == 0)
			{
				if(wallNum == 0 && y == wallPositionY)
				{
					array[x][y] = 4;
				}
				
				else array[x][y] = 2;
			}
			
			else if(y == 0 && x != 0)
			{
				if(wallNum == 1 && x == wallPositionX)
				{
					array[x][y] = 4;
				}
				
				else array[x][y] = 2;
			}
			
			else if(x == Row - 1)
			{
				if(wallNum == 2 && y == wallPositionY)
				{
					array[x][y] = 4;
				}
				
				else array[x][y] = 2;
			}
			
			else if(y == Col - 1 && x != Row - 1)
			{
				if(wallNum == 3 && x == wallPositionX)
				{
					array[x][y] = 4;
				}
				
				else array[x][y] = 2;
			}
			
			else if(x == moverX && y == moverY)
			{
				if(moverDirection == 0)
				{
					array[x][y] = 6;
					Direction = NORTH;
					CurrentRow = x;
					CurrentCol = y;
				}
				
				else if(moverDirection == 1)
				{
					array[x][y] = 7;
					Direction = WEST;
					CurrentRow = x;
					CurrentCol = y;
				}
				
				else if(moverDirection == 2)
				{
					array[x][y] = 8;
					Direction = SOUTH;
					CurrentRow = x;
					CurrentCol = y;
				}
				
				else if(moverDirection == 3)
				{
					array[x][y] = 9;
					Direction = EAST;
					CurrentRow = x;
					CurrentCol = y;
				}
			}
			
			else array[x][y] = 0;
		}
	}
	
	PathSetting = true; //again, not sure what these do
	Count = 1; //actually this one lets the functions know which constuctor is being run
}

Grid::Grid(int r, int c, int mr, int mc, int d) //5 parameter constructor 
{
	Row = r; //sets the private variables
	Col = c;
	
	StartCordRow = mr; //for instance, these are the mover coordinates
	StartCordCol = mc;
	Direction = d; //this is the direction of the mover
	
	//when the row/column is bigger or smaller than what is allowed
	if(Row < 1)
	{
		Row = 1;
	}
		
	if(Col < 1)
	{
		Col = 1;
	}		
	
	if(Row > 40)
	{
		Row = 40;
	}
		
	if(Col > 40)
	{
		Col = 40;
	}	
	
	//when the start coordinates are bigger or smaller than the array length and width
	if(StartCordRow < 0)
	{
		StartCordRow = 0;
	}
	
	else if(StartCordRow > Row - 1)
	{
		StartCordRow = Row - 1;
	}
	
	if(StartCordCol < 1)
	{
		StartCordCol = 0;
	}
	
	else if(StartCordCol > Col - 1)
	{
		StartCordCol = Col - 1;
	}
	
	//initializes array to be all dots
	for(int x = 0; x < Row; x++)
	{
		for(int y = 0; y < Col; y++)
		{
			array[x][y] = 0;
		}
	}
	
	//sets the direction that the mover is facing from the parameters
	if(Direction == NORTH)
	{
		array[StartCordRow][StartCordCol] = 6;
	}
	
	else if(Direction == WEST)
	{
		array[StartCordRow][StartCordCol] = 7;
	}
	
	else if(Direction == SOUTH)
	{
		array[StartCordRow][StartCordCol] = 8;
	}
	
	else if(Direction == EAST)
	{
		array[StartCordRow][StartCordCol] = 9;
	}
		
	//keeps track of the current position of the mover
	CurrentRow = StartCordRow;
	CurrentCol = StartCordCol;
	
	PathSetting = true;
	Count = 2; //i know what this does, lets the other functions now what constructor is being run
}

bool Grid::Move(int s) //move function, takes in a number that determines how many blocks the mover travels
{
	int count = 0; //count variable that allows things to be run a certain number of times
	test = false; //test bolean that makes sure the item hover part works
	
	if(Direction == NORTH) //the next major if statements determine which direction the mover is facing
	{
		for(int x = 0; x < s; x++) //for loop runs as long as the mover is in bounds and is not going into a wall
		{
			if(array[CurrentRow - x][CurrentCol] != 2 && CurrentRow - x >= 0)
			{
				count++; //count increments
			}
		}
		
		if(count == s) //if the count is equal to the amount of desired spaces, the next loop runs becuase it can
		{
			for(int a = 0; a < s; a++) //runs s amount of times
			{				
				if(array[CurrentRow - a][CurrentCol] == 1) //if the next space it goes to is an item, it makes sure its kept one
				{
					array[CurrentRow - a][CurrentCol] = 1;
				}
				
				else if(array[CurrentRow - a][CurrentCol] != 1) //otherwise it is a space, which is the path it goes
				{
					array[CurrentRow - a][CurrentCol] = 5;
				}
			}
					
			CurrentRow = CurrentRow - s; //changes the current postition
			
			if(array[CurrentRow][CurrentCol] == 1)
			{
				test = true; //if it is on an item, it will mak it do the hover thing
			}
			
			array[CurrentRow][CurrentCol] = 6; //then it makes the mover north	
		}
	}
	
	else if(Direction == WEST) //same thing as above, but travelling west
	{
		for(int y = 0; y < s; y++)
		{
			if(array[CurrentRow][CurrentCol - y] != 2 && CurrentCol - y >=  0)
			{
				count++;
			}
			
		}
		
		if(count == s)
		{
			for(int b = 0; b < s; b++)
			{
				if(array[CurrentRow][CurrentCol - b] == 1)
				{
					array[CurrentRow][CurrentCol - b] = 1;
				}
				
				else if(array[CurrentRow][CurrentCol - b] != 1)
				{
					array[CurrentRow][CurrentCol - b] = 5;
				}
			}
					
			CurrentCol = CurrentCol - s;
			
			if(array[CurrentRow][CurrentCol] == 1)
			{
				test = true;
			}
			
			array[CurrentRow][CurrentCol] = 7; //west mover
		}
	}
	
	else if(Direction == SOUTH) //same thing but south
	{
		for(int p = 0; p < s; p++)
		{
			if(array[CurrentRow + p][CurrentCol] != 2 && CurrentRow + p <= Row - 1)
			{
				count++;
			}
		}
	
		if(count == s)
		{
			for(int c = 0; c < s; c++)
			{
				if(array[CurrentRow + c][CurrentCol] == 1)
				{
					array[CurrentRow + c][CurrentCol] = 1;
				}
				
				else if(array[CurrentRow + c][CurrentCol] != 1)
				{
					array[CurrentRow + c][CurrentCol] = 5;
				}
			}
		
			CurrentRow = CurrentRow + s;
			
			if(array[CurrentRow][CurrentCol] == 1)
			{
				test = true;
			}
			
			array[CurrentRow][CurrentCol] = 8; //south mover
		}
	}
	
	else if(Direction == EAST) //same but east
	{
		for(int q = 0; q < s; q++)
		{
			if(array[CurrentRow][CurrentCol + q] != 2 && CurrentCol + q <= Col - 1)
			{
				count++;
			}
		}
		
		if(count == s)
		{
			for(int d = 0; d < s; d++)
			{
				if(array[CurrentRow][CurrentCol + d] == 1)
				{
					array[CurrentRow][CurrentCol + d] = 1;
				}
				
				else if(array[CurrentRow][CurrentCol + d] != 1)
				{
					array[CurrentRow][CurrentCol + d] = 5;
				}
			}
						
			CurrentCol = CurrentCol + s;
			
			if(array[CurrentRow][CurrentCol] == 1)
			{
				test = true;
			}
			
			array[CurrentRow][CurrentCol] = 9; //east mover
		}
	}
}	

void Grid::TogglePath() //turns the path on an off, theres more in the display function
{
	if(PathSetting == true)
	{
		PathSetting = false;
	}
	
	else PathSetting = true;
}

void Grid::TurnLeft() //turns the mover left
{
	if(Direction == NORTH) //if north, it turns to the west
	{
		if(Count == 1) //if the trapped cinstructor runs
		{
			array[CurrentRow][CurrentCol] = 7; //the array value is changed
			Direction = WEST;
		}
		
		Direction = WEST; //otherwise just the direction is changed
	}
	
	else if(Direction == WEST) //same as above, but west to south
	{
		if(Count == 1)
		{
			array[CurrentRow][CurrentCol] = 8;
			Direction = SOUTH;
		}
		
		Direction = SOUTH;
	}
	
	else if(Direction == SOUTH) //south to east
	{
		if(Count == 1)
		{
			array[CurrentRow][CurrentCol] = 9;
			Direction = EAST;
		}
		
		Direction = EAST;
	}
	
	else if(Direction == EAST) //east to north
	{
		if(Count == 1)
		{
			array[CurrentRow][CurrentCol] = 6;
			Direction = NORTH;
		}
		
		Direction = NORTH;
	}
}

void Grid::PutDown() //puts down an item at the curent position
{
	array[CurrentRow][CurrentCol] = 1; //array position is now an item
}

bool Grid::PutDown(int r, int c) //puts down an item at coordinates that are in the array and not on a wall
{
	if(r <= Row && r >= 1 && c <= Col && c >= 1)
	{
		if(array[r][c] != 1 && array[r][c] != 2 || (array[r][c] != 1 && array[r][c] != 2 && Direction == NORTH) || (array[r][c] != 1 && array[r][c] != 2 && Direction == WEST) || (array[r][c] != 1 && array[r][c] != 2 && Direction == SOUTH) || (array[r][c] != 1 && array[r][c] != 2 && Direction == EAST))
		{
			array[r][c] = 1; //places the item
			return true;
		}
		
		else return false; //otherwise returns false
	}
	
	else return false;
}

bool Grid::PickUp() //removes item from the grid
{
	if(array[CurrentRow][CurrentCol] != 0) //makes sure there is an item 
	{
		if(Direction == North) //over writes to be north mover
		{
			array[CurrentRow][CurrentCol] = 6;
		}
		
		else if(Direction == West) //west mover
		{
			array[CurrentRow][CurrentCol] = 7;
		}
		
		else if(Direction == South) //south mover
		{
			array[CurrentRow][CurrentCol] = 8;
		}
		
		else if(Direction == East) //east moc=ver
		{
			array[CurrentRow][CurrentCol] = 9;
		}
		
		test = false; //changes the hover to be false
		return true; //returns true
	}
	
	else return false; //otherwise it is false
}

bool Grid::PlaceBlock(int r, int c) //places block at a coordinate the "user" picks
{
	if(r <= Row && r >= 0 && c <= Col && c >= 0) //makes sure it is in bounds
	{
		if(array[r][c] == 0) //makes sure it only goes over dots
		{
			array[r][c] = 2; //the new array value is a block
			return true; //returns true
		}
		
		else return false; //else false
	}
	else return false;
}

void Grid::Grow(int gr, int gc) //grows the grid by however many the user wants, as long as its between 3 and 40
{
	if(Row + gr <= 40)
	{
		Row = Row + gr;
	}
	
	else Row = 40;
	
	if(Col + gc <= 40)
	{
		Col = Col + gc;
	}
	
	else Col = 40;
}

void Grid::Display() const //the good old display function
{
	char dot = '.';       // = 0
	char item = '0';      // = 1
	char wall = '#';      // = 2
	char overItem = '@';  // = 3
	char exitSpace = ' '; // = 4
	char space = ' ';     // = 5
	char north = '^';     //directions will be outputted if they are TRUE, = 6
	char west = '<';      // = 7
	char south = 'v';     // = 8
	char east = '>';      // = 9
			
	cout << "The Grid:" << endl; //simple cout 
	
	for(int x = 0; x < Row; x++) //double for loops, runs for the rows and the columns
	{
		for(int y = 0; y < Col; y++)
		{
			if(array[x][y] == 0) //if the array value is 0, a dot "." is printed, as well as a space
			{
				cout << dot << space;
			}
			
			else if(array[x][y] == 1) //a 1 means a item is printed
			{
				if(x != CurrentRow || y != CurrentCol) //as long as it isnt the where the mover is
				{
					cout << item << space;
				}
			}
			
			else if(array[x][y] == 2) //a 2 prints a wall
			{
				cout << wall << space;
			}
			
			else if(array[x][y] == 4) //the 3 is later, but a 4 is an exit space for the trapped program
			{
				cout << exitSpace << space;
			}
			
			else if(array[x][y] == 5) //5 is a space
			{
				if(PathSetting == true) //makes sure the path setting is on to print a space, otherwise its a dot
				{
					cout << space << space;
				}
				
				else cout << dot << space;
			}
			
			if(Count == 1) //if the trapped constructor is run
			{
				if(Direction == NORTH)
				{
					if(array[x][y] == 6) //prints north mover
					{		
						cout << north << space;
					}				
				}
				
				else if(Direction == WEST)
				{
					if(array[x][y] == 7) //prints west mover
					{
						cout << west << space;
					}
				}
				
				else if(Direction == SOUTH) //south mover
				{
					if(array[x][y] == 8)
					{
						cout << south << space;
					}
				}
				
				else if(Direction == EAST) //east mover
				{
					if(array[x][y] == 9)
					{
						cout << east << space;
					}
				}
			}
			
			if(x == CurrentRow && y == CurrentCol) //the over item stuff
			{
				if(array[CurrentRow][CurrentCol] == 1) //if the mover is over the item
				{
					cout << overItem << space;
				}
				
				else if(test == true && (array[CurrentRow][CurrentCol] == 6 || array[CurrentRow][CurrentCol] == 7 || array[CurrentRow][CurrentCol] == 8 || array[CurrentRow][CurrentCol] == 9)) //or if the test is true
				{
					cout << overItem << space;
				}
				
				else if(test == false && Count != 1) //otherwise prints the direction
				{
					if(Direction == NORTH)
					{
						cout << north << space;
					}
			
					else if(Direction == WEST)
					{
						cout << west << space;
					}
					
					else if(Direction == SOUTH)
					{
						cout << south << space;
					}
			
					else if(Direction == EAST)
					{
						cout << east << space;
					}
				}
			}
		}
		
		cout << endl; //after every row a new line is printed
	}
	
	cout << endl; //after the function a newline is printed
}

bool Grid::FrontIsClear() const //checks if the front is clear
{	
	if(Count == 1) //checks what constructor was run
	{
		if(Direction == NORTH) //if facing north
		{
			if(array[CurrentRow - 1][CurrentCol] != 2 && array[CurrentRow - 1][CurrentCol] != 4 &&CurrentRow - 1 >= 0) //checks if its clear
			{
				return true; //true
			}
			
			else return false; //otherwise its false
		}
		
		else if(Direction == WEST) //same but west
		{
			if(array[CurrentRow][CurrentCol - 1] != 2 && array[CurrentRow][CurrentCol - 1] != 4 && CurrentCol - 1 >= 0)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == SOUTH) //south
		{
			if(array[CurrentRow + 1][CurrentCol] != 2 && array[CurrentRow + 1][CurrentCol] != 4 && CurrentRow + 1 <= Row - 1)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == EAST) //east
		{
			if(array[CurrentRow][CurrentCol + 1] != 2 && array[CurrentRow][CurrentCol + 1] != 4 && CurrentCol + 1 <= Col - 1)
			{
				return true;
			}
			
			else return false;
		}
	}

	else //same as above but doesnt worry about exit char
	{
		if(Direction == NORTH)
		{
			if(array[CurrentRow - 1][CurrentCol] != 2 && CurrentRow - 1 >= 0)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == WEST)
		{
			if(array[CurrentRow][CurrentCol - 1] != 2 && CurrentCol - 1 >= 0)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == SOUTH)
		{
			if(array[CurrentRow + 1][CurrentCol] != 2 && CurrentRow + 1 <= Row - 1)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == EAST)
		{
			if(array[CurrentRow][CurrentCol + 1] != 2 && CurrentCol + 1 <= Col - 1)
			{
				return true;
			}
			
			else return false;
		}
	}
}

bool Grid::RightIsClear() const //checks if right is clear
{
	if(Count == 1) //trapped constructor
	{
		if(Direction == NORTH)
		{
			if(array[CurrentRow][CurrentCol + 1] == 4 && CurrentCol + 1 <= Col - 1) //if the trap constructor is run, it checks if the right is the exit
			{
				return true; //if true, returns true
			}
		
			else return false; //else returns false
		}
	
		else if(Direction == WEST) //checks the north for the exit
		{
			if(array[CurrentRow - 1][CurrentCol] == 4 && CurrentRow - 1 >= 0)
			{
				return true;
			}
		
			else return false;
		}
	
		else if(Direction == SOUTH) //checks west for exit
		{
			if(array[CurrentRow][CurrentCol - 1] == 4 && CurrentCol - 1 >= 0)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == EAST) //checks south for exit
		{
			if(array[CurrentRow + 1][CurrentCol] == 4 && CurrentRow + 1 <= Row - 1)
			{
				return true;
			}
			
			else return false;
		}
	}
	
	else //otherwise the regular is ran
	{
		if(Direction == NORTH)
		{
			if(array[CurrentRow][CurrentCol + 1] != 2 && CurrentCol + 1 <= Col - 1)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == WEST)
		{
			if(array[CurrentRow - 1][CurrentCol] != 2 && CurrentRow - 1 >= 0)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == SOUTH)
		{
			if(array[CurrentRow][CurrentCol - 1] != 2 && CurrentCol - 1 >= 0)
			{
				return true;
			}
			
			else return false;
		}
		
		else if(Direction == EAST)
		{
			if(array[CurrentRow + 1][CurrentCol] != 2 && CurrentRow + 1 <= Row - 1)
			{
				return true;
			}
			
			else return false;
		}
	}
}

int Grid::GetRow() const //returns the current row
{
	return CurrentRow;
}

int Grid::GetCol() const //returns the current column
{
	return CurrentCol;
}

int Grid::GetNumRows() const //returns the number of rows
{
	return Row;
}

int Grid::GetNumCols() const //returns the number of columns
{
	return Col;
}



//"...every assignment i think it can't get any worse, then i get to the next assignment" -Confucious i think
