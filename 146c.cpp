#include<iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll a, b, x;

void input(){
  cin >> a >> b >> x;
}

ll getdigit(ll num){
  return to_string(num).length();
}

bool check(ll num){
  ll need = a * num + b * getdigit(num);
  if(x >= need){
    return true;
  }else{
    return false;
  }
}

ll search(){
  ll ok = 0;
  ll ng = 1e9 + 1;
  while(abs(ok - ng) > 1){
    ll mid = (ok + ng) / 2;
    if(check(mid) == 1) ok = mid;
    else ng = mid;
  }
  return ok;
}


int main(){
  input();
  //cout << getdigit(10055) << endl;
  cout << search() << endl;
  //cout << check(10) << endl;
}