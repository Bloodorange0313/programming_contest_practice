#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
 
using namespace std;
 
long long inf = 1000000007;
 
int n, k;
int a[100005];
int cnt[100005];
 
 
int main(){
  cin >> n >> k;
  for(int i = 1; i < n + 1; ++i){
    cin >> a[i];
    cnt[i] = n;
  }
  long long tmp = 0;
  int l[n][n];
  for(int i = 1; i < n + 1; ++i){
    for(int j = i; j < n + 1; ++j){
      if(i == j){
        l[i][j] = a[i];
      }else{
        l[i][j] = a[j] + l[i][j - 1];
      }
      if(l[i][j] >= k){
        tmp++;
      }
      //cout << l[i][j] << endl;
    }
  }
  
  cout << tmp << endl;
}