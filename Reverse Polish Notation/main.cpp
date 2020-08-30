#include <iostream>// ввод/вывод
#include <cstring>// strlen - длина строки char
#include <cctype> // isidigit/isalpha - проверка на цифру/букву
using namespace std; 
class Mystack
{
private:
	short lenght = 0;
	char stack[100];
public:
	void push(char arg){
		stack[lenght++] = arg;
	}
	void pop(){
		lenght--;
	}
	char top(){
		return stack[lenght - 1];
	}
	short size(){
		return lenght;
	}
	void clear(){
		lenght = 0;
	}
	bool empty(){
		return lenght == 0 ? 0 : 1;
	}
	void show(){
		for (short i = 0; i < lenght; i++)
			cout << stack[i];
		cout << endl;
	}
};
Mystack toRPN(char str[50]);
int main()
{
	char str[50] = "/0";
	cin >> str;
	Mystack ans = toRPN(str);
	ans.show();
	system("pause");
	return 0;
}
short GetPriority(char operation);
Mystack toRPN(char str[50])
{
	Mystack outputstr, operations;
	for (int i = 0; i < strlen(str) + 1; i++){
		if (i == strlen(str))
			break;
		else if (isalpha(str[i]) || isdigit(str[i]))
			outputstr.push(str[i]);
		else if (str[i] == '(')
			operations.push(str[i]);
		else if (str[i] == ')'){
			while (operations.top() != 0x28){
				outputstr.push(operations.top());
				operations.pop();
			}
			operations.pop();
			continue;
		}
		else {
			if (operations.size() > 0)
			if (GetPriority(str[i]) <= GetPriority(operations.top())){
				outputstr.push(operations.top());
				operations.pop();
			}
			operations.push(str[i]);

		}
	}
	while (operations.size()){
		outputstr.push(operations.top());
		operations.pop();
	}

	return outputstr;
}
short GetPriority(char operation)
{
	switch (operation)
	{
	case '(': return 0;
	case ')': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default: return 4;
	}
}