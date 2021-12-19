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

int main() //main function for trapped algorithm
{
	int rowInput; //creates ints and bools and stuff
	int colInput;
	bool Escape = false;
	
	cout << "Enter in a number for the amount of ROWS and COLUMNS" << endl; //cout stuff 
	
	cout << "ROWS: ";
	cin >> rowInput; //user input for rows
	
	cout << "COLUMNS: ";
	cin >> colInput; //user input for columns
	cout << "\n";
	
	Grid g(rowInput,colInput); //calls the trapped constructor
	
	g.Display(); //displays the grid
	
	do //do while loop, might be able to use a while but idk
	{
		if(g.RightIsClear() == true) //these if blocks check if the mover is able to escape
		{
			g.TurnLeft();
			g.TurnLeft();
			g.TurnLeft();
			
			g.Move(1);
			
			Escape = true;
			
		}
		
		while(g.FrontIsClear() == true) //while the mover can go forward
		{
			g.Move(1); //it moves
			
			if(g.RightIsClear() == true) //checks if it can escape
			{
				g.TurnLeft();
				g.TurnLeft();
				g.TurnLeft();
				
				g.Move(1);
				
				Escape = true;
			}
		}
	
		if(g.RightIsClear() == true) //checks again, i dont think i need this but whatever
		{
			g.TurnLeft();
			g.TurnLeft();
			g.TurnLeft();
			
			g.Move(1);
			
			Escape = true;
			
		}
		
		else g.TurnLeft(); //otherwise turns left
		
	} while(Escape == false);
	
	if(Escape == true) //if the mover escaped, this runs 
	{
		g.TurnLeft();
		g.TurnLeft();
		g.TurnLeft();
		
		cout << "YOU ESCAPED!" << endl;
		g.Display();
		
	}
}
