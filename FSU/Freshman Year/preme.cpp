#include <iostream>
using namespace std;

int main()
{
	int size;
	char answer;

	double shirt;
	double shirt2;
	double shirt3;
	double shirt4;
	double shirt5;
	double shirt6;
	double shirt7;
	
	char sgchoice;
	
	do {
		double total = 0;
		double total2 = 0;
		cout << "How many shirts do you have?: ";
		cin >> size;

		int list[size];

		cout << "\nHow much are your shirts?" << endl;

		for(int x = 0; x < size; x++)
		{
			cout << "Shirt #" << x + 1 << ": ";
			cin >> shirt;
			list[x] = shirt;
			
			total += list[x];	
		}
		
		cout << "Would you like to see the STOCKX or GRAILED payouts?" << endl;
		cout << "Type 's' for STOCKX and 'g' for GRAILED: ";
		cin >> sgchoice;
		
		if(sgchoice == 's')
		{
			for(int x = 0; x < size; x++)
			{
				list[x] = list[x] - (list[x] *.12);		
				cout << list[x];
				cout << "\n";
				total2 += list[x];	
			}
			
			cout << "Total: " << total2 - (38 * size) - 10;
			cout << "\n";
		}
		
		else if(sgchoice == 'g')
		{
			for(int x = 0; x < size; x++)
			{
				list[x] = list[x] - (list[x] *.12) - 7.75;	
				cout << list[x];
				cout << "\n";
				total2 += list[x];
			}
			
			cout << "Total: " << total2 - (38 * size) - 10;
			cout << "\n";
		}
		
		cout << "Do you wish to quit the program? Type 'y' or 'n': ";
		cin >> answer;
	} while(answer == 'n');

return 0;
}
