#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>


using namespace std;
using ll = long long;

int n;
string s;

int main(){
  cin >> n;
  cin >> s;
  ll ans = 1;
  for(int i = 0; i < n - 1; ++i){
    if(s[i] != s[i + 1]){
      ans += 1;
    }
  }
  cout << ans << endl;
}