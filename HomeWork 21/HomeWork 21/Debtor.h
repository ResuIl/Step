#pragma once

class DateTime
{
public:
    int _day = 0;
    string _month = "";
    int _year = 0;
    DateTime() = default;
    DateTime(string month, int day, int year) : _day(day), _month(month), _year(year) {}
};

class Debtor
{
    string _fullname = "";
    DateTime _birthDay;
    string _phone = "";
    string _email = "";
    string _address = "";
    int _debt = 0;
public:
    Debtor() = default;
    Debtor(string fullname, DateTime birthDay, string phone, string email, string address, int debt)
        : _fullname(fullname), _birthDay(birthDay), _phone(phone), _email(email), _address(address), _debt(debt) {}

    string getFullName() {
        return _fullname;
    }

    DateTime getBirthday() {
        return _birthDay;
    }

    string getPhone() {
        return _phone;
    }

    string getEmail() {
        return _email;
    }

    string getAddress() {
        return _address;
    }

    int getDebt() {
        return _debt;
    }

    void print() {
        cout << "Name: " << _fullname << endl;
        cout << "Birthday: " << _birthDay._day << "." << _birthDay._month << "." << _birthDay._year << endl;
        cout << "Phone: " << _phone << endl;
        cout << "Email: " << _email << endl;
        cout << "Address: " << _address << endl;
        cout << "Debt: " << _debt << endl;
        cout << endl;
    }
};