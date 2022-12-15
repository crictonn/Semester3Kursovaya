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
	cout.setf(ios::left);
	if(adminCoeff == 1)
		cout <<setw(20)<< login << setw(30) << password << " Администратор" << endl;
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
		out.open(path, ios::app); //Здесь нужно прописать ios::binary, что бы работало с бинарными файлами
		out << login << ";" << password << ";" << adminCoeff << ";" << endl;
		out.close();
	}
	catch (...) {
		cout << "Ошибка при попытке открытия файла! ";
	}
}

void User::getFromFile(string path, string checkLogin) {
	ifstream in;
	string buff, passCheck;
	vector <string> out;
	const char delim = ';';
	bool check = false;
	try {
		in.open(path); //Здесь нужно прописать ios::binary, что бы работало с бинарными файлами
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
					cout << "Введите Ваш логин: " << login << endl;
					cout << "Введите Ваш пароль: ";
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
						cout << "Неверный пароль!\n";
						system("pause");
					}
				}
			}
			out.clear();
		}
		if (!check) {
			cout << "Неверный логин";
			system("pause");
		}
		in.close();
	}
	catch (...) {
		cout << "Ошибка при попытке открытия файла! ";
	}
}