#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

long long inf = 1000000007;

int n, x;
int l[105];

int main(){
  cin >> n >> x;
  int cnt = 1;
  int tmp = 0;
  for(int i = 0; i < n; ++i){
    cin >> l[i];
    tmp += l[i];
    if(tmp <= x){
      cnt++;
    }else{
      break;
    }
  }
  cout << cnt << endl;
}