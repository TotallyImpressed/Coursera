#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v);

int main()
{

    vector<int> vint = {1,3,5,7,9,0,1,1,1,2,3,4,5};
    Reverse(vint);
    for(auto i: vint) {
        cout << i;
    }
    cout << endl;
    return 0;
}

void Reverse(vector<int>& v) {
    vector<int> tmp = v;
    for(uint i = 0; i < v.size(); i++) {
        tmp[i] = v[v.size() - i - 1];
    }
    v = tmp;
}
