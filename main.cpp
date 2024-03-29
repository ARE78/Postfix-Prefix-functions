#include<iostream>
using namespace std;
int length(char[]);
void postfix_ftn(char [],char[]);
void prefix(char[], char[]);
int evaluate_post(char[]);
int main()
{
	int option, ans;
	char expression[40], resultant[40];
	while (1) {
		cout << "    MENU DRIVEN PROGRAM      " << endl;
		cout << "OPTION :1        INFIX TO POSTFIX " << endl;
		cout << "OPTION :2        INFIX TO PREFIX " << endl;
		cout << "OPTION :3        EVALUATE POSTFIX " << endl;
		cout << "OPTION :4        INFIX TO POSTFIX " << endl;
		cout << "OPTION :0        QUIT" << endl;
		cout << "Enter the option no : ";
		cin >> option;
		while (option < 0 || option>4) {
			cout << "invalid option! try again" << endl;
			cout << "Enter the option no : ";
			cin >> option;
		}
		cin.ignore();
		cout << "Enter the expression : ";
		cin.get(expression, 40);
		switch (option)
		{
		case 1:
			postfix_ftn(expression, resultant);
			cout << "the postfix expression is : " << resultant << endl;
			break;
		case 2:
			prefix(expression, resultant);
			cout << "the postfix expression is : " << resultant << endl;
			break;
		case 3:
			ans = evaluate_post(expression);
			cout << "the answer of postfix evaluation is : " << ans << endl;
			break;
		case 4:
			break;
		case 0:
			exit(0);
			break;
		}
	}
	return 0;
}
int length(char m[])
{
	int i;
	for(i=0;m[i] !='\0';i++)
	{ }
	return i;
}

void postfix_ftn(char exp[], char postfix[])
{
	int x;
	char  stack[40];
	int j = 0, k = 0;
	x = length(exp);
	exp[x] = ')';
	exp[x + 1] = '\0';
	stack[j] = '(';
	j++;
	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] >= 65 && exp[i] <= 90 || exp[i] >= 97 && exp[i] <= 122) {
			postfix[k] = exp[i];
			k++;
		}
		else {
			switch (exp[i])
			{
			case '+':
				if (stack[j - 1] == '-' || stack[j - 1] == '*' || stack[j - 1] == '/' || stack[j - 1] == '^') {
					postfix[k] = stack[j - 1];
					stack[j - 1] = '+';
					k++;
				}
				else {
					stack[j] = '+';
					j++;
				}
				break;
			case '-':
				if (stack[j - 1] == '+' || stack[j - 1] == '*' || stack[j - 1] == '/' || stack[j - 1] == '^') {
					postfix[k] = stack[j - 1];
					stack[j - 1] = '-';
					k++;
				}
				else {
					stack[j] = '-';
					j++;
				}
				break;
			case '*':
				if (stack[j - 1] == '/' || stack[j-1] == '^') {
					postfix[k] = stack[j - 1];
					stack[j - 1] = '*';
					k++;
				}
				else {
					stack[j] = '*';
					j++;
				}
				break;
			case '/':
				if (stack[j - 1] == '*' || stack[j - 1] == '^') {
					postfix[k] = stack[j - 1];
					stack[j - 1] = '/';
					k++;
				}
				else {
					stack[j] = '/';
					j++;
				}
				break;
			case '^':
				stack[j] = '^';
				j++;
			case '(':
				stack[j] = '(';
				j++;
				break;
			case ')':
				while (stack[j - 1] != '(') {
					postfix[k] = stack[j - 1];
					j--, k++;
				}
				j--;
				break;
			}
		}
	}
	stack[j] = '\0';
	postfix[k] = '\0';
}

void prefix(char e[] ,char r[])
{
	int i , j;
	char reverse[40];
	for (i = length(e) - 1,j=0; i >= 0; i--,j++)
	{
		r[j] = e[i];
	}
	r[j] = '\0';
	postfix_ftn(r, reverse);
	for (i = length(reverse) - 1, j = 0; i >= 0; i--, j++)
	{
		r[j] = reverse[i];
	}
	r[j] = '\0';
}

int evaluate_post(char exp[])
{
	int x ,a,b;
	int  stack[40];
	int j = 0, k = 0;
	x = length(exp);
	exp[x] = ')';
	exp[x + 1] = '\0';
	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] >= 48 && exp[i] <= 57) {
			stack[j] = exp[i] -48;
			j++;
		}
		else {
			a = stack[j - 1];
			b = stack[j - 2];
			j = j - 2;
			switch (exp[i]) {
			case'+':
				stack[j] = b + a;
				break;
			case'-':
				stack[j] = b - a;
				break;
			case'*':
				stack[j] = b * a;
				break;
			case'/':
				stack[j] = b / a;
				break;
			case'^':
				stack[j] = b ^ a;
				break;
			}
			j++;
		}
		if (exp[i] == ')')
			return stack[0];
	}
}