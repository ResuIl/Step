#include<iostream>
#include <vector>
using namespace std;

///// ELAVE
class Notification {
	bool isRead; //oxunub ya yox
	//Guest guest;
	string text;
	//datetime;
};


namespace ECommerce {
	namespace Database {

		class Guest {
			string fullname;
			string connected_date;
		private:
			Guest(string name, string date) :fullname(name), connected_date(date) {}

			string getName()const { return fullname; }
			string getDate()const { return connected_date; }
		};

		class Admin {
			string username;
			string password;
		public:
			Admin(string username, string password)
				:username(username), password(password) {}

			string getUsername()const { return username; }
			string getPassword()const { return password; }
		};

		class Product {
			int _id; //avtomatik
			string _name;
			string _description;
			double _price;
			double _discount;
			double _tax; //vergi faizi
		public:
			Product(int id, string name,string description, double price, double discount, double tax)
				:_id(id), _name(name), _description(description), _price(price), _discount(discount), _tax(tax) {}

			int getId()const { return _id; }
			string getName()const { return _name; }
			string getDescription()const { return _description; }
			double getPrice()const { return _price; }
			double getDiscount()const { return _discount; }
			double getTax()const { return _tax; }
		};


		template<typename T>
		class DbSet {
			T** items;
		public:
			void add(const T* item) {

			};
			void deleteByid(const int& id);
			T* getItem(const int& id);
		};

		class Databasee {
		public:
			vector<Product>products;
			vector<Admin>admins;
			vector<Guest>guest;

		};

	}

	void start() {
		using namespace Database;
		Databasee database;
		database.guest.push_back();
	}
}

void main() {
	ECommerce::start();
}