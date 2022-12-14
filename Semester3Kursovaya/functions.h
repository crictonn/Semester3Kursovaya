#pragma once
#include <string>

using namespace std;

void createStaticAdmin();
void loggingIn();
void registration();

void prevMenu();
void userMenu();
void adminMenu();

void addToCatalog(); // ������� ������ ��������� ������ ������ Product � ����
void printCatalog(); // ����� �������� �� �����

void placeOrder(); // ������������ ����� �� ������ ������ �� �������� ������ Product, ���������� � ����
void viewOrder(); // ������� ������ �������� ���� � ����� ����������: ����� ���� ������� � ����� ������ �� ������
void orderDelete();
void changeOrder(string ordNumber); // ��������� ������ � ������

void userMaintaining(); // ���� ���������� ��������������, ��������, ��������, ����� ������
void listUsers();
void deleteUser();
void giveAdminRights(); 