#include <iostream>
#include <string>
#include <locale>
using namespace std;
struct meeting
{
	int begin;
	int end;
	int lenght;
	string name;
};
void swap(meeting &a, meeting &b){
	meeting t = a;
	a = b;
	b = t;
}
void EventSort(meeting *a, int n){
	for (int i = 0; i < n - 1; i++)
	for (int j = i; j < n - i - 1; j++)
	if (a[j].begin > a[j + 1].begin)
		swap(a[j], a[j + 1]);
	cout << endl;
}

int main()
{
	setlocale(0, "");
	int n, h;
	cout << "������ ��������� ������������ ����������� ����� ������� �� ������� �������.\n\n";
	cout << "������� ����� ������ �������� ���: "; cin >> h; cout << endl;
	cout << "������� ����� ��������� �������: "; cin >> n; cout << endl;
	meeting *a = new meeting[n + 1];
	for (int i = 0; i < n; i++){
		cout << "������� �������� �������: "; cin >> a[i].name;
		cout << "������� ��� ������ �������: "; cin >> a[i].begin;
		cout << "������� ��� ����� �������: "; cin >> a[i].end;
		a[i].lenght = a[i].end - a[i].begin;
		cout << "������� ������� ��������!\n\n";
	}
	a[n] = { -1, -1, -1 };
	int counter = 1;
	cout << "��� ���������� ����� �������: \n";
	EventSort(a, n);
	for (int j = 0; j < h; j++){
		int temp = n;
		for (int i = 0; i < n; i++){
			if (j == a[i].begin && a[temp].lenght <= a[i].lenght && a[i].end <= h)
				temp = i;
		}
		if (a[temp].lenght != -1){
			j = a[temp].end - 1;
			cout << "������� �" << counter << ": " << a[temp].name << endl;
			counter++;
		}
	}
	if (counter == 1)
		cout << "\t\t\" ----- \"" << endl;
	system("pause");
	return 0;
}
