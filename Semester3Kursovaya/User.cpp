#include "User.h"


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
