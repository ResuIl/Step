#include <iostream>
#include <vector>
#include <windows.h>
#include<string>
using namespace std;

class Exception :public exception {
protected:
	string _message;
	int _line;
	const char* _source;
	const char* _time;
public:
	Exception(const char* message = "Exception",
		const char* source = "",
		const char* time = "",
		int line = 0) noexcept
		: exception(message)
	{
		_source = source;
		_time = time;
		_line = line;

		_message = "Message: " + (string)exception::what() + "\nSource: " + _source + "\nTime: " + _time + "\nLine: " + to_string(line);
	}

	int line() const { return _line; }
	const char* source() const { return _source; }
	const char* time() const { return _time; }
	const char* message() const { return exception::what(); }

	const char* what() const override
	{
		return _message.c_str();;
	}

};

class DatabaseException : public Exception {
public:
	DatabaseException()
	{
		throw Exception("DatabaseException", __FILE__, __FILE__, __LINE__);
	}
};

class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException()
	{
		throw Exception("InvalidArgumentException", __FILE__, __FILE__, __LINE__);
	}
};

class User {
	int _id;
	string _username;
	string _password;
	string _name;
	string _surname;

public:

	User() = default;

	User(int id, string username, string password, string name, string surname) {
		_id = id;
		_username = username;
		_password = password;
		_name = name;
		_surname = surname;
	}

	string getName() {
		return _name;
	}

	string getSurname() {
		return _surname;
	}

	string getUsername() {
		return _username;
	}

	string getPassword() {
		return _password;
	}

	int getId() {
		return _id;
	}

	void show() const {
		cout << "ID: " << _id << endl;
		cout << "Username: " << _username << endl;
		cout << "Password: " << _password << endl;
		cout << "Name: " << _name << endl;
		cout << "Surname: " << _surname << endl;
	};
};

class Database {
	vector<User>users;
public:
	void addUser(const User& user)
	{
		users.push_back(user);
	}

	User& getUserByUsername(string username)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			if (users[i].getUsername() == username)
				return users[i];
		}
	}

	void hashUserDataById(const int& id)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			if (users[i].getId() == id)
			{
				users[i].getPassword() = stoi(users[i].getPassword()) ^ 15;
				return;
			}
		}
		throw exception("User Not Found!");
	}

	int getSize()
	{
		return users.size();
	}

	User* getUsers()
	{
		return users.data();
	}
};



class Registration {
	Database _database;
public:
	Registration(const Database& database) {
		_database = database;
	}

	Database getDatabase() { return _database; }

	bool signIn(string username, string password)
	{
		for (size_t i = 0; i < _database.getSize(); i++)
		{
			if (_database.getUsers()[i].getUsername() == username && _database.getUsers()[i].getPassword() == password)
				return true;

		}
		throw exception("Incorrect informations");
	}

	void signUp(User user) {

		if (user.getUsername().length() < 6 || (user.getUsername()[0] >= 97 && user.getUsername()[0] <= 122) || user.getPassword().length() < 6 ||
			user.getName().length() < 3 || user.getSurname().length() < 4)
			throw InvalidArgumentException();
		for (size_t i = 0; i < _database.getSize(); i++)
		{
			if (_database.getUsers()[i].getUsername() == user.getUsername())
				throw DatabaseException();
		}
		_database.addUser(user);
	}
};


class StartUp {
public:
	static void Start() {
		Database db;
		Registration twitter(db);

		User user1(1, "Resulssss", "Resul123", "Resul", "Black");
		User user2(2, "Markssss", "Mark123", "Mark", "Adam");

		try
		{
			twitter.signUp(user1);
			twitter.signUp(user2);
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}
};



void main() {
	StartUp::Start();
	
	string test = "Salam";
	cout << islower(test[0]) << endl;

	system("pause");
}