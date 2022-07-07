#pragma once

class BankCard {
private:
	string _longCode = "";
	string _password = "";
	int _balance = 0;
	int _expiredMonth = 0;
	int _expiredYear = 0;
public:
	BankCard(string longCode, string password, int balance, int expiredMont, int expiredYear)
		: _longCode(longCode), _password(password), _balance(balance), _expiredMonth(expiredMont), _expiredYear(expiredYear) {};

	int balance() {
		return _balance;
	}
};

class Bank {
public:
	vector<BankCard> bankcards;


};