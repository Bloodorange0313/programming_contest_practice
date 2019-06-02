#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int n;
int a[100005];
map<int, int>mp;

int main(){
  cin >> n;
  
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i){
    mp[a[i]]++;
  }
  int ans = 0;
  for(auto p : mp){
    int x = p.first;
    int y = p.second;
    if(y < x){
      ans += y;
    }else{
      ans += y - x;
    }
  }
  cout << ans << endl;
}