#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int h, w, a, b, h1, w1;
ll inf = 1000000000 + 7;

ll fact(ll t){
  ll dp[100005];
  for(int i = 0; i <= t; ++i){
    if(i == 0 || i == 1){
      dp[i] = 1;
    }else{
      dp[i] = dp[i - 1] * i % inf;
    }
  }
  return dp[t] % inf;
}

ll comb(ll t, ll u){
  return fact(t) / (fact(t - u) * fact(u)) % inf;
}

ll all_fact(){
  return comb(h + w, w) % inf;
}

void solve(){
  ll tmp = 0;
  for(int i = 0; i < w - b; ++i){
    tmp += (comb(h - a - 1 + b + i, h - a - 1) * comb(a - 1 + w - b - 1 - i, a - 1)) % inf;
    //cout << w - i << endl;
  }
  //ll ans = all_fact() - tmp % inf;
  cout << tmp << endl;
}

int main(){
  cin >> h >> w >> a >> b;
  //h = h1 - 1;
  //w = w1 - 1;
  
  //cout << all_fact() << endl;
  solve();
}