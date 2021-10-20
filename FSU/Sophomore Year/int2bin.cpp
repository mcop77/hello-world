#include <iostream>
using namespace std;

int main()
{
	int num;
	int bits;	
	int arr[64];
	
	cout << "\n\t**********************************" << endl;
	cout << "\t*                                *" << endl;
	cout << "\t*  Integer to Binary Converter!  *" << endl;
	cout << "\t*                                *" << endl;
	cout << "\t**********************************" << endl;
	
	do {
		cout << "\nEnter an Integer: ";
		cin >> num;
		
		cout << "\nHow many bits would you like to display?" << endl;
		cout << "> ";
		cin >> bits;
		
		for (int x = bits - 1; x >= 0; x--) 
		{ 
			int k = num >> x; 
			
			if (k & 1) 
			{
				cout << "1"; 
			}
			
			else cout << "0"; 
			
			if(x % 4 == 0)
			{
				cout << " ";
			}
		} 
		
	} while(num != 0000 || bits != 0000);
}
