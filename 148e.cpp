#include<iostream>
#include<cmath>

using namespace std;
using ll = long long;

ll n;

void input(){
  cin >> n;
}

void solve(){
  ll ans = 0;
  ll cnt = 0;
  ll a = pow(5, cnt);
  while(a <= n){
    ll b = pow(5, cnt + 1);
    if(b <= n){
      cnt++;
      a = pow(5, cnt);
      //cout << a << endl;
    }else{
      break;
    }
  }
  //cout << cnt << endl;
  while(cnt > 0){
    ll c = 2 * pow(5, cnt);
    ans += n / c;
    cnt--;
  }
  if(n % 2 != 0){
    ans = 0;
  }
  cout << ans << endl;

}

int main(){
  input();
  solve();
}