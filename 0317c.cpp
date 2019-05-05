#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

int n;
int a[105], b[105], c[105], d[105];
vector<pair<int, int> >V, W;
vector<int> S;
int x[105], y[105];

void solver(){
  sort(V.begin(), V.end());
  sort(W.begin(), W.end());
  int cnt = 0;
  for(int i = 0; i < n; ++i){
    x[i] = -1;
    y[i] = -1;
    //cout << x[i] << endl;
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(V[i].first < W[j].first && V[i].second < W[j].second /*&& x[i] == -1 */&& y[j] == -1){
        cnt++;
        //x[i] = 1;
        y[j] = 1;
        //cout << V[i].first << endl;
        //cout << x[i] << endl;
        break;
      }
    }
  }
  cout << cnt << endl;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
    V.push_back(make_pair(a[i], b[i]));
  }
  for(int i = 0; i < n; ++i){
    cin >> c[i] >> d[i];
    W.push_back(make_pair(c[i], d[i]));
  }
  solver();
}