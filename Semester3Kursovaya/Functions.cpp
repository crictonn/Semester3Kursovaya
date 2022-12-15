#include "Functions.h"
#include "User.h"
#include "Product.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <random>
#include "Order.h"


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
		cout << product.name << " " << product.brand << " " << product.price << "������ " << product.inStock << " �� ������" << endl;
		products.clear();
	}
	system("pause");
};

void placeOrder() {
	system("cls");
	srand(time(NULL));

	ifstream in(productsPath);
	string buff, selection, ordNumber = "";
	vector<string> products, orderable;
	vector<Product> vectProd;
	const char delim = ';';
	bool existance = false;
	cout << "�������� ���� ����� �� ��������: " << endl;
	int l = 0;
	while (getline(in, buff)) {
		size_t start, end = 0;
		while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = buff.find(delim, start);
			products.push_back(buff.substr(start, end - start));
		}
		cout << products[4*l] << endl;
		l++;
	}
	int productAmount = 0;
	getline(cin, selection);
	for (int i = 0; i < 5; i++) {
		ordNumber += char(rand() % 26 + 0x61);
		ordNumber += to_string(rand() % 10);
	}
	for (int i = 0; i < l; i++) {
		if (selection == products[i * 4]) {
			Product prd(products[i*4], products[i*4+1], atof(products[i*4+2].c_str()), atoi(products[i*4+3].c_str()));
			vectProd.push_back(prd);
			existance = true;
			productAmount++;
			//orderable.push_back(products[i * 4 + 1]);
		}
	}
	if (productAmount == 0) {
		cout << "������ ������ ��� � �������� " << endl;
		system("pause");
	}
	else if (productAmount == 1) {
		//Product pr(selection, products[1], atoi(products[2].c_str()), atoi(products[3].c_str()));
		cout << "������� ���� ���: " << endl;
		string fio;
		getline(cin, fio);
		cout << "������� ��� ����� ��������: " << endl;
		string phone;
		getline(cin, phone);
		Order order(ordNumber, "�� ���������", fio, phone, vectProd[0]);
		order.fileWriteOrder(orderPath);
		cout << "����� ��������!" << endl;
		system("pause");
	}
	else {
		string br;
		cout << "�������� �����: \n";
		for (int i = 0; i < productAmount; i++) {
			cout << /*orderable[i]*/vectProd[i].brand << endl;
		}
		getline(cin, br);
		for (int i = 0; i < productAmount; i++) {
			if (br == /*orderable[i]*/vectProd[i].brand) {
				//Product pr(selection, br, atoi(products[i*2+4].c_str()), atoi(products[i*3+4].c_str()));
				cout << "������� ���� ���: " << endl;
				string fio;
				getline(cin, fio);
				cout << "������� ��� ����� ��������: " << endl;
				string phone;
				getline(cin, phone);
				Order order(ordNumber, "�� ���������", fio, phone, vectProd[i]);
				order.fileWriteOrder(orderPath);
				cout << "����� ��������!" << endl;
				system("pause");
			}
		}
	}
};

void viewOrder() {
	system("cls");
	const char delim = ';';

	ifstream in(orderPath);
	vector <string> ords;
	string buff;
	while (true) {
		cout <<
			"1. ����� ���� �������\n"
			"2. ����� ������ �� ��� ������" << endl;
		switch (_getch())
		{
		case '1': 
			system("cls");

			while (getline(in, buff)) {
				size_t start, end = 0;
				while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
				{
					end = buff.find(delim, start);
					ords.push_back(buff.substr(start, end - start));
				}
				cout << ords[0] << " " << ords[1] << " " << ords[2] << " " << ords[3] << " " << ords[4] << " " << ords[5] << " " << ords[6] << " " << ords[7] << endl;
				ords.clear();
			}
			system("pause");
			return; break;
		case '2': 
			system("cls");
			cout << "������� ����� ������: ";
			string ordNumb;
			getline(cin, ordNumb);

			while (getline(in, buff)) {
				size_t start, end = 0;
				while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
				{
					end = buff.find(delim, start);
					ords.push_back(buff.substr(start, end - start));
				}
				if (ordNumb == ords[0]) {
					cout << ords[0] << " " << ords[1] << " " << ords[2] << " " << ords[3] << " " << ords[4] << " " << ords[5] << " " << ords[6] << " " << ords[7] << endl;
					break;
				}
				ords.clear();
			}
			system("pause");
			return; break;
		}
		
	}
}

