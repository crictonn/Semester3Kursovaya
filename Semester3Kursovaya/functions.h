#pragma once
#include <string>

using namespace std;

void createStaticAdmin(); // Создание администратора admin с паролем admin
void loggingIn(); // Вход в аккаунт
void registration(); // Регистрация нового пользователя

void prevMenu(); // Основное меню
void userMenu(); // Меню пользователя
void adminMenu(); // Меню админимтартора

void addToCatalog(); // Функция должна добавлять объект класса Product в файл
void printCatalog(); // Вывод каталога из файла

void placeOrder(); // Сформировать заказ на основе одного из объектов класса Product, записанных в файл
void viewOrder(); // Функция должна вызывать свич с двумя вариантами: вывод всех заказов и вывод заказа по номеру
void orderDelete(); // Удаление заказа
void changeOrder(); // Изменение данных о заказе
void sortOrders(); // Сортировка заказов

void userMaintaining(); // Меню управления пользователями, создание, удаление, права админа
void listUsers(); // Вывод всех пользователей
void deleteUser(string deleteLogin); // Удаление заданного пользователя
void giveAdminRights(string changeLogin); // Наделение правами пользователя