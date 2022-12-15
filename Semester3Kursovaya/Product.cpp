#include "Product.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void Product::printDat() {
	cout.setf(ios::left);
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout <<  "Наименоваие: "<<setw(20) << name << " | Брэнд: " << setw(15) << brand << " | Цена: " << setw(8) << price << "рублей"<< "| Количество в наличии: " << setw(20) << inStock << endl;
}

void Product::frPrint() {
	cout << "Эта функция нужна чисто для того, чтобы показать friend-функции";
}

void Product::statFunc() {
	cout << "Эта функция нужна чисто для того, чтобы показать static функцию";
}

Product::Product() {
	name = "Телевизор";
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
