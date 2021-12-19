#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> table = {1, 2, 3};
	
	table[3] = 5;
	
	cout << table[3] << endl;
	
	if(6 > table[3])
	{
		cout << "hello" << endl;
	}
	
	return 0;
	
}
