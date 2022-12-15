#pragma once
#include <string>

using namespace std;

void createStaticAdmin(); // �������� �������������� admin � ������� admin
void loggingIn(); // ���� � �������
void registration(); // ����������� ������ ������������

void prevMenu(); // �������� ����
void userMenu(); // ���� ������������
void adminMenu(); // ���� ��������������

void addToCatalog(); // ������� ������ ��������� ������ ������ Product � ����
void printCatalog(); // ����� �������� �� �����

void placeOrder(); // ������������ ����� �� ������ ������ �� �������� ������ Product, ���������� � ����
void viewOrder(); // ������� ������ �������� ���� � ����� ����������: ����� ���� ������� � ����� ������ �� ������
void orderDelete(); // �������� ������
void changeOrder(); // ��������� ������ � ������
void sortOrders(); // ���������� �������

void userMaintaining(); // ���� ���������� ��������������, ��������, ��������, ����� ������
void listUsers(); // ����� ���� �������������
void deleteUser(string deleteLogin); // �������� ��������� ������������
void giveAdminRights(string changeLogin); // ��������� ������� ������������