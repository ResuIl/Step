#pragma once

class Group {
public:
	string _name = "";
	vector<Student> students;
	vector<Lesson> lessons;

	Group(string name) : _name(name) {};


};