#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
using ll = long long;

int n;
ll x[55], y[55];

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> y[i];
  }
  ll mn = n;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      ll tmp1 = x[i] - x[j];
      ll tmp2 = y[i] - y[j];
      ll ans = n;
      for(int k = 0; k < n; ++k){
        for(int o = 0; o < n; ++o){
          if(x[k] - x[o] == tmp1 && y[k] - y[o] == tmp2){
            ans--;
            
          }
        }
      }
      mn = min(ans, mn);

    }
  }
  cout << mn << endl;
  return 0;
}