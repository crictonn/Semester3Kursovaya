#include "User.h"
#include <iomanip>

User::User() {
	login = getLogin();
	password = getPassword();
	adminCoeff = 0;
};

User::User(string log, string pass) {
	login = log;
	password = pass;
	adminCoeff = 0;
};

User::User(string log, string pass, int adm) {
	login = log;
	password = pass;
	adminCoeff = adm;
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
	cout.setf(ios::left);
	if(adminCoeff == 1)
		cout <<setw(20)<< login << setw(30) << password << " �������������" << endl;
	else
		cout << setw(20) << login << setw(30) << password << endl;
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
		out.open(path, ios::app); //����� ����� ��������� ios::binary, ��� �� �������� � ��������� �������
		out << login << ";" << password << ";" << adminCoeff << ";" << endl;
		out.close();
	}
	catch (...) {
		cout << "������ ��� ������� �������� �����! ";
	}
}

void User::getFromFile(string path, string checkLogin) {
	ifstream in;
	string buff, passCheck;
	vector <string> out;
	const char delim = ';';
	bool check = false;
	try {
		in.open(path); //����� ����� ��������� ios::binary, ��� �� �������� � ��������� �������
		while (getline(in, buff)) {
			size_t start, end = 0;
			while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
			{
				end = buff.find(delim, start);
				out.push_back(buff.substr(start, end - start));
			}
			login = out[0];
			if (checkLogin == login) {
				check = true;
				password = out[1];
				adminCoeff = atoi(out[2].c_str());
				while (passCheck != "0") {
					system("cls");
					cout << "������� ��� �����: " << login << endl;
					cout << "������� ��� ������: ";
					getline(cin, passCheck);
					if (password == passCheck) {
						if (adminCoeff == 1) {
							adminMenu();
						}
						else {
							userMenu();
						}
						break;
					}
					else {
						cout << "�������� ������!\n";
						system("pause");
					}
				}
			}
			out.clear();
		}
		if (!check) {
			cout << "�������� �����";
			system("pause");
		}
		in.close();
	}
	catch (...) {
		cout << "������ ��� ������� �������� �����! ";
	}
}