#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<stack>
#include<queue>


using namespace std;
using ll = long long;

ll n, m, l;
int a[100005], b[100005];
ll c[100005];
int q;
int s[100005], t[100005];
const ll Inf = 10000*100000+100;
vector<pair<int, ll> >V[100005];

ll dijkstra(int start, int end){
  ll cost[100005];
  for(int i = 1; i <= n; ++i){
    cost[i] = Inf;
  }
  cost[start] = 0;
  //cout << cost[start] << endl;
  priority_queue<int> SS;
	priority_queue<pair<ll, int> > Q;//始点からの距離と頂点のペア
  //ll ans = 0; // 燃料の入れる回数
  //ll tmp = l;
  for(int i = 1; i <= n; ++i){
    Q.push(make_pair (-cost[i], i));
    //ans[i] = 0;
  }
  while(!Q.empty()){
    pair<ll,int> s = Q.top();
    //cout << s.second << " " << s.first << endl;
    Q.pop();
    bool update = false;
    for(int i = 0; i < V[s.second].size(); ++i){
      int x = s.second, y = V[x][i].first, z = V[x][i].second;
      if(cost[x] < Inf && cost[y] > cost[x] + z && z <= l){
        cost[y] = cost[x] + z;
        update = true;
        Q.push(make_pair(-cost[y], y));
      }
    }
  }
  if(cost[end] != Inf){
    return cost[end];
    //return cost[end] / l;
  }else{
    return -1;
  }
  

}

int main(){
  cin >> n >> m >> l;
  for(int i = 0; i < m; ++i){
    cin >> a[i] >> b[i] >> c[i];
    V[a[i]].push_back(make_pair(b[i], c[i]));
    V[b[i]].push_back(make_pair(a[i], c[i]));
    //cout << V[a[i]].first << endl;
  }
  cin >> q;
  for(int i = 0; i < q; ++i){
    cin >> s[i] >> t[i];
    cout << dijkstra(s[i], t[i]) << endl;
  }


}