#include <iostream>
#include <string>

#include "Calculator.h"
#include "Security.h"
#include "Basic_operation.h"
#include "Matrices_2.h"


using namespace std;

//Function with title 
void hello_word()
{
	cout << "\x1B[31m_____Hello!!_____\033[0m\t\t\nPlease check my calculator";
}

//Function responsible for basic operation, choosing.
void basic_operation_managmnet()
{
	string chose_calculation;
	BasicOperation b;

	while (1)
	{

		cout << "\nYou can(s or S = end):\n-Add number (+)\n-Minus number (-)\n-Multiplication of numbers (*)\n- Dividing a number (/)\n";
		cout << "\n       Your chose:";
		cin >> chose_calculation;
		switch (input_check_for_switch_basic(chose_calculation))
		{
		case 1:
		{
			b.add_next_number();
			b.show_result(b.add());
			break;
		}
		case 2:
		{
			b.add_next_number();
			b.show_result(b.minus());
			break;
		}
		case 3:
		{
			b.add_next_number();
			b.show_result(b.multiplication());
			break;
		}
		case 4:
		{
			b.add_next_number();
			b.show_result(b.dividing());
			break;
		}
		case 5:
		{
			exit(0);
		}
		default:
		{
			break;
		}
		}

	}
}

//Function responsible for matrices, choosing.
void matrices_operation_managmnet()
{
	string chose_calculation;

	while (1)
	{

		cout << "\nYou can(s or S = end):\n-Add matrices (+)\n-Minus matrices (-)\n-Multiplication of matrices (*)\n- Transpone matrices (T or t)\n- Revers matrices (R or r)\n";
		cout << "\n       Your chose:";
		cin >> chose_calculation;
		switch (input_check_for_switch_matrices(chose_calculation))
		{
		case 1:
		{
			add_matrices();
			break;
		}
		case 2:
		{
			minus_matrices();
			break;
		}
		case 3:
		{
			multiplication_matrices();
			break;
		}
		case 4:
		{
			transpone();
			break;
		}
		case 5:
		{
			reverse();
		}
		case 6:
		{
			exit(0);
		}
		default:
		{
			break;
		}
		}

	}
}

//Fain function with loop and main menu
int main()
{
	hello_word();
	string chose_operation;
	do {
		cout << "\nB is basic operation\nM is matrices operation\nS ora s is stop\nYour chose:";
		cin >> chose_operation;
		input_check_for_operation(chose_operation);
		if (input_check_for_operation(chose_operation) == 1)
		{
			basic_operation_managmnet();
		}
		else if (input_check_for_operation(chose_operation) == 2)
		{
			matrices_operation_managmnet();
		}
		else if (input_check_for_operation(chose_operation) == 3)
		{
			return 0;
		}
	} while (input_check_for_operation(chose_operation) == 0);
}

