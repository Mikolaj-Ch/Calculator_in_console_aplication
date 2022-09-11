#pragma once
#include <vector>

using namespace std;

//Matrices class template
template<typename T>
class MatricesOperation
{
public:
	MatricesOperation(int, int);
	~MatricesOperation();
	MatricesOperation operator+(MatricesOperation&);
	MatricesOperation operator-(MatricesOperation&);
	MatricesOperation operator*(MatricesOperation&);
	void transpone();
	void determine_the_reverse();
	int return_dimension_x();
	int return_dimension_y();
	void show_matrices();
private:
	void input_numbers_to_matrice();
	vector<vector<T>> data_matrice;
	int dimension_x = 0;
	int dimension_y = 0;
};