#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;
    string cmd, work;
    int day;
    vector<string> cur_month(31);
    vector<int> cnt(31);
    for (int i = 0; i < q; ++i) {
        cin >> cmd;
        if(cmd == "ADD") {
            cin >> day >> work;
            cur_month[day] += " " + work;
            cnt[day]++;
        }
    }

    for(auto s: cur_month) {
        cout << s << endl;
    }

    for(auto i: cnt) {
        cout << i << endl;
    }



    return 0;
}
