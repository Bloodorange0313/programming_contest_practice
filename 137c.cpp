#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int n;
string s[1000005];
vector<string>V;

void input(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> s[i];
    V.push_back(s[i]);
  }
  for(int i = 0; i < n; ++i){
    sort(V[i].begin(), V[i].end());
  }
  sort(V.begin(), V.end());
}

ll solve(){
  ll cnt = 0;
  ll tmp = 0;
  for(int i = 0; i < n - 1; ++i){
    if(V[i] == V[i + 1]){
      tmp++;
      cnt += tmp;
    }else{
      tmp = 0;
    }
  }
  return cnt;
}

int main(){
  input();
  cout << solve() << endl;
}