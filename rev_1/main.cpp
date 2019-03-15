#include <iostream>
#include <vector>
using namespace std;

//vector<int> Reverse(const vector<int>& v);

//int main()
//{
//    vector<int> vint = {1,3,5,7,9,0,1,1,1,2,3,4,5};
//    vint = Reverse(vint);
//    for(auto i: vint) {
//        cout << i;
//    }
//    cout << endl;
//    return 0;
//}

vector<int> Reverse(const vector<int>& v) {
    vector<int> tmp = v;
    for(uint i = 0; i < v.size(); i++) {
        tmp[i] = v[v.size() - i - 1];
    }
    return tmp;
}
