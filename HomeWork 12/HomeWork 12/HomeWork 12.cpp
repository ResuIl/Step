#include<iostream>
#include<vector>

using namespace std;

struct Location {
private:
	string _longitude;
	string _latitude;

public:
	Location() = default;

	Location(string longitude, string latitude) {
		setLongitude(longitude);
		setLatitude(latitude);
	}

	void setLongitude(string longitude) { _longitude = longitude; }

	void setLatitude(string latitude) { _latitude = latitude; }

	string getLocation() { return _longitude, _latitude; }
};

class City {
private:
	string _name;
	Location _location;
	size_t _population;
	bool _isCapital;

public:

	City() = default;

	City(string name, Location location, size_t population, bool isCapital) {
		setName(name);
		setLocation(location);
		setPopulation(population);
		setIscapital(isCapital);
	}

	void setName(string name) {
		if (name.length() < 2)
			throw "Min Character Count Must Be 3!";
		else
			_name = name;
	}

	void setLocation(Location location) { _location = location; }

	void setPopulation(size_t population) {
		if (population == 0)
			throw"wrong population";
		else
			_population = population;
	}

	void setIscapital(bool isCapital) { _isCapital = isCapital; }

	bool operator<(City city) { return _population < city._population; }

	bool operator==(City city) { return _population == city._population; }

	bool operator>(City city) { return _population > city._population; }

	friend ostream& operator<<(ostream& output, City city);
};

ostream& operator<<(ostream& output, City city) {
	output << "\nName:" << city._name << "\nLocation:" << city._location.getLocation() << "\nPopilation:" << city._population << "\nCapital: " << city._isCapital;
	return output;
}

class Country {
private:
	string _name;
	vector<City> _cities;
	Location _location;
	size_t _count_city;
public:
	Country() = default;

	Country(string name, vector<City> cities, Location location) {
		_name = name;
		_cities = cities;
		_location = location;
		_count_city = _cities.size();
	}

	void addCity(City cities) {
		_cities.push_back(cities);
		cout << _count_city;
	}

	void deleteCity() {
		_cities.pop_back();
	}

};


template<typename M>
class BinarySearchTree
{
	struct Node
	{
		City key;
		Node* left, * right;

		Node(City key) : key(key), left(), right() {}
	};

	Node* root = NULL;

	Node* insertRec(Node* tree, City key)
	{
		if (tree == NULL)
		{
			tree = new Node(key);
			return tree;
		}

		if (key < tree->key)
			tree->left = insertRec(tree->left, key);
		else if (key > tree->key)
			tree->right = insertRec(tree->right, key);

		return tree;
	}

	void inOrderRec(Node* tree)
	{
		if (tree != NULL)
		{
			inOrderRec(tree->left);
			cout << tree->key << endl;
			inOrderRec(tree->right);
		}
	}

	Node* searchRec(Node* tree, City key)
	{
		if (tree == NULL)
			return NULL;
		else if (key == tree->key)
			return tree;
		else if (key > tree->key)
			return searchRec(tree->right, key);

		return searchRec(tree->left, key);
	}

	City minvalue(Node* tree)
	{
		City min = tree->key;

		while (tree->left != NULL)
		{
			min = tree->left->key;
			tree = tree->left;
		}

		return min;
	}

	City maxvalue(Node* tree)
	{
		City max = tree->key;

		while (tree->right != NULL)
		{
			max = tree->right->key;
			tree = tree->right;
		}

		return max;
	}

	Node* deleteRec(Node* tree, City key)
	{
		if (tree == NULL)
			return NULL;

		if (key < tree->key)
			tree->left = deleteRec(tree->left, key);
		else if (key > tree->key)
			tree->right = deleteRec(tree->right, key);
		else
		{
			if (tree->left == NULL)
				return tree->right;
			else if (tree->right == NULL)
				return tree->left;

			tree->key = minvalue(tree->right);

			tree->right = deleteRec(tree->right, tree->key);
		}
		return tree;
	}


public:
	BinarySearchTree() = default;

	void insert(City key)
	{
		root = insertRec(root, key);
	}

	void inOrder()
	{
		inOrderRec(root);
	}

	Node* search(City key)
	{
		return searchRec(root, key);
	}

	City minValue()
	{
		minvalue(root);
	}

	City maxValue()
	{
		maxvalue(root);
	}

	void deleteKey(City key)
	{
		root = deleteRec(root, key);
	}
};


int main() {
	cout << "Hakuna Matata" << endl;
}