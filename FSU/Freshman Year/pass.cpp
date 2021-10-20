#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

void brute(char password[], char helper[], int size);

int main()
{
	int size;
	char password[size];
	char helper[size];
	
	char ans;
	
	do {
		cout << "Enter a password (7 characters or below!): ";
		cin >> password;
	
		brute(password, helper, size);
		
		cout << "Enter another password? (y/n): ";
		cin >> ans;
		
		if(ans == 'n')
		{
			return 0;
		}
		
		while(ans != 'y' && ans != 'n')
		{
			cout << "Please pick y or n: ";
			cin >> ans;
		}
		
	} while(ans != 'n');
	
}

void brute(char password[], char helper[], int size)
{
	int count = 0;
	
	size = strlen(password);
	
	for(int x = 0; x < size; x++)
	{
		if(password[x] == 'a')
		{
			count++;
			helper[x] == 'a';
		}
		
		else if(password[x] == 'b')
		{
			count++;
			helper[x] == 'b';
		}
		
		else if(password[x] == 'c')
		{
			count++;
			helper[x] == 'c';
		}
		
		else if(password[x] == 'd')
		{
			count++;
			helper[x] == 'd';
		}
		
		else if(password[x] == 'e')
		{
			count++;
			helper[x] == 'e';
		}
		
		else if(password[x] == 'f')
		{
			count++;
			helper[x] == 'f';
		}
		
		else if(password[x] == 'g')
		{
			count++;
			helper[x] == 'g';
		}
		
		else if(password[x] == 'h')
		{
			count++;
			helper[x] == 'h';
		}
		
		else if(password[x] == 'i')
		{
			count++;
			helper[x] == 'i';
		}
		
		else if(password[x] == 'j')
		{
			count++;
			helper[x] == 'j';
		}
		
		else if(password[x] == 'k')
		{
			count++;
			helper[x] == 'k';
		}
		
		else if(password[x] == 'l')
		{
			count++;
			helper[x] == 'l';
		}
		
		else if(password[x] == 'm')
		{
			count++;
			helper[x] == 'm';
		}
		
		else if(password[x] == 'n')
		{
			count++;
			helper[x] == 'n';
		}
		
		else if(password[x] == 'o')
		{
			count++;
			helper[x] == 'o';
		}
		
		else if(password[x] == 'p')
		{
			count++;
			helper[x] == 'p';
		}
		
		else if(password[x] == 'q')
		{
			count++;
			helper[x] == 'q';
		}
		else if(password[x] == 'r')
		{
			count++;
			helper[x] == 'r';
		}
		
		else if(password[x] == 's')
		{
			count++;
			helper[x] == 's';
		}
		
		else if(password[x] == 't')
		{
			count++;
			helper[x] == 't';
		}
		
		else if(password[x] == 'u')
		{
			count++;
			helper[x] == 'u';
		}
		
		else if(password[x] == 'v')
		{
			count++;
			helper[x] == 'v';
		}
		
		else if(password[x] == 'w')
		{
			count++;
			helper[x] == 'w';
		}
		
		else if(password[x] == 'x')
		{
			count++;
			helper[x] == 'x';
		}
		
		else if(password[x] == 'y')
		{
			count++;
			helper[x] == 'y';
		}
		
		else if(password[x] == 'z')
		{
			count++;
			helper[x] == 'z';
		}
		
		else if(password[x] == '1')
		{
			count++;
			helper[x] == '1';
		}
		
		else if(password[x] == '2')
		{
			count++;
			helper[x] == '2';
		}
		
		else if(password[x] == '3')
		{
			count++;
			helper[x] == '3';
		}
		
		else if(password[x] == '4')
		{
			count++;
			helper[x] == '4';
		}
		
		else if(password[x] == '5')
		{
			count++;
			helper[x] == '5';
		}
		
		else if(password[x] == '6')
		{
			count++;
			helper[x] == '6';
		}
		
		else if(password[x] == '7')
		{
			count++;
			helper[x] == '7';
		}
		
		else if(password[x] == '8')
		{
			count++;
			helper[x] == '8';
		}
		
		else if(password[x] == '9')
		{
			count++;
			helper[x] == '9';
		}
		
	}	
	
	if(count == size)
	{
		cout << "\nYour password is ";
		
		for(int x = 0; x < size; x++)
		{
			cout << helper[x];
		}
		
		cout << "!\n";
	}
}
