#pragma once
#include <string>

using namespace std;

class Product
{
public:
	void frPrint();
	string name, brand;
	float price;
	int inStock;
	static int grandValue; //static ����

	static void statFunc(); // static �����
	void printDat();
	Product();
	Product(string Name, string Brand, float Price, int InStock);
	~Product();
};

