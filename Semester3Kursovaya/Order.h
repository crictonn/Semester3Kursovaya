#pragma once
#include <string>
#include "Product.h"
using namespace std;

class Order : public Product
{
private:
	string number, status, customerFIO, customerPhoneNumber;

public:
	void fileWriteOrder(string path);
	void fileDeleteOrder(string path);

	Order();
	Order(string Number, string Stat, string fio, string pone, Product product);
	Order(string Number, string name, string brand, string Stat, float price, int instock, string fio, string pone);
	~Order();
};

