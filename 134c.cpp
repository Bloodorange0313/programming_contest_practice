#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

ll n;
ll a[200005];
vector<ll> V;
ll maximum = 0;
ll second_max = 0;

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    V.push_back(a[i]);
  }
  sort(V.begin(), V.end());
  maximum = V[n - 1];
  second_max = V[n - 2];
  for(int i = 0; i < n; ++i){
    if(a[i] == maximum){
      cout << second_max << endl;
    }else{
      cout << maximum << endl;
    }
  }
}