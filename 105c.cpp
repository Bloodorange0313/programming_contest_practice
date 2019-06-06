#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int n;
string ans;

int main(){
  cin >> n;
  int cnt = 1;
  int tmp = n;
  while(abs(tmp / 2) > 1){
    tmp = tmp / 2;
    cnt++;
  }
  //cout << cnt << endl;
  int dp[cnt + 5];
  int tmp2 = n;
  for(int i = cnt; i >= 0; --i){
    if(i == cnt){
      dp[i] = 1;
      tmp2 /= 2;
      ans += '1';
      //cout << tmp2 << endl;
    }else{
      if(abs(tmp2) >= pow(2, i) ){
        dp[i] = 1;
        tmp2 /= 2;
        ans += '1';
        cout << tmp2 << endl;
      }else{
        dp[i] = 0;
        ans += '0';
      }
    }
  }
  if(n == 0){
    cout << 0 << endl;
  }else{
    cout << ans << endl;
  }
}