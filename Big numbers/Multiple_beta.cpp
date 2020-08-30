#include <iostream>
#include <algorithm>
#include <string>
const short MAXS = 1474559;
using namespace std;
void Mul(string A, string B, short (&res)[MAXS], unsigned long long int &sizeOfResult)
{
	bool flag = 0;
	if (A[0] == '-'&&B[0] != '-') {
		A.erase(A.begin());
		flag = 1;
	}
	if (B[0] == '-'&&A[0] != '-') {
		B.erase(B.begin());
		flag = 1;
	}
	if (B[0] == '-'&&A[0] == '-') {
		A.erase(A.begin());
		B.erase(B.begin());
	}

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	if (A[0] == '0'&&A.size() == 1 || B[0] == '0'&&B.size() == 1)
		sizeOfResult = 0;

	else {

		unsigned long long int i, j;
		for (i = 0; i < A.size(); i++) {
			for (j = 0; j < B.size(); j++)
				res[i + j] += (A[i] - 48) * (B[j] - 48);
		}
		sizeOfResult = A.size() + B.size() - 1;
		for (i = 0; i < sizeOfResult; i++)
		{
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
		while (res[sizeOfResult] == 0)
			sizeOfResult--;
		if (flag)
			res[sizeOfResult] *= -1;
		for (i = 0; i < (unsigned long long int)sizeOfResult / 2 + 1; i++)
			swap(res[i], res[sizeOfResult - i]);
	}

}




int main()
{
	ios_base::sync_with_stdio(0);
	string BigNumberOne, BigNumberTwo;
	cin >> BigNumberOne >> BigNumberTwo;
	unsigned long long int sizeOfResult = 0;
	short res[MAXS] = { 0 };
	Mul(BigNumberOne, BigNumberTwo, res, sizeOfResult);
	for (unsigned long long int i = 0; i <= sizeOfResult; i++)
		cout << res[i];
	cout << endl;
	system("Pause");
	return 0;
}
