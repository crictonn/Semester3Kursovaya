#include "Functions.h"
#include "User.h"
#include "Product.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string userPath = "Users.txt", orderPath = "Orders.txt", productsPath = "Products.txt";

void createStaticAdmin() {
	ifstream in(userPath, ios::app);
	int check = 0;
	string line, adm;
	size_t start, end = 0;
	vector<string> admCheck;
	while (getline(in, line)) {
		while ((start = line.find_first_not_of(';', end)) != std::string::npos)
		{
			end = line.find(';', start);
			admCheck.push_back(line.substr(start, end - start));
		}
		adm = admCheck[0];
		if (adm == "admin") {
			check = 1;
			break;
		}
	}
	if (check != 1) {
		User admin("admin", "admin");
		admin.makeAdmin();
		admin.fileWrite(userPath);
	}
	
}

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
	ifstream in(userPath, ios::app);

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
	regUser.fileWrite(userPath);
	//////////////////////////
	cout << "������� ������� ������\n";
	system("pause");
}

ostream& operator << (ostream & out, const Product & p) {
	return out << p.name << ';' << p.brand << ';' << p.price << ';' << p.inStock << ';'<<'\n';
}

void floatException(float value) {
	if (value) throw 1;
	else throw "Error";
}


void addToCatalog() {
	system("cls");
	string name, brand;
	float price;
	int inStock;
	cout << "������� �������� ������: ";
	while(name == "")
	getline(cin, name);
	cout << "������� �������� ������: ";
	while (brand == "")
		getline(cin, brand);
	do
	{
		
		try {
			system("cls");
			cout << "������� �������� ������: " << name << endl;
			cout << "������� �������� ������: " << brand << endl;
			cout << "������� ���� ������: ";
			cin >> price;
			floatException(price);
		}
		catch (...) {
			cin.clear();
			cin.sync();
			cin.ignore();
		}
	} while (price<=0);

	do
	{
		system("cls");
		cout << "������� �������� ������: " << name << endl;
		cout << "������� �������� ������: " << brand << endl;
		cout << "������� ���� ������: " << price << endl;
		cout << "������� ���������� ������ � �������: ";
		cin >> inStock;
		if (!cin) {
			cin.clear();
			cin.sync();
			cin.ignore();
			inStock = -1;
		}
		
	} while (inStock<0);

	Product addProduct(name, brand, price, inStock);
	ofstream out(productsPath, ios::app);
	out << addProduct;
	cout << "����� ������� �������� � �������" << endl;
	system("pause");
};

void printCatalog() {
	system("cls");
	ifstream in(productsPath);
	vector <string> products;
	string buff;

	const char delim = ';';
	while (getline(in, buff)) {
		size_t start, end = 0;
		while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = buff.find(delim, start);
			products.push_back(buff.substr(start, end - start));
		}
		Product product(products[0],products[1], atof(products[2].c_str()), atoi(products[3].c_str()));
		cout << product;
		products.clear();
	}
	system("pause");
};

void userMenu() {
	while (true) {
		system("cls");
		cout << "����\n"
			"1. ����������� ������� �������\n"
			"2. ������������ �����\n"
			"3. ����������� ���������� � ������\n"
			"4. �����" << endl;
		switch (_getch())
		{
		case '1': printCatalog(); break;
		case '2': ; break;
		case '3': break;
		case '4': return; break;
		}
	}
}

void adminMenu() {
	while (true) {
		system("cls");
		cout << "���� �������������\n"
			"1. ����������� ������� �������\n"
			"2. �������� ����� � �������\n"
			"3. ������������ �����\n"
			"4. ����������� ���������� � ������\n"
			"5. �������� ������ � ������\n"
			"6. ������� �����\n"
			"7. ���� ������ � ��������������\n"
			"8. �����" << endl;
		switch (_getch())
		{
		case '1': printCatalog(); break;
		case '2': addToCatalog(); break;
		case '3': break;
		case '4': break;
		case '5': break;
		case '6': break;
		case '7': break;
		case '8': return; break;
		}
	}
}