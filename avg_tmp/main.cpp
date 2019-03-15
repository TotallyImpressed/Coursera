#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,avg = 0, cnt = 0;
    cin >> n;
    vector<int> tmp(n), out;
    for(auto& i: tmp) {
        cin >> i;
    }

    for(auto i: tmp) {
        avg += i;
    }
    avg = avg/n;

    for(uint i = 0; i < tmp.size(); i++) {
        if(tmp[i] > avg) {
            out.push_back(i);
            cnt ++;
        }
    }

    cout << cnt << endl;
    for(auto i: out) {
        cout << i << " ";
    }
    return 0;
}
