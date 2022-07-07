#pragma once
#include "Student.h"
#include "Teachers.h"

class University {
public:
	string name = "ADA";
	vector<Teacher> teachers;
	vector<Student> students;

	int getUniversityEmployerCount() {
		return ((int)teachers.size() + (int)students.size());
	}
	
	void showAllStudents() {
		for (int i = 0; i < students.size(); i++) {
			students[i].print();
		}
	}

	void getPayment() {
		for (int i = 0; i < teachers.size(); i++) {
			cout << "Teacher Name: " << teachers[i].getName() << " Salary: " << teachers[i].getSalary() << endl;
		}
		for (int i = 0; i < students.size(); i++) {
			cout << "Student Name: " << students[i].getName() << " Salary: " << students[i].getSalary() << endl;
		}
	}

	// GetUniverSityScore ve getPaymenti basha dushmedim.

};