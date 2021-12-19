/* Name: Marshall Copeland
Date: 10/07/20
Section: #10
Assignment: HW #4
Due Date: 10/19/20
About this project: You will write a class called Grid, and test it with a couple of programs. A Grid object will be made up of a grid of positions, numbered with rows and columns. Row and column numbering start at 0, at the top left corner of the grid. A grid object also has a "mover", which can move around to different locations on the grid. Obstacles (which block the mover) and other objects (that can be placed or picked up) are also available.

All work below was performed by Marshall Copeland */

// Grid class

class Grid
{
	public:
   // public static class constants, for direction indicators
	static const int NORTH = 0;
	static const int WEST = 1;
	static const int SOUTH = 2;
	static const int EAST = 3;

	// public member funcitons

	Grid();			// build 1 x 1 grid with mover in only
				//  square, facing east
	Grid(int r, int c);		// build grid with r rows, c cols,
				//  blocks around edge with random exit
				//  and random mover position and direction

	Grid(int r, int c, int mr, int mc, int d);
			// build empty grid with r rows, c cols, and mover
                        //  at row mr, col mc, and facing direction d

	bool Move(int s);		// move forward s spaces, if possible
	void TogglePath();		// toggle whether or not moved path is shown
	void TurnLeft();		// turn the mover to the left
	void PutDown();		// put down an item at the mover's position
	bool PutDown(int r, int c);  // put down an item at (r,c), if possible
	bool PickUp();		// pick up item at current position
	bool PlaceBlock(int r, int c);	// put a block at (r,c), if possible
	void Grow(int gr, int gc);	// grow the grid by gr rows, gc columns


	void Display() const;	// display the grid on screen

	// Accessors
	bool FrontIsClear() const;	// check to see if space in front of 
				//  mover is clear
	bool RightIsClear() const;	// check to see if space to right of 
				//  mover is clear
	int GetRow() const;		// return row of the mover
	int GetCol() const;		// return column of the mover
	int GetNumRows() const;	// return number of rows in the grid
	int GetNumCols() const;	// return number of columns in the grid
   
private: //private variables
	int array[40][40]; //initializes the grid
	int Row; //row and col variable
	int Col;
	int StartCordRow; //keeps track of the start coordinates
	int StartCordCol;
	int CurrentRow; //keeps track of the current coordinates
	int CurrentCol;
	int Direction; //direction of the mover
	
	//these bools make it easier to determine what direction the mover is facing, i dont use them
	bool North;
	bool West;
	bool South;
	bool East;
	
	//these bools tell the functions what conststructor is being run, i dont use them
	bool OneXOne;
	bool TrapXTrap;
	bool XXX;
	
	int Count; //i use this though, it tells me what constructor is being run
	
	//this bool determines whether the TogglePath is on/off
	bool PathSetting; //true means the path is showing
	
	bool Item; //dont remember this one
	
	bool onItem; //checks to see if the mover is on the item or not
	
	bool test; //makes the hover thing work
};
