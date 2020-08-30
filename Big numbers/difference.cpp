#include <iostream>
#include <string>
#include <vector>
using namespace std;

void input(vector<int>&arg)
{
	string s;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--)
		arg.push_back(s[i] - 48);
}
void output(vector<int>arg)
{
	while (arg[arg.size() - 1] == 0 && arg.size() > 1)
		arg.resize(arg.size() - 1);
	for (int i = arg.size() - 1; i >= 0; i--)
		cout << arg[i];
	cout << endl;
}
void dif(vector<int>A, vector<int>B, vector<int>&res)
{
	
	for (int i = 0; i < A.size() - 1; i++)
	{
		int temp = A[i] - B[i];
		if (temp < 0) {
			temp = A[i] + 10 - B[i];
			A[i + 1]--;
		}
		res.push_back(temp);
	}
}
void comprasion(vector<int>&A, vector<int>&B)
{

	bool p = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		if (A[i] < B[i]) {
			p = 1;
			break;
		}
		if(A[i] > B[i]) {
			p = 0;
			break;
		}
	}
	if (p) {
		A.swap(B);
		cout << "-";
	}
}


int main()
{
	vector<int>A;
	vector<int>B;
	vector<int>res;
	input(A);
	input(B);
	while (A.size() < B.size())
		A.push_back(0);
	while (B.size() < A.size())
		B.push_back(0);
	
	comprasion(A, B);
	A.push_back(0); B.push_back(0);
	dif(A, B, res);
	output(res);

	system("Pause");
	return 0;
}