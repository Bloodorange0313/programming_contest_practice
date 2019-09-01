#include<iostream>
#include<string>
#include <typeinfo>
#include <cstdlib>
#include <cmath>


using namespace std;
using ll = long long;

ll inf = 1000000000 + 7;
string s;
ll dp[100005][11];

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

void solver(){
  ll num = s.length();
  ll cnt = 0;
  for(int i = num - 1; i >= 0; --i){
    for(int j = 0; j < 10; ++j){
      dp[i][j] = -1;
      //cout << dp[i][j] << endl;
    }
  }
  for(int i = num - 1; i >= 0; --i){
    //cout << dp[i + 1][3] << endl;
    if(s[i] != '?'){
      int tmp = ctoi(s[i]);
      //cout << tmp << endl;
      if(i == num - 1){
        dp[i][tmp] = tmp;
        //cout << dp[i][tmp] <<endl;
        if(dp[i][tmp] == 5){
          cnt++;
        }
      }else{
        for(int j = 0; j < 10; ++j){
          //cout << dp[i + 1][j] << endl;
          if(dp[i + 1][j] != -1){
            ll s = pow(10, (num - 1 - i));
            dp[i][tmp] = (tmp * s + dp[i + 1][j]) % 13;
            //cout << i << " " << tmp << " " << dp[i + 1][tmp] <<endl;
            //cout << num - 1 - i << endl;
            if(dp[i][tmp] == 5){
              //cout << dp[i][tmp] << endl;
              //cout << j << endl;
              cnt++;
              cnt = cnt % inf;
            }
          }
        }
      }
    }else{
      
      for(int k = 0; k < 10; ++k){
        int tmp = k;
        if(i == num - 1){
          dp[i][k] = tmp;
          if(dp[i][k] == 5){
            cnt++;
          }
        }else{
          for(int j = 0; j < 10; ++j){
            if(dp[i + 1][j] != -1){
              //cout << i << " " << tmp << " " << dp[i + 1][j] <<endl;
              ll s = pow(10, (num - 1 - i));
              dp[i][tmp] = (tmp * s + dp[i + 1][j]) % 13;
              if(dp[i][tmp] == 5){
                //cout << dp[i][tmp] << endl;
                //cout << j << endl;
                cnt++;
                cnt = cnt % inf;
              }
            }
          }
        }
      }
    }
  }
  
  cout << cnt << endl;
}

int main(){
  cin >> s;
  solver();
}
