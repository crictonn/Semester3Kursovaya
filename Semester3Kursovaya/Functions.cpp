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
	ifstream in(userPath, ios::app);

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
	regUser.fileWrite(userPath);
	//////////////////////////
	cout << "Аккаунт успешно создан\n";
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
	cout << "Введите название товара: ";
	while(name == "")
	getline(cin, name);
	cout << "Введите название бренда: ";
	while (brand == "")
		getline(cin, brand);
	do
	{
		
		try {
			system("cls");
			cout << "Введите название товара: " << name << endl;
			cout << "Введите название бренда: " << brand << endl;
			cout << "Введите цену товара: ";
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
		cout << "Введите название товара: " << name << endl;
		cout << "Введите название бренда: " << brand << endl;
		cout << "Введите цену товара: " << price << endl;
		cout << "Введите количество товара в наличии: ";
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
	cout << "Товар успешно добавлен в каталог" << endl;
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
		cout << "Меню\n"
			"1. Просмотреть каталог товаров\n"
			"2. Сформировать заказ\n"
			"3. Просмотреть информацию о заказе\n"
			"4. Выход" << endl;
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
		cout << "Меню Админитратора\n"
			"1. Просмотреть каталог товаров\n"
			"2. Добавить товар в каталог\n"
			"3. Сформировать заказ\n"
			"4. Просмотреть информацию о заказе\n"
			"5. Изменить данные о заказе\n"
			"6. Удалить заказ\n"
			"7. Меню работы с пользователями\n"
			"8. Выход" << endl;
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