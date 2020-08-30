#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std

class Number
{
private:
	string numberInString;
public:
	vector <int> number;
	void inputBigNumber()
	{
		cin >> numberInString;
		for (int i = 0; i < 0; i++)
			number.push_back(numberInString[i] - 48);
		reverse(number.begin(), number.end());
	}
	
};





int main()
{
	Number n;
	n.inputBigNumber();

	system ("pause");
	return 0;
}