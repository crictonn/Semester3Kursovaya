#include "Order.h"


//	string name, brand, number, status, customerFIO, customerPhoneNumber;
//	float price;

Order::Order() {
	name = brand = number = customerFIO = customerPhoneNumber = "None"; 
	price = 0;
}
Order::~Order() {};