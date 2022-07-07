#include<iostream>
#include <vector>
using namespace std;

// Header Fayllarina Bole Bilerdim Sizin Template Bele idi deye el vurmadim Xahis Edirem Bal kesmeyin yada issues yerine yazin duzeldim :D

// Kod Chox Uzanmasin Deye Bezi Yerlere Admin girisi uchun yoxlanma yazmadim.

namespace ECommerce {
	namespace Database {

		class Guest {
			
		public:
			string fullname;
			string connected_date;
			Guest(string name, string date) 
				:fullname(name), connected_date(date) {}

			string getName()const { return fullname; }
			string getDate()const { return connected_date; }

			void print() {
				cout << "FullName: " << fullname << endl;
				cout << "Connected Date: " << connected_date << endl;
			}
		};

		class Admin {
			string username;
			string password;
		public:
			Admin(string username, string password)
				:username(username), password(password) {}

			string getUsername()const { return username; }
			string getPassword()const { return password; }

			void print() {
				cout << "Username: " << username << endl;
				cout << "Password: " << password << endl;
			}
		};

		class Product {
			static int staticId;
			int _id; //avtomatik
			string _name;
			string _description;
			double _price;
			double _discount;
			double _tax; //vergi faizi
		public:
			Product(string name,string description, double price, double discount, double tax)
				:_id(staticId++), _name(name), _description(description), _price(price), _discount(discount), _tax(tax) {}

			int getId()const { return _id; }
			string getName()const { return _name; }
			string getDescription()const { return _description; }
			double getPrice()const { return _price; }
			double getDiscount()const { return _discount; }
			double getTax()const { return _tax; }

			void print() {
				cout << "ID: " << _id << endl;
				cout << "Name: " << _name << endl;
				cout << "Description: " << _description << endl;
				cout << "Price: " << _price << endl;
				cout << "Discount: " << _discount << endl;
				cout << "Tax: " << _tax << endl;
			}
		};

		class Databasee {
		public:
			vector<Product>products;
			vector<Admin>admins;
			vector<Guest>guest;

		};
		int Product::staticId = 1;
	}

	void start() {
		using namespace Database;
		Databasee database;
		database.admins.push_back(Admin("Resul", "resul123"));

		Product p("Cola", "Cool Cola", 10, 0, 0);
		database.products.push_back(p);
		cout << "Welcome E-Commerce Program" << endl;
		int op;
		while (true) {
			cout << "1) Customer\n2) Products\n3) Admin Login" << endl;
			cin >> op;
			if (op == 1) {
				int opCustomer;
				do {
					cout << "0) Back\n1) Show Customers\n2) Add Customer" << endl;
					cin >> opCustomer;
					if (opCustomer == 1) {
						int len = database.guest.size();
						cout << "=====================" << endl;
						for (int i = 0; i < len; i++) {
							database.guest[i].print();
						}
						cout << "=====================" << endl;
					}
					else if (opCustomer == 2) {
						string fullName, connectDate;
						cout << "Enter FullName, ConnectedDate: ";
						cin >> fullName >> connectDate;
						Guest guest(fullName, connectDate);
						database.guest.push_back(guest);
						cout << "Customer Successfully Added!" << endl;
					}		
				} while (opCustomer != 0);
			}
			else if (op == 2) {
				int opProducts;
				do {
					cout << "0) Back\n1) Show Products\n2) Add Product" << endl;
					cin >> opProducts;
					if (opProducts == 1) {
						int len = database.products.size();
						cout << "= Total: "<< len << " Products =" << endl;
						for (int i = 0; i < len; i++) {
							database.products[i].print();
						}
						cout << "=====================" << endl;
					}
					else if (opProducts == 2) {
						string name, description;
						double price, discount, tax;
						cout << "Enter Name, Description: ";
						cin >> name >> description;
						cout << "Enter Price, Discount, Tax: ";
						cin >> price >> discount >> tax;
						Product product(name, description, price, discount, tax);
						database.products.push_back(product);
						cout << "Product Successfully Added!" << endl;
					}
				} while (opProducts != 0);
			}
			else if (op == 3) {
				int opProducts;
				do {
					cout << "0) Back\n1) Show Admins\n2) Add Admin" << endl;
					cin >> opProducts;
					if (opProducts == 1) {
						int len = database.products.size();
						cout << "=====================" << endl;
						for (int i = 0; i < len; i++) {
							database.admins[i].print();
						}
						cout << "=====================" << endl;
					}
					else if (opProducts == 2) {
						string username, password;
						cout << "Enter Username, Password: ";
						cin >> username >> password;
						Admin admin(username, password);
						database.admins.push_back(admin);
						cout << "Admin Successfully Added!" << endl;
					}
				} while (opProducts != 0);
			}
			else if (op == 0) {
				exit(0);
			}
			else {
				cout << "1) Customer\n2) Products\n3) Admin Login" << endl;
			}
		}
	}
}

void main() {
	ECommerce::start();
}
