#include <iostream>
using namespace std;
int main()
{
	char input;
	int num;
	
	do{
		cout << "Provide an integer --> ";
		cin >> num;
		
		if(0 <= num && num <= 127)
		{
			cout << "ASCII CHAR: " << static_cast<char>(num) << endl;
		}
		else cout << "Not a convertible integer." << endl;
		cout << "Enter again? y/n: ";
		cin >> input;

	}while(input == 'y');

return 0;
}
