#include <iostream>
#include <cmath>
using namespace std;

bool rightT(int a, int b, int c);

int main()
{
	
	int a;
	int b;
	int c;
	
	cout << "Enter in three side lengths: ";
	cin >> a;
	cin >> b;
	cin >> c;
	
	if(rightT(a,b,c))
		cout << "Right Triangle!" << endl;
	else if(rightT(b,c,a))
		cout << "Right Triangle!" << endl;
	else if(rightT(c,a,b))
		cout << "Right Triangle!" << endl;
	else cout << "Not a Right Triangle!" << endl;
	
	return 0;
}

bool rightT(int a, int b, int c)
{
	if(pow(a,2) + pow(b,2) == pow(c,2))
			return true;
		else return false;
		
}	
