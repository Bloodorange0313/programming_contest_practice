#include<iostream>
#include<queue>

using namespace std;

long long int n, m;
long long int a , b;
long long int x[205], y[205];

queue<long long int> Q;
bool visited[105];

bool t[105][105];


void bfs(long long int s){
  for(int i = 0; i < n; ++i){
    visited[i] = false;
  }
  visited[s] = true;
  Q.push(s);
  long long int cnt = 0;
  long long int depth = 0;
  //long long int depth1 = 0; // 本当の深さ

  while(!Q.empty() && depth == 0){
    s = Q.front();
    //cout << s << endl;
    Q.pop();
    long long int cnt1 = 0;
    long long int tmp;
    tmp = cnt;
    for(int j = 0; j < m; ++j){
      if(t[s][j] == true && visited[j] == false){
        visited[j] = true;
        Q.push(j);
        
        if(cnt1 == 1){
          cnt++;
          cnt++;
        }else if(cnt1 > 1){
          cnt++;
        }
        //cout << j << endl;
        cnt1++; // 並んでいるものがある
        if(j == b){
          depth++;
        }
      }
    }
    //depth1++;
    if(cnt1 > 0){
      cnt1++;
    }
    if(depth > 0){
      cnt = tmp;
      cnt1 = 0;
    }
    
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