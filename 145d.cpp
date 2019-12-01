#include<iostream>

using namespace std;
using ll = long long;

ll x, y;
ll a = 1e9 + 7;

void input(){
  cin >> x >> y;
}

ll dp[1000005];
ll fact(ll num){
  
  
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= num; i++)
  {
    dp[i] = (dp[i - 1] * i) % a;
  }
  return dp[num];
}

/*
ll comb(ll num1, ll num2){
  if(num1 < num2 || num1 < 0 ||  num2 < 0){
    return 0;
  }else{
    ll v = fact(num1);
    ll w = fact(num2);
    ll z = fact(num1 - num2);
    //return ((fact(num1))/ ((fact(num2) * fact(num1 - num2)) % a));
    return v / ((w * z) % a);
    //return v;
    //return z;
  }
  
}
*/

ll comb(ll N_, ll C_) {
	const int NUM_=1400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[a % i] * (a - a / i) % a;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%a, factr[i]=factr[i-1]*inv[i]%a;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%a*factr[N_-C_]%a;
  //return inv[N_];
}

ll solve(){
  if(x + y == 0){
    return 1;
  }
  ll judge = abs(x - y);
  if((x + y) % 3 != 0){
    return 0;
  }
  
  ll count = ((x + y) / 3);
  //ll tmp = (count - abs(judge)) / 2;
  //ll flag = judge / 3;
  ll tmp = (2 * x - y) / 3;

  return comb(count, tmp);
  //return tmp;
}


int main(){
  input();
  cout << solve() << endl;
  //cout << comb(3, 3) << endl;
  
}
