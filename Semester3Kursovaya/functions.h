#pragma once
#include <string>

using namespace std;

void createStaticAdmin();
void loggingIn();
void registration();

void prevMenu();
void userMenu();
void adminMenu();

void addToCatalog(); // Функция должна добавлять объект класса Product в файл
void printCatalog(); // Вывод каталога из файла

void placeOrder(); // Сформировать заказ на основе одного из объектов класса Product, записанных в файл
void viewOrder(); // Функция должна вызывать свич с двумя вариантами: вывод всех заказов и вывод заказа по номеру
void orderDelete();
void changeOrder(string ordNumber); // Изменение данных о заказе

void userMaintaining(); // Меню управления пользователями, создание, удаление, права админа
void listUsers();
void deleteUser();
void giveAdminRights(); 