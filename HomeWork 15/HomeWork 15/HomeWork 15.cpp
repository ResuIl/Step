#include<iostream>
#include<vector>
using namespace std;

class Car
{
protected:
	int _id;
	string _vendor;
	string _model;
	string _color;
	float _power;
public:
	Car(int id, string vendor, string model, string color, float power) {
		_id = id;
		_vendor = vendor;
		_model = model;
		_color = color;
		_power = power;
	}

	virtual void print() {
		cout << _model << endl;
		cout << _vendor << endl;
		cout << _color << endl;
		cout << _power << endl;
	}
};

class Automatic final :public Car
{
private:
	int _maxSpeed;
public:
	Automatic(int id, string model, string vendor, string color, float power)
		:Car(id, model, vendor, color, power) {}

	int get_speed() { return _maxSpeed; }

	void print() override {
		cout << _model << endl;
		cout << _vendor << endl;
		cout << _color << endl;
		cout << _power << endl;
	}
};

class Manual final :public Car
{
private:
	int _transmisions;
public:
	Manual(int id, string model, string vendor, string color, float power)
		:Car(id, model, vendor, color, power) {}

	int getTransmissionCount() { return _transmisions; }

	void print() override {
		cout << _model << endl;
		cout << _vendor << endl;
		cout << _color << endl;
		cout << _power << endl;
	}
};

int main() {
	vector<Car>cars;

	

	cars.push_back(Automatic(2, "BMW", "M5", "red", 2.2));
	cars.push_back(Manual(1, "Toyota", "Camry", "Black", 4.4));


	for (size_t i = 0; i < cars.size(); i++)
	{
		cars[i].print();
	}

}