#include<iostream>


using namespace std;
using ll = long long;

int n;
ll a[100005];
ll x[100005];

void input(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
}

ll sum_value(){

  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ans += a[i];
  }
  return ans;
}

void solve(){
  x[0] = sum_value();
  for(int i = 1; i < n; i = i + 2){
    x[0] -= 2 * (a[i]);
  }
  //return x[0];
  for(int i = 1; i < n; ++i){
    x[i] = 2 * a[i - 1] - x[i - 1];
  }
  for(int i = 0; i < n; ++i){
    cout << x[i] << " ";
  }
  cout << endl;
}

int main(){
  input();
  //cout << solve() << endl;
  solve();
}