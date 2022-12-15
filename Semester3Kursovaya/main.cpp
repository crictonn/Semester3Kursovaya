#include "User.h"
#include "Functions.h"
#include <Windows.h>
#include <time.h>

using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	createStaticAdmin();
	prevMenu();
}