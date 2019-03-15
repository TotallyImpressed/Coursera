#include <iostream>
using namespace std;

bool IsPlindrom(string s);

int main()
{
    string in;
    bool pld;
    cin >> in;
    pld = IsPlindrom(in);
    cout << pld << endl;
    return 0;
}

bool IsPlindrom(string s){
    string str;
    for(int i = s.size() - 1; i >0; --i ) {
        str[s.size() - 1 - i] = s[i];
    }

    cout << str << endl;
    if (str == s)
        return true;
    return false;
}