void orderDelete() {
	system("cls");

	const char delim = ';';

	ifstream in(orderPath);
	vector <string> ords;
	vector <Order> ordVect;
	string buff, check, ordNumber;
	cout << "������� ����� ������ ��� ��������: ";
	getline(cin, ordNumber);
	while (getline(in, buff)) {
		int ck = 0, k = 0;
		size_t start, end = 0;
		while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = buff.find(delim, start);
			check = buff.substr(start, end - start);
			if (ordNumber != check) {
				ords.push_back(buff.substr(start, end - start));
				ck = 1;
			}
			else break;
		}
		if (ck == 1) {
			Order order(ords[k],ords[k+1], ords[k + 2], ords[k + 3], atoi(ords[k + 4].c_str()), atoi(ords[k + 5].c_str()), ords[k + 6], ords[k + 7]);
			ordVect.push_back(order);
			k++;
		}
		ords.clear();
	}
	in.close();
	ofstream out;
	out.open(orderPath, ios::trunc);
	for (int i = 0; i < ordVect.size(); i++) {
		ordVect[i].fileWriteOrder(orderPath);
	}
	cout << "�������� �������" << endl;
	system("pause");
}

bool isNumeric(std::string const& str)
{
	return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

void changeOrder() {

	const char delim = ';';

	ifstream in(orderPath);
	vector <string> ords;
	vector <Order> ordVect;
	string buff, check, ordNumber;
	char choice = ' ';
	while (true) {
		system("cls");
		cout << "������� ����� ������ ��� ���������: ";
		getline(cin, ordNumber);
		cout << "�������� �������� ��� ���������: \n"
			"1. ������������\n"
			"2. �����\n"
			"3. ������\n"
			"4. ��� ���������\n"
			"5. ������� ���������\n"
			"6. ���������� � �������\n"
			"7. ������" << endl;
		switch (_getch())
		{
		case '1': choice = '1'; break;
		case '2': choice = '2'; break;
		case '3': choice = '3'; break;
		case '4': choice = '4'; break;
		case '5': choice = '5'; break;
		case '6': choice = '6'; break;
		case '7': return; break;
		}
		if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6')
			break;
	}
	cout << "������� ����� ��������: ";
	string newline;
	if (choice == '6') {
		while (!isNumeric) {
			getline(cin, newline);
		}
	}
	else
		getline(cin, newline);
	while (getline(in, buff)) {
		int ck = 0, k = 0;
		size_t start, end = 0;
		while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = buff.find(delim, start);
			check = buff.substr(start, end - start);
			if (ordNumber == check) {
				ck = 1;
			}
			ords.push_back(buff.substr(start, end - start));
		}
		if (ck == 0) {
			Order order(ords[k], ords[k + 1], ords[k + 2], ords[k + 3], atoi(ords[k + 4].c_str()), atoi(ords[k + 5].c_str()), ords[k + 6], ords[k + 7]);
			ordVect.push_back(order);
			k++;
		}
		else
		{
			switch (choice) {
			case '1': {
				Order order(ords[k], newline, ords[k + 2], ords[k + 3], atof(ords[k + 4].c_str()), atoi(ords[k + 5].c_str()), ords[k + 6], ords[k + 7]);
				ordVect.push_back(order);
				k++;
				break;
			}
			case '2': {
				Order order(ords[k], ords[k + 1], newline, ords[k + 3], atof(ords[k + 4].c_str()), atoi(ords[k + 5].c_str()), ords[k + 6], ords[k + 7]);
				ordVect.push_back(order);
				k++;
				break;
			}
			case '3': {
				Order order(ords[k], ords[k + 1], ords[k + 2], newline, atof(ords[k + 4].c_str()), atoi(ords[k + 5].c_str()), ords[k + 6], ords[k + 7]);
				ordVect.push_back(order);
				k++;
				break;
			}
			case '4': {
				Order order(ords[k], ords[k + 1], ords[k + 2], ords[k + 3], atof(ords[k + 4].c_str()), atoi(ords[k + 5].c_str()), newline, ords[k + 7]);
				ordVect.push_back(order);
				k++;
				break;
			}
			case '5': {
				Order order(ords[k], ords[k + 1], ords[k + 2], ords[k + 3], atof(ords[k + 4].c_str()), atoi(ords[k + 5].c_str()), ords[k + 6], newline);
				ordVect.push_back(order);
				k++;
				break;
			}
			case '6': {
				Order order(ords[k], ords[k + 1], ords[k + 2], ords[k + 3], atof(ords[k + 4].c_str()), atoi(newline.c_str()), ords[k + 6], ords[k + 7]);
				ordVect.push_back(order);
				k++;
				break;
			}

			}
		}
		ords.clear();
	}
	in.close();
	ofstream out(orderPath, ios::trunc);
	out.close();
	for (int i = 0; i < ordVect.size(); i++) {
		ordVect[i].fileWriteOrder(orderPath);
	}
	cout << "��������� �������" << endl;
	system("pause");
}

