#include <iostream>
#include <cassert>
using namespace std;

template<class T, int maxSize = 100>
class Queue
{
private:
	T arr[maxSize];
	int front = -1;
	int rear = -1;

public:
	Queue() = default;

	void EnQueue(T item) {
		if (isFull())
			throw "Overflow";

		if (isEmpty()) {
			front = 0;
			rear = -1;
		}
		arr[++rear] = item;
	}

	void DeQueue() {
		if (isEmpty())
			throw "UnderFlow";
		front++;
	}

	T peek()const {
		if (isEmpty())
			throw"Queue is empty";
		return arr[front];
	}

	const T* GetArr()const {
		if (isEmpty())
			return nullptr;
		return arr;
	}

	bool isEmpty()const {
		return Size() == 0;
	}

	bool isFull()const { return Size() == maxSize; }

	size_t Size()const {
		if (front == -1)
			return 0;
		return (rear - front) + 1;
	}

};

class Worker
{
private:
	size_t myID;
	string name;
	string surname;
	size_t age;
	size_t pageCount;

public:
	static size_t id;

	Worker() : name(""), pageCount(0), age(18), surname("") {};

	Worker(const string& name, const string& surname, const size_t& age, const size_t& pageCount) {
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetPageCount(pageCount);
		myID = ++id;
	}

	Worker(const Worker& other) {
		SetName(other.name);
		SetPageCount(other.pageCount);
		SetAge(other.age);
		SetSurname(other.surname);
		myID = other.myID;
	}

	Worker& operator=(const Worker& other) {
		SetName(other.name);
		SetPageCount(other.pageCount);
		SetAge(other.age);
		SetSurname(other.surname);
		myID = other.id;
		return *this;
	}

	Worker(Worker&& other) {
		SetName(other.name);
		SetPageCount(other.pageCount);
		SetAge(other.age);
		SetSurname(other.surname);
		myID = other.id;
	}

	string GetName()const { return name; }
	string GetSurname()const { return surname; }
	size_t GetPageCount()const { return pageCount; }
	size_t GetAge()const { return age; }
	size_t GetId()const { return myID; }

	void SetName(const string& name) {
		if (!name.empty() && name.size() >= 4)
			this->name = name;
		else
			assert("Your name is too short!");
	}

	void SetPageCount(const size_t& pageCount) {
		if (pageCount > 0)
			this->pageCount = pageCount;
		else
			assert("page Count==0");
	}

	void SetAge(const size_t& age) {
		if (age > 18)
			this->age = age;
		else
			assert("You must be 18 years older!");
	}

	void SetSurname(const string& surname) {
		if (!surname.empty() && surname.size() > 6)
			this->surname = surname;
		else
			assert("Your surname is too short!");
	}

	void show()const {
		cout << "ID: " << GetId() << endl;
		cout << "Name: " << GetName() << endl;
		cout << "Surname: " << GetSurname() << endl;
		cout << "Age: " << GetAge() << endl;
		cout << "Page count: " << GetPageCount() << endl;
	}
};

size_t Worker::id = 0;

class Printer
{
private:
    Queue<Worker> workers;
public:

    void request(Worker worker) {
        worker.show();
    }

    void start() {

        while (workers.isEmpty()) {
            workers.DeQueue();
        }
    }
};

int main()
{
    cout << "Hello World!\n";
}
