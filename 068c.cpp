#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;

int n, m;
int a[200005], b[200005];
queue<int> Q;
bool f[200005];
vector<int>V[200005];
int cnt[200005];

int bfs2(int s, int e){
  for(int i = 0; i < n; ++i){
    f[i] = false;
    cnt[i] = 0;
  } 
  f[s] = true;
  queue<int> Q1;
  //cout << s << endl;
  Q1.push(s);
  //cout << Q.front() << endl;
  //int t = 0;
  //int cnt = 0;
  bool judge = false;
  int tmp2 = 0;
  while(!Q1.empty() && tmp2 < 2){
    //t++;
    int tmp = Q1.front();
    //cout << Q.front() << endl;
    //cout << tmp << endl;
    Q1.pop();
    tmp2 = cnt[tmp];
    for(int i = 0; i < V[tmp].size(); ++i){
      if(f[V[tmp][i]] == false){
        //cout << V[tmp][i] << endl;
        f[V[tmp][i]] = true;
        Q1.push(V[tmp][i]);
        cnt[V[tmp][i]] = cnt[tmp] + 1;
        if(V[tmp][i] == e && cnt[V[tmp][i]] == 2){
          judge = true;
        }
      }
    }
  }
  return judge;
  //cout << t << endl;
  //cout << s << e << endl;
  //cout << judge << endl;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> a[i] >> b[i];
    V[a[i]].push_back(b[i]);
    V[b[i]].push_back(a[i]);
  }
  if(bfs2(1, n) == false){
    cout << "IMPOSSIBLE" << endl;
  }else{
    cout << "POSSIBLE" << endl;
    //cout << bfs(1, n) << endl;
  }
  //bfs2(1, n);
}