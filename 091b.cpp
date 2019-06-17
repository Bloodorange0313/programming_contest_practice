#include<iostream>
#include<unordered_map>

using namespace std;

int n, m;
string s[105], t[105];
unordered_map<string, int> M;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> s[i];
    M[s[i]]++;
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    cin >> t[i];
    M[t[i]]--;
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans = max(ans, M[s[i]]);
  }
  cout << ans << endl;

}