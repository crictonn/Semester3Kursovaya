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
		cout << product.name << " " << product.brand << " " << product.price << "рублей " << product.inStock << " на складе" << endl;
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
	cout << "Выберите один товар из каталога: " << endl;
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
		cout << "Такого товара нет в каталоге " << endl;
		system("pause");
	}
	else if (productAmount == 1) {
		//Product pr(selection, products[1], atoi(products[2].c_str()), atoi(products[3].c_str()));
		cout << "Введите ваши ФИО: " << endl;
		string fio;
		getline(cin, fio);
		cout << "Введите ваш номер телефона: " << endl;
		string phone;
		getline(cin, phone);
		Order order(ordNumber, "На обработке", fio, phone, vectProd[0]);
		order.fileWriteOrder(orderPath);
		cout << "Заказ оформлен!" << endl;
		system("pause");
	}
	else {
		string br;
		cout << "Выберите бренд: \n";
		for (int i = 0; i < productAmount; i++) {
			cout << /*orderable[i]*/vectProd[i].brand << endl;
		}
		getline(cin, br);
		for (int i = 0; i < productAmount; i++) {
			if (br == /*orderable[i]*/vectProd[i].brand) {
				//Product pr(selection, br, atoi(products[i*2+4].c_str()), atoi(products[i*3+4].c_str()));
				cout << "Введите ваши ФИО: " << endl;
				string fio;
				getline(cin, fio);
				cout << "Введите ваш номер телефона: " << endl;
				string phone;
				getline(cin, phone);
				Order order(ordNumber, "На обработке", fio, phone, vectProd[i]);
				order.fileWriteOrder(orderPath);
				cout << "Заказ оформлен!" << endl;
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
			"1. Вывод всех заказов\n"
			"2. Вывод заказа по его номеру" << endl;
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
			cout << "Введите номер заказа: ";
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
	cout << "Введите номер заказа для удаления: ";
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
	cout << "Удаление успешно" << endl;
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
		cout << "Введите номер заказа для изменения: ";
		getline(cin, ordNumber);
		cout << "Выберите параметр для изменения: \n"
			"1. Наименование\n"
			"2. Бренд\n"
			"3. Статус\n"
			"4. ФИО заказчика\n"
			"5. Телефон заказчика\n"
			"6. Количество в наличии\n"
			"7. Отмена" << endl;
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
	cout << "Введите новое значение: ";
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
	cout << "Изменение успешно" << endl;
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
			"1. Просмотреть всех пользователей\n"
			"2. Удалить пользователя\n"
			"3. Сделать пользователя администратором\n"
			"4. Отмена" << endl;
		switch (_getch()) {
		case '1': listUsers(); break;
		case '2': {
			string deleteLogin;
			while (deleteLogin.empty()) {
				system("cls");
				cout << "Введите логин для удаления: ";
				getline(cin, deleteLogin);
			}
			deleteUser(deleteLogin);
			cout << "Пользователь успешно удален" << endl;
			system("pause"); 
			break;
		}

		case '3': {
			string upgradeLogin;
			while (upgradeLogin.empty()) {
				system("cls");
				cout << "Введите логин пользователя для наделения правами: ";
				getline(cin, upgradeLogin);	
			}
			giveAdminRights(upgradeLogin);
			cout << "Права успешно выданы" << endl;
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
		cout << "Меню\n"
			"1. Просмотреть каталог товаров\n"
			"2. Сформировать заказ\n"
			"3. Просмотреть информацию о заказе\n"
			"4. Выход" << endl;
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
		case '3': placeOrder(); break;
		case '4': viewOrder(); break;
		case '5': changeOrder(); break;
		case '6': orderDelete(); break;
		case '7': userMaintaining(); break;
		case '8': return; break;
		}
	}
}