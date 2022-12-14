#pragma once
#include <string>

using namespace std;

class Product
{
public:
	string name, brand;
	float price;
	int inStock;

	Product();
	Product(string Name, string Brand, float Price, int InStock);
	~Product();
};
