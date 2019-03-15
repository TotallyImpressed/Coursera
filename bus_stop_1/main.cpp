#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<vector<string>, int> busStops;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int stopCnt;
        cin >> stopCnt;
        vector<string> stops(stopCnt);
        for(auto& s: stops) {
            cin >> s;
        }
        int size = busStops.size();
        if(size > 0) {
            busStops[stops] = size + 1;
            for(const auto& m: busStops) {
                if(m.first == stops) {
                    cout << "A" << m.second << endl;
                }
                else {
                    cout << "New bus " << m.second << endl;
                }
            }
        }
        else {
            busStops[stops] = size + 1;
            cout << "New bus " << size + 1 << endl;
        }

    }
    return 0;
}
