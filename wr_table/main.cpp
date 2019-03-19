#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream input("input.txt");
    int col = 0;
    int raw = 0;
    input >> col;
    input >> raw;
    cout << col << " " << raw << endl;
    vector<vector<int>> num_table(raw, vector<int>(col));


    return 0;
}
