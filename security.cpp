#include <iostream>

#include "Calculator.h"
#include "Security.h"

using namespace std;

/*!
* \brief Does not apply, it may be used
*/
bool y_or_n(string y_n)
{
	bool chose;
	if (y_n == "Y" or y_n == "y")
	{
		chose = true;
	}
	else
	{
		chose = true;
	}
	return chose;
}

/*!
* \brief Checks user selection for basic operations.
*/
int input_check_for_switch_basic(string input)
{
	int menu_index = 0;
		if (input == "+")
		{
			menu_index = 1;
		}
		else if (input == "-")
		{
			menu_index = 2;
		}
		else if (input == "*")
		{
			menu_index = 3;
		}
		else if (input == "/")
		{
			menu_index = 4;
		}
		else if (input == "S" or input =="s")
		{
			menu_index = 5;
		}
		else
		{
			menu_index = 0;
		}

	return menu_index;
}

/*!
* \brief Checks input number from user.
*/
float input_check_for_number(float number)
{
	cin >> number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter correct value: ";
		cin >> number;
	}
	return number;
}

/*!
* \brief Checks input number from user.
*/
float input_check_for_number_for_matrice()
{
	float number;
	cin >> number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter correct value: ";
		cin >> number;
	}
	return number;
}

/*!
* \brief Checks user selection in main loop.
*/
int input_check_for_operation(string input)
{
	int menu_index = 0;
		if (input == "B")
		{
			menu_index = 1;
		}
		else if (input == "M")
		{
			menu_index = 2;
		}
		else if (input == "S" or input == "s")
		{
			menu_index = 3;
		}
		else
		{
			menu_index = 0;
		}

	return menu_index;
}

/*!
* \brief Checks user selection for matrixs operations.
*/
int input_check_for_switch_matrices(string input)
{
	int menu_index = 0;
	if (input == "+")
	{
		menu_index = 1;
	}
	else if (input == "-")
	{
		menu_index = 2;
	}
	else if (input == "*")
	{
		menu_index = 3;
	}
	else if (input == "T" or input == "t")
	{
		menu_index = 4;
	}
	else if (input == "R" or input == "r")
	{
		menu_index = 5;
	}
	else if (input == "S" or input == "s")
	{
		menu_index = 6;
	}
	else
	{
		menu_index = 0;
	}

	return menu_index;
}