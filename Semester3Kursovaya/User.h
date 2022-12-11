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
	User(string login, string password);
	~User();

	string getLogin();
	string getPassword();
	void printData();
	void makeAdmin();

	
};
//
//public:
//	User();
//	~User();
//};
