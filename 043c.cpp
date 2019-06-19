#include<iostream>
#include<cmath>

using namespace std;
using ll = long long;

double n;
double a[205];

int main(){
  cin >> n;
  double ave = 0;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    ave += a[i];
  }
  ave /= n;
  ll in_ave = int(ave);
  //cout << in_ave << endl;
  ll c;
  if(in_ave + 1 - ave < ave - in_ave){
    c = in_ave + 1;
  }else{
    c = in_ave;
  }
  //cout << c << endl;
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    //cout << abs(c - a[i]) << endl;
    ans += pow(abs(c - a[i]), 2);
  }
  cout << ans << endl;
}