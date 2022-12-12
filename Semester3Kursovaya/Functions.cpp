#include "Functions.h"
#include "User.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string userPath = "Users.txt", orderPath = "Orders.txt";

void prevMenu() {
	while (true) {
		system("cls");
		cout << "1. Вход в аккаунт\n"
			"2. Регистрация\n"
			"3. Выход" << endl;
		switch (_getch()) {

		case '1': loggingIn(); break;

		case '2': registration(); break;

		case '3': return;
		/*default: 
			system("cls");
			cout << "Неверный ввод! " << endl;
			system("pause");
			break;*/
		}
	
		
	}
}


void loggingIn() {
	string inLog, inPass;
	User outUser("None", "None");
	system("cls");
	cout << "Введите Ваш логин: ";
	getline(cin, inLog);
	outUser.getFromFile(userPath, inLog);
}

void registration() {
	bool ex = false;
	const char delim = ';';
	size_t start, end = 0;
	string login = "", pass, buff, logExistCheck;
	vector <string> vect;
	ifstream in(userPath);

	while (login.empty()) {
		while (true) {
			system("cls");
			cout << "Придумайте логин: ";
			getline(cin, login);
			if (login.find(' ') != string::npos) {
				cout << "Логин не может содержать пробелы " << endl;
				system("pause");
			}
			else {
				while (getline(in, buff)) {
					while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
					{
						end = buff.find(delim, start);
						vect.push_back(buff.substr(start, end - start));
					}
					logExistCheck = vect[0];
					if (logExistCheck == login) {
						cout << "Такой логин уже существует\n";
						system("pause");
						break;
					}
					else ex = true;
				}
			}	
			if (ex) break;
		}
		if (ex) break;
	}
	while (true) {
		system("cls");
		cout << "Придумайте логин: " << login << endl;;
		cout << "\nПридумайте пароль:  ";
		getline(cin, pass);
		if (pass.find(' ') == string::npos && pass.size() >= 4) {
			break;
		}
		else if (pass.find(' ') != string::npos) {
			cout << "Пароль не может содержать пробелы " << endl;
			system("pause");
		}
		else {
			cout << "Пароль должен содержать не менее 4 символов " << endl;
			system("pause");
		}
	}
	
	//Добавление записи в файл
	User regUser(login, pass);
	ofstream out;
	regUser.fileWrite(userPath);
	//////////////////////////
	cout << "Аккаунт успешно создан\n";
	system("pause");
}


void mainMenu() {
	
}