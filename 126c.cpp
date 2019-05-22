#include<iostream>
#include<cmath>

using namespace std;

double n, k;
int cnt[100005];
double answer = 0.00000000000;

int main(){
  cin >> n >> k;
  for(int i = 1; i <= n; ++i){
    int tmp = i;
    cnt[i] = 0;
    while(tmp <= k){
      cnt[i]++;
      tmp *= 2;
    }
  }
  for(int i = 1; i <= n; ++i){
    answer +=  pow(0.5, cnt[i]);
    //cout << cnt[i] << endl;
    //cout << pow((1 / 2), cnt[i]) << endl;
    //cout << (1 / 2.00000000000) << endl;
  }
  cout << answer / n << endl;
}