void listUsers() {
	system("cls");
	ifstream in(userPath);
	const char delim = ';';
	string buff;
	vector<string> users;
	while (getline(in, buff)) {
		size_t start, end = 0;
		while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = buff.find(delim, start);
			users.push_back(buff.substr(start, end - start));
		}
		User us(users[0], users[1], atoi(users[2].c_str()));
		us.printData();
		users.clear();
	}
	system("pause");
}

void deleteUser(string deleteLogin) {
	ifstream in(userPath);
	const char delim = ';';
	string buff;
	vector<string> users;
	vector<User> addUserVect;
	while (getline(in, buff)) {
		size_t start, end = 0;
		while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = buff.find(delim, start);
			users.push_back(buff.substr(start, end - start));
		}
		if (users[0] != deleteLogin) {
			User us(users[0], users[1], atoi(users[2].c_str()));
			addUserVect.push_back(us);
		}
		users.clear();
	}
	in.close();
	ofstream out;
	out.open(userPath, ios::trunc);
	for (int i = 0; i < addUserVect.size(); i++)
		addUserVect[i].fileWrite(userPath);
};

void giveAdminRights(string changeLogin) {
	ifstream in(userPath);
	const char delim = ';';
	string buff;
	vector<string> users;
	vector<User> addUserVect;
	while (getline(in, buff)) {
		size_t start, end = 0;
		while ((start = buff.find_first_not_of(delim, end)) != std::string::npos)
		{
			end = buff.find(delim, start);
			users.push_back(buff.substr(start, end - start));
		}
		if (users[0] == changeLogin) {
			User us(users[0], users[1], 1);
			addUserVect.push_back(us);
		}
		if (users[0] == changeLogin)
			break;
		users.clear();
	}
	in.close();
	deleteUser(changeLogin);
	addUserVect[0].fileWrite(userPath);
};

void userMaintaining() {
	
	while (true) {
		system("cls");
		cout <<
			"1. ����������� ���� �������������\n"
			"2. ������� ������������\n"
			"3. ������� ������������ ���������������\n"
			"4. ������" << endl;
		switch (_getch()) {
		case '1': listUsers(); break;
		case '2': {
			string deleteLogin;
			while (deleteLogin.empty()) {
				system("cls");
				cout << "������� ����� ��� ��������: ";
				getline(cin, deleteLogin);
			}
			deleteUser(deleteLogin);
			cout << "������������ ������� ������" << endl;
			system("pause"); 
			break;
		}

		case '3': {
			string upgradeLogin;
			while (upgradeLogin.empty()) {
				system("cls");
				cout << "������� ����� ������������ ��� ��������� �������: ";
				getline(cin, upgradeLogin);	
			}
			giveAdminRights(upgradeLogin);
			cout << "����� ������� ������" << endl;
			system("pause");
			break;
		}
		case '4': return; break;
		}
	}
}

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
		case '2': placeOrder(); break;
		case '3': viewOrder(); break;
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
		case '3': placeOrder(); break;
		case '4': viewOrder(); break;
		case '5': changeOrder(); break;
		case '6': orderDelete(); break;
		case '7': userMaintaining(); break;
		case '8': return; break;
		}
	}
}