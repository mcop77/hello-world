#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

void menu();
int stringToInt(string str);

int main()
{
	vector<string> ops;
	
	string input;
	
	int scoreSum;
	
	cout << "Welcome to the 2020 World Series!" << endl;
	
	do{
		cout << "Enter in an option from the menu below\n" << endl;
		
		menu();
		
		cout << "Enter in a string: ";
		cin >> input;
		
		if(int(input[0]) < 58)
		{
			ops.push_back(input);
		}
		
		else if(input == "+")
		{
			int tempInt;
			int tempInt2;
			int total;
		
			string tempString;
			
			for(int x = 0; x < ops.size(); x++)
			{
				if(x == ops.size() - 2)
				{
					stringstream tempInt(ops[x]);
				}
				
				else if(x == ops.size() - 1)
				{
					stringstream tempInt2(ops[x]);
				}
			}
			
			total = tempInt + tempInt2;
			
			stringstream ss;
			
			ss << total;
			ss >> tempString;
			
			ops.push_back(tempString);
		}
		
		else if(input == "D")
		{
			int prevScore;
			int total;
			
			string tempString;
			
			stringstream prevScore(ops[ops.size() - 1]);
			
			total = prevScore + prevScore;
			
			stringstream ss;
			
			ss << total;
			ss >> tempString;
			
			ops.push_back(tempString);
			
		}
		
		else if(input == "C")
		{
			ops.pop_back();
		}	
		
		
		
	} while(input != "quit");
	
	
	for(int x = 0; x < ops.size(); x++)
	{
		
	}
	
	return scoreSum;
}



void menu()
{
	cout << "1. An integer X: Record a new score of X" << endl;
	cout << "2. +: Record a new score that is the sum of the previous two scores" << endl;
	cout << "3. D: Record a new score that is double the previous score" << endl;
	cout << "4. C: Invalidate the previous score, removing it from the record" << endl;
}

int stringToInt(string str)
{
	
	
	
}
