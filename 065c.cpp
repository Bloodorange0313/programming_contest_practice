#include<iostream>
#include<cmath>

using namespace std;

long long n, m;
long long answer;

long long int factrial(int n){
  long long int dp[100005];
  for(int i = 1; i <= n; ++i){
    if(i == 1){
      dp[i] = 1;
    }else{
      dp[i] = ((dp[i - 1] * i) % (1000000000 + 7));
    }
  }
  return dp[n];
}

int main(){
  cin >> n >> m;
  if(abs(n - m) >= 2){
    answer = 0;
    //cout <<  << endl;
  }else if(abs(n - m) == 1){
    answer = (factrial(n) * factrial(m));
  }else if(abs(m - n) == 0){
    answer = ((factrial(n) * factrial(m)) * 2);
    //cout << factrial(n) * 2 << endl;
  }
  cout << (answer % (1000000000 + 7)) << endl;
  //cout << factrial(5) << endl;
}