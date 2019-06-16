#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
 
using namespace std;
 
long long inf = 1000000007;
 
long long n, k;
long long a[100005];
int cnt[100005];
 
 
int main(){
  cin >> n >> k;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  long long sum = 0;
  long long ans = 0;
  int r = 0;
  for(int i = 0; i < n; ++i){
    while(sum < k){
      if(r == n){
        break;
      }else{
        sum += a[r];
        r++;
      }
    }
    if(sum < k){
      break;
    }
    ans += n - r + 1;
    sum -= a[i];
  }
  
  cout << ans << endl;
}