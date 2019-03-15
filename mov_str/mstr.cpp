#include <iostream>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& s, vector<string>& d) {
    for(uint i = 0; i < s.size();i++) {
        d.push_back(s[i]);
    }
    s.clear();
}

