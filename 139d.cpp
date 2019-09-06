#include<iostream>

using namespace std;
using ll = long long;

ll n;

int main(){
  cin >> n;
  ll sum = 0;
  for(int i = 1; i < n; ++i){
    sum += i;
  }
  cout << sum << endl;
}