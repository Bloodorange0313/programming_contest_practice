#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

int n;
int u[102], k[102], t[102][102];
queue<int>Q;
vector<int>V;
int color[102];
int d[102];

void bfs(int s){
  for(int i = 1; i <= n; ++i){
    if(u[i] != s){
      color[u[i]] = 0;
      d[u[i]] = 150;
    }
  }
  d[s] = 0;
  int pi = 0;
  Q.push(s);
  while(!Q.empty()){
    int m = Q.front();
    Q.pop();
    for(int i = 1; i <= k[m]; ++i){
      if(color[t[m][i]] == 0){
        color[t[m][i]] = 2;
        d[t[m][i]] = d[m] + 1;
        pi = t[m][i];
        Q.push(t[m][i]);
      }
    }
    color[m] = 1;
  }
  for(int i = 1; i <= n; ++i){
    if(d[i] == 150){
      cout << i << " " << -1 << endl;
    }else{
      cout << i << " " << d[i] << endl;
    }
  }
  
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> u[i] >> k[i];
    for(int j = 1; j <= k[i]; ++j){
      cin >> t[i][j];
    }
  }
  bfs(1);
}