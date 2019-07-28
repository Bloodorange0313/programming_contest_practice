#include<iostream>

using namespace std;
using ll = long long;

ll n;
ll a[200005];

ll solver(ll s){
  ll tmp = 0;
  
  //for(int i = n; i > 0; --i){
    for(int j = s; j <= n; j){
      tmp += ;
    }if(tmp != a[s]){
      return 1;
    }else{
      return 0;
    }
  //}
    
  
}

ll countelement(ll s){
  ll ans = 0;
  for(int i = 1; i <= s; ++i){
    ans += solver(i);
  }
  return ans;
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  cout << countelement(n) << endl; 
  for(int i = 1; i <= n; ++i){
    cout << solver(i) << endl;
  }
}