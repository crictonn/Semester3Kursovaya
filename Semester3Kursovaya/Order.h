#pragma once
#include <string>
#include "Product.h"

using namespace std;

class Order : public Product
{
private:
	string number, status, customerFIO, customerPhoneNumber;

public:
	Order();
	~Order();
};

