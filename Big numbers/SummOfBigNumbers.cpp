//Topla string
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
void SummOfBigNumbers(string A, string B, deque<short>& res)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	while (A.size() < B.size())
		A += '0';
	while (B.size() < A.size())
		B += '0';
	short flag = 0;
	for (short i = 0; i < A.size(); i++)
	{
		short temp = (A[i] - 48) + (B[i] - 48) + flag;
		res.push_back(temp % 10);
		flag = temp / 10;
	}
	if (flag)
		res.push_back(flag);
	reverse(res.begin(), res.end());
}

int main()
{
	string A, B;
	cin >> A >> B;
	deque<short>res;
	SummOfBigNumbers(A, B, res);
	for (short i = 0; i < res.size(); i++)
		cout << res[i];
	cout << endl;
	system("pause");
	return 0;
}
