#pragma once
#include "Bank.h"
#include "Exam.h"


class Student {
public:
	string _name = "";
	string _surname = "";
	string _speciality = "";
	int _score = 0;
	int _money = 0;
	BankCard _bankcard;
	Exam _exam;

	Student(string name, string surname, string speciality, int score, int money, BankCard bankcard, Exam exam)
		: _name(name), _surname(surname), _speciality(speciality), _score(score), _money(money), _bankcard(bankcard), _exam(exam) {};

	int showBalance() {
		return _bankcard.balance();
	}

	string getName() {
		return _name + _surname;
	}

	int getSalary() {
		return  _money;
	}

	void print() {
		cout << "Name: " << _name << endl;
		cout << "Surname: " << _surname << endl;
		cout << "Speciality: " << _speciality << endl;
		cout << "Score: " << _score << endl;
		cout << "Money: " << _money << endl;
	}
};