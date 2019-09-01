#include<iostream>

using namespace std;
using ll = long long;

ll inf = 100000000000005;

int n;
ll c;
ll x[100005], v[100005];
ll dp[100005];

void solver(){
  ll maximum = 0;
  ll dist = 0;
  v[0] = 0;
  dp[0] = 0;
  for(int i = 1; i <= n; ++i){
    dist = min(x[i] - x[i - 1], c - (x[i] - x[i - 1]));
    dp[i] = dp[i - 1] + (v[i] - dist);
    cout << v[i] << " " << x[i] << endl;
    if(dp[i] > maximum){
      maximum = dp[i];
    }
    cout << dp[i] << endl;
  }
  cout << maximum << endl;
}

int main(){
  cin >> n >> c;
  for(int i = 1; i <= n; ++i){
    cin >> x[i] >> v[i];
  }
  //cout << solver() << endl;
  solver();
}