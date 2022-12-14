#include "Order.h"
#include <fstream>

//	string name, brand, number, status, customerFIO, customerPhoneNumber;
//	float price;

Order::Order() {
	name = brand = number = customerFIO = customerPhoneNumber = "None";
	price = inStock = 0;
}

Order::Order(string Number, string Stat, string fio, string pone, Product product) {
	number = Number;
	status = Stat;
	customerFIO = fio;
	customerPhoneNumber = pone;
	name = product.name;
	brand = product.brand;
	price = product.price;
	inStock = product.inStock;
}

Order::Order(string Number, string Stat, string fio, string pone, string Name, string Brand, float Price, int instock) {
	number = Number;
	status = Stat;
	customerFIO = fio;
	customerPhoneNumber = pone;
	name = Name;
	brand = Brand;
	price = Price;
	inStock = instock;
}

Order::~Order() {};


void Order::fileWriteOrder(string path) {
	ofstream out;
	out.open(path, ios::app);
	out << number << ';' << name << ';' << brand << ';' << status << ';' << price << ';' << inStock << ';' << customerFIO << ';' << customerPhoneNumber << ';' << endl;
};