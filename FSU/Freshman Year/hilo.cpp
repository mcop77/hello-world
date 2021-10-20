#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{	
	int num = rand() % 10000 + 1;
	char bet;
	char choice;
	char type;
	int total = 100;
	int betAmount;
	int count = 0;
	
	//50/50 odds
	int lo50 = 1;
	int hi50 = 5000;
	
	//3/2 odds
	int lo3 = 250;
	int hi3 = 9750;
	
	
	
	

	srand(time(0));
	
	cout << "*****************************************************************" << endl;
	cout << "*\t __    __   ________          __          _______ \t*" << endl;
	cout << "*\t|  |  |  | |__    __|        |  |        |  ___  |\t*" << endl;
	cout << "*\t|  |  |  |    |  |           |  |        | |   | |\t*" << endl;
	cout << "*\t|  |__|  |    |  |    _____  |  |        | |   | |\t*" << endl;
	cout << "*\t|   __   |    |  |           |  |        | |   | |\t*" << endl;
	cout << "*\t|  |  |  |    |  |           |  |        | |   | |\t*" << endl;
	cout << "*\t|  |  |  |  __|  |__         |  |______  | |___| |\t*" << endl;
	cout << "*\t|__|  |__| |________|        |_________| |_______|\t*" << endl;
	cout << "*\t\t\t\t\t\t\t\t*" << endl;
	cout << "*****************************************************************" << endl;
	
	
	do {
		
		cout << "\n\n*****************************************************************" << endl;
		
		if(count == 0)
		{
			cout << "\nWould you like to BET? Type \"Y\" for YES: ";
			cin >> bet;
			count = 1;
			
			cout << "\nManual or Automatic Betting? Type \"M\" or \"A\": ";
			cin >> type;
			
			cout << "\nHow much would you like to wager out of your " << total << "?" << endl;
			cout << "> ";
			cin >> betAmount;
			
			while(betAmount > total)
			{
				cout << "\nBet cannot exceed total, try again." << endl;
				cout << "> ";
				cin >> betAmount;
			}
		}
		
		else
		{
			cout << "Continue?: ";
			cin >> bet;
			
			cout << "\nHow much would you like to wager?" << endl;
			cout << "> ";
			cin >> betAmount;
			
			while(betAmount > total)
			{
				cout << "\nBet cannot exceed total, try again." << endl;
				cout << "> ";
				cin >> betAmount;
			}
			
		}
		
		if(type == 'A')
		{
			cout << "\nBET \"H\' for HI and \"L\" for LO: ";
			cin >> choice;
			
			
			if((choice == 'H' || choice == 'h'))
			{
				while(num < hi3 && total > 0)
				{
					total = total - betAmount;
					cout << "You Lost " << betAmount << ". New Total = " << total << "."  << endl;
					
					betAmount = betAmount * 2.5;
					num = rand() % 10000 + 1;
				}
				
				total = total + betAmount;
				cout << "You Win " << betAmount << "!" << endl;
				cout << "Your Total is now " << total << "." << endl;
			}
			
			else if((choice == 'L' || choice == 'l'))
			{
				while(num > lo3 && num <= 5000 && total > 0)
				{
					total = total - betAmount;
					cout << "You Lost " << betAmount << ". New Total = " << total << "."  << endl;
					
					betAmount = betAmount * 2.5;
					num = rand() % 10000 + 1;
				}
				
				total = total + betAmount;
				cout << "You Win " << betAmount << "!" << endl;
				cout << "Your Total is now " << total << "." << endl;
			}
			
			else 
			{
				total = total - betAmount;
				cout << "The number was " << num << "!" << endl;
				cout << "You Lose " << betAmount << "!" << endl;
				cout << "Your Total is now " << total << "." << endl;
			}
		}
		
		else if(bet == 'Y' || bet == 'y')
		{
			cout << "\nBET \"H\' for HI and \"L\" for LO: ";
			cin >> choice;
			
			
			if((choice == 'H' || choice == 'h') && num > 5000)
			{
				total = total + betAmount;
				cout << "The number was " << num << "!" << endl;
				cout << "You Win " << betAmount << "!" << endl;
				cout << "Your Total is now " << total << "." << endl;
			}
			
			else if((choice == 'L' || choice == 'l') && num <= 5000)
			{
				total = total + betAmount;
				cout << "The number was " << num << "!" << endl;
				cout << "You Win " << betAmount << "!" << endl;
				cout << "Your Total is now " << total << "." << endl;
			}
			
			else 
			{
				total = total - betAmount;
				cout << "The number was " << num << "!" << endl;
				cout << "You Lose " << betAmount << "!" << endl;
				cout << "Your Total is now " << total << "." << endl;
			}
			
			num = rand() % 10000 + 1;
		}
		
		
	} while(bet != 'Y' || bet != 'y');
	
	
}
