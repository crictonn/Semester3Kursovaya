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
		cout << "1. ���� � �������\n"
			"2. �����������\n"
			"3. �����" << endl;
		switch (_getch()) {
		case '1': cout << "Case 2 worked" << endl; break;
		case '2': registration(); break;
		case '3': return;
		default: 
			system("cls");
			cout << "�������� ����! " << endl;
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
			cout << "������� �����: ";
			getline(cin, login);
			if (login.find(' ') != string::npos) {
				cout << "����� �� ����� ��������� ������� " << endl;
				system("pause");
			}
			else {
				break;
			}
		}
	}
	while (true) {
		system("cls");
		cout << "������� �����: " << login << endl;;
		cout << "\n������� ������:  " << endl;
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
	/*cout << "\n������� ������  " << endl;
	while (pass.size() < 4) {
		cout << "������ ������ ��������� �� ����� 4 ��������: ";
		getline(cin, pass);
	}*/
	//���������� ������ � ����
	User regUser(login, pass);
	ofstream out;
	regUser.fileWrite(userPath);
	//////////////////////////
	cout << "������� ������� ������\n";
	regUser.getFromFile(userPath);
	system("pause");
}


void mainMenu() {
	
}