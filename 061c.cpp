#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

ll n, k;
ll a[100005], b[100005];
ll cnt[100005];
//vector<pair<long long, long long> >V;

int main(){
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
    cnt[a[i]] += b[i];
    //V.push_back(make_pair(a[i], b[i]));
  }
  for(int ans = 1; ans <= 100000; ++ans){
    if(k <= cnt[ans]){
      cout << ans << endl;
      break;
    }
    k -= cnt[ans];
  }
}