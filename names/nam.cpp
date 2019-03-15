#include <iostream>
#include <map>
#include <set>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        fn[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        ln[year] = last_name;
    }
    string GetFullName(int year) {
        const string first_name = srch(year, fn);
        const string last_name = srch(year, ln);

        if(first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        else if(first_name.empty()) {
            return last_name + " with unknown first name";
        }
        else if(last_name.empty()) {
            return first_name + " with unknown last name";
        }
        else {
            return first_name + " " + last_name;
        }
    }
private:
    map<int, string> fn;
    map<int, string> ln;
    string srch(int& year, map<int,string>& name) {
        string ret_val;
        for(const auto& m: name) {
            if(m.first <= year) {
               ret_val = m.second;
            }
            else {
                break;
            }
        }
        return ret_val;
    }
};
