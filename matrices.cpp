#include <vector>
#include <iostream>
#include <string>

#include "Matrices.h"
#include "Security.h"

using namespace std;

/*!
*\ brief The MatricesOperations class allows you to generate a matrix with dimensions and data entered by the user and perform operations on it.
*
*Supported operations :
*-Adding another Matrix type object from the generated matrix
* -Subtract another Matrix object from the generated matrix
* -Multiplication of the generated matrix by another Matrix type object
* -Transposition of the generated matrix
* -Determination of the matrix inverse of the generated matrix
*/

/*!
*\ brief Constructor of the MatricesOperations class
*
*Creates an object of type Matrix.As arguments it takes : number of matrix columns(int), number of matrix rows(int).
*/
template<typename T>MatricesOperation<T>::MatricesOperation(int dimension_x, int dimension_y)
{
	MatricesOperation::dimension_x = dimension_x;
	MatricesOperation::dimension_y = dimension_y;
	MatricesOperation::input_numbers_to_matrice();
}

template<typename T>MatricesOperation<T>::~MatricesOperation() {};

/*!
*\ brief Overloading the addition operator.
*
*It allows to add two Matrix type objects together.
*/
template<typename T>MatricesOperation<T> MatricesOperation<T>::operator+(MatricesOperation& skladnik)
{
	if ((MatricesOperation::return_dimension_x() == skladnik.return_dimension_x()) && (MatricesOperation::return_dimension_y() == skladnik.return_dimension_y()))
	{
		for (int i = 0; i < MatricesOperation::return_dimension_y(); i++)
		{
			for (int k = 0; k < MatricesOperation::return_dimension_x(); k++)
			{
				skladnik.data_matrice[i][k] += MatricesOperation::data_matrice[i][k];
			}
		}
	}
	else
	{
		throw "\nYou can't di this, dimension incompatbibile.\n ";
	}
	return skladnik;
}

/*!
*\ brief Overloading the subtraction operator.
*
*It allows you to subtract two Matrix type objects from each other.
*/
template<typename T>MatricesOperation<T> MatricesOperation<T>::operator-(MatricesOperation& skladnik)
{
	if ((MatricesOperation::return_dimension_x() == skladnik.return_dimension_x()) && (MatricesOperation::return_dimension_y() == skladnik.return_dimension_y()))
	{
		for (int i = 0; i < MatricesOperation::return_dimension_y(); i++)
		{
			for (int k = 0; k < MatricesOperation::return_dimension_x(); k++)
			{
				skladnik.data_matrice[i][k] -= MatricesOperation::data_matrice[i][k];
			}
		}
	}
	else
	{
		throw "\nYou can't di this, dimension incompatbibile.\n ";
	}
	return skladnik;
}

/*!
*\ brief Overload of the multiplication operator
*
*Allows you to multiply two Matrix type objects by yourself.
*/
template<typename T>MatricesOperation<T>MatricesOperation<T>::operator*(MatricesOperation& skladnik)
{
	if ((MatricesOperation::return_dimension_x() == skladnik.return_dimension_y()))
	{
		vector<vector<T>> result;
		for (int i = 0; i < skladnik.return_dimension_x(); i++)
		{
			vector<T> row;
			row.clear();

			for (int k = 0; k < MatricesOperation::return_dimension_y(); k++)
			{
				T Var = 0;
				for (int o = 0; o < skladnik.return_dimension_y(); o++)
				{
					Var = skladnik.data_matrice[o][i] * MatricesOperation::data_matrice[k][o];
				}

				row.push_back(Var);

			}

			result.push_back(row);
		}
		skladnik.data_matrice = result;
		skladnik.dimension_x = result[0].size();
		skladnik.dimension_y = result.size();
		skladnik.transpone();
	}
	else
	{
		throw "\nYou can't di this, dimension incompatbibile.\n ";
	}
	return skladnik;
}

/*!
*\ brief A method(void) transposing a matrix
*/
template<typename T>void MatricesOperation<T>::transpone()
{
	vector<vector<T>> t_matric;
	vector<T> row;
	for (int i = 0; i < (MatricesOperation::return_dimension_x()); i++)
	{
		row.clear();
		for (int l = 0; l < (MatricesOperation::return_dimension_y()); l++)
		{
			row.push_back(10);
		}
		t_matric.push_back(row);
	}

	for (int i = 0; i < (MatricesOperation::return_dimension_y()); ++i)
	{
		for (int k = 0; k < (MatricesOperation::return_dimension_x()); ++k)
		{
			t_matric[k][i] = MatricesOperation::data_matrice[i][k];
			//swap(MatricesOperation::data_matrice[k][i], MatricesOperation::data_matrice[i][k]);
		}
	}
	MatricesOperation::data_matrice = t_matric;
}

