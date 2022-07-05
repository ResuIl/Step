#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Applier {
public:

	string _name = "";
	int _age = 0;
	string  _speciality = "";
	string _text = "";

	Applier() = default;

	Applier(string name, int age, string speciality, string text) : _name(name), _age(age), _speciality(speciality), _text(text) {};

	string getName() {
		return _name;
	}

	int getAge() {
		return _age;
	}

	string getSpeciality() {
		return _speciality;
	}

	string getText() {
		return _text;
	}

	void print() {
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
		cout << "Speciality: " << _speciality << endl;
		cout << "Text: " << _text << endl;
	}
};


class Company {
	vector<Applier*> appliers;

public:
	void hireUp(Applier* cv) {
		appliers.push_back(cv);
		cout << "Applier Hired" << endl;
	};

	void showAllCV() {
		int len = appliers.size();
		for (int i = 0; i < len; i++) {
			appliers[i]->print();
		}
	};

	void writeToFile(string filename) {

		ofstream fout(filename, ios::out);

		if (!fout)
			throw new exception("File can not created");

		if (!fout.is_open()) {
			fout.close();
			throw new exception("File can not opened");
		}

		int len = appliers.size();
		for (int i = 0; i < len; i++) {
			fout << appliers[i]->getName() << " " << appliers[i]->getAge() << " " << appliers[i]->getSpeciality() << " " << appliers[i]->getText() << endl;
		}

		fout.close();

	};

	void readToFile(string filename) {
		ifstream fin(filename, ios::in);

		if (!fin)
			throw new exception("File can not find");

		if (!fin.is_open()) {
			fin.close();
			throw new exception("File can not opened");
		}

		string data;

		while (!fin.eof())
		{
			getline(fin, data);
			cout << data << endl;
		}
		fin.close();
	};
};

int main() {
	Applier* cv1 = new Applier("Ceyhun", 18, "IT", "Empty1");
	Applier* cv2 = new Applier("Sebine", 17, "Designer", "Empty2");


	Company company;
	try {
		company.hireUp(cv1);
		company.hireUp(cv2);

		//company.writeToFile("company.txt");
		cout << endl;
		company.readToFile("company.txt");
		//company.showAllCV();
	}
	catch (exception* ex) {
		cout << "Error Occured! Error: " << ex->what() << endl;
	}


}