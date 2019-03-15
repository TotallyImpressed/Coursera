#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> queue(0, false);
    vector<int> v_cnt;
    int q = 0;
    int n = 0;
    string cmd;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> cmd;
        if(cmd == "COME") {
            cin >> n;
            queue.resize(queue.size() + n, false);
        }
        else if(cmd == "WORRY") {
            cin >> n;
            queue[n] = true;
        }
        else if(cmd == "QUIET") {
            cin >> n;
            queue[n] = false;
        }
        else if(cmd == "WORRY_COUNT") {
            int cnt = 0;
            for(auto b: queue) {
                if(b == true) {
                    cnt++;
                }
            }
            v_cnt.push_back(cnt);
        }
    }
    for(auto i: v_cnt) {
        cout << i << endl;
    }
    return 0;
}
