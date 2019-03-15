#include <iostream>
using namespace std;

int Factorial(int n) {
    if(n > 10) {
        return 1;
    }
    int f = 1;
    for(int i = 0; i < n; i++) {
        f = f * (i+1);
    }
    return f;
}
