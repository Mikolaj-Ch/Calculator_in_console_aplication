#pragma once
#include <vector>

using namespace std;

//Main class template.
class Calculator
{
public:
	Calculator();
	~Calculator(){};
	bool add_new_number();
	void add_next_number();
	void show_result(float result);
private:
	friend class BasicOperation;
	vector<float> numbers;
	
};
