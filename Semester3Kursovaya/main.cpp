/*
������� �����������
1) ���������� ����������������� ����, ����������� ��������� �����:
� ���������� �����, ����������� ������������, �������� ������ � ������������� ����;
� ��������, ����������, �������������� � �������� �������;
� �����, ���������� � ���������� �������;
� ���������� ������ (����� ������ � ���� ������);
� ������ ����� � ����������� �� ��������� ���������������� ������.
2) �������� �������� � �������� ���������� � ��������� ���/� �������� ������. ���
�������� ������ � ����������� ������ ������������ ���������� ���������� STL (Standard
Template Library).
3) ������������� � ��������� ��������� ����������� �����������:
�- ���������� ������� ��������� ��������-���������������� ����������������
- (����������, ������������, ������������, ������������);
�- ������������� ����������� �������;
�- ������������� �������� ���������� �� ������ � �� ��������;
�- ������������� ����������, ����������������, �������������, ����������� �������;
�- ������������� ����������� ���� (���������� � �����������);
�- ���������� ��������� ������ ��������� (���������� ����� �++);
�- ������������� ���������� ������� � ����������, ��������������� �������;
�- ������������� �������� ������� � �������;
�- ������������� ����������� ������� � �����.
�- ������������� ������������� ��������� ������ � ����� ���������� (smart pointers).
�- ������������� ������� �++, ���������� ���������� �����/������, ���������������
������ � �������.
*/
#include "User.h"
#include "Functions.h"
#include <Windows.h>

using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	createStaticAdmin();
	prevMenu();
	

	//User user;
	//user.makeAdmin();
	//user.printData();
	/*User user;
	getline(cin, user.login);
	cout << user.login;*/
}