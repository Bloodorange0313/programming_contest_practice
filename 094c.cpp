#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

int n;
ll x[200005];
vector<ll>V;

int main(){
  cin >> n;
  ll cnt = 0;
  V.push_back(0);
  for(int i = 1; i <= n; ++i){
    cin >> x[i];
    cnt++;
    V.push_back(x[i]);
  }
  sort(V.begin(), V.end());
  ll medium = (cnt + 1) / 2;
  //cout << medium << endl;
  ll l = V[medium];
  ll r = V[medium + 1];
  //cout << l << endl;
  for(int i = 1; i <= n; ++i){
    if(x[i] <= l){
      cout << r << endl;
    }else{
      cout << l << endl;
    }
  }
}