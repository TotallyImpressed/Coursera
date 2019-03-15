#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> tmp = v;
    for(uint i = 0; i < v.size(); i++) {
        tmp[i] = v[v.size() - i - 1];
    }
    return tmp;
}
