#include <iostream>
using namespace std;
int main()
{

	int num1;
	int num2;
	int num3;

	cout << "Please Enter Three Numbers: ";
	cin >> num1;
	cin >> num2;
	cin >> num3;

	int add = num1 + num2 + num3;
	cout << num1 <<  " + " << num2 << " + " << num3 << " = " << add << endl;
	
	int sub = num1 - num2 - num3;
	cout << num1 <<  " - " << num2 << " - " << num3 << " = " << sub << endl;
	
	int mult = num1 * num2 * num3;
	cout << num1 <<  " * " << num2 << " * " << num3 << " = " << mult << endl;

	if(add % 2 == 0)
	{
	cout << "EVEN" << endl;
	}
	else cout << "ODD" << endl;


return 0;
}
