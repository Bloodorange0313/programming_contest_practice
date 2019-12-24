#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, u, v;
int a[100005], b[100005];
vector<int>V[1000005];
vector<pair<int, int>>takahashi, aoki;

void input(){
  cin >> n >> u >> v;
  for(int i = 1; i < n; ++i){
    cin >> a[i] >> b[i];
    //cout << a[i] << b[i] << endl;
    V[a[i]].push_back(b[i]);
    V[b[i]].push_back(a[i]);
  }
}


void bfs1(int root){
  int flag[1000005], cnt[100005];
  for(int i = 1; i < n; ++i){
    flag[i] = 0;
    cnt[i] = 0;
    //aokicnt[i] = 100005;
  }
  queue<int> Q;
  flag[root] = 1;
  //aokicnt[root] = 0;
  Q.push(root);
  while(!Q.empty()){
    int tmp = Q.front();
    Q.pop();
    for(int i = 0; i < V[tmp].size(); ++i){
      if(!flag[V[tmp][i]]){
        flag[V[tmp][i]] = 1;
        Q.push(V[tmp][i]);
        cnt[V[tmp][i]] = cnt[tmp] + 1;
        //aokicnt[V[tmp][i]] = min(cnt[tmp] + 1, aokicnt[V[tmp][i]]);
      }
    }
  }
  for(int i = 1; i <= n; ++i){
    //cout << i << " " << cnt[i] << endl;
    aoki.push_back(make_pair(cnt[i], i));
    //aokicnt[i] = cnt[i];
  }
  sort(aoki.begin(), aoki.end());
}


int flag2[100005];

int bfs2(int root, int goal){
  int flag[100005], cnt[100005];
  for(int i = 1; i <= n; ++i){
    flag[i] = 0;
    flag2[i] = 0;
    cnt[i] = 100005;
  }
  queue<int> Q;
  flag[root] = 1;
  cnt[root] = 0;
  Q.push(root);
  while(!Q.empty()){
    int tmp = Q.front();
    Q.pop();
    for(int i = 0; i < V[tmp].size(); ++i){
      if(!flag[V[tmp][i]]){
        flag2[tmp] = 1;
        flag[V[tmp][i]] = 1;
        Q.push(V[tmp][i]);
        cnt[V[tmp][i]] = min(cnt[tmp] + 1, cnt[V[tmp][i]]);
      }
    }
  }
  return cnt[goal];
}

int takahashicnt[100005];
void bfs3(int root){
  int flag[100005], cnt[100005];
  for(int i = 1; i <= n; ++i){
    flag[i] = 0;
    flag2[i] = 0;
    cnt[i] = 100005;
  }
  queue<int> Q;
  flag[root] = 1;
  cnt[root] = 0;
  Q.push(root);
  while(!Q.empty()){
    int tmp = Q.front();
    Q.pop();
    for(int i = 0; i < V[tmp].size(); ++i){
      if(!flag[V[tmp][i]]){
        flag2[tmp] = 1;
        flag[V[tmp][i]] = 1;
        Q.push(V[tmp][i]);
        cnt[V[tmp][i]] = min(cnt[tmp] + 1, cnt[V[tmp][i]]);
      }
    }
  }
  //return cnt[goal];
  for(int i = 1; i <= n; ++i){
    takahashicnt[i] = cnt[i];
  }
}

int main(){
  input();
  bfs1(v);
  bfs3(u);
  int nige = u;
  for(int i = aoki.size() - 1; i >= 0; --i){
    if(aoki[i].first > takahashicnt[aoki[i].second] && flag2[aoki[i].second] != 1){
      nige = aoki[i].second;
      break;
    }
  }
  // nigeが高橋くんが追い詰められる場所
  //cout << nige << endl;
  int ans = 0;
  //int c = aoki[nige].first - bfs2(u, nige);
  ans = bfs2(v, nige);
  cout << ans - 1 << endl;
  //cout << nige << endl;
  //cout << bfs2(1, 9) << endl;
  //cout << bfs2(5, 2) << endl;
  
}