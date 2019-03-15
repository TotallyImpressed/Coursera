#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int SearchYear(int& year, map<int,string>& name);
string SearchName(int& year, map<int,string>& name);
string ProcMap(int& year,map<int,string> name);

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        fn[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        ln[year] = last_name;
    }
    string GetFullName(int year) {
        const string first_name = SearchName(year, fn);
        const string last_name = SearchName(year, ln);

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
    string GetFullNameWithHistory(int year) {
        const string first_name = SearchName(year, fn);
        const string last_name = SearchName(year, ln);

        if(first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        else if(first_name.empty()) {
            return ProcMap(year, ln) + " with unknown first name";
        }
        else if(last_name.empty()) {
            return ProcMap(year, fn) + " with unknown last name";;
        }
        else {
            return ProcMap(year, fn) + " " + ProcMap(year, ln);
        }
    }
private:
    map<int, string> fn;
    map<int, string> ln;
};



// Reverse certain part of map and delete adjacent repeatable values in it
string ProcMap(int& year,map<int,string> name) {
    string ret_val;
    vector<string> v_names;
    int found_year = SearchYear(year, name);
    for(const auto& m: name) {
        if(m.first <= found_year) {
            v_names.push_back(m.second);
        }
    }
    reverse(v_names.begin(), v_names.end());
    auto last = unique(v_names.begin(), v_names.end());
    v_names.erase(last, v_names.end());
    if(v_names.size() > 1) {
        ret_val = v_names[0] + " (";

        for(uint i = 1;  i < v_names.size(); i++) {
            ret_val += v_names[i] + ", ";
        }
        ret_val.erase(ret_val.end()-2, ret_val.end());
        ret_val += ")";
    }
    else {
        ret_val = v_names[0];
    }
    return ret_val;
}
// Searching value corresponding to closest year in map
string SearchName(int& year, map<int,string>& name) {
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
// Searching closest year value in map
int SearchYear(int& year, map<int,string>& name) {
    int ret_val = 0;
    for(const auto& m: name) {
        if(m.first <= year) {
           ret_val = m.first;
        }
        else {
            break;
        }
    }
    return ret_val;
}
