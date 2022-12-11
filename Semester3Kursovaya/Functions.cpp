#include "Functions.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


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
	string login, pass;
	while (login.empty()) {
		system("cls");
		cout << "Введите логин: ";
		getline(cin, login);
	}
	cout << "\nВведите пароль  " << endl;
	while (pass.size() < 4) {
		cout << "Пароль должен содержать не менее 4 символов: ";
		getline(cin, pass);
	}
	//Добавление записи в файл

	//////////////////////////
	cout << "Аккаунт успешно создан\n";
	system("pause");
}


void mainMenu() {
	
}