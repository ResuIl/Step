#include <iostream>
#include <stack>
using namespace std;

template<class T>
class DoublyLinkedList
{
public:

	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node(T data = "") : data(data), prev(), next() {}
	};


	// O(1)
	void push_front(T data)
	{
		push_front(new Node(data));
	}

	void push_front(Node* node)
	{
		if (_head == NULL)
		{
			_head = node;
			_tail = node;
			return;
		}

		node->next = _head;
		_head->prev = node;

		_head = node;
	}



	void push_back(T data)
	{
		push_back(new Node(data));
	}

	void push_back(Node* node)
	{
		if (_head == NULL)
		{
			_head = node;
			_tail = node;
			return;
		}


		_tail->next = node;
		node->prev = _tail;

		_tail = node;
	}


	void insert_before(Node* node, T data)
	{
		Node* new_node = new Node(data);

		new_node->prev = node->prev;

		if (node != _head)
			node->prev->next = new_node;
		else
			_head = new_node;

		new_node->next = node;
		node->prev = new_node;
	}

	void insert_after(Node* node, T data);


	void pop_front()
	{
		if (_head == NULL)
			return;

		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
			return;
		}

		_head = _head->next;

		delete _head->prev;
		_head->prev = NULL;
	}

	void pop_back()
	{
		if (_head == NULL)
			return;

		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
			return;
		}


		_tail = _tail->prev;
		delete _tail->next;
		_tail->next = NULL;
	}


	// O(N)
	Node* search(T data)
	{
		auto n = _head;

		while (n != NULL)
		{
			if (n->data == data)
				return n;

			n = n->next;
		}

		return NULL;
	}

	void traversalForward() const
	{
		Node* n = _head;

		while (n != NULL)
		{
			cout << n->data << endl;
			n = n->next;
		}
	}
	void traversalBackward() const
	{
		Node* n = _tail;

		while (n != NULL)
		{
			cout << n->data << endl;
			n = n->prev;
		}
	}


	const Node* head() const { return _head; }
	const Node* tail() const { return _tail; }

	void sort();



private:
	Node* _head = NULL;
	Node* _tail = NULL;
};


struct Product {
private:
	string _name;
	string _typeof;
	string _date;

public:
	Product() = default;

	Product(string name, string typeof, string date) {
		setName(name);
		setTypeof(typeof);
		setDate(date);
	}

	void setName(string name) {
		_name = name;
	}

	void setTypeof(string typeof) {
		_typeof = typeof;
	}

	void setDate(string date) {
		_date = date;
	}

	string getName() {
		return _name;
	};

	string getTypeof() {
		return _typeof;
	};

	string getDate() {
		return _date;
	};

	friend ostream& operator<<(ostream& output, Product product);
};

ostream& operator<<(ostream& output, Product w) {
	output << "\nName:" << w._name
		<< "\ntypeof:" << w._typeof
		<< "\ndate relaese: " << w._date;

	return output;
}

struct Wagon {
private:
	string _name;
	stack<Product> products;

public:
	Wagon() = default;

	Wagon(string name) {
		setName(name);
	}

	void setName(string name) {
		_name = name;
	}

	string getName() {
		return _name;
	};

	void addProduct(Product p) {
		products.push(p);
	}

	void deleteProduct(Product p) {
		products.pop();
	}

};


void main()
{
	Wagon w1;
	w1.products.push(Product{ "Cola" });
	w1.products.push(Product{ "Fanta" });
	w1.products.push(Product{ "Sprite" });


	DoublyLinkedList<Wagon> train;
	train.push_back(w1);

	// train.start();






	DoublyLinkedList<string> dll;
	auto node3 = new DoublyLinkedList<string>::Node("node3");


	dll.push_back("node1");
	dll.push_back(node3);
	dll.push_back("node4");


	dll.insert_before(node3, "node2");


	// dll.pop_back();
	// dll.pop_front();
	// dll.pop_front();



	// DoublyLinkedList<string>::Node* n = dll.search("node3");
	// cout << n->data << endl;

	dll.traversalForward();
	// dll.traversalBackward();

	cout << "Head address -> " << dll.head() << endl;
	cout << "Tail address -> " << dll.tail() << endl;
}