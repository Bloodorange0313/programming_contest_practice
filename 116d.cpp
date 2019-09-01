#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using ll = long long;
using namespace std;

int n, k;
int t[100005];
ll d[100005];
vector<pair<ll, ll> >V;
ll dp[100005];
set<ll>S;

void solver(){
  /*ll diversity = 0;*/
  ll cnt = 0;
  int memory = 0;
  dp[0] = 0;
  while(memory <= k){
    if(memory == 0){
      dp[memory] = 0;
      memory++;
    }else if(memory == 1){
      dp[memory] = V[V.size() - 1].first + (S.size() + 1) * (S.size() + 1);
      //cout << V[V.size() - 1].first << endl;
      S.insert(V[V.size() - 1].second);
      V.erase(V.begin() + V.size() - 1);
      cnt++;
      memory++;
    }else{
      ll tmp1 = V[V.size() - 1].second;
      ll tmp2 = 0, tmp2_value = 0;
      ll y = 0;
      for(int i = V.size() - 1; i >= 0; --i){
        if(V[i].second != tmp1){
          tmp2 = V[i].second;
          tmp2_value = V[i].first;
          y++;
          break;
        }
      }
      //cout << tmp2_value << endl;
      //cout << y << endl;
      //cout << dp[memory - 1] << endl;
      decltype(S)::iterator it = S.find(tmp2);
      if (it == S.end()) { // 見つからない
        //std::cout << *it << std::endl;
        //dp[memory] = dp[memory - 1] + max(V[V.size() - 1].first, tmp2_value + (S.size() + 1) * (S.size() + 1) - S.size() * S.size());
        //cout << V[V.size() - 1].first << endl;
        //cout << tmp2 << endl;
        if(V[V.size() - 1].first > tmp2_value + (S.size() + 1) * (S.size() + 1) - S.size() * S.size()){
          dp[memory] = dp[memory - 1] + V[V.size() - 1].first;
          V.erase(V.begin() + V.size() - 1);
        }else{
          //cout << V[V.size() - y].first << endl;
          dp[memory] = dp[memory - 1] + tmp2_value + (S.size() + 1) * (S.size() + 1) - S.size() * S.size();
          V.erase(V.begin() + V.size() - 1 - y);
          S.insert(tmp2);
        }
      }else{
        dp[memory] = dp[memory - 1] + V[V.size() - 1].first;
        V.erase(V.begin() + V.size() - 1);
      }
      
      //cout << dp[memory - 1] + V[V.size() - 1].first << endl;
      //cout << tmp2_value + (cnt + 1) * (cnt + 1) - cnt * cnt  << endl;
      //cout << S.size() << endl;
      cnt++;
      memory++;
    }
  }
  cout << dp[k] << endl;
}

int main(){
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    cin >> t[i] >> d[i];
    V.push_back(make_pair(d[i], t[i]));
  }
  sort(V.begin(), V.end());

  solver();
}