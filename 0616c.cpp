#include<iostream>

using namespace std;

int n;
long long int a[10005];

long long int solver(){
  long long int cnt[10005];
  long long int sum = 0;
  for(int i = 0; i < n; ++i){
    cnt[i] = 0;
  }
  for(int i = 0; i < n; ++i){
    long long int tmp = a[i];
    while(tmp % 2 == 0){
      cnt[i]++;
      tmp = tmp / 2;
    }
    sum += cnt[i];
  }
  return sum;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  cout << solver() << endl;
}