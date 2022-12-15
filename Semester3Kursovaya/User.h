#pragma once
#include "Functions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class User
{
private:
	string login, password;
	int adminCoeff;

public:
	
	User();
	User(string login, string pass);
	User(string login, string pass, int adm);
	~User();

	string getLogin();
	string getPassword();

	void printData();
	string printlogin();
	string printPass();
	int printCoeff();
	
	void makeAdmin();
	
	void fileWrite(string path);
	void getFromFile(string path, string checkLogin);

	
};

