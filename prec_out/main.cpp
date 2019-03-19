#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    ifstream input("input.txt");
    vector<string> integer;
    vector<string> fraction;
    while(input) {
        integer.push_back(getline(input, integer,'.'));
        fraction.push_back(getline(input, fraction));
    }

    for(const auto& )

    return 0;
}
