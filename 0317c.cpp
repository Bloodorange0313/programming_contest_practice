#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int n;
int a[105], b[105], c[105], d[105];
vector<pair<int, int> >V, W;
vector<int> S;

void solver(){
  sort(V.begin(), V.end());
  sort(W.begin(), W.end());
  //int cnt = 0;
  
  for(int i = n - 1; i > -1; --i){
    for(int j = 0; j < n; ++j){
      if(V[i].first < W[j].first && V[i].second < W[j].second){
        //cnt++;
        //cout<< V[i].first << " " << W[j].first << endl;
        auto result = find(S.begin(), S.end(), V[i].first);
        if(result != S.end()){
          S.push_back(V[i].first);
          cout << V[i].first << " " << W[j].first << endl;
          break;
        }
        
      }
    }
  }
  cout << S.size() << endl;
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