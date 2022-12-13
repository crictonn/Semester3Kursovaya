#pragma once
#include <string>

using namespace std;

class Order
{
private:
	string name, brand, number, status, customerFIO, customerPhoneNumber;
	float price;

public:
	Order();
	~Order();
};

