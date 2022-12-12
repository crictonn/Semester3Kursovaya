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
		cout << "1. ���� � �������\n"
			"2. �����������\n"
			"3. �����" << endl;
		switch (_getch()) {

		case '1': loggingIn(); break;

		case '2': registration(); break;

		case '3': return;
		/*default: 
			system("cls");
			cout << "�������� ����! " << endl;
			system("pause");
			break;*/
		}
	
		
	}
}


void loggingIn() {
	string inLog, inPass;
	User outUser("None", "None");
	system("cls");
	cout << "������� ��� �����: ";
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
			cout << "���������� �����: ";
			getline(cin, login);
			if (login.find(' ') != string::npos) {
				cout << "����� �� ����� ��������� ������� " << endl;
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
						cout << "����� ����� ��� ����������\n";
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
		cout << "���������� �����: " << login << endl;;
		cout << "\n���������� ������:  ";
		getline(cin, pass);
		if (pass.find(' ') == string::npos && pass.size() >= 4) {
			break;
		}
		else if (pass.find(' ') != string::npos) {
			cout << "������ �� ����� ��������� ������� " << endl;
			system("pause");
		}
		else {
			cout << "������ ������ ��������� �� ����� 4 �������� " << endl;
			system("pause");
		}
	}
	
	//���������� ������ � ����
	User regUser(login, pass);
	ofstream out;
	regUser.fileWrite(userPath);
	//////////////////////////
	cout << "������� ������� ������\n";
	system("pause");
}


void mainMenu() {
	
}