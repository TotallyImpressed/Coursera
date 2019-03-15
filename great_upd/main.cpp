#include <iostream>

using namespace std;

void UpdateIfGreater(int first, int& second);

int main()
{
    int a,b;
    cin >> a >> b;
    UpdateIfGreater(a,b);
    cout << b<< endl;
    return 0;
}

void UpdateIfGreater(int first, int& second){
    if(first > second) {
        second = first;
    }
}
