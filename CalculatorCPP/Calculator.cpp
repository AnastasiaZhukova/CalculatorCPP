#include "Calc_lib_head.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	head();
	bool continue_flag = true, start_flag = true, calc_flag = true;;
	string result;
	int pecision;
	double operand1, operand2;
	char operation;
	while (calc_flag)
	{
		if (start_flag)
		{
			
			input_operand(operand1, continue_flag, calc_flag);
			if (!calc_flag) { break; }
			if (!continue_flag) { continue_flag = true; start_flag = true; C_function(); continue; }
			start_flag = false;
		}
		input_operator(operation, continue_flag, calc_flag);
		if (!calc_flag) { break; }
		if (!continue_flag) { continue_flag = true; start_flag = true; C_function(); continue; }
		switch (operation)
		{
		case '+':
		{
			input_operand(operand2, continue_flag, calc_flag);
			if (!calc_flag) { break; }
			if (!continue_flag) { continue_flag = true; start_flag = true; C_function(); continue; }
			cout << "=" << endl;
			addition(operand1, operand2);
			result = to_string(operand1);
			cout << result;
			/*cout << addition(operand1, operand2);*/
			break;
		}
		case '-':
		{
			input_operand(operand2, continue_flag, calc_flag);
			if (!calc_flag) { break; }
			if (!continue_flag) { continue_flag = true; start_flag = true; C_function(); continue; }
			cout << "=" << endl;
			subtraction(operand1, operand2);
			result = to_string(operand1);
			cout << result;
			break;
		}
		case '*':
		{
			input_operand(operand2, continue_flag, calc_flag);
			if (!calc_flag) { break; }
			if (!continue_flag) { continue_flag = true; start_flag = true; C_function(); continue; }
			cout << "=" << endl;
			multiplication(operand1, operand2);
			result = to_string(operand1);
			cout << result;
			break;
		}
		case '/':
		{
			input_operand(operand2, continue_flag, calc_flag);
			if (!calc_flag) { break; }
			if (!continue_flag) { continue_flag = true; start_flag = true; C_function(); continue; }
			cout << "=" << endl;
			try
			{
				if (operand2 == 0)
				{
					throw "Error!Division by zero!";
				}
				division(operand1, operand2);
				result = to_string(operand1);
				cout << result;
			}
			catch (const char *str)
			{
				cout << str << endl;
				start_flag = true;
			}
			break;
		}
		case '^':
		{
			input_operand(operand2, continue_flag, calc_flag);
			if (!calc_flag) { break; }
			if (!continue_flag) { continue_flag = true; start_flag = true; C_function(); continue; }
			cout << "=" << endl;
			try
			{
				if (operand2 == 0 && operand1 == 0) throw 1;
				if (operand2 < 0 && operand1 == 0) throw 2;
				if (operand2 > 0 && operand2 < 1 && operand1 < 0) throw 3;
				power(operand1, operand2);
				result = to_string(operand1);
				cout << result;
			}
			catch (int i)
			{
				if (i == 1)
				{
					cout << "Error! 0^0 is unavailable operation!" << endl;
				}
				if (i == 2)
				{
					cout << "Error! This operation available for all numbers exept '0'(zero)!" << endl;
				}
				if (i == 3)
				{
					cout << "Error! Wrong data!" << endl;
				}
				start_flag = true;
			}
			break;
		}

		}
		cout << endl;
	}


	return 0;
}