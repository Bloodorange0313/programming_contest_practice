#include<iostream>
#include<queue>
#include<vector>

using namespace std;

long long int n, m;
long long int a , b;
long long int x[205], y[205];

queue<long long int> Q;
bool visited[105];

vector<int>V[205];
bool t[105][105];

long long int dp[105];

void bfs(long long int s){
  for(int i = 0; i < n; ++i){
    visited[i] = false;
    
  }
  visited[s] = true;
  Q.push(s);
  long long int cnt = 1;
  long long int judge = 0;
  dp[s] = 0;
  while(!Q.empty() && judge == 0){
    s = Q.front();
    Q.pop();
    for(int j = 0; j < m; ++j){
      
      if(t[s][j] == true && visited[j] == false){
        visited[j] = true;
        Q.push(j);
        dp[j] = dp[s] + 1;
        V[dp[j]].push_back(j);
        //cout << j << endl;
        if(j == b){
          judge++;
        }
      }
    }
  }
  for(int i = 1; i < dp[b]; ++i){
    cnt *= V[i].size();
    //cout << V[i].size() << endl;
  }
  
  cout << cnt << endl;
}




int main(){
  cin >> n;
  cin >> a >> b;
  cin >> m;
  for(int i = 0; i < m; ++i){
    for(int j = i + 1; j < m; ++j){
      t[i][j] = false;
    }
  }
  for(int i = 0; i < m; ++i){
    cin >> x[i] >> y[i];
    t[x[i]][y[i]] = true;
    t[y[i]][x[i]] = true;
  }
  bfs(a);
}