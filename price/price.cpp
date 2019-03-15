#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

vector<float> pr_cond = {0, 0, 0, 0, 0}; //N,A,B,X,Y

for(int i = 0; i < 5; ++i)
   cin >> pr_cond[i];

for(auto c: pr_cond)
   if (c < 0)
      return 1;

if(find(pr_cond.begin(),pr_cond.end(), 0) == pr_cond.end()) {
   if(pr_cond[1] < pr_cond[2]) {
      if(pr_cond[0] < pr_cond[1])
         cout << pr_cond[0] << endl;
      else if((pr_cond[0] > pr_cond[1]) && (pr_cond[0] < pr_cond[2]))
         cout << pr_cond[0] - (pr_cond[0] * pr_cond[3] / 100) << endl;
      else if(pr_cond[0] > pr_cond[2])
         cout << pr_cond[0] - (pr_cond[0] * pr_cond[4] / 100) << endl;
   }
}

return 0;
}
