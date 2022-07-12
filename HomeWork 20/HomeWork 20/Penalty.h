#pragma once

class Penalty
{
	int _id;
	string _text;
	string _date;
	float _price;
public:
	Penalty(int id, string text, string date, float price) :_id(id), _text(text), _date(date), _price(price) {}

	int getId() { 
		return _id; 
	}

	string gettext() { 
		return _text; 
	}

	string getDateTime() { 
		return _date; 
	}

	double getPrice() { 
		return _price; 
	}

	void print() {
		cout << "ID: " << _id << endl;
		cout << "Text: " << _text << endl;
		cout << "Date: " << _date << endl;
		cout << "Price: " << _price << endl;
	}
};
