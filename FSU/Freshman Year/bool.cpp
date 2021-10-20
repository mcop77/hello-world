#include <iostream>
using namespace std;
int main()
{
	bool greaterthan100, negative, even;
	int num;
	
	greaterthan100 = negative = even = false;
	do {
	cout << "Enter in some numbers";
	cin >> num;
	
	if(num > 100)
	{
		greaterthan100 = true;
	}
	if(num < 0)
	{
		negative = true;
	}
	if(num % 2 == 0)
	{
		even = true;
	}
	} while(num != 0);
	
	if(greaterthan100)
		cout << "Greater than 100" << endl;
	if(negative)
	{
		cout << "Negative" << endl;
	}
		
	if(even)
	{
		cout << "Even" << endl;
	}
	
	
	
	return 0;
}
