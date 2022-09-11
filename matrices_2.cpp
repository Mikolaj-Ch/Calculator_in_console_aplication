#include "Matrices.h"
#include "matrices.cpp"

/*!
* \brief Method responsible for add matrices.
*/
void add_matrices()
{
	try
	{
		int X1;
		int X2;
		int Y1;
		int Y2;

		cout << "\nPut X first matrice:\n";
		X1 = input_check_for_number_for_matrice();

		cout << "\nPut Y first matrice:\n";
		Y1 = input_check_for_number_for_matrice();

		cout << "\nFor first matrice:\n";
		MatricesOperation<float> matrice_1 = MatricesOperation<float>(X1, Y1);
		cout << "\nCreate matrice:\n";
		matrice_1.show_matrices();

		cout << "\nPut X second matrice:\n";
		X2 = input_check_for_number_for_matrice();

		cout << "\nPut Y second matrice:\n";
		Y2 = input_check_for_number_for_matrice();

		cout << "\nFor second matrice:\n";
		MatricesOperation<float> matrice_2 = MatricesOperation<float>(X2, Y2);
		cout << "\nCreate matrice:\n";
		matrice_2.show_matrices();

		MatricesOperation<float> sum = matrice_1 + matrice_2;
		cout << "\nResult:\n";
		sum.show_matrices();
	}
	catch (const char* e)
	{
		cout << e;
	}
}

/*!
* \brief Method responsible for minus matrices.
*/
void minus_matrices()
{
	try
	{
		int X1;
		int X2;
		int Y1;
		int Y2;

		cout << "\nPut X first matrice:\n";
		X1 = input_check_for_number_for_matrice();

		cout << "\nPut Y first matrice:\n";
		Y1 = input_check_for_number_for_matrice();

		cout << "\nFor first matrice:\n";
		MatricesOperation<float> matrice_1 = MatricesOperation<float>(X1, Y1);
		cout << "\nCreate matrice:\n";
		matrice_1.show_matrices();

		cout << "\nPut X second matrice:\n";
		X2 = input_check_for_number_for_matrice();

		cout << "\nPut Y second matrice:\n";
		Y2 = input_check_for_number_for_matrice();

		cout << "\nFor second matrice:\n";
		MatricesOperation<float> matrice_2 = MatricesOperation<float>(X2, Y2);
		cout << "\nCreate matrice:\n";
		matrice_2.show_matrices();

		MatricesOperation<float> sum = matrice_1 - matrice_2;
		cout << "\nResult:\n";
		sum.show_matrices();
	}
	catch (const char* e)
	{
		cout << e;
	}
}

/*!
* \brief Method responsible for multiplication matrices.
*/
void multiplication_matrices()
{
	try
	{
		int X1;
		int X2;
		int Y1;
		int Y2;

		cout << "\nPut X first matrice:\n";
		X1 = input_check_for_number_for_matrice();

		cout << "\nPut Y first matrice:\n";
		Y1 = input_check_for_number_for_matrice();

		cout << "\nFor first matrice:\n";
		MatricesOperation<float> matrice_1 = MatricesOperation<float>(X1, Y1);
		cout << "\nCreate matrice:\n";
		matrice_1.show_matrices();

		cout << "\nPut X second matrice:\n";
		X2 = input_check_for_number_for_matrice();

		cout << "\nPut Y second matrice:\n";
		Y2 = input_check_for_number_for_matrice();

		cout << "\nFor second matrice:\n";
		MatricesOperation<float> matrice_2 = MatricesOperation<float>(X2, Y2);
		cout << "\nCreate matrice:\n";
		matrice_2.show_matrices();

		MatricesOperation<float> sum = matrice_1 * matrice_2;
		cout << "\nResult:\n";
		sum.show_matrices();
	}
	catch (const char* e)
	{
		cout << e;
	}
}

/*!
* \brief Method responsible for taranspone matrix.
*/
void transpone()
{
	try
	{
		int X1;
		int Y1;

		cout << "\nPut on X:\n";
		X1 = input_check_for_number_for_matrice();

		cout << "\nPut on Y:\n";
		Y1 = input_check_for_number_for_matrice();

		cout << "\nPut on value:\n";
		MatricesOperation<float> matrice = MatricesOperation<float>(X1, Y1);
		cout << "\nCreate matrice:\n";
		matrice.show_matrices();
		matrice.transpone();
		cout << "\nResult:\n";
		matrice.show_matrices();
	}
	catch (const char* e)
	{
		cout << e;
	}
}

/*!
* \brief Method responsible for reverse matrix.
*/
void reverse()
{
	try
	{
		int X1;
		int Y1;

		cout << "\nPut on X:\n";
		X1 = input_check_for_number_for_matrice();

		cout << "\nPut on Y:\n";
		Y1 = input_check_for_number_for_matrice();

		cout << "\nWprowadz wartosci macierzy:\n";
		MatricesOperation<float> matrice = MatricesOperation<float>(X1, Y1);
		cout << "\nUtworzona macierz:\n";
		matrice.show_matrices();
		matrice.determine_the_reverse();
		cout << "\nWynik:\n";
		matrice.show_matrices();
	}
	catch (const char* e)
	{
		cout << e;
	}
}