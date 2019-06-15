#include<iostream>
 
using namespace std;
 
int n;
long long a[100005];
long long ans1, ans2, sum;
 
void solver(){
  sum = 0;
  for(int i = 1, s = 1; i <= n; ++i, s *= -1){
    sum += a[i];
    if(sum * s <= 0)ans1+=abs(sum-s),sum=s;
  }
  sum = 0;
  for(int i = 1, s = -1; i <= n; ++i, s *= -1){
    sum += a[i];
    if(sum * s <= 0)ans2+=abs(sum-s),sum=s;
  }
  cout << min(ans1, ans2) << endl;
}
 
int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  solver();
}
