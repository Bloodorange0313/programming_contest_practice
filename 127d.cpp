#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using ll = long long;


int n, m;
ll a[100005], c[100005];
int b[100005];
priority_queue<ll>Q;
ll ans = 0;
vector<pair<ll, int> >V;
vector<ll> S;
ll secondcnt = 0;

void input(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    Q.push(-a[i]);
    ans += a[i];
  }
  for(int i = 0; i < m; ++i){
    cin >> b[i] >> c[i];
    secondcnt += b[i];
    V.push_back(make_pair(c[i], b[i]));
  }
  sort(V.begin(), V.end());
  //cout << V[0].first << endl;
  ll tmp = V.size() - 1;
  int count = 0;
  //cout << n << endl;
  //cout << secondcnt << endl;
  while(count < n && count < secondcnt){
    //cout << count << endl;
    //count++;
    int cnt = V[tmp].second;
    //cout << cnt << endl;
    while(cnt > 0){
      S.push_back(V[tmp].first);
      count++;
      //cout << V[tmp].first << endl;
      cnt--;
    }
    tmp--;
  }
  sort(S.begin(), S.end());
  
  
}

ll solve2(){
  for(int i = S.size() - 1; i >= 0; --i){
    ll tmp = Q.top();
    //cout << tmp << endl;
    Q.pop();
    //cout << tmp << endl;
    if(-S[i] < tmp){
      Q.push(-S[i]);
      ans += S[i];
      ans -= -tmp;
    }else{
      Q.push(tmp);
      break;
    }
  }
  return ans;
}

int main(){
  input();
  cout << solve2() << endl;
  //S.clear();
  return 0;
}