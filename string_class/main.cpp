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

//int main() {
//  ReversibleString s("live");
//  s.Reverse();
//  cout << s.ToString() << endl;

//  s.Reverse();
//  const ReversibleString& s_ref = s;
//  string tmp = s_ref.ToString();
//  cout << tmp << endl;

//  ReversibleString empty;
//  cout << '"' << empty.ToString() << '"' << endl;

//  return 0;
//}
