#include<iostream>

using namespace std;
using ll = long long;

int n;
ll x;
ll a[100005];

void input(){
  cin >> n >> x;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
}

ll solve(){
  ll current = 0;
  ll ans = 0;
  for(int i = 0; i < n - 1; ++i){
    current = a[i];
    if(current > x){
      ans += current - x;
      current = x;
    }
    current += a[i + 1];
    if(current > x){
      ans += current - x;
      a[i + 1] -= (current - x);
      current = a[i + 1];
    }
  }
  return ans;
}

int main(){
  input();
  cout << solve() << endl;
}