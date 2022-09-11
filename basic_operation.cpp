#include <iostream>

#include "Basic_operation.h"

using namespace std;

/*!
* \brief BasicOperations class.
* Allows to:
* - add numbers
* - minus numbers
* - multiplication numbers
* - dividing number
*/

/*!
* \brief Method(void) add numbers.
*/
float BasicOperation::add()
{
	return Calculator::numbers[0] += Calculator::numbers[1];
}

/*!
* \brief Method(void) minus numbers.
*/
float BasicOperation::minus()
{
	return Calculator::numbers[0] -= Calculator::numbers[1];
}

/*!
* \brief Method(void) multiplication numbers.
*/
float BasicOperation::multiplication()
{
	return Calculator::numbers[0] = Calculator::numbers[0] * Calculator::numbers[1];
}

/*!
* \brief Method(void) dividing numbers.
*/
float BasicOperation::dividing()
{
	
	if(Calculator::numbers[1] == 0)
	{
		cout << "You can't dividing by 0\n";
		Calculator::numbers[0] = Calculator::numbers[0];
	}
	else
	{
		return Calculator::numbers[0] = Calculator::numbers[0] / Calculator::numbers[1];
	}
}