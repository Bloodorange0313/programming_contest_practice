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

ll dijkstra(int start, int end){
  ll cost[100005];
  for(int i = 1; i <= n; ++i){
    cost[i] = Inf;
  }
  cost[start] = 0;
  //cout << cost[start] << endl;
  priority_queue<int> SS;
	priority_queue<pair<int, int> > Q;//始点からの距離と頂点のペア
  //ll ans = 0; // 燃料の入れる回数
  //ll tmp = l;
  for(int i = 1; i <= n; ++i){
    Q.push(make_pair (-cost[i], i));
    //ans[i] = 0;
  }
  while(!Q.empty()){
    pair<int,int> s = Q.top();
    //cout << s.second << " " << s.first << endl;
    SS.push(s.second);
    Q.pop();
    bool update = false;
    for(int i = 0; i < m; ++i){
      int x = a[i], y = b[i], z = c[i];
      //cout << z << endl;
      //cout << s.second << endl;
      //cout << s.second <<" " << i << " "<< z << endl;
      //cout << a[i] << " " << b[i] << endl;
      if(cost[x] < Inf && cost[y] > cost[x] + z && z <= l){
        cost[y] = cost[x] + z;
        update = true;
        Q.push(make_pair(cost[y], y));
      }
    }
  }
  if(cost[end] != Inf){
    //return cost[end];
    return cost[end] / l;
  }else{
    return -1;
  }
  

}

int main(){
  cin >> n >> m >> l;
  for(int i = 0; i < m; ++i){
    cin >> a[i] >> b[i] >> c[i];
  }
  cin >> q;
  for(int i = 0; i < q; ++i){
    cin >> s[i] >> t[i];
    cout << dijkstra(s[i], t[i]) << endl;
  }


}