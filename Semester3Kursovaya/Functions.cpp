#include "Functions.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


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
	string login, pass;
	while (login.empty()) {
		system("cls");
		cout << "������� �����: ";
		getline(cin, login);
	}
	cout << "\n������� ������  " << endl;
	while (pass.size() < 4) {
		cout << "������ ������ ��������� �� ����� 4 ��������: ";
		getline(cin, pass);
	}
	//���������� ������ � ����

	//////////////////////////
	cout << "������� ������� ������\n";
	system("pause");
}


void mainMenu() {
	
}