#include<iostream>
#include<deque>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int n;
int a[1005][1005];
int m;
int step[1005];
vector<int>V[1005];

int dfs(int v){
  bool visited[1005];
  stack<int>S;
  for(int i = 0; i < n; ++i){
    visited[i] = 0;
  }
  visited[v] = 1;
  bool ok = 0;
  int cnt = 0;
  S.push(v);
  //while(cnt <= m + 1){
    while(!S.empty()){
      int k = S.top();
      S.pop();
      for(int i = 0; i < V[k].size(); ++i){
        if(visited[V[k][i]] != 1){
          visited[V[k][i]] = 1;
          S.push(V[k][i]);
          cnt++;
        }
      }
    }
  //}
  return cnt;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n - 1; ++j){
      cin >> a[i][j];
      if(j > 0){
        V[a[i][j - 1]].push_back(a[i][j]);
        //cout << a[i][j] << endl;
      }
    }
  }
  m = n * (n - 1) / 2;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    //if(ans < dfs(i)){
    //  ans = dfs(i);
    //}
    cout << dfs(i) << endl;
  }
  cout << ans << endl;
}