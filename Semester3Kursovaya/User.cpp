#include "User.h"
#include <fstream>

User::User() {
	login = getLogin();
	password = getPassword();
	adminCoeff = 0;
};

User::User(string log, string password) {
	login = log;
	User::password = password;
	User::adminCoeff = 0;
};

User::~User() {
};


string User::getLogin() {
	string log;
	cout << "Введите логин: ";
	try {
		cin >> log;
	}
	catch (...) {
		cout << "Неверный ввод";
	}
	return log;
};

string User::getPassword() {
	string pass;
	cout << "Введите пароль от 4 знаков: ";
	while (true) {
		cin >> pass;
		if (pass.size() >= 4) {
			return pass;
		}
		else {
			cout << "Недостаточно символов" << endl;
		}
	}
}

void User::makeAdmin() {
	adminCoeff = 1;
}


void User::printData() {
	cout << login << " " << password << " " << adminCoeff << endl;
}

string User::printlogin(){
	return login;
}

string User::printPass(){
	return password;
}

int User::printCoeff(){
	return adminCoeff;
}

void User::fileWrite(string path) {
	ofstream out;
	try {
		out.open(path, ios::app); //Здесь нужно прописать ios::binary, что бы работало с бинарными файлами
		out << login << password << adminCoeff << endl;
		out.close();
	}
	catch (...) {
		cout << "Ошибка при попытке открытия файла! ";
	}
}

void User::getFromFile(string path) {
	ifstream in;
	try {
		in.open(path); //Здесь нужно прописать ios::binary, что бы работало с бинарными файлами
		while (getline(in, login)) {
			cout << login << endl;
		}
		in.close();
	}
	catch (...) {
		cout << "Ошибка при попытке открытия файла! ";
	}
}