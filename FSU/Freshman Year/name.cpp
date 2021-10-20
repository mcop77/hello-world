#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
		
	do {
		
		cout << "What's your name? --> ";
		cin >> name;
		
		if(name == "q")
		{
			return 0;
		}
		
		cout << "Your name is " << name << endl;
		cout << "Type 'q' to QUIT" << endl;
		
	} while(name != "q");

	return 0;
}
