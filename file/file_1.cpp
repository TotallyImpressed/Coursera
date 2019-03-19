#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input("input.txt");
    string line;
   	const string path = "output.txt";
   	ofstream output (path);
    if(input.is_open()) {
        while(getline(input, line)) {
            output << line << endl;
        }
    }
    else {
        cout << "Error" << endl;
    }

    return 0;
}