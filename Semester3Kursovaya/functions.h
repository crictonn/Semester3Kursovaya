#pragma once
#include <string>

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
//void changeOrder(string ordNumber); // ��������� ������ � ������

//void userMaintaining(); // ���� ���������� ��������������, ��������, ��������, ����� ������
//void deleteUser();
//void giveAdminRights(); 