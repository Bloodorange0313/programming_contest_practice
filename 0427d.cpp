#include<iostream>

using namespace std;

long long int n;
long long int a[10005], b[10005], dp[10005];

void solver(){
  for(int i = 1; i < n; ++i){
    if(i == 1){
      dp[i] = max(a[i] + a[i + 1], -1 * (a[i] + a[i + 1]));
      
      if(dp[i] == -1 * (a[i] + a[i + 1])){
        b[i + 1] = -a[i + 1];
        b[i] = -a[i];
      }
      else{
        b[i + 1] = a[i + 1];
        b[i] = a[i];
      }
      
      cout << b[i] << endl;
      cout << b[i + 1] << endl;
    }else{
      //cout << b[i] << endl;
      //cout << b[i + 1] << endl;
      dp[i] = max(dp[i - 1] + a[i + 1], dp[i - 1] - 2 * b[i] - a[i + 1]);
      if(dp[i - 1] + a[i + 1] < dp[i - 1] - 2 * b[i] - a[i + 1]){
        b[i] = -b[i];
        b[i + 1] = -a[i + 1];
      }
      else{
        b[i + 1] = a[i + 1];
        b[i] = b[i];
      }
      
      cout << b[i] << endl;
      cout << b[i + 1] << endl;
    }
  }
  cout << dp[3] << endl;
  /*
  for(int i = 1; i <= n; ++i){
    cout << b[i] <<endl;
  }
  */
  
}

int main(){
  cin >> n;
  for(int i = 1; i < n + 1; ++i){
    cin >> a[i];
  }
  solver();
}