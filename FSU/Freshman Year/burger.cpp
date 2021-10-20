#include <iostream>
using namespace std;
int main()
{
	int ham;
	int chee;
	char response;
	char response2;
	cout << "Welcome...Would you like some food?" << endl;
	cin >> response;
	if(response == 'y')
	{
		cout << "Type 'h' for Hamburger or 'c' for Cheeseburger" << endl;
		cin >> response2;
		if(response2 == 'h')
		{
			cout << "Hamburger coming right up!" << endl;
		}
		else if(response2 == 'c')
		{
			cout << "Cheeseburger coming right up!" << endl;
		}
		else cout << "Abort" << endl;
	}
	else if(response == 'n')
	{
		cout<< "You're missing out" << endl;
	}
	else cout << "Error" << endl;
	cout << "Thank you for stopping at Cheeseburger Queen" << endl;


return 0;
}
