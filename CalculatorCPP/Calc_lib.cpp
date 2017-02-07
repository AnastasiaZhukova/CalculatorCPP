#include "Calc_lib_head.h"
#include <cmath>
#include <conio.h>
#include <iostream>
#include <regex>
using namespace std;
void head()
{
	cout << "\t\t\t\t\tWelcome to my calculator!\n\
\t\t\t\t\tAvailable operations : \n\
\t\t\t\t\t'+' \t'-'\n\
\t\t\t\t\t'*' \t'/'\n\
\t\t\t\t\t'^'\n\
\t\t\t\t\t'C' - start new calculation(attention!Only in english)\t\t\n\
\t\t\t\t\t'esc' - exit\n\
Start new calculatin:\n";
}
void addition(double &operand1, double operand2)
{
	operand1 = operand1 + operand2;
}
void subtraction(double &operand1, double operand2)
{
	operand1 = operand1 - operand2;
}
void multiplication(double &operand1, double operand2)
{
	operand1 = operand1 * operand2;
}
void division(double &operand1, double operand2)
{
	operand1 = operand1 / operand2;
}
void power(double&operand1, double operand2)
{
	operand1 = pow(operand1, operand2);

}
void C_function()
{
	system("cls");
	head();
}
void input_operator(char &opr, bool &continue_flag, bool&calc_flag)
{
	int sign;
	int next_key;
	while (true)
	{
		sign = _getch();
		if (sign == 42 || sign == 43 || sign == 45 || sign == 47 || sign == 94)
		{
			cout << (char)sign;
			while (true)
			{
				next_key = _getch();
				if (next_key == 8) { cout << "\b \b"; break; }
				if (next_key == 13 || next_key == 32) { opr = (char)sign; cout << endl; return; }
				if (next_key == 67 || next_key == 99) { continue_flag = false; return; }
				if (next_key == 27) { calc_flag = false; return; }
			}
		}
		if (sign == 27) { calc_flag = false; return; }
		if (sign == 67 || sign == 99) { continue_flag = false; return; }
		if (sign == 69 || sign == 101)
		{
			opr = (char)sign; return;
		}

	}

}
void input_operand(double &opd, bool &continue_flag, bool&calc_flag)
{
	regex number_0("(\\+|-)?0\\.[0-9]+");
	regex number_1("(\\+|-)?[1-9]+[0-9]*?(\\.)?[0-9]+|[0-9]*");
	regex number_2("(\\+|-)?[1-9]+[0-9]*");
	regex number_3("(\\+|-)?0");
	string operand = "";
	int key;
	int next_key;
	int dot_length = -1;
	while (true)
	{
		key = _getch();
		if (operand.length() == 0)
		{
			if (key == 43 || key == 45)
			{
				operand += (char)key;
				cout << (char)key;
				continue;
			}
		}
		if (key == 27) { calc_flag = false; return; }
		if (key == 48 && (operand[0] == '-' || operand[0] == '+' || operand.length() == 0) /*operand.length() <= 1*/)
		{
			cout << (char)key;
			while (true)
			{
				next_key = _getch();
				if (next_key == 46 || next_key == 8 || next_key == 13 || next_key == 32)
				{
					operand += (char)key;
					key = next_key;
					break;
				}
				if (next_key > 48 && next_key < 58)
				{
					cout << "\b \b";
					key = next_key;
					break;
				}
				if (next_key == 67 || next_key == 99)
				{
					continue_flag = false; return;
				}
				if (next_key == 27) { calc_flag = false; return; }
			}

		}
		if (key == 46 && dot_length == -1)
		{
			operand += (char)key;
			dot_length = operand.length();
			cout << (char)key;
			continue;
		}
		if (key == 67 || key == 99) { continue_flag = false; return; }
		if (key == 27) { calc_flag = false; return; }
		if (key == 8 && operand.length() != 0)
		{
			if (operand.length() == dot_length) { dot_length = -1; }
			operand.pop_back();
			cout << "\b \b";
			continue;
		}
		if ((key == 13 || key == 32) && operand.length() != 0)
		{
			if (regex_match(operand, number_0) || regex_match(operand, number_1) || regex_match(operand, number_2) || regex_match(operand, number_3))
			{
				opd = atof(operand.c_str());
				cout << endl;
			/*	for (int i = 0; i < operand.length(); i++)
				{
					cout << "\b \b";
				}
				cout << '\r';
				cout <<opd << endl;*/
				break;
			}
			else continue;

		}

		operand += (char)key;
		if (regex_match(operand, number_0) || regex_match(operand, number_1) || regex_match(operand, number_2))
		{
			cout << (char)key;
			continue;
		}

		else
		{
			operand.pop_back();
		}
	}
}
