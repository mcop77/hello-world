/* Name: Marshall Copeland
Date: 03/27/21
Section: #07
Assignment: Project #5
Due Date: 04/08/21
About this project: Implement a hash table ADT and other supporting user interfaces;  develop a simple password server program. Analyze the time complexity of certain functions.

All work below was performed by Marshall Copeland */

#include <iostream>
#include <string>
#include "passserver.h"

using namespace std;
using namespace cop4530;

void Menu();

int main()
{
	size_t capacity;
	char menuChoice;
	string filename;
	string username;
	string password;
	string newPassword;
	
	
	cout << "Enter preferred hash table capacity: ";
	cin >> capacity;
	
	PassServer server(capacity);
	
	do {
		Menu();
		
		cin >> menuChoice;
		
		if(menuChoice == 'l')
		{
			cout << "Enter password file name to load from: ";
			cin >> filename;
		}
		
		else if(menuChoice == 'a')
		{
			cout << "Enter username: ";
			cin >> username;
			
			cout << "\nEnter password: ";
			cin >> password;
			
			std::pair<std::string, std::string> newPair;
			newPair = std::make_pair(username, password);
			
			if(server.addUser(newPair))
			{
				cout << "\nUser " << username << " added." << endl;
			}
			
			else cout << "**Error: User already exists. Could not add user" << endl;
		}
		
		else if(menuChoice == 'r')
		{
			cout << "Enter username: ";
			cin >> username;
			
			if(server.removeUser(username))
			{
				cout << "User " << username << " deleted." << endl;
			}
			
			else cout << "**Error: User not found. Could not delete user" << endl;
		}
		
		else if(menuChoice == 'c')
		{
			cout << "Enter username: ";
			cin >> username;
			
			cout << "\nEnter password: ";
			cin >> password;
			
			cout << "\nEnter new password: ";
			cin >> newPassword;
			
			std::pair<std::string, std::string> newPair;
			newPair = std::make_pair(username, password);
			
			if(server.changePassword(newPair, newPassword))
			{
				cout << "Password changed for user " << username << endl;
			}
			
			else cout << "**Error: Could not change user password" << endl;
		}
		
		else if(menuChoice == 'f')
		{
			cout << "Enter username: ";
			cin >> username;
			
			if(server.find(username))
			{
				cout << "User '" << username << "' found" << endl;
			}
			
			else cout << "User '" << username << "' not found" << endl;
		}
		
		else if(menuChoice == 'd')
		{
			server.dump();
		}
		
		else if(menuChoice == 's')
		{
			cout << "Size of hashtable: " << server.size() << endl;
		}
		
		else if(menuChoice == 'w')
		{
			cout << "Enter password file name to write to: ";
			cin >> filename;
			
			server.write_to_file(filename.c_str());
		}
		
		else if(menuChoice != 'x')
		{
			cout << "**Error: Invalid entry.  Try again." << endl;
		}

	} while(menuChoice == 'l' || menuChoice == 'a' || menuChoice == 'r' || menuChoice == 'c' || menuChoice == 'f' || menuChoice == 'd' || menuChoice == 's' || menuChoice == 'w');
}

void Menu()
{
  cout << "\n\n";
  cout << "l - Load From File" << endl;
  cout << "a - Add User" << endl;
  cout << "r - Remove User" << endl;
  cout << "c - Change User Password" << endl;
  cout << "f - Find User" << endl;
  cout << "d - Dump HashTable" << endl;
  cout << "s - HashTable Size" << endl;
  cout << "w - Write to Password File" << endl;
  cout << "x - Exit program" << endl;
  cout << "\nEnter choice : ";
}
