#include<iostream>
#include<cmath>

using namespace std;

int n;
int a[100005];
int cnt = 0;

int main(){
  cin >> n;
  int tmp = 0;
  a[n + 1] = 0;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    cnt += abs(tmp - a[i]);
    tmp = a[i];
  }
  cnt += abs(a[n] - 0);
  //cout << cnt << endl;
  a[0] = 0;
  for(int i = 1; i <= n; ++i){
    if((a[i - 1] <= a[i] && a[i] <= a[i + 1]) || (a[i - 1] >= a[i] && a[i] >= a[i + 1])){
      cout << cnt << endl;
    }else{
      cout << cnt - min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])) * 2 << endl;
    }
  }
  
}