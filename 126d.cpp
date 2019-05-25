#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int n;
long long int u[100005], v[100005], w[100005];
vector<pair<long long int, long long int> > V[100005];
bool color[100005];

void solver(){
  for(int i = 1; i < n + 1; ++i){
    color[i] = 1;
  }
  color[1] = 0;
  for(int i = 1; i < n + 1; ++i){
    for(int j = 0; j < V[i].size(); ++i){
      //cout << V[i][j].first << endl;
      if(color[i] == 0){
        if(V[i][j].second % 2 == 0){
          color[V[i][j].first] = 0;
          //cout << V[i][j].first << endl;
        }else{
          color[V[i][j].first] = 1;
          //cout << V[i][j].first << endl;
        }
      }else{
        if(V[i][j].second % 2 == 0){
          color[V[i][j].first] = 1;
        }else{
          color[V[i][j].first] = 0;
        }
      }
    }
  }for(int i = 1; i < n + 1; ++i){
    cout << color[i] << endl;
  }
}

int main(){
  cin >> n;
  for(int i = 1; i < n; ++i){
    cin >> u[i] >> v[i] >> w[i];
    V[u[i]].push_back(make_pair(v[i], w[i]));
    V[v[i]].push_back(make_pair(u[i], w[i]));
  }
  solver();
}