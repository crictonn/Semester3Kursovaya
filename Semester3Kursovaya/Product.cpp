#include "Product.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void Product::printDat() {
	cout.setf(ios::left);
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout <<  "�����������: "<<setw(20) << name << " | �����: " << setw(15) << brand << " | ����: " << setw(8) << price << "������"<< "| ���������� � �������: " << setw(20) << inStock << endl;
}

void Product::frPrint() {
	cout << "��� ������� ����� ����� ��� ����, ����� �������� friend-�������";
}

void Product::statFunc() {
	cout << "��� ������� ����� ����� ��� ����, ����� �������� static �������";
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
