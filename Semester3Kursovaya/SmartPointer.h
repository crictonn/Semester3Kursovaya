#pragma once
#include <iostream>

enum State{begin, middle};
template <class T>
class SmartPointer {
	T* currentState;
	T* prevState;
public:
	SmartPointer() :prevState(NULL), currentState(new T){}
	SmartPointer(const SmartPointer& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}
	~SmartPointer() {}
	SmartPointer& operator=(const SmartPointer& obj);
		void showState(State state);
		int beginTransactions(int accountNumber);
		void commit();
	void deleteTransactions(); 
	T* operator->();
};
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>&
	obj) {
	if (this != &obj) {
		delete currentState;
		currentState = new T(*(obj.currentState));
	}
	return *this;
}
template <class T>
T* SmartPointer<T>::operator->() {
	return currentState;
}
template <class T>
void SmartPointer<T>::showState(State state) {
		cout << "Состояние объекта ";
	if (!state) cout << "до начала транзакции " << endl;
	else cout << "после выполнения транзакции " << endl;
	if (prevState) cout << "prevState = " << prevState -
> getNumber() << endl;
	else cout << "prevState = NULL" << endl;
	cout << "currentState = " << currentState->getNumber() << endl;
}
template <class T>
int SmartPointer<T>::beginTransactions(int accountNumber) {
		delete prevState;
	prevState = currentState;
		currentState = new T(*prevState);
		if (!currentState) return 0;
	currentState->setNumber(accountNumber);
		return 1;
}
template <class T>
void SmartPointer<T>::commit() {
	delete prevState;
	prevState = NULL;
}
template <class T>
void SmartPointer<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;
		currentState = prevState;
		prevState = NULL;
	}
}