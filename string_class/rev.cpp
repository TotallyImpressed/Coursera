#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {
        s = "";
    }
    ReversibleString(string str){
        s = str;
    }
    string Reverse() {
        reverse(s.begin(), s.end());
        return s;
    }
    string ToString() const{
        return s;
    }
private:
    string s;
};
