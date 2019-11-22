#include<iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
int main()
{
	int a = 16, b = 92, c = 43, d = 40, e = 17, f = 70;
	char Postfix[] = "abc*+d/e-abd-*<";
	int Length = strlen(Postfix);
	int *ans=new int[Length], index = 0;
	cout << "Postfix : ";

	for (int i = 0; i<Length; i++)
	{
		cout << Postfix[i];
		if ((Postfix[i] >= 'a' && Postfix[i] <= 'z') || (Postfix[i] >= 'A' && Postfix[i] <= 'Z'))
		{

			switch (Postfix[i])
			{

			case 'a':
				ans[index] = a;
				index++;
				break;
			case 'b':
				ans[index] = b;
				index++;
				break;
			case 'c':
				ans[index] = c;
				index++;
				break;
			case 'd':
				ans[index] = d;
				index++;
				break;
			case 'e':
				ans[index] = e;
				index++;
				break;
			case 'f':
				ans[index] = f;
				index++;
				break;
			default:
				cout << "Unknown";
			}
		}
		else
		{
			int a = ans[index - 2], b = ans[index - 1];
			switch (Postfix[i])
			{
			case '*':
				ans[index - 2] = a * b;
				index--;
				break;
			case '/':
				ans[index - 2] = a / b;
				index--;
				break;
			case '+':
				ans[index - 2] = a + b;
				index--;
				break;
			case '-':
				ans[index - 2] = a - b;
				index--;
				break;
			case '%':
				ans[index - 2] = a % b;
				index--;
				break;
			case '<':
				(a < b) ? ans[index - 2] = 1 : ans[index - 2] = 0;
				index--;
				break;
			case '>':
				(a > b) ? ans[index - 2] = 1 : ans[index - 2] = 0;
				index--;
				break;
			case '|':
				ans[index - 2] = a || b;
				index--;
				break;
			case '&':
				ans[index - 2] = a && b;
				index--;
				break;
			case '=':
				(a == b) ? ans[index - 2] = 1 : ans[index - 2] = 0;
				index--;
				break;
			case '!':
				(a != b) ? ans[index - 2] = 1 : ans[index - 2] = 0;
				index--;
				break;
			default:
				cout << "Unknown";
			}
		}
	}
	cout << endl <<"Ans : "<< ans[0] << endl;
	system("pause");
}
