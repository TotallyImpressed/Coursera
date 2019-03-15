#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string,string> syn, rev_syn;
    for(int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if(cmd == "ADD") {
            string s1,s2;
            cin >> s1 >> s2;
            if(syn[s1] != s2) {
                syn[s1] = s2;
                rev_syn[s2] = s1;
            }
        }
        else if(cmd == "COUNT") {
            int cnt = 0;
            string s;
            cin >> s;
            cnt = syn.count(s) + rev_syn.count(s);
            for(const auto& m: syn) {
                if(m.second == s) {
                    cnt++;
                }
            }
            for(const auto& m: rev_syn) {
                if(m.second == s) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