/*!
*\ brief The(void) method for determining the inverse matrix.
*
* Supports 2x2 and 3x3 matrices.
*/
template<typename T>void MatricesOperation<T>::determine_the_reverse()
{
	if ((MatricesOperation::return_dimension_x() == 2) && (MatricesOperation::return_dimension_y() == 2))
	{
		T determinant = MatricesOperation::data_matrice[0][0] * MatricesOperation::data_matrice[1][1] - MatricesOperation::data_matrice[1][0] * MatricesOperation::data_matrice[0][1];
		if (!((determinant < 0.0001) && (determinant > -0.0001)))
		{
			T a = MatricesOperation::data_matrice[0][0];
			T b = MatricesOperation::data_matrice[0][1];
			T c = MatricesOperation::data_matrice[1][0];
			T d = MatricesOperation::data_matrice[1][1];
			MatricesOperation::data_matrice[0][0] = (1 / determinant) * d;
			MatricesOperation::data_matrice[0][1] = (1 / determinant) * (-b);
			MatricesOperation::data_matrice[1][0] = (1 / determinant) * (-c);
			MatricesOperation::data_matrice[1][1] = (1 / determinant) * a;
		}
		else
		{
			throw "\nYou can't di this, determinant is 0\n";
		}
	}

	else if ((MatricesOperation::return_dimension_x() == 3) && (MatricesOperation::return_dimension_y() == 3))
	{
		T a11 = MatricesOperation::data_matrice[0][0];
		T a12 = MatricesOperation::data_matrice[0][1];
		T a13 = MatricesOperation::data_matrice[0][2];

		T a21 = MatricesOperation::data_matrice[1][0];
		T a22 = MatricesOperation::data_matrice[1][1];
		T a23 = MatricesOperation::data_matrice[1][2];

		T a31 = MatricesOperation::data_matrice[2][0];
		T a32 = MatricesOperation::data_matrice[2][1];
		T a33 = MatricesOperation::data_matrice[2][2];

		T determinant = (a11 * a22 * a33) + (a12 * a23 * a31) + (a21 * a32 * a13) - (a13 * a22 * a31) - (a11 * a32 * a23) - (a21 * a12 * a33);

		if (!((determinant < 0.0001) && (determinant > -0.0001)))
		{
			MatricesOperation::data_matrice[0][0] = (1 / determinant) * ((a22 * a33) - (a23 * a32));
			MatricesOperation::data_matrice[0][1] = (1 / determinant) * ((a13 * a32) - (a12 * a33));
			MatricesOperation::data_matrice[0][2] = (1 / determinant) * ((a12 * a23) - (a13 * a22));

			MatricesOperation::data_matrice[1][0] = (1 / determinant) * ((a23 * a31) - (a21 * a33));
			MatricesOperation::data_matrice[1][1] = (1 / determinant) * ((a11 * a33) - (a13 * a31));
			MatricesOperation::data_matrice[1][2] = (1 / determinant) * ((a13 * a21) - (a11 * a23));

			MatricesOperation::data_matrice[2][0] = (1 / determinant) * ((a21 * a32) - (a22 * a31));
			MatricesOperation::data_matrice[2][1] = (1 / determinant) * ((a12 * a31) - (a11 * a32));
			MatricesOperation::data_matrice[2][2] = (1 / determinant) * ((a11 * a22) - (a12 * a21));
		}
	}
	else
	{
		throw "\nYou can't di this\n";
	}
}

/*!
*\ brief Returns the X dimension of the matrix.
*
*Returns an int.
*/
template<typename T>int MatricesOperation<T>::return_dimension_x()
{
	return MatricesOperation::dimension_x;
}

/*!
*\ brief Returns the Y dimension of the matrix.
*
*Returns an int.
*/
template <typename T>int MatricesOperation<T>::return_dimension_y()
{
	return MatricesOperation::dimension_y;
}

/*!
*\ brief Displays the matrix in the console.
*/
template<typename T>void MatricesOperation<T>::show_matrices()
{
	string tempMessage = "";
	for (auto& elem : MatricesOperation::data_matrice)
	{
		tempMessage = "";
		for (auto& insideElem : elem)
		{
			tempMessage += " ";
			tempMessage += to_string(insideElem);
		}
		cout << tempMessage << "\n\n";
	}
}

/*!
*\ brief Allows the user to enter data into the matrix.
*
*Accepts all numeric types.
*/
template<typename T>void MatricesOperation<T>::input_numbers_to_matrice()
{
	vector<T> temp;
	T var;

	for (int i = 0; i < MatricesOperation::return_dimension_y(); i++)

	{
		temp.clear();
		for (int k = 0; k < MatricesOperation::return_dimension_x(); k++)
		{
			int color = 0;
			if ((31 + 1) > 37)
			{
				color = 93 + i;
			}
			else
			{
				color = 31 + i;
			}

			cout << "\x1B[" << color << "m";
			cout << "a" << (k + 1) << (i + 1) << "=";
			cout << "\033[0m";

			while (!(cin >> var))
			{
				cout << "Bad value, put new\n";
				cout << "\x1B[" << color << "m";
				cout << "a" << (k + 1) << (i + 1) << "=";
				cout << "\033[0m";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			temp.push_back(var);
		}
		MatricesOperation::data_matrice.push_back(temp);
		cout << "\n";
	}
}
