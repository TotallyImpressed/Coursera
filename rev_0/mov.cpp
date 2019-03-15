#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    vector<int> tmp = v;
    for(int i = 0; i < v.size(); i++) {
        tmp[i] = v[v.size() - i - 1];
    }
    v = tmp;
}
