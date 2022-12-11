#include "User.h"
User::User() {
	User::login = User::password = "admin";
	User::adminCoeff = 1;
}

User::~User() {
	delete& login, & password, & adminCoeff;
}