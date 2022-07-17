#include <iostream>
using namespace std;

#include "SharedPTR.h"

class Test
{
public:
    int x, y, z;
	Test() : x(), y(), z() {}

};

int main()
{
	SharedPTR<Test> test;
    cout << test.getCount() << endl;

	SharedPTR<Test> test1(new Test());
    cout << test1.getCount() << endl;

	SharedPTR<Test> test2(test1);
    cout << test1.getCount() << endl;
    cout << test2.getCount() << endl;
}