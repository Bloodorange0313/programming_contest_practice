#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>


using namespace std;
using ll = long long;

int n;
int d[105];

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> d[i];
  }
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      ans += d[i] * d[j];
    }
  }
  cout << ans << endl;
}