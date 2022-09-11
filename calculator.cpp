#include <iostream>
#include <vector>

#include "Calculator.h"
#include "Security.h"

using namespace std;

/*!
* \brief Calculator class.
* Allows to:
* - get a number
* - show result and add next number
*/

/*!
* \brief Class Calculator constructor.
* 
* Create calculator object and takes the prime number.
*/
Calculator::Calculator()
{
	float first = 0;
	cout << "\nFirst number:";
	first = input_check_for_number(first);
	Calculator::numbers.push_back(first);
	Calculator::numbers.push_back(0);
}

/*!
* \brief Currently not used.
*/
bool Calculator::add_new_number()
{
	bool chose = false;
	string yes_or_no;
	cout << "Do you want to add another number to operation?\n Y = yes, Other = No";
	cin >> yes_or_no;
	chose = y_or_n(yes_or_no);
	return chose;
}

/*!
* \brief Method (void) collector next number to operation.
*/
void Calculator::add_next_number()
{
	float number = 0;
	cout << "Number to operation is:";
	number = input_check_for_number(number);
	Calculator::numbers[1] = number;
}

/*!
* \brief Method  (void) showing result.
*/
void Calculator::show_result(float result)
{
	cout << "\n\x1B[35m     Current number: \033[0m" << result << endl;
}