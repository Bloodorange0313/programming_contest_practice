#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

long long inf = 1000000007;

double eps = 0.0000000001;

double w, h;
double x, y;
long double ans;
bool flag;

int main(){
  cin >> w >> h >> x >> y;
  ans = (w * h) / 2;
  double tmp1 = w/2; double tmp2 = h/2;
  if(x == tmp1 && y == tmp2){
    flag = 1;
  }else{
    flag = 0;
  }
  //cout << tmp2 << endl;
  cout << ans << " " << flag << endl;
}