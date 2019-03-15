#include <iostream>
using namespace std;

int main(void) {

int a,b;
cin >> a >> b;

if(((a % 1) != 0) || ((b % 1)!=0))
   return 1;
else if(b == 0)
   cout << "Impossible" << endl;
else
   if((a >= 0) && (b > 0))
      cout << a/b << endl;

return 0;
}
