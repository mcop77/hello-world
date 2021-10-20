#include <iostream>
using namespace std;
int main()
{
	for(int x = 1; x < 1001; x++)
	{
		if(x < 11)
		{
			cout << x << "  ";
		}
		else cout << x << " ";

		if(x % 10 == 0)
		{
			cout << endl;
		}
	}
return 0;
}
