#pragma once

void createStaticAdmin();
void loggingIn();
void registration();

void prevMenu();
void userMenu();
void adminMenu();

void addToCatalog(); // ������� ������ ��������� ������ ������ Product � ����
void printCatalog(); // ����� �������� �� �����

void placeOrder(); // ������������ ����� �� ������ ������ �� �������� ������ Product, ���������� � ����
void fileWriteOrder();
void viewOrder(); // ������� ������ �������� ���� � ����� ����������: ����� ���� ������� � ����� ������ �� ������
void changeOrder(); // ��������� ������ � ������
void deleteOrder(); // ��� ��� �������

void userMaintaining(); // ���� ���������� ��������������, ��������, ��������, ����� ������
void deleteUser();
void giveAdminRights(); 