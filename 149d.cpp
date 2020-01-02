#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int n, k, r, s, p;
string S;

void input(){
  cin >> n >> k;
  cin >> r >> s >> p;
  cin >> S;
}

int count(char a){
  if(a == 'r'){
    return p;
  }else if(a == 's'){
    return r;
  }else{
    return s;
  }
}

ll solve(){
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    if(i >= k){
      if(S[i - k] == S[i]){
        S[i] = 'g';
      }else{
        ans += count(S[i]);
      }
    }else{
      ans += count(S[i]);
    }
  }
  return ans;
}

int main(){
  input();
  cout << solve() << endl;
}