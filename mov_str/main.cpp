#include <iostream>
#include <vector>
using namespace std;

//void MoveStrings(vector<string> &s, vector<string>& d);

//int main()
//{
//    vector<string> w1 = {"hello", "hey"};
//    vector<string> w2 = {"world", "weed"};
//    MoveStrings(w1,w2);
//    for(auto w: w1) {
//        cout << w << " ";
//    }
//    cout << endl;
//    for(auto w: w2) {
//        cout << w << " ";
//    }
//    cout << endl;
//    return 0;
//}

void MoveStrings(vector<string>& s, vector<string>& d) {
    for(uint i = 0; i < s.size();i++) {
        d.push_back(s[i]);
    }
    s.clear();
}
