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
	cout << "������� �����: ";
	try {
		cin >> log;
	}
	catch (...) {
		cout << "�������� ����";
	}
	return log;
};

string User::getPassword() {
	string pass;
	cout << "������� ������ �� 4 ������: ";
	while (true) {
		cin >> pass;
		if (pass.size() >= 4) {
			return pass;
		}
		else {
			cout << "������������ ��������" << endl;
		}
	}
}

void User::makeAdmin() {
	adminCoeff = 1;
}

void User::printData() {
	cout << login << " " << password << " " << adminCoeff << endl;
}
