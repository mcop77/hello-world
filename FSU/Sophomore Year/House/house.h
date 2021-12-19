/* Name: Marshall Copeland
Date: 09/06/20
Section: #10
Assignment: HW #1
Due Date: 09/14/20
About this project: You are to write a class called House, using filenames house.h and house.cpp, that will allow creation and handling of House objects, as described below.
Assumptions: None

All work below was performed by Marshall Copeland */

class House
{
	public:
	House(int size, char border = 'X', char fill = '*');
	
		int GetSize() const;
		int Perimeter() const;
		double Area() const;
		
		void Grow();
		void Shrink();
		
		void SetBorder(char border);
		void SetFill(char fill);
		
		void Draw() const; 
		
		void Summary() const;
	
	private:
	
	int size;
	char border;
	char fill;
	
	
};
