#include<iostream>
#include<map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
using ll = long long;


int n;
vector<vector<int>> G(100005);
vector<pair<int,int>> vp;

void input(){
  cin >> n;

  for(int i = 1; i < n; ++i){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    vp.emplace_back(a,b);
  }
}

void solve(){
  int k = 0;
  map<pair<int,int>,int> I;
  vector<int> cs(n,0);
  vector<int> used(n,0);
  queue<int> Q;
  used[0] = 1;
  Q.emplace(0);
  while (!Q.empty())
  {
    /* code */
    int v = Q.front();
    Q.pop();
    if(k < G[v].size()){
      k = G[v].size();
    }
    int cur = 1;
    for(int u:G[v]){
      if(used[u])continue;
      if(cur == cs[v])cur++;
      cs[u]=I[make_pair(u,v)]=I[make_pair(v,u)]=cur++;
      used[u]=1;
      Q.emplace(u);
    }
  }
  cout << k << endl;
  for(auto p:vp) cout<<I[p]<<endl;
}

int main(){
  input();
  solve();
}