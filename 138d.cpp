#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;
using ll = long long;


ll n, q;
ll a[2 * 100005], b[2 * 100005];
ll p[100005 * 2], x[100005 * 2];
vector<ll>V[100005 * 2];
unordered_map<ll, ll>M;
ll counter[1000005 * 2];

void input(){
  cin >> n >> q;
  for(int i = 1; i <= n; ++i){
    M[i] = 0;
  }
  for(int i = 1; i < n; ++i){
    cin >> a[i] >> b[i];
    V[a[i]].push_back(b[i]);
    V[b[i]].push_back(a[i]);
  }
  for(int i = 1; i <= q; ++i){
    cin >> p[i] >> x[i];
    counter[p[i]] += x[i]; 
    
  }
  //for(int i = 1; i <= n; ++i){
    //cout << counter[i] << endl;
  //}
}

void solve(){
  stack<ll>S;
  bool visited[100005 * 2];
  for(int i = 1; i <= n; ++i){
    visited[i] = false;
  }
  visited[1] = true;
  //M[1] += counter[1];
  S.push(1);
  while(!S.empty()){
    ll tmp = S.top();
    S.pop();
    //cout << tmp << endl;
    for(int j = 0; j < V[tmp].size(); ++j){
      if(!visited[V[tmp][j]]){
        //cout << V[tmp][j] << endl;
        visited[V[tmp][j]] = true;
        // M[V[tmp][j]] += counter[tmp];
        counter[V[tmp][j]] += counter[tmp];
        S.push(V[tmp][j]);
      }
    }
  }
  for(int i = 1; i <= n; ++i){
    //cout << M[i] << " ";
    cout << counter[i] << " ";
  }
}

int main(){
  input();
  solve();
}
