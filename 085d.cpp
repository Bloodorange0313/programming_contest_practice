#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int n;
ll h;
ll a[100005], b[100005];
vector<ll> s, t;



int main(){
  cin >> n >> h;
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
    //cout << a[i] << b[i] << endl;
    s.push_back(a[i]);
    t.push_back(b[i]);
  }
  sort(s.begin(), s.end(), greater<ll>());
  sort(t.begin(), t.end(), greater<ll>());
  //ll mp = h;
  //ll cnt = 0;
  ll tmp = 0;
  //cout << cnt << endl;
  ll s_ini = s[0];
  ll t_ini = t[0];
  ll t_sum = 0;
  while(t_ini > s_ini && t_sum < h){
    t_sum += t[tmp];
    tmp++;
    t_ini = t[tmp];
  }
  ll s_cnt = 0;
  if(t_sum < h){
    if(((h - t_sum) % s[0]) == 0){
      s_cnt = ((h - t_sum) / s[0]);
    }else{
      s_cnt = ((h - t_sum) / s[0]) + 1;
    }
  }
  cout << tmp + s_cnt << endl;
  
}