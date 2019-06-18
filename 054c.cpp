#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int n, m;
int a[100], b[100];
int visited[100];
vector<int>V[100];


void dfs(int v){
  visited[v] = true;
  for(int i = 0; i < V[v].size(); ++i){
    if(visited[i] != false){
      dfs(i);
    }
  }
  
}


int main(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    visited[i] = false;
  }
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
    V[a[i]].push_back(b[i]);
    V[b[i]].push_back(a[i]);
  }
}