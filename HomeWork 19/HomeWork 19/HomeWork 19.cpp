#include <iostream>
#include <vector>

using namespace std;
#include "University.h"
#include "Teachers.h"
#include "Student.h"
#include "Lesson.h"
#include "Group.h"
#include "Exam.h"
#include "Bank.h"


int main()
{
    // Basha Dusduyum Qederi Yazdim. Ama Ne yazdigimi ozumde tam basha dushmedim :D

    University uni;


    uni.teachers.push_back(Teacher("Resul", "BLACK", 16, Group("FirstClass"), "FirstClass", 10000, BankCard("4169", "1234", 1000000, 10, 21)));

    uni.students.push_back(Student("Rasul", "BLACK", "BEST", 100, 100000, BankCard("4169", "1234", 100000, 10, 26), Exam()));

    cout << uni.getUniversityEmployerCount();

    uni.getPayment();
}