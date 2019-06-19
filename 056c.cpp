#include<iostream>

using namespace std;
using ll = long long;

ll x;

ll solver(ll n){
  ll dp[n];
  dp[0] = 0;
  for(int i = 1; i <= n; ++i){
    dp[i] =  dp[i - 1] + i;
  }
  return dp[n];
}

int main(){
  cin >> x;
  ll cnt = 0;
  //cout << solver(1) << endl;
  
  while(solver(cnt) < x){
    cnt++;
  }
  cout << cnt << endl;
}