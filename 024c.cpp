#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

//const ll inf =  1e9 + 5;

ll n, d, k;

ll l[10005], r[10005];
ll s[105], t[105];

//ll left_val[10005][10005], right_val[10005][10005];
ll cnt[10005];

void input(){
  cin >> n >> d >> k;
  for(int i = 1; i <= d; ++i){
    cin >> l[i] >> r[i];
  }
  for(int i = 1; i <= k; ++i){
    cin >> s[i] >> t[i];
  }
}

void solve(){
  //ll left_val[10005];
  ll current1 = 1;
  ll ans[10005];
  //ll count[100005][100005];
  for(int j = 1; j <= k; ++j){
    ll cnt = 0;
    if(s[j] < t[j]){
      current1 = s[j];
    //cout << s[j] << endl;
      for(int i = 1; i <= d; ++i){
       cnt++;
       if(current1 >= l[i] && current1 < r[i]){
         current1 = r[i];
       }
       //cout << current1 << endl;
       
       if(current1 >= t[j]){
         //cout << cnt << endl;
          ans[j] = cnt;
          break;
         //continue;
       }
      }
    }else{
      current1 = s[j];
      //cout << current1 << endl;
      //cout << s[j] << endl;
      for(int i = 1; i <= d; ++i){
       cnt++;
       if(current1 <= r[i] && current1 > l[i]){
         current1 = l[i];
       }
       //cout << current1 << endl;
       if(current1 <= t[j]){
         //cout << cnt << endl;
          ans[j] = cnt;
          break;
         //continue;
       }
      }
    }
    
  }
  for(int j = 1; j <= k; ++j){
    cout << ans[j] << endl;
  }
  
  
}

int main(){
  input();
  solve();
}