#include "Product.h"
#include <fstream>
#include <iostream>

void Product::printDat() {
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "�����������: " << name << " | �����: " << brand << " | ����: " << price << "������ | ���������� � �������: " << inStock << endl;
}

Product::Product() {
	name = "���������";
	brand = "LG";
	price = 199.99;
	inStock = 0;
}

Product::Product(string Name, string Brand, float Price, int InStock) {
	name = Name;
	brand = Brand;
	price = Price;
	inStock = InStock;
}

Product::~Product() {};
