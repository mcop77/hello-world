/* Name: Marshall Copeland
Date: 02/02/21
Section: #07
Assignment: Project #2
Due Date: 02/11/21
About this project: This project has two parts. In the first part, you will implement a doubly-linked list named List (and corresponding) iterator support. In this second part, you will develop a simple memory management application using the doubly-linked list List that you have developed in the first part of the project. 

All work below was performed by Marshall Copeland */

#include <iostream>
#include "MyMemory.h"
#include "List.h"

using namespace std;
using namespace cop4530;

void print_memu();

int main()
{
	int numBlocks;
	int blockSize;
	char menuChoice;
	
	int count = 0;
	
	cout << "Memory Configuration:" << endl;
	cout << "Number of memory blocks (integer): ";
	cin >> numBlocks;
	
	cout << "Memory block size (integer): ";
	cin >> blockSize;
	
	MyMemory* mlist;
	
	for(int x = 0; x < numBlocks; x++)
	{
		MyMemoryBlock(x, blockSize);
	}
	
	do {
		if(count > 0 && (menuChoice != 'd' || menuChoice != 'r' || menuChoice != 'l' || menuChoice !=  'm'))
		{
			cout << "*****Error: Invalid entry. Try again." << endl;
		}
		
		print_memu();
		cout << "Your choice: ";
		cin >> menuChoice;
		
		cout << menuChoice << "\n" << endl;
		
		count++;
		
		if(menuChoice == 'd')
		{
				mlist->dump();
			
		}
		
		else if(menuChoice == 'r')
		{
			int memSize;
			
			cout << "Requested memory size (integer): ";
			cin >> memSize;
			
			
		}
		
		else if(menuChoice == 'l')
		{
			int memIndex;
			int memLength;
			
			cout << "Release memory index (integer): ";
			cin >> memIndex;
			
			cout << "Release memory length (integer): ";
			cin >> memLength;
			
			if(mlist->release_mem(memIndex, memLength) == false)
			{
				cout << "Memory release operatiion failed" << endl;
			}			
		}
		
		else if(menuChoice == 'm')
		{
			mlist->merge_mem();
		}
		
	} while(menuChoice != 'x');
	
	return 0;
}

void print_memu() 
{
	cout << string(20, '=') << endl;
	cout << "d: memory dump" << endl;
	cout << "r: request memory" << endl;
	cout << "l: release memory" << endl;
	cout << "m: merge memory" << endl;
	cout << "x: quit program" << endl;	
}
