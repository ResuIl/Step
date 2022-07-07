#pragma once
#include "Group.h"

class Teacher {
private:
	string _name = "";
	string _surname = "";
	int _age = 0;
	Group _group;
	string _department = "";
	int _salary = 0;
	BankCard _bankcard;
public:

	Teacher(string name, string surname, int age, Group group, string department, int salary, BankCard bankcard)
		: _name(name), _surname(surname), _age(age), _group(group), _department(department), _salary(salary), _bankcard(bankcard) {};

	string getName() {
		return _name;
	}

	int getSalary() {
		return _salary;
	}
};