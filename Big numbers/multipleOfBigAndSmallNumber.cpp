#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
void multipleOfBigAndSmallNumber(string A, int b, deque<short>&res)
{
	reverse(A.begin(), A.end());
	int flag = 0;
	for (short i = 0; i < A.size(); i++)
	{
		int temp = (A[i] - 48)*b + flag;
		res.push_back(temp % 10);
		flag = temp / 10;
	}
	if (flag)
		res.push_back(flag);
	reverse(res.begin(), res.end());
}


int main()
{
	string A;
	int b;
	cin >> A >> b;
	if (A == "0" || b == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if (A[0] == '-' && b < 0) {
		A.erase(A.begin());
		b *= -1;
	}
	else if (A[0] == '-') {
		A.erase(A.begin());
		cout << "-";
	}
	else if (b < 0)
	{
		b *= -1;
		cout << "-";
	}
	deque<short>res;
	multipleOfBigAndSmallNumber(A, b, res);
	for (short i = 0; i < res.size(); i++)
		cout << res[i];
	cout << endl;
	system("pause");
	return 0;
}