#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 11 , 22 , 33 , 44 , 55 , 66 , 77 , 88 , 99 , 100 };
	int size = 10;
	int amount;
	
	cout << "pick a number: ";
	cin >> amount;
	
	
 
    for(int x = 0; x < size; x++)
    {
		arr[x] = arr[(x + amount) % size];
    }
	
	cout << arr;
	return 0;
}
