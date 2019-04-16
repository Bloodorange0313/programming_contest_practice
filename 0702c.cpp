#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int a[100005];
vector<pair<int, int> > V;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    V.push_back(make_pair(a[i], i));
  }
  sort(V.begin(), V.end());
  for(int i = n - 1; i >= 0; --i){
    cout << V[i].second + 1 << endl;
  }
}