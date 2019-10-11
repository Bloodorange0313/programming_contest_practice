#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll a, b;
//bool judge[1000000000005];
ll gcd(ll a,ll b){
  while(b!=0){
    a%=b;
    swap(a,b);
  }
  return a;
}
int main(){
  cin >> a >> b;
  //cout << ans(a, b) << endl;
  ll c = gcd(a, b);
  ll ans=1;
  for(ll i=2;i*i<=c;i++){
    if(c%i==0){
      ans++;
      while(c%i==0){c/=i;}
    }
  }
  if(c!=1){ans++;}
  cout<<ans<<endl;
}