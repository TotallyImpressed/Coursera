#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    string cmd;
    map<string, vector<string>> busSched;
    vector<string> order;
    int stop_count;

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> cmd;
        if(cmd == "NEW_BUS") {
            string bus;
            cin >> bus >> stop_count;
            vector<string> stops(stop_count);

            for(auto& s: stops) {
                cin >> s;
            }
            busSched[bus] = stops;
            order.push_back(bus);
        }
        else if(cmd == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;

            if(order.size() == 0) {
                cout << "No stop";
            }
            else {
                int crutch = 0;
                for(const auto& s: order) {
                    if((find(busSched[s].begin(), busSched[s].end(), stop) == busSched[s].end()) && (s == order[order.size() - 1]) && (crutch == 0)) {
                        cout << "No stop";
                    }
                    else if(find(busSched[s].begin(), busSched[s].end(), stop) != busSched[s].end()){
                        cout << s << " ";
                        crutch ++;
                    }
                }
            }
            cout << endl;
        }
        else if(cmd == "STOPS_FOR_BUS") {
            string bus;
            string out = "";
            cin >> bus;
            if(find(order.begin(), order.end(), bus) == order.end()) {
                cout << "No bus" << endl;
            }
            else {
                for(const auto& st: busSched[bus]) {
                    cout << "Stop " << st << ": ";
                    for(const auto& s:order) {
                        if((find(busSched[s].begin(), busSched[s].end(), st) != busSched[s].end()) && (s != bus)) {
                            out += s + " ";
                        }
                        else if(out == "" && s == order[order.size() - 1]) {
                            out = "no interchange";
                        }
                    }
                    cout << out << endl;
                    out = "";
                }
            }
        }
        else if(cmd == "ALL_BUSES") {
            if(order.size() == 0) {
                cout << "No buses" << endl;
            }
            else {
                for(const auto& m: busSched) {
                    cout << "Bus " << m.first << ": ";
                    for(const auto& s: busSched[m.first]) {
                        cout << s << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
