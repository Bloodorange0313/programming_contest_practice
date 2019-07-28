#include<iostream>

using namespace std;
using ll = long long;

ll n;
ll a[100005], b[100005];

ll solver(){
  ll cnt = 0;
  for(int i = 0; i < n; ++i){
    ll tmp = b[i];
    if(tmp >= a[i]){
      cnt += a[i];
      tmp -= a[i];
      if(tmp >= a[i + 1]){
        cnt += a[i + 1];
        a[i + 1] = 0;
      }else{
        a[i + 1] -= tmp;
        cnt += tmp;
      }
    }else{
      cnt += tmp;
    }
  }
  return cnt;
}

int main(){
  cin >> n;
  for(int i = 0; i < n + 1; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i){
    cin >> b[i];
  }
  cout << solver() << endl;
}