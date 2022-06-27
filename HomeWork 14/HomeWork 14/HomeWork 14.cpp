#include <iostream>
#include <stack>
using namespace std;

class Engine {
public:
    int engineNo;
    string company;
    int volume;

    Engine() = default;

    Engine(int No, string comp, int vol) {
        this->engineNo = No;
        this->company = comp;
        this->volume = vol;
    }

    void print() {
        cout << "Engine NO: " << engineNo << endl;
        cout << "Company: " << company << endl;
        cout << "Volume: " << volume << endl;
    }
};

class Car : public Engine {
public:
    int _id;
    string _model;
    string _vendor;
    Engine _engine;
    bool _hasSpoiler;

    Car(int id, string model, string vendor, Engine engine, bool spoiler) : Engine(engine) {
        this->_id = id;
        this->_model = model;
        this->_vendor = vendor;
        this->_engine = engine;
        this->_hasSpoiler = spoiler;
    }

    void print() {
        cout << "Car" << endl;
        cout << "ID: " << _id << endl;
        cout << "Model: " << _model << endl;
        cout << "Vendor: " << _vendor << endl;
        Engine::print();
        cout << "Spoiler: " << _hasSpoiler << endl;
    }

};

class Ship : public Engine {
public:
    int _id;
    string _model;
    string _vendor;
    Engine _engine;
    bool _hasSail;

    Ship(int id, string model, string vendor, Engine engine, bool sail) : Engine(engine) {
        this->_id = id;
        this->_model = model;
        this->_vendor = vendor;
        this->_engine = engine;
        this->_hasSail = sail;
    }

    void print() {
        cout << "Ship" << endl;
        cout << "ID: " << _id << endl;
        cout << "Model: " << _model << endl;
        cout << "Vendor: " << _vendor << endl;
        Engine::print();
        cout << "Sail: " << _hasSail << endl;
    }

};

class Airplane : public Engine {
public:
    int _id;
    string _model;
    string _vendor;
    Engine _engine;
    int _engineCount;
    int _passengerCapacity;

    Airplane(int id, string model, string vendor, Engine engine, int engineCount, int passengerCapacity) : Engine(engine) {
        this->_id = id;
        this->_model = model;
        this->_vendor = vendor;
        this->_engine = engine;
        this->_engineCount = engineCount;
        this->_passengerCapacity = passengerCapacity;
    }

    void print() {
        cout << "Ship" << endl;
        cout << "ID: " << _id << endl;
        cout << "Model: " << _model << endl;
        cout << "Vendor: " << _vendor << endl;
        Engine::print();
        cout << "Engine Count: " << _engineCount << endl;
        cout << "Passenger Capacity: " << _passengerCapacity << endl;
    }

};

class Depo {
public:
    int engineNo;
    string company;
    int volume;

    Depo() = default;

    Depo(int No, string comp, int vol) {
        this->engineNo = No;
        this->company = comp;
        this->volume = vol;
    }

    void print() {
        cout << "Engine NO: " << engineNo << endl;
        cout << "Company: " << company << endl;
        cout << "Volume: " << volume << endl;
    }
};

class transportDepo {
public:
    stack<Car> cars;
    stack<Airplane> airplanes;
    stack<Ship> ships;

    void addCar(Car car) {
        cars.push(car);
    }

    void addShip(Ship ship) {
        ships.push(ship);
    }

    void addPlane(Airplane plane) {
        airplanes.push(plane);
    }

    void showAllTransports() {
        cout << "Cars" << endl;
        while (!cars.empty()) {
            cars.top().print();
            cars.pop();
        }

        cout << "Airplanes" << endl;
        while (!airplanes.empty()) {
            airplanes.top().print();
            airplanes.pop();
        }

        cout << "Ships" << endl;
        while (!ships.empty()) {
            ships.top().print();
            ships.pop();
        }
    }
};

int main()
{
    Engine engine(1, "Resul", 2);
    Car car(1, "BMW", "I30", engine, true);
    transportDepo depo;
    depo.addCar(car);
    depo.showAllTransports();
}
