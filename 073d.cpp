#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, R;
int r[205];
int a[205], b[205], c[205];
vector<pair<int, int> >V[205];


int main(){
  cin >> n >> m >> R;
  for(int i = 0; i < R; ++i){
    cin >> r[i];
  }
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i] >> c[i];
    V[a[i]].push_back(make_pair(b[i], c[i]));
    V[b[i]].push_back(make_pair(a[i], c[i]));
  }

}
