#include <iostream>
using namespace std;
#include<map>
#include<vector>
#include"Penalty.h"

int main()
{
    map<string, vector<Penalty>> penalties;

    penalties["99-DO-999"].push_back(Penalty{1, "Parking","01.01.2022", 1000});
    penalties["99-DO-999"].push_back(Penalty{ 1, "Parking123","01.01.2022", 1000 });
    penalties["99-DO-998"].push_back(Penalty{ 1, "Test","01.01.2022", 1000 });

    for (auto p : penalties) {
        for (int i = 0; i < penalties[p.first].size(); i++) {
            penalties[p.first][i].print();
            cout << endl;
        }
    }
}