#pragma once
#include <string>
#include <iostream>

using namespace std;

class User
{
private:
	string login, password;
	int adminCoeff;

public:
	User();
	~User();
};
