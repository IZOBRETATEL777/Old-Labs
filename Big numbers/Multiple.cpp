#include <iostream>
#include <vector>
#include <string>
using namespace std;
void input(vector<int> &arg)
{
	string s;
	cin >> s;

	for (int i = s.size() - 1; i >= 0; i--)
		arg.push_back(s[i]-48);
}
void output(vector<int>arg, int ende)
{

	for (int i = ende; i >= 0; i--)
		cout << arg[i];
	cout << endl;
}
void mult(vector<int>A, vector<int>B, int &sizeOfResult, vector<int> &res)
{
	if ((A[0] == 0 && A.size() == 1) || (B[0] == 0 && B.size() == 1))
		sizeOfResult = 0;
	else {
		int i, j;
		for (i = 0; i < A.size(); i++) {
			for (j = 0; j < B.size(); j++)
				res[i + j] += A[i] * B[j];
		}
		sizeOfResult = A.size() + B.size() - 1;
		for (i = 0; i < sizeOfResult; i++)
		{
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
		while (res[sizeOfResult] == 0)
			sizeOfResult--;
	}
}

int main()
{
	vector<int>A;
	vector<int>B;
	vector<int> res(1000000, 0);
	int sizeOfResult = 0;
	input(A);
	input(B);
	mult(A, B, sizeOfResult, res);
	output(res, sizeOfResult);
	system("PAUSE");
	return 0;
}