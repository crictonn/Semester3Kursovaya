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
	string printlogin();
	string printPass();
	int printCoeff();
	
	void makeAdmin();
	
	void fileWrite(string path);
	void getFromFile(string path);

	
};

