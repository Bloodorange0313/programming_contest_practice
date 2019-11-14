#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

ll n;
ll a[100005], b[100005];

void input(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i){
    cin >> b[i];
  }
}

bool solve(){
  bool flag = false;
  ll diff[100005];
  vector<pair<ll, int> >V;
  for(int i = 0; i < n; ++i){
    diff[i] = b[i] - a[i];
    V.push_back(make_pair(diff[i], i));
  }
  sort(V.begin(), V.end());
  int cnt = 0;
  int tmp1 = 0;
  int tmp2 = n - 1;
  while(cnt < n - 2){
    cnt++;
    if(V[tmp1].first >= 0){
      flag = true;
      break;
    }else{
      if((b[tmp1] - a[V[tmp2].second]) >= 0){
        //swap(a[tmp1], a[V[tmp2.second]]);
        if((b[tmp1] - a[V[tmp2].second]) < 0){
          flag = false;
          break;
        }else{
          tmp1++;
          if((a[V[tmp2].second] - a[V[tmp2 - 1].second) )
        }
      }
    }
  }
}

int main(){
  input();
}