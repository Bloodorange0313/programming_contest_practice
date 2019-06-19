#include<iostream>

using namespace std;
using ll = long long;

int n;
ll a[100005];

/* 
ll add(int s){
  ll dp[s];
  dp[0] = 0;
  for(int i = 1; i <= s; ++i){
    if(i == 1){
      dp[i] = 1;
    }else{
      //dp[i] = dp[i - 1] + i;
      dp[i] = i;
    }
  }
  return dp[s];
}
*/

int main(){
  cin >> n;
  
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  //cout << add(4) << endl;
  ll cnt = 1;
  ll ans = 1;
  ll tmp = a[0];
  for(int i = 1; i < n; ++i){
    if(tmp < a[i]){
      cnt++;
    }else{
      cnt = 1;
    }
    tmp = a[i];
    ans += cnt;
    //cout << add(cnt) << endl;
  }
  cout << ans << endl;
}