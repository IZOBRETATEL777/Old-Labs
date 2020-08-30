#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;
string equation;
int parts(char close)
{
	string digits;
	int number, i = 0;
	while (equation[i] != close) {
		digits.push_back(equation[i]);
		i++;
	}
	if (digits == "" && close == '=') {
		number = 0;
		return number;
	}
	if (digits == "")
		digits.push_back('1');
	number = atoi(digits.c_str());
	equation = equation.substr(i, equation.size() - 1);
	return number;
}
int coefficient(int k, char close)
{
	int b;
	b = parts(close);
	equation = equation.substr(k, equation.size());
	return b;
}
void DiscriminantDo(int a, double D, int b)
{
	double x1, x2;
	
	if (D < 0)
	{
		cout << "ERROR404:\n\tSolution can't be found\n";
		system("pause");
		return;
	}
	else
	{
		x1 = (-b - sqrt(D)) / (2 * a);
		cout << "X_1 = " << x1 << endl;
		if (D == 0) {
			return;
			system("pause");
		}
		x2 = (-b + sqrt(D)) / (2 * a);
		cout << "X_2 = " << x2 << endl;
	}
}
int main()
{
	system("color 27");
	string digits;
	getline(cin, equation);
	int a, b, c, d;
	double D;


	a = coefficient(2, 'x');
	b = coefficient(1, 'x');
	c = coefficient(1, '=');
	d = atoi(equation.c_str());
	if (d != 0)
		c += (-d);
	D = pow(b, 2) - 4 * a*c;
	cout << "Discriminant = " << D << endl;
	DiscriminantDo(a, D, b);
	cout<<endl;
	system("pause");
	return 0;
}