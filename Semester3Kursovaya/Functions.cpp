#include "Functions.h"
#include "User.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

string userPath = "Users.txt", orderPath = "Orders.txt";

void prevMenu() {
	while (true) {
		system("cls");
		cout << "1. Вход в аккаунт\n"
			"2. Регистрация\n"
			"3. Выход" << endl;
		switch (_getch()) {
		case '1': cout << "Case 2 worked" << endl; break;
		case '2': registration(); break;
		case '3': return;
		default: 
			system("cls");
			cout << "Неверный ввод! " << endl;
			system("pause");
			break;
		}
	
		
	}
}


void registration() {
	string login = "", pass;
	while (login.empty()) {
		while (true) {
			system("cls");
			cout << "Введите логин: ";
			getline(cin, login);
			if (login.find(' ') != string::npos) {
				cout << "Логин не может содержать пробелы " << endl;
				system("pause");
			}
			else {
				break;
			}
		}
	}
	while (true) {
		system("cls");
		cout << "Введите логин: " << login << endl;;
		cout << "\nВведите пароль:  " << endl;
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
	/*cout << "\nВведите пароль  " << endl;
	while (pass.size() < 4) {
		cout << "Пароль должен содержать не менее 4 символов: ";
		getline(cin, pass);
	}*/
	//Добавление записи в файл
	User regUser(login, pass);
	ofstream out;
	regUser.fileWrite(userPath);
	//////////////////////////
	cout << "Аккаунт успешно создан\n";
	regUser.getFromFile(userPath);
	system("pause");
}


void mainMenu() {
	
}