#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigNumbers
{


private:
	vector<int>firstNumber;
	vector<int>secondNumber;
	vector<int>result;
	int sizeOfResult;

public:
	
	void input()
	{
		string number;

		cin >> number;
		reverse(number.begin(), number.end());
		for (int i = 0; i < number.size(); i++)
			firstNumber.insert(firstNumber.begin(),number[i] - 48);

		cin >> number;
		reverse(number.begin(), number.end());
		for (int i = 0; i < number.size(); i++)
			secondNumber.insert(secondNumber.begin(), number[i] - 48);

	}

	void sumOfBigNumbers()
	{
		while (firstNumber.size() < secondNumber.size())
			firstNumber.insert(firstNumber.begin(), 0);
		while (secondNumber.size() < firstNumber.size())
			secondNumber.insert(secondNumber.begin(), 0);

		int rest = 0;
		sizeOfResult = 0;
		result.resize(1000, 0);


		for (int i = 0; i < secondNumber.size(); i++)
		{
			int tempResult = firstNumber[i] + secondNumber[i] + rest;
			result.insert(result.begin(), tempResult % 10);
			rest = tempResult / 10;
			sizeOfResult++;
		}
		if (rest){
			if (result[0])
				result.insert(result.begin(), rest);
			else
				result[0] += rest;
			sizeOfResult++;
		}
	}
	void showResult ()
	{
		for (unsigned int i = 0; i < sizeOfResult; i++)
			cout << result[i];
		cout<<endl;

		result.clear();
	}


};



int main()
{
	BigNumbers numbers;
	//cout << numbers.sizeOfResult <<endl;
	numbers.input();
	numbers.sumOfBigNumbers();
	numbers.showResult();

	system ("pause");
	return 0;
}

