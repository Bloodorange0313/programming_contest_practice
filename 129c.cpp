#include<iostream>

using namespace std;

int n, m;
int a[100005];
bool judge[100005];
long long inf = 1000000007;
  

void solver(){
  int dp[100005];
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 1; i <= n; ++i){
    if(judge[i] == 1 && judge[i - 1] == 1){
      dp[i + 1] = 0;
    }else if(judge[i] == 1){
      dp[i + 1] = dp[i - 1] % inf;
    }else if(judge[i - 1] == 1){
      dp[i + 1] = dp[i] % inf;
    }else{
      dp[i + 1] = (dp[i] + dp[i - 1]) % inf;
    }
  }
  cout << dp[n] << endl;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    judge[i] = 0;
  }
  for(int i = 0; i < m; ++i){
    cin >> a[i];
    judge[a[i]] = 1;
  }
  solver();
}