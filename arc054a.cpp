#include<iostream>
#include<cmath>

using namespace std;
using ll = long long;

double l, x, y, s, d;

void input(){
  cin >> l >> x >> y >> s >> d;
}

void solve(){
  double front, back;
  if(s <= d){
    front = d - s;
    back = (l - d) + s;
    double ans_first = front / (x + y);
    if(y <= x){
      cout << ans_first << endl;
    }else{
      double ans_second = back / (y - x);
      cout << min(ans_first, ans_second) << endl;
    }
    
  }else{
    back = s - d;
    front = (l - s) + d;
    double ans_first = front / (x + y);
    if(y <= x){
      cout << ans_first << endl;
    }else{
      double ans_second = back / (y - x);
      cout << min(ans_first, ans_second) << endl;
    }
  }
  
}

int main(){
  input();
  solve();
}
