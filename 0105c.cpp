#include<iostream>
#include<vector>

using namespace std;

long long n;
long long int cnt[1005];
long long int answer = 1;

bool isPrime(int m){
  bool judge = 1;
  for(int i = 2; i < m; ++i){
    if(m % i == 0){
      judge = 0;
      break;
    }
  }
  return judge;
}

long long int solver(){
  for(int i = 1; i <= n; ++i){
    cnt[i] = 1;
  }
  for(int i = 2; i <= n; ++i){
    for(int j = 2; j <= i; ++j){
      if(i % j == 0 && isPrime(j) == 1){
        cnt[j]++;
        long long int tmp = j * j;
        while(i % tmp == 0){
          cnt[j]++;
          tmp *= j;
        }
      }
    }
  }
  for(int i = 1; i <= n; ++i){
    answer *= cnt[i];
    answer = answer % (1000000000 + 7);
    //cout << cnt[i] << endl;
    //cout << answer << endl;
  }
  return answer % (1000000000 + 7);
}

int main(){
  cin >> n;
  cout << solver() << endl;
}