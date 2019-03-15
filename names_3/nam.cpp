#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int SearchYear(const int year, map<int,string>& name);
string SearchName(const int year, const map<int, string> &name);
string ProcMap(const int year, map<int,string> name);

class Person {
public:
    Person (const string& f_name, const string& l_name, int year) {
        fn[year] = f_name;
        ln[year] = l_name;
        birth_year = year;
    }
    void ChangeFirstName(int year, string first_name) {
        if(year > birth_year) {
            fn[year] = first_name;
        }
    }
    void ChangeLastName(int year, string last_name) {
        if(year > birth_year) {
            ln[year] = last_name;
        }
    }
    string GetFullName(int year) const{
        const string first_name = SearchName(year, fn);
        const string last_name = SearchName(year, ln);
        if(year < birth_year) {
            return "No person";
        }
        else if(first_name.empty() && last_name.empty()) {
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
    string GetFullNameWithHistory(const int year) const{
        const string first_name = SearchName(year, fn);
        const string last_name = SearchName(year, ln);

        if(year < birth_year) {
            return "No person";
        }
        else if(first_name.empty() && last_name.empty()) {
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
    int birth_year = 0;
};

// Reverse certain part of map and delete adjacent repeatable values in it
string ProcMap(const int year,map<int,string> name) {
    string ret_val;
    vector<string> v_names;
    const int found_year = SearchYear(year, name);
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
string SearchName(const int year, const map<int,string>& name) {
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
int SearchYear(const int year, map<int,string>& name) {
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
