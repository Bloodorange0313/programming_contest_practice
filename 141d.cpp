#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;
using ll = long long;

int n, m;
ll a[100005];
priority_queue<ll>Q;
ll sum = 0;

void input(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    Q.push(a[i]);
    sum += a[i];
  }
}

ll solve(){
  ll num = m;
  while(num > 0){
    num--;
    ll tmp = Q.top();
    Q.pop();
    double diff = tmp / (pow(2, 1));
    //sum -= tmp;
    sum -= tmp - diff;
    tmp = diff;
    Q.push(tmp);
  }
  return sum;
}

int main(){
  input();
  cout << solve() << endl;
}